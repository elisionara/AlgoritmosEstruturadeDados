#include<stdio.h>
#include<stdlib.h>

struct vertice{
    char label;
    struct vertice *direita;
    struct vertice *esqerda;

};
typedef vertice Vertice;
