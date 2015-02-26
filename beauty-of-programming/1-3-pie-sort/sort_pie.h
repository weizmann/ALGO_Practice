#ifndef SORT_PIE_H_
#define SORT_PIE_H_

class SortPie
{
public:
	SortPie();

	void sort(int *pie_array, int pie_number);

	void print_result();

private:
	bool init(int* pie_array, int pie_number);

	int get_upper_bound();

	int get_lower_bound();

	void do_reverse(int begin, int end);

	void do_search(int step);

	bool is_pie_array_sorted(int* pie_array, int pie_number);

private:
	int  m_pie_number;
	int* m_pie_array;
	int* m_reversed_array;

	int  m_search_count;
	int  m_reversed_step;
	int* m_reversed_step_array;
};

#endif
