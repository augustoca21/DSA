# BFS (Breadth-First Search) en C++

Este archivo implementa el algoritmo de **Búsqueda en Anchura (BFS)** para grafos no dirigidos utilizando C++. BFS es una técnica de recorrido de grafos que explora todos los vecinos de un nodo antes de pasar al siguiente nivel.

---

## 📁 Archivo

- [`bfs_algorithm.cpp`](./bfs_algorithm.cpp): Implementación completa del algoritmo.

---

## 🧠 ¿Cómo funciona?

1. Se inicializa una cola con el nodo de inicio.
2. Se marca el nodo como visitado.
3. Mientras la cola no esté vacía:
   - Se extrae el nodo frontal.
   - Se recorren sus vecinos.
   - Se encolan los vecinos no visitados y se marcan como visitados.
4. El recorrido continúa hasta que todos los nodos alcanzables han sido visitados.

---

## 🧪 Ejemplo de grafo

```plaintext
Grafo no dirigido:

    0
   / \
  1   2
 / \   \
3   4 - 5
```

### Resultado esperado del recorrido BFS desde el nodo 0:
```plaintext
Visited node: 0
Visited node: 1
Visited node: 2
Visited node: 3
Visited node: 4
Visited node: 5
```

---

## 🛠️ Compilación y ejecución

```bash
g++ -std=c++17 bfs_algorithm.cpp -o bfs
./bfs
```

---

## 📚 Conceptos relacionados

- `queue<int>`: Estructura usada para manejar el orden FIFO del recorrido.
- `vector<vector<int>>`: Representación del grafo como lista de adyacencias.
- `vector<bool>`: Marca qué nodos han sido visitados.

---

## 📝 Notas

- Esta versión es para grafos **no dirigidos y no ponderados**.
- No se usa `new` ni punteros para evitar problemas de gestión de memoria.

---

## 🧩 Extensiones posibles

- Adaptar para grafos dirigidos.
- Incluir pesos y aplicar BFS modificado (como en Dijkstra con pesos 0-1).
- Añadir detección de ciclos o componentes conexas.

---

# DFS (Depth-First Search) en C++

Este archivo implementa el algoritmo de **Búsqueda en Profundidad (DFS)** para grafos no dirigidos utilizando C++. DFS explora tan profundo como sea posible antes de retroceder.

---

## 📁 Archivo

- [`dfs_algorithm.cpp`](./dfs_algorithm.cpp): Implementación completa del algoritmo.

---

## 🧠 ¿Cómo funciona?

1. Se inicia el recorrido desde un nodo dado.
2. Se marca como visitado.
3. Se llama recursivamente a todos los vecinos no visitados.
4. El proceso continúa hasta explorar completamente todos los caminos posibles desde el nodo de inicio.

---

## 🧪 Ejemplo de grafo

```plaintext
Grafo no dirigido:

    0
   / \
  1   2
 / \   \
3   4 - 5
```

### Resultado esperado del recorrido DFS desde el nodo 0:
> El orden puede variar dependiendo del orden de los vecinos en la lista de adyacencias. Un posible resultado:

```plaintext
Visited node: 0
Visited node: 1
Visited node: 3
Visited node: 5
Visited node: 4
Visited node: 2
```

---

## 🛠️ Compilación y ejecución

```bash
g++ -std=c++17 dfs_algorithm.cpp -o dfs
./dfs
```

---

## 📚 Conceptos relacionados

- `vector<vector<int>>`: Representación del grafo como lista de adyacencias.
- `vector<bool>`: Marca qué nodos han sido visitados.
- Recursividad: DFS se implementa naturalmente de forma recursiva.

---

## 📝 Notas

- Esta versión es para grafos **no dirigidos y no ponderados**.
- Se puede adaptar fácilmente para grafos dirigidos cambiando la lista de adyacencias.

---

## 🧩 Extensiones posibles

- Implementación iterativa usando pila (`stack`).
- Detectar ciclos.
- Clasificación topológica (en grafos dirigidos acíclicos).
- Conteo de componentes conexas.

---

