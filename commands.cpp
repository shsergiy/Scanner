#include "commands.h"

Commands::Commands()
{

}
void Commands::Kmeans(){}//todo
void Commands::LinerAprocsimation(){}//todo
void Commands::ReadData(string Path,vector<Point> &Points){
    char buffer[30];
       string temp,angle,dis="null";
       ifstream in(Path.c_str());
        if(!in) {
          cout << "Cannot open input file.\n";
       }
       char *pch, *endch ;
       while(!in.eof()){
           in.getline(buffer,30);
           temp = buffer;
          if(!in.eof()){
           angle = temp.substr(6,4);
           //pch= strchr(buffer,'=');
           //pch=strchr(pch+1,'=');
           endch = strchr(buffer,';');
           dis = temp.substr(16,endch-buffer-16);
           ConvertToOxy(atof(angle.c_str()),atoi(dis.c_str()),Points);
           }
       }
       in.close();
}
void Commands::SelectionSort(int *arr,int n){

    int min_pos,temp;

      for (int i=0;i<n-1;i++){
          min_pos=i;
              for (int j=i+1;j<n;j++){
                  if (arr[j]<arr[min_pos])
                      min_pos=j;
              }
          if(min_pos !=i){
              temp=arr[i];
              arr[i]=arr[min_pos];
              arr[min_pos]=temp;
          }

      }

}
void Commands::ConvertToOxy(double Angle,int Distance,vector<Point> & Points){

    int tempX,tempY;

              tempX= Distance * cos(Angle*3.14f/180);
              tempY= Distance * sin(Angle*3.14f/180); // some fail with the Pi = 3.14 an math function
              Point tempPoint(tempX,tempY);
              Points.push_back(tempPoint);

}
void Commands::NoiceIllimination(vector<Point> & Points, vector<Point> &AfterIliminationPoints){

        int step=0;
        int n=7;
        int MedianaX,MedianaY;
        int *PointsX = new int[n];
        int *PointsY = new int[n];
        while(step+7 != Points.size()){
            for(int i=0;i<n;i++){
                PointsX[i]=Points[step+i].get_x();
                PointsY[i]=Points[step+i].get_y();
            }
            SelectionSort(PointsX,n);
            SelectionSort(PointsY,n);
            MedianaX=PointsX[3];
            MedianaY=PointsY[3];
            Point tempPoint(MedianaX,MedianaY);
            AfterIliminationPoints.push_back(tempPoint);
            step++;
    }


}
