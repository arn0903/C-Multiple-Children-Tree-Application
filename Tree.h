#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
tree node structure
*/
typedef struct treenode
{
    char element[3];
    struct treenode *child;
    struct treenode *next;
    int nb_children;
    char *children[5];
}t_treenode;

t_treenode *createNode(char elem[3]);
t_treenode *Push(t_treenode *List, t_treenode *newnode);
t_treenode *Pop(t_treenode *top);

void displayStack(t_treenode *top);
t_treenode *createTree();
void printPreoder(t_treenode *T);
#endif // TREE_H_INCLUDED
