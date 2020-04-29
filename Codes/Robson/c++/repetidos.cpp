#include <iostream>

using namespace std;

typedef struct node {
    int value;
    struct node * next;
} node_t;

void fnRemoveDupVals(node_t * pHead){
    /* INSERT YOUR CODE HERE -> START*/
    node_t * ref = pHead;
    node_t * previous = NULL;
    node_t * pivot = NULL;
    
    while (ref != NULL) {
        previous = ref;
        pivot = ref->next;
        while (pivot != NULL) {
            
            if (ref->value == pivot->value) {
                previous->next = pivot->next;
            } else {
                previous = pivot;
            }
            
            pivot = pivot->next;
            
        }
        
        ref = ref->next;
    }
    
    return;
    
    /* INSERT YOUR CODE HERE -> END*/
}

int main() {
    node_t * head = NULL;
        
    int max;
    cin>>max;
    node_t * previous;
    for (int i = 0; i < max; i++){
        node_t * thisNode = (node_t *) malloc(sizeof(node_t));
        cin>>thisNode->value;
        thisNode->next = NULL;
        if (i == 0) 
            head = thisNode;
        else
            previous->next = thisNode;
        previous = thisNode;
    }

    fnRemoveDupVals(head);  
    
    //Print linked list values in sequence
    node_t * current = head;
    printf("\n\n");
    while (current != NULL) {
        
        cout<<current->value<<endl;
        current = current->next;
    }

    //For this exercise purpose, don't worry about freeing memory

    return 0;
}