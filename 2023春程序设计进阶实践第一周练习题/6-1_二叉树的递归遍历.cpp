//
// Created by lenovo on 2023/6/12.
//
#include<cstdio>
#include<cstdlib>

typedef struct TNode *BinTree;   /* 二叉树类型 */
typedef char ElementType;
struct TNode {    /* 树结点定义 */
    ElementType Data;  /* 结点数据 */
    BinTree Left;   /* 指向左子树 */
    BinTree Right;   /* 指向右子树 */
};
#define MAXSIZE 100

void PreorderTraversal(BinTree BT) {
    if (BT) {
        printf("%c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }

}   /* 二叉树的先序遍历 */

void InorderTraversal(BinTree BT) {
    if (BT) {
        InorderTraversal(BT->Left);
        printf("%c", BT->Data);
        InorderTraversal(BT->Right);
    }

}   /* 二叉树的中序遍历 */
void PostorderTraversal(BinTree BT) {
    if (BT) {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("%c", BT->Data);
    }
}    /* 二叉树的后序遍历 */






//按先序次序输入二叉树中结点的值（一个字符），@表示空树，构造二叉链表表示二叉树T
BinTree CreatBinTree() {
    ElementType ch;
    BinTree T;
    scanf("%c", &ch); /*按先序次序输入树的结点，空树输入@*/
    if (ch == '@')
        T = NULL;
    else {
        T = (BinTree) malloc(sizeof(struct TNode));
        T->Data = ch;
        T->Left = CreatBinTree();
        T->Right = CreatBinTree();
    }
    return T;
}

int main() {
    BinTree BT;
    BT = CreatBinTree();

    if (BT == NULL) {
        printf("\n空树！\n");
    } else {
        printf("先序遍历的结果为：");
        PreorderTraversal(BT);
        printf("\n");

        printf("中序遍历的结果为：");
        InorderTraversal(BT);
        printf("\n");

        printf("后序遍历的结果为：");
        PostorderTraversal(BT);
    }
    return 0;
}
/* 请在这里填写答案 */