#include<stdio.h>
#include<string.h>
typedef struct process{
    char name[50];
    int at;
    int bt;
    int ct;
    int wt;
    int ta;
    int status;
}process;
typedef struct done{
    char name[50];
    int st;
    int ct;
}done;

int main(){
    int n,i,num=0,idle=0,ls=0,j,min,flag=0,minbt,avgwt,avgta;
    done d[20];
    process p[20];
    printf("Enter no. of processes:");
    scanf("%d",&n);
    printf("Enter processes:name,at,bt");
    for (i=0;i<n;i++){
        printf("Process %d",i);
        scanf("%s", p[i].name);
        scanf("%d",&p[i].at);
        scanf("%d",&p[i].bt);
        p[i].status=0;
    }
    i=0;
    while (ls<n){
        minbt=9999;
        for (j=0;j<n;j++){
            if (p[j].at<=i && p[j].status==0){
                if (p[j].bt<minbt){
                    minbt=p[j].bt;
                    min=j;
                }
                flag=1;
            }
        }
        if (idle==0 && flag==1 && p[min].status==0){
            strcpy(d[num].name,p[min].name);
            d[num].st=i;
            p[min].ct=p[min].bt+i;
            d[num].ct=p[min].ct;
            num++;
            i=p[min].ct;
            p[min].status=1;
            flag=0;
            ls++;
        }
        else if(flag==0 && idle==0){
            idle=1;
            strcpy(d[num].name,"Idle");
            d[num].st=i;
            i++;
        }
        else if(idle==1 && flag==1 && p[min].status==0){
            d[num].ct=i;
            num++;
            d[num].st=p[min].at;
            p[min].ct=i;
            d[num].ct=p[min].bt;
            num++;
            p[min].ct=p[min].bt+i;
            i=p[min].ct;
            p[min].status=1;
            idle=0;
            flag=0;
            ls++;
        }
    }
    avgwt=0;
    avgta=0;
    for (j=0;j<n;j++){
        p[j].ta=p[j].ct-p[j].at;
        p[j].wt=p[j].ta-p[j].bt;
        avgwt+=p[j].wt;
        avgta+=p[j].ta;
    }
    printf("\nGantt chart\n");
    for (i=0;i<num;i++){
        printf("----------------");
    }
    printf("\n");
    printf("|\t");
    for (i=0;i<num;i++){
        printf("%s\t|",d[i].name);
        printf("\t");
    }
    printf("\n");
    for (i=0;i<num;i++){
        printf("----------------");
    }
    printf("\n");
    for (i=0;i<num;i++){
        printf("%d",d[i].st);
        printf("\t\t");
    }
    printf("%d",p[num-1].ct);
    printf("\nAverage Waiting Time:%d",avgwt);
    printf("\nAverage Turn Around Time:%d",avgta);
}