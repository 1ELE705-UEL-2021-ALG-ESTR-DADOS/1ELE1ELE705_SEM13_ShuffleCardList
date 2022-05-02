#include <stddef.h>
#include "main.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include "Aux_Func.h"

// Legacy global variables
// if used elsewere it MUST be defined as extern
const char polar[] = { "polar" };
const char cartesian[] = { "cartesian" };

// Global variables
// if used elsewere it MUST be defined as extern

const char* face[] = {	"Ace", "Deuce", "Three", "Four", "Five", 
						"Six", "Seven", "Eight", "Nine", "Ten",
						"Jack", "Queen", "King"	};

const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

// Mude a string com o caminho (PATH) do diret�rio do seu projeto.
// Use duas contrabarras para separar os diret�rios.
const char Path[] = { "C:\\Repos\\1ELE705_22\\1ELE705_SEM12_Gen52Card_Test\\" };


void shuffle(ListCardNodePtr* sPtr) {
	// Encontra o tamanho TAM da lista ligada de cartas apontada por sPtr
	// Varre a lista com i indo de 0 a TAM-1 e i sendo a posi��o atual na lista
	// Para cada posi��o i:
	//		Sorteia uma posi��o j entre 0 e TAM-1
	//		Troca o n� referente � posi��o j com o n� referente � posi��o i.
	// OBS: Note que a lista � ligada, ou seja, as posi��es i e j s�o somente artif�cios abstratos.

}


void createOneFr52Deck(ListCardNodePtr* sPtr) {

}



// Este projeto possui a estrutura b�sica para a implementa��o das fun��es 
// para o gerenciamento de cartas de baralho, que podem ser utilizadas 
// para a constru��o de um jogo.
// 
// A fun��o a ser constru�da �: shuffle.
//
// Utilize a fun��o createOneFr52Deck criada no assignment anterior
//
//
// A fun��o shuffle embaralha uma dada lista din�mica de cartas.
// Um poss�vel algoritmo para a fun��o shuffle segue na forma de coment�rios
// no corpo da fun��o.