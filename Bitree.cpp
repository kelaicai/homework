
#include <stdio.h>
#include <stdlib.h>
//#define NULL 0
typedef char TElemType;
typedef struct BitNode
{
  TElemType data;
  struct BitNode *lchild,*rchild;

} BiTNode,*BiTree;

void CreateBiTree(BiTree *T)
{
  char ch;
  scanf("%c",&ch);
  if(ch ==' ') *T=NULL;
  else
  {
    if(!((*T)=(BiTNode *)malloc(sizeof(BiTNode)))) exit(-1);
    (*T)->data=ch;
    CreateBiTree(&((*T)->lchild));
    CreateBiTree(&((*T)->rchild));
  }
}

void PreOrderTraverse(BiTree T)
{
  if(T ==NULL) return;
  else
    printf("%c",T->data);
  if(T->lchild) PreOrderTraverse(T->lchild);
  if(T->rchild) PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
  if(T ==NULL) return;


  if(T->lchild) InOrderTraverse(T->lchild);
  printf("%c",T->data);
  if(T->rchild) InOrderTraverse(T->rchild);
}

void AfterOrderTraverse(BiTree T)
{
  if(T ==NULL) return;
  if(T->lchild) AfterOrderTraverse(T->lchild);
  if(T->rchild) AfterOrderTraverse(T->rchild);
  printf("%c",T->data);
}

main()
{
  BiTree T;
  printf("������������������������:\n");
  CreateBiTree(&T);
  printf("\n�����������Ϊ:\n");
  PreOrderTraverse(T);
  printf("\n�����������Ϊ:\n");
  InOrderTraverse(T);
  printf("\n�����������Ϊ:\n");
  AfterOrderTraverse(T);

}


