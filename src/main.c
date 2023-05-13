#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../include/linked_list.h"

/* Main function implemented to add information to the Nodes*/
int main(int argc, char **argv){
    char option;
    int result, position;

    do{
        printMenu();
        scanf(" %c", &option);
        getchar();              // getchar removes the new line caracter from the user input
        switch(option){
            case '1':
                printf("Insert the value you want to add to the list: ");
                addNode(stringScan());
                break;
            case '2':
                printf("Insert the value you want to remove from the list: ");
                result = removeNode(stringScan());
                if(result == 1)
                    printf("The node has been removed\n");
                else
                    printf("The node does not exist\n");
                break;
            case '3':
                printf("Insert the position where you want to insert the node: ");
                scanf("%d", &position);
                getchar(); // getchar removes the new line caracter from the user input
                printf("Insert the value you want to insert to the list: ");
                insertNode(stringScan, position);
                break;
            case '4':
                removeAllNodes();
                break;
            case '5':
                printList();
                printf("\n");
                break;
            case '6':
                break;
        }

    }while(option != '6');

    return 0;
}

