#include <stdio.h>
#include "string.h"
#include "linked_list.h"

bool LinkedList_Push(ListItem *item, ListItem **head){
    if (item->name == NULL) {return false;}

    item->next = (*head);
    (*head) = item;

    return true;
}

bool LinkedList_Append(ListItem *item, ListItem **head){
    if (item->name == NULL) {return false;}

    item->next = NULL;
    if (*head == NULL){
        (*head) = item;
        return true;
    }

    ListItem *current = (*head);
    while (current->next != NULL){
        current = current->next;
    }
    current->next = item;
    return true;
}

void LinkedList_PrintAllItems(ListItem **head){
    ListItem *current = (*head);
    printf("Printing singly linked list:\n\r");
    while (current){
        printf("Item value: ");
        printf("%d", current->value);
        printf("\tItem name: ");
        printf("%s", current->name);
        printf("\n\r");
        current = current->next;
    }
}

ListItem* LinkedList_GetItemByName(const char* name, ListItem **head){
    ListItem *current = (*head);
    while (current){
        if (strcmp(name, current->name) == 0) return current;
        current = current->next;
    }
    return NULL;
}

bool LinkedList_IsEmpty(ListItem **head){
    if((*head) == NULL)
        return true;
    return false;
}

size_t LinkedList_GetLen(ListItem **head){
    size_t size = 0;
    if (!LinkedList_IsEmpty(head)){
        ListItem *current = (*head);
        while(current) {
            size++;
            current = current->next;
        }
    }
    return size;
}