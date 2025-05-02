#include <iostream>
#include <vector>
#include <iomanip> // For setprecision

using namespace std;

class CGPACalculator {
private:
    vector<double> semesterGPAs;
    vector<int> creditHours;

public:
    void addSemester() {
        double gpa;
        int credits;
        
        cout << "Enter semester GPA (0.0 - 4.0): ";
        cin >> gpa;
        
        // Validate GPA input
        while (gpa < 0.0 || gpa > 4.0) {
            cout << "Invalid GPA! Please enter a value between 0.0 and 4.0: ";
            cin >> gpa;
        }
        
        cout << "Enter total credit hours for this semester: ";
        cin >> credits;
        
        // Validate credit hours
        while (credits <= 0) {
            cout << "Invalid credit hours! Please enter a positive number: ";
            cin >> credits;
        }
        
        semesterGPAs.push_back(gpa);
        creditHours.push_back(credits);
        
        cout << "Semester added successfully!\n\n";
    }
    
    double calculateCGPA() {
        if (semesterGPAs.empty()) {
            return 0.0;
        }
        
        double totalQualityPoints = 0.0;
        int totalCredits = 0;
        
        for (size_t i = 0; i < semesterGPAs.size(); ++i) {
            totalQualityPoints += semesterGPAs[i] * creditHours[i];
            totalCredits += creditHours[i];
        }
        
        return totalQualityPoints / totalCredits;
    }
    
    void displayAllSemesters() {
        if (semesterGPAs.empty()) {
            cout << "No semesters added yet.\n";
            return;
        }
        
        cout << "\nList of all semesters:\n";
        cout << "----------------------\n";
        cout << setw(10) << "Semester" << setw(15) << "GPA" << setw(20) << "Credit Hours\n";
        
        for (size_t i = 0; i < semesterGPAs.size(); ++i) {
            cout << setw(10) << i+1 
                 << setw(15) << fixed << setprecision(2) << semesterGPAs[i]
                 << setw(15) << creditHours[i] << endl;
        }
        cout << endl;
    }
    
    void resetData() {
        semesterGPAs.clear();
        creditHours.clear();
        cout << "All data has been reset.\n\n";
    }
};

void displayMenu() {
    cout << "\nCGPA Calculator Menu\n";
    cout << "--------------------\n";
    cout << "1. Add Semester GPA\n";
    cout << "2. Calculate Current CGPA\n";
    cout << "3. View All Semesters\n";
    cout << "4. Reset Data\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

int main() {
    CGPACalculator calculator;
    int choice;
    
    cout << "Welcome to CGPA Calculator!\n";
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                calculator.addSemester();
                break;
            case 2:
                cout << fixed << setprecision(2);
                cout << "\nYour current CGPA is: " << calculator.calculateCGPA() << "\n\n";
                break;
            case 3:
                calculator.displayAllSemesters();
                break;
            case 4:
                calculator.resetData();
                break;
            case 5:
                cout << "Thank you for using CGPA Calculator!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
    } while (choice != 5);
    
    return 0;
}