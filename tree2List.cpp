#include "algo_header.h"

class Node 
{
public:
	Node (Node* _left, Node* _right, int _value)
		: left(_left), right(_right), value(_value)
	{
	}
	Node* left;
	Node* right;
	int value;
};

Node* build_tree_based_on_array(int *array, int length) 
{
	if (array == NULL || length <= 0)
	{
		return NULL;
	}
	cout << "length is " << length << endl; 
	Node *root_node = new Node(NULL, NULL, array[0]);
	for (int index = 1; index < length; index++)
	{
		Node* parent_node = root_node;
		while (parent_node != NULL)
		{
			if (array[index] < parent_node->value)
			{
				if (parent_node->left != NULL)
				{
					parent_node = parent_node->left;
				}
				else 
				{
					Node* new_node = new Node(NULL, NULL, array[index]);
					parent_node->left = new_node;
					break;
				}
			}
			else if (array[index] > parent_node->value)
			{
				if (parent_node->right != NULL)
				{
					parent_node = parent_node->right;
				}
				else
				{
					Node* new_node = new Node(NULL, NULL, array[index]);
					parent_node->right = new_node;
					break;
				}
			}
		}
	}
	return root_node;
}


void pre_order_tree_traversal(Node* root_node)
{
	if (root_node != NULL)
	{
		cout << "pre_order_tree_traversal value is " << root_node->value << endl;
		pre_order_tree_traversal(root_node->left);
		pre_order_tree_traversal(root_node->right);
	}
}

typedef struct ListPair
{
	Node* head;
	Node* tail;
} ListPair;

ListPair convert(Node* root_node)
{
	ListPair list_pair;
	if (root_node != NULL)
	{
		if (root_node->left != NULL)
		{
			ListPair left_list = convert(root_node->left);
			root_node->left = left_list.tail;
			left_list.tail->right = root_node;
			list_pair.head = left_list.head;
		}
		else 
		{
			list_pair.head = root_node;
		}
		if (root_node->right != NULL)
		{
			ListPair right_list = convert(root_node->right);
			root_node->right = right_list.head;
			right_list.head->left = root_node;
			list_pair.tail = right_list.tail;
		}
		else
		{
			list_pair.tail = root_node;
		}
	}
	return list_pair;
}

int main() 
{
	int array[] = {5, 3, 1, 4, 6, 8, 7};
	Node* root_node = build_tree_based_on_array(array, sizeof(array) / sizeof(array[0]));
	pre_order_tree_traversal(root_node);
	ListPair list_pair = convert(root_node);
	Node* iter = list_pair.head;
	while (iter != NULL && iter != list_pair.tail)
	{
		cout << "list node value is " << iter->value << endl;
		iter = iter->right;
	}
	return 0;
}
