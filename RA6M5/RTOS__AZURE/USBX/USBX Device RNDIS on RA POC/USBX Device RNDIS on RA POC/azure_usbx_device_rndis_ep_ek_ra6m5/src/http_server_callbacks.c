/*
 * http_server_callbacks.c
 *
 *  Created on: Jul 26, 2022
 *      Author: a5123412
 */
#include "usb_network_thread.h"

#define FLASH_HP_DF_BLOCK_0         0x40100000U /*   64 B:  0x40100000 - 0x4010003F */

static char *get_html(void);
static void read_post(char *post);

char buffer[512];

UINT authentication_check(struct NX_HTTP_SERVER_STRUCT *server_ptr, UINT request_type, CHAR *resource, CHAR **name, CHAR **password, CHAR **realm);
UINT request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type, CHAR *resource, NX_PACKET *packet_ptr);

UINT authentication_check(struct NX_HTTP_SERVER_STRUCT *server_ptr, UINT request_type, CHAR *resource, CHAR **name, CHAR **password, CHAR **realm)
{
#if 0
      *name =  "name5";
      *password = "password6";
      *realm =  "test.htm";
      return(NX_HTTP_BASIC_AUTHENTICATE);
#else
      FSP_PARAMETER_NOT_USED(server_ptr);
      FSP_PARAMETER_NOT_USED(request_type);
      FSP_PARAMETER_NOT_USED(resource);
      FSP_PARAMETER_NOT_USED(name);
      FSP_PARAMETER_NOT_USED(password);
      FSP_PARAMETER_NOT_USED(realm);
      return(NX_SUCCESS);
#endif
}

UINT request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type, CHAR *resource, NX_PACKET *packet_ptr)
{
    if (request_type == 1) {        // GET data
        char *html = get_html();
        nx_http_server_callback_data_send(server_ptr, html, strlen(html));
        free(html);
    }

    if (request_type == 2) {        // POST data
        UINT actual_length;
        UINT status = nx_http_server_content_get(server_ptr, packet_ptr, 0, buffer, 512, &actual_length);

        if (status != NX_SUCCESS)
            __BKPT();

        read_post(buffer);

        char *html = get_html();
        nx_http_server_callback_data_send(server_ptr, html, strlen(html));
        free(html);

        ULONG reset_code = 0xF0F0F0F0UL;
        tx_queue_send(&g_reset_queue, &reset_code, TX_NO_WAIT);
    }

    FSP_PARAMETER_NOT_USED(resource);
    return(NX_HTTP_CALLBACK_COMPLETED);
}

static char *get_html(void)
{
    fsp_err_t fsp_err;
    uint8_t read_buffer[8];
    char ip_base[16];
    char ip_out[16];
    char html_string[400];

    fsp_err = R_FLASH_HP_Open(&g_flash0_ctrl, &g_flash0_cfg);
    if (fsp_err != FSP_SUCCESS) __BKPT();

    memcpy(read_buffer, (uint8_t *) FLASH_HP_DF_BLOCK_0, sizeof(read_buffer));

    fsp_err = R_FLASH_HP_Close(&g_flash0_ctrl);
    if (fsp_err != FSP_SUCCESS) __BKPT();

    sprintf(ip_base, "%d.%d.%d.%d", read_buffer[0], read_buffer[1], read_buffer[2], read_buffer[3]);
    sprintf(ip_out, "%d.%d.%d.%d", read_buffer[4], read_buffer[5], read_buffer[6], read_buffer[7]);
    sprintf(html_string, "<html>\r\n<form method=\"post\">\r\n<div>\r\n<label for=\"ip_base\">Basestation IP</label>\r\n<input name=\"ip_base\""
        " id=\"ip_base\" value=\"%s\">\r\n</div>\r\n<div>\r\n<label for=\"ip_out\">Outstation IP</label>\r\n<input name="
        "\"ip_out\" id=\"ip_out\" value=\"%s\">\r\n</div>\r\n<div>\r\n<button>Submit</button>\r\n</div>\r\n</form>\r\n</html>", ip_base, ip_out);

    char *html = malloc(sizeof(char) * strlen(html_string));
    sprintf(html, html_string);
    return html;
}

static void read_post(char *post)
{
    fsp_err_t fsp_err;
    uint8_t write_buffer[8];
    char *substr;
    char ip_base[16];
    char ip_out[16];

    // Parse the post into ip address strings eg. to parse: ip_base=192.168.1.123&ip_out=192.168.1.231
    substr = strtok(post, "=&");
    substr = strtok(NULL, "=&");
    sprintf(ip_base, substr);
    substr = strtok(NULL, "=&");
    substr = strtok(NULL, "=&");
    sprintf(ip_out, substr);

    // Parse the ip address strings into 8 bit unsigned integers
    substr = strtok(ip_base, ".");
    for (int i = 0; i < 4; i++) {
        write_buffer[i] = (uint8_t)atoi(substr);
        substr = strtok(NULL, ".");
    }
    substr = strtok(ip_out, ".");
    for (int i = 4; i < 8; i++) {
        write_buffer[i] = (uint8_t)atoi(substr);
        substr = strtok(NULL, ".");
    }

    // TODO: USE strol and check if values are between 0 and 255
    fsp_err = R_FLASH_HP_Open(&g_flash0_ctrl, &g_flash0_cfg);
    if (fsp_err != FSP_SUCCESS) __BKPT();

    fsp_err = R_FLASH_HP_Erase(&g_flash0_ctrl, FLASH_HP_DF_BLOCK_0, 1);
    if (fsp_err != FSP_SUCCESS) __BKPT();

    fsp_err = R_FLASH_HP_Write(&g_flash0_ctrl, (uint32_t)write_buffer, FLASH_HP_DF_BLOCK_0, 8);
    if (fsp_err != FSP_SUCCESS) __BKPT();

    fsp_err = R_FLASH_HP_Close(&g_flash0_ctrl);
    if (fsp_err != FSP_SUCCESS) __BKPT();
}
