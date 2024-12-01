#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int distance = 0;

    vector<int> leftList;
    vector<int> rightList;

    int left, right;
    while (cin >> left >> right) {
        leftList.push_back(left);
        rightList.push_back(right);
    }

    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    for (int i = 0; i < leftList.size(); i++) {
        distance += abs(leftList[i] - rightList[i]);
    }

    cout << distance << endl;

    return 0;
}