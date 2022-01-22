#include "FiniteContextModel.h"
#include <iostream>

int main(void)
{
    FiniteContextModel fcm = FiniteContextModel(5,0,"Os_Maias.txt");
    fcm.occurenceMap();
    fcm.printOccurenceMap();
    std::cout << "entropy of the model :" << fcm.calculateEntropy() << "\n";
    return 0;
}
