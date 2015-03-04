#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
		const int MAX_CHAR_COUNT = 128;
		int pattern[MAX_CHAR_COUNT];
		int text[MAX_CHAR_COUNT];

		for (unsigned int index = 0; index < MAX_CHAR_COUNT; ++index) {
			pattern[index] = 0;
			text[index] = 0;
		}

		for (unsigned int index = 0; index < T.length(); ++index) {
			pattern[T[index]]++;
		}

		int begin = 0;
		int end = 0;
		int min_begin = -1;
		int min_end = -1;

		text[S[end]]++;
		while (end < S.length()) {
			if (is_contain_pattern(pattern, text, MAX_CHAR_COUNT)) {
				cout << "begin is " << begin << endl;
				if (begin == 0 || (end - begin) < (min_end - min_begin)) {
					min_end = end;
					min_begin = begin;
				}
				text[S[begin]]--;
				begin++;	
			} else {
				end++;
				cout << "end is " << end << endl;
				text[S[end]]++;
			}
		}

		cout << "min_begin is " << min_begin << ", min_end is " << min_end << endl;

		if (min_end != -1) {
			return S.substr(min_begin, min_end - min_begin + 1);
		} else {
			return string();
		}

    }

private:
	
	bool is_contain_pattern(int *pattern, int *text, unsigned int size) {
		if (pattern == NULL || text == NULL) {
			return false;
		}
		for (unsigned int index = 0; index < size; ++index) {
			if (pattern[index] > text[index]) {
				return false;
			}
		}
		return true;
	}

};

int main() {
	Solution solution;
	cout << solution.minWindow("a", "a") << endl;
}
