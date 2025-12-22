#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Array
{
private:
    vector<int> arr;
    int size;

    void SyncSize() { size = arr.size(); }

    void DeleteByIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index\n";
            return;
        }
        arr.erase(arr.begin() + index);
        SyncSize();
    }

    void DeleteByValue(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                arr.erase(arr.begin() + i);
                SyncSize();
                return;
            }
        }
        cout << "Value not found\n";
    }

public:
    Array()
    {
        size = 5;
        arr.assign(size, 0); // fill with zeros
    }

    Array(int n)
    {
        size = n;
        arr.assign(size, 0); // fill with zeros
    }

    // Copy constructor
    Array(const Array& other)
    {
        arr = other.arr;
        size = other.size;
    }

    void Fill(int mode)
    {
        arr.clear();
        if (mode == 0) // default
        {
            arr.assign(5, 0);
        }
        else if (mode == 1) // keyboard
        {
            cout << "Enter size >>> ";
            cin >> size;
            int elem;
            for (int i = 0; i < size; i++)
            {
                cout << "Enter element >>> ";
                cin >> elem;
                arr.push_back(elem);
            }
        }
        else if (mode == 2) // random
        {
            cout << "Enter size >>> ";
            cin >> size;
            for (int i = 0; i < size; i++)
                arr.push_back(rand() % 100);
        }
        else
        {
            cout << "Invalid fill mode\n";
        }
        SyncSize();
    }

    void Print() const
    {
        if (arr.empty())
        {
            cout << "Array is empty\n";
            return;
        }
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }

    void Add(int element)
    {
        arr.push_back(element);
        SyncSize();
    }

    void Delete()
    {
        int option;
        cout << "Delete by index (0) or value (1)? >>> ";
        cin >> option;
        if (option == 0)
        {
            int index;
            cout << "Enter index >>> ";
            cin >> index;
            DeleteByIndex(index);
        }
        else
        {
            int value;
            cout << "Enter value >>> ";
            cin >> value;
            DeleteByValue(value);
        }
    }

    void Sort(bool ascending = true)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if ((ascending && arr[j] > arr[j + 1]) ||
                    (!ascending && arr[j] < arr[j + 1]))
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    double Find()
    {
        if (arr.empty())
        {
            cout << "Array is empty!\n";
            return 0;
        }

        int option;
        cout << "Max (1), Min (0), Average (2) >>> ";
        cin >> option;

        if (option == 1) // Max
        {
            int maxVal = arr[0];
            for (int i = 1; i < size; i++)
                if (arr[i] > maxVal) maxVal = arr[i];
            return maxVal;
        }
        else if (option == 0) // Min
        {
            int minVal = arr[0];
            for (int i = 1; i < size; i++)
                if (arr[i] < minVal) minVal = arr[i];
            return minVal;
        }
        else if (option == 2) // Average
        {
            int sum = 0;
            for (int i = 0; i < size; i++)
                sum += arr[i];
            return static_cast<double>(sum) / size;
        }
        else
        {
            cout << "Invalid option\n";
            return 0;
        }
    }

    ~Array()
    {
        cout << "Array deleted\n";
    }
};

int main()
{
    Array a1;
    a1.Print();

    Array a2(10);
    a2.Print();

    a2.Fill(2);

    Array a3 = a2;
    a3.Print();

    a3.Add(999);
    a3.Print();
}
