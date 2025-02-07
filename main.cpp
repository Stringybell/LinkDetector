#include "LinkDetector.h"  // Make sure to include the header file for the class

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    // Input connections
    vector<vector<int>> connections(n);
    for (int i = 0; i < n; i++) {
        int mat;
        cin >> mat;
        connections[i].resize(mat);
        for (int j = 0; j < mat; j++) {
            cin >> connections[i][j];
            connections[i][j]--;
        }
    }

    // Create an instance of LinkDetector
    LinkDetector detector;
    // Find missing links
    vector<pair<int, int>> missingLinks = detector.findMissingLinks(n, m, connections);

    // Output the missing links
    cout << missingLinks.size() << endl;
    for (const auto& link : missingLinks) {
        cout << link.first << " " << link.second << endl;
    }

    return 0;
}
