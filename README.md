# Process-Scheduling-Simulator
This program simulates various process scheduling algorithms used by operating systems.

The algorithms supported by this project are:
* First Come First Serve
* Round Robin
* Priority Scheduling Algorithm
* Preemptive Shortest Job  First

## Getting Started

To run this project, you must have the GNU C++ compiler installed. 

### Windows
For Windows this can be installed with the [MINGW installer] (http://www.mingw.org/)

Install the following packages with the MINGW Installer:
* mingw32-base-bin
* mingw32-gcc-g++-bin

### Linux
```
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential libncurses5 libncurses5-dev
```
## Installation
This project is a command line tool so make sure to open either a Windows Command prompt or Linux terminal before proceeding. Once in the terminal change directory 'cd' into the directory of the project.

### Windows
To build the project run the following command:
```
> mingw32-make
```

### Linux/MacOS
To build this project in a Linux environment run the following commad:
```
$ make 
```

## Running
To run this project use the following commands depending on your platform.

### Windows
```
> Scheduler_Simulator
```

### Linux/MacOS
```
$ ./Scheduler_Simulator
```




