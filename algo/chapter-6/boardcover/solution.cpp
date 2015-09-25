#include <iostream>
#include <vector>

using namespace std;

const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, -1}},
	{{0, 0}, {1, 0}, {1, -1}},
	{{0, 0}, {0, -1}, {-1, -1}},
};

bool set(vector<vector<int> >& board, int x, int y, int type, int delta) {
	bool success = true;
	for (int index = 0; index < 3; index++) {
		const int nx = x + coverType[index][type][0];
		const int ny = y + coverType[index][type][1];
		if (ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size()) {
			success = false;
		} else if ((board[nx][ny] += delta) > 1) {
			success = false;
		}
	}
	return success;
}

int cover(vector<vector<int> >& board) {
	int x = -1, y = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
		if (y != -1) {
			break;
		}
	}
	
	if (y == -1) {
		return 1;
	}

	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, x, y, type, 1)) {
			ret += cover(board);
		}
		set(board, x, y, type, -1);
	}

	return ret;
}


int main() {

	return 0;
}
