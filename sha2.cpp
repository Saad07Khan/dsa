#include <iostream>
#include "sha2.h"
 
using std::string;
using std::cout;
using std::endl;
 
int main(int argc, char *argv[])
{
    string input = "saad";
    string output2 = sha256(input);
    cout << "sha256('"<< input << "'):" << output2 << endl;
    return 0;
}

