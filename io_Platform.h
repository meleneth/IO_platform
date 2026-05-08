#pragma once

#include <cstddef>
#include <cstdint>

#if defined(WINDOWS)

#include <windef.h>

#define PLATFORM_SLASH ('\\')
#define NATIVE_STRING_TYPE const wchar_t

bool io_wstrncmp(NATIVE_STRING_TYPE *str1, NATIVE_STRING_TYPE *str2,
                 int num_char);

#elif defined(LINUX)

#include <limits.h>

#define LINUX
#define MAX_PATH PATH_MAX
#define PLATFORM_SLASH ('/')
#define NATIVE_STRING_TYPE const char

#else
#error "Unsupported platform"
#endif

struct file_info {
  int size; // currently only supports 32-bit address sizes
  uint8_t *data;
};

/*
int io_strncmp(const char *str1, const char *str2, int num_char);
int io_strncasecmp(NATIVE_STRING_TYPE *str1, NATIVE_STRING_TYPE *str2,
                   int num_char);
*/
// not really trying to fix stuff here, I care about the build stuff
int io_strncasecmp(const char *str1, const char *str2, int num_char);
int io_strncmp(const char *str1, const char *str2, int num_char);

bool io_isdir(char *dir_path);

char *io_wchar_utf8(NATIVE_STRING_TYPE *src);
wchar_t *io_utf8_wchar(const char *src);
char *io_get_cwd();

void *io_open_dir(char *dir_name);
char *io_scan_dir(void *dir_stream);
bool io_close_dir(void *dir_stream);

char *io_path_check(char *file_name);
bool io_file_exists(const char *filename);
bool io_create_path_from_file(char *file_path);
bool io_make_dir(char *dir_path);
bool io_swap_slash(char *path_buff);
int io_file_size(const char *filename);
bool io_backup_file(char *file_path, char *dest_path);
bool io_create_backup_dir(char *dir);
bool io_move_file(char *file_path, char *dest_dir);
uint8_t *io_load_txt_file(char *full_path);
file_info *io_load_file(char *full_path);
bool io_save_txt_file(char *path, char *txt);
bool fallout2exe_exists(const char *game_path);
