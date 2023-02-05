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
*   creation of the pipe, two file descriptors are created, the first one ``fd[0]`` being the read end and the second one ``fd[1]`` the write end of the pipe
*   creating a child process for each command, implementing ``wait()`` between them so that the first child process is terminated before the second is created
*   first child process: open the file in read mode and redirect the ``stdin`` to it, redirect the ``stdout`` to the write end of the pipe (``fd[1]``)
*   
*   parsing the environment variables: check if the command passed as an argument is accessible using ``acess()``, first in the current directory, then in every path included in the PATH environment variable
*   executing the command using ``execve()``
*   error management: creating a function and a proper header file with error messages and implementing all the different conditions when an error message should be sent

## Result 

Here are examples of commands and their execution with my program: 

## Tips for 42 students 
*   if you haven't worked with structs before, take the opportunity to do so at the beginning of the project, you will need them
*   before coding a new function, think of the functions you already have in libft and see if you can use them (obviously you can also use ft_printf und       get_next_line for this project), HOWEVER: every problem can be solved in different ways, so don't feel obligated to use code from previous projects if     you think of a better solution (for example, I preferred to read the file character by character and put it in one string first before converting it       to a 2D-array instead of using gnl)
*   concerning the images, my first reflex was to allocate memory on the heap every loophook but it's more convenient and less risky for leaks to simply       put them in a struct as pointer to ``mlx_image_t``
*   at the beginning, the players movement lagged a bit because of the rendering queue that kept growing, so I decided to delete and rerender the images       at every hook (however a better approach would be to delete and rerender only when something moves)
*   for the enemy movement I used the C-function ``rand()`` to decide in which direction the enemy would move. The enemy can move one tile at a time in       any direction. To achieve this, I needed a random number between -1 and 1, which I obtained using this formula: ``(rand() % 3) - 1``. I then added         the randomly generated number to the x and y coordinates of the enemy to make it move accordingly. This means it can also move diagonally.
*   for the sprite animation, I alternate between two images at a given frequency. This frequency is determined using a gameloop-count and a speed             variable. Every loop, I check if the result of ``gameloop-count % speed`` is over or under half the speed. One image or the other is shown                 respectively
*   make sure you clean your old assets and messages/strings that you put in the window, you can use the MLX42-function ``mlx_delete_image`` to do so
*   for leaks detection I used ``leaks -atExit -- ./so_long [a map-file]`` instead of valgrind. Xcode’s leaks function is a very handy tool and is already     preinstalled on the school computers

## What I learned 
I learned that environment variables are a thing and how to use them. 
