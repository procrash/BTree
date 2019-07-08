#include "eventqueue.h"


EventQueue::EventQueue(Polygon polygon) {

    idxNextEventOnQueue = 0;
    nrOfEvents = 2*polygon.nrOfPoints;

    for (std::size_t i=0; i<polygon.nrOfPoints; ++i) {
        Event e1(i, polygon.points[i]);
        Event e2(i, polygon.points[i+1]);

        if (polygon.points[i]<polygon.points[i+1]) {
            e1.type = EventType::Left;
            e2.type = EventType::Right;
        } else {
            e1.type = EventType::Right;
            e2.type = EventType::Left;
        }

        eventQueue.push_back(e1);
        eventQueue.push_back(e2);

    }

    Quicksort::sort(eventQueue);
}
