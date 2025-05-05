#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

// Function Prototypes
void adduser(string username, string password, string role);
string who();
char studentmenu();
char adminmenu();
void clearscreen();
void mainHeader();
void addstudent();
void subheader();
void seatdetails();
void viewallstudents();
void addstudentintoarray(string name, float matric, float fsc, float ecat, string p1, string p2, string p3);
int seatm_menu();
void aggrigate();
void seatmangment();
void compareMarks(string name1, float ecat1, string name2, float ecat2);
void calculateAggregate(string name, float matricMarks, float interMarks, float ecatMarks);
int studentInfo();

// Data Structures
const int TOTAL_USER = 10;
int user_count = 0;
string usernamea[TOTAL_USER];
string passworda[TOTAL_USER];
string rolea[TOTAL_USER];

const int TOTAL_STUDENTS = 10;
int count_S = 0;
string student_namea[TOTAL_STUDENTS];
float matrica[TOTAL_STUDENTS];
float fsca[TOTAL_STUDENTS];
float ecata[TOTAL_STUDENTS];
string pref1a[TOTAL_STUDENTS];
string pref2a[TOTAL_STUDENTS];
string pref3a[TOTAL_STUDENTS];

string department[] = {"CS", "EE", "DS"};
int seatsa[] = {0, 0, 0};
float aggregate[TOTAL_STUDENTS];
bool resultannounce = false;

string username;

int main() {
    adduser("admin", "123", "ADMIN");
    adduser("student", "123", "STUDENT");

    while (true) {
        string w = who();

        if (w == "ADMIN") {
            system("cls");
            cout << "Welcome admin.." << endl;
            char adminoption;

            while (true) {
                adminoption = adminmenu();

                if (adminoption == '1') {
                    addstudent();
                } else if (adminoption == '2') {
                    viewallstudents();
                } else if (adminoption == '3') {
                    aggrigate();
                    cout << "Merit list calculated using aggregates." << endl;
                    clearscreen();
                } else if (adminoption == '4') {
                    cout << "Enter a username: ";
                    string uname, pass, role;
                    cin >> uname;
                    cout << "Enter a password: ";
                    cin >> pass;
                    cout << "Enter a role: ";
                    cin >> role;
                    adduser(uname, pass, role);
                } else if (adminoption == '5') {
                    seatmangment();
                } else if (adminoption == '6') {
                    resultannounce = true;
                    cout << "Result announced." << endl;
                    clearscreen();
                } else if (adminoption == '7') {
                    break;
                } else {
                    cout << "WRONG INPUT.." << endl;
                }
                clearscreen();
            }
        } else if (w == "STUDENT") {
            cout << "Welcome student.." << endl;
            char studentoption;
            while (true) {
                studentoption = studentmenu();

                if (studentoption == '1') {
                    int st_index = studentInfo();
                    if (st_index != -1) {
                        cout << "Name\tMatric\tFSC\tECAT\t1st\t2nd\t3rd" << endl;
                        cout << student_namea[st_index] << "\t" << matrica[st_index] << "\t"
                             << fsca[st_index] << "\t" << ecata[st_index] << "\t"
                             << pref1a[st_index] << "\t" << pref2a[st_index] << "\t" << pref3a[st_index] << endl;
                    } else {
                        cout << "Student not found!" << endl;
                    }
                } else if (studentoption == '2') {
                    if (resultannounce) {
                        int idx = studentInfo();
                        if (idx != -1) {
                            cout << "Your aggregate is: " << aggregate[idx] << "%" << endl;
                        }
                    } else {
                        cout << "Your result is not announced." << endl;
                    }
                } else if (studentoption == '3') {
                    break;
                } else {
                    cout << "Invalid Option!" << endl;
                }
                clearscreen();
            }
        } else {
            cout << "WRONG CREDENTIALS..." << endl;
        }
        clearscreen();
    }

    return 0;
}

// Function Definitions

string who() {
    cout << "Enter username: ";
    cin >> username;
    string password;
    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < user_count; i++) {
        if (usernamea[i] == username && passworda[i] == password) {
            return rolea[i];
        }
    }
    return "WRONG";
}

void adduser(string username, string password, string role) {
    if (user_count < TOTAL_USER) {
        usernamea[user_count] = username;
        passworda[user_count] = password;
        rolea[user_count] = role;
        user_count++;
    }
}

void mainHeader() {
    cout << "***********************************************************" << endl;
    cout << "         University Admission Management System            " << endl;
    cout << "***********************************************************" << endl;
}

char adminmenu() {
    mainHeader();
    cout << "Admin Menu" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. View All Students" << endl;
    cout << "3. Generate Merit List" << endl;
    cout << "4. Add User" << endl;
    cout << "5. Seat Management" << endl;
    cout << "6. Announce Result" << endl;
    cout << "7. Logout" << endl;
    char option;
    cout << "Your option: ";
    cin >> option;
    return option;
}

char studentmenu() {
    mainHeader();
    cout << "Student Menu" << endl;
    cout << "1. View Profile" << endl;
    cout << "2. Check Admission Status" << endl;
    cout << "3. Logout" << endl;
    char option;
    cout << "Your option: ";
    cin >> option;
    return option;
}

void clearscreen() {
    cout << "Press any key to continue...";
    getch();
    system("cls");
}

void subheader() {
    cout << "Choose your preferences:" << endl;
    cout << "1. CS - Computer Science" << endl;
    cout << "2. EE - Electrical Engineering" << endl;
    cout << "3. DS - Data Science" << endl;
}

void addstudent() {
    string name, pref1, pref2, pref3;
    float matric, fsc, ecat;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter matric marks (out of 1100): ";
    cin >> matric;
    cout << "Enter FSC marks (out of 550): ";
    cin >> fsc;
    cout << "Enter ECAT marks (out of 400): ";
    cin >> ecat;
    subheader();
    cout << "Enter 1st preference: ";
    cin >> pref1;
    cout << "Enter 2nd preference: ";
    cin >> pref2;
    cout << "Enter 3rd preference: ";
    cin >> pref3;
    addstudentintoarray(name, matric, fsc, ecat, pref1, pref2, pref3);
}

void addstudentintoarray(string name, float matric, float fsc, float ecat, string p1, string p2, string p3) {
    if (count_S < TOTAL_STUDENTS) {
        student_namea[count_S] = name;
        matrica[count_S] = matric;
        fsca[count_S] = fsc;
        ecata[count_S] = ecat;
        pref1a[count_S] = p1;
        pref2a[count_S] = p2;
        pref3a[count_S] = p3;
        count_S++;
    }
}

int seatm_menu() {
    mainHeader();
    cout << "Seat Management Menu:" << endl;
    cout << "1. Edit CS Capacity" << endl;
    cout << "2. Edit EE Capacity" << endl;
    cout << "3. Edit DS Capacity" << endl;
    cout << "4. View Seat Details" << endl;
    cout << "5. Back to Admin Menu" << endl;
    int option;
    cout << "Your option: ";
    cin >> option;
    return option;
}

void seatmangment() {
    int option;
    while (true) {
        option = seatm_menu();
        if (option >= 1 && option <= 3) {
            cout << "Enter new seat count for " << department[option - 1] << ": ";
            int count;
            cin >> count;
            seatsa[option - 1] = count;
        } else if (option == 4) {
            seatdetails();
        } else if (option == 5) {
            break;
        } else {
            cout << "Invalid option!" << endl;
        }
        clearscreen();
    }
}

void viewallstudents() {
    cout << "Name\tMatric\tFSC\tECAT\tPref1\tPref2\tPref3" << endl;
    for (int i = 0; i < count_S; i++) {
        cout << student_namea[i] << "\t" << matrica[i] << "\t" << fsca[i] << "\t"
             << ecata[i] << "\t" << pref1a[i] << "\t" << pref2a[i] << "\t" << pref3a[i] << endl;
    }
}

void aggrigate() {
    for (int i = 0; i < count_S; i++) {
        aggregate[i] = (matrica[i] / 1100.0) * 30 + (fsca[i] / 550.0) * 30 + (ecata[i] / 400.0) * 40;
    }
}

void seatdetails() {
    cout << "Department Seat Details:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << department[i] << ": " << seatsa[i] << " seats" << endl;
    }
}

int studentInfo() {
    for (int i = 0; i < count_S; i++) {
        if (username == student_namea[i]) {
            return i;
        }
    }
    return -1;
}

void compareMarks(string name1, float ecat1, string name2, float ecat2) {
    if (ecat1 > ecat2) {
        cout << name1 << " has higher ECAT marks and gets roll number 1." << endl;
    } else if (ecat2 > ecat1) {
        cout << name2 << " has higher ECAT marks and gets roll number 1." << endl;
    } else {
        cout << "Both have equal ECAT marks." << endl;
    }
}

void calculateAggregate(string name, float matricMarks, float interMarks, float ecatMarks) {
    float agg = (matricMarks / 1100.0) * 30 + (interMarks / 550.0) * 30 + (ecatMarks / 400.0) * 40;
    cout << "Aggregate of " << name << " is: " << agg << "%" << endl;
}

