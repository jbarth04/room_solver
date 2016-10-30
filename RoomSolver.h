/*
 * RoomSolver.h
 *
 *  Edited on: October 6th, 2016
 *      Author: Josie Barth
 */

#ifndef ROOMSOLVER_H
#define ROOMSOLVER_H

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

//
//  A class to solve room assignment. 
//
//  Given n number of people and n rooms, each person gives their preference
//  "Y" (yes) if they'd live in a particular room or "N" (no).
//
//  Then with the preferences for each user for each room, this class can
//  determine what room arrangement(s) are possible to satisfy a combination of
//  "yes" answers for each person in a room, or it will state that no
//  combinations are possible
//

// struct {
//     string name;
//     bool preference;
// }

class RoomSolver
{
public:

    // constructor
    RoomSolver();

    // destructor
    ~RoomSolver();

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
    bool readRoomPref(string filename);

    // solves all possible room combinations where each person gets a room
    // with a preference of "yes", if possible
    void FindRoomCombo(int row, int col);

    // prints a satisfying room combination, otherwise prints 
    // "no combination possible"
    void printRoomCombo();

private:

    int numPeople; // n people for n rooms

    vector< vector<bool> > PreferenceMap; // 2D vector with map of 

    // array with the name of each person 
    // row n in the PreferenceMap is parallel to index n in the array Names
    vector<string> Names; 

    // function for debugging to see if user input is read in correctly
    void printRoomPreferences();
};

#endif