#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
using namespace std;

class Employee
{
    int Emp_id;
    char name[20];
    float salary;
public:
    Employee(){}
    void accept()
    {
            cout<<"\n Enter Employee Id : ";
            cin>>Emp_id;
            cout<<"\n Enter Employee Name : ";
            cin>>name;
            cout<<"\n Enter Employee Salary : ";
            cin>>salary;
    }
    void display();
    void Selection_Sort(int n, Employee *s);
    void Bubble_Sort(int n, Employee *s);
    void Insertion_Sort(int n, Employee* s);
    void operator=(Employee s1);
    void Swap(Employee& x, Employee& y);
};
void Employee::operator=(Employee s1)
{
    Emp_id = s1.Emp_id;
    strcpy(name,s1.name);
    salary = s1.salary;
}
void Employee::display()
{
    cout<<"\n Staff Id : "<<Emp_id;
    cout<<"\n Name : "<<name;
    cout<<"\n Salary : "<<salary<<"\n";
}
void Employee::Swap(Employee& x, Employee& y)
{
    Employee temp;
    temp = x;
    x = y;
    y = temp;
}
void Employee::Selection_Sort(int n, Employee *s)  //Function for selection sorting the data by employee ID
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(s[i].Emp_id > s[j].Emp_id)
            {
                    Swap(s[i],s[j]);
            }
        }
    }
}
void Employee::Bubble_Sort(int n, Employee *s)  //Function for bubble sorting the data by employee ID
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (s[j].Emp_id < s[j+1].Emp_id)
            {
                Swap(s[j],s[j+1]);
            }
        }
    }
}
void Employee::Insertion_Sort(int n, Employee* s)  //Function for Insertion sorting the data by employee ID
{
    int i, j;
    Employee value;
    for(i = 1; i < n; i++)
    {
        value = s[i];
        j = i - 1;
        while (j >= 0 && s[j].Emp_id > value.Emp_id)
        {
            s[j + 1] = s[j];
            j = j -1;
        }
        s[j + 1] = value;
    }
}

int main()
{
    int ch;
    Employee *s;
    int n;
    cout<<"\n Enter No.of Records You Want : ";
    cin>>n;
    s = new Employee[n];
    while(ch!=6)
    {
        cout<<"\n 1. Accept Data ";
        cout<<"\n 2. Display Data ";
        cout<<"\n 3. Selection Sort Data by ID ";
        cout<<"\n 4. Bubble Sort Data by ID ";
        cout<<"\n 5. Insertion Sort Data by ID ";
        cout<<"\n 6. Exit ";
        cout<<"\n\n Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                for(int i=0; i<n; i++)
                {
                        cout<<"\n\n Enter Data for Employee " <<i+1<<"\n";
                        s[i].accept();
                }
                break;
            case 2:
                for(int i=0; i<n; i++)
                {
                        s[i].display();
                }
                break;
            case 3:
                s->Selection_Sort(n, s);  //Passing parameter to Selection Sort function
                cout<<"\n Data is Sorted using Selection Sort\n";
                break;
            case 4:
                s->Bubble_Sort(n, s);  //Passing parameter to Bubble Sort function
                cout<<"\n Data is Sorted using Bubble Sort\n";
                break;
            case 5:
                s->Insertion_Sort(n, s);  //Passing parameter to Insertion Sort function
                cout<<"\n Data is Sorted using Insertion Sort\n";
                break;
            case 6:
                exit(0);
            default:
                cout<<"\n Invalid Choice . . .";
        }
    }

    return 0;
}
