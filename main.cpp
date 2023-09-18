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
int **llenandoMatriz(int,int);

void iniciarEspanol(){
	setlocale(LC_ALL,"spanish");
}

int main() {
	//mensaje de saludo
	printf("\n\nHola buenas tardes...\n\n");
	
	//una pausa moment�nea
	pausa();
	
	//iniciando el idioma espa�ol
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
	printf("Escriba el n�mero de la opci�n deseada:\n");
	printf("\n1. Calcular Grafo ingresando datos.");
	printf("\n2. Calcular Grafo por archivo de texto.");
	printf("\n3. Salir");
	printf("\n\nElijo la opci�n: ");
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
				break;
			case 3:
				seguir = false;
				break;
			default:
				printf("\n\nNo has elegido una opci�n correcta, vuelve a intentarlo...\n\n");
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
		printf("�Cu�ntos nodos deseas ingresar? (El m�nimo es de dos nodos...)\n");
		scanf("%d",&numNodos);
		
		if(numNodos && numNodos > 1){
			break;
		}
			printf("\n\nIngresa una opci�n v�lida...\n\n");
			pausa();
	fflush(stdin);
	}while(true);
	
	//ejecutamos la funcion llenando la matriz manualmente => por eso le enviamos la opcion 1, indicando llenado manual
	int **matr = llenandoMatriz(1,numNodos);
	
	system("cls");
	printf("\n\nEl grafo ser� dibujado considerando %i nodos.\n",numNodos);
	printf("cuando se abra la ventana con el dibujo, si desea cerrarlo de click sobre aquella ventana\n y presione enter...\n\n");
	pausa();
	
	
	//comenzando el dibujo del grafo
	dibujandoGrafo(numNodos,matr);
	
}

int **llenandoMatriz(int opcionLlenado, int numNodosPedidos){
	
	switch(opcionLlenado){
		case 1:
			
			
			int **matriz;
			matriz = (int **)malloc (numNodosPedidos*sizeof(int *));

			for (int i=0;i<numNodosPedidos;i++){
				matriz[i] = (int *) malloc (numNodosPedidos*sizeof(int));
			}
			
			for (int i=0;i<numNodosPedidos;i++){
				
				for(int j=0;j<numNodosPedidos;j++){
					printf("\n\ndame el peso a guardar en la posici�n [%i][%i]: ",i,j);
					scanf("%i",&matriz[i][j]);
					fflush(stdin);
				}
				
			}
			
			return matriz;
			
			break;
		case 2:
			break;
	}
	
	
}

void dibujandoGrafo(int numeroNodos, int **matrix){
	initwindow(1000, 1000); // Crea una ventana gr�fica de 1000x1000 p�xeles
	
    int tamanoNodo = 40; // Tama�o que tendr� cada nodo
    
    
//    int matrix[][numeroNodos] = {{0, 1, 1, 0, 0, 1},
//                       		  	 {1, 0, 1, 1, 0, 0},
//                              	 {1, 1, 0, 0, 1, 1},
//                              	 {0, 1, 0, 0, 1, 1},
//                              	 {0, 0, 1, 1, 0, 0},
//							  	 {0, 0, 1, 1, 0, 0}}; // Ejemplo de matriz de adyacencia

    // Coordenadas de los nodos
	// int nodeX[] = {100, 500, 900, 500, 100};
	// int nodeY[] = {100, 500, 500, 900, 900};
    
    int nodoX[] = {100, 100, 500, 700, 900, 700};
    int nodoY[] = {100, 300, 100, 500, 500, 700};

    // Configura el tama�o y el color del texto
    settextstyle(0, 0, 3); // Fuente 0, sin estilo especial, tama�o 3
	// setcolor(RED); // Color del texto en rojo
	
    // Dibuja los nodos como c�rculos y coloca etiquetas
    for (int i = 0; i < numeroNodos; i++) {
        circle(nodoX[i], nodoY[i], tamanoNodo); // Dibuja un c�rculo en la posici�n del nodo
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
                // Calcula la direcci�n de la l�nea
                double angle = atan2(nodoY[j] - nodoY[i], nodoX[j] - nodoX[i]);

                // Ajusta las coordenadas de inicio y fin para que no est�n dentro de los c�rculos
                int startX = nodoX[i] + (int)(tamanoNodo * cos(angle));
                int startY = nodoY[i] + (int)(tamanoNodo * sin(angle));
                int endX = nodoX[j] - (int)(tamanoNodo * cos(angle));
                int endY = nodoY[j] - (int)(tamanoNodo * sin(angle));

                line(startX, startY, endX, endY); // Dibuja una l�nea entre nodos conectados

				//dibujamos los pesos en el medio de cada l�nea
				char es[200];
				sprintf(es, "%d", matrix[i][j]);   
        		outtextxy(((endX - startX)/2)+startX-20, ((endY - startY)/2)+startY-20, es); 
    			
				 // Calcula las coordenadas de la punta de la flecha
    			int arrowX = nodoX[j] - (int)(tamanoNodo * cos(angle));
    			int arrowY = nodoY[j] - (int)(tamanoNodo * sin(angle));

    			// Calcula las coordenadas de los extremos de las alas de la flecha
    			int wing1X = arrowX - (int)((tamanoNodo/2) * cos(angle + M_PI / 6)); // �ngulo de 30 grados
    			int wing1Y = arrowY - (int)((tamanoNodo/2) * sin(angle + M_PI / 6));
    			int wing2X = arrowX - (int)((tamanoNodo/2) * cos(angle - M_PI / 6)); // �ngulo de -30 grados
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