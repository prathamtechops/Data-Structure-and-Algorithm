#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter how many elements are there in the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element No:" << i + 1 << " ";
        cin >> arr[i];
    }

    cout << "Elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int element_to_delete;

    cout << "\nEnter the element to delete: ";
    cin >> element_to_delete;

    int index;
    for (index = 0; index < n; index++)
    {
        if (arr[index] == element_to_delete)
            break;
    }

    while (index < n)
    {
        n--;
        for (int j = index; j < n; j++)
            arr[j] = arr[j + 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
