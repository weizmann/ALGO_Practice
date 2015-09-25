#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

vector<vector<char> >board;

bool hasWord(int x, int y, const string& word) {
	if (!inRange(x, y)) {
		return false;
	}

	if (board[x][y] != word[0]) {
		return false;
	}

	if (word.size() == 1) {
		return true;
	} 

	for (int index = 0; index < 8; index ++) {
		const int nx = x + dx[index];
		const int ny = y + dy[index];
		if (hasWord(nx, ny, word.substr(1))) {
			return true;
		}
	}

	return false;
}

int main () {
	return 0;
}
