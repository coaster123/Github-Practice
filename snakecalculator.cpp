#include <cctype>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

long long Operation(long long acc, char symbol, long long digit) {
    
    if (symbol == '+') {
        return acc + digit; 
    } 
    if (symbol == '-') { 
        return acc - digit; 
    } 
    if (symbol == '*') {
        return acc * digit; 
    }

}

long long solve(const vector<string>& grid, int r, int c, long long acc, char symbol) {
    
    if (r < 0 || r >= (int)grid.size()){
        return acc;
    }
    if (c >= (int)grid[r].size()) {
        return acc;
    }

    char cell = grid[r][c];

    if (isdigit((unsigned char)cell)) {
        acc = Operation(acc, symbol, cell - '0');
    }

    if (cell == '+' || cell == '-' || cell == '*') {
        char newOper = cell;
        return solve(grid, r, c + 1, acc, newOper);
    }

    if (cell == '^') {
        if (r - 1 >= 0) {
            long long up = solve(grid, r - 1, c, acc, symbol);
            return solve(grid, r, c + 1, up, symbol);
        }
        else {
            return solve(grid, r, c + 1, acc, symbol);
        }
    }

    if (cell == 'v') {
        if (r + 1 < (int)grid.size()) {
            long long down = solve(grid, r + 1, c, acc, symbol);
            return solve(grid, r, c + 1, down, symbol);
        }
        else {
            return solve(grid, r, c + 1, acc, symbol);
        }
    }

    return solve(grid, r, c + 1, acc, symbol);
}



long long run(const vector<string>& grid) {
    if (grid.empty()){
        return 0;
    }
    else{
        return solve(grid, 0, 0, 0, '+');
    }
}

int main() {
    vector<string> program = {
        "257*233+6v790-12",
        "61247833212+*9^3"
    };

    cout << "Program result: " << run(program) << "\n";

    return 0;
}
