#pragma once

#include "polygon.h"
#include "event.h"
#include "quicksort.h"
#include <optional>

class Polygon;

class EventQueue
{
private:
    std::size_t idxNextEventOnQueue{0};
    std::size_t nrOfEvents{0};
    std::vector<Event> eventQueue;

public:
    EventQueue(Polygon polygon);
    EventQueue() {}
    std::optional<Event> next() {
        std::optional<Event> result;

        if (idxNextEventOnQueue<nrOfEvents) {
            result = eventQueue[idxNextEventOnQueue++];
        }

        return result;
    }
};

