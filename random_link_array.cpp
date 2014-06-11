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
    for (int i = 0; i < list_length; i++) {
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
        list[i].random = &list[(rand() * 100) % list_length];
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

int main() {
    random_node* list = init_random_list(LIST_LENGTH);
    print_rand_list(list, LIST_LENGTH);
}












