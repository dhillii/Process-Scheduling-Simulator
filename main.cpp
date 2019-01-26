#include<iostream>
#include "scheduler.h"

using namespace std;


int main(){
    FCFS_Scheduler Scheduler;

    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int  burst_time[] = {10, 5, 8}; 

    Scheduler.findavgTime(processes, n, burst_time);

    return(0);
}