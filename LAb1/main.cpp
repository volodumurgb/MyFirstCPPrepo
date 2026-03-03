#include <iostream>
#include "functions.h"
int main() {
    FILE *f;
    int err = fopen_s(&f, "check.txt", "r");
    if (err != 0) {
        std::cerr << "Error opening file!" << std::endl;
        return 0;
    }
    FinalDiva(f);   
    fclose(f);
return 1;
}
