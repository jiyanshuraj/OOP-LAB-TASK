#include<iostream>
using namespace std;
class Battery{
    int MAh;
    public:
    Battery(int mah):MAh(mah){}
    void Display(){
        cout<<"BATTERY: "<<MAh<<endl;
    }
};
class SmartPhone{
    int model;
    Battery b;
    public:
    SmartPhone(int m,Battery b):model(m),b(b){}
    void display(){
        b.Display();
        cout<<"MODEL: "<<model<<endl;
    }
};
int main()
{
SmartPhone SP(5000,2019);
SP.display();
return 0;
}
