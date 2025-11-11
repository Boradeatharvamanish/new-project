// Sorting:
// code:
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void asc(int arr[],int n)
{
int i , j, temp;

for( i = 0 ; i < n-1 ; i++)
{
for( j = 0 ; j < n-1-i ; j++)
{
if(arr[j]>arr[j+1])
{
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
}

void desc(int arr[],int n)
{ int i , j , temp;
for(i=0 ; i < n-1 ; i++)
{
for(j=0 ; j < n-1-i ; j++)
{
if(arr[j]<arr[j+1])
{
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
}

int main()
{    
 int n;
     
 printf("Array size:");
 scanf("%d", &n);
     
 int arr[n];
 printf("Enter %d elements :\n", n);
 for(int i = 0; i < n; i++)
 {
 scanf("%d", &arr[i]);
 }
pid_t num_pid = fork();
     
     
if(num_pid<0)
{
printf("Error in fork execution");
exit(1);
}
 else if(num_pid == 0) {
       
 printf("Child process pid %d descending order\n", getpid());
 desc(arr, n);
 printf("Child sorted array: ");
 for(int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 exit(0);
 }
 else {
 printf("Parent process pid %d ascending order\n", getpid());
 asc(arr, n);
 printf("Parent sorted array: ");
 for(int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
    }
 printf("\n");
 wait(NULL);  
  }
 return 0;
             

}
    
