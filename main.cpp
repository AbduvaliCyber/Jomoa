#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Student {
private:
    string fullname;
    int age;
    string course;

public:
    Student() : fullname(""), age(0), course("") {}
    Student(string name, int a, string c) : fullname(name), age(a), course(c) {}

    void input() {
        cout << "Ismi va familiyasi: ";
        getline(cin, fullname);
        cout << "Yoshi: ";
        cin >> age;
        cin.ignore();
        cout << "Kurs (masalan: C++ Dasturlash): ";
        getline(cin, course);
    }

    void print() const {
        cout << "Ism: " << fullname << ", Yoshi: " << age << ", Kurs: " << course << endl;
    }

    string getName() const { return fullname; }
};

class NajotTalim {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        cin.ignore();
        cout << "Talaba qo'shish:\n";
        s.input();
        students.push_back(s);
        cout << "Talaba qo'shildi.\n";
    }

    void showStudents() const {
        if (students.empty()) {
            cout << "Hozircha talaba yo'q.\n";
            return;
        }
        cout << "Najot Ta'lim talabalari:\n";
        for (size_t i = 0; i < students.size(); i++) {
            cout << i+1 << ". ";
            students[i].print();
        }
    }

    void removeStudent() {
        if (students.empty()) {
            cout << "Talabalar ro'yxati bo'sh.\n";
            return;
        }
        showStudents();
        cout << "O'chirish uchun talaba raqamini kiriting: ";
        int index;
        cin >> index;
        if (index < 1 || index > (int)students.size()) {
            cout << "Noto'g'ri raqam.\n";
            return;
        }
        students.erase(students.begin() + index - 1);
        cout << "Talaba o'chirildi.\n";
    }

    void saveToFile(const string& filename) {
        ofstream fout(filename);
        if (!fout) {
            cout << "Faylni ochib bo'lmadi.\n";
            return;
        }
        fout << students.size() << "\n";
        for (const auto& s : students) {
            fout << s.getName() << "\n" << s.getAge() << "\n" << s.getCourse() << "\n";
        }
        fout.close();
        cout << "Ma'lumotlar faylga saqlandi.\n";
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Faylni ochib bo'lmadi.\n";
            return;
        }
        size_t n;
        fin >> n;
        fin.ignore();
        students.clear();
        for (size_t i = 0; i < n; i++) {
            string name, course;
            int age;
            getline(fin, name);
            fin >> age;
            fin.ignore();
            getline(fin, course);
            students.emplace_back(name, age, course);
        }
        fin.close();
        cout << "Ma'lumotlar fayldan yuklandi.\n";
    }
};

int main() {
    NajotTalim nt;
    const string filename = "najot_students.txt";
    nt.loadFromFile(filename);

    while (true) {
        cout << "\nNajot Ta'lim boshqaruv tizimi\n";
        cout << "1. Talaba qo'shish\n";
        cout << "2. Talabalar ro'yxatini ko'rsatish\n";
        cout << "3. Talaba o'chirish\n";
        cout << "4. Ma'lumotlarni faylga saqlash\n";
        cout << "5. Chiqish\n";
        cout << "Tanlov: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                nt.addStudent();
                break;
            case 2:
                nt.showStudents();
                break;
            case 3:
                nt.removeStudent();
                break;
            case 4:
                nt.saveToFile(filename);
                break;
            case 5:
                cout << "Dasturdan chiqildi.\n";
                return 0;
            default:
                cout << "Noto'g'ri tanlov.\n";
        }
    }
    return 0;
}
