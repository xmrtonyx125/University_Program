#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "node.h"
#include "athlete.h"
#include "ultilies.h"
void createList ( dbl_linked_list_t* lPtr){

	lPtr -> headPtr = NULL;
	lPtr -> tailPtr = NULL;

}

void insertNode ( dbl_linked_list_t* lPtr, node_t* nPtr){
	node_t* curPtr;
        if ( lPtr != NULL ){
                if ( lPtr -> headPtr == NULL){
                        lPtr -> headPtr = nPtr; // get the same address of n
                        lPtr -> tailPtr = nPtr;
                 }
		// if nPtr need to be insert before the head of the list
                else if (strcmp (nPtr -> a.nationality, lPtr -> headPtr -> a.nationality) < 0){ 
				lPtr -> headPtr -> prevPtr = nPtr;
				nPtr -> nextPtr = lPtr -> headPtr;
				lPtr -> headPtr = nPtr;				
		}
		else if (strcmp (nPtr -> a.nationality , lPtr -> tailPtr -> a.nationality) >= 0){
				lPtr -> tailPtr -> nextPtr = nPtr;
				nPtr -> prevPtr = lPtr -> tailPtr;
				lPtr -> tailPtr = nPtr;
		}
		else {
			curPtr = lPtr -> headPtr;
			while(curPtr != NULL){
				if (strcmp (nPtr -> a.nationality, curPtr  -> a.nationality ) < 0){
					nPtr -> nextPtr = curPtr;
                                        nPtr -> prevPtr = curPtr -> prevPtr;
                                        curPtr -> prevPtr -> nextPtr = nPtr;
                                        curPtr -> prevPtr = nPtr;
					break;

			}				
			curPtr= curPtr -> nextPtr;

			}				
		}
	}	
}

void deleteList ( dbl_linked_list_t* lPtr ){
	
	node_t* curPtr;
	
	if( lPtr != NULL && lPtr -> headPtr != NULL){

		curPtr = lPtr -> headPtr;
		while(curPtr != NULL){
			lPtr -> headPtr = curPtr -> nextPtr;
			free(curPtr);
			curPtr = lPtr -> headPtr;
		}
	}
	lPtr -> tailPtr = NULL;

}

int find_Country(const dbl_linked_list_t* lPtr,int* gold, int* silver, int* bronze, char key_country[]){
        node_t* curPtr;
        int foundOne = FALSE;
        curPtr = lPtr -> headPtr;
        while (curPtr != NULL){
                if (strcmp (key_country, curPtr ->a.nationality ) == 0){
                        *gold += curPtr -> a.gold;
                        *silver += curPtr -> a.silver;
                        *bronze += curPtr -> a.bronze;
			foundOne = TRUE;
                }
                curPtr = curPtr -> nextPtr;
        }
	return foundOne;
}


void find_Athlete (const dbl_linked_list_t* lPtr, char key_name[], int size){
	node_t* curPtr;
	int foundOne = FALSE;
	char temp [256];
	curPtr = lPtr -> headPtr;
	while (curPtr != NULL){
		strcpy (temp, curPtr -> a.name);
		to_Lower (temp);
		if (strncmp (temp, key_name, size - 1) == 0){
			foundOne = TRUE;
			print_Athlete (curPtr -> a);
		}
		curPtr = curPtr -> nextPtr;
	}
	if (foundOne == FALSE){
		printf (" There is no match for this athlete name\n");
	}
		
}

void traverseStack (const dbl_linked_list_t* lPtr){
	int i = 0;        
	node_t* curPtr;
        if ( lPtr != NULL) { // if the list exists
		curPtr = lPtr -> headPtr;
                while (curPtr != NULL ){
			i++;
                        print_Athlete(curPtr -> a);
                        curPtr = curPtr -> nextPtr;
                }
        }
	printf("%d\n", i);
}

