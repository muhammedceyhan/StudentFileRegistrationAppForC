# Student File Registration System

A simple Command Line Interface (CLI) application written in C to manage student records using file-based persistence.

## Features

- **Create Student**: Add new students with their name and surname. Student IDs are automatically assigned.
- **List Students**: View a list of all active (non-deleted) students.
- **Delete Student**: Remove a student record by their ID.

## Getting Started

### Prerequisites

- A C compiler (GCC recommended).

### Compilation

 To compile the program, run the following command in your terminal:

```bash
gcc FileStudentRecordSystem.c -o StudentRecordSystem
```

### Usage

1. Run the compiled executable:
   ```bash
   ./StudentRecordSystem
   ```
   (On Windows, you might run `StudentRecordSystem.exe`)

2. Follow the on-screen menu to perform operations:
   - Enter `1` to **Create a student**.
   - Enter `2` to **Delete a student**.
   - Enter `3` to **List students**.
   - Enter `0` to **Exit** the application.

## Data Storage

Student records are stored in a file named `StudentRecordSystem.txt` in the same directory as the executable. The file format is CSV-like:
`isDeleted,Name,Surname,ID`

## License

This project is open source.
