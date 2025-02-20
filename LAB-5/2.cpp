#define MAX 5
#include<iostream>
#include<string>
using namespace std;
class Patient{
public:
int id;
string name;
string* results;
Patient(int id,string name,string results[]){
this->results= new string[MAX];
for(int i=0;i<MAX;i++){
this->results[i]=results[i];
}
}
Patient(const Patient& p){
id=p.id;
name=p.name;
for(int i=0;i<MAX;i++){
results[i]=p.results[i];
}
}
void display(){
cout << "id: " <<id<< endl;
cout << "name: " << endl;
for(int i=0;i<MAX;i++){
cout << "Result[" <<i+1<<"]:"<<results[i]<< endl;
}
}

void deallocatememory(){
delete[] results;
}

};
int main()
{
string result[MAX];
for(int i=0;i<MAX;i++){
cout << "Result" <<i+1<<": ";
cin >> result[i];
}
    Patient p(1234,"Jiyanshu Raj",result);
    Patient p2(p);
    p.display();
    p2.display();
    p.deallocatememory();
    p2.deallocatememory();
    return 0;
}
