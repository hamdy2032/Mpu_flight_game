# ✈️ 3D City Flight Simulator (ESP32 + MPU6050 / MPU6500)

A browser-based 3D endless city flight simulator controlled in real-time using physical hand gestures via an **ESP32** and an **MPU6050 / MPU6500 IMU sensor**, powered by **Three.js** and the **Web Serial API**.

## 🎮 Live Demo
👉 **[Play Online Now](https://hamdy2032.github.io/Mpu_flight_game/)**  
*(Requires a desktop Chromium browser such as Google Chrome or Microsoft Edge with the ESP32 connected via USB)*

---

## ✨ Features
- **Real-Time Motion Control:** Smooth Roll & Pitch flight dynamics driven by physical hand tilt.
- **Zero-Install Web Interface:** Runs directly in the browser using the **Web Serial API** (`115200` baud) with no external drivers or local servers required.
- **In-Game Axis Calibration:** Built-in `Center (C)`, `Flip Left/Right`, `Flip Up/Down`, and `Swap Axes` controls to adapt immediately to any breadboard orientation.
- **Interactive Gameplay:** Coin collection, combo multipliers, real-time Speed/Altitude/Tilt HUD, and building obstacle avoidance.

---

## 🛠️ Hardware Architecture & Wiring (I2C)

The handheld controller uses an **ESP32 DevKit** to read raw accelerometer and gyroscope data over **I2C**, applies sensor fusion to compute stable Roll and Pitch angles, and streams them over USB Serial at 100Hz.

```text
+-----------------------+               +-----------------------+
|      ESP32 DevKit     |               |    MPU6050 Module     |
|                       |               |                       |
|                  3V3  |-------------->| VCC                   |
|                  GND  |-------------->| GND                   |
|              GPIO 22  |-------------->| SCL                   |
|              GPIO 21  |<------------->| SDA                   |
|                  GND  |-------------->| AD0 (Sets Addr 0x68)  |
+-----------------------+               +-----------------------+
