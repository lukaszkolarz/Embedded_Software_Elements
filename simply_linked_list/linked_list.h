#ifndef EMBEDDED_SOFTWARE_ELEMENTS_LINKED_LIST_H
#define EMBEDDED_SOFTWARE_ELEMENTS_LINKED_LIST_H

#include <stdbool.h>
#include <stdint.h>
#include "stddef.h"

typedef void(*ListItemFunction)(char* args);

typedef struct ListItem {
    char* name;
    int value;
    ListItemFunction callback;
    struct ListItem *next;
} ListItem;

/**
 * @brief This function registers new item in the beginning of List_Item list
 *
 * @param item pointer to a @ref ListItem structure
 * @param head is the pointer to first element on the list
 *
 * @retval true if new item was successfully added
 * @retval false if an error occurred
 */
bool LinkedList_Push(ListItem *item, ListItem **head);

/**
 * @brief This function registers new item in the end of the List_Item list
 *
 * @param item pointer to a @ref ListItem structure
 * @param head is the pointer to first element on the list
 *
 * @retval true if new item was successfully added
 * @retval false if an error occurred
 */
bool LinkedList_Append(ListItem *item, ListItem **head);

/**
 * @bref This function prints information about all items registered in the ListItem list.
 *
 * @param head is the pointer to first element on the list
 */
void LinkedList_PrintAllItems(ListItem **head);

/**
 * @brief This function searches for list element by given name
 *
 * @param name pointer a string to search
 * @param head is the pointer to first element on the list
 *
 * @retval searched element of the list
 * @retval NULL if there is no searched element
 */
ListItem* LinkedList_GetItemByName(const char* name, ListItem **head);

/**
 * @brief This function checks if the list is empty
 *
 * @param head is the pointer to first element on the list
 *
 * @retval true if is empty
 * @retval false otherwise
 */
bool LinkedList_IsEmpty(ListItem **head);

/**
 * @brief This function counts elements of the list
 *
 * @param head is the pointer to first element on the list
 *
 * @return number of elements in the list
 */
size_t LinkedList_GetLen(ListItem **head);

#endif //EMBEDDED_SOFTWARE_ELEMENTS_LINKED_LIST_H
