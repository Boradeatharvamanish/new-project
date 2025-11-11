#include<stdio.h>
#include<stdbool.h>

#define max_proc 10
#define max_resource 10

int n,m;
int alloc[max_proc][max_resource];
int max[max_proc][max_resource];
int need[max_proc][max_resource];
int avail[max_resource];

bool safety_algo(int safeseq[]){
    int work[max_resource];
    bool finish[max_proc] = {false};

    for(int i=0; i<m; i++)
        work[i] = avail[i];

    int count = 0;
    while(count < n){
        bool found = false;
        for(int i=0; i<n; i++){
            if(!finish[i]){
                bool canAllocate = true;
                for(int j=0; j<m; j++){
                    if(need[i][j] > work[j]){
                        canAllocate = false;
                        break;
                    }
                }
                if(canAllocate){
                    for(int j=0; j<m; j++){
                        work[j] += alloc[i][j];
                    }
                    safeseq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if(!found){
            return false;
        }
    }
    return true;
}

int main(){
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    printf("Enter the number of resources\n");
    scanf("%d", &m);

    printf("Enter the allocation matrix\n");
    for(int i=0; i<n; i++){
        printf("p%d:", i);
        for(int j=0; j<m; j++){
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the maximum matrix\n");
    for(int i=0; i<n; i++){
        printf("p%d:", i);
        for(int j=0; j<m; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources\n");
    for(int i=0; i<m; i++){
        scanf("%d", &avail[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }


    printf("allocation matrix:\n");
    for(int i=0; i<n; i++){
        printf("p%d: ", i);
        for(int j=0; j<m; j++){
            printf("%d ", alloc[i][j]);
        }
        printf("\n");
    }

    printf("need matrix:\n");
    for(int i=0; i<n; i++){
        printf("p%d: ", i);
        for(int j=0; j<m; j++){
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("available resources:\n");
    for(int i=0; i<m; i++){
        printf("%d ", avail[i]);
    }
    printf("\n");

    int safeseq[max_proc];
    if(safety_algo(safeseq)){
        printf("System is in safe state ,Safe sequence is: ");
        for(int i=0; i<n; i++){
            printf("p%d ", safeseq[i]);
        }
        printf("\n");
    } else {
        printf("System is not in safe state.\n");
    }

    while(1) {
        int req_process;
        printf("Enter no of process making req and -1 to exit");
        scanf("%d", &req_process);
        if(req_process == -1) break;

        int req[max_resource];
        printf("Enter the request vector for process p%d:\n", req_process);
        for(int i = 0; i < m; i++) {
            scanf("%d", &req[i]);
        }

        bool valid = true;
        for(int i = 0; i < m; i++) {
            if(req[i] > need[req_process][i]) {
                valid = false;
                break;
            }
        }

        if(!valid) {
            printf("resource not there.\n");
        } else {
            for(int i = 0; i < m; i++) {
                avail[i] -= req[i];
                alloc[req_process][i] += req[i];
                need[req_process][i] -= req[i];
            }

            int safeseq2[max_proc];
            if(safety_algo(safeseq2)) {
                printf("request granted Safe sequence: ");
                for(int i = 0; i < n; i++) {
                    printf("p%d ", safeseq2[i]);
                }
                printf("\n");
            } else {
                printf("request not granted\n");

                for(int i = 0; i < m; i++) {
                    avail[i] += req[i];
                    alloc[req_process][i] -= req[i];
                    need[req_process][i] += req[i];
                }
            }
        }
    }

    return 0;
}
