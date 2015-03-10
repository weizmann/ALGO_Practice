#include <iostream>
#include <vector>

using namespace std;

int get_longest_inc_seq_size(vector<int>squence) {
	vector<int>dp;
	dp.reserve(squence.size());
	dp[0] = 1;
	for (int i = 1; i < squence.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (squence[j] <= sequence[i]) {
				dp[i] = dp[j] + 1;
				break;
			}
		}	
	}
	return dp[squence.size() - 1];
}

int main() {
	
}


