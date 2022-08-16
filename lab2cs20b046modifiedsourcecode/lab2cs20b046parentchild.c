#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
	
	int pid;
	pid = fork();
     	
	if(pid > 0){
		pid = wait();
		printf(1, "child id  = %d\n", pid);
		int parentid = getpid();
		printf(1, "parent's process id = %d\n", parentid);
	}
	else if(pid == 0){
		char* argv[2];
		argv[0] = "1";
		argv[1] = "2";
		exec("./lab3cs20b046add2", argv);
		printf(1,"child exiting\n");
		
		
		exit();
	}
	else{
		printf(1, "fork error \n");
	}
	exit();
}
