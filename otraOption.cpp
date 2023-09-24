
							/*DIBUJAMOS LA FLECHA DE LA PRIMERA ARISTA YA DIBUJADA E INCLUIMOS SU PESO*/
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
    						//dibujamos los pesos en el medio de la línea
							char es[200];
							sprintf(es, "%d", matrix[i][j]);
							if(matrix[i][j]!=1){
								if(matrix[i][j]<10){
									outtextxy(((endX - startX)/2)+startX-10, ((endY - startY)/2)+startY-10, es);
								}else{
									outtextxy(((endX - startX)/2)+startX-21, ((endY - startY)/2)+startY-21, es);
								}		 
							}
													
							
    						
    						
							/*DIBUJAMOS LA SEGUNDA ARISTA Y LA SEGUNDA FLECHA*/
							// Calcula la dirección de la línea
							
							nodoY[j] = nodoY[j]+15;
							nodoY[i] = nodoY[i]-15;
							nodoX[j] = nodoX[j]+30;
							nodoX[i] = nodoX[i]+30;
							
                			double angle = atan2(nodoY[j] - nodoY[i], nodoX[j] - nodoX[i]);
							
                			// Ajusta las coordenadas de inicio y fin para que no estén dentro de los círculos
                			int startX = nodoX[i] + (int)(tamanoNodo * cos(angle));
                			int startY = nodoY[i] + (int)(tamanoNodo * sin(angle));
                			int endX = nodoX[j] - (int)(tamanoNodo * cos(angle));
                			int endY = nodoY[j] - (int)(tamanoNodo * sin(angle));

							//en caso de que tienen un valor distinto pero no es cero, entonces ambos toman caminos distintos
							line(startX, startY, endX, endY); // Dibuja una línea entre nodos conectados
							
							//volvemos a crear una flecha conectado a él						
							
							// Calcula las coordenadas de la punta de la flecha
    						arrowX = (nodoX[i])- (int)(tamanoNodo * cos(angle));
    						arrowY = (nodoY[i]) - (int)(tamanoNodo * sin(angle));
							
    						// Calcula las coordenadas de los extremos de las alas de la flecha
    						wing1X = arrowX - (int)((tamanoNodo/2) * cos(angle + M_PI / 6)); // Ángulo de 30 grados
    						wing1Y = arrowY - (int)((tamanoNodo/2) * sin(angle + M_PI / 6));
    						wing2X = arrowX - (int)((tamanoNodo/2) * cos(angle - M_PI / 6)); // Ángulo de -30 grados
    						wing2Y = arrowY - (int)((tamanoNodo/2) * sin(angle - M_PI / 6));

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
    					
    						//dibujamos los pesos en el medio de la línea
							sprintf(es, "%d", matrix[j][i]);
							if(matrix[j][i]!=1){
								if(matrix[j][i]<10){
									outtextxy(((endX - startX)/2)+startX-10, ((endY - startY)/2)+startY-10, es);
								}else{
									outtextxy(((endX - startX)/2)+startX-21, ((endY - startY)/2)+startY-21, es);
								}		 
							}
							nodoY[j] = nodoY[j]-15;
							nodoY[i] = nodoY[i]+15;
							nodoX[j] = nodoX[j]-30;
							nodoX[i] = nodoX[i]-30;
							matrix[i][j]=0;
							matrix[j][i]=0;