#include "FiniteContextModel.h"
#include <iostream>

int main(void)
{
    FiniteContextModel fcm = FiniteContextModel(5,0.3,"Os_Maias.txt"); //Os_Maias.txt
    fcm.printOccurenceMap();
    double entropy = fcm.calculateEntropy();
    std::cout << "Entropy of the file: " << entropy << std::endl;
    return 0;
}
