#include <iostream>
#include <stdio.h>

typedef struct Ochered
{
	Ochered *Next;
	int Info;
}Ochered;

Ochered* Add ( Ochered* First, int Kol_vo )
{
	Ochered* TMP, *TMP1;
	TMP = new Ochered;
	Kol_vo++;
	printf( "%d: ", Kol_vo );
	scanf( "%d", &TMP->Info );
	TMP1 = First;
	TMP->Next = TMP1;
	First = TMP;
	return First;
}
Ochered* Dell ( Ochered* First, int Kol_vo )
{
	Ochered* TMP;
	if( Kol_vo > 1 )
	{
		for( TMP = First; TMP->Next->Next; TMP = TMP->Next );
		delete[] TMP->Next;
		TMP->Next = 0;
	}
	else
	{
		delete[] First;
		First = 0;
	}
	return First;
}
void Read_Last ( Ochered* First )
{
	//Ochered* TMP;
	//for( TMP = First; TMP->Next; TMP = TMP->Next );
	printf( "Last element: %d", First->Info );
}
void Read_All ( Ochered* First )
{
	Ochered* TMP;
	int i = 1;
	for( TMP = First; TMP->Next; TMP = TMP->Next )
	{
		printf( "%d: %d\n", i, TMP->Info );
		i++;
	}
	printf( "%d: %d\n", i, TMP->Info );
}
void main()
{
	int N, i, Kol_vo = 0;
	Ochered* First, *TMP, *TMP1;
	printf( "Input N: " );
	scanf( "%d", &N );
	First = new Ochered;
	First->Next = 0;
	printf( "1: " );
	scanf( "%d", &First->Info );
	Kol_vo++;
	for( i = 1; i < N; i++ )
	{
		TMP = new Ochered;
		printf( "%d: ", i + 1 );
		scanf( "%d", &TMP->Info );
		TMP1 = First;
		TMP->Next = TMP1;
		First = TMP;
		Kol_vo++;
	}
	printf( "\n" );
	First = Add( First, Kol_vo );
	Kol_vo++;
	printf( "\n" );
	First = Dell( First, Kol_vo );
	Kol_vo--;
	printf( "\n" );
	Read_Last ( First );
	printf( "\n" );
	Read_All ( First );
	system( "pause" );
}