#include "gtest/gtest.h"
#include <cstring>
#include "aux_functions.h"
#define _USE_MATH_DEFINES
#include "math.h"

extern "C"
{
    #include <time.h>
    #include <stdlib.h>
    #include "../src/Aux_Func.h"
}


TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);

    // Inicializações do Projeto

    // Randomiza, eventualmente.
    srand((unsigned int) time(NULL));
}

// Test createOneFr52Deck

// Testa se a função createOneFr52Deck gera uma lista ligada com 
// as 52 cartas do baralho de forma ordenada.
// Lê um arquivo binário com a sequencia correta, converte para 
// lista ligada (ReadFileOfOneFr52Deck) e compara com a lista
// gerada pela função sob teste
TEST(TestcreateOneFr52Deck, TestMatchFr52Deck) {
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr actualDeck = NULL;

    createOneFr52Deck(&actualDeck);
    ReadFileOfOneFr52Deck(&expectedDeck);
    ASSERT_TRUE(ListMatch(actualDeck, expectedDeck));
}



TEST(TestShuffle52CardDeck, TestDeckHas52Cards) {
    ListCardNodePtr actualDeck = NULL;
    ListCardNodePtr proxCardPtr = NULL;
    int expectedNumberOfCards = 52;
    int actualNumberOfCards;

    createOneFr52Deck(&actualDeck);
    shuffle(&actualDeck);

    for (actualNumberOfCards = 0, proxCardPtr = actualDeck;
        actualNumberOfCards < 52 && proxCardPtr != NULL;
        actualNumberOfCards++, proxCardPtr = proxCardPtr->nextPtr);

    EXPECT_EQ(actualNumberOfCards, expectedNumberOfCards);
}

TEST(TestShuffle52CardDeck, TestDeckHasRepeatedCards) {
    // cria o histograma para verificar se todas as cartas estão presentes 
    // ou se há cartas repetidas
    int histogram[53] = { 0 }, i;
    int expectedHistogram[53] = { 0 };

    // preenche o expectedHistogram com os valores esperados
    for (i = 1; i <= 52; i++) {
        expectedHistogram[i] = 1;
    }

    ListCardNodePtr actualDeck = NULL;
    ListCardNodePtr proxCardPtr = NULL;

    createOneFr52Deck(&actualDeck);
    shuffle(&actualDeck);

    // Preenche o histograma
    // (a posição zero do vetor histograma é desprezada)
    for (proxCardPtr = actualDeck; proxCardPtr != NULL; proxCardPtr = proxCardPtr->nextPtr) {
        i = (proxCardPtr->card.suit_number - 1) * 13 + proxCardPtr->card.face_number;
        histogram[i]++;
    }

    ASSERT_TRUE(ArraysMatch(histogram, expectedHistogram));
}

TEST(TestShuffle52CardDeck, testDeckHasNotA_ThreeCardSequence) {
    ListCardNodePtr actualDeck = NULL;
    ListCardNodePtr atualCardPtr = NULL, anteriorCardPtr = NULL, anteriorDoAnteriorCardPtr = NULL;

    createOneFr52Deck(&actualDeck);
    shuffle(&actualDeck);

    int histogram[14] = { 0 };
    int i;
    bool GO;

    atualCardPtr = actualDeck;
    if (atualCardPtr == NULL) {
        GO = false; // Nenhuma carta na lista
    }
    else {
        anteriorCardPtr = atualCardPtr;
        atualCardPtr = atualCardPtr->nextPtr;
        if (atualCardPtr == NULL) {
            GO = false; // Só tem 1 carta na lista
        }
        else {
            anteriorDoAnteriorCardPtr = anteriorCardPtr;
            anteriorCardPtr = atualCardPtr;
            atualCardPtr = atualCardPtr->nextPtr;
            if (atualCardPtr == NULL) {
                GO = false; // Só tem 2 cartas na lista
            }
            else
                GO = true; // Tem, pelo menos 3 cartas na lista
        }
    }

    if (GO) {
        for (
             ; atualCardPtr != NULL
             ; anteriorDoAnteriorCardPtr = anteriorCardPtr, anteriorCardPtr = atualCardPtr, atualCardPtr = atualCardPtr->nextPtr
            ) 
        {
            if (anteriorDoAnteriorCardPtr->card.suit_number == anteriorCardPtr->card.suit_number
                                            &&
                anteriorCardPtr->card.suit_number == atualCardPtr->card.suit_number) 
            {
                // Preenche um histograma com a face das 3 cartas analisadas
                histogram[anteriorDoAnteriorCardPtr->card.face_number] ++;
                histogram[anteriorCardPtr->card.face_number] ++;
                histogram[atualCardPtr->card.face_number] ++;
                // Analisa o histograma para ver se há uma sequência de três "uns"
                i = 3;
                while (i <= 13) {
                    if (histogram[i] == 1 && histogram[i - 1] == 1 && histogram[i - 2] == 1) {
                        // Trinca encontrada;
                        GO = false;
                        break;
                    }
                    i++;
                }
                // Quebra o loop for se uma trinca foi encontrada
                if (!GO) {
                    break;
                }
                // Zera as posições utilizadas no histograma para a eventual próxima análise
                histogram[anteriorDoAnteriorCardPtr->card.face_number] = 0;
                histogram[anteriorCardPtr->card.face_number] = 0;
                histogram[atualCardPtr->card.face_number] = 0;
            }
        }
        EXPECT_TRUE(GO);
    }
    else
        EXPECT_TRUE(GO);


}