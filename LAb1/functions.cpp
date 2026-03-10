#include "functions.h"
#include <iostream>



void sumPrice(Price &A, Price &B) {
    A.grn += B.grn;
    A.cop += B.cop;
}        
void priceCount(Price  &A, int count) {
    A.grn *= count;
       A.cop *= count;
}
void finalizePrice(Price &A) {
    if (A.cop % 10 >= 5) {
        A.cop += 10 - (A.cop % 10);
    } else {
        A.cop -= A.cop % 10;    
    }
}
void printPrice(Price &A) {
    std::cout << "Price" << std::endl;
    std::cout << A.grn << " grn " << A.cop << " cop" << std::endl;
    finalizePrice(A);
    if (A.cop >= 100) {
        A.grn += A.cop / 100;
        A.cop %= 100;
    }
    std::cout << "Price with rounding" << std::endl;
    std::cout << A.grn << " grn " << A.cop << " cop" << std::endl;
}   
void FinalDiva(FILE *f) {
char name[50];
int g, n;
short int c;
char str[10], str1[10], str2[10];
Price totalSum = { 0, 0 };
Price price;
while (fscanf_s(f, "%s %d %s %hi %s %d %s", name, _countof(name), &g, str, _countof(str), &c, str1, _countof(str1), &n, str2, _countof(str2)) == 7) {
    Price price = { g, c };
    priceCount(price, n);
    sumPrice(totalSum, price);
}
    if (totalSum.cop >= 100) {
        totalSum.grn += totalSum.cop / 100;
        totalSum.cop %= 100;
    }
    printPrice(totalSum);
}
