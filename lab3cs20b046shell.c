#include "types.h"
#include "stat.h"
#include "user.h"
#include "math.h"

void cursor(){
        printf(1, "CS20B046$ ");
}


void execute(int a,int b, char ch){
	
	if(ch == '+')
		printf(1,"%d\n", a+b);
	if(ch == '*')
		printf(1,"%d\n", a*b);

	if(ch == '-')
		printf(1,"%d\n", a-b);

	/*
	int pid=fork();
        if(pid>0){
                pid=wait();
                //printf(1,"Child Process id is: %d\n",pid);
                int parent_id=getpid();
                //printf(1,"The parent's process id is: %d\n",parent_id);
        }else if(pid==0){
		if(ch == '+')
                	exec("./addition",argv);
                if(ch == '-')
			exec("./subtraction",argv);
		if(ch == '*')
			exec("./multiplication", argv);



                //printf(1,"Exited from child successfully\n");
                exit();
        }
        else{
                printf(1,"Fork error!\n");
        }
	*/
}

void parse(char *buff){
	int len = strlen(buff);
	// checking the echo case
	if(len >= 5){
		if(buff[0] == 'e' && buff[1] == 'c' && buff[2] == 'h' && buff[3] == 'o' && buff[4] == ' '){
			char s[100];
			//printf(1,"echo done\n");
			for(int i = 5; i <= len; i++){
				s[i-5] = buff[i];
			}

			printf(1, "%s\n" , s);
			return;
		}
	}


	// getting arithmatic expression
	
	int a = 0, b = 0;
	int i = 0;
	for(;i<len && buff[i] != ' ' ;i++){
		int val = buff[i] - '0';
		a = a*10 + val;
	}
	i++;
	char ch = buff[i];
	i+=2;
	for(;i<=len && buff[i] != ' ' && buff[i] != '\n';i++){
                int val = buff[i] - '0';
                b = b*10 + val;
        }

//	printf(1, "%d ,%c,  %d \n", a, ch, b);
	execute(a,b,ch);

}

int getcmd(char *buf, int nbuf)
{
  cursor();
  memset(buf, 0, nbuf);
  gets(buf, 100);
  // printf(1,"string is %s", buf );
 	
  if(buf[0] == '\n')
	  return -2;
  if(buf[0] == 0) // EOF
    return -1;
  return 0;
}


int main(int argc, char* argv[]){
	static char buff[100];
	int val = 0;
	while(val != -2){
		val = getcmd(buff, 100);
		parse(buff);
	}
	printf(1, "%s" , buff);
	return 0;
}
