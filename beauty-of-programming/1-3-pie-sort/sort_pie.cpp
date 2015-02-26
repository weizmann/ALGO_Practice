#include "sort_pie.h"

#include <iostream>

using namespace std;

SortPie::SortPie()
: m_pie_number(0)
, m_pie_array(NULL)
, m_reversed_array(NULL)
, m_reversed_step_array(NULL)
, m_search_count(0)
, m_reversed_step(0)
{
		
}

void SortPie::sort(int* pie_array, int pie_number)
{
	if (init(pie_array, pie_number))
	{
		return;
	}
	do_search(0);
}

bool SortPie::init(int *pie_array, int pie_number)
{
	if (pie_array == NULL || pie_number <= 0)
	{
		cout << "pie sort failed, please check the args" << endl;
		return false;
	}
	
	m_pie_number = pie_number;

	if (m_pie_array != NULL)
	{
		delete m_pie_array;
		m_pie_array = NULL;
	}
	
	m_pie_array = new int[m_pie_number];
	for (int index = 0; index < m_pie_number; index++)
	{
		//TODO: use memcpy will be better???
		m_pie_array[index] = pie_array[index]; 
	}

	if (m_reversed_array != NULL)
	{
		delete m_reversed_array;
		m_reversed_array = NULL;
	}

	m_reversed_array = new int[m_pie_number];
	for (int index = 0; index < m_pie_number; index++)
	{
		m_reversed_array[index] = pie_array[index];
	}

	if (m_reversed_step_array != NULL)
	{
		delete m_reversed_step_array;
		m_reversed_step_array = NULL;
	}
	int max_step = get_upper_bound();
	m_reversed_step_array = new int[max_step];

	return true;	
}

void SortPie::print_result()
{
	cout << "input pie array: " << endl;
	for (int index = 0; index < m_pie_number; index++)
	{
		cout << m_pie_array[index] << " ";
	}
	cout << endl;

	cout << "search count is " << m_search_count << endl;
	cout << "sorted strategy is: " << endl;
	for (int index = 0; index < m_reversed_step; index++)
	{
		cout << m_reversed_step_array[index] <<  " " << endl;
	}
	cout << endl;

	cout << "sorted pie array: " << endl;
	for (int index = 0; index < m_pie_number; index++)
	{
		cout << m_reversed_array[index] << " ";
	}
	cout << endl;
}

int SortPie::get_upper_bound()
{
	return m_pie_number * 2;
}

int SortPie::get_lower_bound()
{
	int lower_bound = 0;
	for (int index = 1; index < m_pie_number; index ++)
	{
		int delta = m_reversed_array[index] - m_reversed_array[index - 1];
		if (delta == -1 || delta == 1)
		{
			continue;
		}
		else
		{
			lower_bound ++;
		}
	}
	return lower_bound;
}

void SortPie::do_reverse(int begin, int end)
{
	for (int index = 0; index < (end - begin) / 2; index ++)
	{
		int tmp = m_reversed_array[begin + index];
		m_reversed_array[begin + index] = m_reversed_array[end - index];
		m_reversed_array[end - index] = tmp;
	}
}

bool SortPie::is_pie_array_sorted(int* pie_array, int pie_number)
{
	for (int index = 1; index < pie_number; index ++)
	{
		if (pie_array[index] < pie_array[index - 1])
		{
			return false;
		}
	}
	return true;
}

void SortPie::do_search(int step)
{
	int lower_bound = get_lower_bound();
	int upper_bound = get_upper_bound();
	if (m_search_count > upper_bound || m_search_count + lower_bound > upper_bound)
	{
		return;
	}

	if (is_pie_array_sorted(m_reversed_array, m_pie_number))
	{
		print_result();
		return;
	}

	m_search_count ++;

	for (int index = 0; index < m_pie_number; index ++)
	{
		do_reverse(0, index);
		m_reversed_step_array[step] = index;
		do_search(step + 1);
		do_reverse(0, index);
	}
}

