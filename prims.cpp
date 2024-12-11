#include <iostream>
#include <cstring>
#define HIGH 99999
using namespace std;

class graph {
    int g[10][10], n;
    int v_array[10];
    string dept[10];

public:
    void initialize() {
        cout << "\nEnter total number of departments: ";
        cin >> n;

        cout << "\nEnter department names: ";
        for (int i = 0; i < n; i++) {
            cin >> dept[i];
        }

        cout << "\nEnter distances between departments:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    cout << "Distance between " << dept[i] << " and " << dept[j] << ": ";
                    cin >> g[i][j];
                } else {
                    g[i][j] = HIGH; // No self-loop, or assign HIGH if it's not relevant
                }
            }
        }
    }

    void display() {
        cout << "\nDepartment names: ";
        for (int i = 0; i < n; i++) {
            cout << dept[i] << "\t";
        }
        cout << endl;

        cout << "\nAdjacency matrix (Distances):\n";
        for (int i = 0; i < n; i++) {
            cout << dept[i];
            for (int j = 0; j < n; j++) {
                cout << "\t" << g[i][j];
            }
            cout << endl;
        }
    }

    void prims() {
        int cost = 0;
        memset(v_array, 0, sizeof(v_array)); // Initialize v_array with 0 (false)
        v_array[0] = true; // Start from the first department (0th index)
        cout << "\nEdge: Weight\n";

        int n_edges = 0;
        while (n_edges < n - 1) {
            int min = HIGH;
            int r = 0, c = 0;

            for (int i = 0; i < n; i++) {
                if (v_array[i]) {
                    for (int j = 0; j < n; j++) {
                        if (!v_array[j] && g[i][j] && g[i][j] < min) {
                            min = g[i][j];
                            r = i;
                            c = j;
                        }
                    }
                }
            }

            cout << dept[r] << " - " << dept[c] << ": " << g[r][c] << endl;
            cost += g[r][c];
            v_array[c] = true;
            n_edges++;
        }

        cout << "\nCost of minimum spanning tree using Prim's algorithm: " << cost << endl;
    }
};

int main() {
    graph g;
    g.initialize();
    g.display();
    g.prims();

    return 0;
}
