<div align="center">
<img width="975" alt="Bildschirmfoto 2023-02-05 um 15 38 52" src="https://user-images.githubusercontent.com/114035440/216844572-1f81b2b9-6134-42e7-84fe-590f208f6959.png">

</div>
    
# pipex
perform a IPC (Inter Process Communication) by coding a pipe mechanism

## Table of Contents

* [Project Overview](#project-overview)
* [Divide and Conquer](#divide-and-conquer)
* [Result](#result)
* [Tips for 42 students](#tips-for-42-students)
* [What I learned](#what-i-learned)

## Project Overview

It is about the following task:
<div align="center">
<img width="733" alt="Bildschirmfoto 2023-02-04 um 20 14 04" src="https://user-images.githubusercontent.com/114035440/216796531-3096bec3-e4d4-4144-a7c7-bc73cc078171.png">
</div>

The general idea: we read from infile, execute cmd1 with infile as input, send the output to cmd2, which will write to outfile.

#### What does a pipe do? 
A pipe connects a data flow from one process to another. Generally, you attach or "pipe" the output of one process to the input of another.
<div align="center">
<img width="608" alt="Bildschirmfoto 2023-02-05 um 15 23 51" src="https://user-images.githubusercontent.com/114035440/216842946-659a516a-d7f0-4666-9a12-1237e5a958e5.png">    
</div>
source: https://www.slideshare.net/tusharkute/implementation-of-pipe-in-linux?next_slideshow=1 

## Divide and Conquer 
I got started with identifying the concepts that were new to me.

<ins>1. Research</ins>
*   concept of pipes
*   concept of pipeline
*   how to redirect input and output to and from files
*   fd's, pipe call and pid 
*   FIFO and LIFO
*   read system call
*   how to make babies in C (``fork()``)
*   the particularity of the functions ``wait()`` and ``waitpid()`` as well as ``exec()`` and ``exit()``
*   how to use ``dup2``
*   which fd has to be closed at what moment?
*   ``here_doc``

<ins>2. Code Structure</ins>
*   creating a Makefile that doesn't relink
*   creating a header file 

<ins>3. Implementation</ins>
*   creation of the pipe, two file descriptors are created, the first one ``fd[0]`` being the read end and the second one ``fd[1]`` the write end     of the pipe
*   creating a child process for each command, implementing ``wait()`` between them so that the first child process is terminated before the         second is created
*   first child process: open the infile in read mode and redirect the ``stdin`` to it, redirect the ``stdout`` to the write end of the pipe         (``fd[1]``)
*   second child process: open the outfile in write mode and redirect the ``stdin``to ``fd[0]``and the ``stdout`` to the outfile 
*   close all the fd's
*   parsing the environment variables: check if the command passed as an argument is accessible using ``acess()``, first in the current               directory, then in every path included in the PATH environment variable
*   executing the command using ``execve()``
*   error management: creating a function and a proper header file with error messages and implementing all the different conditions when an         error message should be sent (e.g. number of args, existing files, files rights, existing cmds)

## Result 

Here are examples of commands and their execution with my program: 

## Tips for 42 students 
*   make sure you fully understand the functions you need to use for your pipe creation and how pipes work generally, I find this article very       helpful: https://www.rozmichelle.com/pipes-forks-dups/
*   I personally find it cleaner and easier to understand to use one child process for each command since it's clear what is excecuted when and       the parent process stays in the main
*   read the man pages ``man 2 wait``, ``man perror`` and ``man dup2``
*   when fork is called, all open fd's are duplicated to the child process
*   when you're working with envp, it's better to make a copy of it, this way you don't risk modifying it by mistake
*   if you want to avoid scrolling down each time, you can use this valgrind cmd: 
    ``valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./<program> <args>``
    e.g: ``valgrind --leak-check=full --trace-children=yes ./pipex Makefile cat cat outfile``
    
A little diagram I made that helped my visual brain understand IPC:


## What I learned 
By completing this project, I learned how to execute shell commands from within a program. Additionally, I learned that environment variables are a thing, why they exist and how to use them, outside and inside a C program. I generally deepened my understanding of processes and the communication between them as well as the difference between programs and processes. I learned how to correctly use file descriptors and  gained experience with reading from and writing to files. Overall, I gained an insight on process management, program execution and data handling. 
