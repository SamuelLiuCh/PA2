// **************************************************************************
//  File       [maxPlanarSubset.cpp]
//  Author     [Samuel Liu]
//  Synopsis   [maxPlanarSubset]
//  Modify     [2021/11/20 Samuel Liu]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "maxPlanarSubset.h"
using namespace std;

// constructor
maxPlanarSubset::maxPlanarSubset() {}

// fill Matrix M
void maxPlanarSubset::fillMatrix(vector<int>& Connection, vector<vector<int>>& MatrixM, int Points)
{
    //determine Number of MIS
    for (int l = 1; l < Points; l++)
    {
        for (int i = 0; i  < (Points-l); i++)
        {
            int j = i+l;
            int k = Connection[j];
            // k out of M[i,j]
            if (k > j || k < i)
            {
                MatrixM[i][j] = MatrixM[i][j-1];
            }
            // k = i
            else if (k == i)
            {
                MatrixM[i][j] = MatrixM[i+1][j-1]+1;
            }
            // k in M[i,j]
            else
            {   
                if (MatrixM[i][j-1] >= MatrixM[i][k-1]+1+MatrixM[k+1][j-1])
                {
                    MatrixM[i][j] = MatrixM[i][j-1];
                }
                else
                {
                    MatrixM[i][j] = MatrixM[i][k-1]+1+MatrixM[k+1][j-1];
                }
            }
        }
    }
}

// fill Array Choice
void maxPlanarSubset::fillChoice(vector<int>& Connection, vector<vector<int>>& MatrixM, vector<bool>& Choice, int Points, int i, int j)
{
    //create Choice Array between each Point
    int k = Connection[j];
    if (i < j)
    {
        // MatrixM[i][j] = MatrixM[i][j-1]
        if (MatrixM[i][j] == MatrixM[i][j - 1])
        {
            fillChoice(Connection, MatrixM, Choice, Points, i, j-1);
        }
        // MatrixM[i][j] = MatrixM[i+1][j-1]+1
        else if (k == i)
        {
            Choice[i] = 1;
            fillChoice(Connection, MatrixM, Choice, Points, i+1, j-1);
        }
        // MatrixM[i][j] = MatrixM[i][k-1]+1+MatrixM[k+1][j-1]
        else
        {
            Choice[k] = 1;
            fillChoice(Connection, MatrixM, Choice, Points, i, k-1);
            fillChoice(Connection, MatrixM, Choice, Points, k+1, j-1);
        }
    }
}

