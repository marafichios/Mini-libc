// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int puts(const char *s)
{
    while(*s != '\0')
    {
        syscall(__NR_write, 1, s, 1);
        s++;
    }
    syscall(__NR_write, 1, "\n", 1);
    return 0;
}