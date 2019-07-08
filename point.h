#pragma once

class Point
{
public:
    int x;
    int y;

    Point(int x, int y);
    Point();

    bool operator<(const Point& other) {
        if (this->x <other.x) return true;
        if (this->x >other.x) return false;

        if (this->y <other.y) return true;
        if (this->y >other.y) return false;
        return false;
    }

    bool operator>(const Point& other) {
        if (this->x <other.x) return false;
        if (this->x >other.x) return true;

        if (this->y <other.y) return false;
        if (this->y >other.y) return true;
        return false;
    }
    bool operator<=(const Point& other) {
        if (this->x == other.x && this->y == other.y) return true;
        return *this < other;
    }

    bool operator>=(const Point& other) {
        if (this->x == other.x && this->y == other.y) return true;
        return *this > other;
    }
};

