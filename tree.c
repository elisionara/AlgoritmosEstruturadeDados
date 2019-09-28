#include<stdio.h>
#include<stdlib.h>
#include"vertex.h"

//ADICIONANDO UM VÉRTICE
vertex* addVertex(vertex* root, int element){
    if(root == NULL){
            root = (vertex*)malloc(sizeof(vertex));
            root -> left = NULL;
            root -> right = NULL;
            root -> key = element;

    }else if(root -> key > element){
            root -> left = addVertex(root -> left, element);

    }else{
            root -> right = addVertex(root -> right, element);

    }
    return root;
}
//REMOVENDO UM VÉRTICE
vertex* biggeright(vertex* no){
    if(no -> right != NULL){
        no -> right = biggeright(no -> right);

    }else{
        vertex* aux = NULL;
        aux = (vertex*)malloc(sizeof(vertex*));

        *aux = *no;

        free(no);
        no = NULL;
        free(no -> right);

        return aux;
    }

}

vertex* rmvertex(vertex* leaf, int element){
    if(leaf == NULL){
        return NULL;

    }else if(leaf -> key > element){
        leaf -> left = rmvertex(leaf -> left, element);

    }else if(leaf -> key < element){
            leaf -> right = rmvertex(leaf -> right , element);

    }else{
        if(leaf -> left == NULL && leaf -> right == NULL){
            free(leaf);
            return NULL;

        }else if(leaf -> left == NULL && leaf -> right != NULL){
              vertex* aux1 = leaf;
              return leaf -> right;

              free(aux1);

        }else if(leaf -> right == NULL && leaf -> left != NULL){
            vertex* aux = leaf;
            return leaf -> left;

            free(aux);

        }else if(leaf -> right != NULL && leaf -> left != NULL){
          vertex* aux = biggeright(leaf -> left);


          aux -> right = leaf->right;
          aux -> left = leaf->left;

          free(leaf -> left);
          leaf = NULL;

          return aux;

      }
    }
}

//IMPRIMINDO!!!!
//IMPRIMINDO EM ORDEM
void treeInorder(vertex* root){//LADO ESQUERDO, VISITA A RAIZ, LADO DIREITO
    if(root != NULL){
        treeInorder(root -> left);
        printf("%d ", root -> key);
        treeInorder(root -> right);
    }
}

//IMPRIMINDO PRE-ORDEM
void treePreorder(vertex* root){//RAIZ, LADO ESQUERDO, LADO DIREITO
    if(root != NULL){
        printf("%d ", root -> key);
        treePreorder(root -> left);
        treePreorder(root -> right);
    }
}

//IMPRIMINDO POS-ORDEM
void treePosorder(vertex* root){//LADO ESQUEDO, LADO DIREIRO, RAIZ
    if(root != NULL){
        treePosorder(root -> left);
        treePosorder(root -> right);
        printf("%d ", root -> key);
    }
}

void treeInorder(vertex* root);
void treePreorder(vertex* root);
void treePosorder(vertex* root);

vertex* addVertex(vertex* root, int element);
vertex* rmvertex(vertex* leaf, int element);
vertex* biggerihgt(vertex* no);

int main(){

    vertex* root = NULL;

    root = addVertex(root, 100);
    root = addVertex(root, 50);
    root = addVertex(root, 200);
    root = addVertex(root, 80);
    root = addVertex(root, 90);
    root = addVertex(root, 70);
    root = addVertex(root, 60);
    root = addVertex(root, 120);
    root = addVertex(root, 140);
    root = addVertex(root, 250);

    printf("In Order:\n");
    treeInorder(root);

    printf("\nPre Order:\n");
    treePreorder(root);

    printf("\nPos Order:\n");
    treePosorder(root);

    printf("\nRemovendo...\n");
    root = rmvertex(root, 50);
    //root = rmvertex(root, 100);
    root = rmvertex(root, 120);

    printf("In Order:\n");
    treeInorder(root);

    return 0;

}
