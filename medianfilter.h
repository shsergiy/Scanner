#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H


#include "basefilter.h"

class Medianfilter : public BaseFilter {
public:
    Medianfilter();
    void Filter();
    ~Medianfilter(){}
private:
protected:

};

#endif // MEDIANFILTER_H
