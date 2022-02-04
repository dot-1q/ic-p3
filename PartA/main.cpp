#include "FiniteContextModel.h"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        // Conversion to int
        std::stringstream toInt(argv[1]);
        int k = 0;
        toInt >> k;

        // Conversion to float
        std::stringstream toFloat(argv[2]);
        float alpha = 0;
        toFloat >> alpha;

        FiniteContextModel fcm = FiniteContextModel(k, alpha, argv[3]);  // Os_Maias.txt 
        fcm.printOccurenceMap();
        double entropy = fcm.calculateEntropy();
        std::cout << "Entropy of the file: " << entropy << std::endl;
    }
    else
    {
        std::cout << "ERROR!\nUsage ./fcm [-k-] [-alpha-] [-text_path-]" << std::endl;
        exit(1);
    }
}
