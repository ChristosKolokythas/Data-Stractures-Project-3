/************************************************************************
Implementation File	: TStoixeiouDDA.c
Syggrafeas			: Y. Cotronis
Skopos				: Ylopoihsh synarthsevn typou stoixeiou
*************************************************************************/
#include "typos_stoixeiouDDA.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int TSDDA_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
	if (strcmp(s1.word, s2.word))
		return 1; /* synthikh word part == */
	else
		return 0;

}

int TSDDA_mikrotero(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
	if (strcmp(s1.word, s2.word)>0)
		return 1; /* synthikh word part == */
	else
		return 0;	
}

int TSDDA_megalytero(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
	if (strcmp(s1.word, s2.word)<0)
		return 1; /* synthikh word part == */
	else
		return 0;
}

void TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source)
{
	target->index = source.index;
	target->word = malloc(strlen(source.word) + 1);
	strcpy(target->word, source.word);
}
 
int TSDDA_readValue (FILE *from, TStoixeiouDDA * Elem)
{
	char temp[75];
	fscanf(from, "%s", temp);
	Elem->word = malloc(strlen(temp) + 1);
	strcpy(Elem->word, temp);
	return 1;
}
 
int TSDDA_writeValue(FILE *to,TStoixeiouDDA Elem)
{
	fprintf(to,"%s \n", Elem.word);
	return 1;
}
