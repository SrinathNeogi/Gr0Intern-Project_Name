#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the average grade
double calculateAverage(const vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

// Function to get the letter grade based on the average
char getLetterGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<int> grades;
    int grade;

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter the grade for student " << i + 1 << ": ";
        cin >> grade;
        grades.push_back(grade);
    }

    // Calculate the average grade
    double average = calculateAverage(grades);

    // Get the letter grade
    char letterGrade = getLetterGrade(average);

    // Display the final grades
    cout << "Average grade: " << average << endl;
    cout << "Letter grade: " << letterGrade << endl;

    return 0;
}
