#include "basefilter.h"
#include <string>


BaseFilter::BaseFilter(){}

BaseFilter::BaseFilter(int window){
    Window=window;
    Items = new int[window];
}
BaseFilter::BaseFilter(const BaseFilter & bf){
    Window=bf.Window;
    Items = new int[Window];
    Items = std::memcpy(Items,bf.Items,Window * sizeof *arr);

}
BaseFilter::operator =(const BaseFilter & bf){
    if(this == &bf)
        return *this;
    delete [] Items;
    Window=bf.Window;
    Items = new int [Window];
    return *this;

}
BaseFilter::~BaseFilter(){
    delete [] Items;
}

BaseFilter::SelectionSort(){

    int min_pos,temp;
      for (int i=0;i<Window-1;i++){
          min_pos=i;
              for (int j=i+1;j<Window;j++){
                  if (Items[j]<Items[min_pos])
                      min_pos=j;
              }
          if(min_pos !=i){
              temp=Items[i];
              Items[i]=Items[min_pos];
              Items[min_pos]=temp;
          }

      }
}
