# 🧠 Live Memory Monitor

A simple, lightweight RAM usage monitor for **Linux** written in pure **C**.

This project displays total, free, available, and used memory in real-time, along with a colored progress bar for visual representation. 
Ideal for system enthusiasts, learners, or anyone who wants to keep an eye on their system's memory usage from the terminal.

----------------------------------------------------------------------

## 📸 Preview

https://github.com/user-attachments/assets/a5213fd1-01e8-4e32-a86b-f8e308dde9fa
----------------------------------------------------------------------

## ⚙️ Features

- 📊 **Live memory usage update**
- 🎨 **Colored output**
- 🧱 **Progress bar**
- 🧠 Clean and understandable C code
- 🐧 Linux-only (reads from "/proc/meminfo")

----------------------------------------------------------------------

## 🚀 How to Compile & Run

### 1. Clone the repository
```bash

git clone https://github.com/YOUR_USERNAME/Memory-Monitor.git

cd Memory-Monitor

gcc memory.c -o memory

./memory
