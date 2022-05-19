#include"OceanLogic.h"
#include"DisplayOcean.h"

int main(int argc, char* argv[]) {
    DisplayOcean CLIDisplay;
    OceanLogic* myOcean = new OceanLogic();
    CLIDisplay.DisplayMaps(myOcean->Run());
    delete myOcean;
    return 0;
}