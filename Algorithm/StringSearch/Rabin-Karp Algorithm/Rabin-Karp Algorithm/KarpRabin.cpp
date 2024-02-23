#include "KarpRabin.h"
#include <stdio.h>
#include <math.h>

int KarpRabin(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
    int i = 0;
    int j = 0;
    int Coefficient = pow(2, PatternSize - 1); 
    // 2�� PatternSize - 1 ���� .  �Լ��ȿ��� �Ź� ����ϴ°��� ȿ�������� ���ϴ�.
    // �ۿ��� �����θ��� ������� ������ �����ͼ� ����ϱ� ! 


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

int Hash(char* String, int Size)    //�����ѹ� [0,������ ����] ��ŭ ���ϴ� �Լ�
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

//Hash() �Լ��� ���� (�ʱ� �ؽð�)��  ���ŵ� ���� , ���Ӱ� �߰��� ���ڸ� �̿��ؼ� ����ϴ� �Լ� 
int ReHash(char* String, int Start, int Size, int HashPrev, int Coefficient) 
{
    if (Start == 0)
        return HashPrev;

    return String[Start + Size - 1] +
        ((HashPrev - Coefficient * String[Start - 1]) * 2);
}