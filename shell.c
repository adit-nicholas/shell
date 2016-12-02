#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

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
  //  if (strcmp(cmd[0], exit) == 0){
  // kill(getppid(),15);
  //  kill(getpid(), 15);
  //}
  if(strcmp(cmd[0],cd) == 0){
    chdir(cmd[i-1]);
  }
  execvp(cmd[0] , cmd);
  return 0;
   
}

//char trim(char orig[]){
//  char * s;
  //printf("Before: %s has %d characters\n", orig, strlen(&orig));
  //if (orig[0] == " "){
//s = strsep(&orig, " ");
//
//}
//if (orig[strlen(&orig) - 1] = " "){
//  orig[strlen(&orig) - 1] = 0;
//}
  //printf("After: %s has %d characters\n", orig, strlen(&orig)); 
// return orig;
//}

//int multcmd(char cmd[]){
//char * s;
//char a[256];
//*(strchr(cmd, '\n')) = NULL;
//while(cmd){
//  s = strsep(&cmd, ";");
//  printf("%s \n", s);
//  strcpy(a,s);
//  printf("%s \n", a);
//  trim(a);
  //  if (fork() = 0 ){
    // runprog(a);
    //}
    //else{
    // wait();
    //}
// }
//return 0;
//}

//void redirect(char cmd[]){
//if(strchr(cmd, ">") ){
//  printf("Works");
//  dup2(open(".", OCREAT | O_EXCL), dup(STDOUT_FILENO));
//  
//}
//}

int main(){
  char path [256];
  char buffer [256];
  char exit [] = "exit";
  int i = 1;
  char semicolon[] = ";";
  while(i == 1){
    getcwd(&path, 255);
    printf("%s ", path);
    fgets(&buffer, 256, stdin);
    //  redirect(buffer);
    //if ((strstr(&buffer,&semicolon))){
    //multcmd(buffer);
    //}
    else if ((strstr(&buffer,&exit))){
      printf("Terminated\n");
      return 0;
    }
    //printf("%s \n", buffer);
    else{
      if (fork() == 0){
	runprog(buffer);
      }
      else {
	wait();
      }
    }
  }
    return 0;
}
