#include <iostream>
#include "Lang.h"
#include "../../PartA/FiniteContextModel.h"
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
    
    if (argc == 5){
        // Conversion to int
        stringstream toInt(argv[1]);
        int k = 0;
        toInt >> k;

        // Conversion to float
        stringstream toFloat(argv[2]);
        float alpha = 0;
        toFloat >> alpha;
        
        Lang lang  = Lang(k, alpha, argv[3], argv[4]);

        // Conversion to string
        stringstream toString(argv[3]);
        string refText;
        toString >> refText;

        string tmp = refText.substr(22, refText.size());
        string str = tmp.substr(0, tmp.find("_"));

        double bits = lang.calculateBits();
        cout << "Number of bits needed (" << str << "): " << bits << " per symbol" << endl;
    }
    else{
        cout << "ERROR!\nUsage ./lang [-k-] [-alpha-] [-reference text file path-] [-analysis text file path-]" << endl;
        exit(1);
    }
}
