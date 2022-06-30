#include <iostream>

using namespace std;

class Sort
{
private:
    int Size;
    int* arr;

    void selection_sort(int*a, int n)
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

    void bubble_sort(int*a, int n)
    {
        int swapped;
        int i, j;
        for (i= 1; i< n; i++)
        {
            swapped = 0;
            for(j = 0; j < n -i; j++)
            {
                if(a[j] > a[j+1])
                {
                    Swap(a[j],a[j+1]);
                    swapped = 1;
                }
            }
            if(!swapped) break;
        }
    }

    void insertion_sort(int* arr, int n)
    {
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    int Partition (int* arr, int low, int high)
    {
        int pivot = arr[high]; // pivot
        int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                Swap(arr[i], arr[j]);
            }
        }
        Swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quick_sort(int* arr, int low, int high)
    {
        if (low < high)
        {
            // pi is partitioning index
            // arr[p] is now at right place
            int pi = Partition(arr, low, high);

            // Separately sort elements before
            // partition and after partition
            quick_sort(arr, low, pi - 1);
            quick_sort(arr, pi + 1, high);
        }
    }

    void Merge(int* arr, int p, int q, int r) {

      // Create L ← A[p..q] and M ← A[q+1..r]
      int n1 = q - p + 1;
      int n2 = r - q;

      int L[n1], M[n2];

      for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
      for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

      // Maintain current index of sub-arrays and main array
      int i, j, k;
      i = j = 0;
      k = p;

      // Until we reach either end of either L or M, pick larger among
      // elements L and M and place them in the correct position at A[p..r]
      while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
          arr[k] = L[i];
          i++;
        } else {
          arr[k] = M[j];
          j++;
        }
        k++;
      }

      // When we run out of elements in either L or M,
      // pick up the remaining elements and put in A[p..r]
      while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
      }

      while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
      }
    }

    // Divide the array into two sub arrays, sort them and merge them
    void merge_sort(int* arr, int l, int r) {
      if (l < r) {
        // m is the point where the array is divided into two sub arrays
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        // Merge the sorted subarrays
        Merge(arr, l, m, r);
      }
    }

    void Swap(int&x, int&y)
    {
        int temp;
        temp= x;
        x = y;
        y = temp;
    }

public:
    void Set(int a[], int S)
    {
        delete(arr);
        Size = S;
        arr = new int[Size+1];
        arr = a;
    }

    void Get_selection_sort()
    {
        selection_sort(arr, Size);
        for (int i=0; i<Size; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    void Get_bubble_sort()
    {
        bubble_sort(arr, Size);
        for (int i=0; i<Size; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    void Get_insertion_sort()
    {
        insertion_sort(arr, Size);
        for (int i=0; i<Size; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    void Get_quick_sort()
    {
        quick_sort(arr, 0, Size-1);
        for (int i=0; i<Size; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    void Get_merge_sort()
    {
        merge_sort(arr, 0, Size-1);
        for (int i=0; i<Size; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    ~Sort()
    {
        delete(arr);
    }
};

int main()
{
    Sort S1;
    int Len = 0;
    int* a;
    a = new int[Len+1];

    cout << "Enter the length of array please ! ";
    cin >> Len;

    cout << "Enter the elements of an array = ";
    for (int i=0; i<Len; i++) cin >> a[i];

    S1.Set(a,Len);

    cout << "\nSelection Sort : " ;
    S1.Get_selection_sort();

    cout << "\nBubble Sort : " ;
    S1.Get_bubble_sort();

    cout << "\nInsertion Sort : " ;
    S1.Get_insertion_sort();

    cout << "\nQuick Sort : " ;
    S1.Get_quick_sort();

    cout << "\nMerge Sort : " ;
    S1.Get_merge_sort();

return 0;
}
