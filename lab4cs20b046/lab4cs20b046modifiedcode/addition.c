#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char*argv[]){
int x=0;
int y=0;

x=atoi(argv[0]);
y=atoi(argv[1]);
//printf(1, "argv[0] %d\n", argv[0]);
//printf(1, "argv[1] %d\n", argv[1]);
//printf(1, "a = %d\n", x );
//printf(1, "b = %d\n", y );
printf(1,"%d \n",x+y);
exit();
}
