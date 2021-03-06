/*
 * Copyright (c) 2020 EmbedJournal
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef _UTIL_STRUTIL_H_
#define _UTIL_STRUTIL_H_

#include <stdint.h>
#include <string.h>

/*
 * atohstr() - Converts an array of bytes to its hexadecimal string
 * representation.
 *
 * Usage:
 *   uint8_t arr[4] = { 0xca, 0xfe, 0xba, 0xbe };
 *   char hstr[16];
 *   if (atohstr(hstr, arr, 4) == 0) {
 *       // hstr = "cafebabe\0";
 *   }
 *
 * Note:
 * sizeof passed char *hstr, has to be atleast (2 * arr_len) + 1.
 */
int atohstr(char *hstr, const uint8_t *arr, const int arr_len);

/*
 * hstrtoa() - Converts a hexadecimal string to it's value as array of
 * bytes.
 *
 * Usage:
 *   uint8_t arr[4];
 *   const char *hstr = "cafebabe";
 *   if (hstrtoa(arr, hstr) == 0) {
 *       // arr[4] = { 0xca, 0xfe, 0xba, 0xbe };
 *   }
 *
 * Note:
 * sizeof uint8_t *arr has to be atleast half of strlen(hstr)
 */
int hstrtoa(uint8_t *arr, const char *hstr);

/*
 * safe_atoi() - A wrapper for atoi() that returns -ve on non number-ish
 * strings. This can be used to distinguish "0" from "A" as both would
 * return 0 by the bare atoi()'s contract.
 */
int safe_atoi(const char *a, int *i);

/*
 * safe_strncpy() - A wrapper for strnlen() that guarantees null
 * terminated copy to dest. If strlen(src) > size, then only size-1
 * chars are copied to dest and a terminating '\0' is added.
 */
char *safe_strncpy(char* dest, const char* src, size_t size);

/*
 * rstrip(), lstrip(), strip() - String space trim methods, as defined
 * in python3 programming language.
 */
void rstrip(char *str);
void lstrip(char *str);
void strip(char *str);

#endif /* _UTIL_STRUTIL_H_ */