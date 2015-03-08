#include <iostream>

using namespace std;

int Graph[110];
int dp[110][65][65];
int available_state_in_row[65];
int available_state_count;
int available_cannon_in_row[65];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int row, col;
	cin >> row >> col;
	char input_char;

	memset(Graph, 0, sizeof(Graph));
	memset(dp, 0, sizeof(dp));

	for (int row_index = 0; row_index < row; row_index++) {
		for (int col_index = 0; col_index < col; col_index++) {
			cin >> input_char;
			if (input_char == 'H') {
				Graph[row_index] += (1 << col_index);
			}
		}
	}

	available_state_count = 0;
	int MAX_NUM = 0;
	for (int index = 0; index <= (1 << col); index++) {
		int num = index;
		if ((num & (num << 1)) || (num & (num << 2)) || (num & (num >> 1)) || (num & (num >> 2))) {
			continue;
		}
		available_state_count++;
		available_state_in_row[available_state_count] = num;
		int cannon_count = 0;
		while (num) {
			if (num % 2) {
				cannon_count++;
			}
			num = num >> 1;
		}
		available_cannon_in_row[available_state_count] = cannon_count;
	}

	for (int index = 0; index < available_state_count; index++) {
		if (available_state_in_row[index] & Graph[0]) {
			continue;
		}
		dp[0][index][0] = available_cannon_in_row[index];
		if (dp[0][index][0] > MAX_NUM) {
			MAX_NUM = dp[0][index][0];
		}
	}	

	for (int index = 0; index < available_state_count; index++) {
		if (available_state_in_row[index] & Graph[1]) {
			continue;
		}
		for (int first_row_index = 0; first_row_index < available_state_count; first_row_index++) {
			if (available_state_in_row[first_row_index] & Graph[0]) {
				continue;
			}
			if (available_state_in_row[first_row_index] & available_state_in_row[index]) {
				continue;
			}
			dp[1][index][first_row_index] = max(dp[1][index][first_row_index], dp[0][first_row_index][0] + available_cannon_in_row[index]);
			if (dp[1][index][first_row_index] > MAX_NUM) {
				MAX_NUM = dp[1][index][first_row_index];
			}
		}
	}

	for (int row_index = 2; row_index < row; row_index++) {
		for (int state_index = 0; state_index < available_state_count; state_index++) {
			if (available_state_in_row[state_index] & Graph[row_index]) {
				continue;
			}
			for (int prev_row_state_index = 0; prev_row_state_index < available_state_count; prev_row_state_index++) {
				if (available_state_in_row[prev_row_state_index] & Graph[row_index - 1]) {
					continue;
				}
				if (available_state_in_row[prev_row_state_index] & available_state_in_row[state_index]) {
					continue;
				}
				for (int prever_row_state_index = 0; prever_row_state_index < available_state_count; prever_row_state_index++) {
					if (available_state_in_row[prever_row_state_index] & Graph[row_index - 2]) {
						continue;
					}
					if ((available_state_in_row[prev_row_state_index] & available_state_in_row[prever_row_state_index]) || (available_state_in_row[state_index] & available_state_in_row[prever_row_state_index])) {
						continue;
					}
					dp[row_index][state_index][prev_row_state_index] = max(dp[row_index][state_index][prev_row_state_index], dp[row_index - 1][prev_row_state_index][prever_row_state_index] + available_cannon_in_row[state_index]);
					if (dp[row_index][state_index][prev_row_state_index] > MAX_NUM) {
						MAX_NUM = dp[row_index][state_index][prev_row_state_index];
					}
				}
			}
		}
	}

	cout << MAX_NUM << endl;

	return 0;
}
