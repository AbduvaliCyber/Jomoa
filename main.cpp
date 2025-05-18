#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    map<string,string> data = {
        {"Dilshoda","Gentra"},
        {"Abduvali","Malibu3"},
        {"Elnurbek","Coblt"},
        {"Behruzbek","Malibu3"},
        {"Ziyodulo","Laceti"},
    };

    for (auto   d :data) {
        cout << d.first << "s fav car is " << d.second << endl;
    }


    return 0;
}
