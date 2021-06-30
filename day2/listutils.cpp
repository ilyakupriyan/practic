#include <iostream>
#include <time.h>

struct Node {
    int val;
    Node* next = NULL;
};


// Инициализации элемента односвязного списка нулями
void init(Node* node) {
    node->val = 0;
}


// Отображения односвязного списка на экран
void show(Node* head) {
    Node* count = head;
    while (count->val != NULL) {
        std::cout << count->val << " ";
        count = count->next;
    }
    std::cout << std::endl;
}


// Добавления элемента в односвязный список
void pushNode(Node* head, Node* node) {
    Node* count = head;

    while (count->next != NULL)
        count = count->next;

    count->next = node;
    node->next = NULL;
}


// Написать функцию копирования элементов массива source в новый массив dest
void copyMas(Node* source, Node* dest) {
    while (source->next != NULL || dest->next != NULL) {
        dest->val = source->val;
        dest = dest->next;
        source = source->next;
    }
}


// Написать функцию сравнение списков source и dest. Если списки равны 0, если не равны -1
int compareMas(Node* source, Node* dest) {
    while (source->next != NULL || dest->next != NULL) {
        if (source->val != dest->val)
            return -1;
        dest = dest->next;
        source = source->next;
    }
    return 0;
}


int testCopyMas() {
    srand(time(NULL));

    Node* source = new Node;
    Node* dest = new Node;
    Node* source_node = source, * dest_node = dest;

    for (int i = 0; i <= 5; i++) {
        pushNode(source, new Node);
        pushNode(dest, new Node);

        source_node->val = rand() % 30;
        init(dest_node);

        source_node = source_node->next;
        dest_node = dest_node->next;
    }

    if (compareMas(source, dest) != -1)
        return -1;

    copyMas(source, dest);

    if (compareMas(source, dest) != 0)
        return -1;

    source->next->next->val = -1;

    if (compareMas(source, dest) != -1)
        return -1;
    return 0;
}


static void runTest(int (*testFunction)(), const std::string& testName)
{
    if (testFunction() == 0)
        std::cout << "Test " << testName << " - OK" << std::endl;
    else
        std::cout << "Test " << testName << " - FAIL" << std::endl;
}



int main() {
    runTest(testCopyMas, "testSkoFromList");

    return 0;
}