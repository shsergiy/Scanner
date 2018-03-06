#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        virtual ~Point();
        Point(int,int,double);
        int get_x() const;
        int get_y() const;
        double get_angle() const;
        void set_x(int);
        void set_y(int);
        void set_angle(double);
        bool operator <(const Point&) const;
    protected:

    private:
        int Coordinate_X,Coordinate_Y;
        double Angle;
};

#endif // POINT_H
