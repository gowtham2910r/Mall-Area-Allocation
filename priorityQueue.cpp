#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class node
{
      public:
        string name;
        int area;
        int priority;
        node *next;
        node(){
            area=0;
            name="";
            priority=0;
            next=NULL;
        }
};
node* front=NULL;
void insertpq(string name,int priority,int area)
{
        node *temp;
        temp=new node;
        temp->name=name;
        temp->priority=priority;
        temp->area=area;
        if(front==NULL||priority > front->priority)
        {
                temp->next=front;
                front=temp;
        }
        else{
                node *prev,*ptr;
                ptr=front->next;
                prev=front;
                while(ptr!=NULL&&prev->next->priority>priority)
                {
                        ptr=ptr->next;
                        prev=prev->next;
                }
                prev->next=temp;
                temp->next=ptr;
                temp->next=ptr;
        }
}
void remove()
{
        ofstream file;
        file.open("area.txt",ios::app);
        while(front!=NULL){
            node*temp;
            temp=front;
            front=front->next;
            file<< temp->name <<" "<< temp->area<<endl;
        }
        file.close();
}
int main(){
      string name;
      int priority;
      int req_area;
      ifstream file;
      file.open("priorities.txt",ios::in);
      while(true){
            file>>name;
            file>>priority;
            file>>req_area;
            if(file.eof())break;
            //cout<<name<<" "<<priority<<" "<<req_area<<endl;
            insertpq(name, priority, req_area);
      }
      remove();

}
