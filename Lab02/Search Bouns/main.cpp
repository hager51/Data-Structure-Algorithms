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
    void operator=(Employee s1);
    void Swap(Employee& x, Employee& y);
    int sequential_search(int n, Employee* s, int num);
    int Binary_search(int n, Employee* s, int num);
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
void Employee::Selection_Sort(int n, Employee *s)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(s[i].Emp_id > s[j].Emp_id) Swap(s[i],s[j]);
        }
    }
}
int Employee::sequential_search(int n, Employee* s, int num)
{
    int i= 0, found = 0;
    while ((!found) && (i< n))
    {
        if (num == s[i].Emp_id)
            found = 1;
        else
            i++;
    }
    if (found)
        return i;
    else
        return -1;
}

int Employee::Binary_search(int n, Employee* s, int num)
{
    Selection_Sort(n, s);
    int found = 0;
    int high = n ;
    int low = 0;
    int mid;
    while ((!found) && (low <= high ))
    {
        mid = (high + low) / 2;
        if (s[mid].Emp_id > num)
            high = mid - 1; // go right
        else if (s[mid].Emp_id < num)
            low = mid + 1; // go left
        else
            found = 1;
    }
    if (found) return mid;
    else return -1;
}

int main()
{
    int ch, SearchNum;
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
        cout<<"\n 4. Sequential Search in Data using ID ";
        cout<<"\n 5. Binary Search in Data using ID ";
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
                s->Selection_Sort(n, s);
                cout<<"\n Data is Sorted using Selection Sort\n";
                break;
            case 4:
                cout << "Enter the number you search for : " ;
                cin >> SearchNum;
                s->sequential_search(n, s, SearchNum);
                cout<<"\n Sequential Search index : "<<s->sequential_search(n, s, SearchNum) << endl;
                break;
            case 5:
                cout << "Enter the number you search for : " ;
                cin >> SearchNum;
                s->Binary_search(n, s, SearchNum);
                cout<<"\n Binary Search index : " << s->Binary_search(n, s, SearchNum) << endl;
                break;
            case 6:
                exit(0);
            default:
                cout<<"\n Invalid Choice . . .";
        }
    }

    return 0;
}
