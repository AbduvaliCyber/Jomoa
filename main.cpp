#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept>
using namespace std;

// ArrayManager klassi: massivlar bilan ishlash uchun
class ArrayManager {
private:
    int* arr;
    int size;

public:
    // Konstruktor (dinamik massiv yaratadi)
    ArrayManager(int n) : size(n) {
        if (size <= 0)
            throw invalid_argument("Massiv o'lchami musbat bo'lishi kerak");
        arr = new int[size];
    }

    // Destruktor
    ~ArrayManager() {
        delete[] arr;
    }

    // Elementlarni kiriting
    void input() {
        cout << "Massivning " << size << " ta elementini kiriting:\n";
        for(int i = 0; i < size; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    // Massivni chiqarish
    void print() const {
        cout << "Massiv elementlari: ";
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Eng katta elementni topish
    int findMax() const {
        int maxVal = arr[0];
        for(int i = 1; i < size; i++) {
            if(arr[i] > maxVal)
                maxVal = arr[i];
        }
        return maxVal;
    }

    // Eng kichik elementni topish
    int findMin() const {
        int minVal = arr[0];
        for(int i = 1; i < size; i++) {
            if(arr[i] < minVal)
                minVal = arr[i];
        }
        return minVal;
    }

    // Massivni saralash (o'sish tartibida)
    void sortArray() {
        sort(arr, arr + size);
    }

    // Massivdan element qidirish (linear search)
    int search(int key) const {
        for(int i = 0; i < size; i++) {
            if(arr[i] == key)
                return i; // indeks qaytariladi
        }
        return -1; // topilmadi
    }

    // Faylga yozish
    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout)
            throw runtime_error("Fayl ochib bo'lmadi");
        fout << size << "\n";
        for(int i = 0; i < size; i++) {
            fout << arr[i] << " ";
        }
        fout.close();
    }

    // Fayldan o'qish
    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin)
            throw runtime_error("Fayl ochib bo'lmadi");
        int newSize;
        fin >> newSize;
        if(newSize <= 0)
            throw runtime_error("Fayldagi massiv o'lchami noto'g'ri");

        delete[] arr; // eski massivni o'chirish
        size = newSize;
        arr = new int[size];
        for(int i = 0; i < size; i++) {
            fin >> arr[i];
        }
        fin.close();
    }
};

int main() {
    try {
        int n;
        cout << "Massiv o'lchamini kiriting: ";
        cin >> n;

        ArrayManager am(n);

        am.input();
        am.print();

        cout << "Eng katta element: " << am.findMax() << endl;
        cout << "Eng kichik element: " << am.findMin() << endl;

        am.sortArray();
        cout << "Saralangan massiv: ";
        am.print();

        int key;
        cout << "Qidiriladigan elementni kiriting: ";
        cin >> key;
        int index = am.search(key);
        if(index != -1)
            cout << key << " elementi " << index << "-indeksta topildi.\n";
        else
            cout << key << " elementi topilmadi.\n";

        // Faylga yozish va o'qish
        string filename = "massiv_data.txt";
        am.saveToFile(filename);
        cout << "Massiv faylga yozildi: " << filename << endl;

        // Yangi massiv yaratib fayldan o'qish
        ArrayManager am2(1); // dastlab kichik massiv
        am2.loadFromFile(filename);
        cout << "Fayldan o'qilgan massiv: ";
        am2.print();

    } catch(const exception& e) {
        cerr << "Xatolik: " << e.what() << endl;
    }
    return 0;
}
