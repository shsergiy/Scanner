#ifndef GLWIGET_H
#define GLWIGET_H
#include <QGLWidget>

class GlWiget
{
    Q_OBJECT
public:
   explicit GlWiget(QWidget *parent=0);
    void initGL();
    void paintGL();
    void resizeGL(int w,int h);



};

#endif // GLWIGET_H
