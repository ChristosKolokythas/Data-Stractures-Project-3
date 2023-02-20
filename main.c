/************************************************************************
Programma pelaths	: main.c
Syggrafeas			: 
Skopos				: skeleton main for askhsh 3
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "typos_stoixeiouDDA.h"
#include "Words.h"
#include <string.h>
#include <sys/time.h>                /* for gettimeofday() */
#include <math.h>


void InitialiseTree(FILE *wordlist, typosWords W);
void SearchUpdateTree(FILE *wordlist, typosWords W);
void Results(FILE *out, typosWords W);


int main(int argc, char *argv[])
{ 	typosWords A;
FILE *WordList = NULL, *Text, *Output ;
   int x;

   Text = fopen("RomeoAndJuliet.txt", "r");

   printf("\nPress 1 to open wordsbyABC\n");
   printf("Press 2 to open wordsbyFrequency\n");
   printf("Press 3 to open wordsbyRandom\n");
   scanf("%d", &x);

   if (x == 1)
	   WordList = fopen("wordsByABC.txt", "r");
   else if (x == 2)
	   WordList = fopen("wordsByFrequency.txt", "r");
   else if (x == 3)
	   WordList = fopen("wordsByRandom.txt", "r");

   Output = fopen("Apotelesmata.txt","w");
/* need to add appropriate calls to open and close files */

  	A=dhmiourgia_Words();
  	InitialiseTree(WordList, A);
	SearchUpdateTree(Text, A);
	Results(Output, A);
	katastrofh_Words(&A);

	fclose(WordList);
	fclose(Output);
	fclose(Text);

	system("pause");
  getchar();	
}

void InitialiseTree(FILE *wordlist, typosWords W)
{
	struct timeval t1, t2;
	double elapsedTime;
	int i=0;

	/* start timer */
	gettimeofday(&t1, NULL);
	TStoixeiouDDA Elem;
	while (1) {
		if (feof(wordlist))
			break;
		else{
			TSDDA_readValue(wordlist, &Elem);
			InsertWord(W, Elem.word);
			free(Elem.word);
		}

		if (W->wordCounter == (pow(2, 10 + i)))
		{
			//printf("%d \n",W->SearchFrequencies[x]);
			gettimeofday(&t2, NULL);

			/* compute and print the elapsed time in millisec */
			elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
			elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
			printf("elapsedTime=%g msec\n", elapsedTime);
			SetInsertTime(W, elapsedTime, i);
			i = i + 1;
		}

	  } 
	//int x;
	//for (x = 0; x = 100000; x++)


	printf("\ntelos 1hs\n");
	/* Reads words from wordlist and inserts into DDA using InsertWord
		after 1024, 2048, 4096,... words sets array times using SetInsertTime 
	*/
}

void SearchUpdateTree(FILE *wordlist, typosWords W)
{
	/* Reads words from wordlist and calls CheckWord 
	   updates times using SetCheck Time
	*/ 

	while(!feof(wordlist)){

		TStoixeiouDDA Elem;
		TSDDA_readValue(wordlist, &Elem);
		struct timeval t1, t2;
		double elapsedTime;

		/* start timer */
		gettimeofday(&t1, NULL);

		CheckWord(W, Elem.word);

		/* stop timer */
		gettimeofday(&t2, NULL);

		/* compute and print the elapsed time in millisec */
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
		printf("elapsedTime=%g msec\n", elapsedTime);
		
	}
	printf("\n2hs\n");
}

void Results(FILE *out, typosWords W)
{/* calls ShowCommonWords, updates time diadromh using SetDiadromhTime and Prints times and Counters*/
	struct timeval t1, t2;
	double elapsedTime;

	/* start timer */
	gettimeofday(&t1, NULL);

	ShowCommonWords(out, W);

	gettimeofday(&t2, NULL);

	/* compute and print the elapsed time in millisec */
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	printf("elapsedTime=%g msec\n", elapsedTime);

	SetDiadromhTime(W, elapsedTime);
	
	PrintData(out, W);
	printf("teeeeeest\n");
}
