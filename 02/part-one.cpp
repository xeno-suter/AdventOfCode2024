#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    string line;
    int safeCount = 0;

    while (getline(cin, line) && !line.empty())
    {
        istringstream ss(line);
        int x, y;
        bool increasing = true, decreasing = true, isSafe = true;

        if (ss >> x) {
            while (ss >> y)
            {
                int diff = y - x;

                if (abs(diff) < 1 || abs(diff) > 3) {
                    isSafe = false;
                    break;
                }

                if (diff > 0) {
                    decreasing = false;
                } else if (diff < 0) {
                    increasing = false;
                }

                x = y;
            }

            if (isSafe && (increasing || decreasing)) {
                safeCount++;
            }
        }
    }

    cout << "Safe: " << safeCount << endl;

    return 0;
}
