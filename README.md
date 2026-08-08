# ESP32-Servo-Web-Control

This project demonstrates how to control a **Servo Motor** using an **ESP32** through a web-based interface.  
The ESP32 creates a WiFi Access Point and hosts a webpage with **OPEN** and **CLOSE** buttons.  
The servo and LEDs respond to the selected command.

---

## 📦 Components

- ESP32 DevKit  
- Servo Motor  
- Green LED  
- Red LED  
- 2 × 220Ω Resistors  
- Jumper Wires  

---

## 🔌 Pin Configuration

| Component     | ESP32 Pin |
|---------------|-----------|
| Servo Signal  | GPIO 18   |
| Green LED     | GPIO 25   |
| Red LED       | GPIO 26   |

---

## ⚙️ How It Works

### **OPEN**
- Servo rotates to **90°**
- **Green LED ON**
- **Red LED OFF**

### **CLOSE**
- Servo rotates to **0°**
- **Green LED OFF**
- **Red LED ON**

---

## 📡 WiFi Access Point

The ESP32 creates its own WiFi network:

- **SSID:** ESP32-Servo  
- **Password:** 12345678  
- **IP Address:** 192.168.4.1  

Connect to this network using your phone or laptop, then open the IP address in a browser to access the control page.

---

## 🧪 Simulation (Wokwi)

This project was developed and tested using **Wokwi**.

- The servo motor and LEDs work correctly in the simulation.  
- The ESP32 successfully creates the WiFi Access Point and starts the web server.
  
<img width="729" height="816" alt="Screenshot 2026-08-08 025225" src="https://github.com/user-attachments/assets/869b78c8-ef49-4c43-ad16-16df339e74bf" />

### ⚠️ Limitation  
Wokwi requires a **paid WiFi Gateway** subscription to access the ESP32 web server from outside the simulator.  
However, the AP and web server **still run internally**, and all servo/LED actions can be tested.

---

## 🔗 Project Link

**Wokwi Project:**  
https://wokwi.com/projects/305569599398609473
---

## 📁 Files Included

- `ESP32_Servo_Web_Control.ino` — main program  
- `diagram.json` — Wokwi wiring diagram  
- `README.md` — project documentation  

