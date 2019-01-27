#ifndef SCHEDULER_H
#define SCHEDULER_H

class FCFS_Scheduler{
   
    private:
        void findWaitingTime(int processes[], int n,int bt[], int wt[]);
        void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[]);
    
    public:
        void findavgTime( int processes[], int n, int bt[]);

};

class RR_Scheduler{
    private:
        void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum);
        void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);

    public:
        void findavgTime(int processes[], int n, int bt[], int quantum);

};

class Priority_Scheduler{


};


#endif