#include <iostream>

using namespace std;

int Graph[110];
int dp[110][65][65];

int main() {
	int row, col;
	cin >> row >> col;
	char input_char;

	memset(Graph, 0, sizeof(Graph));
	memset(dp, 0, sizeof(dp));

	for (int row_index = 0; row_index < row; row_index++) {
		for (int col_index = 0; col_index < col; col_index++) {
			cin >> input_char;
			if (input_char == 'P') {
				Graph[row_index] += (1 << col_index);
			}
		}
	}

	for (int index = 0; index <= (1 << col); index++) {
		
	}

}
