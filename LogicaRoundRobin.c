#include <stdio.h>

void main() {
    int i, n, total = 0, x, counter = 0, qt;
    int wt = 0, tt = 0, at[10], bt[10], temp[10];
    
    printf("Ingrese número de procesos : ");
    scanf("%d", &n);
    x = n;
    for(i = 0; i < n; i++)
    {
        printf("\nProceso %d...\n", i + 1);
        printf("Ingrese Tiempo Llegada: ");
        scanf("%d", &at[i]);
        printf("Ingrese Tiempo Ejecución: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("\nIngrese el Quantum: ");
    scanf("%d", &qt);
    printf("\n+-----+------------+--------------+-----------------+\n");
    printf("| P ID | T EJECUCION | T ESPERA | T RESPUESTA |\n");
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
}
