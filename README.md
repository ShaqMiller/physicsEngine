# Physics Engine

A simple 2D physics simulation application built with C++ and SFML. This project demonstrates fundamental physics concepts such as collisions, object movement, and vector math using a custom-built engine and SFML for rendering.

---

## 🌀 How It Works

- **Physics Simulation:**  
  The engine simulates 2D objects like balls and walls, handling movement, collision detection, and response based on vector calculations.

- **Core Components:**  
  - `Vector`: Represents 2D vectors and provides vector operations.  
  - `Ball`: A circular object that can move and collide with other objects.  
  - `Wall`: Static lines representing boundaries or obstacles.

- **Rendering:**  
  The SFML library is used to draw objects and display the simulation visually in a window.

- **Input Handling:**  
  Basic user interaction (optional) to control or reset the simulation.

---

## ✅ Features

- 2D vector arithmetic and physics calculations  
- Collision detection between balls and walls  
- Real-time graphical display using SFML  
- Modular code structure with clear separation of physics and rendering logic  
- Simple build system using Makefile

---

## 📦 Dependencies

- [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/)  
- Standard C++17 compiler (e.g., g++)

> All required SFML DLLs are included in the `bin` directory.

---

## 🚀 Build and Run

1. **Build the project**  
   Run the following command in your project root directory (where the `Makefile` is located):

   ```bash
   make
