#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;

// Función para preprocesar la cadena e insertar separadores
string preprocess(const string &s) {
    string t = "^"; // carácter de inicio
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$"; // carácter final
    return t;
}

// Algoritmo de Manacher para encontrar el palíndromo más largo
vector<int> manacher(const string &s) {
    string t = preprocess(s);
    int n = t.length();
    vector<int> p(n, 0); // Arreglo de longitudes de palíndromos
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i; // espejo de i respecto al centro

        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }

        // Intentar expandir palíndromo centrado en i
        while (t[i + (1 + p[i])] == t[i - (1 + p[i])]) {
            p[i]++;
        }

        // Actualizar centro y frontera si se expande más allá
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    return p;
}


int main() {
    string s;
    cout << "Ingresa una cadena: ";
    cin >> s;

    vector<int> p = manacher(s);

    // Encontrar el palíndromo más largo
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < p.size() - 1; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    int count = 0;
    for (int i = 1; i < p.size() - 1; ++i) {
        count+=(p[i]+1)/2;
    }

    cout << count << endl;


    int start = (centerIndex - maxLen) / 2;
    cout << "Palindromo mas largo: " << s.substr(start, maxLen) << endl;

    return 0;
}
