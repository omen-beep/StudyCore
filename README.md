# StudyCore

**StudyCore** is a modular embedded systems project I built while studying microcontroller programming. It showcases my hands-on learning with MPLAB X IDE and the XC8 compiler, using the PIC microcontroller family.

This project helped me understand embedded system architecture, driver abstraction, and low-level C programming by developing drivers for commonly used components.

---

##  Why I Made This

I created this project during my studies as a way to apply theoretical knowledge in a practical way. Instead of relying on ready-made libraries, I wrote drivers from scratch for components like:

- 7-segment display
- Push buttons
- DC motor
- Keypad

It started as a learning exercise and eventually became a reusable foundation for future PIC projects.

---

##  Project Features

- Modular ECU layer with separate drivers for each component
- Application logic to demonstrate usage of drivers
- Developed using MPLAB X and XC8 compiler
- Organized project structure for clarity and reusability

---

##  Getting Started

### Requirements

- MPLAB X IDE (recommended version X.X or later)
- Microchip XC8 Compiler
- PIC microcontroller (adjust the code to your target chip if needed)

### How to Run

1. Clone or download this repo.
2. Open the project in MPLAB X IDE.
3. Connect your PIC development board.
4. Build and program the microcontroller.

---

##  Folder Structure

StudyCore/
│
├── ECU_Layer/ # Drivers for components
├── application.c # Main application logic
├── application.h
├── Makefile
├── .gitignore
└── README.md # You're here!

---

##  What I Learned

- Writing modular embedded drivers from scratch
- Using MPLAB X and understanding its build system
- Managing microcontroller I/O and timing
- Organizing embedded code for scalability
