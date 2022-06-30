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
    Employee *pRight;
    Employee *pLeft;
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

class BinaryTree
{
    Employee *pParent;
    Employee *insert(Employee *pRoot, Employee *data);
    void inOrder(Employee *pRoot);
    void preOrder(Employee *pRoot);
    void postOrder(Employee *pRoot);
    Employee *Delete(Employee* pRoot, int Code);
    int height(Employee* pRoot);
public:
    BinaryTree() { pParent= NULL; }
    void insertNode(Employee *data);
    Employee *searchTree(int code);
    void inOrderTraverse();
    void preOrderTraverse();
    void postOrderTraverse();
    void deleteNode(int Code);
    int TreeHeight();
};
void BinaryTree::insertNode(Employee *data)
{
    pParent = insert(pParent, data);
}
Employee *BinaryTree::insert( Employee *pRoot, Employee *data)
{
// 1. If the tree is empty , return a new single node as a root of the tree
    if (pRoot == NULL)
    {
        data->pRight = NULL;
        data->pLeft = NULL;
        return (data);
    }
// 2. otherwise , go down to insert it in the right place
    else
    {
        if(data->GetId() <= pRoot->GetId())
            pRoot->pLeft = insert(pRoot->pLeft,data);
        else
            pRoot->pRight= insert(pRoot->pRight,data);
        return(pRoot); // return the unchanged pParent pointer
    }
}
Employee *BinaryTree::searchTree(int code)
{
    Employee *pRoot;
    pRoot = pParent;
    while (pRoot && code != pRoot->GetId())
    {
        if(code < pRoot->GetId())
            pRoot = pRoot-> pLeft ;
        else
            pRoot = pRoot -> pRight ;
    }
    if(pRoot)
    {
        pRoot->printEmployee();
        return pRoot;
    }
    else
    {
        cout << "This ID is not Exist...\n";
    }
}
void BinaryTree::inOrderTraverse()
{
    inOrder(pParent);
}
void BinaryTree::inOrder(Employee *pRoot)
{
    if (pRoot)
    {
        inOrder(pRoot->pLeft);
        cout << "Code : " << pRoot->GetId() << endl;
        inOrder(pRoot->pRight);
    }
}
void BinaryTree::preOrderTraverse()
{
    preOrder(pParent);
}
void BinaryTree::preOrder(Employee *pRoot)
{
    if(pRoot)
    {
        cout<< "Code : " << pRoot->GetId() << endl;
        preOrder(pRoot->pLeft);
        preOrder(pRoot->pRight);
    }
}
void BinaryTree::postOrderTraverse()
{
    postOrder (pParent);
}
void BinaryTree::postOrder(Employee * pRoot)
{
    if(pRoot)
    {
        postOrder(pRoot->pLeft);
        postOrder(pRoot->pRight);
        cout << "Code : " << pRoot->GetId() << endl;
    }
}
void BinaryTree::deleteNode(int Code)
{
    Delete(pParent, Code);
    cout << Code << endl;
}
Employee *BinaryTree::Delete(Employee* pRoot, int Code)
{
    // Base case
    if (pRoot == NULL)
        return pRoot;

    // Recursive calls for ancestors of node to be deleted
    if (pRoot->GetId() > Code) {
        pRoot->pLeft = Delete(pRoot->pLeft, Code);
        return pRoot;
    }
    else if (pRoot->GetId() < Code) {
        pRoot->pRight = Delete(pRoot->pRight, Code);
        return pRoot;
    }
    // We reach here when root is the node to be deleted.

    // If one of the children is empty
    if (pRoot->pLeft == NULL) {
        Employee* temp = pRoot->pRight;
        delete pRoot;
        return temp;
    }
    else if (pRoot->pRight == NULL) {
        Employee* temp = pRoot->pLeft;
        delete pRoot;
        return temp;
    }

    // If both children exist
    else {

        Employee* succParent = pRoot;

        // Find successor (Smallest in Right)
        Employee* succ = pRoot->pRight;
        while (succ->pLeft != NULL) {
            succParent = succ;
            succ = succ->pLeft;
        }

        if (succParent != pRoot)
            succParent->pLeft = succ->pRight;
        else
            succParent->pRight = succ->pRight;

        // Copy Successor Data to root
        pRoot->SetId(succ->GetId());

        // Delete Successor and return root
        delete succ;
        return pRoot;
    }
}
int BinaryTree::TreeHeight()
{
    height(pParent);
}
int BinaryTree::height(Employee* pRoot)
{
    if (pRoot == NULL)
        return 0;
    else
    {
        // Find the height of left, right subtrees
        int left_height = height(pRoot->pLeft);
        int right_height = height(pRoot->pRight);

        // Find max(subtree_height) + 1 to get the height of the tree
        return max(left_height, right_height) + 1;
    }
}

int main()
{
    Employee Emp1(1, "Ahmed Ali", 1500), Emp2, Emp3(5, "Mohamed Khalid", 2200), Emp4(8, "Heba Hamad", 1700), Emp5(3, "Hager Nasser", 2000);
    BinaryTree T;

    T.insertNode(&Emp1);
    T.insertNode(&Emp2);
    T.insertNode(&Emp3);
    T.insertNode(&Emp4);
    T.insertNode(&Emp5);

    cout << "\nDisplay All IDs for Employee which exist in my Tree In Ordered ...\n";
    T.inOrderTraverse();

    cout << "\nDisplay All IDs for Employee which exist in my Tree Pre Ordered ...\n";
    T.preOrderTraverse();

    cout << "\nDisplay All IDs for Employee which exist in my Tree Post Ordered ...\n";
    T.postOrderTraverse();

    cout << "\nSearching For Employee that its id = 5 ...";
    T.searchTree(5);

    cout << "\nSearching For Employee that its id = 2 ...";
    T.searchTree(2);

    cout << "\nI Will Delete The Employee which ID = ";
    T.deleteNode(1);

    cout << "\nAfter Deleting ....\n";
    T.inOrderTraverse();

    cout << "\nThe Hight of the tree = "<< T.TreeHeight() << endl;


    return 0;
}
