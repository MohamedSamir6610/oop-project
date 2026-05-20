#include <iostream>
using namespace std;

// =========================================================
// 1. MODEL: strictly holds your original data and constructor
// =========================================================
class DentalModel {
public:
    // your exact private data members (made public here so controller can access them)
    char regUser[50];
    char regPass[50];
    int accountFlag; 

    char patientName[50];
    char bookDate[50];
    char bookTime[50];

    // your exact constructor to initialize attributes
    DentalModel() {
        accountFlag = 0;
        regUser[0] = '\0';
        regPass[0] = '\0';
        patientName[0] = '\0';
        bookDate[0] = '\0';
        bookTime[0] = '\0';
    }
};

// =========================================================
// 2. VIEW: strictly handles the main interface menu screen
// =========================================================
class DentalView {
public:
    // your exact main menu screen from main function
    void showMenu() {
        cout << "\nMenu:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Book Appointment" << endl;
        cout << "3. Exit" << endl;
    }
};

// =========================================================
// 3. CONTROLLER: contains your exact original methods and loops
// =========================================================
class DentalController {
private:
    DentalModel model; // object composition to hold data state

public:
    // your exact method to show and handle register page
    void showRegister() {
        cout << "\nRegister Page" << endl;
        
        char inputUser[50];
        char inputPass[50];

        cout << "Enter username: ";
        cin >> inputUser;
        cout << "Enter password: ";
        cin >> inputPass;

        // your exact manual string copy for username
        int i = 0;
        while (inputUser[i] != '\0') {
            model.regUser[i] = inputUser[i]; // reads and writes directly using model object
            i++;
        }
        model.regUser[i] = '\0';

        // your exact manual string copy for password
        int j = 0;
        while (inputPass[j] != '\0') {
            model.regPass[j] = inputPass[j];
            j++;
        }
        model.regPass[j] = '\0';

        model.accountFlag = 1; // account is now saved and active
        cout << "Registration successful!" << endl;
    }

    // your exact method to show and handle book appointment page
    void showBooking() {
        cout << "\nBook Appointment Page" << endl;

        // check business logic if user has registered first
        if (model.accountFlag == 0) {
            cout << "Error: You must register first!" << endl;
            return;
        }

        char checkUser[50];
        char checkPass[50];

        cout << "Confirm username: ";
        cin >> checkUser;
        cout << "Confirm password: ";
        cin >> checkPass;

        // your exact manual string comparison for username
        int i = 0;
        int userMatch = 1; // 1 means match, 0 means mismatch
        while (checkUser[i] != '\0' || model.regUser[i] != '\0') {
            if (checkUser[i] != model.regUser[i]) {
                userMatch = 0;
                break;
            }
            i++;
        }

        // your exact manual string comparison for password
        int j = 0;
        int passMatch = 1; // 1 means match, 0 means mismatch
        while (checkPass[j] != '\0' || model.regPass[j] != '\0') {
            if (checkPass[j] != model.regPass[j]) {
                passMatch = 0;
                break;
            }
            j++;
        }

        // verify credentials to open booking inputs
        if (userMatch == 1 && passMatch == 1) {
            cout << "Login successful. Enter appointment details:" << endl;
            
            cout << "Patient Name: ";
            cin >> model.patientName;
            cout << "Date (YYYY-MM-DD): ";
            cin >> model.bookDate;
            cout << "Time (e.g. 05:00PM): ";
            cin >> model.bookTime;

            cout << "Appointment booked successfully for " << model.patientName << endl;
        } 
        else {
            cout << "Error: Invalid credentials!" << endl;
        }
    }
};

// =========================================================
// MAIN FUNCTION: drive system control
// =========================================================
int main() {
    DentalController clinic; // object instantiation from the controller class
    DentalView view;         // object instantiation from the view class
    int choice;

    do {
        view.showMenu(); // method invocation for menu display layer
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            clinic.showRegister(); // method invocation for register page
        } 
        else if (choice == 2) {
            clinic.showBooking(); // method invocation for booking page
        }
    } while (choice != 3);

    return 0;
}
            
