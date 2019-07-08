#pragma once
#include "point.h"
#include "polygon.h"
#include "sweeplinesegment.h"
#include "btree.h"


class SweepLine
{
private:
    Polygon& polygon;
    std::size_t numberOfVertices{0};
    BTree<SweepLineSegment> tree;
public:


    SweepLine(Polygon& polygon) : polygon(polygon), numberOfVertices(polygon.nrOfPoints){
    }


    SweepLineSegment add(Event event) {

        SweepLineSegment result;

        Point p1 = polygon.points[event.edgeIdx];
        Point p2 = polygon.points[event.edgeIdx+1];

        if (p1<p2) {
            result.lP = p1;
            result.rP = p2;
        } else {
            result.lP = p2;
            result.rP = p1;
        }

        tree.insert(result);

        return  result;

    }


    bool isIntersecting(const Point& P1, const Point& P2,
                        const Point& P3, const Point& P4) {
        return (((P3.x-P1.x)*(P2.y-P1.y) - (P3.y-P1.y)*(P2.x-P1.x))
                    * ((P4.x-P1.x)*(P2.y-P1.y) - (P4.y-P1.y)*(P2.x-P1.x)) < 0)
            &&
            (((P1.x-P3.x)*(P4.y-P3.y) - (P1.y-P3.y)*(P4.x-P3.x))
                 * ((P2.x-P3.x)*(P4.y-P3.y) - (P2.y-P3.y)*(P4.x-P3.x)) < 0);
    }

};


