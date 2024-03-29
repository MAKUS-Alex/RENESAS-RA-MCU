/***********************************************************************************************************************
 * Copyright [2015-2021] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 * 
 * This file is part of Renesas SynergyTM Software Package (FSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas FSP license agreement. Unless otherwise agreed in an FSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * File Name    : filex_stub.c
 * Description  : FileX Stub Support Template source file.
 **********************************************************************************************************************/

/* This is a stub routine for FileX for a user application that do not have FileX to rely on. To use this module,
 * users need to define function definitions to match their system requirements. Primary function definitions are
 * just templates and not functional.
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "usb_network_thread.h"
#include "filex_stub.h"

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/* Define your own FileX stub functions. */

UINT        fx_directory_attributes_read( FX_MEDIA *media_ptr, CHAR *directory_name, UINT *attributes_ptr )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    FSP_PARAMETER_NOT_USED(attributes_ptr);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_attributes_set( FX_MEDIA *media_ptr, CHAR *directory_name, UINT attributes )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    FSP_PARAMETER_NOT_USED(attributes);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_create( FX_MEDIA *media_ptr, CHAR *directory_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_delete( FX_MEDIA *media_ptr, CHAR *directory_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_rename( FX_MEDIA *media_ptr, CHAR *old_directory_name, CHAR *new_directory_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(old_directory_name);
    FSP_PARAMETER_NOT_USED(new_directory_name);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_first_entry_find( FX_MEDIA *media_ptr, CHAR *directory_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    return FX_ACCESS_ERROR;
}


UINT        fx_directory_first_full_entry_find( FX_MEDIA *media_ptr, CHAR *directory_name, UINT *attributes,
                ULONG *size, UINT *year, UINT *month, UINT *day, UINT *hour, UINT *minute, UINT *second )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    FSP_PARAMETER_NOT_USED(attributes);
    FSP_PARAMETER_NOT_USED(size);
    FSP_PARAMETER_NOT_USED(year);
    FSP_PARAMETER_NOT_USED(month);
    FSP_PARAMETER_NOT_USED(day);
    FSP_PARAMETER_NOT_USED(hour);
    FSP_PARAMETER_NOT_USED(minute);
    FSP_PARAMETER_NOT_USED(second);
    return FX_ACCESS_ERROR;
}


UINT        fx_directory_next_entry_find( FX_MEDIA *media_ptr, CHAR *directory_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_next_full_entry_find( FX_MEDIA *media_ptr, CHAR *directory_name, UINT *attributes,
                ULONG *size, UINT *year, UINT *month, UINT *day, UINT *hour, UINT *minute, UINT *second )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    FSP_PARAMETER_NOT_USED(attributes);
    FSP_PARAMETER_NOT_USED(size);
    FSP_PARAMETER_NOT_USED(year);
    FSP_PARAMETER_NOT_USED(month);
    FSP_PARAMETER_NOT_USED(day);
    FSP_PARAMETER_NOT_USED(hour);
    FSP_PARAMETER_NOT_USED(minute);
    FSP_PARAMETER_NOT_USED(second);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_name_test( FX_MEDIA *media_ptr, CHAR *directory_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_information_get( FX_MEDIA *media_ptr, CHAR *directory_name, UINT *attributes, ULONG *size,
                UINT *year, UINT *month, UINT *day, UINT *hour, UINT *minute, UINT *second )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(directory_name);
    FSP_PARAMETER_NOT_USED(attributes);
    FSP_PARAMETER_NOT_USED(size);
    FSP_PARAMETER_NOT_USED(year);
    FSP_PARAMETER_NOT_USED(month);
    FSP_PARAMETER_NOT_USED(day);
    FSP_PARAMETER_NOT_USED(hour);
    FSP_PARAMETER_NOT_USED(minute);
    FSP_PARAMETER_NOT_USED(second);
    return FX_ACCESS_ERROR;
}


UINT        fx_directory_default_set( FX_MEDIA *media_ptr, CHAR *new_path_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(new_path_name);
    return FX_ACCESS_ERROR;
}

UINT        fx_directory_default_get( FX_MEDIA *media_ptr, CHAR **return_path_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(return_path_name);
    return FX_ACCESS_ERROR;
}

UINT        fx_file_best_effort_allocate( FX_FILE *file_ptr, ULONG size, ULONG *actual_size_allocated )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(size);
    FSP_PARAMETER_NOT_USED(actual_size_allocated);
    return FX_ACCESS_ERROR;
}

UINT        fx_file_create( FX_MEDIA *media_ptr, CHAR *file_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(file_name);
    return FX_ACCESS_ERROR;
}

UINT        fx_file_delete( FX_MEDIA *media_ptr, CHAR *file_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(file_name);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_rename( FX_MEDIA *media_ptr, CHAR *old_file_name, CHAR *new_file_name )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(old_file_name);
    FSP_PARAMETER_NOT_USED(new_file_name);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_attributes_set( FX_MEDIA *media_ptr, CHAR *file_name, UINT attributes )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(file_name);
    FSP_PARAMETER_NOT_USED(attributes);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_attributes_read( FX_MEDIA *media_ptr, CHAR *file_name, UINT *attributes_ptr )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(file_name);
    FSP_PARAMETER_NOT_USED(attributes_ptr);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_open( FX_MEDIA *media_ptr, FX_FILE *file_ptr, CHAR *file_name, UINT open_type )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(file_name);
    FSP_PARAMETER_NOT_USED(open_type);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_close( FX_FILE *file_ptr )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_read( FX_FILE *file_ptr, VOID *buffer_ptr, ULONG request_size, ULONG *actual_size )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(buffer_ptr);
    FSP_PARAMETER_NOT_USED(request_size);
    FSP_PARAMETER_NOT_USED(actual_size);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_write( FX_FILE *file_ptr, VOID *buffer_ptr, ULONG size )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(buffer_ptr);
    FSP_PARAMETER_NOT_USED(size);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_allocate( FX_FILE *file_ptr, ULONG size )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(size);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_relative_seek( FX_FILE *file_ptr, ULONG byte_offset, UINT seek_from )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(byte_offset);
    FSP_PARAMETER_NOT_USED(seek_from);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_seek( FX_FILE *file_ptr, ULONG byte_offset )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(byte_offset);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_truncate( FX_FILE *file_ptr, ULONG size )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(size);
    return FX_ACCESS_ERROR;
}
UINT        fx_file_truncate_release( FX_FILE *file_ptr, ULONG size )
{
    FSP_PARAMETER_NOT_USED(file_ptr);
    FSP_PARAMETER_NOT_USED(size);
    return FX_ACCESS_ERROR;
}

UINT        fx_media_format( FX_MEDIA *media_ptr, VOID (*driver)( FX_MEDIA *media), VOID *driver_info_ptr,
                UCHAR *memory_ptr, UINT memory_size, CHAR *volume_name, UINT number_of_fats, UINT directory_entries,
                UINT hidden_sectors, ULONG total_sectors, UINT bytes_per_sector, UINT sectors_per_cluster, UINT heads,
                UINT sectors_per_track )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(driver);
    FSP_PARAMETER_NOT_USED(driver_info_ptr);
    FSP_PARAMETER_NOT_USED(memory_ptr);
    FSP_PARAMETER_NOT_USED(memory_size);
    FSP_PARAMETER_NOT_USED(volume_name);
    FSP_PARAMETER_NOT_USED(number_of_fats);
    FSP_PARAMETER_NOT_USED(directory_entries);
    FSP_PARAMETER_NOT_USED(hidden_sectors);
    FSP_PARAMETER_NOT_USED(total_sectors);
    FSP_PARAMETER_NOT_USED(bytes_per_sector);
    FSP_PARAMETER_NOT_USED(sectors_per_cluster);
    FSP_PARAMETER_NOT_USED(heads);
    FSP_PARAMETER_NOT_USED(sectors_per_track);
    return FX_SUCCESS;
}
UINT        fx_media_open( FX_MEDIA *media_ptr, CHAR *media_name, VOID (*media_driver)(FX_MEDIA *),
                VOID *driver_info_ptr, VOID *memory_ptr, ULONG memory_size )
{
    FSP_PARAMETER_NOT_USED(media_ptr);
    FSP_PARAMETER_NOT_USED(media_name);
    FSP_PARAMETER_NOT_USED(media_driver);
    FSP_PARAMETER_NOT_USED(driver_info_ptr);
    FSP_PARAMETER_NOT_USED(memory_ptr);
    FSP_PARAMETER_NOT_USED(memory_size);
    return FX_SUCCESS;
}


