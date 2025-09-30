# Dijkstra's Algorithm en C++

Este archivo implementa el algoritmo de **Dijkstra** para encontrar las distancias más cortas desde un nodo de inicio a todos los demás en un grafo dirigido con pesos positivos.

---

## 📁 Archivo

- [`dijkstra_algorithm.cpp`](./dijkstra_algorithm.cpp): Implementación del algoritmo de Dijkstra con `priority_queue`.

---

## 🧠 ¿Cómo funciona?

1. Se inicializan todas las distancias como infinitas excepto la del nodo de inicio.
2. Se utiliza una cola de prioridad (`priority_queue`) para procesar los nodos con la menor distancia conocida.
3. Se actualizan las distancias a los vecinos si se encuentra un camino más corto.
4. Se repite hasta que todos los nodos han sido procesados.

---

## 🧪 Ejemplo de grafo

```plaintext
Grafo dirigido y ponderado (pesos positivos):

0 -> 1 (10)
0 -> 2 (3)
1 -> 2 (1)
1 -> 3 (2)
2 -> 1 (4)
2 -> 3 (8)
2 -> 4 (2)
3 -> 4 (7)
4 -> 3 (9)
```

### Resultado esperado:
```plaintext
Distance from 0 to 0: 0
Distance from 0 to 1: 7
Distance from 0 to 2: 3
Distance from 0 to 3: 9
Distance from 0 to 4: 5
```

---

## 🛠️ Compilación y ejecución

```bash
g++ -std=c++17 dijkstra_algorithm.cpp -o dijkstra
./dijkstra
```

---

## 📚 Conceptos clave

- `priority_queue`: Para seleccionar el nodo con menor distancia conocida.
- `vector<vector<pair<int, int>>>`: Lista de adyacencias con pesos.
- `numeric_limits<int>::max()`: Representa infinito.

---

## 📝 Notas

- Solo funciona correctamente con **pesos no negativos**.
- Para grafos con pesos negativos, considera Bellman-Ford.

---

## 🧩 Extensiones posibles

- Guardar el camino más corto (no solo la distancia).
- Aplicar en mapas o grids.
- Optimizar para grafos muy grandes con estructuras más avanzadas.

---
