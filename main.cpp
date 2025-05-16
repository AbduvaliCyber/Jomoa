#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

string getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

class Commit {
public:
    string message;
    string timestamp;

    Commit(string msg) {
        message = msg;
        timestamp = getCurrentTime();
    }

    void display() {
        cout << "Commit: " << message << " at " << timestamp;
    }
};

class Branch {
public:
    string name;
    vector<Commit> commits;

    Branch(string branchName) {
        name = branchName;
    }

    void addCommit(string message) {
        commits.emplace_back(message);
    }

    void showHistory() {
        cout << "Branch: " << name << endl;
        for (auto& c : commits) {
            c.display();
        }
    }
};

class Repository {
public:
    string name;
    map<string, Branch> branches;

    Repository(string repoName) {
        name = repoName;
        branches["main"] = Branch("main");
    }

    void createBranch(string branchName) {
        if (branches.find(branchName) == branches.end()) {
            branches[branchName] = Branch(branchName);
            cout << "Branch '" << branchName << "' created.\n";
        } else {
            cout << "Branch already exists.\n";
        }
    }

    void commit(string branchName, string message) {
        if (branches.find(branchName) != branches.end()) {
            branches[branchName].addCommit(message);
            cout << "Commit added to branch '" << branchName << "'.\n";
        } else {
            cout << "Branch not found.\n";
        }
    }

    void log(string branchName) {
        if (branches.find(branchName) != branches.end()) {
            branches[branchName].showHistory();
        } else {
            cout << "Branch not found.\n";
        }
    }
};

class User {
public:
    string username;
    vector<Repository> repositories;

    User(string uname) {
        username = uname;
    }

    void createRepo(string repoName) {
        repositories.emplace_back(repoName);
        cout << "Repository '" << repoName << "' created.\n";
    }

    Repository* getRepo(string repoName) {
        for (auto& repo : repositories) {
            if (repo.name == repoName) {
                return &repo;
            }
        }
        cout << "Repository not found.\n";
        return nullptr;
    }
};

int main() {
    vector<User> users;
    string uname;
    cout << "Enter your username: ";
    cin >> uname;
    User user(uname);
    users.push_back(user);

    int choice;
    while (true) {
        cout << "\n1. Create Repository\n2. Create Branch\n3. Commit\n4. Show Log\n5. Exit\nChoice: ";
        cin >> choice;
        string repoName, branchName, message;

        switch (choice) {
        case 1:
            cout << "Enter repository name: ";
            cin >> repoName;
            users[0].createRepo(repoName);
            break;
        case 2:
            cout << "Enter repository name: ";
            cin >> repoName;
            cout << "Enter branch name: ";
            cin >> branchName;
            if (auto repo = users[0].getRepo(repoName))
                repo->createBranch(branchName);
            break;
        case 3:
            cout << "Enter repository name: ";
            cin >> repoName;
            cout << "Enter branch name: ";
            cin.ignore();
            getline(cin, branchName);
            cout << "Enter commit message: ";
            getline(cin, message);
            if (auto repo = users[0].getRepo(repoName))
                repo->commit(branchName, message);
            break;
        case 4:
            cout << "Enter repository name: ";
            cin >> repoName;
            cout << "Enter branch name: ";
            cin >> branchName;
            if (auto repo = users[0].getRepo(repoName))
                repo->log(branchName);
            break;
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
