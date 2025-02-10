#include<stdio.h>
int main()
{
   int n,i,j,temp;
   printf("enter number of process");
   scanf("%d",&n);
   
   int bt[n],wt[n],tat[n],p[n];
   for(i=0;i<n;i++) {
     printf("enter burst time for process P%d",i+1);
     scanf("%d",&bt[i]);
     p[i]=i+1;
  }
  
  for(i=0;i<n-1;i++){
     for(j=i+1;j<n;j++) {
        if(bt[i]>bt[j]) {
            temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
       }
    }
 }
 
 wt[0]=0;#include<stdio.h>
int main()
{
   int n,i,j,temp;
   printf("enter number of process");
   scanf("%d",&n);
   
   int bt[n],wt[n],tat[n],p[n];
   for(i=0;i<n;i++) {
     printf("enter burst time for process P%d",i+1);
     scanf("%d",&bt[i]);
     p[i]=i+1;
  }
  
  for(i=0;i<n-1;i++){
     for(j=i+1;j<n;j++) {
        if(bt[i]>bt[j]) {
            temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
       }
    }
 }
 
 wt[0]=0;
 tat[0]=bt[0];
 for(i=1;i<n;i++) {
    wt[i]=wt[i-1]+bt[i-1];
    tat[i]=wt[i]+bt[i];
 }
 
 printf("\nprocess\tburst time\twaiting time\tturn around time\n");
 for(i=0;i<n;i++){
   printf("P%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
 }
 int totalwaitingtime=0;
 for( i=0;i<n;i++) {
    totalwaitingtime+=wt[i];
  }
   printf("average waiting time: %.2f",(float)totalwaitingtime/n);
   
 
}
            
       
   
	
 tat[0]=bt[0];
 for(i=1;i<n;i++) {
    wt[i]=wt[i-1]+bt[i-1];
    tat[i]=wt[i]+bt[i];
 }
 
 printf("\nprocess\tburst time\twaiting time\tturn around time\n");
 for(i=0;i<n;i++){
   printf("P%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
 }
 int totalwaitingtime=0;
 for( i=0;i<n;i++) {
    totalwaitingtime+=wt[i];
  }
   printf("average waiting time: %.2f",(float)totalwaitingtime/n);
   
 
}
            
       
   
	
