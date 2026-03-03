#ifndef FUNCTIONS_H
#include <cstdio>
#define FUNCTIONS_H

struct Price
{
    int grn;
    int cop;
};
void FinalDiva(FILE *f);
void readPrice(Price &A, FILE *f);
void normalizePrice(Price &A);
void sumPrice(Price &A, Price &B);
void priceCount(Price &A, int count);
void printPrice(Price &A);
void finalizePrice(Price &A);
#endif