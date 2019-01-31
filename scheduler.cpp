#include<iostream>
#include "scheduler.h"
#include <algorithm> 

using namespace std;

void FCFS_Scheduler::findWaitingTime(int processes[], int n,int bt[], int wt[]) { 
    // waiting time for first process is 0 
    wt[0] = 0; 

    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ; 
} 
        
// Function to calculate turn around time 
void FCFS_Scheduler::findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[]) { 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

//Function to calculate average time 
void FCFS_Scheduler::findavgTime( int processes[], int n, int bt[]) { 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 

    //Function to find waiting time of all processes 
    findWaitingTime(processes, n, bt, wt); 

    //Function to find turn around time for all processes 
    findTurnAroundTime(processes, n, bt, wt, tat); 

    //Display processes along with all details 
    cout << "Processes  "<< " Burst time  "
        << " Waiting time  " << " Turn around time\n"; 

    // Calculate total waiting time and total turn  
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl; 
    } 

    cout << endl <<"Average waiting time = " 
        << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " 
        << (float)total_tat / (float)n << endl; 
} 

void RR_Scheduler::findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum){ 
    // Make a copy of burst times bt[] to store remaining 
    // burst times. 
    int rem_bt[n]; 
    for (int i = 0 ; i < n ; i++) 
        rem_bt[i] =  bt[i]; 

    int t = 0; // Current time 

    // Keep traversing processes in round robin manner 
    // until all of them are not done. 
    while (1) 
    { 
        bool done = true; 

        // Traverse all processes one by one repeatedly 
        for (int i = 0 ; i < n; i++) 
        { 
            // If burst time of a process is greater than 0 
            // then only need to process further 
            if (rem_bt[i] > 0) 
            { 
                done = false; // There is a pending process 

                if (rem_bt[i] > quantum) 
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t += quantum; 

                    // Decrease the burst_time of current process 
                    // by quantum 
                    rem_bt[i] -= quantum; 
                } 

                // If burst time is smaller than or equal to 
                // quantum. Last cycle for this process 
                else
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t = t + rem_bt[i]; 

                    // Waiting time is current time minus time 
                    // used by this process 
                    wt[i] = t - bt[i]; 

                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    rem_bt[i] = 0; 
                } 
            } 
        } 

        // If all processes are done 
        if (done == true) 
        break; 
    } 
} 
  
// Function to calculate turn around time 
void RR_Scheduler::findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) { 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

    
void RR_Scheduler::findavgTime(int processes[], int n, int bt[], int quantum) { 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 

    // Function to find waiting time of all processes 
    findWaitingTime(processes, n, bt, wt, quantum); 

    // Function to find turn around time for all processes 
    findTurnAroundTime(processes, n, bt, wt, tat); 

    // Display processes along with all details 
    cout << "Processes "<< " Burst time "
        << " Waiting time " << " Turn around time\n"; 

    // Calculate total waiting time and total turn 
    // around time 
    for (int i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
            << wt[i] <<"\t\t " << tat[i] <<endl; 
    } 

    cout << endl <<"Average waiting time = "
        << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n << endl; 
} 

// Function to sort the Process acc. to priority
bool comparison(Process a, Process b){
    return (a.priority > b.priority);
}

// Function to find the waiting time for all processes 
void Priority_Scheduler::findWaitingTime(Process proc[], int n, int wt[]){
    // waiting time for first process is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  proc[i-1].bt + wt[i-1] ;
}

void Priority_Scheduler::findTurnAroundTime(Process proc[], int n, int wt[], int tat[]){
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = proc[i].bt + wt[i];
}

void Priority_Scheduler::findavgTime(Process proc[], int n){
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    //Function to find waiting time of all processes 
    findWaitingTime(proc, n, wt); 
  
    //Function to find turn around time for all processes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    //Display processes along with all details 
    cout << "\nProcesses  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t    " << wt[i] 
             << "\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n <<endl; 
}

void Priority_Scheduler::priorityScheduling(Process proc[], int n){
    // Sort processes by priority 
    sort(proc, proc + n, comparison); 
  
    cout<< "Order in which processes gets executed \n"; 
    for (int  i = 0 ; i <  n; i++) 
        cout << proc[i].pid <<" " ; 
  
    findavgTime(proc, n); 
}