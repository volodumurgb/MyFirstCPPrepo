#ifndef FUNCTIONS_H
#include <cstdio>
#define FUNCTIONS_H

struct Price
{
    int grn;
    short int cop;
};
void FinalDiva(FILE *f);
void sumPrice(Price &A, Price &B);
void priceCount(Price &A, int count);
void printPrice(Price &A);
void finalizePrice(Price &A);
#endif