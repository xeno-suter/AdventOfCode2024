#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int distance = 0;
    vector<int> leftList;
    unordered_map<int, int> rightMap;

    int left, right;
    while (cin >> left >> right) {
        leftList.push_back(left);
        if (rightMap.find(right) == rightMap.end()) {
            rightMap[right] = 1;
        } else {
            rightMap[right]++;
        }
    }

    for (int i = 0; i < leftList.size(); i++) {
        distance += leftList[i] * rightMap[leftList[i]];
    }

    cout << distance << endl;

    return 0;
}