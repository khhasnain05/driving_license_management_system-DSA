# 🚦 Driving License Management System (DSA Project)

A console based **Driving License Management System** developed in **C++** as a third semester **Data Structures and Algorithms (DSA)** project.

The application simulates the basic workflow of a driving license authority, allowing applicants to register, apply for learner permits, take driving tests, and receive licenses. The project demonstrates the practical implementation of data structures, file handling, and object oriented programming concepts.

---

# Features

### Applicant Module

* Register a new applicant
* Login using User ID and Password
* Apply for learner permits
* View learner permits
* View issued licenses
* Open medical form PDF

### Testing Officer Module

* Officer authentication
* Conduct computer based traffic sign test
* Conduct practical driving test
* Automatically issue license after passing both tests

### License Incharge Module

* View all registered users
* View all learner records
* View all license records
* Search applicants
* Display system statistics

---

# Technologies Used

* C++
* Object Oriented Programming (OOP)
* File Handling
* Windows API

---

# Data Structures Used

This project demonstrates multiple DSA concepts.

| Data Structure | Purpose |
|---------------|---------|
| Binary Search Tree | Store registered users |
| Queue | Breadth First Traversal |
| Stack | Inorder Traversal |
| Arrays | Store learners, licenses and questions |
| Hash Set (`unordered_set`) | Prevent duplicate User IDs and CNICs |

---

# Project Structure

```
Driving-License-Management-System
│
├── main.cpp
├── Medical Form.pdf
├── users.txt
├── learners.txt
├── licenses.txt
├── README.md
├── .gitignore
│
└── .vscode
    └── tasks.json
```

---

# Requirements

* Windows Operating System
* Visual Studio 2022 (Recommended)
* C++17 Compiler

---

# Installation

## Clone the repository

```bash
git clone https://github.com/khhasnain05/driving_license_management_system-DSA.git
```

Or download the project as a ZIP file from GitHub.

---

# Before Running

Make sure these files exist in the project folder.

```
users.txt
learners.txt
licenses.txt
Medical Form.pdf
```

If the text files are missing, simply create empty files with the same names.

---

# Build and Run

Open the project in Visual Studio.

Build the project.

```
Ctrl + Shift + B
```

Run the project.

```
Ctrl + F5
```

---

# Default Administrative Credentials

## Testing Officer

Username

```
admin
```

Password

```
root12345
```

## License Incharge

Username

```
incharge
```

Password

```
incharge123
```

---

# Data Storage

The application stores data locally using text files.

* users.txt
* learners.txt
* licenses.txt

All records are automatically loaded when the application starts and saved when changes occur.

---

# Project Workflow

```
Applicant Registration
        │
        ▼
Applicant Login
        │
        ▼
Apply for Learner Permit
        │
        ▼
Medical Form Verification
        │
        ▼
Computer Based Test
        │
        ▼
Practical Driving Test
        │
        ▼
Driving License Issued
```

---

# License

This project is developed for educational purposes.