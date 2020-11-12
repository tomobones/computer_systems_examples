// **********************************
// *                                *
// *  display the content of a      *
// *  variable as it is saved in    *
// *  memory as a hex bytes         *
// *                                *
// *                                *
// *                                *
// *                                *
// **********************************


#include <stdio.h>

// cast pointer to this simple pointer -> pointer arithmetics
// consider pointer as sequence of bytes rather than original data type
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void* x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
   
    printf("int:     "); 
    show_int(ival);
    printf("float:   "); 
    show_float(fval);
    printf("pointer: "); 
    show_pointer(pval);
}

int main()
{
    int val;

    printf("please enter a value: ");
    scanf("%d", &val);
    test_show_bytes(val);
    return 0;
}