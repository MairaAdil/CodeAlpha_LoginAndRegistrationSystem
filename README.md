# 🔐 Login & Registration System — CodeAlpha C++ Internship

A console-based **Login and Registration System** developed in C++ as part of the **CodeAlpha C++ Programming Internship — Task 2**.

The application provides a simple user authentication workflow where users can create an account, register a username and password, and later log in using their saved credentials. User information is stored in a local text file and checked during authentication.

---

## 📌 Project Overview

The **Login & Registration System** is designed to demonstrate the basic concepts behind user registration and authentication using C++.

The system allows users to:

* Register a new username and password
* Validate usernames and passwords
* Detect duplicate usernames
* Store registered credentials in a local file
* Log in using previously registered credentials
* Receive success and error messages
* Exit the application through a simple menu

The project also includes a colored console interface and sound feedback for successful and unsuccessful operations.

---

## 🏢 CodeAlpha Internship

**Internship:** CodeAlpha C++ Programming Internship
**Task:** Task 2 — Login and Registration System
**Language:** C++
**Application Type:** Console Application
**Platform:** Windows

---

## ✨ Main Features

### 📝 User Registration

Users can create an account by providing:

* Username
* Password

The registration process checks the entered information before saving the credentials.

### 👤 Username Validation

A username:

* Cannot be empty
* Can contain letters
* Can contain numbers
* Can contain underscores (`_`)
* Cannot contain spaces
* Cannot contain other special characters

Example of a valid username:

```text
Maira_123
```

### 🔎 Duplicate Username Detection

Before creating a new account, the program checks `users.txt` to determine whether the username already exists.

If the username is already registered, the user is asked to choose another one.

### 🔑 Password Validation

The program requires passwords to contain at least **6 characters**.

```text
Minimum password length: 6 characters
```

### 🔐 Login Verification

During login, the system:

1. Takes the username.
2. Takes the password.
3. Opens the credentials file.
4. Searches for a matching username and password.
5. Displays the appropriate result.

### 🔊 Audio Feedback

The program uses Windows `Beep()` functionality to provide different sounds for:

* Successful operations
* Errors

### 🎨 Console Interface

The application uses colored console text to distinguish:

* Menu options
* Input prompts
* Success messages
* Error messages
* Section headings

---

## 🔄 System Workflow

```text
                    ┌─────────────────────┐
                    │       Start         │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │     Main Menu       │
                    └──────────┬──────────┘
                               │
                 ┌─────────────┼─────────────┐
                 ▼             ▼             ▼
            Register         Login          Exit
                 │             │
                 ▼             ▼
        Validate Username   Enter Credentials
                 │             │
                 ▼             ▼
        Check Duplicate     Read users.txt
                 │             │
                 ▼             ▼
        Validate Password   Verify Credentials
                 │             │
                 ▼       ┌─────┴─────┐
          Save to File    │           │
                 │      Match       No Match
                 │       │           │
                 ▼       ▼           ▼
        Registration    Success     Error
          Successful
```

---

## 📂 Credential Storage

Registered credentials are stored locally in:

```text
users.txt
```

The program writes each username and password as a pair separated by a space.

Example structure:

```text
username1 password123
username2 mypass456
```

During login, the program reads the stored username and password pairs and compares them with the credentials entered by the user.

---

## ⚠️ Security Consideration

This project is intended as an **educational authentication system**.

The current implementation stores passwords in **plain text** inside `users.txt`. Therefore, it should **not be considered suitable for real-world authentication or production use**.

A production-ready authentication system should use techniques such as:

* Password hashing
* Salting
* Secure credential storage
* Encrypted communication
* Strong authentication policies
* Proper access control

This project focuses on demonstrating the basic C++ implementation of registration, file handling, validation, and login verification.

---

## 🧩 Core Functions

The program is organized into separate functions for different responsibilities.

### `validUsername()`

Checks whether the username follows the allowed character rules.

```cpp
bool validUsername(string username)
```

### `validPassword()`

Checks whether the password meets the minimum length requirement.

```cpp
bool validPassword(string password)
```

### `usernameExists()`

Searches `users.txt` to determine whether a username is already registered.

```cpp
bool usernameExists(string username)
```

### `registration()`

Handles the complete registration process, including validation and saving the new credentials.

```cpp
void registration()
```

### `login()`

Reads stored credentials and verifies the user's login information.

```cpp
void login()
```

### `setColor()`

Changes the Windows console text color.

```cpp
void setColor(int color)
```

### `successSound()` / `errorSound()`

Provide audio feedback for successful and unsuccessful actions.

---

## 🛠️ Technologies Used

### Programming Language

**C++**

### Libraries

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <windows.h>
```

### Important C++ Concepts

* Functions
* Strings
* File handling
* Input validation
* Loops
* Conditional statements
* Boolean functions
* Character validation
* File streams
* Console formatting
* Windows API functions

---

## 🖥️ Application Menu

When the program starts, the user is presented with:

```text
========================================
       LOGIN & REGISTRATION SYSTEM
========================================

1. Register
2. Login
3. Exit

Enter choice:
```

The user can select one of the three available operations.

---

## 📝 Registration Process

The registration workflow is:

```text
Enter Username
      ↓
Validate Username
      ↓
Check Existing Username
      ↓
Enter Password
      ↓
Validate Password
      ↓
Save Credentials
      ↓
Registration Successful
```

If an invalid username or password is entered, the program displays an appropriate error message and asks for valid information.

---

## 🔓 Login Process

The login workflow is:

```text
Enter Username
      ↓
Enter Password
      ↓
Open users.txt
      ↓
Search Stored Credentials
      ↓
   ┌──┴──┐
   ↓     ↓
 Match  No Match
   ↓     ↓
Success  Error
```

When the credentials match a registered account, the program displays:

```text
Login successful!
Welcome, username!
```

Otherwise, the user receives an invalid credentials message and can try again.

---

## ❌ Error Handling

The program handles several invalid situations, including:

* Empty or invalid usernames
* Unsupported username characters
* Duplicate usernames
* Passwords shorter than 6 characters
* Invalid menu selections
* Non-numeric menu input
* Missing `users.txt`
* File opening errors during registration

Error messages are displayed using a different console color and an error sound.

---

## 📁 Project Structure

```text
CodeAlpha_LoginAndRegistrationSystem/
│── 1. Screenshot.jpg
│── 2. Screenshot.jpg
│── 3. Screenshot.jpg
├── 4. Screenshot.jpg
├── README.md
└── main.cpp
```

> `users.txt` is created/updated by the program when users register. It contains the locally stored credentials used by the application.

---

## ⚙️ Requirements

To compile and run this project:

* Windows operating system
* C++ compiler
* C++ compatible IDE
* Support for Windows API

The project uses:

```cpp
#include <windows.h>
```

for console colors, delays, and sound effects.

---

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/MairaAdil/CodeAlpha_LoginAndRegistrationSystem.git
```

### 2. Open the Project

Open `main.cpp` in a C++ compatible IDE such as Visual Studio, Code::Blocks, or another Windows-based C++ development environment.

### 3. Compile the Program

Build/compile the C++ source file.

### 4. Run

Start the program and choose:

```text
1 → Register
2 → Login
3 → Exit
```

---

## 🧪 Example Usage

### Registration

```text
========================================
             REGISTRATION
========================================

Enter username: Maira_123
Enter password: password123

Registration successful!
```

### Login

```text
========================================
                 LOGIN
========================================

Enter username: Maira_123
Enter password: password123

Login successful!
Welcome, Maira_123!
```

### Invalid Login

```text
Invalid username or password!
Please try again.
```

---

## 🎯 Learning Objectives

This project provided practical experience with:

* Building a menu-driven C++ application
* Implementing registration logic
* Implementing login verification
* Working with text files
* Reading and writing file data
* Validating user input
* Detecting duplicate usernames
* Creating reusable functions
* Using Boolean validation functions
* Working with Windows console features
* Designing a basic authentication workflow

---

## 🚀 Future Improvements

The system could be further enhanced by adding:

* Password hashing
* Salted password storage
* Password masking during input
* Stronger password requirements
* Password recovery
* Account deletion
* Username/password update
* Login attempt limits
* User-specific files or a database
* Encrypted credential storage
* Session management
* Multi-user roles and permissions
* More secure authentication mechanisms

---

## ⚠️ Project Scope

This application was created as an **educational C++ project for the CodeAlpha Internship**.

It demonstrates the fundamental workflow of registration and login using local file storage. It is not intended to replace a production authentication system.

---

## 👩‍💻 Author

**Maira Adil**

**BS Artificial Intelligence Student**
University of Central Punjab

### Connect With Me

* **LinkedIn:** [linkedin.com/in/mairaadil](https://www.linkedin.com/in/mairaadil)
* **GitHub:** [github.com/MairaAdil](https://github.com/MairaAdil)

---

## 🏆 CodeAlpha Internship

This project was completed as **Task 2 — Login and Registration System** during the **CodeAlpha C++ Programming Internship**.

The project helped strengthen practical understanding of C++ functions, file handling, validation, and basic authentication workflows.

---

## 🎇 Acknowledgment

Special thanks to **CodeAlpha** for providing the internship opportunity and project-based learning experience to practice and apply C++ programming concepts.

---

⭐ If you found this project useful, feel free to explore the repository and leave a star.
