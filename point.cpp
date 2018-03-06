#include "point.h"

Point::Point(){Coordinate_X=0;Coordinate_Y=0;Angle=0;}

Point::Point(int x , int y ,double ang){
    Coordinate_X=x;
    Coordinate_Y=y;
    Angle=ang;
}
Point::~Point(){

}
bool Point::operator <(const Point& p) const {
    return (Coordinate_X< p.Coordinate_X);
}
int Point::get_x() const {
    return Coordinate_X;
}
int Point::get_y() const
{
    return Coordinate_Y;
}
void Point::set_x(int x){
    Coordinate_X=x;
}
void Point::set_y(int y){
    Coordinate_Y=y;

}
double Point::get_angle() const {
    return Angle;
}
 void Point::set_angle(double ang){
    Angle=ang;
}
