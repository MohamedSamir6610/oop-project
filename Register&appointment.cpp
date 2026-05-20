#include <iostream>
using namespace std;

// class for dental clinic system to handle register and booking pages
class DentalClinic {
private:
    // private data members for register page
    char regUser[50];
    char regPass[50];
    int accountFlag; // 0 means no account, 1 means registered

    // private data members for book appointment page
    char patientName[50];
    char bookDate[50];
    char bookTime[50];

public:
    // constructor to initialize object attributes in memory
    DentalClinic() {
        accountFlag = 0;
        regUser[0] = '\0';
        regPass[0] = '\0';
        patientName[0] = '\0';
        bookDate[0] = '\0';
        bookTime[0] = '\0';
    }

    // method to show and handle register page
    void showRegister() {
        cout << "\nRegister Page" << endl;
        
        char inputUser[50];
        char inputPass[50];

        cout << "Enter username: ";
        cin >> inputUser;
        cout << "Enter password: ";
        cin >> inputPass;

        // manual string copy for username
        int i = 0;
        while (inputUser[i] != '\0') {
            regUser[i] = inputUser[i];
            i++;
        }
        regUser[i] = '\0';

        // manual string copy for password
        int j = 0;
        while (inputPass[j] != '\0') {
            regPass[j] = inputPass[j];
            j++;
        }
        regPass[j] = '\0';

        accountFlag = 1; // account is now saved and active
        cout << "Registration successful!" << endl;
    }

    // method to show and handle book appointment page
    void showBooking() {
        cout << "\nBook Appointment Page" << endl;

        // check business logic if user has registered first
        if (accountFlag == 0) {
            cout << "Error: You must register first!" << endl;
            return;
        }

        char checkUser[50];
        char checkPass[50];

        cout << "Confirm username: ";
        cin >> checkUser;
        cout << "Confirm password: ";
        cin >> checkPass;

        // manual string comparison for username
        int i = 0;
        int userMatch = 1; // 1 means match, 0 means mismatch
        while (checkUser[i] != '\0' || regUser[i] != '\0') {
            if (checkUser[i] != regUser[i]) {
                userMatch = 0;
                break;
            }
            i++;
        }

        // manual string comparison for password
        int j = 0;
        int passMatch = 1;
        while (checkPass[j] != '\0' || regPass[j] != '\0') {
            if (checkPass[j] != regPass[j]) {
                passMatch = 0;
                break;
            }
            j++;
        }

        // verify credentials to open booking inputs
        if (userMatch == 1 && passMatch == 1) {
            cout << "Login successful. Enter appointment details:" << endl;
            
            cout << "Patient Name: ";
            cin >> patientName;
            cout << "Date (YYYY-MM-DD): ";
            cin >> bookDate;
            cout << "Time (e.g. 05:00PM): ";
            cin >> bookTime;

            cout << "Appointment booked successfully for " << patientName << endl;
        } 
        else {
            cout << "Error: Invalid credentials!" << endl;
        }
    }
};

int main() {
    DentalClinic clinic; // object instantiation from the class
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Book Appointment" << endl;
        cout << "3. Exit" << endl;
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
