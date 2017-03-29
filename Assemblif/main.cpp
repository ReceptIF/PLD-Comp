#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    if((argc != 3 && argc !=4) || (string)argv[1] == "-h")
    {
        cout << "Usage : Assemblif.exe input.s outputName" << endl;
        cout << "Optional arguments :" << endl;
        cout << "-O[1,2,3] : Tell GCC to optimize" << endl;
        return 1;
    }
    string inputName = argv[1];
    string inputNameWithOextension = inputName.substr(0, inputName.size()-1)+'o';
    string outputName = argv[2];

    //as.
    string asCommand = "as -o " + inputNameWithOextension + " " + inputName;
    cout << "Running command " << asCommand << endl;
    system(asCommand.c_str());

    //g++
    string gCommand = "gcc "+ inputNameWithOextension + " -o "+ outputName;
    if(argc == 4)
        gCommand = gCommand + ' ' +argv[3];
    cout << "Running command " << gCommand << endl;
    system(gCommand.c_str());
    return 0;
}