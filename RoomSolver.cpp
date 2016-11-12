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

// wrapper function for solve
void RoomSolver::FindRoomCombos() 
{
    vector<onePreference> testSoln;
    solve(0, testSoln);
}

// solves all possible room combinations where each person gets a room
// with a preference of "yes", if possible
void RoomSolver::solve(int person, vector<onePreference> testSoln)
{
    
    if (person >= numPeople) {

        if (testSoln.size() == (unsigned long)numPeople) { // get rid of warning

            Solutions.push_back(testSoln);
        }
        return;
    }

    for (int room = 0; room < numPeople; room++) {

        // check user preference
        if (PreferenceMap[person][room] == true) {
        
            if (not isRoomTaken(room)) {

                addToRoomMap(room);

                onePreference testPref;
                testPref.name = Names[person];
                testPref.room = room;

                testSoln.push_back(testPref);

                // recursively solve for next person
                solve((person + 1), testSoln);

                // remove previous recursive solutions
                testSoln.pop_back();
                removeFromRoomMap(room);
            }
        }  
    }
}

// if a room is already taken in the room map, returns true,
// otherwise returns false
bool RoomSolver::isRoomTaken(int room)
{
    if (RoomMap[room] == true) {
        return true;
    } 

    return false;        
}

// given a room number, adds the room as taken to the room map
void RoomSolver::addToRoomMap(int room)
{

    RoomMap[room] = true;
}

// given a room number, removes the room as taken from the room map
void RoomSolver::removeFromRoomMap(int room)
{

    RoomMap.erase(room);
}

// prints all satisfying room combinations, otherwise prints 
// "No solution for given user preferences"
void RoomSolver::printRoomCombos()
{
    // printRoomPreferences();
    int numSolutions = Solutions.size();

    if (numSolutions <= 0) {
        cout << "No solution for given user preferences" << endl;
        return;
    }

    for (int i = 0; i < numSolutions; i++) {
        cout << "Solution " << (i + 1) << ": " << endl;
        for (int j = 0; j < numPeople; j++) {

            cout << Solutions[i][j].name << " is in room " << (Solutions[i][j].room + 1) << endl;

        }
        cout << endl;
    }
}

// prints room preferences map for each user
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