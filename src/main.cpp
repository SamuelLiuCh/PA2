// **************************************************************************
//  File       [main.cpp]
//  Author     [Samuel Liu]
//  Synopsis   [the main program of the maxPlanarSubset]
//  Modify     [2021/11/20 Samuel Liu]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "maxPlanarSubset.h"
using namespace std;

void help_message()
{
    cout << "usage: ./bin/mps <input file name> <output file name\n" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
       help_message();
       return 0;
    }

    maxPlanarSubset maxPlanarSubset;

    //open input file
    ifstream fin(argv[1]);
    //read the First Line 2N
    int Points;
    fin >> Points;
    //create Connection Array between each Point
    vector<int> Connection(Points,0);
    for (int i = 0; i < (Points/2); i++)
    {
        int a,b;
        fin >> a >> b;
        Connection[b] = a;
        Connection[a] = b;
    }
    //close input file
    fin.close();

    //create Matrix of Points
    vector<vector<int>> MatrixM(Points,vector<int>(Points));

    // do max Planar Subset
    maxPlanarSubset.fillMatrix(Connection, MatrixM, Points);

    //open output file
    ofstream fout(argv[2]);
    //write Number of choice Connection N
    fout << MatrixM[0][Points-1] << endl;
    //write Pairs of choice Connection a b
    vector<bool> Choice(Points,0);
    maxPlanarSubset.fillChoice(Connection, MatrixM, Choice, Points, 0, Points-1);
    for (int i = 0; i < Points; ++i)
    {
      if (Choice[i] == 1)
            fout << i << " " << Connection[i] << '\n';
    }
    //close output file
    fout.flush();
    fout.close();

    return 0;
}