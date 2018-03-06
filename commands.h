#ifndef COMMANDS_H
#define COMMANDS_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <QString>
#include <cstring>
#include <cmath>
#include <vector>
#include <point.h>
using namespace std;
class Commands
{
public:
    Commands();
    void ReadData(string,vector<Point> &);
    void SelectionSort(int *,int);
    void ConvertToOxy(double,int,vector<Point> &);
    void NoiceIllimination(vector<Point> &,vector<Point> &);
    void Kmeans();
    void LinerAprocsimation();
};

#endif // COMMANDS_H
