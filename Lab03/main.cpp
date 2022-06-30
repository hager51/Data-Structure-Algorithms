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
    void SetId(int i) {Id = i;}
    void SetName(char arr[20])
    {
        for (int i=0 ; i<21; i++)
            Name[i] = arr[i];
    }
    void SetSalary(int s) {Salary = s;}
    int GetId() {return Id;}
    char* GetName() {return Name;}
    int GetSalary() {return Salary;}
    void printEmployee()
    {
        cout << "\nEmployee Id = " << GetId() << "          ";
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
void LinkedList ::  insertList(Employee* pNode)
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
        pItem = pItem->pNext;
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

class Queue : private LinkedList
{
public:
    Queue():LinkedList(){}
    void enQueue(Employee* e){LinkedList::addList(e);}
    Employee* deQueue(){LinkedList::getFirst();}
    Employee* searchQueue(int Key){return LinkedList::searchList(Key);}
    int deleteQueue(int Code){return LinkedList::deleteList(Code);}
    void freeQueue(){LinkedList::freeList();}
    void displayQueue(){LinkedList::displayAll();}
    ~Queue(){}
};

class Stack : private LinkedList
{
public:
    Stack():LinkedList(){}
    void push(Employee* e){LinkedList::addList(e);}
    Employee* pop(){LinkedList::getLast();}
    Employee* searchStack(int Key){return LinkedList::searchList(Key);}
    int deleteStack(int Code){return LinkedList::deleteList(Code);}
    void freeStack(){LinkedList::freeList();}
    void displayStack(){LinkedList::displayAll();}
    ~Stack(){}
};

int main()
{
    Employee Emp1(1, "Ahmed Ali", 1500), Emp2, Emp3(5, "Mohamed Khalid", 2200), Emp4(8, "Heba Hamad", 1700), Emp5(3, "Hager Nasser", 2000);
    Queue Q;
    Stack S;

    cout << "______Queue______" << endl;

    Q.enQueue(&Emp1);
    Q.enQueue(&Emp2);
    Q.enQueue(&Emp3);
    Q.enQueue(&Emp4);
    Q.enQueue(&Emp5);

    cout << "\nDisplay All Employee which exist in my Queue...";
    Q.displayQueue();

    cout << "\nSearching For Employee that its id = 5 ...";
    Q.searchQueue(5);

    cout << "\nI Will Delete This Employee..";
    Q.deleteQueue(0);

    cout << "\nAfter Deleting Employee that id = 0, Queue Will be.." ;
    Q.displayQueue();

    cout << "\nAfter deQueue Employee , Queue Will be..";
    Q.deQueue();
    Q.displayQueue();

    cout << "\nAfter Free the Queue.." << endl;
    Q.freeQueue();
    Q.displayQueue();
/********************************************************************************************************************/
    cout << "\n\n______Stack______" << endl;

    S.push(&Emp1);
    S.push(&Emp2);
    S.push(&Emp3);
    S.push(&Emp4);
    S.push(&Emp5);

    cout << "\nDisplay All Employee which exist in my Stack...";
    S.displayStack();

    cout << "\nSearching For Employee that its id = 2 ...";
    S.searchStack(2);

    cout << "\nI Will Delete This Employee..";
    S.deleteStack(0);

    cout << "\nAfter Deleting Employee that id = 0, Stack Will be.." ;
    S.displayStack();

    cout << "\nAfter Popping from, Stack Will be..";
    S.pop();
    S.displayStack();

    cout << "\nAfter Free the Stack.." << endl;
    S.freeStack();
    S.displayStack();

    return 0;
}
