#include<iostream>
#include "scheduler.h"
#include<vector>

using namespace std;

char initPrompt();

int main(){
    int numProc, quantum;
    int bt;
    int priority;
    int burst_times[100];    
    int processes[100];
    Process P_Processes[100];
    

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
            cout << " Enter the number of Processes: ";
            cin >> numProc;

            for(int i = 0; i < numProc; i++){
                int temp = i;   //protect i value from being mutated
                
                P_Processes[temp].pid = temp+1;

                cout << endl << " Enter the burst time for Process " << P_Processes[temp].pid <<": ";
                cin >> bt;
                P_Processes[temp].bt = bt;

                cout << endl << " Enter the priority for Process " << P_Processes[temp].pid <<": ";
                cin >> priority;
                P_Processes[temp].priority = priority;
            }
            cout << endl << "....................PRIORITY SCHEDULING SIMULATION...................." << endl;
            Priority_Scheduler P_Scheduler;
            P_Scheduler.priorityScheduling(P_Processes, numProc);

            break;

        case 'S':
        case 's':
            cout << " Enter the number of Processes: ";
            cin >> numProc;

            for(int i = 0; i < numProc; i++){
                int temp = i;   //protect i value from being mutated
                
                P_Processes[temp].pid = temp+1;

                cout << endl << " Enter the burst time for Process " << P_Processes[temp].pid <<": ";
                cin >> bt;
                P_Processes[temp].bt = bt;

                cout << endl << " Enter the arrival time for Process " << P_Processes[temp].pid <<": ";
                cin >> priority;
                P_Processes[temp].arr_time = priority;
            }
            cout << endl << "....................PREEMPTIVE SHORTEST JOB FIRST SIMULATION...................." << endl;
            PSJF_Scheduler SJF_Scheduler;
            SJF_Scheduler.findavgTime(P_Processes, numProc);
            break;
        default:
            cout << " The choice you entered is invalid. Exiting..." << endl;
            exit(0);
    }
    return(0);
}


char initPrompt(){
    char choice;
    cout << " Please choose your desired scheduling algorithm:" << endl;
    cout << " (F): FCFS | (R): Round Robin | (P): Priority | (S): Preemptive Shortest Job First" << endl;
    cout << " > ";
    cin >> choice;
    return choice;
}