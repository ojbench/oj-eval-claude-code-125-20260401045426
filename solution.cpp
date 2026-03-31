#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        // union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        vector<int> i_vals(n), j_vals(n), e_vals(n);
        map<int, int> compress;

        // Read all constraints and collect all variables
        for (int k = 0; k < n; k++) {
            scanf("%d %d %d", &i_vals[k], &j_vals[k], &e_vals[k]);
            compress[i_vals[k]] = 0;
            compress[j_vals[k]] = 0;
        }

        // Coordinate compression
        int idx = 0;
        for (auto& p : compress) {
            p.second = idx++;
        }

        // Process constraints in two passes
        // First pass: process all equality constraints
        UnionFind uf(idx);
        for (int k = 0; k < n; k++) {
            if (e_vals[k] == 1) {
                int ci = compress[i_vals[k]];
                int cj = compress[j_vals[k]];
                uf.unite(ci, cj);
            }
        }

        // Second pass: check inequality constraints
        bool satisfiable = true;
        for (int k = 0; k < n; k++) {
            if (e_vals[k] == 0) {
                int ci = compress[i_vals[k]];
                int cj = compress[j_vals[k]];
                if (uf.same(ci, cj)) {
                    satisfiable = false;
                    break;
                }
            }
        }

        printf("%s\n", satisfiable ? "YES" : "NO");
    }

    return 0;
}
