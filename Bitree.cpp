
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
  printf("请输入先序建立二叉树的序列:\n");
  CreateBiTree(&T);
  printf("\n先序遍历序列为:\n");
  PreOrderTraverse(T);
  printf("\n中序遍历序列为:\n");
  InOrderTraverse(T);
  printf("\n后序遍历序列为:\n");
  AfterOrderTraverse(T);

}


