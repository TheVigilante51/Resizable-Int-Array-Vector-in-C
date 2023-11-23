//
// Vector_Int.c
//

#include "Vector_Int.h"
#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BRIGHT_GREEN "\x1b[92m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void copyIntArrays(int* a,int* b , int length)
{
    for(int i = 0; i < length ; i++)
    {
        b[i] = a[i];
    }
}

void Vector_Int_Rsrv (Vector_Int* v,int space)
{
    v->array = malloc ( sizeof(int) * space);
    v->length = 0;

    if (v->array == NULL)
    {
        printf(ANSI_COLOR_RED "There was a problem with malloc" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "\nCouldn't allocate memory" ANSI_COLOR_RESET);
        return;
    }
    // Setting Default Value to 0
    // Initializing the length var
    for (int i = 0; i < space ; i++)
    {
        v->array[i] = 0;
        v->length++;
    }
    printf(ANSI_COLOR_BRIGHT_GREEN "Memory allocated Successfully !\n" ANSI_COLOR_RESET);
}

void Vector_Int_Push (Vector_Int* v, int x)
{
    // Checking if the array is FRESH for efficient code
    if ( ( v->array[0] == 0 ) && (( v->length * sizeof(int) ) == sizeof(int) ) )
    {
        v->array[0] = x;
        return;
    }

    // Getting size and length of the present array
    int size = (v->length) * sizeof(int); // No. of values 
    
    // Creating a new buffer to store the present values of array
    int* temp = malloc (size);  
    // Copying the content to temprory buffer
    copyIntArrays (v->array , temp, v->length); 

    // Freeing the present array so as to store
    // New values in a bigger array
    free(v->array);

    // Allocating the required memory size to add 
    // Given int value to the array
    v->array = malloc (size + sizeof(int));
    copyIntArrays (temp , v->array, v->length); // copying old data

    // Adding the given new value to the array
    v->array[v->length] = x;
    v->length++;

    // Freeing the temprory buffer
    free(temp);
}

void Vector_Int_Destroy (Vector_Int* v)
{
    free(v->array);
}

void Vector_Int_Print (Vector_Int* v)
{
    printf(ANSI_COLOR_BLUE "===============================\n" ANSI_COLOR_RESET);

    for(int i = 0; i < (v->length) ; i++)
    {
        printf("%d\t",v->array[i]);
    }
    printf("\n");
    printf(ANSI_COLOR_BLUE "===============================\n" ANSI_COLOR_RESET);
}