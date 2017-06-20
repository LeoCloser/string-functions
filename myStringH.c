#include <conio.h>
#include <stdio.h>
#include <windows.h> // In the other IDE or Compilers not is necesary this library
/*
    Mis funciones de la libreria string.h 
    
	Lopez Madrigal Leonardo 
*/

char *_strtok(char *str, char *caracter);
int stringCompare(char *str1, char *str2);
char *convertMayus(char *str);
char *convertMinus(char *str);
char *invertString(char *str);
void stringCopy(char *str, char *dest);
char *strConcat(char *str, char *str2);
int longitud(char *str);
char *strcharpos(char *str, char caracter);
//int _strcmpii(char *str, char *str2); /* No distingue mayuscula sobre min*/
//char *_strnset (char * s, int ch, size_t n); /* Establece un número n determinado de caracteres ch de una cadena. */
char * _strstr (const char * s1, const char * s2);
/* compara una cadena completa con una palabra y si la ecuenctra regresa el puntero */

char *str = "Hola-mundo - desde - java - hola";

char *prueba ="casaasdAAvvbsd12312as";
char *prueba2 ="casaasd";

int main(void){
	
	char *temp, *destino, i=0;
	char *caracter = " ";
	temp = (char *)malloc(sizeof(char ));
	
	/*temp = _strtok(str,caracter);
    puts(temp);*/
    if( stringCompare(prueba,prueba2) ){
    	printf("1\n");
	} else {
		printf("0\n");
	}
	temp = convertMayus(prueba);
	printf("%s\n",temp);
	temp = convertMinus(temp);
	printf("%s\n",temp);
	
	temp = invertString("casa");
	printf("%s\n",temp);
	
	stringCopy(temp,destino);
	printf("%s\n",destino);
	return 0;
}

char *_strtok(char *str, char *caracter){
	int j=0; 
	char *aux;
	aux = (char *)malloc(sizeof(char ));  /*only in dev c++ 5.11 dev c++ 5.11*/
	while( *str == *caracter ) *str++;
	
	while( *str != *caracter && *str != '\0' ){
	       //Copy string 
		   aux[j++] = *str++;
	}
	aux[j] = '\0';
	return aux;
}

int stringCompare(char *str1, char *str2){
	int bandera=0, i=0, j=0;
	
	while( str1[i] != '\0' || str2[j] != '\0' ){ //Compare two string whith the end. 
		
		if( str1[i] == str2[j] ){           // equals the flag=1;
		    bandera=1;
		} else {
		    bandera=0;                   //no equals flag=0 and finish.
		    return bandera;
		}
		i++;
		j++;
		
	}
	return bandera;
}

char *convertMayus(char *str){
	int i=0;
	char *aux;
	aux = (char *)malloc(sizeof(char )); //only in dev c++ 5.11
	while( str[i] != '\0' ){
		if( str[i] >= 'a' && str[i] <= 'z' ){
			aux[i] = str[i] - 32;
		} else {
			aux[i] = str[i];
		}
		i++;
	}
	aux[i]='\0';
	return aux;
}

char *convertMinus(char *str){
	int i=0;
	char *aux;
	aux = (char *)malloc(sizeof(char )); //only in dev c++ 5.11
	while(str[i] != '\0'){
		if( str[i] >= 'A' && str[i] <= 'Z'){
			aux[i] = str[i] + 32;
		} else {
			aux[i] = str[i];
		} 
		i++;
	}
	aux[i]='\0';
	return aux;
}

char *invertString(char *str){
	int i=0, j=0;
	char *aux;
	aux = (char *)malloc(sizeof(char )); //only in dev c++ 5.11
	j = longitud(str);
	do{
		aux[i] = str[j-1]; // sub -1 for the last place is the end '\0', pos-1 == last character
		i++;
		j--;
	}while(j > 0);
	aux[i]='\0';
	return aux;
}

void stringCopy(char *str, char *dest){
	int i=0, j=0; 
	while(str[i] != '\0'){
		dest[j++] = str[i++];
	}
    dest[j]='\0';
}

/*char *strConcat(char *str, char *str2){
	int i=0, j=longitud(str);

}*/

/*
    char *strConcat(char *str, char *str2);
    char *strcharpos(char *str, char caracter);
*/

int longitud(char *str){ // int strlen(char * )
	int i=0;
 
	while( str[i] != '\0' ){
	
		   i++;
	}
	
	return i;
}

