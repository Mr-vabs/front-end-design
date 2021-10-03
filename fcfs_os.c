// FCFS

// #include<stdio.h>

// void findWaitingTime(int processes[], int n, int bt[], int wt[])
// {
// 	wt[0] = 0;

// 	for (int i = 1; i < n ; i++ )
// 		wt[i] = bt[i-1] + wt[i-1] ;
// }

// void findTurnAroundTime( int processes[], int n,
// 				int bt[], int wt[], int tat[])
// {
// 	for (int i = 0; i < n ; i++)
// 		tat[i] = bt[i] + wt[i];
// }

// void findavgTime( int processes[], int n, int bt[])
// {
// 	int wt[n], tat[n], total_wt = 0, total_tat = 0;

// 	findWaitingTime(processes, n, bt, wt);

// 	findTurnAroundTime(processes, n, bt, wt, tat);

// 	printf("Processes Burst time Waiting time Turn around time\n");

// 	for (int i=0; i<n; i++)
// 	{
// 		total_wt = total_wt + wt[i];
// 		total_tat = total_tat + tat[i];
// 		printf(" %d ",(i+1));
// 		printf("	 %d ", bt[i] );
// 		printf("	 %d",wt[i] );
// 		printf("	 %d\n",tat[i] );
// 	}
// 	int s=(float)total_wt / (float)n;
// 	int t=(float)total_tat / (float)n;
// 	printf("Average waiting time = %d",s);
// 	printf("\n");
// 	printf("Average turn around time = %d ",t);
// }

// int main()
// {
// 	int processes[] = { 1, 2, 3, 4, 5};
// 	int n = sizeof processes / sizeof processes[0];
// 	int burst_time[] = {10, 5, 8, 4, 9};
// 	findavgTime(processes, n, burst_time);
// 	return 0;
// }

// ROUND ROBIN

// #include<stdio.h>

// int main()
// {

//   int count,j,n,time,remain,flag=0,time_quantum;
//   int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
//   printf("Enter Total Process:\t ");
//   scanf("%d",&n);
//   remain=n;
//   for(count=0;count<n;count++)
//   {
//     printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
//     scanf("%d",&at[count]);
//     scanf("%d",&bt[count]);
//     rt[count]=bt[count];
//   }
//   printf("Enter Time Quantum:\t");
//   scanf("%d",&time_quantum);
//   printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
//   for(time=0,count=0;remain!=0;)
//   {
//     if(rt[count]<=time_quantum && rt[count]>0)
//     {
//       time+=rt[count];
//       rt[count]=0;
//       flag=1;
//     }
//     else if(rt[count]>0)
//     {
//       rt[count]-=time_quantum;
//       time+=time_quantum;
//     }
//     if(rt[count]==0 && flag==1)
//     {
//       remain--;
//       printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
//       wait_time+=time-at[count]-bt[count];
//       turnaround_time+=time-at[count];
//       flag=0;
//     }
//     if(count==n-1)
//       count=0;
//     else if(at[count+1]<=time)
//       count++;
//     else
//       count=0;
//   }
//   printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
//   printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

//   return 0;
// }

// PRIORITY

// #include<stdio.h>

// int main()
// {
//     int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
//     printf("Enter Total Number of Process:");
//     scanf("%d",&n);

//     printf("\nEnter Burst Time and Priority\n");
//     for(i=0;i<n;i++)
//     {
//         printf("\nP[%d]\n",i+1);
//         printf("Burst Time:");
//         scanf("%d",&bt[i]);
//         printf("Priority:");
//         scanf("%d",&pr[i]);
//         p[i]=i+1;
//     }

//     for(i=0;i<n;i++)
//     {
//         pos=i;
//         for(j=i+1;j<n;j++)
//         {
//             if(pr[j]<pr[pos])
//                 pos=j;
//         }

//         temp=pr[i];
//         pr[i]=pr[pos];
//         pr[pos]=temp;

//         temp=bt[i];
//         bt[i]=bt[pos];
//         bt[pos]=temp;

//         temp=p[i];
//         p[i]=p[pos];
//         p[pos]=temp;
//     }

//     wt[0]=0;

//     for(i=1;i<n;i++)
//     {
//         wt[i]=0;
//         for(j=0;j<i;j++)
//             wt[i]+=bt[j];

//         total+=wt[i];
//     }

//     avg_wt=total/n;
//     total=0;

//     printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
//     for(i=0;i<n;i++)
//     {
//         tat[i]=bt[i]+wt[i];
//         total+=tat[i];
//         printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
//     }

//     avg_tat=total/n;
//     printf("\n\nAverage Waiting Time=%d",avg_wt);
//     printf("\nAverage Turnaround Time=%d\n",avg_tat);

// 	return 0;
// }

// #include <stdio.h>
// #include <conio.h>
// #include<stdlib.h>
// #define infinity 999

// void dij(int n, int v, int cost[10][10], int dist[])
// {
//     int i, u, count, w, flag[10], min;
//     for (i = 1; i <= n; i++)
//         flag[i] = 0, dist[i] = cost[v][i];
//     count = 2;
//     while (count <= n)
//     {
//         min = 99;
//         for (w = 1; w <= n; w++)
//             if (dist[w] < min && !flag[w])
//                 min = dist[w], u = w;
//         flag[u] = 1;
//         count++;
//         for (w = 1; w <= n; w++)
//             if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
//                 dist[w] = dist[u] + cost[u][w];
//     }
// }
// void main()
// {
//     int n, v, i, j, cost[10][10], dist[10];
//     printf("\nEnter the number of nodes : ");
//     scanf("%d", &n);
//     printf("\nEnter the cost matrix : \n");
//     for (i = 1; i <= n; i++)
//         for (j = 1; j <= n; j++)
//         {
//             scanf("%d", &cost[i][j]);
//             if (cost[i][j] == 0)
//                 cost[i][j] = infinity;
//         }
//     printf("\nEnter the source matrix : ");
//     scanf("%d", &v);
//     dij(n, v, cost, dist);
//     printf("\nShortest path : \n");
//     for (i = 1; i <= n; i++)
//         if (i != v)
//             printf("%d->%d,cost=%d\n", v, i, dist[i]);
//     getch();
// }

// #include <stdio.h>
// #include<stdlib.h>
// #include <conio.h>
// int sum = 0;
// int max(int a, int b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }
// void knapsack(int m, int n, int w[], int p[])
// {
//     int v[100][200], x[10], i, j;
//     for (i = 0; i <= m; i++)
//         v[0][i] = 0;
//     for (i = 1; i <= n; i++)
//     {
//         for (j = 0; j <= m; j++)
//         {
//             if (j >= w[i])
//                 v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
//             else
//                 v[i][j] = v[i - 1][j];
//         }
//     }
//     for (i = 1; i <= n; i++)
//         x[i] = 0;
//     i = n;
//     j = m;
//     while (i > 0 && j > 0)
//     {
//         if (v[i][j] != v[i - 1][j])
//         {
//             x[i] = 1;
//             j = j - w[i];
//         }
//         i--;
//     }
//     printf("\nTHE OPTIMAL SET OF WEIGHTS IS:\n");
//     for (i = 1; i <= n; i++)
//     {
//         if (x[i] == 1)
//         {
//             printf("X%d=1\t", i);
//             sum = sum + p[i];
//         }
//         else
//             printf("X%d=0\t", i);
//     }
//     printf("\nTotal profit = %d", sum);
// }
// void main()
// {
//     int w[10], p[10], i, m, n;
//     printf("\n0/1 KNAPSACK PROBLEM\n\n");
//     printf("ENTER THE NUMBER OF ITEMS: ");
//     scanf("%d", &n);
//     printf("ENTER THE WEIGHTS OF THE ITEMS:\n");
//     for (i = 1; i <= n; i++)
//         scanf("%d", &w[i]);
//     printf("ENTER THE PROFITS OF THE ITEMS:\n");
//     for (i = 1; i <= n; i++)
//         scanf("%d", &p[i]);
//     printf("ENTER THE CAPACITY OF KNAPSACK: ");
//     scanf("%d", &m);
//     knapsack(m, n, w, p);
//     getch();
// }

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
void insertion_sort(int a[], int);
void quick_sort(int a[], int, int, int);
void bubble_sort(int a[], int);
int partition(int a[], int, int);
void main()
{
    int data[1000], i, n, element, ch, a[1000], b[1000], c[1000];

    while (1)
    {
        
        printf("****MENU****\nEnter 1 to apply and compare quick sort,bubble sort,insertion sort\nEnter 2 for exit\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of elements in array \n");
            scanf("%d", &n);
            printf("Enter array elements\n");
            for (i = 0; i < n; i++)
            {
                data[i] = rand();
            }
            for (i = 0; i < n; i++)
            {
                a[i] = data[i];
                b[i] = data[i];
                c[i] = data[i];
            }
            quick_sort(a, 0, n - 1, n);
            //printf("After quick sort array elements are:- \n");
            //for(i=0;i<n;i++)
            //printf("%d\n",a[i]);
            bubble_sort(b, n);
            insertion_sort(c, n);
            break;
        case 2:
            exit(0);
        default:
            printf("You have entered wrong choice\n");
        }
        getch();
    }
}
void quick_sort(int a[], int p, int r, int n)
{
    int q, i;
    double time;
    clock_t start, end;
    if (p == 0 && r == n - 1)
        start = clock();
    if (p < r)
    {
        q = partition(a, p, r);
        quick_sort(a, p, q - 1, n);
        quick_sort(a, q + 1, r, n);
    }
    if (p == 0 && r == n - 1)
    {
        end = clock();
        time = ((double)(end - start)) / CLK_TCK;
        printf("Time taken by quick sort is %f\n", time);
    }
}
int partition(int a[], int p, int r)
{
    int i, j, temp, pivot;
    i = p - 1;
    pivot = a[r];
    for (j = p; j < r; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = pivot;
    a[r] = temp;
    return i + 1;
}
void bubble_sort(int b[], int n)
{
    int i, j, temp;
    double time;
    clock_t start, end;
    start = clock();

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    end = clock();
    time = ((double)(end - start)) / CLK_TCK;
    printf("Time taken by bubble sort is %f\n", time);
    //printf("After bubble sort array elements are:- \n");
    //for(i=0;i<n;i++)
    //printf("%d\n",b[i]);
}
void insertion_sort(int a[], int n)
{
    int i, j, temp;
    double time;
    clock_t start, end;
    start = clock();
    for (i = 1; i < n; i++)
    {
        j = i;
        temp = a[j];
        while (j > 0 && temp < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
    end = clock();
    time = ((double)(end - start)) / CLK_TCK;
    printf("Time taken by insertion sort is %f\n", time);
    //printf("After insertion sort array elements are:- \n");
    //for(i=0;i<n;i++)
    //printf("%d\n",a[i]);
}
