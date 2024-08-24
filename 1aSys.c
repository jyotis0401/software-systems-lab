#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
//int symlink(const char *f2, const char *symlinkf2);
int catch=symlink("f2","symlinkf2");
// per÷ror("error");
return 0;
}