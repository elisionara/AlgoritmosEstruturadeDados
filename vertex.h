#include<stdio.h>
#include<stdlib.h>

struct vertice{
    int key;
    struct vertice *left;
    struct vertice *right;

};
typedef struct vertice vertex;
