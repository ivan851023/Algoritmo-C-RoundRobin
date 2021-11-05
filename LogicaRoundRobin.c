#include <stdio.h>

void main() {
    int i, n, total = 0, x, counter = 0, qt;
    int wt = 0, tt = 0, at[10], bt[10], temp[10];
    double average_wait_time, average_turnaround_time;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    x = n;
    for(i = 0; i < n; i++)
    {
        printf("\nProcess %d...\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("\nEnter Time Quantum: ");
    scanf("%d", &qt);
    printf("\n+-----+------------+--------------+-----------------+\n");
    printf("| PID | BURST TIME | WAITING TIME | TURNAROUND TIME |\n");
    printf("+-----+------------+--------------+-----------------+\n");
    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= qt && temp[i] > 0)
        {
                total = total + temp[i];
                temp[i] = 0;
                counter = 1;
        }
        else if(temp[i] > 0)
        {
                temp[i] = temp[i] - qt;
                total = total + qt;
        }
        if(temp[i] == 0 && counter == 1)
        {
                x--;
                printf("| %2d  |     %2d     |      %2d      |       %2d        |\n", i + 1, bt[i], total - at[i] - bt[i], total - at[i]);
                printf("+-----+------------+--------------+-----------------+\n");
                wt = wt + total - at[i] - bt[i];
                tt = tt + total - at[i];
                counter = 0;
        }
        if(i == n - 1)
        {
                i = 0;
        }
        else if(at[i + 1] <= total)
        {
                i++;
        }
        else
        {
                i = 0;
        }
    }
    average_wait_time = wt * 1.0 / n;
    average_turnaround_time = tt * 1.0 / n;
    printf("\nAverage Waiting Time: %lf", average_wait_time);
    printf("\nAverage Turnaround Time: %lf\n", average_turnaround_time);
}
