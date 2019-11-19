# CPU Scheduling

## Introduction

**Problem Statement:**

Write a program to simulate the scheduling of processes in an operating system.

The following CPU scheduling algorithms are implemented in this C project:

* First Come First Serve
* Shortest Job First
* Priority Based Scheduling
* Round Robin Scheduling

** **

## Usage
Compile using:
```
> make -f makefile.mk
```

To compile without makefile, use:
```
> gcc main.c fcfs.c sjf.c prioritybased.c roundrobin.c queue.c time.c
```

Execute using:
```
> a.exe < inputs.txt
```

To add custom inputs to the program, modify the `inputs.txt` file, following the format below:

```
<Number Of Test Cases>

<Number Of Processes in Test Case 1>
<Process ID> <Burst Time> <Priority>
<Process ID> <Burst Time> <Priority>
<Process ID> <Burst Time> <Priority>
...etc

<Number Of Processes in Test Case 2>
<Process ID> <Burst Time> <Priority>
<Process ID> <Burst Time> <Priority>
<Process ID> <Burst Time> <Priority>
...etc

and so on.
```

Contents of a sample `inputs.txt` file are given below:
```
2

3
1 10 2
2 5 0
3 8 5

3
1 3 0
2 4 0
3 3 0
```

** **

## Team Members
* Naveen K Murthy - PES2201800051
* Roshan Daivajna - PES2201800372