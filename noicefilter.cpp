#include "noicefilter.h"
#include <math.h>
#include <algorithm>
using namespace  std;

Noicefilter::Noicefilter(){}

void Noicefilter::setParameters(string path,int window){
    string Path = path;
    Window =window;
    ReadData(Path);
}
void Noicefilter::ReadData(std::string Path){
    char buffer[30];
    string temp,angle,dis="null";
    ifstream in(Path.c_str());
     if(!in) {
       cout << "Cannot open input file.\n";
    }
    char *endch,*endch2;
    while(!in.eof()){
        in.getline(buffer,30);
        temp = buffer;
       if(!in.eof()){
        endch2 = strchr(buffer,',');
        angle = temp.substr(6,endch2-buffer-6);
        endch = strchr(buffer,';');
        dis = temp.substr(endch2-buffer+6,endch-buffer-(endch2-buffer+6));
        ConvertToxy(atof(angle.c_str()),atoi(dis.c_str()));
        }
    }
    in.close();

 }
std::vector<Point>& Noicefilter::get_Points(){
    return Points;
}
void Noicefilter::ConvertToxy(double Angle,int Distance){
    Point tempPoint(Distance*cos(Angle*3.14/180),Distance*sin(Angle*3.14/180),Angle);
    Points.push_back(tempPoint);
}
void Noicefilter::SelectionSort(vector<double> & WindowPoints){
      double min_pos,temp;
      for (int i=0;i<Window-1;i++){
          min_pos=i;
              for (int j=i+1;j<Window;j++){
                  if (WindowPoints[j]<WindowPoints[min_pos])
                      min_pos=j;
              }
          if(min_pos !=i){
              temp=WindowPoints[i];
              WindowPoints[i]=WindowPoints[min_pos];
              WindowPoints[min_pos]=temp;
          }

      }
}
void Noicefilter::MedianaFilter(){

    unsigned int step =0;
    std::vector<double> PointX;
    std::vector<double> PointY;
    std::vector<double> PointAng;
    while (step+Window != Points.size()){
        for (int i=0;i<Window;i++)
        {
            PointX.push_back(Points[step+i].get_x());
            PointY.push_back(Points[step+i].get_y());
            PointAng.push_back(Points[step+i].get_angle());
        }
        SelectionSort(PointX);
        SelectionSort(PointY);
        SelectionSort(PointAng);
        Point tempPoint(PointX[Window/2],PointY[Window/2],PointAng[Window/2]);
        Points[step]=tempPoint;
        PointX.clear();
        PointY.clear();
        PointAng.clear();
        step++;
        }
    for (int i=0;i<Points.size();i++)
        std::cout<< Points[i].get_angle()<<endl;

}
void Noicefilter::SortPointsByY(vector<Point> & Vector1){
    sort(Vector1.begin(), Vector1.end(),
        [](const Point & a, const Point & b) -> bool
    {
        return a.get_angle() > b.get_angle();
    });
}
std::vector<Point> Noicefilter::ArrayOfPoints(){

    vector<Point> vec;
    DetectCrashPoints(0,Points.size()-1);
    vec =DrawPoints;
    vec.insert(vec.begin(),Points[0]);
    vec.push_back(Points[Points.size()-1]);
    for (int i=0;i<vec.size();i++)
        cout <<vec[i].get_angle()<<" "<<endl;

   SortPointsByY(vec);
    return vec;
}
void Noicefilter::DetectCrashPoints(int s,int e){


    int start=s,end=e;

     double A=0.0,B=0.0,C=0.0;

    A=Points[start].get_y()-Points[end].get_y();
    B=Points[end].get_x()-Points[start].get_x();
    C=Points[start].get_x()*Points[end].get_y()-Points[end].get_x()*Points[start].get_y();

    int MaxIndex=0;
    double MaxDistance=0.0,Distance=0.0;

    for (int i=0;i<Points.size();i++){
        Distance=abs(A*Points[i].get_x()+B*Points[i].get_y()+C)/sqrt(pow(A,2)+pow(B,2));
            if(MaxDistance<Distance && Points[start].get_angle()<=Points[i].get_angle() && Points[end].get_angle()>=Points[i].get_angle()){
                MaxIndex=i;
                MaxDistance=Distance;
            }
     //cout<<Points[i].get_x()<<" "<<Points[i].get_y()<<" "<<MaxIndex<<endl;
    //cout<<Distance<<endl;
    }

    if (MaxDistance>20 && Points[start].get_angle()<Points[MaxIndex].get_angle() && Points[end].get_angle()>Points[MaxIndex].get_angle()){

      DetectCrashPoints(start,MaxIndex);
      DetectCrashPoints(MaxIndex,end);
      cout<<"--------------"<<Points[MaxIndex].get_x()<<" "<<Points[MaxIndex].get_y()<<" "<<MaxIndex<<endl;
      DrawPoints.push_back(Points[MaxIndex]);

    }


    }
void Noicefilter::AveregeGeometric(){
   int step=0;
   double AveregeX=1,AveregeY=1;
   while (step+Window!=Points.size()){
       for (int i=0;i<Window;i++){
           AveregeX*=Points[step+i].get_x();
           AveregeY*=Points[step+i].get_y();
       }                                                            //todo
       cout <<AveregeX<<" "<<AveregeY<<endl;
       //Point tempPoint(pow(AveregeX,1.0/Window),pow(AveregeY,1.0/Window));
     //  Points[step]=tempPoint;
       cout <<pow(AveregeX,1.0/7)<<" "<<pow(AveregeY,1.0/7)<<endl;
       AveregeX=1;AveregeY=1;
       step++;
   }
}
void Noicefilter::LinerRegresion(Point &Start,Point &End){
    int n=Points.size();
    double Sx=0,Sy=0,Sxy=0,Sxx=0;
    double a,b;
    for(int i=0; i < n; i++){
  //      cout<<Points[i].get_x()<<" "<<Points[i].get_y()<<endl;
     Sx+=Points[i].get_x();
     Sy+=Points[i].get_y();
     Sxy+=Points[i].get_x()*Points[i].get_y();
     Sxx+=Points[i].get_x()*Points[i].get_x();
    }
    Sx/=n;
    Sy/=n;
    Sxy/=n;
    Sxx/=n;
    a=(Sx*Sy-Sxy)/(Sx*Sx-Sxx);
    b=(Sxy-a*Sxx)/Sx;

    sort(Points.begin(),Points.end());

    Start.set_x(Points.begin()->get_x());
    Start.set_y(Points.begin()->get_x()*a+b);
    End.set_x(Points[Points.size()-1].get_x());
    End.set_y(Points[Points.size()-1].get_x()*a+b);

    //cout<<Points.begin()->get_x()<<" "<<Points.begin()->get_x()*a+b<<endl;
    //cout<<Points[Points.size()-1].get_x()<<" "<<Points[Points.size()-1].get_x()*a+b<<endl;
}
