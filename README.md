# 🚦 Smart Traffic Routing System – Dijkstra’s Algorithm (C++)

This project simulates a smart traffic routing system using **Dijkstra’s Algorithm** to determine the shortest path in a city road network. It also allows **dynamic traffic light adjustment** by modifying edge weights and recalculating the route.

---

## 🧠 Key Features

- ✅ Calculates shortest path using Dijkstra’s Algorithm  
- ✅ Simulates real-time traffic changes (e.g., traffic light delay)  
- ✅ Recalculates path after traffic adjustment  
- ✅ Input validation for robust user experience  
- ✅ Works with undirected weighted graphs  

---

## 🛠️ How It Works

### 1. **Graph Input**
- User defines the number of nodes (intersections) and edges (roads).
- Each edge includes a source, destination, and weight (e.g., time, distance).

### 2. **Shortest Path Calculation**
- The system uses **Dijkstra’s Algorithm** to compute the shortest path from a starting point to the destination.

### 3. **Traffic Light Simulation**
- The user can change the weight of an edge to simulate traffic changes (e.g., delays from red lights).
- The algorithm recalculates the shortest path after adjustment.

---

## 📋 Example Workflow

```plaintext
Enter number of nodes and edges: 5 6
Enter edges (source destination weight):
0 1 10
0 2 5
1 2 2
1 3 1
2 3 9
3 4 4
Enter start and end nodes: 0 4

→ Shortest distance from 0 to 4 is: 15

Simulating traffic light adjustment...
Enter the edge (u v) and new weight: 1 3 20

→ Updated shortest distance from 0 to 4 is: 26
Smart-Traffic-System/
├── traffic_routing.cpp   # Main source code
├── README.md             # Project documentation (this file)
