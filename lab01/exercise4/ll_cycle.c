#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
     /* TODO: Implement ll_has_cycle */
    
    if (head == NULL) { //check if the list is empty or not
        return 0;
    }
    
    node *slow_ptr = head;
    node *fast_ptr = head->next;
    
    while (head != NULL && fast_ptr != NULL && fast_ptr->next != NULL) {
        if (fast_ptr == slow_ptr || fast_ptr->next == slow_ptr) {
            return 1; 
        }
        if (slow_ptr->next !=NULL){
          slow_ptr = slow_ptr->next;
        }
          fast_ptr = fast_ptr->next->next;
    }

    return 0;
}
