#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int runprog(char a[]){
  char * s;
  char cmd[10];
  int i = 0;    
  strchr(a, '\n') = NULL;
  printf("%s \n", a);
  while (a != NULL){
    s = strsep(&a, " ");
    cmd[i] = s;
    printf("%s %s\n", s , cmd[i]);
    i++;
    
  }
  cmd[i] = 0;
  execvp(cmd[0] , cmd);
  return 0;
   
}

int main(){
  char * buffer = calloc (1, 256);
  fgets(&buffer, 256, stdin);
  printf("%s \n", buffer);
  if (fork() == 0){
    runprog(&buffer);
  }
  else {
    wait();
  }
  return 0;
}
