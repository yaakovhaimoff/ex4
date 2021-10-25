#pragma once
#include "Vertex.h"
#include "Rectangle.h"

class Square
{
public:
    Square(const Vertex& bottomLeft, const Vertex& topRight);
    Square(const Vertex& start, double length);

    ~Square();
    Vertex getBottomLeft(const double leftBottomVertex);
    Vertex getTopRight(const double rightTopVertex);
    double getLength(const double topLength);

    void draw(Board& board) const;
    Rectangle getBoundingRectangle()const;
    double getArea()const;
    Vertex getCenter()const;
    bool scale(double factor);

private:
    Vertex m_bottomLeft;
    Vertex m_topRight;
};

