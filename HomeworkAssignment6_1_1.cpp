#include <iostream>
using namespace std;

/**
* FUNCTION SIGNATURE:
 * void leftShiftElements(int arr[], int N, int M)
 * PURPOSE:
 * circulate array values of a variable array size to the rightward and to the beginning from the end
 * PARAMETER:
 *     int arr[], int N, int M
 * RETURN VALUE:
 *     No value to return as the array is modified within the function
*/
void leftShiftElements(int arr[], int N, int M)
{
    int arrTemp[N];
    int shiftValue = M;
    bool testShift = true;
    // when M is larger than N, shiftValue is modified and passed
    while (testShift)
    {
        if(M > N)
        {
            // subtract N from M until M < N
            while(M > N)
                M -= N;
            // subtract once more and convert to positive int to begin shift value
            M -= N;
            M *= -1;
            shiftValue = M;
        }
        else
        {
            shiftValue = M;
            testShift = false;
        }
        // loop starts at arr[0] and copies to arrTemp[shiftValue]
            /**
            * this is somewhat redundant as it covers some values twice
            * (the values that are in the range of the difference between M and N
            */
        for(int i = 0; i < N; i++)
        {
            if(shiftValue == N)
            {
                shiftValue = 0;
            }
            arrTemp[shiftValue] = arr[i];
            shiftValue++;
        }
    }
    // loop through arrTemp and copy values into arr
    cout << "[";
    for(int j = 0; j < N; j++)
    {
        arr[j] = arrTemp[j];
        cout << arr[j];
        if(j < N - 1)
            cout << ", ";
    }
    cout << "]";
}
int main()
{
    int arr[] = {1, 2, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    leftShiftElements(arr, size, 1);
    cout << endl << endl;
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    leftShiftElements(arr1, size1, 3);
    cout << endl << endl;
    int arr3[] = {1,2};
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
    leftShiftElements(arr3, size3, 1);
    cout << endl << endl;
    int arr4[] = {1};
    int size4 = sizeof(arr4)/sizeof(arr4[0]);
    leftShiftElements(arr4, size4, 0);
    cout << endl << endl;
    int arr5[] = {1};
    int size5 = sizeof(arr5)/sizeof(arr5[0]);
    leftShiftElements(arr5, size5, 12);
    cout << endl << endl;
    int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int size6 = sizeof(arr6)/sizeof(arr6[0]);
    leftShiftElements(arr6, size6, 1256);
    cout << endl << endl;
    int arr7[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
    int size7 = sizeof(arr7)/sizeof(arr7[0]);
    leftShiftElements(arr7, size7, 56);
    return 0;
}
