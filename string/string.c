// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	if (destination == NULL || source == NULL) {
        return NULL;
    }

    char *ptr = destination;
    while ((*ptr++ = *source++) != '\0') {
        
    }
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	if (destination == NULL || source == NULL) {
        return NULL;
    }

    size_t i;
    for (i = 0; i < len && source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }

    for (; i < len; ++i) {
        destination[i] = '\0';
    }
	return destination;
}

char *strcat(char *destination, const char *source)
{
	if (destination == NULL || source == NULL) {
        return NULL;
    }

    char *ptr = destination;
    while (*ptr != '\0') {
        ptr++;
    }

    while (*source != '\0') {
		*ptr++ = *source++;
    }
	*ptr = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	if (destination == NULL || source == NULL) {
        return NULL;
    }

	size_t dest_len = strlen(destination);
    size_t i;

    for (i = 0 ; i < len && source[i] != '\0' ; i++)
        destination[dest_len + i] = source[i];
    destination[dest_len + i] = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL) {
        return -2;
    }

    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }

        ++str1;
        ++str2;
    }

    if (*str1 == '\0' && *str2 != '\0') {
        return -1;
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    }

    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	if (str1 == NULL || str2 == NULL) {
        return -2;
    }

    while (len > 0 && *str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }

        ++str1;
        ++str2;
        --len;
    }

    if (len == 0) {
        return 0;
    }

    if (*str1 == '\0' && *str2 != '\0') {
        return -1;
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    }

	return 0;
}

size_t strlen(const char *str)
{
    if (str == NULL) {
        return 0;
    }
    const char *s;

    for (s = str; *s; ++s) {
        
    }
    return (s - str);
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
		if (*str == c) {
			return (char *)str;
		}
		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	if (str == NULL) {
        return NULL;
    }

	const char *ptr = str;

	while (*ptr != '\0') {
		ptr++;
	}
	
	while (ptr >= str) {
		if (*ptr == c) {
			return (char *)ptr;
		}
		ptr--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{	
	const char *h;
    const char *n;

    n = needle;

    if (*n == 0) {
        return (char *) haystack;
    }

    for ( ; *haystack != 0; haystack += 1) {
        if (*haystack != *n) {
            continue;
        }

        h = haystack;
        while (1) {
            if (*n == 0) {
                return (char *) haystack;
            }
            if (*h++ != *n++) {
                break;
            }
        }
        n = needle;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *ptr1 = NULL;

	if (!needle[0])
		return (char*)haystack + strlen(haystack);
	while (1) {
		char *ptr2 = strstr(haystack, needle);
		if (!ptr2)
			return ptr1;
		ptr1 = ptr2;
		haystack = ptr2 + 1;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *d = (char *)destination;
	const char *s = (const char *)source;

	for (size_t i = 0; i < num; i++) {
		d[i] = s[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *d = (char *)destination;
    const char *s = (const char *)source;

    if (d > s && d < s + num) {
        d += num;
        s += num;
        while (num-- > 0) {
            *(--d) = *(--s);
        }
    } else {
        while (num-- > 0) {
            *d++ = *s++;
        }
    }
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *p1 = ptr1;
    const unsigned char *p2 = ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
	unsigned char* ptr = (unsigned char*)source;
	while (num-- > 0)
		*ptr++ = value;
	return source;
}

//Documentation:
//https://manual.cs50.io/
//https://opensource.apple.com/source/tcl/
//https://opensource.apple.com/source/gcc/
//https://opensource.apple.com/source/Libc/