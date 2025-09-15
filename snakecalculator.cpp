
#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int Operation(const vector<string>& grid, int r, int& c) {
    
    int result = 0;
    char operation = '+';

    while (c < grid[r].size()) {

        char x = grid[r][c];

        if (isdigit(x)) {
            int num = x - '0';
            if (operation == '+') {
                result += num;
            }
            else if (operation == '-') {
                result -= num;
            }
            else if (operation == '*') {
                result *= num;
            }
        }
        else if (x == '+' || x == '-' || x == '*') {
            operation = x;
        }
        else if (x == 'v') {
            int bottomRow = r + 1;
            int newCol = 0;
            result += Operation(grid, bottomRow, newCol);
        }
        else if (x == '^') {
            x++;
            return result;
        }

        c++;
    }

    return result;
}

int main() {
    vector<string> grid = {
        "1234v3v1",
        "111^3^",
    };

    int col = 0;
    int result = Operation(grid, 0, col);

    cout << "\n";

    for (const string& row : grid) {
        cout << row << endl;
    }

    cout << "\n";
    cout << "The Numbers all adding up to this grid of numbers is -> " << result;

    return 0;
}
