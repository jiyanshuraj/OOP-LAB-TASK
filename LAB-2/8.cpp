#include<iostream>
using namespace std;
struct Student{
    string name;
    int rollno;
    int marks;
};
Student* AllocateMemory(int size){
    return new Student[size];
}

void inputUser(Student* stud,int size){
  for (int i = 0; i <size; i++)
  {
    cout<<"Name: ";
    cin>>stud[i].name;
    cout<<"Roll No: ";
    cin>>stud[i].rollno;
    cout<<"Marks: ";
    cin>>stud[i].marks;
  }
}
void DisplayHighest(Student* stud,int size){
    int high =0;
    int count = 0;
    for (int i = 0; i <size; i++)
    {
        if (stud[i].marks>high)
        {
            high = stud[i].marks;
            count=i;
        }
        
    }
    cout<<"Student with highest marks is. "<<endl;
    cout<<"Name. "<<stud[count].name<<endl;
cout<<"Roll No: "<<stud[count].rollno<<endl;
cout<<"Marks: "<<stud[count].marks<<endl;
}

void DeAllocate(Student* stud){
    delete[] stud;
}
int main()
{
int size;
cout<<"Enter No. of Student: ";
cin>>size;
Student* Stud = AllocateMemory(size);
inputUser(Stud,size);
DisplayHighest(Stud,size);
DeAllocate(Stud);


return 0;
}
