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
void display(string name[],int row){
    for (int i = 0; i <row; i++)
    {
       cout<<"Name["<<i+1<<"] = "<<name[i]<<endl;
    }
    
}
bool attendence_checker(string name1[],string name2[],int row,string searchName){
    for (int  i = 0; i < row; i++)
    {
      if(name1[i]==searchName || name2[i]==searchName){
       return true;
      }  
    }
    return false;
}
int total_donnation(int max_input1,int max_input2){
    const int max_donation = 10;
   return max_donation*(max_input1+max_input2);
}
int main()
{
const int row = 5;
string name1[row];
string name2[row];
cout<<"Enter Name of participants for event 1:"<<endl;
inputuser(name1,row);
cout<<"Enter Name of participants for event 2:"<<endl;
inputuser(name2,row);
cout<<"Displaying the names of participants for event 1"<<endl;
display(name1,row);
cout<<"__________________________________________"<<endl;
cout<<"Displaying the names of participants for event 2"<<endl;
display(name2,row);
string searchname;
cout<<"Enter Name you want to search: "<<endl;
getline(cin,searchname);
bool ac=attendence_checker(name1,name2,row,searchname);
if (ac==true)
{
    cout<<"Name is Registered"<<endl;
}
else
{
    cout<<"NON-REGISTERED"<<endl;
}
cout<<"total donation = "<<total_donnation(row,row)<<endl;

return 0;
}
