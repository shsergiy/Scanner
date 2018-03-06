#include "glwidget.h"
#include <algorithm>
#include <iostream>
GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    this->ReadDataCheck=false;
    this->NoiceCheck=false;
    this->AproximationCheck=false;
}
void GLWidget::initializeGL()
{
    glClearColor(0.87, 0.85, 0.87, 1);


}
void AfterIllumination(Point value){
    glPointSize(2);
    glBegin(GL_POINTS);
        glColor3d(0,0,1);
        glVertex3d(value.get_x()*0.001,value.get_y()*0.001,0);
     glEnd();


}
void DrawLine(Point Start,Point End){
    std::cout<<"x1 ="<<Start.get_x()<<" , "<<"y1 ="<<Start.get_y()<<" , "<<"x2 ="<<End.get_x()<<" , "<<"y2 ="<<End.get_y()<<" ;"<<std::endl;
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3d(0,1,0);
    glVertex3d(Start.get_x()*0.001,Start.get_y()*0.001,0);
    glVertex3d(End.get_x()*0.001,End.get_y()*0.001,0);
    glEnd();
}
void AfterKmeans(Point value){
    //todo kmeans drawing
}
void BeforIllumination(Point value){
    glPointSize(2);
    glBegin(GL_POINTS);
        glColor3d(1,0,0);
        glVertex3d(value.get_x()*0.001,value.get_y()*0.001,0);
     glEnd();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
        if (ReadDataCheck)
    {
            std::for_each (Point_S.begin(),Point_S.end(),BeforIllumination);
          if(NoiceCheck)
            {
              std::for_each(Point_B.begin(),Point_B.end(),AfterIllumination);
                if(AproximationCheck)
                {
                    for (int i=0;i<DrawLines.size()-1;i++)
                         DrawLine(DrawLines[i],DrawLines[i+1]);
                }
            }
    }

}

void GLWidget::resizeGL(int w,int h)
{
    glViewport(0,0,w,h);
}

