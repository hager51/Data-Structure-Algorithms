#include <iostream>

using namespace std;

class Search
{
private:
    int Size;
    int* arr;

public:
    Search (int a[], int S)
    {
        Size = S;
        arr = new int[Size];
        arr = a;
    }

    int sequential_search(int*a, int n, int num)
    {
        int i= 0, found = 0;
        while ((!found) && (i< n))
        {
            if ( num == a[i])
                found = 1;
            else
                i++;
        }
        if (found)
            return i;
        else
            return -1;
    }

    int Binary_search(int*a, int n, int num)
    {
        Sort(a,n);
        int found = 0;
        int high = n ;
        int low = 0;
        int mid;
        while ((!found) && (low <= high ))
        {
            mid = (high + low) / 2;
            if (a [mid] > num)
                high = mid - 1; // go right
            else if (a[mid] < num)
                low = mid + 1; // go left
            else
                found = 1;
        }
        if (found) return mid;
        else return -1;
    }

    void Swap(int&x, int&y)
    {
        int temp;
        temp= x;
        x = y;
        y = temp;
    }

    void Sort(int*a, int n)
    {
        int i, j, min;
        for (i= 0; i< (n-1); i++)
        {
            min = i;
            for (j = (i+1); j < n; j++)
            {
                if(a[j] < a[min]) min = j;
            }
        if (i!= min) Swap(a[i],a[min]);
        }
    }

    ~Search()
    {
        delete(arr);
    }
};

int main()
{
    int Len = 0, SearchNum = 0;
    int* a;
    a = new int[Len];
    cout << "Enter the length of array please : ";
    cin >> Len;

    cout << "Enter the elements of an array = ";
    for (int i=0; i<Len; i++) cin >> a[i];

    Search S(a,Len);
    cout << "Enter the number you search for : " ;
    cin >> SearchNum;

    cout << "\n       Sequential Search       " << endl;

    if (S.sequential_search(a,Len,SearchNum) != -1)
        cout << "The number you search for is founded with index = " << S.sequential_search(a,Len,SearchNum) << endl;
    else
        cout << "The number you search for is not founded ....!" << endl;


    cout << "\n       Binary Search       " << endl;

    if (S.Binary_search(a,Len,SearchNum) != -1)
        cout << "The number you search for is founded with index = " << S.Binary_search(a,Len,SearchNum) << endl;
    else
        cout << "The number you search for is not founded ....!" << endl;

    return 0;
}
