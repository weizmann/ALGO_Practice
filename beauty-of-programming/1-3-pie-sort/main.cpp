#include <iostream>

#include "sort_pie.h"

using namespace std;

int main()
{
	int pie_array[10] = {3, 2, 5, 1, 4, 8, 7, 9, 6, 0};
	SortPie sort_pie;
	sort_pie.sort(pie_array, 10);
}
