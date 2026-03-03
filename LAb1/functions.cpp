#include "functions.h"
#include <iostream>



void readPrice(Price &A, FILE *f) {
    char name[50];
    char str[10];
    char str1[10];
    char str2[10];
    int g, n, c;
fscanf_s(f, "%s %d %s %d %s %d %s", name, _countof(name), &g, str, _countof(str), &c, str1, _countof(str1), &n, str2, _countof(str2));
}

void normalizePrice(Price &A) {
    if (A.cop >= 100) {
        A.grn += A.cop / 100;
        A.cop %= 100;
    }
}
void sumPrice(Price &A, Price &B) {
    A.grn += B.grn;
    A.cop += B.cop;
    normalizePrice(A);
}        
void priceCount(Price  &A, int count) {
    A.grn *= count;
       A.cop *= count;
    normalizePrice(A);
}
void finalizePrice(Price &A) {
    if (A.cop % 10 >= 5) {
        A.cop += 10 - (A.cop % 10);
        normalizePrice(A);
    } else {
        A.cop -= A.cop % 10;    
    }
}
void printPrice(Price &A) {
    normalizePrice(A);
    std::cout << "Price" << std::endl;
    std::cout << A.grn << " grn " << A.cop << " cop" << std::endl;
    finalizePrice(A);
    std::cout << "Price with rounding" << std::endl;
    std::cout << A.grn << " grn " << A.cop << " cop" << std::endl;
}   
void FinalDiva(FILE *f) {
char name[50];
int g, c, n;
char str[10], str1[10], str2[10];
Price totalSum = { 0, 0 };

while (fscanf_s(f, "%s %d %s %d %s %d %s", name, _countof(name), &g, str, _countof(str), &c, str1, _countof(str1), &n, str2, _countof(str2)) == 7) {
    Price price = { g, c };
    normalizePrice(price);
    sumPrice(totalSum, price);
    priceCount(price, n);
}

fclose(f);
printPrice(totalSum);
}
