#include<iostream>
#include<string>
using namespace std;
class Car{
public:
string rnum;
string modelName;
string ownerName;

Car(string rnum,string modelName,string ownerName){
this->rnum=rnum;
this->modelName=modelName;
this->ownerName=ownerName;
}
Car(const Car& c){
rnum=c.rnum;
modelName=c.modelName;
cout << "Enter car owner name: ";
cin >> ownerName;
}
void display(){
cout << "Registration number: "<<rnum << endl;
cout << "Model Name: "<<modelName << endl;
cout << "owner model Name:" <<ownerName<< endl;
}
};
int main()
{
    Car c1("AVV-598","2019","Jiyanshu Raj");
    Car c2(c1);
    c1.display();
    c2.display();
    
    return 0;
}
