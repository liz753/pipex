# pipex
handling pipes in C language

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

PID 

## Divide and Conquer 
I got started with identifying the concepts that were new to me.

<ins>1. Research</ins>
*   ch
*   im
*   i

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
*   when fork is called, all open fd's are duplicated to the child process
*   when you're working with envp, it's better to make a copy of it, this way you don't risk modifying it by mistake
*   if you want to avoid scrolling down each time, you can use this valgrind cmd: 
    ``valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./<program> <args>``
    e.g: ``valgrind --leak-check=full --trace-children=yes ./pipex Makefile cat cat outfile``
    

## What I learned 
I learned that environment variables are a thing, why they exist and how to use them, outside and inside a C program. I 

