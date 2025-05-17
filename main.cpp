#include <iostream>
#include <algorithm> // sort() funksiyasi uchun
using namespace std;

// Funksiya: massivni chiqarish
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Funksiya: eng katta elementni topish
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// Funksiya: eng kichik elementni topish
int findMin(int arr[], int size) {
    int minVal = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}

// Funksiya: massivda elementni qidirish
int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target)
            return i; // indeks qaytadi
    }
    return -1; // topilmadi
}

int main() {
    // 1. Oddiy massiv (statik)
    const int SIZE = 5;
    int nums[SIZE] = {10, 20, 5, 8, 15};

    cout << "Statik massiv elementlari: ";
    printArray(nums, SIZE);

    cout << "Eng katta element: " << findMax(nums, SIZE) << endl;
    cout << "Eng kichik element: " << findMin(nums, SIZE) << endl;

    int key = 8;
    int foundIndex = linearSearch(nums, SIZE, key);
    if(foundIndex != -1)
        cout << key << " elementi " << foundIndex << "-indeksta topildi." << endl;
    else
        cout << key << " elementi topilmadi." << endl;

    // 2. Dinamik massiv
    int n;
    cout << "\nDinamik massiv o‘lchamini kiriting: ";
    cin >> n;

    int* dynArray = new int[n];
    cout << n << " ta element kiriting:\n";
    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> dynArray[i];
    }

    cout << "Dinamik massiv: ";
    printArray(dynArray, n);

    // Sortlash
    sort(dynArray, dynArray + n);
    cout << "Saralangan massiv: ";
    printArray(dynArray, n);

    delete[] dynArray; // xotirani tozalash

    // 3. 2 o‘lchovli massiv (matritsa)
    int rows = 2, cols = 3;
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "\n2D massiv (matritsa):" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
