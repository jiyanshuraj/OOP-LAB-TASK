#define MAX 5
#include<iostream>
#include<string>
using namespace std;
class TravelGuidde{
    public:
    string Name;
    int yearOfExperience;
    string Specialization;
    void Assign(){
        cout<<"Name: ";
        cin>>Name;
        cout<<"Years of Experience: ";
        cin>>yearOfExperience;
        cout<<"Specialization: ";
        cin>>Specialization;
    }
   void display(){
    cout<<"NAME. "<<Name<<endl;
    cout<<"YEAR OF EXPERIENCE. "<<yearOfExperience<<endl;
    cout<<"SPECIALIZATION. "<<Specialization<<endl;
   }
   
};

class TravelAgency{
    TravelGuidde* tg;
    public:
    void Assign(TravelGuidde* tg[],int* size){
       if (*size<MAX)
       {
        tg[*size]->Assign();
        cout<<"Trave Guide Assigned"<<endl;
        (*size)++;
       }  
    
    else
    {
        cout<<"Invalid!"<<endl;
    } 
}
void Display(TravelGuidde* tg[],int size){
    for (int  i = 0; i <size; i++)
    {
        tg[i]->display();
    }
} 
void Dealocate(){
    delete[] tg;
}
};

TravelGuidde* AllocateMemory(int size){
    return new TravelGuidde[size];
}

int main()
{
int size = 0;
TravelGuidde* tg= AllocateMemory(MAX);
TravelAgency ta;
ta.Assign(&tg,&size);
ta.Display(&tg,size);
ta.Dealocate();
return 0;
}
