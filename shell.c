#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int runprog(char a[]){
  char * s;
  char * cmd[10];
  int i = 0;    
  *(strchr(a, '\n')) = NULL;
  //printf("%s \n", a);
  while (a != NULL){
    s = strsep(&a, " ");
    cmd[i] = s;
    //printf("%s %s\n", s , cmd[i]);
    i++;
    
  }
  cmd[i] = 0;
  char exit[] = "exit";
  char cd[] = "cd";
  if (strcmp(cmd[0], exit) == 0){
    kill(getppid(),15);
    kill(getpid(), 15);
  }
  if(strcmp(cmd[0],cd) == 0){
    chdir(cmd[i-1]);
  }
  execvp(cmd[0] , cmd);
  return 0;
   
}

int main(){
  char path [256];
  char buffer [256];
  while(1){
    getcwd(&path, 255);
    printf("%s ", path);
    fgets(&buffer, 256, stdin);
    //printf("%s \n", buffer);
    if (fork() == 0){
      runprog(buffer);
    }
    else {
      wait();
    }
  }
  return 0;
}
