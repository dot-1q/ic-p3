#include "FiniteContextModel.h"
#include <iostream>

int main(void)
{
    FiniteContextModel fcm = FiniteContextModel(5,0,"Os_Maias.txt");

    fcm.occurence_map();
    return 0;
}
