#include <stdio.h>
#define max 10

int main(){
int n,AT[max],WT[max],BT[max],TAT[max],CT[max],PID[max],RT[max],i,min,maxCT=0, time;
double avg_WT=0,avg_TAT=0,thrpt;
printf("Please enter number of processes\n");
scanf("%d",&n);
if(n>max){
printf("Limit exceeded.");
}
else if(n<1){
printf("No process exist or negative input.");
}
else{
for(i=0;i< n;i++){
printf("Enter details for process %d:\n",i+1);
printf("Arrival Time: ");
scanf("%d",&AT[i]);
printf("Burst Time: ");
scanf("%d",&BT[i]);
PID[i]=i+1;
}
//sorting for arrival time
int temp;
for(i=0;i<n -1;i++){
min=i;
for(int j=i+1;j< n;j++){
if(AT[j]< AT[min]){
min=j;
}
}
if(min!=i){
temp=AT[i];
AT[i]=AT[min];
AT[min]=temp;

temp=BT[i];
BT[i]=BT[min];
BT[min]=temp;

temp=PID[i];
PID[i]=PID[min];
PID[min]=temp;
}
}

for(i=0;i< n;i++){
RT[i]=BT[i];
}

RT[n]=9999;
int smallest, cnt=0;
for(time=0;cnt!=n;time++){
    smallest=n;
    for(i=0;i< n;i++){
        if(AT[i]<=time && RT[i]< RT[smallest] && RT[i]>0){
            smallest=i;
        }
    }
    RT[smallest]--;
    if(RT[smallest]==0){
        cnt++;
        thrpt=time+1;
        CT[smallest]=thrpt;
        if(maxCT < thrpt)
        {
            maxCT=thrpt;
        }
    }
}

printf("Process\tArrival Time\tExecution Time\tCompletion Time\tTAT\tWaiting Time\n");
for(i=0;i< n;i++){
TAT[i]=CT[i]-AT[i];
WT[i]=TAT[i]-BT[i];
avg_TAT=avg_TAT+TAT[i];
avg_WT=avg_WT+WT[i];
printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",PID[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
}
avg_TAT=(double)avg_TAT/n;
avg_WT=(double)avg_WT/n;
thrpt=(double)n/(maxCT-AT[0]);
printf("\nAvg.TAT=%.2f\n",avg_TAT);
printf("Avg.WT=%.2f\n",avg_WT);
printf("Throughput=%.2f\n",thrpt);
}
return 0;
}
