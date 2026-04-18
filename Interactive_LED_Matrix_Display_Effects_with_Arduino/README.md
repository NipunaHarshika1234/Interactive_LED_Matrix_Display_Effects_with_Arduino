# Arduino 8x8 LED Matrix Animation System

A real-time animation system built using Arduino and an 8x8 LED matrix. This project demonstrates multiple dynamic visual effects such as wave motion, checker patterns, center expansion, and random sparkles using efficient row-column multiplexing.

---

## 🚀 Features

- Wave animation (Up & Down)
- Center expansion effect
- Checkerboard animation pattern
- Random sparkle effect
- Smooth LED multiplexing control
- Frame buffer-based rendering system

---

## 🧠 How It Works

The system uses an 8x8 frame buffer stored in memory. Each animation updates this buffer, and a fast refresh (multiplexing) method scans rows and columns to display stable images on the LED matrix.

### Core Concepts Used:
- Row-column multiplexing
- Bitwise operations for LED control
- Frame buffering technique
- Microsecond-level refresh timing

---

## 🔧 Hardware Requirements

- Arduino UNO / Nano
- 8x8 LED Matrix
- Resistors (220Ω recommended)
- Jumper wires
- Breadboard

---
