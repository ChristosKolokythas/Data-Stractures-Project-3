/************************************************************************
Header File         : Words.h
Syggrafeas			: Y. Cotronis
Skopos       		: diepafh synarthsevn typou words
*************************************************************************/
#ifndef __TYPOS_WORDS__ 
#define __TYPOS_WORDS__

/*orismos typou Words */
typedef struct RecWords * typosWords; 

#define Simple 1 /* 0 for AVL and 1 for Simple BST */
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres -
mporeite na xrhsimopoihsete thn  domh
#if ... #else ...#endif
gia na diaforopihsete tis dyo ylopoihseis
Akolou9oyn paradeignata xrhshs
*/

#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif

typedef struct RecWords
{
	typos_deikti WordsRiza; 		/* to Words apoteleitai apo to DDA */
	int SearchFrequencies[100000]; /* array of times each word is found */
	int wordCounter;				/* counts current number of words in DDA*/
	int wordsFound;				/* counter of words found in DDA */
	int wordsNotFound;				/* counter of words not found in DDA */
	double InsertTime[10];   		/* xronoi eisagvghs ana 1024, 2048,...*/
	double CheckTime;         		/* xronos anazhthshs */
	double DiadromhTime;	  		/* xronos diadromhs */
}RecWords;

/* epikefalides praxewn */

/* praxeis poy yloioyntai me praxeis DDA */
typosWords dhmiourgia_Words();
void katastrofh_Words(typosWords * Wordsptr);

void InsertWord(typosWords Words, char * w);
void CheckWord(typosWords Words, char * w);
void ShowCommonWords(FILE *out, typosWords Words);

/* praxeis poy diaxeirizontai toys xronoys */
void SetInsertTime(typosWords Words, float time, int position);
void SetCheckTime(typosWords Words, float time);
void SetDiadromhTime(typosWords Words, float time);

void PrintData(FILE *out, typosWords Words);
#endif

