#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        size = -1;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 0)
        {
            int parent = parent / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void deleteMax()
    {
        if (size == -1)
        {
            return;
        }
        arr[0] = arr[size];
        size--;
        int i = 0;
        while (i < size)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size && arr[left] > arr[i])
            {
                swap(arr[left], arr[i]);
                i = left;
            }
            else if (right < size && arr[right] > arr[i])
            {
                swap(arr[right], arr[i]);
                i = right;
            }
            else
                return;
        }
    }

    void heapify(int arr[], int size, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && arr[largest] < arr[left])
            largest = left;
        if (right < size && arr[largest] < arr[right])
            right = largest;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, size, largest);
        }
    }
    

    void print()
    {
        for (int i = 0; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Heap h;
    h.insert(10);
    h.insert(12);
    h.insert(15);
    h.print();

    return 0;
}