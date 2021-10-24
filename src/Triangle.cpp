#pragma once

#include <iosfwd>
#include "Vertex.h"
#include "Board.h"
#include "Triangle.h"
#include "Utilities.h"
#include <cmath>

// _________________________________________
// Triangle::Triangle(const Vertex vertcies[3])
// {
//     if (vertcies[0].isTriangle(vertcies[1], vertcies[2]) &&
//         sameCol(vertcies[0], vertcies[1]))
//     {
//         m_triangleVertex[0] = vertcies[0];
//         m_triangleVertex[1] = vertcies[1];
//         m_triangleVertex[2] = vertcies[2];
//     }
//     else
//     {
//         m_triangleVertex[0] = Vertex(20, 20);
//         m_triangleVertex[1] = Vertex(30, 20);
//         m_triangleVertex[2] = Vertex(25, 20 + sqrt(75));
//     }
// }
Triangle::Triangle(const Vertex vertcies[3])
    : Triangle(vertcies[0], vertcies[1], vertcies[2].m_row - vertcies[1].m_row) {}
// ________________________________________________
Triangle::Triangle(const Vertex &v0, const Vertex &v1, double height)
{
    Vertex v2;
    v2.m_col = (v0.m_col + v1.m_col) / 2;
    v2.m_row = (v1.m_row + height);
    if (v0.isTriangle(v1, v2) &&
        sameCol(v0, v1))
    {
        m_triangleVertex[0] = v0;
        m_triangleVertex[1] = v1;
        m_triangleVertex[2] = v2;
    }
    else
    {
        m_triangleVertex[0] = Vertex(20, 20);
        m_triangleVertex[1] = Vertex(30, 20);
        m_triangleVertex[2] = Vertex(25, 20 + sqrt(75));
    }
}
// _________________________________________
Vertex Triangle::getVertex(int index) const
{
    return m_triangleVertex[index];
}
// _______________________________
double Triangle::getLength() const
{
    return abs(m_triangleVertex[1].m_col - m_triangleVertex[0].m_col);
}
// _______________________________
double Triangle::getHeight() const
{
    return abs(m_triangleVertex[2].m_row - m_triangleVertex[1].m_row);
}

// not good, need to work on it more.
// _____________________________________
void Triangle::draw(Board &board) const
{
    board.drawLine(this->m_triangleVertex[0], this->m_triangleVertex[1]);
    board.drawLine(this->m_triangleVertex[1], this->m_triangleVertex[2]);
    board.drawLine(this->m_triangleVertex[2], this->m_triangleVertex[0]);
}

// _____________________________________________
Rectangle Triangle::getBoundingRectangle() const
{
}
// ______________________________
double Triangle::getArea() const
{
    return (abs(m_triangleVertex[0].m_col - m_triangleVertex[1].m_col) *
            abs(m_triangleVertex[2].m_row - m_triangleVertex[1].m_row)) /
           2;
}
// __________________________________
double Triangle::getPerimeter() const
{
    return 3 *
           abs(m_triangleVertex[0].m_col - m_triangleVertex[1].m_col);
}
// _______________________________
Vertex Triangle::getCenter() const
{
    return Vertex((m_triangleVertex[0].m_col + m_triangleVertex[1].m_col +
                   m_triangleVertex[2].m_col) /
                      3,
                  (m_triangleVertex[0].m_row + m_triangleVertex[1].m_row +
                   m_triangleVertex[2].m_row) /
                      3);
}
// ________________________________
bool Triangle::scale(double factor)
{
}