#include <iostream>
#include <stdio.h>

typedef struct List
{
	List *Next;
	int Info;
}List;
void Print( List *First )
{
	List *Spisok;
	int i;
	if( Spisok )
	{
		for( Spisok = First, i = 1; Spisok->Next; i++ )
		{
			printf( "%d: %d\n", i, Spisok->Info );
			Spisok = Spisok->Next;
		}
		printf( "%d: %d\n", i, Spisok->Info );
	}
	else
	{
		printf( "Empty!\n");
	}
}
void Del( List **First, int Kol_vo )
{
	int Del_Number;
	List *Spisok = First[ 0 ], *TMP, *TMP1;
	printf( "Input deletion element: " );
	scanf( "%d", &Del_Number );
	if( Kol_vo == 1 )
	{
		delete[]Spisok;
		Spisok = 0;
	}
	else
	{
		if( Del_Number == 1 )
		{
			TMP = Spisok;
			Spisok = TMP->Next;
			delete[] TMP;
		}
		else if ( Del_Number == Kol_vo )
		{
			for( TMP = Spisok; TMP->Next->Next; TMP = TMP->Next );
			delete[]TMP->Next;
			TMP->Next = 0;
		}
		else
		{
			TMP = Spisok;
			for( int i = 1; i < Del_Number - 1; i++ )
			{
				TMP = TMP->Next;
			}
			TMP1 = TMP->Next->Next;
			delete[] TMP->Next;
			TMP->Next = TMP1;
		}
	}
	First[ 0 ] = Spisok;
}
void main()
{
	int Kol_vo, i;
	List *Spisok, *TMP;
	printf( "Input kol_vo: " );
	scanf( "%d", &Kol_vo );
	Spisok = new List;
	printf( "1: " );
	scanf( "%d", &Spisok->Info  );
	TMP = Spisok;
	TMP->Next = 0;
	for( i = 1; i < Kol_vo; i++ )
	{
		TMP->Next = new List;
		TMP = TMP->Next;
		printf( "%d: ", i + 1 );
		scanf( "%d", &TMP->Info );
		TMP->Next = 0;
	}
	//Print	( Spisok );
	printf( "\n" );
	Del		( &Spisok, Kol_vo );
	printf( "\n" );
	Print	( Spisok );
	system( "pause" );
}