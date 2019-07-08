#pragma once

#include "point.h"
enum class EventType{Left, Right};

struct Event
{
    int edgeIdx;
    EventType type;
    Point eventVertex;

    Event(int edgeIdx,Point eventVertex) : edgeIdx(edgeIdx), eventVertex(eventVertex) {

    }

    bool operator<(const Event& other) {
        return this->eventVertex < other.eventVertex;
    }
    bool operator>(const Event& other) {
        return this->eventVertex > other.eventVertex;
    }
    bool operator<=(const Event& other) {
        return this->eventVertex <= other.eventVertex;
    }
    bool operator>=(const Event& other) {
        return this->eventVertex >= other.eventVertex;
    }
};
