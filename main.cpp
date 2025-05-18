#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    int idi;
    string phone;
    bool isMale;
    string major;


public:
    Student(string input_name, int input_age, int input_di, string input_phone, bool input_isMale,string input_major) {
        name = input_name;
        age = input_age;
        idi = input_di;
        phone = input_phone;
        isMale = input_isMale;
        major = input_major;
    };
    void getName() {
        cout << name << endl;
    }
    void getAge() {
        cout << age << endl;
    }
    void getDi() {
        cout << idi << endl;
    }
    void getId() {
        cout << idi << idi;
    }
    void getPhone() {
        cout << phone << endl;
    }
    void getIsMale() {
        cout << isMale << endl;
    }
    void getMajor() {
        cout << major << endl;
    }
    void getInfo() {
        cout<<"Student data: "<<endl;
        cout<<"ID: "<<idi<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Phone: "<<phone<<endl;
        cout<<"IsMale: "<<isMale<<endl;
        cout<<"Major: "<<major<<endl;
    }

};









int main() {
    Student s1("Elnurbek",11,30505,"999999999",true,"Dasturlash");
    Student s2("Abduvali",12,41112,"919199191",true,"Cyber");

    s2.getInfo();

    return 0;
}
