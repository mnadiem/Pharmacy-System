<div align="center">

# 💊 Pharmacy Management System

**A console-based pharmacy inventory manager built in C++ using a doubly linked list.**

<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++">
<img src="https://img.shields.io/badge/Core%20Concept-Doubly%20Linked%20List-6A5ACD?style=for-the-badge" alt="Doubly linked list">
<img src="https://img.shields.io/badge/Project-Data%20Structures-2E8B57?style=for-the-badge" alt="Data Structures project">

</div>

---

## 📌 Overview

This university project demonstrates how a **doubly linked list** can be used to manage a pharmacy's inventory. Each item stores a barcode, name, quantity, and unit price. Users interact with the system through a menu-driven terminal interface.

## ✨ Features

- **Add items** at the beginning or end of the list, or before an existing item.
- **Delete items** by barcode, with a confirmation prompt.
- **Modify item details**, including name, quantity, and price.
- **Search for items** by barcode.
- **Inventory check** with low-stock alerts for items with a quantity of 15 or less.
- **Display the current item list** in a simple itemized view.

## 🧠 Data Structure

Each item is represented by a node containing:

- Barcode
- Item name
- Quantity
- Price
- Pointer to the next node
- Pointer to the previous node

The doubly linked list supports traversal in both directions and demonstrates insertion and deletion operations at different positions.

## 🖥️ Screenshots

The following screenshots are included in the repository as examples of the console application and its workflow.

<div align="center">
  <img src="Pharmacy%20System/Picture1.png" alt="Pharmacy system screenshot 1" width="48%">
  <img src="Pharmacy%20System/Picture2.png" alt="Pharmacy system screenshot 2" width="48%">
  <img src="Pharmacy%20System/Picture3.png" alt="Pharmacy system screenshot 3" width="48%">
  <img src="Pharmacy%20System/Picture4.png" alt="Pharmacy system screenshot 4" width="48%">
</div>

## 🛠️ Build and Run

You need a C++ compiler such as **g++**.

From the repository root, run:

```bash
g++ "Pharmacy System/main.cpp" -o pharmacy-system
./pharmacy-system
```

On Windows, run the generated `pharmacy-system.exe` from Command Prompt or PowerShell.

## ⚠️ Current Scope

- This is an educational console application, not a production pharmacy or point-of-sale system.
- Inventory is stored in memory, so the data is not saved after the program exits.
- The current implementation is focused on inventory operations and does not integrate with a database, barcode scanner, or external payment system.

## 👥 Contributors

- Ahmed Samir Ibrahem El Sayed
- Mohamed Nadim Mohamed Mohamed

---

<div align="center">
  <sub>Created as a C++ data structures project.</sub>
</div>
