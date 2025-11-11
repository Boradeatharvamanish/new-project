// OS-3 FCFS
// Code:

#include<stdio.h>
#include<stdlib.h>

struct process {
int pid;
int at;
int bt;
int ct;
int tat;
int wt;
};

int main(){
int n;
printf("ENTER THE NO OF PROCESSES YOU WANT :");
scanf(" %d",&n);
struct process p[n];

for(int i=0;i<n;i++){
p[i].pid=i+1;

printf("ADD THE ARRIVAL TIME AND BURST TIME OF PROCESS %d",p[i].pid);
scanf("%d %d", &p[i].at ,&p[i].bt);

}



int current_time=0;
float atat=0, awt=0;

for(int i=0;i<n;i++){
if(current_time<p[i].at)
current_time=p[i].at;
p[i].ct=current_time+p[i].bt;
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
current_time=p[i].ct;
atat+=p[i].tat;
awt+=p[i].wt;
}

// display the table:
printf("\n%-10s%-10s%-10s%-10s%-10s%-10s\n","process","at","bt","ct","tat","wt");
for(int i=0;i<n;i++){
printf("p%-9d%-10d%-10d%-10d%-10d%-10d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

}

printf("\nAVERAGE TAT : %.2f\n", atat/n);
printf("AVERAGE WT  : %.2f\n", awt/n);


printf("\nPRINTING THE GANTT CHART:\n");
printf("%d", p[0].at);
for (int i = 0; i < n; i++) {
printf(" - p%d - %d", p[i].pid, p[i].ct);
}
printf("\n");


return 0;


}
