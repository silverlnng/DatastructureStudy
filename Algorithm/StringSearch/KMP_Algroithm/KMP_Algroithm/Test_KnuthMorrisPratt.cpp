#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstring>
#include "KnuthMorrisPratt.h"

#define MAX_BUFFER 512

int main(int argc, char** argv)
{
    char* FilePath;
    FILE* fp;

    char  Text[MAX_BUFFER];
    char* Pattern;
    int   PatternSize = 0;
    int   Line = 0;

    if (argc < 3)
    {
        printf("Usage: %s <FilePath> <Pattern>\n", argv[0]);
        return 1;
    }

    FilePath = argv[1];
    Pattern = argv[2];

    PatternSize = static_cast<int>(strlen(Pattern));

    if ((fp = fopen(FilePath, "r")) == NULL)
    {
        printf("Cannot open file:%s\n", FilePath);
        return 1;
    }

    //// fget�Լ� : fgets(char* str, int num, FILE* stream);
    //// stream: ���ڿ��� �о���� ��Ʈ���� FILE ��ü�� ����Ű�� ������. Ư��, ǥ�� �Է�(stdin) ���� �Է��� �������� ���⿡ stdin �� ���ָ� �ȴ�
    //// 
    while (fgets(Text, MAX_BUFFER, fp) != NULL)
    {
        int Position =
            KnuthMorrisPratt(Text, strlen(Text), 0, Pattern, PatternSize);

        Line++;

        if (Position >= 0)
        {
            printf("line:%d, column:%d : %s", Line, Position + 1, Text);
        }
    }

    fclose(fp);



    //printf()

    return 0;
}