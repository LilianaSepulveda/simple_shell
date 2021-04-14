# 0x16. C - Simple Shell
***

In this project we are going to create a simple UNIX command interpreter in interactive and non-interactive mode, in c language.

## Table of Contents
1. [Description](#Description.-what-is-shell)
2. [Requirements](#Requirements-of-the-project)
	* ## *Objective*
	* ## *General-Requirements*
3. [Invocation](#Invocation)
	* ## Testing-interactive-and-non--interactive-mode)
4. [Functions used](#Functions-used)
5. [Process Flow Diagram](#Process-Flow-Diagram)
6. [Authors](#Authors)



## Description
***
shell is a program that provides a user interface for interpreting commands and invoking or executing the different programs available in the operating system.
A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems.


## Requirements-of-the-project
***


### Objective

Write a simple UNIX command interpreter.


### General Requirements

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to


## Invocation
***

[filename] = __hsh.c__

To invoke the shell, compile all .c files in the repository with the flags and run the resulting executable, this way:


![how compile the shell](https://i.imgur.com/ZCCjWya.png)


### Testing interactive and non-interactive mode

Shell can be invoked both interactively and non-interactively.
If shell is invoked with standard input not connected to a terminal, it reads and executes received commands. Should work like this:

![non-interactive mode](https://i.imgur.com/bDLubDu.png)

but also if shell is invoked with standard input connected to a terminal the interactive mode of shell is opened. Here displays the prompt $ when it is ready to read a command,should work like this:

![interactive mode](https://i.imgur.com/bnm8gPj.png)


## Functions used
***


__List of functions used in shell development.__

![Fucntions](https://i.imgur.com/ChCMUXO.png)


## Authors
***
* Yael Uribe <[YaelUribe](https://github.com/YaelUribe)>
* Liliana Sepulveda Lindarte <[LilianaSepulveda](https://github.com/LilianaSepulveda)>
		<img src="https://www.holbertonschool.com/holberton-logo.png" width="360"/>

