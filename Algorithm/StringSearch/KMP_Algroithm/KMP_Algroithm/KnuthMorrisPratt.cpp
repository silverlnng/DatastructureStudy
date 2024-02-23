#include "KnuthMorrisPratt.h"
#include <stdlib.h>

//�ִ� ����� �ʺ� �����ϴ� ���̺��� ����� �Լ�
void Preprocess(char* Pattern, int PatternSize, int* Border)
{
    int i = 0;
    int j = -1;

    Border[0] = -1;
    //���� : BAABABAA
    while (i < PatternSize)
    {
        while (j > -1 && Pattern[i] != Pattern[j])
        {
            j = Border[j];
        }
        // (1): i=0 , j=-1 while �� ���� false

         /*(2): i=1,j=0, Pattern[1] , Pattern[0] �� 
           �ٸ��ٸ� j = Border[0] = -1 while�� Ż��
           ���ٸ� while �� ���� false = Ż��*/

         //(3)_1: j=0 
         // Pattern[2] �� Pattern[0] �� ��
         // �ٸ��ٸ� j = Border[0] = -1
         // �������  
        // (3)_1: j=1 
        //  Pattern[2] �� Pattern[1] �� ��
        // ������� 
        i++;
        //(1):i=1
        //(2):i=2
        //(3):i=3
        j++;
        //(1): j=0
        //(2): �޶� j=0 ,���ٸ� j=1
        //(3)_1 : j=0 ,1 (3)_2 :j=2
        Border[i] = j;
        //(1): Border[1] = 0;
        //(2): �ٸ��ٸ� Border[2] = 0; ,���ٸ� Border[2] = 1; 
        //(3): ���ٸ� Border[3] = 2;            
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