#ifndef SCHEDULER_H
#define SCHEDULER_H

class FCFS_Scheduler{
   
    private:
        void findWaitingTime(int processes[], int n,int bt[], int wt[]);
        void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);
    
    public:
        void findavgTime(int processes[], int n, int bt[]);

};

class RR_Scheduler{
    private:
        void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum);
        void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);

    public:
        void findavgTime(int processes[], int n, int bt[], int quantum);

};


 struct Process{
        int pid;  // Process ID 
        int bt;   // CPU Burst time required 
        int priority; // Priority of this process 
        int arr_time; //Arrival Time
};

bool comparison(Process a, Process b);

class Priority_Scheduler{
    private:
        void findWaitingTime(Process proc[], int n, int wt[]);
        void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]);
        void findavgTime(Process proc[], int n);
    public:
        void priorityScheduling(Process proc[], int n);
};

class PSJF_Scheduler{
    private:
        void findWaitingTime(Process proc[], int n, int wt[]);
        void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]);
        
    public:
        void findavgTime(Process proc[], int n);
};


#endif