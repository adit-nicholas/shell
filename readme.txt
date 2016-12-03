Nicholas Adit and Nicholas Adit

Features:
Forks and executes commands, including exit and cd

Attemped:
Run multiple commands
Redirection 
Piping
(NOTHING iS WORKING)

Things that didn't work:
When trying to do multiple commands , it would split it into multiple commands, but wouldn't run each command.
With redirection, it couldn't find the command

Bugs:
Whenever you run cd then try to exit, it wouldn't exit the entire shell, only the cd program.
 
Functions:
int runprog(char a[]) - Takes the command, parses through the string and executes program

int main() - The actual "shell", will take the command from the line and forks , one running the process while the other waits

*IN PROGRESS*
char trim(char orig[]) - Tries to trim the string 

int multcmd(char cmd[]) - Will try to execute multiple commands by parsing through the string if there is a ";" and forks 

My bash isn't working. If I fix it, I'll upload the full version.