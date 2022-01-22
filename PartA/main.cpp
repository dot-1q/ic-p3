#include "FiniteContextModel.h"
#include <iostream>

int main(void)
{
    FiniteContextModel fcm = FiniteContextModel(10,0,"Os_Maias.txt"); //Os_Maias.txt
    fcm.occurenceMap();
    fcm.printOccurenceMap();
    std::cout << "\n";
    std::cout << "entropy of the model :" << fcm.calculateEntropy() << "\n";
    std::cout << "\n";
    return 0;
}
