#include <algorithm>

#include "gtest/gtest.h"
#include "medir.h"
#include "problema3.h"

using namespace std;

vector<ruta> generar_rutas(int n) {
    vector<ruta> rutas;
    
    unsigned precio = 0;

    for(int i = 1; i <= n; i++) {
        // Ruta del nodo hacia la única fábrica (nodo 0)
        rutas.push_back(ruta(0, i, precio++));

        // Ruta entre el i-ésimo nodo y un nodo j al azar tal que 1 <= j < i
        if(i > 3) rutas.push_back(ruta(i, rand() % (i - 2) + 1, precio++));
    }

    return rutas;  
}

TEST(problema3, PerformanceMejorCaso) {
    medir(string("perf/problema3/mejor-caso.csv"),
          1000,
          20,
          [&] (int n) { return generar_rutas(n); },
          [&] (int n, const vector<ruta>& rutas) { problema3(n + 1, 1, rutas); }
          );
}

TEST(problema3, PerformancePeorCaso) {
    medir(string("perf/problema3/peor-caso.csv"),
          1000,
          20,
          [&] (int n) {
              vector<ruta> rutas = generar_rutas(n);
              reverse(rutas.begin(), rutas.end());
              return rutas;
          },
          [&] (int n, const vector<ruta>& rutas) { problema3(n + 1, 1, rutas); }
          );
}

TEST(problema3, PerformanceInstanciasAleatorias) {
    medir(string("perf/problema3/instancias-aleatorias.csv"),
          1000,
          20,
          [&] (int n) {
              vector<ruta> rutas = generar_rutas(n);
              random_shuffle(rutas.begin(), rutas.end());
              return rutas;
          },
          [&] (int n, const vector<ruta>& rutas) { problema3(n + 1, 1, rutas); }
          );
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}