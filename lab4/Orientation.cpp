#include "Orientation.h"
#include <iostream>

int orientationCheck()
{
    LGBT* characters[3];

    characters[0] = new Femboy("@femboy.szn", "he/him/they", "short-haired");
    characters[1] = new Gay();
    characters[2] = new Lesbian();

    for (int i = 0; i < 3; i++)
    {
        characters[i]->displayInfo();
        characters[i]->SaySomething();
        std::cout << "_______________________________________" << std::endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete characters[i];
    }

    return 0;
}
