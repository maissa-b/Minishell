# Minishell
## The project Minishell is a project from 42'school, in the Unix branch

This project is the first step to create the bash-like shell, 42sh.
In this project, we learn about fork and execve, how to parse command line
to adapt behavior in consequence and environment.
We had to make builtins which are similar to "env", "cd", "exit", "setenv",
"unsetenv". In execution's processus, i had to check if the command was
a builtin, if it's not, i had to split the environment string variable "PATH"
with ":", and test command line with absolute path.

The features seen here are :
	
	- fork and child process,
	- execve,
	- basic syntaxic parsing (";" and builtins/binary commands),
	- environment gesture;
