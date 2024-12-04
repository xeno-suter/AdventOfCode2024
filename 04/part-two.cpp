#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool checkXMAS(const vector<string>& grid, int cx, int cy) {
    int n = grid.size();
    int m = grid[0].size();

    if (cx - 1 < 0 || cx + 1 >= n || cy - 1 < 0 || cy + 1 >= m) {
        return false;
    }

    char topLeft = grid[cx - 1][cy - 1];
    char topRight = grid[cx - 1][cy + 1];
    char center = grid[cx][cy];
    char bottomLeft = grid[cx + 1][cy - 1];
    char bottomRight = grid[cx + 1][cy + 1];

    string diagonal1 = {topLeft, center, bottomRight}; // Top-left to bottom-right
    string diagonal2 = {topRight, center, bottomLeft}; // Top-right to bottom-left

    return (diagonal1 == "MAS" || diagonal1 == "SAM") &&
           (diagonal2 == "MAS" || diagonal2 == "SAM");
}

int countXMASPatterns(const vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (checkXMAS(grid, i, j)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    vector<string> grid;
    string line;

    while (getline(inputFile, line)) {
        grid.push_back(line);
    }
    inputFile.close();

    int result = countXMASPatterns(grid);

    cout << "The number of X-MAS patterns in the grid is " << result << "." << endl;

    return 0;
}
