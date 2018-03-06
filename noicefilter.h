#ifndef NOICEFILTER_H
#define NOICEFILTER_H
#include "point.h"
#include <vector>
#include <cstring>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
class Noicefilter
{
public:
    Noicefilter();
    void SortPointsByY(std::vector<Point> &);
    void MedianaFilter();
    void AveregeGeometric();
    std::vector<Point> ArrayOfPoints();
    std::vector<Point>& get_Points();
    void setParameters(std::string,int);
    void SelectionSort(std::vector<double> &);
    void ReadData(std::string);
    void ConvertToxy(double,int);
    void LinerRegresion(Point &,Point &);
    void DetectCrashPoints(int,int);
    std::vector<Point> DrawPoints;
private:
std::string Path="";
int Window;
std::vector<Point> Points;

protected:



};

#endif // NOICEFILTER_H
