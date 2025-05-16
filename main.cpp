#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;

string currentDate() {
    time_t t = time(0);
    char* dt = ctime(&t);
    return string(dt);
}

class Tool {
protected:
    string title;
    string author;
    string subject;
    string uploadDate;
    string type; // Book, Video, Test, etc.

public:
    Tool(string t, string a, string s, string ty)
        : title(t), author(a), subject(s), type(ty) {
        uploadDate = currentDate();
    }

    string getType() const { return type; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    virtual void display() const {
        cout << "📘 Title: " << title << "\n";
        cout << "✍️  Author: " << author << "\n";
        cout << "📂 Subject: " << subject << "\n";
        cout << "🗂 Type: " << type << "\n";
        cout << "📅 Uploaded: " << uploadDate;
        cout << "----------------------------------\n";
    }
};

class EduToolsManager {
private:
    vector<Tool> tools;

public:
    void addTool() {
        string t, a, s, ty;
        cout << "\nEnter title: ";
        getline(cin, t);
        cout << "Enter author: ";
        getline(cin, a);
        cout << "Enter subject: ";
        getline(cin, s);
        cout << "Enter type (Book/Video/Test/PDF/Slides): ";
        getline(cin, ty);
        tools.emplace_back(t, a, s, ty);
        cout << "✅ Tool added successfully!\n";
    }

    void listByCategory(string category) {
        cout << "\n📂 Showing all " << category << "s:\n";
        int count = 0;
        for (const auto& tool : tools) {
            if (tool.getType() == category) {
                tool.display();
                count++;
            }
        }
        if (count == 0)
            cout << "❌ No tools found in this category.\n";
    }

    void searchByTitle(string keyword) {
        cout << "\n🔍 Search results for \"" << keyword << "\":\n";
        int count = 0;
        for (const auto& tool : tools) {
            if (tool.getTitle().find(keyword) != string::npos ||
                tool.getAuthor().find(keyword) != string::npos) {
                tool.display();
                count++;
            }
        }
        if (count == 0)
            cout << "❌ No matching tools found.\n";
    }

    void showStatistics() {
        map <string, int> stats;
        for (const auto& tool : tools) {
            stats[tool.getType()]++;
        }

        cout << "\n📊 Tool Statistics:\n";
        for (const auto& entry : stats) {
            cout << " - " << entry.first << ": " << entry.second << "\n";
        }
        if (tools.empty()) {
            cout << "No tools added yet.\n";
        }
    }

    void showAllTools() {
        cout << "\n📚 All Uploaded Tools:\n";
        for (const auto& tool : tools) {
            tool.display();
        }
        if (tools.empty())
            cout << "❌ No tools to display.\n";
    }
};

void showMenu() {
    cout << "\n===== 🎓 EDU TOOLS MANAGER =====\n";
    cout << "1. Add New Tool\n";
    cout << "2. Show All Tools\n";
    cout << "3. List Tools by Category\n";
    cout << "4. Search by Title/Author\n";
    cout << "5. Show Statistics\n";
    cout << "6. Exit\n";
    cout << "================================\n";
    cout << "Enter your choice: ";
}

int main() {
    EduToolsManager manager;
    int choice;
    string category, keyword;

    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            manager.addTool();
            break;
        case 2:
            manager.showAllTools();
            break;
        case 3:
            cout << "Enter category (Book/Video/Test/PDF/Slides): ";
            getline(cin, category);
            manager.listByCategory(category);
            break;
        case 4:
            cout << "Enter keyword to search (title or author): ";
            getline(cin, keyword);
            manager.searchByTitle(keyword);
            break;
        case 5:
            manager.showStatistics();
            break;
        case 6:
            cout << "👋 Goodbye! Study well!\n";
            return 0;
        default:
            cout << "❌ Invalid option, try again.\n";
        }
    }

    return 0;
}
