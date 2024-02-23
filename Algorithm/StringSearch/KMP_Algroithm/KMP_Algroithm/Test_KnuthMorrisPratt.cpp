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

    //// fget함수 : fgets(char* str, int num, FILE* stream);
    //// stream: 문자열을 읽어들일 스트림의 FILE 객체를 가리키는 포인터. 특히, 표준 입력(stdin) 에서 입력을 받으려면 여기에 stdin 을 써주면 된다
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