#include "KarpRabin.h"
#include <stdio.h>
#include <math.h>

int KarpRabin(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
    int i = 0;
    int j = 0;
    int Coefficient = pow(2, PatternSize - 1); 
    // 2의 PatternSize - 1 제곱 .  함수안에서 매번 계산하는것은 효율적이지 못하다.
    // 밖에서 변수로만들어서 계산한후 안으로 가져와서 사용하기 ! 


    int HashText = Hash(Text, PatternSize);
    int HashPattern = Hash(Pattern, PatternSize);

    for (i = Start; i <= TextSize - PatternSize; i++)
    {
        HashText = ReHash(Text, i, PatternSize - 1, HashText, Coefficient);

        if (HashPattern == HashText)
        {
            for (j = 0; j < PatternSize; j++)
            {
                if (Text[i + j] != Pattern[j])
                    break;
            }

            if (j >= PatternSize)
                return i;
        }
    }

    return -1;
}

int Hash(char* String, int Size)    //최초한번 [0,패턴의 길이] 만큼 구하는 함수
{
    int i = 0;
    int HashValue = 0;

    for (i = 0; i < Size; i++)
    {
        HashValue = String[i] + (HashValue * 2);
        // i = 0 , HashValue = String[0] + 0*2
        // 
        // i = 1 , HashValue = String[1] + String[0]*2

        /* i = 2 , HashValue = String[2] + (String[1] + String[0]*2)*2
                             = String[2] + String[1]*2 + String[0]*2*2 */

        /* i = 3 , HashValue = String[3] + (String[2] + (String[1] + String[0]*2)*2)*2
                             = String[3] + String[2]*2 + String[1]*2*2 + String[0]*2*2*2 */
   
    }

    return HashValue;
}

//Hash() 함수를 통해 (초기 해시값)을  제거된 문자 , 새롭게 추가된 문자만 이용해서 계산하는 함수 
int ReHash(char* String, int Start, int Size, int HashPrev, int Coefficient) 
{
    if (Start == 0)
        return HashPrev;

    return String[Start + Size - 1] +
        ((HashPrev - Coefficient * String[Start - 1]) * 2);
}