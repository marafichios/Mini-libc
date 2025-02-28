// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	int ret;
	va_list ap;
	
	va_start(ap, flags);
	mode_t mode = va_arg(ap, mode_t);
	va_end(ap);
	
	ret = syscall(__NR_open, filename, flags, mode);
	
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
