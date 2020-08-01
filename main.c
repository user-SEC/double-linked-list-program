
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//stale TRUE potrzebne do  warunkow
const int TRUE = 1;
//numer albumu z warunkow zadania
const int student_id = 75194;
//wyswietlanie ciagu znakow poprzedzone tabulaturami
void printf_correct(char* string)
{
	printf("\t\t\t\t\t\t %s\n",string);
}
//konwersja do szesnastkowego
void printf_hex()
{
	//wczytujemy liczbe do konwersjii
	char num[100];
	printf_correct("Podaj liczbe do konwersji");
	scanf("%99s",num);
	char *check;
	//funkcja 'strtol' konwersja do systemu 10
	int converted_number = strtol(num,&check, 8);
	// jezeli konwersja sie nie udala, zapisujemy do  check
	// sprawdzamy czy konwersja sie udala i czy liczba spelnia warunek
	//numer albumu studenta
	if(*check != '\0' || converted_number > student_id)
		printf_correct("Nie mozna przekonwertowac");
	//jezeli wszystko spelnione wyswietl w danym systemie
	else
		printf("\t\t\t\t\t\tLiczba w postaci heksadecymalnej: %X\n",converted_number);
	
}
//konwersja do osemkowego
void printf_oct(){
	//wczytujemy liczbe do konwersjii
	char num[100];
	printf_correct("Podaj liczbe do konwersji");
	scanf("%99s",num);
	char *check = "";
	int converted_number = strtol(num,&check, 16);
	// jezeli konwersja sie nie udala, zapisujemy do  check
	// sprawdzamy czy konwersja sie udala i czy liczba spelnia warunek
	//numer albumu studenta
	if(*check != '\0' || converted_number > student_id)
		printf_correct("Nie mozna przekonwertowac");
	else
		//jezeli wszystko spelnione wyswietl w danym systemie
		printf("\t\t\t\t\t\tLiczba w postaci osemkowej: %o\n",converted_number);	
}
//funkcja okreslacja dzialanie programu w zaleznosci
//od wybory uzytkownika
void program_system(char* choice){

int correct = 0;
//porownujemy wybor uzykownia z konkretnymi opcjami funkcja 'strcmp'
//jezeli pasuje wywolujemy konkretna funkcje konwersjii lub wychodzimy
if(!strcmp(choice,"1")){
	printf_correct("Wybrano opcje 1");
	correct = 1;
	printf_hex();
}
if(!strcmp(choice,"2")){
	printf_correct("Wybrano opcje 2");
	correct = 1;
	printf_oct();
}
if(!strcmp(choice,"3"))
	{printf_correct("Zegnaj");
	exit(0);}
//jezeli nie znaleziono dopasowania komunikat i powrot d
//glownej petli programu
if(!correct)
printf_correct("Wprowadz poprawna opcje");	
} 
//menu glowna petla programu wyswietla menu i oczekuje na wczytanie wyboru uzytkownika
void menu(){
	//tablica do wczytania opcji
	char choice[100];
	while(TRUE){
		printf_correct("---------------------------");
		printf_correct("|1.Konwertuj na szesnastkowy|");
		printf_correct("|2.Konwertuj na osemkowy    |");
		printf_correct("|3.Wyjscie                  |");
		printf_correct("---------------------------");
		//okreslamy rozmiar bufora tak zeby nie przepelnic tablicy
		scanf("%99s",choice);
		//wywolujemy funkcje wraz z wyborem uzykownika
		program_system(choice);
		
	}
}
//main z ktorej wywolujemy menu
int main()
{
	menu();
   return 0;
}
