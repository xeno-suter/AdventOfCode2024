#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool checkWord(const vector<string>& grid, const string& word, int x, int y, int dx, int dy) {
    int n = grid.size();
    int m = grid[0].size();
    int len = word.length();

    for (int i = 0; i < len; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != word[i]) {
            return false;
        }
    }
    return true;
}

int countWordOccurrences(const vector<string>& grid, const string& word) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());

    vector<pair<int, int>> directions = {
        {0, 1},  {0, -1},  // Horizontal
        {1, 0},  {-1, 0},  // Vertical
        {1, 1},  {-1, -1}, // Diagonal (top-left to bottom-right and vice versa)
        {1, -1}, {-1, 1}   // Diagonal (top-right to bottom-left and vice versa)
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (const auto& dir : directions) {
                int dx = dir.first;
                int dy = dir.second;
                if (checkWord(grid, word, i, j, dx, dy)) {
                    count++;
                }
                if (checkWord(grid, reversedWord, i, j, dx, dy)) {
                    count++;
                }
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
    string word = "XMAS";

    while (getline(inputFile, line)) {
        grid.push_back(line);
    }
    inputFile.close();

    int result = countWordOccurrences(grid, word) / 2;

    cout << "The word " << word << " (including its reverse) appears " << result << " times in the grid." << endl;

    return 0;
}
