#include <iostream>

using namespace std;

int main() 
{
	int total_num, total_weight;
	cin >> total_num >> total_weight;

	if (total_num <= 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int* weight = new int[total_num];
	int* desire = new int[total_num];

	for (int index = 0; index < total_num; index++)
	{
		cin >> weight[index] >> desire[index];	
	}

	int *dp_array = new int[total_weight + 1];
	for (int i = 0; i <= total_weight; i++)
	{
		dp_array[i] = 0;
	}

	for (int i = 0; i < total_num; i++) 
	{
		for (int j = total_weight; j > 0; j--)
		{
			if (j >= weight[i])
			{
				int choose_j_desire = (i > 0) ? (dp_array[j-weight[i]] + desire[i]) : (desire[i]);
				int discard_j_desire = (i > 0) ? (dp_array[j]) : 0;
				dp_array[j] = choose_j_desire > discard_j_desire ? choose_j_desire : discard_j_desire;
			}
		}
	}
	cout << dp_array[total_weight] << endl;
	delete weight;
	delete desire;
	delete dp_array;

	return 0;
}
