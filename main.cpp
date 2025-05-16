#include <iostream>
#include <windows.h>  // Rang uchun Windows kutubxonasi
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void showTitle(const string& title) {
    setColor(11);  // Ochiq ko‘k rang
    cout << "\n=== " << title << " ===\n";
    setColor(7);   // Standart rang
}

void showOverview() {
    showTitle("Najot Ta'lim Umumiy Ma'lumot");
    cout << "Najot Ta'lim - O'zbekistondagi yetakchi ta'lim markazi.\n";
    cout << "2018-yilda tashkil etilgan va zamonaviy kasblar bo'yicha ta'lim beradi.\n";
    cout << "Bitiruvchilarning 75-85% doimiy ish bilan ta'minlanadi.\n";
}

void showCourses() {
    showTitle("Kurslar");
    cout << "1. Dasturlash: Python, JavaScript, React, Node.js, QA\n";
    cout << "2. Dizayn: Grafik dizayn, UX/UI dizayn\n";
    cout << "3. Marketing: SMM, Digital marketing\n";
    cout << "Kurslar Bootcamp va Standart shaklda taklif qilinadi.\n";
}

void showBranches() {
    showTitle("Filiallar");
    cout << "Toshkent: Xadra, Chilonzor, Chimboy\n";
    cout << "Viloyatlar: Farg'ona, Samarqand, Xorazm\n";
}

void showContacts() {
    showTitle("Aloqa");
    cout << "Telefon: +998 78 888 98 88\n";
    cout << "Veb-sayt: https://najottalim.uz\n";
    cout << "Telegram: @najottalim\n";
}

int main() {
    int choice;

    setColor(14); // Sariq rang bilan salomlashish
    cout << "Najot Ta'lim haqida interaktiv dasturga xush kelibsiz!\n";
    setColor(7);  // Standart rang

    do {
        setColor(10); // Yashil rang
        cout << "\n===== Menyu =====\n";
        setColor(7);
        cout << "1. Umumiy ma'lumot\n";
        cout << "2. Kurslar\n";
        cout << "3. Filiallar\n";
        cout << "4. Aloqa\n";
        cout << "0. Chiqish\n";
        cout << "Tanlovingiz: ";
        cin >> choice;

        switch (choice) {
            case 1: showOverview(); break;
            case 2: showCourses(); break;
            case 3: showBranches(); break;
            case 4: showContacts(); break;
            case 0:
                setColor(12); // Qizil rang
                cout << "Dasturdan chiqish...\n";
                break;
            default:
                setColor(12); // Qizil rang
                cout << "Noto'g'ri tanlov, qaytadan urinib ko'ring.\n";
                setColor(7);
                break;
        }
    } while (choice != 0);

    setColor(7); // Rangni tiklash
    return 0;
}
