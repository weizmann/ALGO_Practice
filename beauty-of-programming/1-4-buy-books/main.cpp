#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_lowest_price(int *book_array, int single_price, int book_count)  
{
	
}

inline bool compare_function(int a, int b) 
{
	return a < b;
}

class CompareFunc
{
public:
	bool operator() (int a, int b) { return a < b; }
};

int main() 
{
	int book_array[] = {1, 3, 4, 0, 5, 2};
	int book_size = sizeof(book_array) / sizeof(int);
	vector<int>book_vector(book_array, book_array + book_size);

	sort(book_vector.begin(), book_vector.end(), CompareFunc());

	cout << "print book vector after sorted:" << endl;
	for (vector<int>::iterator iter = book_vector.begin(); iter != book_vector.end(); iter++)
	{
		cout<< *iter <<  endl;
	}

	return 0;
}
