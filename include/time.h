/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef	__TIME_H
#define	__TIME_H	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/essentials.h>
#include <internal/types.h>

struct timespec {
    long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);


#ifdef __cplusplus
}
#endif

#endif