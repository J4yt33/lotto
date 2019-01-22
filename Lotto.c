/*
 ============================================================================
 Name        : Lotto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Funktionsname: Eingabe
// Die FUnktion liest vom benutzer werte für n und k ein
// Eingabeparameter mit zulässigem Wertebereich: übergeben werden keine parameter, allerdings werden daten für n und k eingelesen 0<k<n<90
// Rückgabeparameter mit zulässigem Wertebereich: int *
// Autor: Jan Taschbach
// Version: 1.1
// Datum der letzten Änderung: 22.1.2019
int * Eingabe(){
	//variablen deklaration
	// platz für n und k
	int KundN[2];
	//rückgabewert auf die eingegebenen zahlen ist ein pointer
	int * PointerAufNundK;
	PointerAufNundK=&KundN[0];
	//pointer auf die eingabewerte um eindeutige namen zu haben und nicht kundn[0] bzw kundn[1]
	int *k=&KundN[0];
	int *n=&KundN[1];
	//marker zur überprüfung der Eingabe
	int EingabeKorrekt=0;

	//einlesen der daten von n und k und überprüfung der eingabe aus korrektheit
	do{
		//eingabe aufforderung
		printf("Bitte geben sie 0<k<n<90 ein\n\n");
		printf("Bitte geben sie k ein\n:");
		scanf("%i",&KundN[0]);
		printf("Bitte geben sie n <= 90 ein\n:");
		scanf("%i",&KundN[1]);

		//pruefen auf korrekte eingabe
		// 0<k<n<=90
		if((0<*k)&&(*k<*n)&&(*n<=90)){

			printf("n=%i",*n);
			printf("k=%i",*k);
			EingabeKorrekt=1;
		}else{
			printf("Falsche Eingabe\n\n\t    !\n\t0<k<n<=90\n\n------------------------------\n\n\n");

			EingabeKorrekt=0;
		}
	}while(EingabeKorrekt==0);

	//rückgabe der adresse der daten
	return PointerAufNundK;
}

// Funktionsname: Sortiere
// die funktion sortiert die werte in den spalten
// Eingabeparameter mit zulässigem Wertebereich: die funktion bekommt das array mit usertipps und gewinnzahlen übergeben
// Rückgabeparameter mit zulässigem Wertebereich: -
// Autor: Jan Taschbach
// Version: 1.1
// Datum der letzten Änderung: 21.1.2019
void  sortiere(int Array[92][3]){
	//markeriert ob die spalte sortiert ist
	int i,Sort=0;
	//zwischenspeicher für den tausch der variablen
	int Swap=0;
	//anzahl der tipps
	int k=Array[0][0];


	//wenn die naechste zahl groeßer ist wie die aktuelle tausche die beiden und setze einen marker fuer einen neuen durchlauf
	//1.spalte(zufallszahlen)

	do{
		Sort=1;
		for(i=1;i<k;i++){
			if(Array[i][0]>Array[i+1][0]){
				Swap=Array[i+1][0];
				Array[i+1][0]=Array[i][0];
				Array[i][0]=Swap;
				Sort=0;
				break;
			}
		}
	}while(Sort==0);

	//2.spalte(tippzahlen)
	do{
		Sort=1;
		for(i=1;i<k;i++){
			if((Array[i][1])>(Array[i+1][1])){
				Swap=(Array[i+1][1]);
				Array[i+1][1]=Array[i][1];
				Array[i][1]=Swap;
				Sort=0;
				break;
			}
		}
	}while(Sort==0);
}

// Funktionsname: Zufall
// Die funktion tippt mit hilfe der rand() funktion verschiedene zahlen und fügt diese in die nullte spalte des arrays ein
// Eingabeparameter mit zulässigem Wertebereich: die funktion bekommt das array übergeben, die zahlen müssen ungleich 0 und alle verschieden sein wobei die obere grenze n ist
// Rückgabeparameter mit zulässigem Wertebereich: -
// Autor: Jan Taschbach
// Version: 1.1
// Datum der letzten Änderung: 21.1.2019
void Zufall(int array[92][3]){

	//Zufallsgenerator
	//Ziehen ohne zurücklegen 	k ist die Anzahl der Ziehungen
	//							n ist die Obere Schranke des Pools aus Ganzen Zahlen, die untere Grenze ist 1
	//deklaration der variablen
	//zählvariablen
	int j,i;
	//marker um sicherzustellen dass nur von 0 verschiedene zahlen getippt werden
	int doppeltOderNull=0;
	//eindeutige namen für k und n
	int k=array[0][0];								//k
	int n=array[0][1];								//n
	//nötig für die zufallsfunktion
	time_t t;
	srand((unsigned) time(&t));

	//tippe erste zahl
	//erste zahl !=0
	do{
		array[1][0]=rand()%n;
	}while(array[1][0]==0);

	//gib allen weiteren einen verschiedenen wert zwischen 1 und n
	for(i=2;i<k+1;i++){
		do{
			doppeltOderNull=0;
			array[i][0]=rand()%n;
			for(j=1;j<i;j++){
				if((array[i][0]==array[j][0])|| (array[i][0]==0)){
					doppeltOderNull=1;
					array[i][0]=rand()%n;
					break;
				}
			}}while(doppeltOderNull==1);
	}
}


// Funktionsname: Bin
// Kurzbeschreibung der Aufgabe der Funktion
// Eingabeparameter mit zulässigem Wertebereich: ...
// Rückgabeparameter mit zulässigem Wertebereich: ...
// Autor: ...
// Version: ...
// Datum der letzten Änderung: ...
long int Bin ( int n, int k){
	//zählvarieble
	long int i;
	//binomialkoeffizient
	long int binomialkoeffizient = 1;

	//berechne binomialkoeffizient
	for (i = 1; i <= k; i++)
		binomialkoeffizient = binomialkoeffizient * (n - i + 1) / i;
	//rückgabe des wertes
	return (binomialkoeffizient);
}


// Funktionsname: Tipp
// Einlesen der Tippzahlen in die Zeilen der zweite Spalte des Arrays, beginnend mit der 1. zeile
// Eingabeparameter mit zulässigem Wertebereich: int array[92][3], die benutzereingabe darf k tipps beinhalten die zwischen 1 und 90 liegen dürfen
// Rückgabeparameter mit zulässigem Wertebereich: -
// Autor: Jan Taschbach
// Version: 1.1
// Datum der letzten Änderung: 22.1.2019
void  Tipp(int array[92][3]){
	//uebernehme k aus den übergebenen Daten
	int k=array[0][0];
	//aktuelle Tippnummer
	int TippNummer;
	//zählvariablen
	int j;
	//pruefe auf korrekte Eingabe
	int ungueltigeEingabe=0;

	//eingabeauforderung
	printf("Bitte geben sie ihre Tippzahlen ein\n\n");

	//erste zahl
	do{
		printf("Bitte geben sie einen Tipp ein\n:");
		//lese ersten Tipp in array
		scanf("%i",&array[1][1]);
		//pruefen auf korrekte Eingabe
		if(array[1][1]==0||array[1][1]>90||array[1][1]<1)printf("ungueltige Eingabe");
	}while(array[1][1]==0||array[1][1]>90||array[1][1]<1);

	//gib allen einen verschiedenen wert zwischen 1 und 90
	for(TippNummer=2;TippNummer<k+1;TippNummer++){
		do{
			ungueltigeEingabe=0;
			printf("Bitte geben sie einen Tipp ein\n:");

			scanf("%i",&array[TippNummer][1]);
			for(j=1;j<TippNummer;j++){
				if((array[TippNummer][1]==array[j][1])|| (array[TippNummer][1]==0) || (array[TippNummer][1]<1) || (array[TippNummer][1]>90)){
					ungueltigeEingabe=1;
					printf("ungueltige Eingabe");
					break;
				}
			}}while(ungueltigeEingabe==1);
	}
}

// Funktionsname: Vergleiche
// die Funktion überprüft die tipps des users mit denen der rand() fkt, zählt die richtigen und speicher die gewinnzahlen
// Eingabeparameter mit zulässigem Wertebereich: die funktion bekommt das array übergeben
// Rückgabeparameter mit zulässigem Wertebereich: anzahl der richtigen, int AnzahlRichtige
// Autor: Jan Taschbach
// Version: 1.1
// Datum der letzten Änderung: 21.1.2019

int vergleiche(int array[92][3]){
//zählvariablen
	int i,j;
	//zähle die richtigen
	int AnzahlRichtige=0;
	//k liest sich besser
	int k=array[0][0];
	//vergleiche die tipps und speichere die richtigen tippzahlen in der 2. spalte des arrays
	for(i=1;i<k+1;i++){
		for(j=0;j<k+1;j++){
			if (array[i][0]==array[j][1]){
				//speicherung der gewinnzahlen
				array[AnzahlRichtige][2]=array[i][1];
				//zähle die richtigen tipps
				AnzahlRichtige++;
				break;
			}
		}
	}
	//rückgabe der anzahl der richtigen
	return AnzahlRichtige;
}


// Funktionsname: main
// Die Funktion erstellt das Array zur Speicherung der Benutzertipps in der 1. Spalte und der gewinnzahlen in der 0. spalte, in die 0.zeile werden n und k eingelesen
//außerdem werden von hier die funktionen zur Eingabe des tipps, der erstellung der gewinnzahlen und der sortierung der zahlen aufgerufen
// Eingabeparameter mit zulässigem Wertebereich: -
// Rückgabeparameter mit zulässigem Wertebereich: -
// Autor: Jan Taschbach
// Version: 1.1
// Datum der letzten Änderung: 21.1.2019

void main() {

	//zählvariable um mindestens 3 richtige zu bestimmen
	int countuntil3=1;
	//zählvariable
	int i;
	//eingabe
	// rufe funktion zur eingabe von n und k auf und erstelle pointer auf die eingabewerte									1x2		 n, k
	int * nuk=Eingabe();
	//matrix erstellen zur speicherung der werte n,AnzahlTipps,gewinnzahlen,usertipps,zahlendieübereinstimmen
	int array[92][3];
	//binomialkoeffizient
	long BinomialKoeffizient;
	//anzahl tipps
	int AnzahlTipps=array[0][0];
	//Anzahl der richtigen Tipps
	int AnzahlRichtige;
	//n und AnzahlTipps an das array uebergeben
	array[0][0]=*nuk;
	array[0][1]=*(nuk+1);

	//AnzahlTipps liest sich besser =k
	AnzahlTipps=array[0][0];

	//tipp abgeben in 2. spalte
	Tipp(array);

	//zufallswerte in 1. spalte
	Zufall(array);

	//sortiere die eingaben
	sortiere(array);

	//berechne binomialkoeffizient
	BinomialKoeffizient=Bin(array[0][1],array[0][0]);

	//ausgabe des Binomialkoeffizienten
	printf("\nBinomialkoeffizient:= Anzahl der Moeglichen Ziehungsergebnisse %li\n",BinomialKoeffizient);

	//vergleiche tipps mit gewinnzahlen
	AnzahlRichtige=vergleiche(array);

	//tippe weiter bis 3 matches
	while(AnzahlRichtige<3){
		countuntil3++;
		Zufall(array);
		sortiere(array);
		AnzahlRichtige=vergleiche(array);
	}
	//ausgabe der anzahl ziehungen bis min. 3 richtige
	printf("Die Anzahl der Ziehungen bis min. 3 richtige ist %i\n",countuntil3);
	//ausgabe der gewinnzahlen
	printf("Die Anzahl ihrer Gewinnzahlen ist %i",AnzahlRichtige);

	//ausgabe ihres tipps
	printf("\nIhr Tipp:\t ");
	for(i=1;i<AnzahlTipps+1;i++){
		printf("%i,",array[i][1]);
	}

	//ausgabe der gewinnzahlen
	printf("\nDie Gewinnzahlen:");
	for(i=1;i<AnzahlTipps+1;i++){
		printf("%i,",array[i][0]);
	}

	//ausgabe der zahlen die richtig sind
	printf("\nFolgende Zahlen haben gewonnen:");
	for(i=0;i<AnzahlRichtige;i++){
		printf("%i,",array[i][2]);
	}
}

