#include "polygon.h"

#include <optional>

#include "event.h"
#include "sweepline.h"
#include "sweeplinesegment.h"

Polygon::Polygon(std::vector<Point> points):points(points){
    nrOfPoints = points.size();
}

bool Polygon::simple_Polygon()
{
    EventQueue  Eq(*this);


        SweepLine   SL(*this);


        std::optional<Event>      e;                  // the current event
        SweepLineSegment      s;                  // the current SL segment


        // This loop processes all events in the sorted queue
        // Events are only left or right vertices since
        // No new events will be added (an intersect => Done)
        while ((e = Eq.next())) {         // while there are events

            if (e->type == EventType::Left) {      // process a left vertex

                Event evt = *e;

                s = SL.add(evt);          // add it to the sweep line
                /*
                if (SL.intersect(  s, s->above))
                    return false;      // Pn is NOT simple
                if (SL.intersect(  s, s->below))
                    return false;      // Pn is NOT simple
                */
            }
            else {                      // processs a right vertex
                /*
                s = SL.find(e);
                if (SL.intersect(  s->above, s->below))
                    return false;      // Pn is NOT simple
                SL.remove(s);           // remove it from the sweep line
                */
            }
        }


    return true;      // Pn IS simple
}
