/*
Name: 2.c
Author: MT2024072
Description: Program to print the system resource limits using getrlimit system call.
Date: 10 sep 2024
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include<sys/resource.h>
int main() {
    struct rlimit limits;
    int resource;

    for (resource = 0; resource < RLIM_NLIMITS; resource++) {
        if (getrlimit(resource, &limits) == -1) {
            fprintf(stderr, "Error for resource %d\n", resource);
            continue;
        }
        printf("Resource %d: soft limit=%llu, hard limit=%llu\n", resource, limits.rlim_cur, limits.rlim_max);
    }

    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 2.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Resource 0: soft limit=9223372036854775807, hard limit=9223372036854775807
Resource 1: soft limit=9223372036854775807, hard limit=9223372036854775807
Resource 2: soft limit=9223372036854775807, hard limit=9223372036854775807
Resource 3: soft limit=8388608, hard limit=67104768
Resource 4: soft limit=0, hard limit=9223372036854775807
Resource 5: soft limit=9223372036854775807, hard limit=9223372036854775807
Resource 6: soft limit=9223372036854775807, hard limit=9223372036854775807
Resource 7: soft limit=709, hard limit=1064
Resource 8: soft limit=256, hard limit=9223372036854775807

*/