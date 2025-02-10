
#include<iostream>
using namespace std;
class MarkerPen{
private:
string  brand;
string colour;
int inkLevel;
bool refilibility;
public:
MarkerPen(string b,string c,int il,bool r):brand(b),colour(c),inkLevel(il),refilibility(r){}
void checkstatus(){
cout << "brand. " <<brand<< endl;
cout << "colour.  " <<colour<<endl;
cout << "ink Level. " <<inkLevel<< endl;
cout << "refilibility" <<(refilibility? "yes": "No")<<endl;
}
void write(){
if(inkLevel>0){
inkLevel--;
cout << "write....." << endl;
}
else{
cout << "Please refill" << endl;
}

}
void refill(){
if(refilibility){
inkLevel =100;
cout << "marker refilled" << endl;
}
else{
cout << "cannot be refilled" << endl;
}
}
};
int main(){
MarkerPen mp("Dollar","Blue",2,true);
mp.checkstatus();
mp.write();
mp.write();
mp.checkstatus();
mp.refill();
mp.checkstatus();
return 0;
}
