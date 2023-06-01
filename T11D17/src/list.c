#include "list.h"

// #include <stdlib.h>  // для malloc() - импортируем из list.h !!!

// Функция инициализации структуры односвязного списка на базе переданной struct door:
struct node* init(struct door* door) {
    struct node* my_node = (struct node*)malloc(sizeof(struct node));  // создаем новый элемент списка

    if (my_node != NULL) {
        my_node->data.id = door->id;          // записываем данные в поле id
        my_node->data.status = door->status;  // записываем данные в поле status
        my_node->next = NULL;
    }

    return my_node;
}

// Функция вставки нового элемента (struct door) в односвязный список после переданного узла elem:
struct node* add_door(struct node* elem, struct door* door) {
    struct node* my_node = NULL;

    if (elem != NULL) {
        my_node = (struct node*)malloc(sizeof(struct node));

        if (my_node != NULL) {
            my_node->data.id = door->id;          // записываем данные в поле id
            my_node->data.status = door->status;  // записываем данные в поле status

            my_node->next = elem->next;  // связываем новый элемент с другими элементами
            elem->next = my_node;
        }
    }

    return my_node;
}

// Функция поиска двери в списке по её id:
struct node* find_door(int door_id, struct node* root) {
    struct node* p_node = root;  // создаем указатель на корень

    while (p_node != NULL) {  // пока не дойдем до конца списка

        if (p_node->data.id == door_id) {  // если нашли нужный id двери, то выходим из цикла
            break;
        }

        p_node = p_node->next;  // перемещаемся к следующей двери
    }

    return p_node;
}

// Функция удаления элемента списка:
struct node* remove_door(struct node* elem, struct node* root) {
    struct node* p_node = root;

    if (elem == root) {
        p_node = root->next;
        free(elem);
    } else {
        while (p_node->next != elem) {
            p_node = p_node->next;
        }
        p_node->next = elem->next;
        free(elem);
        p_node = root;
    }

    return p_node;  // возвращаем адрес корня списка
}

// Функция, выполняющая освобождение памяти, занимаемой структурой списка:
void destroy(struct node* root) {
    struct node* p_node = root;

    while (p_node != NULL) {
        struct node* deleted_node = p_node;  // адрес удаляемого элемента

        p_node = p_node->next;  // переходим к следующему элементу

        free(deleted_node);  // удаляем элемент
    }
}
