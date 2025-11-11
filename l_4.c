// OS_4

// CODE:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct process {
int pid;
int at;
int bt;
int ct;
int rt;
int tat;
int wt;
int completed;
};

int main() {
int n;
printf("ENTER THE NO OF PROCESSES YOU WANT: ");
scanf("%d", &n);
struct process p[n];
for (int i = 0; i < n; i++) {
p[i].pid = i + 1;
printf("ADD THE ARRIVAL TIME AND BURST TIME OF PROCESS %d: ", p[i].pid);
scanf("%d %d", &p[i].at, &p[i].bt);
p[i].rt = p[i].bt; 
p[i].completed = 0;
  }

for(int i=0;i<n;i++){

printf("THE AT AND BT OF %d is %d %d",p[i].pid,p[i].at,p[i].bt);
printf("\n");
}

int current_time = 0;
int count = 0; 
float atat = 0, awt = 0;

printf("\nGANTT CHART:\n");
while (count < n) {
int idx = -1;
int min_rt = INT_MAX;
for (int i = 0; i < n; i++) {
if (p[i].at <= current_time && !p[i].completed && p[i].rt < min_rt) {
min_rt = p[i].rt;
idx = i;
}
}

if (idx == -1) {
current_time++; 
}
else {
printf("%d-- p%d--", current_time, p[idx].pid);
p[idx].rt--;
current_time++;

if (p[idx].rt == 0) {
p[idx].completed = 1;
p[idx].ct = current_time;
p[idx].tat = p[idx].ct - p[idx].at;
p[idx].wt = p[idx].tat - p[idx].bt;
atat += p[idx].tat;
awt += p[idx].wt;
count++;
}
}
}
printf(" %d \n", current_time);


printf("\n%-10s%-10s%-10s%-10s%-10s%-10s\n", "process", "at", "bt", "ct", "tat", "wt");
for (int i = 0; i < n; i++) {
printf("p%-9d%-10d%-10d%-10d%-10d%-10d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
 }

printf("\nAVERAGE TAT : %.2f\n", atat / n);
printf("AVERAGE WT  : %.2f\n", awt / n);

return 0;
}

