#ifndef LINKDETECTOR_H
#define LINKDETECTOR_H

#include <iostream>
#include <vector>
using namespace std;

class LinkDetector {
public:
    vector<pair<int, int>> findMissingLinks(int n, int m, vector<vector<int>> connections) {
        // Matrix to track connections
        vector<vector<bool>> check(m, vector<bool>(m, false));

        // Mark the connections as true in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < connections[i].size(); j++) {
                for (int k = j + 1; k < connections[i].size(); k++) {
                    check[connections[i][j]][connections[i][k]] = true;
                    check[connections[i][k]][connections[i][j]] = true;
                }
            }
        }

        // Vector to store missing connections
        vector<pair<int, int>> missingLinks;

        // Find missing connections
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (!check[i][j]) {
                    missingLinks.push_back({i + 1, j + 1});
                }
            }
        }

        return missingLinks;
    }
};
#endif // LINKDETECTOR_H