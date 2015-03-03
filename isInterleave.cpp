#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

	bool isInterleave(string s1, string s2, string s3) {
		if (s1 == NULL || s2 == NULL || s3 == NULL) 
		{
			return false;
		}

		const int s1_len = s1.size();
		const int s2_len = s2.size();
		const int s3_len = s3.size();

		if (s1_len == 0 || s2_len == 0) 
		{
			//TODO
		}

		bool dp_table[s1_len][s2_len];


	}

};

int main() 
{
	
}
