// **************************************************************************
//  File       [maxPlanarSubset.h]
//  Author     [Samuel Liu]
//  Synopsis   [the header file for the maxPlanarSubset]
//  Modify     [2021/11/20 Samuel Liu]
// **************************************************************************

#ifndef _MAXPLANARSUBSET_H
#define _MAXPLANARSUBSET_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class maxPlanarSubset
{
    public:
                maxPlanarSubset();          // constructor
        void    fillMatrix(vector<int>&, vector<vector<int>>&, int);                 // fill Matrix M
        void    fillChoice(vector<int>&, vector<vector<int>>&, vector<bool>&, int, int, int);       // fill Array Choice
};

#endif
