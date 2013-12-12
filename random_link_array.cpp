#include <iostream>
#include <cstdlib>

using namespace std;

#define RAND_MAX_NUM 100
#define LIST_LENGTH 20

typedef int node_t;
typedef struct random_node {
    random_node* next;
    random_node* random;
    node_t value;
} random_node;

void init_random_pointer(random_node*, int);
int get_node_value(random_node*);
random_node* init_random_list(const int list_length) {
    random_node* list = new random_node[list_length];
    for (int i = 0; i < list_length - 1; i++) {
        list[i].next = &list[i+1];
        list[i].value = i;
    }
    list[list_length - 1].next = NULL;
	list[list_length - 1].value = list_length - 1;
	init_random_pointer(list, list_length);
    return list;
}

void init_random_pointer(random_node* list, int list_length) {
    for (int i = 0; i < list_length; i++) {
		int recorded_rand = rand();
		int index = (recorded_rand) % list_length;
        list[i].random = &list[index];
		printf("%dth list node random is %d, %d\n", i, index, recorded_rand);
    }
}
#define INVAL_NUM 999
void print_rand_list(random_node* list, int list_length) {
    for (int i = 0; i < list_length; i++) {
        cout<<"node ["<< i << "] value is "<<list[i].value<<" next is "<<get_node_value(list[i].next)
            <<", random is "<<get_node_value(list[i].random)<<endl;
    }
}

int get_node_value(random_node* wanted_node) {
    if (wanted_node == NULL) {
        return INVAL_NUM;
    } else {
        return wanted_node->value;
    }
}

void copy_list(random_node* list, int list_length) {
	for (int i = 0; i < list_length; i++) {
		random_node* new_node = new random_node(list[i]);
		new_node->next = list[i].next;
		new_node->value = i;
		list[i].next = new_node;
	}
	for (int i = 0; i < list_length; i+=2) {
		list[i+1].random = list[i].random->next;
	}
}

random_node* split_list(random_node* list, int list_length) {
	random_node* new_head = list->next;
	for (int i = 0; i < list_length; i++) {
		list->next = new_head->next;
		new_head->next = new_head->next->next;

		list = list->next;
		new_head = new_head->next;
	}
	return new_head;
}

int main() {
    random_node* list = init_random_list(LIST_LENGTH);
    print_rand_list(list, LIST_LENGTH);
	copy_list(list, LIST_LENGTH);
	random_node* new_list = split_list(list, LIST_LENGTH);
	print_rand_list(new_list, LIST_LENGTH);
}












