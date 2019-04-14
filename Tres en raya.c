//Juego de 3 en raya.

#include <stdio.h>

int start();
int loop(char c[][3], int a);
void intro_primera (char c[][3]);
void intro_yo(char c[][3]);
void intro_iafacil(char c[][3]);
void tablero (char c[][3]);
int ganador(char c[][3]);

//INTRO IA DIFICIL
int check(char c[][3]);//PRIMERO VERIFICA, DESPUES VA A EL MAIN
void disp(char c[][3], char s[9], char so[5]);
int ganare(char v[3],char s[9]);
void choice(char v[3], char so[5]);
void intro_iadificil(char c[][3]);//MAIN

int main(){


int d,r;

d = start();


char c[3][3];


r = loop (c,d);

if (r==1){
	system("cls");
	main();
}

return 0;

}


int loop(char c[][3], int d){ //Repite el ciclo para refrescar la imagen y actualizar por cada jugada, cambio de turnos etc.


int i,g,r,z;


i=0;
r=0;

intro_primera (c);

do{
	
z=0;

system("cls");
tablero(c);

if( i % 2 == 0 ){
	
	 intro_yo(c);
	
}else{
	 
	 if (d==1){
		intro_iafacil(c);
	}else{
		    
		    if(c[1][1]=='5'){
				
				 c[1][1]='O';
				
				}else{
				
					 z = check(c);
		
			     	 if(z==0){
			 	 
				  	 intro_iadificil(c);
			 	
				 	 }
				////	Rk	 aca va la intro ia dificil, hay que agregar un if 
				 }
		
				//intro ia_dificil;
		}
}

i++;

g = ganador(c);


}while(i<9 && g == 3);

system("cls");
tablero(c);

switch (g){

 case 1:
	printf("\n\n          HAS GANADO !!!! ERES UN GENIO !!! QUIERES JUGAR DE NUEVO ?\n 1- Si\n 2- No \n\n");
	scanf("%d",&r);
	break;
	

case 2:
	printf("\n\n          HAS PERDIDO !!!!!! INTENTALO DE NUEVO.\n 1- Si\n 2- No \n\n");
    scanf("%d",&r);
 	break;
	

case 3:
	printf("\n\n          HAN EMPATADO !!!!!! INTENTALO DE NUEVO. \n 1- Si \n 2- No \n\n");
	scanf("%d",&r);
	break;
	}
	
	return r;
}



void intro_primera (char c[][3]){ // define los valores de cada posicion de la matriz
	
	int i,j;
	
	char aux;
	
	aux = '1';
	
for (i=0;i<3;i++){
	
		for(j=0;j<3;j++){
		
			c[i][j] = aux++;
			
		}
	
	}
	
}

void intro_yo(char c[][3]){ //coloca la ficha del jugador
	
	int i,j,k;
	char aux;
	
	do{
		
		k=0;
		
		do{
			
			printf("\n\nColoca una ficha: ");
			fflush(stdin);
			scanf("%c",&aux);	
		
		}while (aux<'1' || aux>'9');	
			
			
		for(i=0;i<3;i++){
				
			for(j=0;j<3;j++){
				
				if(c[i][j]==aux){
					
					c[i][j]='X';
					k=1;
				}	
			}
		}
		
	if(k!=1){
		printf("\n Numero no disponible. Por favor selecciona de nuevo.\n");
	}	
	
	}while(k!=1);
	
}

void intro_iafacil(char c[][3]){  // coloca la ficha de la ia facil
	
	int i,j,k;
	
	srand (time(NULL));

do{
	
	i = rand () %3;
	j = rand () %3;
	
	k = 0;
	
	if (c[i][j]=='X' || c[i][j]=='O'){
		k=1;
	}

		
}while(k==1);
	
c[i][j]= 'O';
		
}


void tablero (char c[][3]){ //dibuja el tablero
	
	int i,j;
	
	for(i=0;i<3;i++){
		
		for (j=0;j<3;j++){
			
			if (j<2){
				printf(" %c |",c[i][j]);				
			}else{
				printf(" %c ",c[i][j]);
			}
		}
	if(i<2){
	
		printf("\n-----------\n");
	
	}
}
	
	printf("\n\n");
	
}

int check(char c[][3]){ //Comprueba entre los numeros disponibles para elegir si algun jugador tiene 2 'O'(primero) ó 'X'(si no hay 2'O's)y elige devolviendo z=1, saltando el turno de ia_dificil

char s[9];
int i,z,b;

z=0;
b=0;

for(i=0;i<9;i++){		//Cerar los vectores

 	s[i] = 0;
 	
}



if ( c[0][0] == '1' ) {// Comprueba el 1

	s[b] = '1';
	b++;

}
        
if ( c[0][1] == '2' ) {// Comprueba el 2

	s[b] = '2';
	b++;

}

if ( c[0][2] == '3' ) {// Comprueba el 3

	s[b] = '3';
	b++;

}
	
if ( c[1][0] == '4' ) {//Comprueba el 4

	s[b] = '4';
	b++;

}
	
if ( c[1][1] == '5' ) {//Comprueba el 5

	s[b] = '5';
	b++;
	
}
	
if ( c[1][2] == '6' ) {//Comprueba el 6

	s[b] = '6';
	b++;
	
}
	
if ( c[2][0] == '7' ) {//Comprueba el 7

	s[b] = '7';
	b++;

}
	
if ( c[2][1] == '8') {//Comprueba el 8 

	s[b] = '8';
	b++;

}
	
if ( c[2][2] == '9' ) {//Comprueba el 9

	s[b] = '9';
	b++;

}


//Ya tengo un S[] de numeros disponibles, ahora ver en sus posiciones las posibilidades de tapar 2 x o 2 O, empezar por las 'O'. Funciona correctamente

	
for (i=0; i<9 && z!=1; i++){

 	if(s[i]=='1'){

		 if (c[1][0] == 'O' && c[2][0] == 'O'|| c[0][1] == 'O' && c[0][2] == 'O' || c[1][1] == 'O' && c[2][2] == 'O'){
		
			  c[0][0] = 'O';
			  z=1;
			  			  
		 }
	 //fin if 1 'O'
	 }else if(s[i]=='2'){
	
			 if (c[1][1] == 'O' && c[2][1] == 'O'|| c[0][0] == 'O' && c[0][2] == 'O'){
		
			  c[0][1] = 'O';
			  z=1;
			  
	  	 		}
	 	//fin if 2 'O'
	 		 }else if(s[i]=='3'){

					 if (c[0][0] == 'O' && c[0][1] == 'O'|| c[2][0] == 'O' && c[1][1] == 'O' || c[1][2] == 'O' && c[2][2] == 'O'){
		
				 	  c[0][2] = 'O';
			  	   	  z=1;
			  	   	  
	  	 			}
	 			 //fin if 3 'O'
	 			    }else if(s[i]=='4'){

					 	 	 if (c[0][0] == 'O' && c[2][0] == 'O'|| c[1][1] == 'O' && c[1][2] == 'O'){
		
				 	 	   		 c[1][0] = 'O';
			  	   	  			 z=1;
			  	   	  			 
	  	 						}
			 			 //fin if 4 'O'
	 			     	 }else if(s[i]=='5'){
											
								 if (c[0][1] == 'O' && c[2][1] == 'O'|| c[1][0] == 'O' && c[1][2] == 'O' || c[0][0] == 'O' && c[2][2] == 'O' || c[2][0] == 'O' && c[0][2] == 'O'){
		
				 	  				 c[1][1] = 'O';
							  	   	  z=1;
							  	   	  
	  	 							}
	 			 			//fin if 5 'O'Rk
	 			    			}else if(s[i]=='6'){

					 					 if (c[0][2] == 'O' && c[2][2] == 'O'|| c[1][0] == 'O' && c[1][1] == 'O'){
		
				 	  				 		c[1][2] = 'O';
			  	   	  				 		z=1;
			  	   	  				 		
	  	 									}
	 			 				//fin if 6 'O'
	 					    			}else if(s[i]=='7'){

					 							 if (c[1][1] == 'O' && c[0][2] == 'O'|| c[1][0] == 'O' && c[0][0] == 'O' || c[2][1] == 'O' && c[2][2] == 'O'){
		
				 	  								 c[2][0] = 'O';
			  	   	  								 z=1;
			  	   	  								 
	  	 											 }
	 			 						 //fin if 7 'O'
	 			    							}else if(s[i]=='8'){

					 									if (c[1][1] == 'O' && c[0][1] == 'O'|| c[2][0] == 'O' && c[2][2] == 'O'){
		
				 	  										 c[2][1] = 'O';
			  	   	  										 z=1;
			  	   	  										 
	  	 													 }
	 			 									//fin if 8 'O'
	 			    									 }else if(s[i]=='9'){

					 											 if (c[2][0] == 'O' && c[2][1] == 'O'|| c[0][0] == 'O' && c[1][1] == 'O' || c[1][2] == 'O' && c[0][2] == 'O'){
		
				 	  												c[2][2] = 'O';
													 	  	   	    z=1;
													 	
	  	 															}
	 			 											//fin if 9 'O'
	 			 											//Empieza a ver si hay dos X
	 			    											}
																 	 
}
																	 
for (i=0; i<9 && z!=1; i++){																	 
																	 
																	 
	if(s[i]=='1'){

		 if (c[1][0] == 'X' && c[2][0] == 'X'|| c[0][1] == 'X' && c[0][2] == 'X' || c[1][1] == 'X' && c[2][2] == 'X'){
		
			  c[0][0] = 'O';
			  z=1;
			  }
	 //fin if 1 'X'
	 }else if(s[i]=='2'){
	
			 if (c[1][1] == 'X' && c[2][1] == 'X'|| c[0][0] == 'X' && c[0][2] == 'X'){
		
			  c[0][1] = 'O';
			  z=1;
	  	 	  }
	 	//fin if 2 'X'
	 		 }else if(s[i]=='3'){

					 if (c[0][0] == 'X' && c[0][1] == 'X'|| c[2][0] == 'X' && c[1][1] == 'X' || c[1][2] == 'X' && c[2][2] == 'X'){
		
				 	  c[0][2] = 'O';
			  	   	  z=1;
	  	 			  }
	 			 //fin if 3 'X'
	 			    }else if(s[i]=='4'){

					 	 	 if (c[0][0] == 'X' && c[2][0] == 'X'|| c[1][1] == 'X' && c[1][2] == 'X'){
		
				 	 	   		 c[1][0] = 'O';
			  	   	  			 z=1;
	  	 					 	 }
			 			 //fin if 4 'X'
	 			     	 }else if(s[i]=='5'){

						 		 if (c[0][1] == 'X' && c[2][1] == 'X'|| c[1][0] == 'X' && c[1][2] == 'X' || c[0][0] == 'X' && c[2][2] == 'X' || c[2][0] == 'X' && c[0][2] == 'X'){
		
				 	  				 c[1][1] = 'O';
							  	   	  z=1;
	  	 							 }
	 			 			//fin if 5 'X'
	 			    			}else if(s[i]=='6'){

					 					 if (c[0][2] == 'X' && c[2][2] == 'X'|| c[1][0] == 'X' && c[1][1] == 'X'){
		
				 	  				 		c[1][2] = 'O';
			  	   	  				 		z=1;
	  	 									}
	 			 				//fin if 6 'X'
	 					    			}else if(s[i]=='7'){

					 							 if (c[1][1] == 'X' && c[0][2] == 'X'|| c[1][0] == 'X' && c[0][0] == 'X' || c[2][1] == 'X' && c[2][2] == 'X'){
		
				 	  								 c[2][0] = 'O';
			  	   	  								 z=1;
	  	 											 }
	 			 						 //fin if 7 'X'
	 			    							}else if(s[i]=='8'){

					 									if (c[1][1] == 'X' && c[0][1] == 'X'|| c[2][0] == 'X' && c[2][2] == 'X'){
		
				 	  										 c[2][1] = 'O';
			  	   	  										 z=1;
	  	 													 }
	 			 									//fin if 8 'X' Hecho por Rodrigo Kohnen
	 			    									 }else if(s[i]=='9'){

					 											 if (c[2][0] == 'X' && c[2][1] == 'X'|| c[0][0] == 'X' && c[1][1] == 'X' || c[1][2] == 'X' && c[0][2] == 'X'){
		
				 	  												c[2][2] = 'O';
													 	  	   	    z=1;
	  	 															}
	 			 											//fin if 9 'X'
	 			    											}else{
	 			    												
	 			    												z=0;
	 			    											
																 	}

}//final if z!=1

	return z;
	
}




int start(){//menu eleccion
	
	int d;
	
	printf("-----   -----    -----   ----- \n  I     I    I   I       I\n  I     -----    -----   -----\n  I     I    I   I           I\n  I     I     I  -----   -----\n                       EN RAYA\n\n  Elija la dificultad:\n 1- Facil.  \n 2- Dificil.\n");
	
	scanf("%d",&d);
	
	while(d<1||d>2){
	printf("\n\nPor favor selecciona 1 o 2:\n ");
	scanf("%d",&d);
	}
	
	return d;
}

int ganador(char c[][3]){// Comprueba si hay ganador
	
	
	
if(c[0][0] =='X' || c[0][0] =='O'){ //controla el 1
		
	if(c[0][0]==c[0][1]&&c[0][0]==c[0][2]){//123
			
		if(c[0][0]=='X'){
				
			return 1;// He ganado
		
		}else{
				
			return 2;//He perdido
				
			}
			
	}
		
	if(c[0][0]==c[1][0]&&c[0][0]==c[2][0]){//147
			
		if(c[0][0]=='X'){
				
			return 1;
		
		}else{
				
			return 2;
			
			}
	}
		
	if(c[0][0]==c[1][1]&&c[0][0]==c[2][2]){//159
			
		if(c[0][0]=='X'){
				
			return 1;
			
		}else{
				
			return 2;
			
			}
	}
		
}
	
if(c[1][1] =='X' || c[1][1] =='O'){ //controla el 5
		
	if(c[1][1]==c[0][1]&&c[1][1]==c[2][1]){//528
			
		if(c[1][1]=='X'){
				
			return 1;
			
		}else{
				
			return 2;
				
		}
			
	}
	
	if(c[1][1] ==c[1][0] && c[1][1] == c[1][2]){//546
			
		if(c[1][1] =='X'){
				
			return 1;
			
		}else{
				
			return 2;
				
		}
			
	}
		
	if(c[1][1] == c[2][0] && c[1][1] == c[0][2]){//573
			
		if(c[1][1] =='X'){
				
			return 1;
		
		}else{
				
			return 2;
				
		}
	}
}

if(c[2][2] =='X' || c[2][2] =='O'){ //controla el 9
		
	if(c[2][2]==c[2][1]&&c[2][2]==c[2][0]){//987
			
		if(c[2][2]=='X'){
				
			return 1;
			
		}else{
				
			return 2;
				
		}
			
	}
	
	if(c[2][2]==c[0][2]&&c[2][2]==c[1][2]){//936
			
		if(c[2][2]=='X'){
				
			return 1;
			
		}else{
				
			return 2;
				
		}
			
	}
}

return 3;
}

void intro_iadificil(char c[][3]){
	
	
	int i,j,f;
	char so[5], s[9], v[3], res;
	
	f=0;
	
for(i=0;i<9;i++){		//Cerar los vectores

 	s[i] = 0;
 	
}

for(i=0;i<5;i++){

 	so[i] = 0;
 	
}

/*
funcion para crear un vector de numeros libres s y despues cerarlo para reutilizar y para ver si con alguno de ellos se tapan 2 'X' o 2 'O'. si es asi escribir	
*/	
	
//Crea dos vectores, uno de numeros favorables disponibles + 'O', y otro de Seleccionados 'O'
disp(c,s,so);//Paso de parametros y devolucion correcta, esta funcionando hasta aca. Probado con printf en main al terminar la funcion.

/*
for(i=0;i<9;i++){

printf("%c ",s[i]);

}

printf("\n\n");

for(i=0;i<5;i++){

printf("%c ",so[i]);

}

printf("\n\n");
*/
//Comprueba si en el vector favorable hay un vector ganador para poder elegir uno de esos elementos, y señala el vector ganador acertado.
f = ganare(v,s);//Paso de parametros y devolucion correcta, esta funcionando hasta aca. Probado con printf en main al terminar la funcion.
/*for(i=0;i<3;i++){
	
	 printf("%c ", v[i]);
	 
}

 printf("\n\n ");
*/
if (f==1){
	
	 intro_iafacil(c);
	
}else{



	 choice(v,so);

	 res = v[0];

	 for(i=0;i<3;i++){
				
			for(j=0;j<3;j++){
				
				if(c[i][j]==res){
					
					c[i][j]='O';
				 }	
			}
	    }


//printf("\n\n%c\n\n ",res);//Res es el numero elegido de los ganadores al azar.
 }
}


void choice(char v[3],char so[5]){ //1/3 Del vector ganador mira si hay 'O'  cera los que si, ordena por metodo burbuja y elige un numero al azar guardando en vector v para ahorrar variables.


int i,j,c;
char res;

c=0;

for (i=0;i<3;i++){
	
	 for(j=0;j<5;j++){
	 	
		 if ( v[i] == so[j] ){
		 		
		 	v[i] = '0';
		 	c++;//indica los 0 que hay
		 }
	 }
}

for (i=0;i<3;i++){
	
	 for(j=i+1;j<3;j++){
	 
	 	if(v[i] > v[j]){
	
			res=v[i];
			v[i]=v[j];
			v[j]=res;//Ordena por el metodo burbuja
		 }
	}
}

if (c==0){

srand(time(NULL));
i = rand() %3;	
res = v[i];
	
}else if(c==1){	
	 	 srand(time(NULL));
	 	 i = rand() %2+1;	
	 	 res = v[i];
	 	 }else if (c==2){
	 	 	 	 res = v[2];
	 	 	 	}

v[0] = res;

}
	
	
int ganare(char v[3],char s[9]){// 2/3Correcto, Funciona bien. Comprueba si en el vector favorable hay un vector ganador para poder elegir uno de esos elementos, y señala el vector ganador acertado.
	
int i, win, a, b, f;

//intente poner un switch case pero cuando hay muchas variables me sale optimiced out y me descarta variables...


v[0] = '1';
v[1] = '2';
v[2] = '3';  //CASO 0

f = 0;
win = 0;	
i = 0;

for(a=0;a<3;a++){
	
	 for (b=0;b<9 && win<a+1;b++){
		
		 if(v[a] == s[b]){
	 		 	
	     win++;
	 		 	
		 }	
	
	 }
}
	
if (win!=3){//V1
		
	
 	 v[0] = '1';
  	 v[1] = '4';
 	 v[2] = '7';  //CASO 1


	 win = 0;	
 	 i ++;
	
	 for(a=0;a<3;a++){
	
	 	 for (b=0;b<9 && win<a+1;b++){
		
		 	 if(v[a] == s[b]){
	 		 	
	     	 win++;
	 		 	
		 	}	
	
	 	 }
	 }
	
 	if (win!=3){//V2
		
	 	 v[0] = '1';
	 	 v[1] = '5';
	 	 v[2] = '9'; //CASO 2


	 	 win = 0;	
	 	 i ++;
	
	 	 for(a=0;a<3;a++){
	
	 	 	 for (b=0;b<9 && win<a+1;b++){
		
		 	 	 if(v[a] == s[b]){
	 		 	
	     	 	 win++;
	 		 	
			 	 }	
	
	 	 	 }
	 	 }
	
	 	 if (win!=3){//V3
		
		 	 v[0] = '2';
			 v[1] = '5';
			 v[2] = '8';// CASO 3


			 win = 0;	
	   		 i ++;
	
			 for(a=0;a<3;a++){
	
	 			 for (b=0;b<9 && win<a+1;b++){
		
		 			 if(v[a] == s[b]){
	 		 	
	     				win++;
	 		 	
		 				}	
	
	 			 }
			 }
	
			 if (win!=3){//V4
		
				 v[0] = '3';
				 v[1] = '5';
	 			 v[2] = '7';//CASO 4

				 win = 0;	
	  			 i ++;

				 for(a=0;a<3;a++){
	
	 	  		 	 for (b=0;b<9 && win<a+1;b++){
		
		 				 if(v[a] == s[b]){
	 		 	
	     				 win++;
	 		 	
		 				 }	
	
	 				 }
				}
	
				 if (win!=3){//V5
		
					 v[0] = '3';
					 v[1] = '6';
					 v[2] = '9';//CASO 5

					 win = 0;	
					 i ++;
	
					 for(a=0;a<3;a++){
	
	 					for (b=0;b<9 && win<a+1;b++){
		
		 				 	 if(v[a] == s[b]){
	 		 	
	     					 win++;
	 		 	
		 					 }	
	
	 					 }
					 }
	
					 if (win!=3){//V6
					 
		
						 v[0] = '4';
						 v[1] = '5';
						 v[2] = '6';//CASO 6

						 win = 0;	
						 i ++;

						 for(a=0;a<3;a++){
	
	 						 for (b=0;b<9 && win<a+1;b++){
		
		 						 if(v[a] == s[b]){
	 		 	
	     							win++;
	 		 	
		 						 }	
	
	 						 }
						 }
	
						 if (win!=3){//V7
		
						 v[0] = '7';
						 v[1] = '8';
						 v[2] = '9';//CASO 7

						 win = 0;	
						 i ++;

						 	 for(a=0;a<3;a++){
	
	 							 for (b=0;b<9 && win<a+1;b++){
		
		 							 if(v[a] == s[b]){
	 		 	
	     								 win++;
	 		 	
		 							 }
	
	 							 }
							 }
								if (win!=3){
								 f=1;
							 	}/*else{//V8
	  						    	 printf("\nHas ganado. El vector ganador es el %i\n",i);
		   							}
								*/
	
							 }/*else{//V7
	  		 				 printf("\nHas ganado. El vector ganador es el %i\n",i);Rk
		   	 				 }*/
	
	
					 	}/*else{//V6
	  		 			 printf("\nHas ganado. El vector ganador es el %i\n",i);
		   	 			 }*/			
	
	
				 	}/*else{//V5
	  		 	   	 printf("\nHas ganado. El vector ganador es el %i\n",i);
		   	 		 }*/
	
	
			 	}/*else{//V4
	  		 	 printf("\nHas ganado. El vector ganador es el %i\n",i);
		   	 	 }*/
	
	
			}/*else{//V3
	  		 printf("\nHas ganado. El vector ganador es el %i\n",i);
		   	 }*/
	
	
		 }/*else{//V2
	   	 printf("\nHas ganado. El vector ganador es el %i\n",i);
   	    }*/
	
	
	 }/*else{ V1
		printf("\nHas ganado. El vector ganador es el %i\n",i);
	 }*/
	 
return f;	 
	 
}


void disp(char c[][3], char s[9], char so[5])// 3/3Correcto, Funciona bien Crea dos vectores, uno de numeros favorables disponibles + 'O', y otro de Seleccionados 'O'
{

    int  i, a, b;
    

    a = 0;
    b = 0;
    
//No me deja hacer ciclos no compila bien el compilador, variables optimized out, se salta el orden de los ciclos, 3 for anidados y dos if anidados. Ver. Me dijeron que quite optimizaciones con gcc -O0
// Cambio por 9 if para terminar... 

if ( c[0][0] == '1' || c[0][0] == 'O') {// Comprueba el 1

	s[b] = '1';
	b++;

	if (c[0][0] == 'O') {

		so[a] = '1';
		a++;
    }
}
        
if ( c[0][1] == '2' || c[0][1] == 'O') {// Comprueba el 2

	s[b] = '2';
	b++;

	if (c[0][1] == 'O') {

		so[a] = '2';
		a++;
    }
}

if ( c[0][2] == '3' || c[0][2] == 'O') {// Comprueba el 3

	s[b] = '3';
	b++;

	if (c[0][2] == 'O') {

		so[a] = '3';
		a++;
    }
}
	
if ( c[1][0] == '4' || c[1][0] == 'O') {//Comprueba el 4

	s[b] = '4';
	b++;

	if (c[1][0] == 'O') {

		so[a] = '4';
		a++;
    }
}
	
if ( c[1][1] == '5' || c[1][1] == 'O') {//Comprueba el 5

	s[b] = '5';
	b++;

	if (c[1][1] == 'O') {

		so[a] = '5';
		a++;
    }
}
	
if ( c[1][2] == '6' || c[1][2] == 'O') {//Comprueba el 6

	s[b] = '6';
	b++;

	if (c[1][2] == 'O') {

		so[a] = '6';
		a++;
    }
}
	
if ( c[2][0] == '7' || c[2][0] == 'O') {//Comprueba el 7

	s[b] = '7';
	b++;

	if (c[2][0] == 'O') {

		so[a] = '7';
		a++;
    }
}
	
if ( c[2][1] == '8' || c[2][1] == 'O') {//Comprueba el 8 

	s[b] = '8';
	b++;

	if (c[2][1] == 'O') {

		so[a] = '8';
		a++;
    }
}
	
if ( c[2][2] == '9' || c[2][2] == 'O') {//Comprueba el 9

	s[b] = '9';
	b++;

	if (c[2][2] == 'O') {

		so[a] = '9';
		a++;
    }
}
	

/*for (m='1';m<='9';m++){

	for (n=0;n<3;n++){
		
		for (k=0;k<3;k++){
			
			if (m==c[n][k] || c[n][k] =='O'){
				
				s[b] = m;
				b++;
				
				if (c[n][k] =='O'){
				
					so[a] = m;
					a++;
					n
				}
			}
		}
	}		
}
*/	
	
}
	






