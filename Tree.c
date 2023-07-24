#include "Tree.h"


/*
function to create a node
*/
t_treenode *createNode(char elem[3])
{
    t_treenode *new_node;

    new_node=(t_treenode*)malloc(sizeof(t_treenode));

    if(new_node==NULL)
    {
        printf("Error\n");
    }
    else
    {
        fflush(stdin);
        strcpy(new_node->element, elem);

        new_node->next = NULL;

    }
    return new_node;
}


/*
function to add a node to the stack
*/
t_treenode *Push(t_treenode *List, t_treenode *newnode)
{
    newnode->next = List; //insert a new node at the top
    List = newnode; //update top pointer


    //puts(newnode->element);
    //printf("\nElement has been added\n\n");

    return List;
}


/*
function to remove a node from the stack
*/
t_treenode *Pop(t_treenode *top)
{
    t_treenode *current;

    //if the stack is empty
    if (top == NULL)
    {
        //printf("\nStack is empty\n");
    }
    else
    {
        //update pointers and free memory
        current = top;
        top = top->next;
        free(current);

    }


    //printf("\nElement has been removed\n\n");


    return top;
}


/*
function to display the stack
*/
void displayStack(t_treenode *top)
{
    t_treenode *current;

    //if the stack is empty
    if (top == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        current = top;
        printf("\n-------TOP-------\n");

        //traverse
        while (current->next != NULL)
        {
            puts(current->element);
            //current = current->next;
        }
        //print last element
        //puts(current->element);
    }

    printf("\n");
}


/*
function to create the Tree
*/
t_treenode *createTree()
{

    //create all nodes
    t_treenode *root = createNode("A");
    t_treenode *nodeB = createNode("B");
    t_treenode *nodeBp = createNode("B'");
    t_treenode *nodeC = createNode("C");
    t_treenode *nodeD = createNode("D");
    t_treenode *nodeE = createNode("E");
    t_treenode *nodeF = createNode("F");
    t_treenode *nodeFp = createNode("F'");
    t_treenode *nodeG = createNode("G");
    t_treenode *nodeH = createNode("H");
    t_treenode *nodeI = createNode("I");

    //link all nodes
    root->children[0] = nodeB->element;
    root->children[1] = nodeBp->element;
    root->children[2] = nodeC->element;
    root->children[3] = nodeD->element;
    nodeC->children[0] = nodeG->element;
    nodeC->children[1] = nodeH->element;
    nodeC->children[2] = nodeI->element;
    nodeB->children[0] = nodeE->element;
    nodeB->children[1] = nodeF->element;
    nodeBp->children[0] = nodeFp->element;

    //set number of children
    nodeBp->nb_children = 1;
    root->nb_children = 4;
    nodeC->nb_children = 3;
    nodeB->nb_children = 2;
    nodeD->nb_children = 0;
    nodeE->nb_children = 0;
    nodeF->nb_children = 0;
    nodeFp->nb_children = 0;
    nodeG->nb_children = 0;
    nodeH->nb_children = 0;
    nodeI->nb_children = 0;


    return root;
}

/*
function from a Preorder traverse
*/
void printPreoder(t_treenode *T)
{
    t_treenode *List = NULL;
    t_treenode *current = NULL;
    int i, a;

    //set current as top
    current = T;

    //push first element
    List = Push(List, current);

    printf("PREORDER TRAVERSAL\n");

    //repeat while the list isn't empty
    while(List!=NULL)
    {
        //print element before poping it
        puts(List->element);
        List = Pop(List);

        //get the number of children for top
        a = (current->nb_children);

        //case if number of children is 0
        if(a==0)
        {
            current = current->next;
        }

        else
        {
            //push all children in the stack
            for(i=a-1; i>=0; i--)
                List = Push(List, current->children[i]);

            for(i=a-1; i>=0; i--)
            {
                if(strcmp(current->children[i], List)==0)
                {
                    //update current pointer by verifying that top element of the list is in the tree
                    current = current->children[i];
                    //puts(current->element);
                }

            }
        }

        //displayStack(List);

    }



}



