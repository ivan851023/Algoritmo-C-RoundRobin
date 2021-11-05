#include <stdio.h>

void main() {
    int i, n, total = 0, x, counter = 0, qt;
    int at[10], bt[10], temp[10];
    	
	//qt Quantum
	//n Es el numero de procesos ingresados por el usuario
	//total Es donde se almacena el tiempo de finalizacion
	//at se almacena el tiempo de llegada
	//x es una variable interna que almacena el no de procesos a ejecutar
	//bt se almacena el tiempo de ejecucion
	//temp es el valor disponible despues de usar el quantum
	// counter se utiliza como bandera para indicar si el proceso termina o sigue
	//i es la variable que se va a encargar de hacer los recorridos por cada proceso
	
	
	
	
    printf("Ingrese número de procesos : ");
	scanf("%d", &n);//se almacena en la variable n el no de procesos ingresados por el usuario
    x = n;// se asigna los procesos ingresados a la variable x
    for(i = 0; i < n; i++)// se encarga de recorrer los procesos ingresados
    {
        printf("\nProceso %d...\n", i + 1);
        printf("Ingrese Tiempo Llegada: ");
        scanf("%d", &at[i]);//se almacena en la variable at el tiempo de llegada
        printf("Ingrese Tiempo Ejecución: ");
        scanf("%d", &bt[i]);//se almacena en la variable bt el tiempo de ejecucion
        temp[i] = bt[i]; //se almaceba en la vairable temp el tiempo de ejecucion el cual va cambiando segun los quntim utilizados
    }
	//al final de este bucle se arma un array de esta forma {n,n,n,n} segun el numero de procesos
	
	
    printf("\nIngrese el Quantum: ");
    scanf("%d", &qt);//se almacena en la variable qt el quantum ingresado
    printf("\n+-----+------------+--------------+-----------------+\n");
    printf("| P ID | T EJECUCION | T ESPERA | T RESPUESTA | T FINALIZACION |\n");// se arma las columnas que va a tener la tabla
    printf("+-----+------------+--------------+-----------------+\n");
    for(total = 0, i = 0; x != 0;)//bucle que realiza todos los recorridos necesarios para cada uno de los quantum
    {
        if(temp[i] <= qt && temp[i] > 0)//ingresa cuando el tiempo de ejecucion es menor al quantum y en esta condicion el proceso termina su recorrido
        {
                total = total + temp[i];
                temp[i] = 0;
                counter = 1;
        }
        else if(temp[i] > 0)//ingresa cuando el tiempo de ejecucion es mayor al quantum
        {
                temp[i] = temp[i] - qt;
                total = total + qt;
        }
        if(temp[i] == 0 && counter == 1)//ingresa cuando el proceso termina y se encarga de imprimir los resultados
        {
                x--;//cuando x es cero quiere decir que los procesos terminan
                printf("| %2d  |     %2d     |      %2d      |       %2d        |\n", i + 1, bt[i], total - at[i] - bt[i], total - at[i], total);
                printf("+-----+------------+--------------+-----------------+\n");
                counter = 0;
        }
        if(i == n - 1)//ingresa cuando terminan todos los procesos
        {
                i = 0;
        }
        else if(at[i + 1] <= total)//ingresa cuando aun quedan procesos en cola
        {
                i++;
        }
        else
        {
                i = 0;
        }
    }
}





