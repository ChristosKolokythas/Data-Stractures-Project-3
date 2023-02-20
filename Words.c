#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Words.h"
#include "typos_stoixeiouDDA.h"


typosWords dhmiourgia_Words()
{
   typosWords WordsNew=malloc(sizeof(RecWords));
   int x;
#if (Simple)
   printf("use simple BST\n");
   Tree_dimiourgia(&(WordsNew->WordsRiza));
#else   
    printf("use AVL BST\n");
    AVLTree_dimiourgia(&(WordsNew->WordsRiza));
#endif	

	WordsNew->wordCounter=0;
	WordsNew->wordsFound=WordsNew->wordsNotFound=0;
	for (x = 0; x < 100000; x++)
	{
		WordsNew->SearchFrequencies[x] = 0;
	}
	for (x = 0; x < 10; x++)
	{
		WordsNew->InsertTime[x] = 0;
	}
   return WordsNew;         
}

void katastrofh_Words(typosWords * Wordsptr)
{
#if (Simple)
   Tree_katastrofi(&(*Wordsptr)->WordsRiza);
#else
   AVLTree_katastrofi(&(*Wordsptr)->WordsRiza);
#endif
   free(*Wordsptr);
   *Wordsptr=NULL;
}

void InsertWord(typosWords Words, char * w)
{
	/* Input w
		sets stoixeio DDA (kai ta 2 melh) word + index (wordCounter)
		calls eisagogi_komvou sto DDA 
		sets SearchFrequency[wordCounter]=0;
		wordCounter++;
	*/
	int ypsilotero=0,error = 0;
	
	TStoixeiouDDA temp;
	temp.word = malloc(strlen(w) + 1);
	strcpy(temp.word,w);
	temp.index = Words->wordCounter;

#if (Simple)
	Tree_eisagogi(&Words->WordsRiza,temp,&error);
#else   
	AVLTree_eisagogi(&Words->WordsRiza, temp, &ypsilotero, &error);
#endif	
	if (error != 1)
		Words->wordCounter++;
	else
	{
		printf("h leksh yparxei %s %d \n",w,Words->wordCounter);
		
	}
	free(temp.word);
}

void CheckWord(typosWords Words, char * w)
{
	/* Input w
		sets w se neo stoixeio DDA
		calls anazitisi_komvou and
		if found 
			calls periexomena and increases frequency in array SearchFrequencies[index]
	*/
	TStoixeiouDDA temp;
	typos_deikti deiktis;
	int found = 0;

	temp.word = malloc(strlen(w) + 1);
	strcpy(temp.word, w);

#if (Simple)
	Tree_anazitisi(Words->WordsRiza, temp, &deiktis, &found);
	if (found) {
		TStoixeiouDDA temp2;
		Tree_periexomeno(deiktis, &temp2);
		Words->wordsFound++;
		Words->SearchFrequencies[temp2.index]+=1;
		}
	else
		Words->wordsNotFound++;
#else   
	AVLTree_anazitisi(Words->WordsRiza, temp, &deiktis, &found);
	if (found) {
		TStoixeiouDDA temp2;
		AVLTree_periexomeno(deiktis, &temp2);
		Words->wordsFound++;
		Words->SearchFrequencies[temp2.index]++;
	}
	else
		Words->wordsNotFound++;
#endif	

	free(temp.word);
}

void anadromh(FILE *out, typos_deikti deiktis, typosWords Words)
{

#if (Simple)
	typos_deikti arpaidi = Tree_apaidi(deiktis), deksipaidi = Tree_dpaidi(deiktis);

	if (arpaidi != NULL)
		anadromh(out, arpaidi, Words);

		TStoixeiouDDA temp;
		Tree_periexomeno(deiktis, &temp);
		if (Words->SearchFrequencies[temp.index] >= 1)
			TSDDA_writeValue(out, temp);
	if (deksipaidi != NULL)
		anadromh(out, deksipaidi, Words);

		Tree_periexomeno(deiktis, &temp);
		if (Words->SearchFrequencies[temp.index] >= 1)
		{
			//printf("test\n");
			TSDDA_writeValue(out, temp);
		}
	
#else   
	typos_deikti arpaidi = AVLTree_apaidi(deiktis), deksipaidi = AVLTree_dpaidi(deiktis);

	if (arpaidi != NULL)
	{
		anadromh(out, arpaidi, Words);
		TStoixeiouDDA temp;
		AVLTree_periexomeno(deiktis, &temp);
		if (Words->SearchFrequencies[temp.index] >= 1)
			TSDDA_writeValue(out, temp);
	}
	if (deksipaidi != NULL)
	{
		anadromh(out, deksipaidi, Words);
		TStoixeiouDDA temp;
		AVLTree_periexomeno(deiktis, &temp);
		if (Words->SearchFrequencies[temp.index] >= 1)
			TSDDA_writeValue(out, temp);
	}
#endif	
}

void ShowCommonWords(FILE *out, typosWords Words)
{
	/* diadromh DDA kai emfanish  if frequenxy >= 1 */
	anadromh(out, Words->WordsRiza, Words);
}

/* praxeis poy diaxeirizontai toys xronoys */

void SetInsertTime(typosWords Words, float time, int position)
{
	/* Input time, position
		sets Words.InsertTime[position]=time;
	*/
	Words->InsertTime[position] = time;
}

void SetCheckTime(typosWords Words, float time){
	/* Sets Serach Times */
	Words->CheckTime = time;
}

void SetDiadromhTime(typosWords Words, float time)
{	
	/* Input time
		sets Words.DiadromhTime=time;
	*/
	Words->DiadromhTime = time;
}

void PrintData(FILE *out, typosWords Words)
{
	/* emfanizei InsertTimes, DiadromhTime and Counters*/
	fprintf(out,"Lekseis           : %d \n", Words->wordCounter);
	fprintf(out,"Lekseisfound      : %d \n", Words->wordsFound);
	fprintf(out,"Lekseisntofound   : %d \n", Words->wordsNotFound);
	fprintf(out,"Xronos anazhthshs : %lf \n", Words->CheckTime);
	fprintf(out,"Xronos diadromis  :%lf \n", Words->DiadromhTime);
	int x;
	for(x=0;x<10;x++)
		fprintf(out,"Xronos eisagwghs :%lf \n", Words->InsertTime[x]);

}



