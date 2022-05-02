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

// Mude a string com o caminho (PATH) do diretório do seu projeto.
// Use duas contrabarras para separar os diretórios.
const char Path[] = { "C:\\Repos\\1ELE705_22\\1ELE705_SEM12_Gen52Card_Test\\" };


void shuffle(ListCardNodePtr* sPtr) {
	// Encontra o tamanho TAM da lista ligada de cartas apontada por sPtr
	// Varre a lista com i indo de 0 a TAM-1 e i sendo a posição atual na lista
	// Para cada posição i:
	//		Sorteia uma posição j entre 0 e TAM-1
	//		Troca o nó referente à posição j com o nó referente à posição i.
	// OBS: Note que a lista é ligada, ou seja, as posições i e j são somente artifícios abstratos.

}


void createOneFr52Deck(ListCardNodePtr* sPtr) {

}



// Este projeto possui a estrutura básica para a implementação das funções 
// para o gerenciamento de cartas de baralho, que podem ser utilizadas 
// para a construção de um jogo.
// 
// A função a ser construída é: shuffle.
//
// Utilize a função createOneFr52Deck criada no assignment anterior
//
//
// A função shuffle embaralha uma dada lista dinâmica de cartas.
// Um possível algoritmo para a função shuffle segue na forma de comentários
// no corpo da função.