#include<iostream>
#include "scheduler.h"
#include<vector>

using namespace std;

char initPrompt();

int main(){
    int numProc, quantum;
    int bt;
    int burst_times[100];    
    int processes[100];
    

    char choice = initPrompt();

    switch(choice){
        case 'F':
        case 'f':
            cout << " Enter the number of Processes: ";
            cin >> numProc;

            for(int i = 0; i < numProc; i++){
                int temp = i;   //protect i value from being mutated
                processes[temp] = temp+1;
                cout << endl << " Enter the burst time for Process " << temp+1 <<": ";
                cin >> bt;
                burst_times[temp] = bt;
            }

            cout << endl << "....................FCFS SIMULATION...................." << endl;
            FCFS_Scheduler F_Scheduler;
            F_Scheduler.findavgTime(processes, numProc, burst_times);
            break;

        case 'R':
        case 'r':
            cout << " Enter the number of Processes: ";
            cin >> numProc;

            cout << " Enter the Quantum: ";
            cin >> quantum;

            for(int i = 0; i < numProc; i++){
                int temp = i;   //protect i value from being mutated
                processes[temp] = temp+1;
                cout << endl << " Enter the burst time for Process " << temp+1 <<": ";
                cin >> bt;
                burst_times[temp] = bt;
            }

            cout << endl << "....................ROUND ROBIN SIMULATION...................." << endl;
            RR_Scheduler R_Scheduler;
            R_Scheduler.findavgTime(processes, numProc, burst_times, quantum);

            break;
        case 'P':
        case 'p':
            
            break;
        default:
            cout << "The choice you entered is invalid. Exiting..." << endl;
            exit(0);
    }
    return(0);
}


char initPrompt(){
    char choice;
    cout << " Please choose your desired scheduling algorithm:" << endl;
    cout << " (F): FCFS | (R): Round Robin | (P): Priority" << endl;
    cout << " > ";
    cin >> choice;
    return choice;
}