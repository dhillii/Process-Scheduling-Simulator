#include<iostream>
#include "scheduler.h"

using namespace std;

char initPrompt();

int main(){
    char choice = initPrompt();

    switch(choice){
        case 'F':
        case 'f':
        case 'R':
        case 'r':
        case 'P':
        case 'p':
            cout << "You entered " << choice << endl;
            break;
        default:
            cout << "The choice you entered is invalid. Exiting..." << endl;
            exit(0);
    }

    RR_Scheduler Scheduler;

    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int  burst_time[] = {10, 5, 8}; 

    Scheduler.findavgTime(processes, n, burst_time, 2);

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