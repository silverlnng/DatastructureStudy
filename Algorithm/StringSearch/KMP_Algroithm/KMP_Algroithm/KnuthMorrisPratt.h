#pragma once
#ifndef KNUTHMORRISPRAT_H
#define KNUTHMORRISPRAT_H

#include <stdio.h>

int  KnuthMorrisPratt(char* Text, int TextSize, int Start,
    char* Pattern, int PatternSize);

void Preprocess(char* Pattern, int PatternSize, int* Border);
//최대 경계의 너비를 보관하는 테이블을 만드는 함수
#endif