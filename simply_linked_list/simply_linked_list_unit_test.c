#include "simply_linked_list_unit_test.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define test(expr)(!(expr)) ? (printf(FAILED" at line %u\n", __LINE__), false) : (printf(PASSED"\n"), true)
#define test_quiet(expr)(!(expr)) ? (printf(FAILED" at line %u\n", __LINE__), false) : true
#define PASSED "\x1b[32mPASSED\x1b[0m"
#define FAILED "\x1b[31mFAILED\x1b[0m"
#define PRI_SIZET "zu"

enum{
    CAPACITY1 = 10,
    CAPACITY2 = 100,
    CAPACITY3 = 1000
};

void generateItem(size_t i, ListItem *item){
    char *buff = malloc(20);
    sprintf(buff, "NAME: %"PRI_SIZET"", i);
    item->value = i;
    item->name = buff;
}

static bool LinkedList_Empty_Test(ListItem *head){
    printf("Test 0: Checking list structure\n");
    printf("\tChecking emptiness: ");
    bool result = test(true == LinkedList_IsEmpty(&head));
    printf("\tChecking size: ");
    result &= test(0 == LinkedList_GetLen(&head));
    printf("Test 0: %s\n\n", true == result ? PASSED : FAILED);
    head = NULL;
    return result;
}

static bool LinkedList_Push_Test(ListItem *head, size_t dataSize){
    printf("Test 1: Checking pushing\n");
    printf("\tChecking if the list is empty: ");
    bool result = test(true == LinkedList_IsEmpty(&head));
    if (true == result){
        printf("\tWriting new items into the list\n");
        for (size_t i = 1; true == result && i <= dataSize; i++){
            ListItem *item = (ListItem*)malloc(sizeof(ListItem));
            generateItem(i, item);
            result &= test_quiet(true == LinkedList_Push(item, &head));
            result &= test_quiet(i == LinkedList_GetLen(&head));
            result &= test_quiet(false == LinkedList_IsEmpty(&head));
            if(false == result){
                printf("\t\tWriting data no %"PRI_SIZET" produced invalid state (IsEmpty: %s, Length: %"PRI_SIZET")\n",
                        i, LinkedList_IsEmpty(&head) ? "TRUE" : "FALSE",
                        LinkedList_GetLen(&head));
            }
        }
        if (true == result){
            printf("\tLength is %"PRI_SIZET": ", dataSize);
            result &= test(dataSize == LinkedList_GetLen(&head));
            printf("\tIs not empty: ");
            result &= test(false == LinkedList_IsEmpty(&head));
        }
    }
    printf("Test 1: %s\n\n", (true == result) ? PASSED : FAILED);
    head = NULL;
    return result;
}

static bool LinkedList_Append_Test(ListItem *head, size_t dataSize){
    printf("Test 2: Checking append\n");
    printf("\tChecking if the list is empty: ");
    bool result = test(true == LinkedList_IsEmpty(&head));
    if (true == result){
        printf("\tWriting new items into the list\n");
        for (size_t i = 1; true == result && i <= dataSize; i++){
            ListItem *item = (ListItem*)malloc(sizeof(ListItem));
            generateItem(i, item);
            result &= test_quiet(true == LinkedList_Append(item, &head));
            result &= test_quiet(i == LinkedList_GetLen(&head));
            result &= test_quiet(false == LinkedList_IsEmpty(&head));
            if(false == result){
                printf("\t\tWriting data no %"PRI_SIZET" produced invalid state (IsEmpty: %s, Length: %"PRI_SIZET")\n",
                       i, LinkedList_IsEmpty(&head) ? "TRUE" : "FALSE",
                       LinkedList_GetLen(&head));
            }
        }
        if (true == result){
            printf("\tLength is %"PRI_SIZET": ", dataSize);
            result &= test(dataSize == LinkedList_GetLen(&head));
            printf("\tIs not empty: ");
            result &= test(false == LinkedList_IsEmpty(&head));
        }
    }
    printf("Test 2: %s\n\n", (true == result) ? PASSED : FAILED);
    head = NULL;
    return result;
}

static bool LinkedList_GettingAppendedItem_Test(ListItem *head, size_t dataSize) {
    printf("Test 3: Checking getting item by name (saved with append function)\n");
    printf("\tChecking if the list is empty: ");
    bool result = test(true == LinkedList_IsEmpty(&head));
    if (true == result) {
        printf("\tWriting new items to the list\n");
        for (size_t i = 1; true == result && i <= dataSize; i++) {
            ListItem *item = (ListItem *) malloc(sizeof(ListItem));
            generateItem(i, item);
            result &= test_quiet(true == LinkedList_Append(item, &head));
            result &= test_quiet(i == LinkedList_GetLen(&head));
            result &= test_quiet(false == LinkedList_IsEmpty(&head));
            if (false == result) {
                printf("\t\tWriting data no %"PRI_SIZET" produced invalid state (IsEmpty: %s, Length: %"PRI_SIZET")\n",
                       i, LinkedList_IsEmpty(&head) ? "TRUE" : "FALSE",
                       LinkedList_GetLen(&head));
            }
        }
    }
    if (true == result) {
        printf("\tSearching for list elements\n");
        for (size_t i = 1; true == result && i <= dataSize; i++) {
            char *buff = malloc(20);
            sprintf(buff, "NAME: %"PRI_SIZET"", i);
            ListItem *item = LinkedList_GetItemByName(buff, &head);
            result &= test_quiet(0 == strcmp(item->name, buff));
            if (false == result) {
                printf("\t\tSearching for data no %"PRI_SIZET" produced invalid state\n", i);
            }


        }
    }
    printf("Test 3 %s\n\n", (true == result) ? PASSED : FAILED);
    head = NULL;
    return result;
}

static bool LinkedList_GettingPushedItem_Test(ListItem *head, size_t dataSize) {
    printf("Test 4: Checking getting item by name (saved with push function\n");
    printf("\tChecking if the list is empty: ");
    bool result = test(true == LinkedList_IsEmpty(&head));
    if (true == result) {
        printf("\tWriting new items to the list\n");
        for (size_t i = 1; true == result && i <= dataSize; i++) {
            ListItem *item = (ListItem *) malloc(sizeof(ListItem));
            generateItem(i, item);
            result &= test_quiet(true == LinkedList_Push(item, &head));
            result &= test_quiet(i == LinkedList_GetLen(&head));
            result &= test_quiet(false == LinkedList_IsEmpty(&head));
            if (false == result) {
                printf("\t\tWriting data no %"PRI_SIZET" produced invalid state (IsEmpty: %s, Length: %"PRI_SIZET")\n",
                       i, LinkedList_IsEmpty(&head) ? "TRUE" : "FALSE",
                       LinkedList_GetLen(&head));
            }
        }
    }
    if (true == result) {
        printf("\tSearching for list elements\n");
        for (size_t i = 1; true == result && i <= dataSize; i++) {
            char *buff = malloc(20);
            sprintf(buff, "NAME: %"PRI_SIZET"", i);
            ListItem *item = LinkedList_GetItemByName(buff, &head);
            result &= test_quiet(0 == strcmp(item->name, buff));
            if (false == result) {
                printf("\t\tSearching for data no %"PRI_SIZET" produced invalid state\n", i);
            }


        }
    }
    printf("Test 4 %s\n\n", (true == result) ? PASSED : FAILED);
    head = NULL;
    return result;
}

bool SimplyLinkedList_UnitTest(void){
    static ListItem *head = NULL;
    size_t dataSize[3] = {CAPACITY1, CAPACITY2, CAPACITY3};
    bool result = true;
    for(int i = 0; true == result && i < (sizeof(dataSize) / sizeof(*dataSize)); ++i){
        printf("========== PERFORMING TEST FOR DATA BUFFER WITH SIZE %"PRI_SIZET" ==========\n", dataSize[i]);
        do{
            if(false == (result &= LinkedList_Empty_Test(head))) break;
            if(false == (result &= LinkedList_Push_Test(head, dataSize[i]))) break;
            if(false == (result &= LinkedList_Append_Test(head, dataSize[i]))) break;
            if(false == (result &= LinkedList_GettingAppendedItem_Test(head, dataSize[i]))) break;
            if(false == (result &= LinkedList_GettingPushedItem_Test(head, dataSize[i]))) break;
        }while(0);
        printf("========== TEST FOR DATA BUFFER WITH SIZE %"PRI_SIZET" FINISHED WITH RESULT %s ==========\n", dataSize[i], (true == result) ? PASSED : FAILED);

    }
    return result;
}