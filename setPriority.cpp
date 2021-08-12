#include<iostream>

#include<string>
#include<fstream>
using namespace std;
int main()
{
        int priority=0;
        int date;
        int month;
        int year;
        int hr,min,sec;
        int rating;
        int base_date = 11;
        int base_month = 4;
        int base_year = 2019;
        int req_area;
        fstream file;
        file.open("data.txt",ios::in);
        string type;
        string name;
        file>>name;
        file>>type;
        file>>rating;
        file>>date;
        file>>month;
        file>>year;
        file>>req_area;

        if(type=="food")
        {
                priority=9;
        }
        else if(type=="accessories")
        {
                priority=6;
        }
        else if(type=="fashion")
        {
                priority=7;
        }
        else if(type=="footwear")
        {
            priority=8;
        }
        else if(type=="others")
        {
                priority=5;
        }

//      cout<<priority<<endl;
        priority+=rating;
//      cout<<priority<<endl;

        //cout<<"Current system date is "<< ltm->tm_mday<<"/"<<1 + ltm->tm_mon<<"/"<<1900 + ltm->tm_year<<endl;
        if((year-base_year>0))
        {
                priority+=2;
        }
        else if(month-base_month > 8)
        {
                priority+=4;
        }
        else if(month-base_month > 4){
                priority+=6;
        }
        else if(month-base_month > 0){
               priority+=8;
        }
        else if(date-base_date > 15){
              priority+=9;
        }
        else{
              priority+=10;
        }
        file.close();
        //cout<<type<<" "<<rating<<" "<<date<<"/"<<month<<"/"<<year<<endl;
        ofstream file2;
        file2.open("priorities.txt",ios::app);
        file2<<name<<" "<<priority<<" "<<req_area<<endl;
        return 0;
}
