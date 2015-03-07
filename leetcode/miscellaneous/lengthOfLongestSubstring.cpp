#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 0) {
            return 0;
        }
        
        int substr_begin_index = 0;
        int cur_substr_length = 1;
        int longest_substr_length = 1;
        
        for (unsigned int index = 0; index < 256; index++) {
            m_last_occur_index[index] = -1;
        }
        m_last_occur_index[s[0]] = 0;
        
        for (unsigned int index = 1; index < s.length(); index++) {
            if (m_last_occur_index[s[index]] < substr_begin_index) {
                cur_substr_length++;
            } else {
                if (cur_substr_length > longest_substr_length) {
                    longest_substr_length = cur_substr_length;
                }
                cur_substr_length = index - m_last_occur_index[s[index]];
                substr_begin_index = m_last_occur_index[s[index]]++;
            }
            m_last_occur_index[s[index]] = index;
        }
        
        if (cur_substr_length > longest_substr_length) {
            longest_substr_length = cur_substr_length;
        }
        return longest_substr_length;
    }
    
private:
    int m_last_occur_index[256];
    
};
int main() 
{
	Solution s;
	string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	cout << "length of longest substring is " << s.lengthOfLongestSubstring(str) << endl;
}
