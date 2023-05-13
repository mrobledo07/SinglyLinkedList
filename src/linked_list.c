#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "../include/linked_list.h"

/* Linked list for generic types*/
typedef struct{
    void *next;
    void *data;
} Node;

Node *head = NULL;
int n_nodes = 0;

//Insert a Node of a generic type at the beggining of the list O(1)
void addNode(void *data){
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = head;
    head = new;
    n_nodes++;
}


//Remove a Node of a generic type from the list O(n)
int removeNode(void *data){
    Node *aux = head;
    Node *prev = NULL;

    while(aux != NULL){
        if(compare(aux->data, data)){
            if(prev == NULL)
                head = aux->next;
            else
                prev->next = aux->next;
            
            free(aux);
            n_nodes--;
            return 1;
        }
        prev = aux;
        aux = aux->next;
   }
   return 0;
}

//Insert a Node of a generic type in a certain position of the list O(n)
void insertNode(void *data, int position){
    int i = 0;
    Node *aux = head;
    Node *new = malloc(sizeof(Node));
    new->data = data;
    position--;
    while(i < position && aux != NULL){
        aux = aux->next;
        i++;
    }
    if (aux != NULL){
        new->next = aux->next;
        aux->next = new;
    }
    n_nodes++;
}

//Remove all the Nodes of the list O(n)
void removeAllNodes(){
    Node *aux = head;
    Node *prev = NULL;
    while(aux != NULL){
        prev = aux;
        aux = aux->next;
        free(prev);
    }
    head = NULL;
    n_nodes = 0;
}

//Print all the Nodes of the list O(n)
void printList(){
    Node *aux = head;
    while(aux != NULL){
        printf("%s->", (char *)aux->data);
        aux = aux->next;
    }
}

//Shows short menu to interact with the data structure
void printMenu(){
    printf("You can perform the following actions:\n");
    printf("\t1. Add a node to the list\n");
    printf("\t2. Remove a node from the list\n");
    printf("\t3. Insert a node to the list\n");
    printf("\t4. Remove all nodes from the list\n");
    printf("\t5. Print list\n");
    printf("\t6. Exit\n");
}


/* FUNCTIONS IMPLEMENTED TO PERFORM OPERATIONS WITH STRINGS */


//Takes a string introduced by the user and returns it
char *stringScan(){
    char *strin = malloc(sizeof(char) * 25);    //memory allocates for 25 chars
    fgets(strin, sizeof(strin), stdin);         //takes string introduced by the user and insert it to strin variable
    strin[strcspn(strin, "\n")] = '\0';         //replaces "\n" to "\0" from the string introduced by the user
    char *data = malloc(strlen(strin)+1);       //memory allocates the strin variable length plus 1 to data variable("\0" character)
    strcpy(data, strin);                        //copies the strin value to data
    free(strin);                                //free the memory block allocated previously to strin
    return data;
}

//Compares two Strings and returns the result of the comparison
unsigned int compare(void *data1, void *data2){
    int comparison = 0;
    int i = 1;

    if(strlen(data1) != strlen(data2))      //compares the strings's length
        return 0;
    else{
        while(comparison == 0 && i < strlen(data1)){    //if they aren't same length, keeps looping until finds some unequal character
            comparison = *(char *)(sizeof(char)*i + (intptr_t)data1) - *(char *)(sizeof(char)*i + (intptr_t)data1);
            i++;
        }
        
        if(comparison == 0)
            return 1;
        else
            return 0;
    }
    
}