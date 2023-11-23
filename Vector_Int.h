//
// Vector_Int.h
//

#ifndef RESIZABLE_INT_ARRAY
#define RESIZABLE_INT_ARRAY

typedef struct {
    int* array;
    int length;
} Vector_Int;

// A function for copying int arrays for convinience
void copyIntArrays(
    int* a,int* b , int length
);

// Reserve space in vector and initialize its default values as 0
void Vector_Int_Rsrv(
    Vector_Int* v,int space
);

// Adding values to the Vector
void Vector_Int_Push(
    Vector_Int* v, int x
);

// Finally, Destroying the vector
void Vector_Int_Destroy (
    Vector_Int* v
);

// A function for printing the int vector
void Vector_Int_Print(
    Vector_Int* v
);

#endif