/*
============================================================================
Name : 21.c
Author : Jyoti Singh
Description : Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() {
    pid_t cpid = fork();  // Create a child process

    if (cpid == -1) {
        // Fork failed
        perror("fork");
        return 1;
    }

    if (cpid == 0) {
        // This is the child process
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID (from child): %d\n", getppid());
    } else {
        // This is the parent process
        printf("Parent process ID: %d\n", getpid());
        printf("Child process ID (from parent): %d\n", cpid);
    }

    return 0;
}
    


/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 21.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./21.c
-bash: ./21.c: Permission denied
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
Parent process ID: 71990
Child process ID (from parent): 71991
Child process ID: 71991
Parent process ID (from child): 1

*/

/*
============================================================================
Name : 
Author : Jyoti Singh
Description : 
Date: 28th Aug, 2024.
============================================================================
*/


// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>

// int main(){

//     return 0;
// }