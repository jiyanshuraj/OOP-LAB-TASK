#include<iostream>
using namespace std;
void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* AllocateNum(){
    int* num = new int;
    return num; 
}
int* AllocateArray(int size){
    int* arr = new int[size];
    return arr;
}

void inputUser(int* arr,int size){
    for (int i = 0; i <size; i++)
    {
        cout<<"Arr["<<i+1<<"]: ";
        cin>>arr[i];
    } 
}

void reverse(int* arr, int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        Swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}
void DeAlloocateArray(int* arr){
    delete[] arr;
}

void deallocateInt(int* arr){
    delete arr;
}

int main()
{
int* a = AllocateNum();
int* b = AllocateNum();
cout<<"Enter a: ";
cin>>*a;
cout<<"Enter b: ";
cin>>*b;
int size;
cout<<"Enter Size of Array: ";
cin>>size;
int* arr = AllocateArray(size);
cout<<"The value of A beore Swap is. "<<*a<<endl;
cout<<"The value of B beore Swap is. "<<*b<<endl;
swap(a,b);
cout<<"The value of A after Swap is. "<<*a<<endl;
cout<<"The value of B after Swap is. "<<*b<<endl;
inputUser(arr,size);
reverse(arr,size);
cout<<"Revere is. "<<endl;
for (int i = 0; i <size; i++)
{
    cout<<"arr["<<i+1<<"]: "<<arr[i]<<endl;
}
deallocateInt(a);
deallocateInt(b);
DeAlloocateArray(arr);
return 0;
}
