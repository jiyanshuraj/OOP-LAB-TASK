
#include<iostream>
#include<string>
using namespace std;
void inputuser(string name[],int row){
    for (int i = 0; i <row; i++)
    {
      cout<<"Name["<<i+1<<"]: ";
      getline(cin,name[i]);
    }
    
}
int main()
{
const int row = 5;
string name1[5];
string name2[5];
cout<<"Enter Name of participants for event 1:"<<endl;
inputuser(name1,row);
cout<<"Enter Name of participants for event 2:"<<endl;
inputuser(name2,row);
return 0;
}
