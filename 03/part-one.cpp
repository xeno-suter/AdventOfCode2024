#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    regex valid_mul_pattern(R"(mul\((\d+),(\d+)\))");

    int total_sum = 0;
    smatch match;

    string memory;

    while (getline(cin, memory)) {
        string::const_iterator search_start(memory.cbegin());
        while (regex_search(search_start, memory.cend(), match, valid_mul_pattern)) {
            int a = stoi(match[1]);
            int b = stoi(match[2]);

            total_sum += a * b;
            search_start = match.suffix().first;
        }
    }

    cout << "Total " << total_sum << endl;

    return 0;
}
