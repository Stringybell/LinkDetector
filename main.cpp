#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Number of nodes and number of connections
    int n, m;
    cin >> n >> m;
    // Matrix to track connections
    bool check[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            // Initialize all connections to false
            check[i][j] = false;
        }
    }

    // Vector to store connections for each node
    vector<vector<int>> node(n);
    for (int i = 0; i < n; i++) {
        // Number of connections for the current node
        int mat;
        cin >> mat;
        for (int j = 0; j < mat; j++) {
            // Connection data
            int newdata;
            cin >> newdata;
            if (newdata > 0 && newdata <= m) {
                // Store the connection
                node[i].push_back(newdata - 1);
            }
        }
        // Mark the connections as true in the matrix
        for (int x = 0; x < node[i].size(); x++) {
            for (int y = x + 1; y < node[i].size(); y++) {
                check[node[i][x]][node[i][y]] = true;
                check[node[i][y]][node[i][x]] = true;
            }
        }
    }

    // Count of missing connections
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (!check[i][j]) {
                // Increment count if connection is missing
                count++;
            }
        }
    }
    // Output the count of missing connections
    cout << count << endl;

    // Output the pairs of nodes that are not connected
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (!check[i][j]) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}
