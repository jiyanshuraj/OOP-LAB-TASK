#include<iostream>
#include<string>
using namespace std;
struct Student{
    string name;
    int rollno;
    int marks[5];
};

Student* AllocateMemory(int size){
    return new Student[size];
}

void inputUser(Student* stud,int size){
    for (int i = 0; i <size; i++)
    {
        cout<<"Enter Name: ";
        cin>>stud[i].name;
        cout<<"Enter ROll No: ";
        cin>>stud[i].rollno;
        for (int j = 0; j <5 ; j++)
        {
            cout<<"Marks["<<i+1<<"]["<<j+1<<"]: ";
            cin>>stud[i].marks[j];
        }
        
    }
    
}

void calculate(Student* Stud,int size){
    char grade;
    for (int i = 0; i <size; i++)
    {
            int sum=0;
      for (int j = 0; j <5; j++)
      {
        sum+=Stud[i].marks[j];
      }
      int avg = sum/5;
      if (avg>90)
      {
        grade = 'A';
      }
      else if (avg>80)
      {
        grade = 'B';
      }
      else if (avg>70)
      {
        grade = 'C';
      }
      else if(avg>60){
        grade = 'D';
      }
      else
      {
        grade = 'F';
      }
      cout<<"Sum. "<<sum<<endl;
      cout<<"Average. "<<avg<<endl;
      cout<<"Grade. "<<grade<<endl;
      cout<<"-------------------------"<<endl;
      
      }
    }

void DeAllocate(Student* stud){
    delete[] stud;
}  

int main()
{
int size;
cout<<"Enter No. of students: ";
cin>>size;
Student* stud = AllocateMemory(size);
inputUser(stud,size);
calculate(stud,size);
DeAllocate(stud);
return 0;
}
