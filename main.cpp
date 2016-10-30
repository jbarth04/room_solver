//Purpose: Main for Room Solver
//Created by: Josie Barth
//Date: October 27th 2016
//Last Modified: October 27th 2016

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "RoomSolver.h"

using namespace std;

int main(int ac, char *av[]) 
{  
    RoomSolver RS;
    
    if (ac == 1) {
        
        cout << "Room Input Needed\n"; 
        return 1;
    }
    
    if (RS.readRoomPref(string(av[1])) == false) {
        cout << "Error reading room preferences" << endl;
        return 1;
    }

    RS.printRoomCombo();
    
    return 0;
}
