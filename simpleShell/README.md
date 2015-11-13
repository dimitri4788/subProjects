Simple Unix Shell
=================

A simple Unix shell interpreter (e.g., bash, csh etc.).

Description
-----------
- Type of commands: *built-in* commands and *non built-in* commands
    - Built-in commands are executed without creating a new process
        - cd, exit and two commands (!# and !) based on a history feature
            - !#: Prints a list of all the commands saved in the history separated by newlines.
            - !query: Re-executes the last command whose prefix matches query
    - Non built-in commands are executed by creating a new process
        - pwd, ls, echo Hello, etc.

How to Build
------------
```sh
$ mkdir build bin lib
$ cd build
$ cmake ..
$ make
```

Usage
-----
Running shell
```sh
$ cd bin
$ ./simpleShell
```
<br>
Running unit-tests
```sh
$ cd bin
$ ./test_log
```

Author
------
Deep Aggarwal  
deep.uiuc@gmail.com  
Date Created: 11/05/2015  
