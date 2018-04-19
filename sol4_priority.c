#include<stdio.h>
int main()
{
int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
float wtavg, tatavg;
printf("\n*******ENTER THE NUMBER OF PROCESS*******\n\n\t\t\t");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i] = i;   //contains process number
printf("\nENTER THE BURST TIME OF THE PROCESS %d----->>>", i);
scanf("%d",&bt[i]);
printf("\nTEACHER/STUDENT PROCESS (0/1) ? ----->>> ");// choose process for teacher or student 
scanf("%d", &su[i]);
}
      
	
for(i=0;i<n;i++)
{
for(k=i+1;k<n;k++)
{
if(su[i] > su[k])
{
temp=p[i];
p[i]=p[k];
p[k]=temp;
				
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
				
temp=su[i];
su[i]=su[k];
su[k]=temp;
}
}
}
//calculate wating time
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];    //calculate average wating time
tatavg = tatavg + tat[i];  //calculate turnaround time
}
printf("\nPROCESS\tTEACHER/STUDENT PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	
for(i=0;i<n;i++)
{
printf("\n%d \t\t\ %d \t \t %d \t\t %d \t\t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
}

printf("\nAVERAGE WATING IS ----->>> %f",wtavg/n);
printf("\nAVERAGE TURNAROUND TIME ---->>> %f",tatavg/n);

return 0;
}
