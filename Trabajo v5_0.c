#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Delraramos Funciones

int MARCAS();
void ALTA_OP();
int BAJA_OP ();
void ALTA_INC();
int OPERARIOS();
int OPERARIOSALTA();
int OPERARIOSBAJA();


int main(){
	// Declaramos Variables
	int opcsw;
	int opcsw2;
	int opcsw4; 
	
	Menuinicio:
	do{ 
	 system("cls");
	 printf("\t\t CONTROL DE TIEMPOS\n");
	 printf("\t\t BY PEDRO & LUCAS\n\n\n\n");
	 printf("\t 1 - Marcas\n\n");
	 printf("\t 2 - Gestion de Operarios\n\n");
 	 printf("\t 3 - Alta de Incidencias\n\n");  // Define las incidencia a utilizar.
	 printf("\t 4 - Informes Listados\n\n\n");
	 printf("\t\t Seleccione una opcion........:\t");
	 scanf("%i",&opcsw);
	}while(opcsw!=1 && opcsw!=2 && opcsw!=3 && opcsw!=4);
	
		switch(opcsw){
		case 1:	// Marcas	// Ahora capturamos marca 	
		marca:
		system("cls");
		printf("\t\t CONTROL DE TIEMPOS\n");	
		printf("\t\t Marcas\n\n\n");
		
		MARCAS (); // Funcion Marcas
		
		Sleep (3000);
		goto Menuinicio;
		break;
				
		case 2:	// Gestion de Operarios
		menugestionoperarios:	
		do{
		// Menu de Operarios
		system("cls");
		printf("\t\t CONTROL DE TIEMPOS\n");
		printf("\t\t GESTION DE OPERARIOS\n\n\n\n");
		printf("\t 1 - Alta de Operario\n\n");
		printf("\t 2 - Baja de Operario\n\n");
		printf("\t 3 - Menu Inicial\n\n\n\n");
		printf("\t\t Seleccione una opcion........:\t");
	 	scanf("%i",&opcsw2);
		}while(opcsw2!=1 && opcsw2!=2 && opcsw2!=3);
			switch(opcsw2){
			    case 1:
				system("cls");
				printf("\t\t CONTROL DE TIEMPOS\n");	
				printf("\t\t Gestion de operarios - Alta de Operarios\n\n");
				
				ALTA_OP();
								
				goto menugestionoperarios;
				break;	
				
			    case 2:
			    system("cls");
				printf("\t\t CONTROL DE TIEMPOS\n");	
				printf("GESTION DE OPERARIOS - Baja de Operarios\n\n");
				
				
				BAJA_OP();
				
				
				goto menugestionoperarios;
				break;
			
			    case 3:
			    goto Menuinicio;
				break;
				
				default:
					printf("Seleccion no valida");
					Sleep(3000);
					goto menugestionoperarios;
			}
			break;
		
		case 3: 
		
		    system("cls");
			printf("\t\t CONTROL DE TIEMPOS\n");	
			printf("GESTION DE INCIDENCIAS\n\n");
			
			ALTA_INC();
			
			Sleep (3000);
			goto Menuinicio;
		
		break;
		
		case 4:
		menuinformes:	
		do{
		//Menu Listados
		system("cls");
		printf("\t\t CONTROL DE TIEMPOS\n");	
		printf("\t\t Informes - Listados\n\n");
		printf("\t 1 - Listado Global de Operarios:\n\n");
		printf("\t 2 - Listados Operarios de Alta:\n\n");
		printf("\t 3 - Listados Operarios de Baja:\n\n");
		printf("\t 4 - Menu Inicial\n\n\n\n");
		printf("\t\t Seleccione una opcion........:\t");
	 	scanf("%i",&opcsw4);
		}while(opcsw4<1 || opcsw4>4);
			
			switch(opcsw4){
			    case 1: // Listado global de operarios
					system("cls");
					printf("\t\t CONTROL DE TIEMPOS\n");	
					printf("\t\t Listado Global de Operarios\n\n\n");
									
					OPERARIOS();
					
					Sleep (10000);
					goto menuinformes;	
				break;
				
				case 2: // Listado Operarios de Alta
					system("cls");
					printf("\t\t CONTROL DE TIEMPOS\n");	
					printf("\t\t Listado Operarios de Alta\n\n\n");
					
					OPERARIOSALTA();
					
					Sleep (10000);
					goto menuinformes;
				break;
		
				case 3: // Listado Operarios de Baja
					system("cls");
					printf("\t\t CONTROL DE TIEMPOS\n");	
					printf("\t\t Listado Operarios de Baja\n\n\n");
					
					OPERARIOSBAJA();
					
					Sleep (10000);
					goto menuinformes;
				break;
				
				case 4:
			   goto Menuinicio;
				break;
			}
		break;
		}
return 0;
}

//<<  FUNCIONES  >>
 
// FUNCION MARCAS
int MARCAS(){

	struct operario{
		int id_operario;
		char estado;
		char nombre[50];
		char apellido_1[50];
		char apellido_2[50];
	};

// Declaramos Variables

	char opccase [20];
	//int id_operario;
	int id_operarioB;
	char tipo_marca[25];
	int cod_inc;
	char ent_sal[25];
	char fecha[128];
	char hora[128];
	
	// Calculo de Fecha y Hora Buscado en Intenet - https://poesiabinaria.net-

	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	strftime(fecha,128,"%d/%m/%y",tlocal);
	strftime(hora,128,"%H:%M:%S",tlocal);
	
	//Solicitamos Datos de la Marca a Realizar
	printf("\t Fecha\t\t\t\t");printf("%s\n",fecha);
	printf("\n\t Hora\t\t\t\t");printf("%s\n",hora);
	printf("\n\t Cod. Operario\t\t\t");scanf("%i",&id_operarioB);

	// BUSCAMOS QUE EL OPERARIO EXISTA Y NO ESTE DE BAJA.
	struct operario gestion[100];
	int n=0;
	int i;
		
	FILE*fichero;
		fichero = fopen("operarios.txt","r");
	
		if (fichero == NULL) {
		printf("Error en la apertura de fichero");
		return -1;
		}
		
		while(fscanf(fichero,"%i %c %s %s %s\n",&gestion[n].id_operario,&gestion[n].estado,gestion[n].nombre,gestion[n].apellido_1,gestion[n].apellido_2) != EOF){
		n++;
		}
		
		if (id_operarioB>n){
			printf("\n\n <<EL OPERARIO NO EXISTE>>\n\n\n");
			Sleep(3000);
		}
		
	for (i=0; i<n; i++){

		if (gestion[i].id_operario == id_operarioB){
			if(gestion[i].estado =='A'){
				printf("\n\t Presencia/Incidencia (P/I)\t");scanf("%s",&tipo_marca);
	
				// Condicional Tipo de Marca (P) presencia.  
	     		if(strcmp(tipo_marca,"P")==0){
					printf("\n\t Entrada/Salida (E/S)\t\t");scanf("%s",&ent_sal);
			
					// Ahora presentamos la marca a realizar/grabar
					system("cls");
					printf("\t\t CONTROL DE TIEMPOS\n\n");
					printf("\t\t Marcas\n\n\n");
					printf("\t\t <<USTED VA A MARCAR>> \n\n");
					printf("\t Fecha\t\t\t\t");printf("%s\n",fecha);
					printf("\n\t Hora\t\t\t\t");printf("%s\n",hora);
					printf("\n\t Cod. Operario\t\t\t");printf("%i\t",id_operarioB);printf("%s\t",gestion[i].nombre);printf("%s\t",gestion[i].apellido_1);printf("%s\t",gestion[i].apellido_2);
					printf("\n\n\t Presencia/Incidencia (P/I)\t");printf("%s",tipo_marca);
					printf("\n\n\t Entrada/Salida (E/S)\t\t");printf("%s\n\n\n",ent_sal);
					cod_inc = 0;
			
					printf("\t\t<<DESEA REGISTRAR MARCA (SI/NO)>>\t");
			
					scanf("%s",&opccase);
				if(strcmp(opccase,"SI")==0){
			
					FILE* fichero;
					fichero = fopen("marcas.txt", "a");
					fprintf(fichero,"%s ",fecha);
					fprintf(fichero,"%s ",hora); 
					fprintf(fichero,"%i ",id_operarioB);
					fprintf(fichero,"%s ",tipo_marca);
					fprintf(fichero,"%s ",ent_sal);
					fprintf(fichero,"%i\n",cod_inc);
					fclose(fichero);
				
					printf("\t\t <<Marca Presencia Registrada>>\n");
				}	
				if(strcmp(opccase,"NO")==0){
					printf("\t\t <<Marca Presencia NO registrada>>\t\t");
				}			
				}
				// Condicional Tipo de Marca (P) presencia. 
	 			if(strcmp(tipo_marca,"I")==0){
	 	 			printf("\n\t Cod. Incidencia\t\t");scanf("%i",&cod_inc);
					printf("\n\t Salida/Entrada (S/E)\t\t");scanf("%s",&ent_sal);
	 	
	    			// Ahora presentamos la marca a realizar/grabar
					system("cls");
					printf("\t\t CONTROL DE TIEMPOS\n\n");
					printf("\t\t Marcas\n\n\n");
					printf("\t\t <<USTED VA A MARCAR>> \n\n");
					printf("\t Fecha\t\t\t\t");printf("%s\n",fecha);
					printf("\n\t Hora\t\t\t\t");printf("%s\n",hora);
					printf("\n\t Cod. Operario\t\t\t");printf("%i",id_operarioB);
					printf("\n\n\t Presencia/Incidencia (P/I)\t");printf("%s",tipo_marca);
					printf("\n\n\t Salida/Entrada (S/E)\t\t");printf("%s",ent_sal);
					printf("\n\n\t Cod. Incidencia\t\t");printf("%i\n\n\n",cod_inc);
				
					printf("\t\t <<DESEA REGISTRAR MARCA (SI/NO)>>\t");
					scanf("%s",&opccase);
					
					if(strcmp(opccase,"SI")==0){
						FILE* fichero;
						fichero = fopen("marcas.txt", "a");
						fprintf(fichero,"%s ",fecha);
						fprintf(fichero,"%s ",hora);
						fprintf(fichero,"%i ",id_operarioB);
						fprintf(fichero,"%s ",tipo_marca);
						fprintf(fichero,"%s ",ent_sal);
						fprintf(fichero,"%i\n",cod_inc);
						fclose(fichero);
					
						printf("\n\n <<Marca Incidencia Registrada>>\n");
					}		
					if(strcmp(opccase,"NO")==0){
					printf("\n\n <<Marca Incidencia NO registrada>>\t\t");
					}	
				}
			}		
		}
		if (gestion[i].id_operario == id_operarioB){
			if(gestion[i].estado =='B'){
				printf("\n\n <<EL OPERARIO ESTA DE BAJA>>\n\n\n");
				Sleep(3000);	
			}
		}
	}
	fclose(fichero);

	return 0;
}

		
//FUNCION ALTA DE OPERARIO
void ALTA_OP()
{
	char registro;
	char nuevo_op;
	int id_operario;
	char estado[50]= "A";
	char nombre[50];
	char apellido_1[50];
	char apellido_2[50];
   int ch;
	int num_lineas;
	
	FILE * NLineas;	
	
	//Alta_Operarios;
	Alta_Operario_1:
	system("cls");
	printf("\t\t CONTROL DE TIEMPOS\n");
	printf("\t\t Gestion de Operarios - Alta de Operarios\n\n\n");

	// Calculo del Nº de Operario - El ultimo+1
		NLineas = fopen("Operarios.txt", "r");
      if(NLineas == NULL){
      	printf("Error en apertura");
      }
	   num_lineas = 0;
   	while ((ch = fgetc(NLineas)) != EOF){
       if (ch == '\n'){
       num_lineas++;
       }
      }
     	fclose(NLineas);
	
	id_operario = num_lineas+1;

	printf("\tid_operario:\t\t\t");printf("%i\n",id_operario);
	printf("\tEstado (A) Alta:\t\t");printf("%s\n",estado);// Por defecto es A
	printf("\tNombre:\t\t\t\t");scanf("%s",&nombre);	
	printf("\tApellido 1:\t\t\t");scanf("%s",&apellido_1);
	printf("\tApellido 2:\t\t\t");scanf("%s",&apellido_2);
	
	// Alta de Operarios - Presentacion de datos
	system("cls");
	printf("\t\t CONTROL DE TIEMPOS\n");
	printf("\t\t Gestion de Operarios - Alta de Opearios\n\n\n");	
	
	printf("\t\t <<USTED VA A REGISTRAR>> \n\n");
	
	printf("\tid_operario:\t\t\t");printf("%i\n",id_operario);
	printf("\tEstado (A) Alta (B) Baja:\t");printf("%s\n",estado);
	printf("\tNombre:\t\t\t\t");printf("%s\n",nombre);	
	printf("\tApellido 1:\t\t\t");printf("%s\n",apellido_1);
	printf("\tApellido 2:\t\t\t");printf("%s\n\n\n",apellido_2);
	
		do{
		printf("\t\tDesea registrar operario (S/N):\t");scanf("%s",&registro);
		} while (registro !='S' && registro !='N') ; 

	if (registro == 'S'){

		FILE* fichero;
		fichero = fopen("operarios.txt", "a");
		fprintf(fichero,"%i ",id_operario);
		fprintf(fichero,"%s ",estado);
		fprintf(fichero,"%s ",nombre);
		fprintf(fichero,"%s ",apellido_1);
		fprintf(fichero,"%s\n",apellido_2);
		fclose(fichero);
		printf("\n\n <<Operario registrado>>\n");	
		printf("\n\n <<Registrar Nuevo Operario (S/N)>>\t");scanf("%s",&nuevo_op);
		if (nuevo_op=='S'){
		goto Alta_Operario_1;
		}
	}
	if (registro=='N'){
		printf("Opererio NO registrado");	
		
	}
}

//FUNCION DE BAJA OP
int BAJA_OP()
{
	struct operario{
		int id_operario;
		char estado;
		char nombre[50];
		char apellido_1[50];
		char apellido_2[50];
	};

	int id_operarioB;

	system("cls");
	printf("\t\t CONTROL DE TIEMPOS\n");
	printf("\t GESTION DE OPERARIOS- BAJA DE OPERARIOS\n\n");

		printf("Introduzca id_Opeario a dar de BAJA:\t");scanf("%i",&id_operarioB); // 

	struct operario gestion[100];
	int n=0;
	int i;
		
	FILE*fichero;
		fichero = fopen("operarios.txt","r");
	
		if (fichero == NULL) {
		printf("Error en la apertura de fichero");
		return -1;
		}
		
		while(fscanf(fichero,"%i %c %s %s %s\n",&gestion[n].id_operario,&gestion[n].estado,gestion[n].nombre,gestion[n].apellido_1,gestion[n].apellido_2) != EOF){
		n++;
		}
	
	
		if (id_operarioB>n){
			printf("\n\n <<EL OPERARIO NO EXISTE>>\n\n\n");
			Sleep(3000);
		}

		printf("\n\nCodigo\tEstado\tNombre\tApellido 1\tApellido 2\n");
	
	for (i=0; i<n; i++){

		if (gestion[i].id_operario == id_operarioB){
			if(gestion[i].estado =='A'){
				printf("%i\t %c\t %s\t %s\t %s\n",gestion[i].id_operario,gestion[i].estado,gestion[i].nombre,gestion[i].apellido_1,gestion[i].apellido_2);
				
				Sleep(3000);
				
				gestion[i].estado = 'B';
			
				system("cls");
				printf("\t\t CONTROL DE TIEMPOS\n");
				printf("\t GESTION DE OPERARIOS- BAJA DE OPERARIOS\n\n");
				printf("\n\nCodigo\tEstado\tNombre\tApellido 1\tApellido 2\n");
				printf("\n\n EL OPERARIO VA A CAMBIAR SU ESTADO A BAJA \n\n");
				printf("%i\t %c\t %s\t %s\t %s\n",gestion[i].id_operario,gestion[i].estado,gestion[i].nombre,gestion[i].apellido_1,gestion[i].apellido_2);
			}		
		}
		if (gestion[i].id_operario == id_operarioB){
			if(gestion[i].estado =='B'){
				printf("%i\t %c\t %s\t %s\t %s\n",gestion[i].id_operario,gestion[i].estado,gestion[i].nombre,gestion[i].apellido_1,gestion[i].apellido_2);
				printf("\n\n <<EL OPERARIO YA ESTA DE BAJA>>\n\n\n");
				Sleep(3000);	
			
			}
		}
	}
	fclose(fichero);
	
	fichero = fopen("operarios.txt","w+");
	
		if (fichero == NULL) {
		printf("Error en la apertura de fichero");
		return -1;
		}	
	for (i=0; i<n; i++){
	//	printf("%i\t %c\t %s\t %s\t %s\n",gestion[i].id_operario,gestion[i].estado,gestion[i].nombre,gestion[i].apellido_1,gestion[i].apellido_2);
	
	fprintf(fichero, "%i %c %s %s %s\n",gestion[i].id_operario,gestion[i].estado,gestion[i].nombre,gestion[i].apellido_1,gestion[i].apellido_2);
	}	
	
	fclose(fichero);
	
	return 0;
	}

//FUNCION ALTA DE INCIDENCIAS
void ALTA_INC()
{
	int id_incidencia; // Identificador de Incidencia
	char registro_inc;
	char nueva_inc;
	char tipo_inc[1]; // Son dos tipos, de Trabajo (T) o Personal (P)
	char descripcion_inc[50];
   int ch;
	int num_lineas;
	
	FILE * NLineas;
	
//	Solicitud datos Incidencia a resgistrar.
	alta_incidencia:
	system("cls");
	printf("\t\t CONTROL DE TIEMPOS\n");
	printf("\t GESTION DE INCIDENCIAS - Alta de incidencias\n\n");

	// Calculo del Nº de Incidencia - El ultimo+1
	NLineas = fopen("Incidencias.txt", "r");
      if(NLineas == NULL){
      	printf("Error en apertura");
        }
	   num_lineas = 0;
   	while ((ch = fgetc(NLineas)) != EOF){
       if (ch == '\n'){
       num_lineas++;
       }
      }
     	fclose(NLineas);
		id_incidencia = num_lineas+1;
		
	printf("Codigo Incidencia:\t\t\t\t");printf("%i\n",id_incidencia);
		
	printf("Tipo Incidencia Trabajo(T) / Personal(P):\t");scanf("%s",&tipo_inc); 
	printf("Descripcion Incidencia:\t\t\t\t");scanf("%s",&descripcion_inc);	

	//	Presentación de Incidencia a resgistrar.
	system("cls");
	printf("\t\t CONTROL DE TIEMPOS\n");
	printf("\t GESTION DE INCIDENCIAS - Alta de incidencias\n\n");
	
	printf("Codigo Incidencia:\t\t\t\t");printf("%i\n\n",id_incidencia);
	printf("Tipo Incidencia Trabajo (T)/Personal (P):\t");printf("%s\n\n",tipo_inc);
	printf("Descripcion Incidencia:\t\t\t\t");printf("%s\n\n",descripcion_inc);	

	do{
		
		printf("Desea registrar incidencia: (S/N):\t");scanf("%s",&registro_inc);
			
	} while (registro_inc !='S' && registro_inc !='N') ; 			

	if (registro_inc == 'S'){
	
		//printf("Estoy en registro \n\n");
	
		FILE* fichero;
	
		fichero = fopen("incidencias.txt", "a"); 
		fprintf(fichero,"%i ",id_incidencia);
		fprintf(fichero,"%s ",tipo_inc);
		fprintf(fichero,"%s\n",descripcion_inc);
		fclose(fichero);
		
		printf("\n\n <<Incidencia registrada>>\n");	
		printf("\n\n <<Registrar Nueva Incidencia (S/N)>>\t");scanf("%s",&nueva_inc);
		if (nueva_inc == 'S'){
	    goto alta_incidencia;
		}
	}
		if (registro_inc == 'N'){
		printf("\n\n<<Incidncia NO registrada>>");	
			
	}
}

//FUNCION LISTADO GLOBAL DE OPERARIOS
int OPERARIOS(){
	
	struct operario{
		int id_operario;
		char estado;
		char nombre[50];
		char apellido_1[50];
		char apellido_2[50];
	};
		
	system("cls");
	printf("\t\t CONTROL DE TIEMPOS\n");
	printf("\t INFORMES - LISTADO GLOBAL DE OPERARIOS\n\n");
		
	struct operario gestion[100];
	int n=0;
	int i;
	FILE*fichero;
		fichero = fopen("operarios.txt","r");
	
		if (fichero == NULL) {
		printf("Error en la apertura de fichero");
		return -1;
		}
		
		while(fscanf(fichero,"%i %c %s %s %s\n",&gestion[n].id_operario,&gestion[n].estado,gestion[n].nombre,gestion[n].apellido_1,gestion[n].apellido_2) != EOF){
		n++;
		}
		fclose(fichero);
	
	printf("Codigo\tEstado\tNombre\tApellido 1\tApellido 2\n");
	for (i=0; i<n; i++){
	printf("%i\t %c\t %s\t %s\t %s\n",gestion[i].id_operario,gestion[i].estado,gestion[i].nombre,gestion[i].apellido_1,gestion[i].apellido_2);
	}
	
	printf("Numero de Operarios: %d\n", n);
	return 0;
}

//FUNCION LISTADO OPERARIOS DE ALTA
int OPERARIOSALTA(){

struct operario{
		int id_operario;
		char estado;
		char nombre[50];
		char apellido_1[50];
		char apellido_2[50];
	};
			
	system("cls");
	printf("\t\t CONTROL DE TIEMPOS\n");
	printf("\t INFORMES - LISTADO ALTAS DE OPERARIOS\n\n");
	
	struct operario gestion[100];
	int n=0,contAltas=0;
	int i;
	FILE*fichero;
		fichero = fopen("operarios.txt","r");
	
		if (fichero == NULL) {
		printf("Error en la apertura de fichero");
		return -1;
		}
			
		while(fscanf(fichero,"%i %c %s %s %s\n",&gestion[n].id_operario,&gestion[n].estado,gestion[n].nombre,gestion[n].apellido_1,gestion[n].apellido_2) != EOF){
		n++;
		}
		fclose(fichero);
		
	printf("Codigo\tEstado\tNombre\tApellido 1\tApellido 2\n");
	for (i=0; i<n; i++){
	    if(gestion[i].estado == 'A'){
		printf("%i\t %c\t %s\t %s\t %s\n",gestion[i].id_operario,gestion[i].estado,gestion[i].nombre,gestion[i].apellido_1,gestion[i].apellido_2);
		contAltas++;
		}
	}	
	printf("Numero Total de Operarios: %d\n", n);
	printf("Numero de Altas:%i",contAltas);
	return 0;
}

//FUNCION LISTADO OPERARIOS DE BAJA
int OPERARIOSBAJA(){

struct operario{
		int id_operario;
		char estado;
		char nombre[50];
		char apellido_1[50];
		char apellido_2[50];
	};
			
system("cls");
	printf("\t\t CONTROL DE TIEMPOS\n");
	printf("\t INFORMES - LISTADO ALTAS DE OPERARIOS\n\n");
	
	
	struct operario gestion[100];
	int n=0,contBajas=0;
	int i;
	FILE*fichero;
	fichero = fopen("operarios.txt","r");
	
	if (fichero == NULL) {
		printf("Error en la apertura de fichero");
		return -1;
	}
		
	while(fscanf(fichero,"%i %c %s %s %s\n",&gestion[n].id_operario,&gestion[n].estado,gestion[n].nombre,gestion[n].apellido_1,gestion[n].apellido_2) != EOF){
		n++;
	}
	
	fclose(fichero);
	
	
	printf("Codigo\tEstado\tNombre\tApellido 1\tApellido 2\n");
	for (i=0; i<n; i++){
	    if(gestion[i].estado == 'B'){
		  printf("%i\t %c\t %s\t %s\t %s\n",gestion[i].id_operario,gestion[i].estado,gestion[i].nombre,gestion[i].apellido_1,gestion[i].apellido_2);
		  contBajas++;
		}
	
}
	printf("Numero Total de Operarios: %d\n", n);
	printf("Numero de Bajas:%i",contBajas);
	return 0;
}
