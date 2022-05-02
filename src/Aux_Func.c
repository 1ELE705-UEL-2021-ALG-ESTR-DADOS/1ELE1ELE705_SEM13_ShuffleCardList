#include "Aux_Func.h"

extern const char Path[];

extern const char* face[];
extern const char* suit[];

size_t ReadFileOfOneFr52Deck(ListCardNodePtr* sPtr) {
	FILE* cfPtr;
	int i = 0;
	ListCardNodePtr newPtr, currentPtr;
	char myPath[100];

	// Abre o arquivo com as cartas do baralho ordenadas
	sprintf(myPath, "%s%s", Path, "Fr52Deck.dat");
	if ((cfPtr = fopen(myPath, "rb")) == NULL) {
		return 1;
	}

	// Insere o primeiro n�-carta
	newPtr = malloc(sizeof(ListCardNode));
	if (newPtr == NULL) return 2;
	// L� o conte�do do n�-carta do arquivo e 
	// coloca no primeiro n�-carta
	if (feof(cfPtr)) return 3;
	fread(newPtr, sizeof(ListCardNode), 1, cfPtr);
	// Refaz os ponteiros internos dos n�s para a posi��o
	// atual das strings de face e naipe 
	newPtr->card.face = face[newPtr->card.face_number - 1];
	newPtr->card.suit = suit[newPtr->card.suit_number - 1];
	// Refaz os ponteiros do n� e da lista
	newPtr->nextPtr = NULL;
	currentPtr = newPtr;
	*sPtr = newPtr;
	i++;

	// Insere os n�s-carta restantes
	for (; i < 52; i++) {
		newPtr = malloc(sizeof(ListCardNode));
		if (newPtr == NULL) return 2;
		if (feof(cfPtr)) return 3;
		fread(newPtr, sizeof(ListCardNode), 1, cfPtr);
		newPtr->card.face = face[newPtr->card.face_number - 1];
		newPtr->card.suit = suit[newPtr->card.suit_number - 1];
		currentPtr->nextPtr = newPtr;
		currentPtr = newPtr;
	}
	fclose(cfPtr); // Fecha o arquivo
	return 0;
}

