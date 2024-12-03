#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    regex all_pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");

    int total_sum = 0;
    bool mul_enabled = true;

    smatch match;
    string memory;
    while (getline(cin, memory)) {
        string::const_iterator search_start(memory.cbegin());

        while (regex_search(search_start, memory.cend(), match, all_pattern)) {
            if (match[0] == "do()") {
                mul_enabled = true;
            } else if (match[0] == "don't()") {
                mul_enabled = false;
            } else if (mul_enabled) {
                int a = stoi(match[1]);
                int b = stoi(match[2]);

                total_sum += a * b;
            }
            search_start = match.suffix().first;
        }
    }

    cout << "Total " << total_sum << endl;

    return 0;
}
