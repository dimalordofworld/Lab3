#include <iostream>
#include <stdio.h>

typedef struct Stek
{
	Stek *Next;
	int Info;
}Stek;

void Read_Top( Stek* Top )
{
	printf( "Last: %d\n", Top->Info );
}

Stek* Dell( Stek* Top )
{
	Stek *TMP;
	TMP = Top;
	Top = Top->Next;
	delete[] TMP;
	return Top;
}

Stek* Add( Stek* Top, int Kol_vo )
{
	Stek *TMP, *TMP1;
	Kol_vo++;
	printf( "%d: ", Kol_vo );
	TMP = new Stek;
	scanf( "%d", &TMP->Info );
	TMP1 = Top;
	TMP->Next = TMP1;
	Top = TMP;
	return Top;
}

void main()
{
	int N, i;
	int Kol_vo = 0;
	Stek *Top = 0, *TMP, *TMP1;
	printf( "Input N: " );
	scanf( "%d", &N );
	Top = new Stek;
	printf( "1: " );
	scanf( "%d", &Top->Info );
	Kol_vo++;
	for( i = 1; i < N; i++ )
	{
		TMP = new Stek;
		printf( "%d: ", i + 1 );
		scanf( "%d", &TMP->Info );
		TMP1 = Top;
		TMP->Next = TMP1;
		Top = TMP;
		Kol_vo++;
	}
	printf( "\n" );
	Top = Add( Top, Kol_vo );
	Kol_vo++;
	printf( "\n" );
	Top = Dell( Top );
	Kol_vo--;
	printf( "\n" );
	Read_Top( Top );
	system( "pause" );
}