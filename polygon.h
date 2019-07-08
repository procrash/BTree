#pragma once
#include <vector>
#include "point.h"
#include "eventqueue.h"



class Polygon
{

public:
    std::vector<Point> points;
    int nrOfPoints{0};

    Polygon(std::vector<Point> points);


    bool simple_Polygon();



};

