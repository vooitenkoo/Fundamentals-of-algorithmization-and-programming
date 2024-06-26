#include "field.h"
#include "structure.h"

Field::Field(int centerX, int centerY, int r, Biome::BiomeName b)
    :biome(b)
    ,hereStructure(Structure::Type::NONE)
    ,hereUnit(centerX, centerY,Unit::Type::NONE, 5)
    ,x(centerX)
    ,y(centerY)
{
    for (int i = 0; i < 6; i++)
    {
        float currentAngle = 60 * i;
        float x = r * sin(qDegreesToRadians(currentAngle));
        float y = r * cos(qDegreesToRadians(currentAngle));
        hexagon << QPointF(x+ centerX, y+ centerY);
    }
}

bool Field::isInside(int x, int y)
{
    return hexagon.containsPoint(QPoint(x, y),Qt::FillRule::OddEvenFill);
};
