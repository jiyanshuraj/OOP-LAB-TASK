#include<iostream>
#include<string>
using namespace std;
class Movie{
    string Title;
    string director;
    float Duration;
    public:
    Movie(){
        Title  = " ";
        director = " ";
        Duration = 0.00;
    }
    Movie(string t,string d,float dur):Title(t),director(d),Duration(dur){}
   
    void Display(){
        cout<<"Title: "<<Title<<endl;
        cout<<"Drector: "<<director<<endl;
        cout<<"Duration: "<<Duration<<endl;
    }
};
class CinemaHall{
    Movie m[100];
    public:
    void display(Movie m[],int size){
        for (int i = 0; i <size; i++)
        {
            m[i].Display();
        }
        
    }
};
int main()
{
Movie m1("K3G","Karan Johar",125.32);
Movie m2("KGF CHAPTER-1","Prashant Neel",125.36);
Movie m[]={m1,m2};
int size = sizeof(m)/sizeof(m[0]);
CinemaHall ch;
ch.display(m,size);
return 0;
}
