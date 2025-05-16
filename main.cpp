#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Forward declarations
class Course;

class Person {
public:
    string name;
    string email;

    Person(string n, string e) : name(n), email(e) {}

    virtual void showInfo() = 0;
};

class Student : public Person {
public:
    map<string, double> grades;

    Student(string n, string e) : Person(n, e) {}

    void addGrade(string courseName, double grade) {
        grades[courseName] = grade;
    }

    void showInfo() override {
        cout << "👩‍🎓 Student: " << name << " | Email: " << email << endl;
        for (auto& g : grades) {
            cout << "  📚 " << g.first << ": " << g.second << " ball" << endl;
        }
    }
};

class Teacher : public Person {
public:
    vector<string> teachingCourses;

    Teacher(string n, string e) : Person(n, e) {}

    void assignCourse(string courseName) {
        teachingCourses.push_back(courseName);
    }

    void showInfo() override {
        cout << "👨‍🏫 Teacher: " << name << " | Email: " << email << endl;
        for (auto& c : teachingCourses) {
            cout << "  📘 Teaching: " << c << endl;
        }
    }
};

class Course {
public:
    string name;
    Teacher* instructor;
    vector<Student*> students;

    Course(string courseName, Teacher* t) : name(courseName), instructor(t) {
        instructor->assignCourse(name);
    }

    void enrollStudent(Student* s) {
        students.push_back(s);
    }

    void showCourseInfo() {
        cout << "\n📚 Course: " << name << endl;
        cout << "  👨‍🏫 Instructor: " << instructor->name << endl;
        cout << "  👥 Enrolled Students:\n";
        for (auto* s : students) {
            cout << "    - " << s->name << endl;
        }
    }
};

class EduCenter {
private:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;

public:
    void addStudent(string name, string email) {
        students.emplace_back(name, email);
        cout << "✅ Student added: " << name << endl;
    }

    void addTeacher(string name, string email) {
        teachers.emplace_back(name, email);
        cout << "✅ Teacher added: " << name << endl;
    }

    Student* findStudent(string name) {
        for (auto& s : students) {
            if (s.name == name)
                return &s;
        }
        return nullptr;
    }

    Teacher* findTeacher(string name) {
        for (auto& t : teachers) {
            if (t.name == name)
                return &t;
        }
        return nullptr;
    }

    Course* findCourse(string name) {
        for (auto& c : courses) {
            if (c.name == name)
                return &c;
        }
        return nullptr;
    }

    void createCourse(string courseName, string teacherName) {
        Teacher* t = findTeacher(teacherName);
        if (t) {
            courses.emplace_back(courseName, t);
            cout << "✅ Course created: " << courseName << endl;
        } else {
            cout << "❌ Teacher not found!\n";
        }
    }

    void enrollStudentToCourse(string studentName, string courseName) {
        Student* s = findStudent(studentName);
        Course* c = findCourse(courseName);
        if (s && c) {
            c->enrollStudent(s);
            cout << "📥 Enrolled " << s->name << " to " << c->name << endl;
        } else {
            cout << "❌ Student or Course not found!\n";
        }
    }

    void gradeStudent(string studentName, string courseName, double grade) {
        Student* s = findStudent(studentName);
        if (s) {
            s->addGrade(courseName, grade);
            cout << "✅ Graded " << s->name << ": " << courseName << " = " << grade << endl;
        } else {
            cout << "❌ Student not found!\n";
        }
    }

    void showAllCourses() {
        for (auto& c : courses) {
            c.showCourseInfo();
        }
    }

    void showAllPeople() {
        cout << "\n=== 👩‍🎓 Students ===\n";
        for (auto& s : students) s.showInfo();
        cout << "\n=== 👨‍🏫 Teachers ===\n";
        for (auto& t : teachers) t.showInfo();
    }
};

int main() {
    EduCenter center;

    int choice;
    string name, email, course, teacher;
    double grade;

    while (true) {
        cout << "\n==== 📘 EduCenter Menu ====\n";
        cout << "1. Add Student\n2. Add Teacher\n3. Create Course\n4. Enroll Student\n";
        cout << "5. Grade Student\n6. Show All Courses\n7. Show All Users\n8. Exit\n";
        cout << "Select: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter student name: "; getline(cin, name);
            cout << "Enter student email: "; getline(cin, email);
            center.addStudent(name, email);
            break;
        case 2:
            cout << "Enter teacher name: "; getline(cin, name);
            cout << "Enter teacher email: "; getline(cin, email);
            center.addTeacher(name, email);
            break;
        case 3:
            cout << "Enter course name: "; getline(cin, course);
            cout << "Enter teacher name: "; getline(cin, teacher);
            center.createCourse(course, teacher);
            break;
        case 4:
            cout << "Enter student name: "; getline(cin, name);
            cout << "Enter course name: "; getline(cin, course);
            center.enrollStudentToCourse(name, course);
            break;
        case 5:
            cout << "Enter student name: "; getline(cin, name);
            cout << "Enter course name: "; getline(cin, course);
            cout << "Enter grade: "; cin >> grade; cin.ignore();
            center.gradeStudent(name, course, grade);
            break;
        case 6:
            center.showAllCourses();
            break;
        case 7:
            center.showAllPeople();
            break;
        case 8:
            cout << "👋 Goodbye!\n";
            return 0;
        default:
            cout << "❌ Invalid choice.\n";
        }
    }

    return 0;
}
