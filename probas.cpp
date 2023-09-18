void s(){
	initwindow(1000, 1000); // Crea una ventana gr�fica de 1000x1000 p�xeles
	int numeroNodos= 11;
    int tamanoNodo = 40; // Tama�o que tendr� cada nodo
    
    
    int matrix[][numeroNodos] = {{0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1},
                       		  	 {1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1},
                       		  	 {1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
                       		  	 {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1},
                       		  	 {1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1},
                       		  	 {1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1},
                       		  	 {1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1},
                              	 {1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1},
                              	 {0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1},
                              	 {0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1},
							  	 {0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0}}; // Ejemplo de matriz de adyacencia

    // Coordenadas de los nodos
	// int nodeX[] = {100, 500, 900, 500, 100};
	// int nodeY[] = {100, 500, 500, 900, 900};
    
    int nodoX[] = {100, 100, 500, 700, 900, 700};
    int nodoY[] = {100, 300, 300, 500, 500, 700};

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
    			
    			//Retsableciendo los valores a cero
    			arrowX = 0;
    			arrowY = 0;
    			wing1X = 0;
    			wing2X = 0;
    			wing1Y = 0;
    			wing2Y = 0;
    	
			}
        }
    }

    // Espera a que el usuario presione una tecla antes de cerrar la ventana
    getch();

    // Cierra la ventana gr�fica
    closegraph();

}