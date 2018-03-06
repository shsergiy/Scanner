#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include <QMatrix4x4>
#include <point.h>
#include <vector>
#include <point.h>
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);

    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);
    bool ReadDataCheck ;
    bool NoiceCheck;
    bool AproximationCheck;
    std::vector<Point> Point_S;
    std::vector<Point> Point_B;
    std::vector<Point> DrawLines;
    Point Start,End;
private:

};

#endif // GLWIDGET_H
