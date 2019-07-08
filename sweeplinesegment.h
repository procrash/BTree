#pragma once

#include "point.h"

// SweepLine segment data struct
struct SweepLineSegment {
    int      edge;          // polygon edge i is V[i] to V[i+1]
    Point    lP;            // leftmost vertex point
    Point    rP;            // rightmost vertex point
    SweepLineSegment*   above;         // segment above this one
    SweepLineSegment*   below;         // segment below this one
    SweepLineSegment(){}

    bool operator<(const SweepLineSegment& other){
        if (lP.y < other.lP.y) return true;
        return false;
    }
    bool operator>(const SweepLineSegment& other){
        if (lP.y > other.lP.y) return true;
        return false;
    }

};
