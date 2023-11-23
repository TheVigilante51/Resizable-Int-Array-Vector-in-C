//
// Vector_Int.h
//

#ifndef RESIZABLE_INT_ARRAY
#define RESIZABLE_INT_ARRAY

typedef struct {
    int* array;
    int length;
} Vector_Int;

void copyIntArrays(
    int* a,int* b , int length
);

void Vector_Int_Rsrv(
    Vector_Int* v,int space
);

void Vector_Int_Push(
    Vector_Int* v, int x
);

void Vector_Int_Destroy (
    Vector_Int* v
);

void Vector_Int_Print(
    Vector_Int* v
);

#endif