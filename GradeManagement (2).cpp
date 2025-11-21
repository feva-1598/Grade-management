/*

Group Members:

Kaleab Belayhun --- UGR/7539/17
Feven Biruk --- UGR/5878/17
Hewan yared --- UGR/4580/17
Firaol Terefe --- UGR/5582/17
Nahom Meki ---  UGR/9179/17

*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAX = 200;

string English[MAX] = {
    "Main Menu", "Admin Login", "Instructor Login", "Student Login", "Exit", "Choose an option: ", "Invalid input.",
    "Going back...", "Exiting program...", "Please create an admin account to start!", "Enter username: ",
    "Enter password: ", "Admin account creation successful!", "Login successful.", "Login failed.",
    "--- Admin Panel ---", "Register Instructor", "Register Course", "Register Student", "Update Instructor",
    "Update Course", "Update Student", "Display Instructors", "Display Courses", "Display Students",
    "Unregister/Delete Instructor", "Unregister/Delete Course", "Unregister/Delete Student",
    "Search for an Instructor", "Search for a Course", "Search for a Student", "0. Go Back",
    "Enter Instructor's Name: ", "Enter Instructor's PhoneNumber: ", "Enter Instructor's Digital Id Fin Number: ",
    "Enter Instructor's Username: ", "Enter Instructor's Password: ", "Instructor registered.",
    "Maximum instructor limit reached.", "Enter Course Name: ", "Enter Course ECTS: ", "Invalid ECTS.",
    "Enter Course Instructor ID: ", "Invalid Instructor ID.", "Course registered.", "Maximum course limit reached.",
    "Enter Student's Full Name: ", "Enter Student's Username: ", "Student registered.", "Maximum student limit reached.",
    "List of Instructors:", "ID: ", ", Name: ", ", PhoneNumber: ", ", FaydaFin: ", "List of Courses:",
    ". Course Name: ", ", ECTS: ", ", Course Instructor ID: ", "List of Students:", ". Student Name: ",
    "Enter Instructor ID to update: ", "Invalid Instructor ID.", "Enter new Name (current: ", "): ",
    "Enter new PhoneNumber (current: ", "Enter new Digital Id Fin Number (current: ", "Enter new Username (current: ",
    "Enter new Password: ", "Instructor updated.", "Enter Course ID to update: ", "Invalid Course ID.",
    "Enter new Course Name (current: ", "Enter new Course ECTS (current: ", "Enter new Course Instructor ID (current: ",
    "Course updated.", "Enter Student ID to update: ", "Invalid Student ID.", "Enter new FullName (current: ",
    "Student updated.", "Enter Instructor ID to delete: ", "Instructor not found.", "Instructor deleted.",
    "Enter Course ID to delete: ", "Course not found.", "Course deleted.", "Enter Student ID to Delete: ",
    "Student not found.", "Student deleted.", "Your Courses:", "No courses assigned.", "Enter Course ID: ",
    "Invalid course ID or not your course.", "Students:", "Enter Student ID: ", "Invalid student ID.",
    "Enter Grade (0-100): ", "Invalid grade.", "Grade assigned.", "Your Grades:", "GPA: ", "No grades available.",
    "Enter Instructor ID to search: ", "Instructor found!", "Fullname : ", "PhoneNumber : ",
    "Enter Course ID to search: ", "Course found!!", "Course Name: ", "Instructor ID: ",
    "Enter Student ID to search: ", "Student found!!", "Student Name: ", "--- Instructor Panel ---",
    "Grade Students", "View Courses", "--- Student Panel ---", "View Grades and GPA", "Enter your username: ",
    "Enter your password: ", "Please choose your language:", "1. English", "2. Amharic"
};

string Amharic[MAX] = {
    "ዋናው ገጽ", "የአስተዳዳሪ መግቢያ", "የአስተማሪ መግቢያ", "የተማሪ መግቢያ", "ውጣ", "አንድ አማራጭ ይምረጡ: ", "የተሳሳተ ግብዓት።",
    "ወደ ኋላ በመመለስ ላይ...", "ፕሮግራሙ እየወጣ ነው...", "ለመጀመር እባክዎ የአስተዳዳሪ መለያ ይፍጠሩ!", "የተጠቃሚ ስም ያስገቡ: ",
    "የይለፍ ቃል ያስገቡ: ", "የአስተዳዳሪ መለያ በተሳካ ሁኔታ ተፈጥሯል!", "በተሳካ ሁኔታ ገብተዋል/ገብተሻል።", "መግባት አልተሳካም።",
    "--- የአስተዳዳሪ ፓነል ---", "አስተማሪ ይመዝግቡ", "ትምህርት ይመዝግቡ", "ተማሪ ይመዝግቡ", "አስተማሪ ያዘምኑ",
    "ትምህርት ያዘምኑ", "ተማሪ ያዘምኑ", "አስተማሪዎችን ይመልከቱ", "ትምህርቶችን ይመልከቱ", "ተማሪዎችን ይመልከቱ",
    "አስተማሪ ያስወግዱ/ይሰርዙ", "ትምህርት ያስወግዱ/ይሰርዙ", "ተማሪ ያስወግዱ/ይሰርዙ",
    "አስተማሪ ይፈልጉ", "ትምህርት ይፈልጉ", "ተማሪ ይፈልጉ", "0. ወደ ኋላ ተመለስ",
    "የአስተማሪውን ስም ያስገቡ: ", "የአስተማሪውን ስልክ ቁጥር ያስገቡ: ", "የአስተማሪውን ዲጂታል መታወቂያ ፊን ቁጥር ያስገቡ: ",
    "የአስተማሪውን የተጠቃሚ ስም ያስገቡ: ", "የአስተማሪውን የይለፍ ቃል ያስገቡ: ", "አስተማሪ ተመዝግቧል።",
    "ከፍተኛው የአስተማሪ ገደብ ደርሷል።", "የኮርስ ስም ያስገቡ: ", "የኮርስ ECTS ያስገቡ: ", "የተሳሳተ ECTS።",
    "የኮርስ አስተማሪ መታወቂያ ያስገቡ: ", "የተሳሳተ አስተማሪ መታወቂያ።", "ኮርስ ተመዝግቧል።", "ከፍተኛው የኮርስ ገደብ ደርሷል።",
    "የተማሪውን ሙሉ ስም ያስገቡ: ", "የተማሪውን የተጠቃሚ ስም ያስገቡ: ", "ተማሪ ተመዝግቧል።", "ከፍተኛው የተማሪ ገደብ ደርሷል።",
    "የአስተማሪዎች ዝርዝር:", "መታወቂያ: ", ", ስም: ", ", ስልክ ቁጥር: ", ", ፋይዳ ፊን: ", "የኮርሶች ዝርዝር:",
    ". የኮርስ ስም: ", ", ECTS: ", ", የኮርስ አስተማሪ መታወቂያ: ", "የተማሪዎች ዝርዝር:", ". የተማሪ ስም: ",
    "ለማዘመን የአስተማሪ መታወቂያ ያስገቡ: ", "የተሳሳተ አስተማሪ መታወቂያ።", "አዲስ ስም ያስገቡ (አሁን ያለው: ", "): ",
    "አዲስ ስልክ ቁጥር ያስገቡ (አሁን ያለው: ", "አዲስ ዲጂታል መታወቂያ ፊን ቁጥር ያስገቡ (አሁን ያለው: ", "አዲስ የተጠቃሚ ስም ያስገቡ (አሁን ያለው: ",
    "አዲስ የይለፍ ቃል ያስገቡ: ", "አስተማሪው ዘምኗል።", "ለማዘመን የኮርስ መታወቂያ ያስገቡ: ", "የተሳሳተ የኮርስ መታወቂያ።",
    "አዲስ የኮርስ ስም ያስገቡ (አሁን ያለው: ", "አዲስ የኮርስ ECTS ያስገቡ (አሁን ያለው: ", "አዲስ የኮርስ አስተማሪ መታወቂያ ያስገቡ (አሁን ያለው: ",
    "ኮርሱ ዘምኗል።", "ለማዘመን የተማሪ መታወቂያ ያስገቡ: ", "የተሳሳተ የተማሪ መታወቂያ።", "አዲስ ሙሉ ስም ያስገቡ (አሁን ያለው: ",
    "ተማሪው ዘምኗል።", "ለመሰረዝ የአስተማሪ መታወቂያ ያስገቡ: ", "አስተማሪ አልተገኘም።", "አስተማሪ ተሰርዟል።",
    "ለመሰረዝ የኮርስ መታወቂያ ያስገቡ: ", "ኮርስ አልተገኘም።", "ኮርስ ተሰርዟል።", "ለመሰረዝ የተማሪ መታወቂያ ያስገቡ: ",
    "ተማሪ አልተገኘም።", "ተማሪ ተሰርዟል።", "የእርስዎ ኮርሶች:", "ኮርሶች አልተመደቡም።", "የኮርስ መታወቂያ ያስገቡ: ",
    "የተሳሳተ የኮርስ መታወቂያ ወይም የእርስዎ ኮርስ አይደለም።", "ተማሪዎች:", "የተማሪ መታወቂያ ያስገቡ: ", "የተሳሳተ የተማሪ መታወቂያ።",
    "ውጤት ያስገቡ (0-100): ", "የተሳሳተ ውጤት።", "ውጤት ተመድቧል።", "የእርስዎ ውጤቶች:", "GPA: ", "ምንም ውጤቶች የሉም።",
    "ለመፈለግ የአስተማሪ መታወቂያ ያስገቡ: ", "አስተማሪ ተገኝቷል!", "ሙሉ ስም : ", "ስልክ ቁጥር : ",
    "ለመፈለግ የኮርስ መታወቂያ ያስገቡ: ", "ኮርስ ተገኝቷል!!", "የኮርስ ስም: ", "የአስተማሪ መታወቂያ: ",
    "ለመፈለግ የተማሪ መታወቂያ ያስገቡ: ", "ተማሪ ተገኝቷል!!", "የተማሪ ስም: ", "--- የአስተማሪ ፓነል ---",
    "ተማሪዎችን ደረጃ ስጥ", "ኮርሶችን ተመልከት", "--- የተማሪ ፓነል ---", "ውጤቶችን እና GPA ይመልከቱ", "የተጠቃሚ ስምዎን ያስገቡ: ",
    "የይለፍ ቃልዎን ያስገቡ: ", "እባክዎ ቋንቋዎን ይምረጡ:", "1. እንግሊዝኛ", "2. አማርኛ"
};

string* translation[2] = {Amharic, English};

string instructors[MAX][3];
string courseNames[MAX];
string students[MAX];

int courseEctsAndInstructor[MAX][2];

int studentGrades[MAX][MAX];
string instructorCredentials[MAX][2];
string studentCredentials[MAX][2];

// Admin credentials
string adminUserName, adminPassword;

int instructorCount = 0;
int courseCount = 0;
int studentCount = 0;

// Clear console
void clearConsole() {
    system("cls");
}

// Display Functions
void displayInstructors(int chosen) {
    cout << "\n" << translation[chosen][50] << "\n";
    for (int i = 0; i < instructorCount; i++) {
        cout  << i + 1 << ". "
             << translation[chosen][51] << instructors[i][0]
             << translation[chosen][52] << instructors[i][1]
             << translation[chosen][53] << instructors[i][2] << "\n";
    }
}

void displayCourses(int chosen) {
    cout << "\n" << translation[chosen][55] << "\n";
    for (int i = 0; i < courseCount; i++) {
        cout << i + 1 << translation[chosen][56] << courseNames[i]
             << translation[chosen][57] << courseEctsAndInstructor[i][0]
             << translation[chosen][58] << courseEctsAndInstructor[i][1] << "\n";
    }
}

void displayStudents(int chosen) {
    cout << "\n" << translation[chosen][59] << "\n";
    for (int i = 0; i < studentCount; i++) {
        cout << i + 1 << translation[chosen][60] << students[i] << endl;
    }
}

// Register Functions
void registerInstructor(int chosen) {
    if (instructorCount < MAX) {
        cout << "\n" << translation[chosen][32];
        cin.ignore(1, '\n');
        getline(cin, instructors[instructorCount][0]);
        cout << translation[chosen][33];
        getline(cin, instructors[instructorCount][1]);
        cout << translation[chosen][34];
        getline(cin, instructors[instructorCount][2]);
        cout << translation[chosen][35];
        getline(cin, instructorCredentials[instructorCount][0]);
        cout << translation[chosen][36];
        getline(cin, instructorCredentials[instructorCount][1]);
        instructorCount++;
        cout << translation[chosen][37] << "\n";
    } else {
        cout << translation[chosen][38] << "\n";
    }
    system("pause");
    clearConsole();
}

void registerCourse(int chosen) {
    if (courseCount < MAX) {
        cout << "\n" << translation[chosen][39];
        cin.ignore(1, '\n');
        getline(cin, courseNames[courseCount]);
        cout << translation[chosen][40];
        int ects;
        cin >> ects;
        if (!cin || ects <= 0) {
            cout << translation[chosen][41] << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
            system("pause");
            clearConsole();
            return;
        }
        courseEctsAndInstructor[courseCount][0] = ects;
        displayInstructors(chosen);
        cout << translation[chosen][42] << ": ";
        int instructorId;
        cin >> instructorId;
        if (!cin || instructorId < 1 || instructorId > instructorCount) {
            cout << translation[chosen][43] << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
            system("pause");
            clearConsole();
            return;
        }
        courseEctsAndInstructor[courseCount][1] = instructorId;
        courseCount++;
        cout << translation[chosen][44] << "\n";
    } else {
        cout << translation[chosen][45] << "\n";
    }
    system("pause");
    clearConsole();
}

void registerStudent(int chosen) {
    if (studentCount < MAX) {
        cout << "\n" << translation[chosen][46];
        cin.ignore(1, '\n');
        getline(cin, students[studentCount]);
        cout << "\n" << translation[chosen][47];
        getline(cin, studentCredentials[studentCount][0]);
        cout << translation[chosen][11];
        getline(cin, studentCredentials[studentCount][1]);
        for (int i = 0; i < MAX; i++) {
            studentGrades[studentCount][i] = -1;
        }
        studentCount++;
        cout << translation[chosen][48] << "\n";
    } else {
        cout << translation[chosen][49] << "\n";
    }
    system("pause");
    clearConsole();
}

// Update Functions
void updateInstructor(int chosen) {
    int id;
    cout << "\n" << translation[chosen][61];
    cin >> id;
    if (!cin || id < 1 || id > instructorCount) {
        cout << translation[chosen][62] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    cout << translation[chosen][63] << instructors[i][0] << translation[chosen][64];
    cin.ignore(1, '\n');
    getline(cin, instructors[i][0]);
    cout << translation[chosen][65] << instructors[i][1] << translation[chosen][64];
    getline(cin, instructors[i][1]);
    cout << translation[chosen][66] << instructors[i][2] << translation[chosen][64];
    getline(cin, instructors[i][2]);
    cout << translation[chosen][67] << instructorCredentials[i][0] << translation[chosen][64];
    getline(cin, instructorCredentials[i][0]);
    cout << translation[chosen][68];
    getline(cin, instructorCredentials[i][1]);
    cout << translation[chosen][69] << "\n";
    system("pause");
    clearConsole();
}

void updateCourse(int chosen) {
    int id;
    cout << "\n" << translation[chosen][70];
    cin >> id;
    if (!cin || id < 1 || id > courseCount) {
        cout << translation[chosen][71] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    cout << translation[chosen][72] << courseNames[i] << translation[chosen][64];
    cin.ignore(1, '\n');
    getline(cin, courseNames[i]);
    cout << translation[chosen][73] << courseEctsAndInstructor[i][0] << translation[chosen][64];
    int ects;
    cin >> ects;
    if (!cin || ects <= 0) {
        cout << translation[chosen][41] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    courseEctsAndInstructor[i][0] = ects;
    displayInstructors(chosen);
    cout << translation[chosen][73] << courseEctsAndInstructor[i][1] << translation[chosen][64];
    int instructorId;
    cin >> instructorId;
    if (!cin || instructorId < 1 || instructorId > instructorCount) {
        cout << translation[chosen][43] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    courseEctsAndInstructor[i][1] = instructorId;
    cout << translation[chosen][75] << "\n";
    system("pause");
    clearConsole();
}

void updateStudent(int chosen) {
    int id;
    cout << "\n" << translation[chosen][76];
    cin >> id;
    if (!cin || id < 1 || id > studentCount) {
        cout << translation[chosen][77] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    cout << translation[chosen][78] << students[i] << translation[chosen][64];
    cin.ignore(1, '\n');
    getline(cin, students[i]);
    cout << translation[chosen][67] << studentCredentials[i][0] << translation[chosen][64];
    getline(cin, studentCredentials[i][0]);
    cout << translation[chosen][68];
    getline(cin, studentCredentials[i][1]);
    cout << translation[chosen][79] << "\n";
    system("pause");
    clearConsole();
}

// Delete Functions
void deleteInstructor(int chosen) {
    int id;
    cout << "\n" << translation[chosen][80];
    cin >> id;
    if (!cin || id < 1 || id > instructorCount) {
        cout << translation[chosen][81] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    for (int j = i; j < instructorCount - 1; j++) {
        instructors[j][0] = instructors[j + 1][0];
        instructors[j][1] = instructors[j + 1][1];
        instructors[j][2] = instructors[j + 1][2];
        instructorCredentials[j][0] = instructorCredentials[j + 1][0];
        instructorCredentials[j][1] = instructorCredentials[j + 1][1];
    }
    instructorCount--;
    cout << translation[chosen][82] << "\n";
    system("pause");
    clearConsole();
}

void deleteCourse(int chosen) {
    int id;
    cout << "\n" << translation[chosen][83];
    cin >> id;
    if (!cin || id < 1 || id > courseCount) {
        cout << translation[chosen][84] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    for (int j = i; j < courseCount - 1; j++) {
        courseNames[j] = courseNames[j + 1];
        courseEctsAndInstructor[j][0] = courseEctsAndInstructor[j + 1][0];
        courseEctsAndInstructor[j][1] = courseEctsAndInstructor[j + 1][1];
    }
    for (int k = 0; k < studentCount; k++) {
        studentGrades[k][i] = -1;
        for (int j = i; j < courseCount - 1; j++) {
            studentGrades[k][j] = studentGrades[k][j + 1];
        }
    }
    courseCount--;
    cout << translation[chosen][85] << "\n";
    system("pause");
    clearConsole();
}

void deleteStudent(int chosen) {
    int id;
    cout << "\n" << translation[chosen][86];
    cin >> id;
    if (!cin || id < 1 || id > studentCount) {
        cout << translation[chosen][87] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    for (int j = i; j < studentCount - 1; j++) {
        students[j] = students[j + 1];
        studentCredentials[j][0] = studentCredentials[j + 1][0];
        studentCredentials[j][1] = studentCredentials[j + 1][1];
    }
    studentCount--;
    cout << translation[chosen][88] << "\n";
    system("pause");
    clearConsole();
}

// Instructor Functions
void instructorGradeStudents(int instructorId, int chosen) {
    int studentId, courseId, grade;
    bool hasCourses = false;
    cout << "\n" << translation[chosen][89] << "\n";
    for (int i = 0; i < courseCount; i++) {
        if (courseEctsAndInstructor[i][1] == instructorId) {
            cout << i + 1 << ". " << courseNames[i] << "\n";
            hasCourses = true;
        }
    }
    if (!hasCourses) {
        cout << translation[chosen][90] << "\n";
        system("pause");
        clearConsole();
        return;
    }
    cout << "\n" << translation[chosen][91];
    cin >> courseId;
    if (!cin || courseId < 1 || courseId > courseCount || courseEctsAndInstructor[courseId - 1][1] != instructorId) {
        cout << translation[chosen][92] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    cout << "\n" << translation[chosen][93] << "\n";
    for (int i = 0; i < studentCount; i++) {
        cout << i + 1 << ". " << students[i] << "\n";
    }
    cout << translation[chosen][94];
    cin >> studentId;
    if (!cin || studentId < 1 || studentId > studentCount) {
        cout << translation[chosen][95] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    cout << translation[chosen][96];
    cin >> grade;
    if (!cin || grade < 0 || grade > 100) {
        cout << translation[chosen][97] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    studentGrades[studentId - 1][courseId - 1] = grade;
    cout << translation[chosen][98] << "\n";
    system("pause");
    clearConsole();
}

// Student Functions
void viewStudentGrades(int studentId, int chosen) {
    double totalPoints = 0.0;
    int totalEcts = 0;
    cout << "\n" << translation[chosen][99] << "\n";
    for (int i = 0; i < courseCount; i++) {
        if (studentGrades[studentId - 1][i] != -1) {
            double gpaPoints;
            int grade = studentGrades[studentId - 1][i];
            if (grade >= 90) gpaPoints = 4.0;
            else if (grade >= 80) gpaPoints = 3.0;
            else if (grade >= 70) gpaPoints = 2.0;
            else if (grade >= 60) gpaPoints = 1.0;
            else gpaPoints = 0.0;
            cout << courseNames[i] << ": " << grade << " (ECTS: " << courseEctsAndInstructor[i][0] << ")\n";
            totalPoints += gpaPoints * courseEctsAndInstructor[i][0];
            totalEcts += courseEctsAndInstructor[i][0];
        }
    }
    if (totalEcts > 0) {
        double gpa = totalPoints / totalEcts;
        cout << "\n" << translation[chosen][100] << fixed << setprecision(2) << gpa << "\n";
    } else {
        cout << "\n" << translation[chosen][101] << "\n";
    }
    system("pause");
    clearConsole();
}

// Search Functions
void searchInstructors(int chosen) {
    int id;
    cout << "\n" << translation[chosen][103];
    cin >> id;
    if (!cin || id < 1 || id > instructorCount) {
        cout << translation[chosen][63] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    cout << translation[chosen][104] << "\n";
    cout << translation[chosen][105] << instructors[i][0] << "\n";
    cout << translation[chosen][106] << instructors[i][1] << "\n";
    system("pause");
    clearConsole();
}

void searchCourses(int chosen) {
    int id;
    cout << "\n" << translation[chosen][106];
    cin >> id;
    if (!cin || id < 1 || id > courseCount) {
        cout << translation[chosen][71] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    cout << "\n" << translation[chosen][107] << "\n";
    cout << translation[chosen][108] << courseNames[i] << "\n";
    cout << translation[chosen][57] << courseEctsAndInstructor[i][0] << "\n";
    cout << translation[chosen][109] << courseEctsAndInstructor[i][1] << "\n";
    system("pause");
    clearConsole();
}

void searchStudents(int chosen) {
    int id;
    cout << "\n" << translation[chosen][110];
    cin >> id;
    if (!cin || id < 1 || id > studentCount) {
        cout << translation[chosen][77] << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        clearConsole();
        return;
    }
    int i = id - 1;
    cout << "\n" << translation[chosen][111] << "\n";
    cout << translation[chosen][112] << students[i] << "\n";
    system("pause");
    clearConsole();
}

// Admin Panel
void adminTasks(int chosen) {
    int choice;
    do {
        cout << "\n" << translation[chosen][15] << "\n";
        cout << "1. " << translation[chosen][16] << "\n";
        cout << "2. " << translation[chosen][17] << "\n";
        cout << "3. " << translation[chosen][18] << "\n";
        cout << "4. " << translation[chosen][19] << "\n";
        cout << "5. " << translation[chosen][20] << "\n";
        cout << "6. " << translation[chosen][21] << "\n";
        cout << "7. " << translation[chosen][22] << "\n";
        cout << "8. " << translation[chosen][23] << "\n";
        cout << "9. " << translation[chosen][24] << "\n";
        cout << "10. " << translation[chosen][25] << "\n";
        cout << "11. " << translation[chosen][26] << "\n";
        cout << "12. " << translation[chosen][27] << "\n";
        cout << "13. " << translation[chosen][28] << "\n";
        cout << "14. " << translation[chosen][29] << "\n";
        cout << "15. " << translation[chosen][30] << "\n";
        cout << translation[chosen][31] << "\n";
        cout << translation[chosen][5];
        cin >> choice;
        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << translation[chosen][6] << "\n";
            system("pause");
            clearConsole();
            continue;
        }
        clearConsole();
        switch (choice) {
            case 1: registerInstructor(chosen); break;
            case 2: registerCourse(chosen); break;
            case 3: registerStudent(chosen); break;
            case 4: updateInstructor(chosen); break;
            case 5: updateCourse(chosen); break;
            case 6: updateStudent(chosen); break;
            case 7: displayInstructors(chosen); system("pause"); clearConsole(); break;
            case 8: displayCourses(chosen); system("pause"); clearConsole(); break;
            case 9: displayStudents(chosen); system("pause"); clearConsole(); break;
            case 10: deleteInstructor(chosen); break;
            case 11: deleteCourse(chosen); break;
            case 12: deleteStudent(chosen); break;
            case 13: searchInstructors(chosen); break;
            case 14: searchCourses(chosen); break;
            case 15: searchStudents(chosen); break;
            case 0: cout << translation[chosen][7] << "\n"; clearConsole(); break;
            default: cout << translation[chosen][6] << "\n"; system("pause"); clearConsole();
        }
    } while (choice != 0);
}

// Instructor Panel
void instructorTasks(int instructorId, int chosen) {
    int choice;
    do {
        cout << "\n" << translation[chosen][113] << "\n";
        cout << "1. " << translation[chosen][114] << "\n";
        cout << "2. " << translation[chosen][115] << "\n";
        cout << translation[chosen][31] << "\n";
        cout << translation[chosen][5] << "\n";
        cin >> choice;
        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << translation[chosen][7] << "\n";
            system("pause");
            clearConsole();
            continue;
        }
        clearConsole();
        switch (choice) {
            case 1: instructorGradeStudents(instructorId, chosen); break;
            case 2: displayCourses(chosen); system("pause"); clearConsole(); break;
            case 0: cout << translation[chosen][8] << "\n"; clearConsole(); break;
            default: cout << translation[chosen][7] << "\n"; system("pause"); clearConsole();
        }
    } while (choice != 0);
}

// Student Panel
void studentTasks(int studentId, int chosen) {
    int choice;
    do {
        cout << "\n" << translation[chosen][116] << "\n";
        cout << "1. " << translation[chosen][117] << "\n";
        cout << "2. " << translation[chosen][115] << "\n";
        cout << translation[chosen][31] << "\n";
        cout << translation[chosen][5] << "\n";
        cin >> choice;
        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << translation[chosen][7] << "\n";
            system("pause");
            clearConsole();
            continue;
        }
        clearConsole();
        switch (choice) {
            case 1: viewStudentGrades(studentId, chosen); break;
            case 2: displayCourses(chosen); system("pause"); clearConsole(); break;
            case 0: cout << translation[chosen][8] << "\n"; clearConsole(); break;
            default: cout << translation[chosen][7] << "\n"; system("pause"); clearConsole();
        }
    } while (choice != 0);
}

// Login
void login(int role, int chosen) {
    string username, password;
    cout << "\n" << translation[chosen][10];
    cin.ignore(1, '\n');
    getline(cin, username);
    cout << translation[chosen][11];
    getline(cin, password);
    clearConsole();
    switch (role) {
        case 1: // Admin
            if (username == adminUserName && password == adminPassword) {
                cout << "\n" << translation[chosen][13] << "\n";
                system("pause");
                clearConsole();
                adminTasks(chosen);
            } else {
                cout << "\n" << translation[chosen][14] << "\n";
                system("pause");
                clearConsole();
            }
            break;
        case 2: // Instructor
            for (int i = 0; i < instructorCount; i++) {
                if (username == instructorCredentials[i][0] && password == instructorCredentials[i][1]) {
                    cout << "\n" << translation[chosen][13] << "\n";
                    system("pause");
                    clearConsole();
                    instructorTasks(i + 1, chosen);
                    return;
                }
            }
            cout << "\n" << translation[chosen][14] << "\n";
            system("pause");
            clearConsole();
            break;
        case 3: // Student
            for (int i = 0; i < studentCount; i++) {
                if (username == studentCredentials[i][0] && password == studentCredentials[i][1]) {
                    cout << "\n" << translation[chosen][13] << "\n";
                    system("pause");
                    clearConsole();
                    studentTasks(i + 1, chosen);
                    return;
                }
            }
            cout << "\n" << translation[chosen][14] << "\n";
            system("pause");
            clearConsole();
            break;
    }
}

// Main
int main() {
    system("chcp 65001");
    system("cls");
    int chosen = 1;
    int choice;
    cout << "Please choose a language to start\n";
    cout << "0. Amharic\n";
    cout << "1. English\n\n";
    cout << "Your choice: ";
    cin >> chosen;
    if (!cin || (chosen != 0 && chosen != 1)) {
        cin.clear();
        cin.ignore(10000, '\n');
        chosen = 0;
    }
    cin.ignore(10000, '\n');
    cout << "\n" << translation[chosen][9] << "\n";
    cout << translation[chosen][10];
    getline(cin, adminUserName);
    cout << translation[chosen][11];
    getline(cin, adminPassword);
    cout << "\n" << translation[chosen][12] << "\n";
    system("pause");
    clearConsole();
    do {
        cout << "\n--- " << translation[chosen][0] << " ---\n";
        cout << "1. " << translation[chosen][1] << "\n";
        cout << "2. " << translation[chosen][2] << "\n";
        cout << "3. " << translation[chosen][3] << "\n";
        cout << "0. " << translation[chosen][4] << "\n";
        cout << translation[chosen][5];
        cin >> choice;
        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << translation[chosen][6] << "\n";
            system("pause");
            clearConsole();
            continue;
        }
        clearConsole();
        switch (choice) {
            case 1: login(1, chosen); break;
            case 2: login(2, chosen); break;
            case 3: login(3, chosen); break;
            case 0: cout << translation[chosen][8] << "\n"; break;
            default: cout << translation[chosen][6] << "\n"; system("pause"); clearConsole();
        }
    } while (choice != 0);
    return 0;
}
