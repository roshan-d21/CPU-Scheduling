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

Execute using:
```
> ./a.exe < inputs.txt
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

** **

## Team Members
* Naveen K Murthy - PES2201800051
* Roshan Daivajna - PES2201800372