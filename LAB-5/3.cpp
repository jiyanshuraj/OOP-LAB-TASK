#define MAX 5
#include<iostream>
#include<string>
using namespace std;
class Professor{
    public:
    string Name;
    string Department;
    void Add(){
        cout<<"Enter Name: ";
        cin>>Name;
        cout<<"Enter Department: ";
        cin>>Department;
    }
    void Display(){
        cout<<"Name: "<<Name<<endl;
        cout<<"Department: "<<Department<<endl;
    }
};

class University{
    Professor* p;
    public:
    void Add(Professor* p[],int* size){
        if (*size<MAX)
        {
            p[*size]->Add();
            cout<<" Professor Added "<<endl;
            (*size)++;
        }
        else
        {
            cout<<"Invalid!"<<endl;
        }
        
    }

    void Display(Professor* p[],int size){
     for (int i = 0; i < size; i++)
     {
        p[i]->Display();
     }
     
    }
    void Dealloccate(){
        delete[] p;
    }
};

Professor* allocateMemory(int size){
    return new Professor[size];
}
int main()
{
int size = 0;
Professor* p1=allocateMemory(MAX);
University u;
u.Add(&p1,&size);
u.Add(&p1,&size);
u.Add(&p1,&size);
u.Add(&p1,&size);
u.Add(&p1,&size);
u.Display(&p1,size);
u.Dealloccate();
return 0;
}
