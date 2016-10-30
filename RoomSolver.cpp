// Purpose: create .cpp file for RoomSolver
// Created by: Josie Barth
// Date: October 27th 2016
// Last Modified: October 27th 2016

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "RoomSolver.h"

using namespace std;

// constructor
RoomSolver::RoomSolver()
{
    numPeople = 0;
}

// destructor
RoomSolver::~RoomSolver() 
{
    // nothing to do
}

// First line of input is the number of people (which is also equal to 
// the number of rooms).
// The following n lines of input are the names of n people, each with 
// n preferences.  Preferences are indicated by either Y (yes) or N (no)
// for each room.

// Sample-input
//      4
//      Josie Y N Y N
//      Sophie Y N N N
//      Cristiana N N N Y
//      Madison N Y Y Y

// reads room preferences for each user, returns false at EOF
bool RoomSolver::readRoomPref(string filename)
{
    ifstream f;
    f.open( filename.c_str() );
    
    if (!f.is_open()) // cannot open file
        return false;

    string junk; //this line gets eaten once data is read in
    string name;
    char preference;

    if (f >> numPeople) {

        if (numPeople <= 0)
            return false;

        getline(f, junk);

        for (int i = 0; i < numPeople; i++) {

            if (f >> name)
                Names.push_back(name);  

            vector<bool> SingleUserPreferences;
            for (int j = 0; j < numPeople; j++) {

                if (f >> preference) {

                    if ((preference == 'Y') or (preference == 'y')) {
                        SingleUserPreferences.push_back(true);
                    }
                    else {
                        SingleUserPreferences.push_back(false);
                    }
                }
            }
            getline(f, junk);  
            PreferenceMap.push_back(SingleUserPreferences);
        }
        return true;   
    }
    return false;
}

// solves all possible room combinations where each person gets a room
// with a preference of "yes", if possible
void RoomSolver::FindRoomCombo(int row, int col)
{
    for (int i = row; i < numPeople; i++) {
        for (int j = col; j < numPeople; j++) {
            
        }
    }
}

// prints a satisfying room combination, otherwise prints 
// "no combination possible"
void RoomSolver::printRoomCombo()
{
    printRoomPreferences();
    return;
}

void RoomSolver::printRoomPreferences() {
    for (int i = 0; i < numPeople; i++) {
        cout << Names[i] << "'s preferences are ";
        for (int j = 0; j < numPeople; j++) {
            if (PreferenceMap[i][j] == true) {
                cout << "Y";
            }
            else {
                cout << "N";
            }
        }
        cout << endl;
    }
    return;
}