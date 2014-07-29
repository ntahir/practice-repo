#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct tree_node
{
    int val;
    struct tree_node* left;
    struct tree_node* right;

}tree_node_t;

typedef struct list_node
{
    int val;
    struct list_node* next;

}list_node_t;


int max(int a, int b)
{
    return (a>b?a:b);
}


tree_node_t* make_bst(int* values, int nr_values)
{
    int ii=0;
    int val=0;
    tree_node_t* root = (tree_node_t*)calloc(1, sizeof(tree_node_t));
    tree_node_t* p = root;
    tree_node_t* q = p;
    
    root->val = values[0];

    printf("Creating BST of following values...\n");

    for(ii=0; ii<nr_values; ii++)
    {
        printf(": %d:", values[ii]); 
    }

    printf("\n");

    
    for(ii=1; ii<nr_values; ii++)
    {
        val = values[ii];
        p = q = root;

        while(p)
        {
            q = p;
            
            if(val < p->val)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }

        p = (tree_node_t*)calloc(1, sizeof(tree_node_t));
        p->val = val;

        if(val < q->val)
        {
            q->left = p;            
        }
        else
        {
            q->right = p;
        }
        //repeat for next value in the array. 
    } 

    return root;

}

void in_order_recurse(tree_node_t* node)
{
        if(!node)
        {
            return;
        }

        in_order_recurse(node->left);
        printf(": %d:", node->val);
        in_order_recurse(node->right);

}

void encode_str(char* str)
{
    //TODO
}

void print_list(list_node_t* head)
{
    printf("\nPrinting List...\n");

    while(head)
    {
        printf(":%d:", head->val);
        head = head->next;    
    }
    printf("\n");
}

void reverse_list(list_node_t** head)
{
    //emtpy list
    if(*head == NULL) return;

    list_node_t* prev = NULL;
    list_node_t* current = *head;
    list_node_t* next = current ? current->next:NULL;

    while(next)
    {
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }

    current->next = prev;
    *head = current;

}

int add_to_list(list_node_t* head, int val)
{
    if(!head)
    {
        return 1;
    }

    list_node_t* prev = head;
    
    while(head)
    {
        prev = head;
        head = head->next;
    }
    //reusing head ptr
    head = (list_node_t*)calloc(1, sizeof(list_node_t));
    head->val = val;
    prev->next = head;

}


int main(int argc, char** argv)
{
    tree_node_t* bst_root;
    int numbers[] = {3,6,1,8,10,9,7,4,20,11};

    bst_root = make_bst(numbers, sizeof(numbers)/sizeof(int));
    
    in_order_recurse(bst_root);

    printf("\n");
    list_node_t* node = (list_node_t*)calloc(1, sizeof(list_node_t));
    node->val = numbers[0];
    
    int ii=0;
    for(ii=1; ii<sizeof(numbers)/sizeof(int); ii++)
    {
        add_to_list(node, numbers[ii]);
    }

    print_list(node);

    #if 0
    node->next = (list_node_t*)calloc(1, sizeof(list_node_t));
    node->next->next = (list_node_t*)calloc(1, sizeof(list_node_t));
    node->next->next->next = (list_node_t*)calloc(1, sizeof(list_node_t));
    node->next->next->next->next = (list_node_t*)calloc(1, sizeof(list_node_t));
    node->next->next->next->next->next = (list_node_t*)calloc(1, sizeof(list_node_t));
    node->next->next->next->next->next->next = (list_node_t*)calloc(1, sizeof(list_node_t));
    #endif

	return 0;
}



