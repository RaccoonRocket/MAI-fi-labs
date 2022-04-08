# Отчет по лабораторной работе N 23 по курсу
# "Фундаментальная информатика"

Студент группы: M80-104Б, Борисов Сергей Павлович\
Контакты: 9802432172sergei@gmail.com\
Работа выполнена: 06.04.2022\
Преподаватель: Безлуцкая Елизавета Николаевна

## 1. Тема

Динамические структуры данных. Обработка деревьев.

## 2. Цель работы

Изучение и освоение такой динамической структуры данных, как дерево.

## 3. Задание

Вариант 4.\
Определить значение листа двоичного дерева, имеющего минимальную глубину.

## 4. Оборудование

Процессор: AMD Ryzen 3500U\
ОП: 7851 Мб\
SSD: 256 Гб\
Монитор: 1920x1080\

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **18.10 cosmic**\
Интерпретатор команд: **bash**, версия **4.4.19**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **--**\

## 6. Идея, метод, алгоритм решения задачи

Создать/воспользоваться созданным двоичным деревом, имеющего следующие функции: добавление нового узла; текстовая визуализация дерева; удаление узла; вычисление значенися функции, соответствующей номеру задания.\
Реализация заданной функции: рекурсивный обход всего дерева, при нахождении листа заносим глубину узла и его значение в массив. По окончании обхода дерева, итерацией найти в массиве наименьшую глубину листа. Далее так же итерацией в массиве вывести значения листьев, имеющие минимальную глубину.

## 7. Сценарий выполнения работы

Программа состоит из следующих файлов:\
tree.h — заголовочный файл для дерева\
tree.c — реализация функций и процедур дерева\
main.c — основной файл с выполненным заданием


## 8. Распечатка протокола

tree.h:
```
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
} Tree;

Tree *tree_create(int value);
Tree *tree_add_element(Tree *parent, int value);
Tree *delete_element(Tree *parent, int value);
void tree_print(Tree *t, int n);
Tree* search_in_tree(Tree *t, int value);
Tree* minimum(Tree *t);
void depth(Tree *parent, int n); //n - quantity elements
void traversal(Tree *parent, int c, int a []);

#endif //_TREE_H_
```

tree.c:
```
#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int i = 0;

Tree *root_create(int value)
{
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->data = value;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = NULL;
    return tree;
}

Tree *tree_add_element(Tree *root, int value)
{
    if (root == NULL) {
        printf("Done!\n");
        return root_create(value);
    }

    Tree *NewTree = (Tree*)malloc(sizeof(Tree));
    NewTree->data = value;
    Tree *tree1 = root;
    Tree *tree2 = NULL;

    while (tree1 != NULL) {
        tree2 = tree1;
        if (value < tree1->data) {
            tree1 = tree1->left;
        }
        else if (value > tree1->data) {
            tree1 = tree1->right;
        }
        else {
            printf("This value is already exist in tree! Use other values!\n");
            return root;
        }
    }
    NewTree->parent = tree2;
    NewTree->left = NULL;
    NewTree->right = NULL;
    if (value < tree2->data) {
        tree2->left = NewTree;
    } else {
        tree2->right = NewTree;
    }
    printf("Done!\n");
    return root;
}

void tree_print(Tree *root, int n)
{
    if (root != NULL) {
        tree_print(root->right, n + 1);
        for (int i = 0; i < n; i++) printf("\t");
        printf("%d\n", root->data);
        tree_print(root->left, n + 1);
    }
}

Tree *delete_element(Tree *root, int value)
{
    Tree* tree1 = NULL, * tree2 = NULL, *tree3 = root, *tree4 = NULL;

    if (root == NULL) {
        printf("Delete error! Your tree isn't exist!\n");
        return root;
    }
    tree1 = search_in_tree(tree3, value);
    if (tree1 == NULL) {
        printf("Your element already isn't exist!\n");
        return root;
    }
    // First case. element == leaf
    if (tree1->left == NULL && tree1->right == NULL) {
        if (tree1->parent == NULL) { // If this is root
            free(tree1);
            tree1 = NULL;
            printf("Successful deletion\n");
            return NULL;
        }
        tree2 = tree1->parent;
        if (tree2->left == tree1) {
            tree2->left = NULL;
        }
        else {
            tree2->right = NULL;
        }
        free(tree1);
    }
    // Second case. one of subtrees are available
    else if (tree1->left != NULL && tree1->right == NULL) { // left subtrees is exist
        if (tree1->parent == NULL) { // If this is root
            tree4 = tree1->left;
            tree4->parent = NULL;
            free(tree1);
            printf("Successful deletion\n");
            return tree4;
        }
        tree2 = tree1->parent;
        if (tree2->left == tree1) {
            tree2->left = tree1->left;
        }
        else {
            tree2->right = tree1->left;
        }
        free(tree1);
    }
    else if (tree1->left == NULL && tree1->right != NULL) { // right subtrees is exist
        if (tree1->parent == NULL) { // If this is root
            tree4 = tree1->right;
            tree4->parent = NULL;
            free(tree1);
            printf("Successful deletion\n");
            return tree4;
        }
        tree2 = tree1->parent;
        if (tree2->left == tree1) {
            tree2->left = tree1->right;
        }
        else {
            tree2->right = tree1->right;
        }
        free(tree1);
    }
    // Third case. Both subtrees are available
    else if (tree1->left != NULL && tree1->right != NULL) {
        tree2 = minimum(tree1->right);
        tree1->data = tree2->data;
        tree4 = tree2->parent;
        if (tree4->left == tree2) {
            free(tree2);
            tree4->left = NULL;
        }
        if (tree4->right == tree2) {
            free(tree2);
            tree4->right = NULL;
        }
    }
    printf("Successful deletion\n");
    return root;
}

Tree *search_in_tree(Tree *root, int value)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    if (value > root->data) {
        return search_in_tree(root->right,value);
    } else {
        return search_in_tree(root->left, value);
    }
}

Tree *minimum(Tree *t)
{
    if (t->left == NULL) {
        return t;
    }
    return minimum(t->left);
}

void depth(Tree *root, int n) {
    if (root == NULL) return;
    int c = 1, a[n+1];
    for (int q = 0; q < n+1; ++q) a[q] = 0;
    if (root->left != NULL) traversal(root->left, c, a);
    if (root->right != NULL) traversal(root->right, c, a);
    printf("array done\n");
    int o = a[0];
    for (int j = 0; a[j] != 0 && j < n+1; j+=2) {
        if (a[j] < o) o = a[j];
    }
    printf("Lists with minimum depth:\n");
    for (int j = 0; a[j] != 0 && j < n+1; j+=2) {

        if (a[j] == o) printf("%d\n", a[j+1]);
    }
}


void traversal(Tree *root, int c, int a []) {
    c++;
    if (root->left != NULL) traversal(root->left, c, a);
    if (root->right != NULL) traversal(root->right, c, a);
    if (root->left == NULL && root->right == NULL) {
        a[i] = c;
        a[++i] = root->data;
        printf("i=%d %d %d\n", c, a[i-1], a[i]);
        ++i;
    }
}
```

main.c:
```
#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"
#include "Tree.c"


void print_menu() {
	printf("\nSelect the desired action by writing the appropriate number:\n");
	printf("1) Add an item to the tree\n");
	printf("2) Print the tree\n");
	printf("3) Remove an item from the tree\n");
	printf("4) Search list with minimum depth\n");
	printf("Enter 0 for exit\n");
}

int main(void)
{
	Tree *t = NULL;
	int value;
	char c;
	int n = 0;
	printf("Welcome to the program for processing binary search trees!\n");
	print_menu();
	while ((c = getchar()) != EOF) {
		value = 0;
		if (c == '\n') continue;
		switch (c) {
		case '1':
			printf("\nEnter the value you want to add to the tree:");
			scanf("%d", &value);
			t = tree_add_element(t, value);
			n++;
			break;
		case '2':
			tree_print(t, 1);
			break;
		case '3':
			printf("\nEnter the value you want to delete from the tree: ");
			scanf("%d", &value);
			t = delete_element(t, value);
			n--;
			break;
        case '4':
            printf("\nSearcing list with minimum depth:\n");
            if (t == NULL) return 0;
            depth(t, n);
            //printf("\n%d", bfs(t));
            break;
		case '0':
			printf("\nHave a nice day!\n");
			return 0;
		default:
			printf("The number you entered isn't in the menu :(\nPlease try again, in case you made a mistake\n");
			break;
		}
		print_menu();
	}
}
```

## 9. Дневник отладки
```
+---+---------------+------------+-----------+---------------------------+-------------------------+-------------+
| № | Лаб. или дом. | Дата       | Время     | Событие                   | Действие по исправлению | Примечание  |
+===+===============+============+===========+===========================+=========================+=============+
|0  | Дом           | 01.04.2022 | 11:30     | Более эффективным способом| Неисправимо             | Мне грустно |
|   |               |            |           | обхода дерева для         |                         |             |
|   |               |            |           | выполнения данного задания|                         |             | 
|   |               |            |           | является обход в ширину   |                         |             |
+-------------------+------------+-----------+---------------------------+-------------------------+-------------+
```
## 10. Замечания автора по существу работы

Претензий, замечаний, предложений по данной лабораторной работе не имею.

## 11. Выводы

Изучение организации основных динамических структур данных, считаю, необходимым для освоения программирования. Является ступенью к изучению более сложных структур данных: графов. Программирование графами в свою очередь улучшает характеристики по наглядности, простоте, компактности, скорости ввода и занимаемой памяти компьютера.

