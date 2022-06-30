#include <iostream>
#include<string.h>

using namespace std;

class Employee
{
private:
    int Id;
    char Name[20];
    int Salary;

public:
    Employee *pNext;
    Employee *pPrevious;
    void SetId(int i)
    {
        Id = i;
    }
    void SetName(char arr[20])
    {
        for (int i=0 ; i<21; i++)
        {
            Name[i] = arr[i];
        }
    }
    void SetSalary(int s)
    {
        Salary = s;
    }

    int GetId()
    {
        return Id;
    }
    char* GetName()
    {
        return Name;
    }
    int GetSalary()
    {
        return Salary;
    }

    void printEmployee()
    {
        cout << "\n Employee Id = " << GetId() << "         ";
        cout << "Employee Name = " << GetName() << "            ";
        cout << "Employee Salary = " << GetSalary() << endl;
    }

    Employee()
    {
        Id = Salary = 0;
        strcpy(Name," ");
    }

    Employee(int i , char* a , int j)
    {
        Id = i;
        strcpy(Name,a);
        Salary = j;
    }

    ~Employee (){}
};

class LinkedList
{
protected:
    Employee *pStart;
    Employee *pEnd;
    void addList(Employee *pItem)
    {
        if (!pStart) /* Case of empty list Add the first node */
        {
            pItem->pNext = NULL;
            pItem->pPrevious = NULL;
            pStart = pEnd = pItem;
        }
        else /* Case of existing list nodes Append Node */
        {
            pEnd->pNext = pItem;
            pItem->pPrevious = pEnd;
            pItem->pNext = NULL; pEnd = pItem;
        }
    }
public:
    LinkedList() {pStart=pEnd=NULL;}
    void insertList(Employee *pNode);
    Employee* searchList(int Code);
    int deleteList(int Code);
    void freeList();
    void displayAll();
    Employee* getFirst();
    Employee* getLast();
    ~LinkedList() {freeList();}
};
void LinkedList::insertList(Employee* pNode)
{
    Employee *ptemp;
    if(pStart==NULL) addList(pNode); // empty list
    else
    {
        ptemp=pStart;
        while(ptemp && ptemp ->GetId() < pNode->GetId() )
            ptemp= ptemp->pNext; // find its right location or reach the end
        if(!ptemp) addList(pNode); // it will be the last Node
        else if(ptemp==pStart) // it will be the first Node
         {
             pNode->pNext=pStart;
             pNode->pPrevious=NULL;
             pStart->pPrevious=pNode;
             pStart=pNode;
         }
         else // in any middle loaction
         {
             pNode->pNext=ptemp;
             pNode->pPrevious=ptemp->pPrevious;
             ptemp->pPrevious->pNext=pNode;
             ptemp->pPrevious=pNode;
         }
    }
}
Employee* LinkedList::searchList(int key) // sequential search
{
    Employee * pItem= NULL;
    pItem = pStart; // begin from the first node
    while(pItem && pItem->GetId() != key)
    {
        pItem = pItem->pNext;
    }
    if(pItem)
    {
        pItem->printEmployee();
        return pItem;
    }
    else
        cout << "This ID is not Exist....\n";
}
int LinkedList::deleteList(int Code)
{
    Employee *pItem;
    int RetFlag = 1;
    pItem = searchList(Code); // First search for it
    if (!pItem) { RetFlag = 0; } //Not found
    else
    { // Found
        if(pStart == pEnd) /* Case of one node */
        {
            pStart = pEnd = NULL;
        }
        else if(pItem == pStart) /* Case of first node */
        {
            pStart = pStart->pNext;
            pStart->pPrevious = NULL;
        }
        else if(pItem == pEnd) /* Case of last node */
        {
            pEnd = pEnd->pPrevious;
            pEnd->pNext = NULL;
        }
        else /* Case of intermediate node */
        {
            pItem->pPrevious->pNext = pItem->pNext;
            pItem->pNext->pPrevious = pItem->pPrevious;
        }
        delete pItem;
    }
    return RetFlag;
}
void LinkedList::freeList()
{
    Employee * pItem;
    while(pStart)
    {
        pItem = pStart;
        pStart = pStart->pNext;
        delete pItem;
    }
    pEnd = NULL;
}
void LinkedList::displayAll()
{
    Employee * pItem;
    pItem = pStart;
    while(pItem)
    {
        pItem->printEmployee();
        pItem = pItem ->pNext;
    }
}
Employee* LinkedList::getFirst()
{
    Employee* pItem;
    pItem = pStart;
    if(pStart)
    {
        if(pStart == pEnd)
            pStart = pEnd = NULL;
        else
        {
            pStart = pStart->pNext;
            pStart->pPrevious = NULL;
        }
    }
    return pItem;
}
Employee* LinkedList::getLast()
{
    Employee* pItem;
    pItem = pEnd;
    if(pEnd)
    {
        if(pStart == pEnd)
            pStart = pEnd = NULL;
        else
        {
            pEnd = pEnd->pPrevious;
            pEnd->pNext = NULL;
        }
    }
    return pItem;
}

int main()
{
    Employee Emp1(1, "Ahmed Ali", 1500), Emp2, Emp3(5, "Mohamed Khalid", 2200), Emp4(8, "Heba Hamad", 1700), Emp5(3, "Hager Nasser", 2000);
    LinkedList L;

    L.insertList(&Emp1);
    L.insertList(&Emp2);
    L.insertList(&Emp3);
    L.insertList(&Emp4);
    L.insertList(&Emp5);

    cout << "\nDisplay All Employee which exist in my Linked List ...";
    L.displayAll();

    cout << "\nSearching For Employee that its id = 2 ...";
    L.searchList(2);

    cout << "\nI Will Delete This Employee..";
    L.deleteList(0);

    cout << "\nAfter Deleting Employee that id = 0, Linked List Will be.." ;
    L.displayAll();

    cout << "\nAfter Getting First Employee and Remove him, Linked List Will be..";
    L.getFirst();
    L.displayAll();

    cout << "\nAfter Getting Last Employee and Remove him, Linked List Will be..";
    L.getLast();
    L.displayAll();

    cout << "\nAfter Free the Linked List.." << endl;
    L.freeList();
    L.displayAll();

    return 0;
}
