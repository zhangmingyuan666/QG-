#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "binary_sort_tree.h"

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr * T)//初始化树
{
    *T = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));

    (*T)->root = NULL;

    return 1;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr * T, ElemType n)//插入节点
{
    NodePtr p = (NodePtr)malloc(sizeof(Node));
    if(BST_search(*T, n))
    {
        printf("树中已经有这个数字了 无法插入");
        return 0;
    }
    p->value = n;
    p->right = NULL;
    p->left = NULL;

    if(((*T)->root) == NULL)
    {
        (*T)->root = p;
        printf("%d", (*T)->root->value);
        return 1;
    }

    NodePtr q=(*T)->root ,parent;
    do{
        parent=q;

        if(parent->value>n)
            q=parent->left;
        else
            q=parent->right;
    }while(q!=NULL);

    if(parent->value>n)
        parent->left=p;
    else
        parent->right=p;


    return 1;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr T, ElemType n)
{
    NodePtr p = BST_search1(T->root,n);
    if(p == NULL)
    {
        printf("查找不到%d这个元素\n");
        return 0;
    }
    else
    {
        printf("查找的到%d这个元素");
        return 1;
    }
}

NodePtr BST_search1(NodePtr pTree,ElemType key)
{
	if(!pTree || pTree->value == key)	//查找到时返回的pTree为该元素节点，没查找到时为NULL
		return pTree;
	else if(key < pTree->value)			//如果key小于当前节点的值，则在其左子树中递归查找
		return BST_search1(pTree->left,key);
	else								//如果key大于当前节点的值，则在其右子树中递归查找
		return BST_search1(pTree->right,key);
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr * T, ElemType key)//删除节点
{
    DeleteBST(&(*T)->root, key);
}

Status DeleteBST(NodePtr *T,int key)
{
    if((*T) == NULL)
    {
        printf("树空 无法删除\n\n");
        return 0;
    }

    else
    {
        if(key == (*T)->value)
        {
            return BST_deleteNodes(T);//执行删除函数
        }

        else if(key < (*T)->value)
        {
            return DeleteBST(&((*T)->left),key);
        }

        else
        {
            return DeleteBST(&((*T)->right),key);
        }
    }
}




Status BST_deleteNodes(NodePtr * T)//用于删除节点
{

    NodePtr p = NULL,s = NULL;

    if((*T)->left == NULL)
    {
        p = (*T);
        (*T) = (*T)->right;
        free(p);
    }

    else if((*T)->right == NULL)
    {
        p = (*T);
        (*T) = (*T)->left;
        free(p);
    }

    else//这种情况 用b的子节点的右节点的最右边代替这个节点
    {
        p = (*T);
        s = (*T)->left;
        while(s->right != NULL)
        {
            p = s;
            s = s->right;
        }

       (*T)->value = s->value;

        if(p!=(*T))//后面这一段不太懂 为什么p有可能不等于*T讷

        {
            p->right = s->left;
        }
        else
        {
            p->left = s->left;
        }

        free(s);

    }
    return 1;
}


void visit(NodePtr P)
{
    printf("%d\t", P->value);
}

Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr))//带递归的先序遍历
{
    BST_preorderI_1(T->root,visit);

    return 1;
}

Status BST_preorderI_1(NodePtr T, void (*visit)(NodePtr))
{
    if(T!=NULL)
    {
        visit(T);
        BST_preorderI_1(T->left,visit);
        BST_preorderI_1(T->right,visit);
    }
}

Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    BST_inorderI_1(T->root,visit);

    return 1;
}
Status BST_inorderI_1(NodePtr T, void (*visit)(NodePtr))
{
    if(T!=NULL)
    {

        BST_inorderI_1(T->left,visit);
        visit(T);
        BST_inorderI_1(T->right,visit);
    }
}

Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    BST_postorderI_1(T->root,visit);

    return 1;
}

Status BST_postorderI_1(NodePtr T, void (*visit)(NodePtr))
{
    if(T!=NULL)
    {
        BST_postorderI_1(T->left,visit);
        BST_postorderI_1(T->right,visit);
        visit(T);
    }
}


/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */

void menu(void)
{
    printf("************************************\b");
    printf("请输入你需要的操作:\n");
    printf("1.初始化树（必须初始化才能跑）\n");
    printf("2.查找数字\n");
    printf("3.插入数字\n");
    printf("4.删除数字\n");
    printf("5.递归前序遍历\n");
    printf("6.递归中序遍历\n");
    printf("7.递归后序遍历\n");
    printf("8.迭代前序遍历\n");
    printf("9.迭代中序遍历\n");
    printf("10.迭代后续遍历\n");
    printf("11.层序遍历\n");
    printf("12.退出程序\n");
    printf("************************************\n");
    printf("请输入你的操作:");
    printf("\n\n");
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    levelorder(T->root,visit);
    return 1;
}

void levelorder(NodePtr bt, void (*visit)(NodePtr))
{
    NodePtr q[100];

    ElemType front = 0, rear = 0;
    NodePtr p;
    if(bt == NULL)
        return;

    q[rear] = bt;//q[0]一开始被定义为队首
    rear = (rear + 1) % 100;
    while(front!=rear)
    {
        p = q[front];
        front = (front + 1) % 100;
        visit(p);
        if(p->left != NULL)
        {
            q[rear]=p->left;
            rear = (rear + 1) % 100;
        }

        if(p->right != NULL)
        {
            q[rear]=p->right;
            rear=(rear+1)%100;
        }
    }
    printf("\n");
}
