#include "Vector_Int.h"

int main()
{
    Vector_Int v;
    Vector_Int_Rsrv (&v, 1);
    Vector_Int_Push (&v, 18);
    Vector_Int_Push (&v, 69);
    Vector_Int_Print (&v);

    Vector_Int_Push (&v, 86);
    Vector_Int_Print (&v);

    Vector_Int_Push (&v, 21);
    Vector_Int_Print (&v);

    Vector_Int_Destroy (&v);
    return 0;
}