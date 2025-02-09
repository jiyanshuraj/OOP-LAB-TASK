#include<iostream>
using namespace std;
int* AllocateMemory(int size){
    int* arr= new int[size];
}

void inputUser(int* arr,int size){
    for (int i = 0; i <size; i++)
    {
        cout<<"arr["<<i+1<<"]: ";
        cin>>arr[i];
    }
}
void displayInfo(int* arr,int size){
    int max=0,sum=0;
    for (int i = 0; i <size; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
        sum+=arr[i];   
    }
    cout<<"Sum. "<<sum<<endl;
    cout<<"Average. "<<sum/size<<endl;
    cout<<"Max. "<<max<<endl;  
}

void Deallocate(int* arr){
    delete[] arr;
}

int main()
{
int size;
cout<<"Enter Size of an array: ";
cin>>size;
int* arr= AllocateMemory(size);
inputUser(arr,size);
displayInfo(arr,size);
Deallocate(arr);
return 0;
}
