# Student Record Management System

This project is a simple Student Record Management System written in C. It allows you to add, display, search, update, and delete student records. Additionally, you can save the student data to a file and load it back into the system.

## Features

- **Add Student:** Add a new student to the system.
- **Display All Students:** Display the details of all students.
- **Search Student by PRN:** Search for a student by their PRN (Permanent Registration Number).
- **Update Student Information by PRN:** Update the details of a student identified by their PRN.
- **Delete Student:** Delete a student record from the system.
- **Save Data to File:** Save all student records to a text file.
- **Load Data from File:** Load student records from a text file.

## Structure

The project consists of the following components:

- **Student Structure:** Defines the structure to represent a student with fields such as roll number, PRN, full name, branch, division, and marks.
- **Menu Display:** Displays a menu of options for the user to interact with the system.
- **Input Handling:** Functions to handle user inputs and validate them.
- **File Operations:** Functions to save student data to a file and load data from a file.

## Functions

- `void displayMenu()`: Displays the main menu.
- `void clearBuffer()`: Clears the input buffer to handle input errors.
- `int isDuplicatePRN(struct Student students[], int numStudents, const char *prn)`: Checks for duplicate PRNs.
- `void addStudent(struct Student students[], int *numStudents)`: Adds a new student to the system.
- `void displayAllStudents(struct Student students[], int numStudents)`: Displays all students.
- `void searchStudentByPRN(struct Student students[], int numStudents)`: Searches for a student by PRN.
- `void updateStudentByPRN(struct Student students[], int numStudents)`: Updates student information by PRN.
- `void deleteStudent(struct Student students[], int *numStudents)`: Deletes a student record.
- `void saveDataToFile(struct Student students[], int numStudents)`: Saves student data to a file.
- `void loadDataFromFile(struct Student students[], int *numStudents)`: Loads student data from a file.

## Usage

1. **Compile the program:**
   ```sh
   gcc -o student_management student_management.c
   ```

2. **Run the program:**
   ```sh
   ./student_management
   ```

3. **Follow the menu options:**
   - Enter `1` to add a student.
   - Enter `2` to display all students.
   - Enter `3` to search for a student by PRN.
   - Enter `4` to update a student's information by PRN.
   - Enter `5` to delete a student.
   - Enter `6` to save student data to a file.
   - Enter `7` to load student data from a file.
   - Enter `8` to exit the program.

## Example

Here’s an example interaction with the system:

```
Student Record Management System
1. Add Student
2. Display All Students
3. Search Student by PRN
4. Update Student Information by PRN
5. Delete Student
6. Save Data to File
7. Load Data from File
8. Exit
Enter your choice: 1

Enter Roll Number: 101
Enter PRN: PRN2024
Enter Full Name: John Doe
Enter Branch: CSE
Enter Division (A to V): B
Enter Marks: 85.5
Student added successfully.

Enter your choice: 2

All Students:
Roll Number: 101, PRN: PRN2024, Name: John Doe, Branch: CSE, Division: B, Marks: 85.50

Enter your choice: 6
Data saved to file successfully.

Enter your choice: 8
Exiting program.
```

## Notes

- Ensure the file `student_data.txt` exists in the same directory as the executable when loading data.
- The system allows a maximum of 100 students.
- Division input should be a character from A to V.
- Marks should be a floating-point number.

## Contributing

Feel free to submit issues or pull requests for improvements and bug fixes.

## License

This project is licensed under the MIT License.

---

This README provides a clear overview of your project, its features, and how to use it. It will help users understand the functionality and structure of your Student Record Management System.
