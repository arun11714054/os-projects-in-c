#include<stdio.h>
#include<string.h>
int main()
{
    char pro_Name[15][6],tmpy[5];
    int i,j,pro_Time[10],wai_Time[10],total_wai_Time=0,priority[20],tmpy1,n;
    float A_wai_Time;
    printf("Enter the Number of Processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the process %d name:",i+1);
        scanf("%s",&pro_Name[i]);
        printf("Enter the Process Time:");
        scanf("%d",&pro_Time[i]);
        printf("Enter the Priority:");
        scanf("%d",&priority[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(priority[i]>priority[j])
            {
                tmpy1=priority[i];
                priority[i]=priority[j];
                priority[j]=tmpy1;
                tmpy1=pro_Time[i];
                pro_Time[i]=pro_Time[j];
                pro_Time[j]=tmpy1;
                strcpy(tmpy,pro_Name[i]);
                strcpy(pro_Name[i],pro_Name[j]);
                strcpy(pro_Name[j],tmpy);
            }
        }
    }
    wai_Time[0]=0;
    for(i=1;i<n;i++)
    {
        wai_Time[i]=wai_Time[i-1]+wai_Time[i-1];
        total_wai_Time=total_wai_Time+wai_Time[i];
    }
    A_wai_Time=(float)total_wai_Time/n;
    printf("Process Name\t Process Time\t Priority\t Waiting Time\n");
    for(i=0;i<n;i++)
    {
       printf(" %s\t %d\t %d\t %d\n" ,pro_Name[i],pro_Time[i],priority[i],wai_Time[i]);
    }
    printf("Total Waiting Time=%d\n",total_wai_Time);
    printf("Avg waiting time=%f",A_wai_Time);
   
    int Time_slice,pid[10],Need[10],wai_Time1[15],T_A_Time[10],k,l,m,o;
    int B_Time[10],flag[10],total_T_A_Time=0,total_wai_Time1=0;
    float A_wai_time,Atat;
    printf("\nEnter the number of Processors \n");
    scanf("%d",&n);
    m=n;
    printf("\n Enter the Time slice \n");
    scanf("%d",&Time_slice);
    for(i=1;i<=n;i++)
    {
        printf("\n Enter the process ID %d",i);
        scanf("%d",&pid[i]);
        printf("\n Enter the Burst Time for the process");
        scanf("%d",&B_Time[i]);
        Need[i]=B_Time[i];
    }
    for(i=1;i<=n;i++)
    {
        flag[i]=1;
        wai_Time[i]=0;
    }
    while(n!=0)
    {
        for(i=1;i<=n;i++)
        {
            if(Need[i]>=Time_slice)
            {
                for(j=1;j<=n;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(Need[j]!=0))
                    wai_Time[j]=wai_Time[j]+Time_slice;
                }
                Need[i]=Need[i]-Time_slice;
                if(Need[i]==0)
                {
                    flag[i]=0;
                    n--;
                }
            }
            else
            {
                for(j=1;j<=n;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(Need[j]!=0))
                    wai_Time[j]+=Need[i];
                }
                Need[i]=0;
                n--;
                flag[i]=0;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        T_A_Time[i]=wai_Time[i]+B_Time[i];
        total_wai_Time1=total_wai_Time+wai_Time[i];
        total_T_A_Time=total_T_A_Time+T_A_Time[i];
    }
    A_wai_Time=(float)total_wai_Time1/m;
    Atat=(float)total_T_A_Time/m;
    printf("\n\n Process \t Process ID  \t Burst Time \t Waiting Time \t Turn around Time \n ");
    for(i=1;i<=m;i++)
    {
        printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,pid[i],B_Time[i],wai_Time[i],T_A_Time[i]);
    }
    printf("\n Avg Waiting Time=%f",A_wai_Time);
    printf("\n Avg Turn around Time=%f",Atat);
}

