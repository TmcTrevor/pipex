# pipex

SUBJECT :
    https://cdn.intra.42.fr/pdf/pdf/26356/en.subject.pdf
    
 ## 1 - char **envm;

([https://stackoverflow.com/questions/19198797/whats-the-use-of-the-third-environment-variable-argument-to-the-c-main](https://stackoverflow.com/questions/19198797/whats-the-use-of-the-third-environment-variable-argument-to-the-c-main))

```
int main(int argc, char* argv[], char* env[]){

std::cout << env[11] << '\n';  //this prints home directory of current user(11th for me was the home directory)

return 0;
}
```

 

> Although getenv() allows you to find the value of an environment variable you know about, it does not allow you to find the value of an environment variable whose name you don't know. The envp argument to main() and the environ global variable allow you to find all the environment variables. Thus, getenv() on its own is not a replacement for the envp argument.
> 

> It is an array containing all the environmental variables. It can be used for example to get the user name or home directory of current logged in user. One situation is, for example, if I want to hold a configuration file in user's home directory and I need to get the PATH;
> 

> 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
> 

## 2 - pid_t

> ([https://www.includehelp.com/c/process-identification-pid_t-data-type.aspx](https://www.includehelp.com/c/process-identification-pid_t-data-type.aspx))
> 

> pid_t data type stands for process identification and it is used to represent process ids. Whenever, we want to declare a variable that is going to be deal with the process ids we can use pid_t data type. The type of pid_t data is a signed integer type (signed int or we can say int)
> 

> pid_t data type stands for process identification and it is used to represent process ids. Whenever, we want to declare a variable that is going to be deal with the process ids we can use pid_t data type.
> 

> The type of pid_t data is a signed integer type (signed int or we can say int).
> 

> **Header file:**
> 

> The header file which is required to include in the program to use pid_t is sys/types.h
> 

> **There are basically two functions, which returns the process ids and if we check their return type, it is pid_t, the functions are...**
> 

> getpid() – this function returns the process id of the calling process, its syntax is, pid_t getpid()
> 

> getppid() – this function returns the parent process id in which the function is calling, its syntax is, pid_t getppid()
> 

> **Example:** program to get process id and parent process id and the data type will be pid_t
> 

```

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t process_id;
	pid_t p_process_id;

	process_id = getpid();
	p_process_id = getppid();

	printf("The process id: %d\n",process_id);
	printf("The process id of parent function: %d\n",p_process_id);

return 0;
}

```

**Output**

```
    The process id: 3614
    The process id of parent function: 3613
```

## 3 - pipe() function

([https://linuxhint.com/pipe_system_call_c/](https://linuxhint.com/pipe_system_call_c/))

**pipe()**

is a Linux system function. The

**pipe()**

system function is used to open file descriptors, which are used to communicate between different Linux processes. In short, the

**pipe()**

function is used for inter-process communication in Linux.  In this article, I am going to show you how to use the pipe() system function in Linux. So, let’s get started.

# **All About pipe() Function:**

> The syntax of the **pipe()** function is:
> 

> int pipe(int pipefd[2]);
> 

> Here, the pipe() function creates a unidirectional data channel for inter-process communication. You pass in an **int** (Integer) type array **pipefd** consisting of 2 array element to the function pipe(). Then the pipe() function creates two file descriptors in the **pipefd** array.
> 

> The first element of the **pipefd** array, **pipefd[0]** is used for reading data from the pipe.
> 

> The second element of the **pipefd** array, **pipefd[1]** is used for writing data to the pipe.
> 

> On success, the pipe() function returns 0. If an error occurs during pipe initialization, then the pipe() function returns -1.
> 

> The pipe() function is defined in the header **unistd.h**. In order to use the pipe() function in your C program, you must include the header **unistd.h** as follows:
> 

> #include <stdio.h>
> 

> #include <stdlib.h>
> 

> #include <unistd.h>
> 

> int main(void) {
> 

> int pipefds[2];
> 

> if(pipe(pipefds) == -1) {
> 

> [perror](https://www.opengroup.org/onlinepubs/009695399/functions/perror.html)
> 

> ("pipe");
> 

> [exit](https://www.opengroup.org/onlinepubs/009695399/functions/exit.html)
> 

> (EXIT_FAILURE);
> 

> }
> 

> [printf](https://www.opengroup.org/onlinepubs/009695399/functions/printf.html)
> 

> ("Read File Descriptor Value: %d\n", pipefds[0]);
> 

> [printf](https://www.opengroup.org/onlinepubs/009695399/functions/printf.html)
> 

> ("Write File Descriptor Value: %d\n", pipefds[1]);
> 

> return EXIT_SUCCESS;
> 

> }
> 

# 4 - fork() in C

> ([https://www.geeksforgeeks.org/fork-system-call/](https://www.geeksforgeeks.org/fork-system-call/))
> 

> Fork system call is used for creating a new process, which is called ***child process***, which runs concurrently with the process that makes the fork() call (parent process). After a new child process is created, both processes will execute the next instruction following the fork() system call. A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process.
> 

> It takes no parameters and returns an integer value. Below are different values returned by fork().
> 

> ***Negative Value***: creation of a child process was unsuccessful.
> 

> ***Zero***: Returned to the newly created child process.
> 

> ***Positive value***: Returned to parent or caller. The value contains process ID of newly created child process.
> 

## 5 - Dup() and Dup2()

([https://www.geeksforgeeks.org/dup-dup2-linux-system-call/](https://www.geeksforgeeks.org/dup-dup2-linux-system-call/))

## 6 - Access

### *NAME*

> access - determine accessibility of a file
> 

### *SYNOPSIS*

> #include <unistd.h>int access(const char *path, int amode);
> 

### *DESCRIPTION*

> The access() function shall check the file named by the pathname pointed to by the path argument for accessibility according to the bit pattern contained in amode, using the real user ID in place of the effective user ID and the real group ID in place of the effective group ID.The value of amode is either the bitwise-inclusive OR of the access permissions to be checked (R_OK, W_OK, X_OK) or the existence test (F_OK).If any access permissions are checked, each shall be checked individually, as described in the Base Definitions volume of IEEE Std 1003.1-2001, Chapter 3, Definitions. If the process has appropriate privileges, an implementation may indicate success for X_OK even if none of the execute file permission bits are set.
> 

### *RETURN VALUE*

> If the requested access is permitted, access() succeeds and shall return 0; otherwise, -1 shall be returned and errno shall be set to indicate the error.
> 

## 7 - Execve

## **NAME [top](https://man7.org/linux/man-pages/man2/execve.2.html#top_of_page)**

```
       execve - execute program

```

## **SYNOPSIS [top](https://man7.org/linux/man-pages/man2/execve.2.html#top_of_page)**

```
#include <unistd.h>int execve(const char *pathname, char *constargv[],char *constenvp[]);
```

## **DESCRIPTION [top](https://man7.org/linux/man-pages/man2/execve.2.html#top_of_page)**

```
execve() executes the program referred to bypathname.  This
       causes the program that is currently being run by the calling
       process to be replaced with a new program, with newly initialized
       stack, heap, and (initialized and uninitialized) data segments.

```

## **RETURN VALUE [top](https://man7.org/linux/man-pages/man2/execve.2.html#top_of_page)**

```
       On success,execve() does not return, on error -1 is returned,
       anderrno is set to indicate the error.
```

## NB : for Open (......, 0777)

> If you're passing them to chmod (the command-line program), there is no difference. But in a C program or similar, 0777 is octal (three sets of three 1 bits, which is what you intend), while 777 is decimal, and it's quite a different bit pattern. (chmod will interpret any numeric argument as octal, hence no leading zero is necessary.)
> 

# 8 - waitpid() — Wait for a specific child process to end

([https://www.ibm.com/docs/en/zos/2.1.0?topic=functions-waitpid-wait-specific-child-process-end](https://www.ibm.com/docs/en/zos/2.1.0?topic=functions-waitpid-wait-specific-child-process-end))

## Standards

[Untitled](https://www.notion.so/41b256733813429ab1c9a3a18394d5e8)

## Format

`#define _POSIX_SOURCE
#include <sys/wait.h>

pid_t waitpid(pid_t *pid*, int **status_ptr*, int *options*);`

## General description

Suspends the calling process until a child process ends or is stopped. More precisely, waitpid() suspends the calling process until the system gets status information on the child. If the system already has status information on an appropriate child when waitpid() is called, waitpid() returns immediately. waitpid() is also ended if the calling process receives a signal whose action is either to execute a signal handler or to end the process.**pid_t *pid***Specifies the child processes the caller wants to wait for:
• If *pid* is greater than 0, waitpid() waits for termination of the specific child whose process ID is equal to *pid*.
• If *pid* is equal to zero, waitpid() waits for termination of any child whose process group ID is equal to that of the caller.
• If *pid* is -1, waitpid() waits for any child process to end.
• If *pid* is less than -1, waitpid() waits for the termination of any child whose process group ID is equal to the absolute value of *pid*.**int **status_ptr***Points to a location where waitpid() can store a status value. This status value is zero if the child process explicitly returns zero status. Otherwise, it is a value that can be analyzed with the status analysis macros described in “Status Analysis Macros”, below.The *status_ptr* pointer may also be NULL, in which case waitpid() ignores the child's return status.**int *options***Specifies additional information for waitpid(). The *options* value is constructed from the bitwise inclusive-OR of zero or more of the following flags defined in the sys/wait.h header file

## Returned value

If successful, waitpid() returns a value of the process (usually a child) whose status information has been obtained.

If WNOHANG was given, and if there is at least one process (usually a child) whose status information is not available, waitpid() returns 0.

If unsuccessful, waitpid() returns -1 and sets errno
