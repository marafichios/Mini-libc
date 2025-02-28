// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <unistd.h>


unsigned int sleep(unsigned int seconds)
{
    struct timespec req = {seconds, 0};
    struct timespec rem = {0, 0};
    int ret = nanosleep(&req, &rem);
    if (ret < 0) {
        return rem.tv_sec;
    }
    else {
        return 0;
    }
}