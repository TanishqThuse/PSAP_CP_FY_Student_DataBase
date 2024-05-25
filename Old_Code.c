#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILENAME "student_data.dat"

// Structure to represent a student
struct Student {
    int rollNumber;
    char prn[15];
    char fullName[100];
    char branch[20];
    char division;
    float marks;
};

// Function to display the menu
void displayMenu() {
    printf("\nStudent Record Management System\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by PRN\n");
    printf("4. Update Student Information by PRN\n");
    printf("5. Delete Student\n");
    printf("6. Save Data to File\n");
    printf("7. Load Data from File\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

// Function to handle input errors
void clearBuffer() {
    while (getchar() != '\n');
}

// Function to check for duplicate PRNs
int isDuplicatePRN(struct Student students[], int numStudents, const char *prn) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].prn, prn) == 0) {
            return 1; // Duplicate found
        }
    }
    return 0; // No duplicate
}

// Function to add a new student
void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents == MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter Roll Number: ");
    int rollNumber;
    if (scanf("%d", &rollNumber) != 1) {
        printf("Invalid input. Roll Number must be an integer.\n");
        clearBuffer();
        return;
    }

    printf("Enter PRN: ");
    char prn[15];
    scanf("%s", prn);

    if (isDuplicatePRN(students, *numStudents, prn)) {
        printf("Student with PRN %s already exists.\n", prn);
        return;
    }

    students[*numStudents].rollNumber = rollNumber;
    strcpy(students[*numStudents].prn, prn);

    printf("Enter Full Name: ");
    scanf(" %[^\n]", students[*numStudents].fullName);

    printf("Enter Branch: ");
    scanf("%s", students[*numStudents].branch);

    printf("Enter Division (A to V): ");
    if (scanf(" %c", &students[*numStudents].division) != 1 ||
        (students[*numStudents].division < 'A' || students[*numStudents].division > 'V')) {
        printf("Invalid input. Division must be A to V.\n");
        clearBuffer();
        return;
    }

    printf("Enter Marks: ");
    if (scanf("%f", &students[*numStudents].marks) != 1) {
        printf("Invalid input. Marks must be a floating-point number.\n");
        clearBuffer();
        return;
    }

    (*numStudents)++;
    printf("Student added successfully.\n");
}

// Function to display all students
void displayAllStudents(struct Student students[], int numStudents) {
    printf("\nAll Students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll Number: %d, PRN: %s, Name: %s, Branch: %s, Division: %c, Marks: %.2f\n",
               students[i].rollNumber, students[i].prn, students[i].fullName, students[i].branch, students[i].division, students[i].marks);
    }
}

// Function to search for a student by PRN
void searchStudentByPRN(struct Student students[], int numStudents) {
    char prn[15];
    printf("Enter PRN to search: ");
    scanf("%s", prn);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].prn, prn) == 0) {
            printf("Student found:\n");
            printf("Roll Number: %d, PRN: %s, Name: %s, Branch: %s, Division: %c, Marks: %.2f\n",
                   students[i].rollNumber, students[i].prn, students[i].fullName, students[i].branch, students[i].division, students[i].marks);
            return;
        }
    }

    printf("Student with PRN %s not found.\n", prn);
}

// Function to update student information by PRN
void updateStudentByPRN(struct Student students[], int numStudents) {
    char prn[15];
    printf("Enter PRN to update: ");
    scanf("%s", prn);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].prn, prn) == 0) {
            printf("Enter new Roll Number: ");
            if (scanf("%d", &students[i].rollNumber) != 1) {
                printf("Invalid input. Roll Number must be an integer.\n");
                clearBuffer();
                return;
            }

            printf("Enter new Full Name: ");
            scanf(" %[^\n]", students[i].fullName);

            printf("Enter new Branch: ");
            scanf("%s", students[i].branch);

            printf("Enter new Division (A to V): ");
            if (scanf(" %c", &students[i].division) != 1 ||
                (students[i].division < 'A' || students[i].division > 'V')) {
                printf("Invalid input. Division must be A to V.\n");
                clearBuffer();
                return;
            }

            printf("Enter new Marks: ");
            if (scanf("%f", &students[i].marks) != 1) {
                printf("Invalid input. Marks must be a floating-point number.\n");
                clearBuffer();
                return;
            }

            printf("Student information updated successfully.\n");
            return;
        }
    }

    printf("Student with PRN %s not found.\n", prn);
}]

// Function to delete a student
void deleteStudent(struct Student students[], int *numStudents) {
    char prn[15];
    printf("Enter PRN to delete: ");
    scanf("%s", prn);

    for (int i = 0; i < *numStudents; i++) {
        if (strcmp(students[i].prn, prn) == 0) {
            // Shift elements to remove the student
            for (int j = i; j < *numStudents - 1; j++) {
                students[j] = students[j + 1];
            }

            (*numStudents)--;
            printf("Student deleted successfully.\n");
            return;
        }
    }

    printf("Student with PRN %s not found.\n", prn);
}

// Function to save data to a file
void saveDataToFile(struct Student students[], int numStudents) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(students, sizeof(struct Student), numStudents, file);
    fclose(file);

    printf("Data saved to file successfully.\n");
}

// Function to load data from a file
void loadDataFromFile(struct Student students[], int *numStudents) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    *numStudents = fread(students, sizeof(struct Student), MAX_STUDENTS, file);

    if (fclose(file) != 0) {
        printf("Error closing file.\n");
        return;
    }

    printf("Data loaded from file successfully.\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayAllStudents(students, numStudents);
                break;
            case 3:
                searchStudentByPRN(students, numStudents);
                break;
            case 4:
                updateStudentByPRN(students, numStudents);
                break;
            case 5:
                deleteStudent(students, &numStudents);
                break;
            case 6:
                saveDataToFile(students, numStudents);
                break;
            case 7:
                loadDataFromFile(students, &numStudents);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}