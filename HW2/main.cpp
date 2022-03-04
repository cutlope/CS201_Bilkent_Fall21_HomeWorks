using namespace std;
#include <iostream>
#include <ctime>
#include <cstdlib>

void sortArray(int array[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

//find largest element in array linear time
int findLargest(int *arr, int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

bool linearSearch(int *arr1, int arr1Size, int *arr2, int arr2Size)
{

    //loop through arr2
    for (int i = 0; i < arr2Size; i++)
    {
        //loop through arr1
        for (int j = 0; j < arr1Size; j++)
        {
            if (arr2[i] == arr1[j])
            {
                break;
            }

            else if (j == (arr1Size - 1))
            {
                return false;
            }
        }
    }

    return true;
}

//generate random sorted array of size n with elements within range k
int *generateRandomArray(int n, int k)
{
    int *arr = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % k;
    }
    // Sort array using quicksort

    sortArray(arr, n);
    return arr;
}

//reused code from slides
int binarySearch(int *arr, int arrSize, int value)
{
    int low = 0;
    int high = arrSize - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < value)
            low = mid + 1;
        else if (arr[mid] > value)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

//check if arr2 is a subset of arr1 using binary search
bool binaryAlgo(int arr1[], int arr1Size, int arr2[], int arr2Size)
{
    for (int i = 0; i < arr2Size; i++)
    {
        if (binarySearch(arr1, arr1Size, arr2[i]) == -1)
        {
            return false;
        }
    }
    return true;
}

//check if arr2 is a subset of arr1 using frequency tables
bool frequencyTables(int arr1[], int arr1Size, int maxValArr1, int arr2[], int arr2Size)
{
    int *freqTable = new int[maxValArr1 + 1]();

    for (int i = 0; i < arr1Size; i++)
    {
        freqTable[arr1[i]]++;
    }
    for (int i = 0; i < arr2Size; i++)
    {
        if (freqTable[arr2[i]] == 0)
        {
            delete[] freqTable;
            return false;
        }
        else
        {
            freqTable[arr2[i]]--;
        }
    }
    delete[] freqTable;
    return true;
}

int main()
{
    int *arr1;
    int *arr2;
    int arr1Size[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    int arr2Size = 10000;
    int k = 10;

    for (int z = 0; z < 10; z++)
    {
        cout << "\n Running Algorithm Analysis with n: " << arr1Size[z] << " and m : " << arr2Size << endl;
        cout << "<------------------------------------------------------->" << endl;
        arr1 = generateRandomArray(arr1Size[z], k);
        arr2 = generateRandomArray(arr2Size, k);

        //Algorithm 1
        cout << "Linear Search: ";
        double duration;
        clock_t startTime = clock();
        for (int i = 0; i < 5; i++)
        {
            linearSearch(arr1, arr1Size[z], arr2, arr2Size);
        }
        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << fixed << "Execution took " << duration / 5 << " milliseconds." << endl;

        //Algorithm 2
        cout << "Binary Search: ";
        startTime = clock();
        for (int i = 0; i < 1000; i++)
        {
            binaryAlgo(arr1, arr1Size[z], arr2, arr2Size);
        }
        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration / 1000 << " milliseconds." << endl;

        //Algorithm 3
        int maxValArr1 = findLargest(arr1, arr1Size[z]);
        cout << "Frequency Table: ";
        startTime = clock();
        for (int i = 0; i < 1000; i++)
        {
            frequencyTables(arr1, arr1Size[z], maxValArr1, arr2, arr2Size);
        }
        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration / 1000 << " milliseconds." << endl;

        delete[] arr1;
        delete[] arr2;
        cout << "<------------------------------------------------------->" << endl;
    }

    return 0;
}
