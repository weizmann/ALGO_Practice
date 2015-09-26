#include <iostream>
#include <vector>

using namespace std;

int lisWithBruteForce(vector<int> squence) {
	if (squence.empty()) {
		return 0;
	}

	int ret = 0;
	for (int i = 0; i < squence.size(); i++) {
		vector<int> subSquence;
		for (int j = i + 1; j < squence.size; j++) {
			if (squence[j] > squence[i]) {
				subSquence.push_back(squence[j]);
			}
		}
		ret = max(ret, 1 + lisWithBruteForce(subSquence));
	}
	return ret;
}

int squenceLength;
vector<int> squence = vector<int>(squenceLength); // initialized from input
vector<int> memorize_cache = vector<int>(squenceLength, -1);

int lisWithDp(int startIndex) {
	if (startIndex >= squenceLength) {
		return 1;
	}	
	if (memorize_cache[startIndex] != -1) {
		return memorize_cache[startIndex];
	}
	int ret = 0;
	for (int index = startIndex; index < squence; index++) {
		if (squence[index] > squence[startIndex]) {
			ret = max(ret, lisWithDp(index));
		}
	}
	memorize_cache.push_back(ret);
	return ret;
}

int main () {
	return 0;
}
