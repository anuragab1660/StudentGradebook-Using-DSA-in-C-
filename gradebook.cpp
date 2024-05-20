#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    vector<int> grades;

    // Constructor with default name
    Student(const string& n = "Unknown") : name(n) {}
};
class Gradebook {
private:
    map<int, Student> students;
public:
    void addStudent(int id, const string& name) {
        students[id] = Student(name);
    }

    void addGrade(int id, int grade) {
        students[id].grades.push_back(grade);
    }

    float calculateAverage(int id) {
        const vector<int>& grades = students[id].grades;
        float sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    void generateReport() {
        cout << "Student Grade Report:" << endl;
        cout << "---------------------" << endl;
        for (const auto& pair : students) {
            int id = pair.first;
            const Student& student = pair.second;
            cout << "Student ID: " << id << ", Name: " << student.name << endl;
            cout << "Grades: ";
            for (int grade : student.grades) {
                cout << grade << " ";
            }
            cout << endl;
            cout << "Average Grade: " << calculateAverage(id) << endl;
            cout << endl;
        }
    }
};

int main() {
    Gradebook gradebook;

    gradebook.addStudent(101, "Vaishnavi");
    gradebook.addGrade(101, 85);
    gradebook.addGrade(101, 90);
    gradebook.addGrade(101, 75);

    gradebook.addStudent(102, "Bansari");
    gradebook.addGrade(102, 80);
    gradebook.addGrade(102, 70);
    gradebook.addGrade(102, 85);

    gradebook.generateReport();

    return 0;
}
