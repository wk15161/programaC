#include <winbgim.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

void iniciarEspanol();
int listaOpciones();
void dibujandoGrafo(int,int**);
void pausa();
void programa();
void grafoConDatos();
void grafoConTxt();
int **llenandoMatrizManual(int);
int **llenandoMatrizAuto(int,char[200]);

void iniciarEspanol(){
	setlocale(LC_ALL,"spanish");
}

int main() {
	//mensaje de saludo
	printf("\n\nHola buenas tardes...\n\n");
	
	//una pausa momentánea
	pausa();
	
	//iniciando el idioma español
	iniciarEspanol();
	
	//el usuario accede al programa
    programa();
    
    //mensaje de despedida
    printf("\n\nMuchas gracias por utilizar este programa...\n\n");
    
	return 0;
}


void pausa(){
	system("pause");
	system("cls");
	fflush(stdin);
}

int listaOpciones(){
	printf("\n\n");
	int opcion = 0;
	printf("Escriba el número de la opción deseada:\n");
	printf("\n1. Calcular Grafo ingresando datos.");
	printf("\n2. Calcular Grafo con una matriz desde archivo de texto.");
	printf("\n3. Salir");
	printf("\n\nElijo la opción: ");
	scanf("%i",&opcion);
	system("cls");
	return opcion;
}

void programa(){
	bool seguir = true;
	do{
		int thisOpcion = listaOpciones();
		
		switch(thisOpcion){
			case 1:
				grafoConDatos();
				break;
			case 2:
				grafoConTxt();
				break;
			case 3:
				seguir = false;
				break;
			default:
				printf("\n\nNo has elegido una opción correcta, vuelve a intentarlo...\n\n");
				pausa();
				break;
		}
		
		system("cls");
	}while(seguir);
}

void grafoConDatos(){
	int numNodos;
	do{
		printf("\n\n");
		printf("¿Cuántos nodos deseas ingresar? (El mínimo es de dos nodos y el máximo es de 7...)\n");
		scanf("%d",&numNodos);
		
		if(numNodos && numNodos > 1 && numNodos < 8){
			break;
		}
			printf("\n\nIngresa una opción válida...\n\n");
			pausa();
	fflush(stdin);
	}while(true);
	
	//ejecutamos la funcion llenando la matriz manualmente
	int **matr = llenandoMatrizManual(numNodos);
	
	system("cls");
	printf("\n\nEl grafo será dibujado considerando %i nodos.\n",numNodos);
	printf("cuando se abra la ventana con el dibujo, si desea cerrarlo de click sobre aquella ventana\n y presione enter...\n\n");
	pausa();
	
	
	//comenzando el dibujo del grafo
	dibujandoGrafo(numNodos,matr);
	
}

void grafoConTxt(){
	int tamano = 1;
	char archivoNombre[200];
	FILE* archivo;
	do{
		fflush(stdin);
		printf("\n\n");
		printf("Por favor coloca tu archivo txt dentro de la carpeta donde estás ejecutando este programa..\n");
		printf("Y terminado ello, escribe tal y cuál el nombre de tu archivo txt");
		printf("\n\nEjemplo: archivito.txt");
		printf("\nCabe destacar que solamente se pueden generar de 2 a 7 nodos...");
		printf("\n\nNombre del archivo: ");
		fgets(archivoNombre, 200, stdin);
	
		//SI HAY SALTOS DE LÍNEA EN EL stdin
		if ((strlen(archivoNombre) > 0) && (archivoNombre[strlen(archivoNombre) - 1] == '\n')){
        	archivoNombre[strlen(archivoNombre) - 1] = '\0';
    	}
		fflush(stdin);
		
		system("cls");
	
		// declaramos una variable de tipo archivo
		archivo = fopen(archivoNombre, "r");
    	if (archivo == NULL) {
        	printf("\n\nNo existe el archivo. Inténtalo de nuevo\n\n");
        	pausa();
			fflush(stdin);
    	}else if(archivo != NULL){
    		
    		 // Contamos el número de filas que existen dentro del archivo
    		tamano = 1;
    		while (!feof(archivo)) {
        		char c = fgetc(archivo);
        		if (c == '\n') {
            		tamano++;
        		}
    		}
    
    		fclose(archivo);
			fflush(stdin);
			
			if(tamano<2 || tamano>7){
				printf("\n\nEl archivo contiene %i nodos y no se puede generar, recuerda que solamente se permite un rango de 2 a 7 nodos..\n\n",tamano);
				pausa();
				fflush(stdin);
			}else{
				break;
			}
		}
	
	}while(true);
	
	
	//ejecutamos la funcion llenando la matriz automáticamente
	int **matr = llenandoMatrizAuto(tamano,archivoNombre);
	
	system("cls");
	printf("\n\nEl grafo será dibujado considerando %i nodos.\n",tamano);
	printf("cuando se abra la ventana con el dibujo, si desea cerrarlo de click sobre aquella ventana\n y presione enter...\n\n");
	pausa();
	
	
	//comenzando el dibujo del grafo
	dibujandoGrafo(tamano,matr);
	
}

int **llenandoMatrizAuto(int tamano,char archivoNombre[200]){

	//Declaramos la matriz sin parámetros
	int** matriz;		
	matriz = (int **)malloc (tamano*sizeof(int *));

	for (int i=0;i<tamano;i++){
		matriz[i] = (int *) malloc (tamano*sizeof(int));
	}
	
	//leemos el archivo
	FILE* archivo = fopen(archivoNombre, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        pausa();
        exit(1);
    }
	
    // Leemos los valores
	for (int i = 0; i < tamano; i++) {
    	for (int j = 0; j < tamano; j++) {
        	if (fscanf(archivo, "%d", &matriz[i][j]) != 1) {
            	printf("Error al leer el archivo en [%d][%d]\n, reinicie el programa,\n y seleccione un archivo con una matriz válida...", i, j);
            	pausa();
            	exit(1);
        	}
    	}
	}
			
	return matriz;
}

int **llenandoMatrizManual(int numNodosPedidos){
	
	//Declaramos la matriz sin parámetros
	int** matriz;		
	matriz = (int **)malloc (numNodosPedidos*sizeof(int *));

	for (int i=0;i<numNodosPedidos;i++){
		matriz[i] = (int *) malloc (numNodosPedidos*sizeof(int));
	}
			
	for (int i=0;i<numNodosPedidos;i++){			
		for(int j=0;j<numNodosPedidos;j++){
			printf("\n\ndame el peso a guardar en la posición [%i][%i]: ",i,j);
			scanf("%i",&matriz[i][j]);
			fflush(stdin);
		}
				
	}
			
	return matriz;
}

void dibujandoGrafo(int numeroNodos, int **matrix){
	initwindow(1000, 1000); // Crea una ventana gráfica de 1000x1000 píxeles
	
    int tamanoNodo = 40; // Tamaño que tendrá cada nodo
    
    //Posiciones predeterminadas de cada nodo
    int nodoX[] = {100, 100, 500, 450, 900, 550, 300};
    int nodoY[] = {100, 450, 100, 500, 300, 800, 900};

    // Configura el tamaño y el color del texto
    settextstyle(0, 0, 3); // Fuente 0, sin estilo especial, tamaño 3
	// setcolor(RED); // Color del texto en rojo
	
    // Dibuja los nodos como círculos y coloca etiquetas
    for (int i = 0; i < numeroNodos; i++) {
        circle(nodoX[i], nodoY[i], tamanoNodo); // Dibuja un círculo en la posición del nodo
        // Coloca etiquetas en los nodos
        char letra[2];
        letra[0] = 'A' + i; // Etiquetas de letras ('A', 'B', 'C', ...)
        letra[1] = '\0'; // Termina la cadena
        outtextxy(nodoX[i] - 5, nodoY[i] - 5, letra); // Coloca la etiqueta cerca del nodo
    }

    // Dibujar las aristas
    for (int i = 0; i < numeroNodos; i++) {
        for (int j = 0; j < numeroNodos; j++) {
            if (matrix[i][j] != 0) {
            	printf("\n\nPosicion: %i, %i - la matriz es la posicion [%i][%i] con valor %1",i,j,i,j,matrix[i][j]);
                // Calcula la dirección de la línea
                double angle = atan2(nodoY[j] - nodoY[i], nodoX[j] - nodoX[i]);

                // Ajusta las coordenadas de inicio y fin para que no estén dentro de los círculos
                int startX = nodoX[i] + (int)(tamanoNodo * cos(angle));
                int startY = nodoY[i] + (int)(tamanoNodo * sin(angle));
                int endX = nodoX[j] - (int)(tamanoNodo * cos(angle));
                int endY = nodoY[j] - (int)(tamanoNodo * sin(angle));

                line(startX, startY, endX, endY); // Dibuja una línea entre nodos conectados

				//dibujamos los pesos en el medio de cada línea
				char es[200];
				sprintf(es, "%d", matrix[i][j]);
				if(matrix[i][j]!=0 && matrix[i][j]!=1){
					outtextxy(((endX - startX)/2)+startX-20, ((endY - startY)/2)+startY-20, es); 
				}   
        		
    			
				 // Calcula las coordenadas de la punta de la flecha
    			int arrowX = nodoX[j] - (int)(tamanoNodo * cos(angle));
    			int arrowY = nodoY[j] - (int)(tamanoNodo * sin(angle));

    			// Calcula las coordenadas de los extremos de las alas de la flecha
    			int wing1X = arrowX - (int)((tamanoNodo/2) * cos(angle + M_PI / 6)); // Ángulo de 30 grados
    			int wing1Y = arrowY - (int)((tamanoNodo/2) * sin(angle + M_PI / 6));
    			int wing2X = arrowX - (int)((tamanoNodo/2) * cos(angle - M_PI / 6)); // Ángulo de -30 grados
    			int wing2Y = arrowY - (int)((tamanoNodo/2) * sin(angle - M_PI / 6));

   			 	// Dibuja las alas de la flecha
    			line(wing1X, wing1Y, arrowX, arrowY);
    			line(wing2X, wing2Y, arrowX, arrowY);
    			
			
    			//Restableciendo los valores a cero
    			arrowX = 0;
    			arrowY = 0;
    			wing1X = 0;
    			wing2X = 0;
    			wing1Y = 0;
    			wing2Y = 0;
    	
			}
        }
    }

    // Esperamos a que el usuario presione una tecla para poder cerrar el dibujo
    getch();

    // Cerramos el dibujo
    closegraph();

}