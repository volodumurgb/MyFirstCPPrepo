#include "Orientation.h"
#include <iostream>

int orientationCheck()
{
    LGBT* characters[2];

	std::cout << "Creating characters..." << std::endl;
    characters[0] = new BiMen();
    std::cout << "_______________________________________" << std::endl;
    characters[1] = new Existence();

    std::cout << "\n";
	std::cout << "Information about characters:" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        characters[i]->displayInfo();
        characters[i]->SaySomething();
        std::cout << "_______________________________________" << std::endl;
    }

	std::cout << "\n";
	std::cout << "Deleting characters..." << std::endl;
    for (int i = 0; i < 3; i++)
    {
        delete characters[i];
        std::cout << "_______________________________________" << std::endl;
    }

    return 0;
}