#ifndef BASEFILTER_H
#define BASEFILTER_H



class BaseFilter
{
public:
    BaseFilter();
    BaseFilter(int);
    BaseFilter(const BaseFilter & );
    virtual void Filter(BaseFilter &) =0;
    void SelectionSort();
    virtual ~BaseFilter();
    BaseFilter & operator=(const BaseFilter & );
private:
    int Window;
    int * Items;
protected:
};




#endif // BASEFILTER_H
