#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CompareFunc
{
public:
	bool operator() (int a, int b) { return a < b; }
};

void computeLowestPrice(vector<int>books, int single_price)
{
	sort(books.begin(), books.end(), CompareFunc());

	if (books)

}

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
