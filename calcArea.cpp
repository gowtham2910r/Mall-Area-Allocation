#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int find_area()
{
      ifstream file;
      file.open("area.txt",ios::in);
      while(true){
            string name;
            int reqarea;
            file>>name;
            file>>reqarea;
            if(file.eof())break;
            //cout<<name<<" "<<reqarea;
            if(reqarea>1000)
                  reqarea=1000;
            int count=0;
              int area;
              if(count<5)
              {
                      area=reqarea;
                      count++;
              }
              else if(count<10)
              {
                      area=(4*reqarea)/5;
                      count++;
              }
              else if(count<15)
              {
                      area=(3*reqarea)/5;
                      count++;
              }
              else if(count<20)
              {
                      area=reqarea/2;
                      count++;
              }
              else{
                      area = 2*reqarea/5;
              }
              file2<<name<<" "<<area<<endl;
      }

}
int main()
{
        find_area();

}
