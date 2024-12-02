#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

bool isSafe(const vector<int>& levels) {    
    bool increasing = levels[1] > levels[0];

    for (size_t i = 1; i < levels.size(); ++i)
    {
        int diff = levels[i] - levels[i - 1];

        if (abs(diff) < 1 || abs(diff) > 3) return false;
        if ((levels[i] > levels[i - 1]) != increasing) return false;
    }
    return true;
}

bool canBeMadeSafe(const vector<int>& levels) {
    for (size_t i = 0; i < levels.size(); ++i)
    {
        vector<int> modifiedLevels = levels;
        modifiedLevels.erase(modifiedLevels.begin() + i);

        if (isSafe(modifiedLevels)) return true;
    }

    return false;
}

int main() {
    string inputLine;
    vector<vector<int> > reports;

    while (getline(cin, inputLine))
    {
        stringstream ss(inputLine);
        vector<int> levels;
        
        int num;
        while (ss >> num) levels.push_back(num);
        reports.push_back(levels);
    }

    int safeCount = 0;

    for (const auto& report : reports) {
        if (isSafe(report) || canBeMadeSafe(report)) {
            ++safeCount;
        }
    }

    cout << "Safe: " << safeCount << endl;
    return 0;
}
