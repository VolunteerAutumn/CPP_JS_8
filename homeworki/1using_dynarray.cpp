#include <iostream>
#include <cstdlib>
using namespace std;

// I still also made it using dynamic arrays because I was bored outta my mind ngl

class Array {
private:
    int* arr;
    int size;

    void DeleteByIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }
        int* newArr = new int[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) newArr[j++] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size--;
    }

    void DeleteByValue(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                DeleteByIndex(i);
                return;
            }
        }
        cout << "Value not found\n";
    }

public:
    // Default constructor
    Array() {
        size = 5;
        arr = new int[size]{0};
    }

    // Constructor with size
    Array(int n) {
        size = n;
        arr = new int[size]{0};
    }

    // Copy constructor
    Array(const Array& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    void Fill(int mode) {
        delete[] arr; // clear old data
        arr = nullptr;
        if (mode == 0) { // default
            size = 5;
            arr = new int[size]{0};
        } else if (mode == 1) { // keyboard
            cout << "Enter size >>> ";
            cin >> size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                cout << "Enter element >>> ";
                cin >> arr[i];
            }
        } else if (mode == 2) { // random
            cout << "Enter size >>> ";
            cin >> size;
            arr = new int[size];
            for (int i = 0; i < size; i++)
                arr[i] = rand() % 100;
        } else {
            cout << "Invalid fill mode\n";
        }
    }

    void Print() const {
        if (size == 0 || arr == nullptr) {
            cout << "Array is empty\n";
            return;
        }
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void Add(int element) {
        int* newArr = new int[size + 1];
        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];
        newArr[size] = element;
        delete[] arr;
        arr = newArr;
        size++;
    }

    void Delete() {
        int option;
        cout << "Delete by index (0) or value (1)? >>> ";
        cin >> option;
        if (option == 0) {
            int index;
            cout << "Enter index >>> ";
            cin >> index;
            DeleteByIndex(index);
        } else {
            int value;
            cout << "Enter value >>> ";
            cin >> value;
            DeleteByValue(value);
        }
    }

    void Sort(bool ascending = true) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if ((ascending && arr[j] > arr[j + 1]) ||
                    (!ascending && arr[j] < arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    double Find() {
        if (size == 0 || arr == nullptr) {
            cout << "Array is empty!\n";
            return 0;
        }

        int option;
        cout << "Max (1), Min (0), Average (2) >>> ";
        cin >> option;

        if (option == 1) { // Max
            int maxVal = arr[0];
            for (int i = 1; i < size; i++)
                if (arr[i] > maxVal) maxVal = arr[i];
            return maxVal;
        } else if (option == 0) { // Min
            int minVal = arr[0];
            for (int i = 1; i < size; i++)
                if (arr[i] < minVal) minVal = arr[i];
            return minVal;
        } else if (option == 2) { // Average
            int sum = 0;
            for (int i = 0; i < size; i++)
                sum += arr[i];
            return static_cast<double>(sum) / size;
        } else {
            cout << "Invalid option\n";
            return 0;
        }
    }

    ~Array() {
        delete[] arr;
        cout << "Array deleted\n";
    }
};

// Testing
int main() {
    Array a1;
    a1.Print();

    Array a2(10);
    a2.Print();

    a2.Fill(2);
    a2.Print();

    Array a3 = a2;
    a3.Print();

    a3.Add(999);
    a3.Print();

    a3.Delete();
    a3.Print();

    a3.Sort(false);
    a3.Print();

    cout << "Average: " << a3.Find() << endl;
}
