#include "KnuthMorrisPratt.h"
#include <stdlib.h>

//최대 경계의 너비를 보관하는 테이블을 만드는 함수
void Preprocess(char* Pattern, int PatternSize, int* Border)
{
    int i = 0;
    int j = -1;

    Border[0] = -1;
    //예시 : BAABABAA
    while (i < PatternSize)
    {
        while (j > -1 && Pattern[i] != Pattern[j])
        {
            j = Border[j];
        }
        // (1): i=0 , j=-1 while 문 조건 false

         /*(2): i=1,j=0, Pattern[1] , Pattern[0] 비교 
           다르다면 j = Border[0] = -1 while문 탈출
           같다면 while 문 조건 false = 탈출*/

         //(3)_1: j=0 
         // Pattern[2] 와 Pattern[0] 을 비교
         // 다르다면 j = Border[0] = -1
         // 같은경우  
        // (3)_1: j=1 
        //  Pattern[2] 와 Pattern[1] 을 비교
        // 같은경우 
        i++;
        //(1):i=1
        //(2):i=2
        //(3):i=3
        j++;
        //(1): j=0
        //(2): 달라서 j=0 ,같다면 j=1
        //(3)_1 : j=0 ,1 (3)_2 :j=2
        Border[i] = j;
        //(1): Border[1] = 0;
        //(2): 다르다면 Border[2] = 0; ,같다면 Border[2] = 1; 
        //(3): 같다면 Border[3] = 2;            
    }
}

int  KnuthMorrisPratt(char* Text, int TextSize, int Start,
    char* Pattern, int PatternSize)
{
    int i = Start;
    int j = 0;
    int Position = -1;

    int* Border = (int*)calloc(PatternSize + 1, sizeof(int));

    Preprocess(Pattern, PatternSize, Border);

    while (i < TextSize)
    {
        while (j >= 0 && Text[i] != Pattern[j])
            j = Border[j];

        i++;
        j++;

        if (j == PatternSize)
        {
            Position = i - j;
            break;
        }
    }

    free(Border);
    return Position;
}