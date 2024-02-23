#include <stdio.h>
#include <string.h>
#include "KarpRabin.h"
#include <math.h>

#define MAX_BUFFER 512

int main(int argc, char** argv)
{
    char  Text[MAX_BUFFER] = "My name is pattern";
    char* Pattern =(char*)"pattern";
    int   PatternSize = 4;
    int h0, h1, rh1;

    int result = KarpRabin(Text, strlen(Text), 0, Pattern, strlen(Pattern));
    printf("%d\n", result);

    h0 = Hash(Pattern, PatternSize);
    h1 = Hash(Pattern + 1, PatternSize);
    rh1 = ReHash(Pattern, 1, PatternSize, h0, (int)pow(2, PatternSize - 1));

    printf("h0:%d\n", h0);
    printf("h1:%d\n", h1);
    printf("rh1:%d\n", rh1);

    return 0;
}