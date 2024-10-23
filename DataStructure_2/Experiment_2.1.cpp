#include <stdio.h>
#include <stdlib.h>
// 二叉树结点结构体定义
typedef struct btnode {
	char element;          // 数据元素
	struct btnode* lChild; // 左孩子指针
	struct btnode* rChild; // 右孩子指针
} BTNode;

// 二叉树结构体定义
typedef struct binarytree {
	BTNode* root;         // 指向根结点的指针
} BinaryTree;

BTNode* NewNode(char x, BTNode* ln, BTNode* rn) {
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	if (!p) return NULL; // 内存分配失败
	p->element = x;
	p->lChild = ln;
	p->rChild = rn;
	return p;
}

// 创建
void Create(BinaryTree* bt) {
	bt->root = NULL; // 初始化根结点为空
}

// 先序遍历
void PreOrder(BTNode* t) {
	if (!t) return;
	printf("%c ", t->element); // 访问根结点
	PreOrder(t->lChild);       // 先序遍历左子树
	PreOrder(t->rChild);       // 先序遍历右子树
}

void PreOrderTree(BinaryTree* bt) {
	PreOrder(bt->root);
}

// 计算结点总数
int CountNodes(BTNode* t) {
	if (!t) return 0;
	return 1 + CountNodes(t->lChild) + CountNodes(t->rChild); // 递归计算
}

// 计算叶结点个数
int CountLeafNodes(BTNode* t) {
	if (!t) return 0;
	if (!t->lChild && !t->rChild) return 1; // 叶结点
	return CountLeafNodes(t->lChild) + CountLeafNodes(t->rChild); // 递归计算
}

// 计算树的高度
int TreeHeight(BTNode* t) {
	if (!t) return 0;
	int leftHeight = TreeHeight(t->lChild);
	int rightHeight = TreeHeight(t->rChild);
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // 返回高度
}

// 交换二叉树的左右子树
void SwapSubtrees(BTNode* t) {
	if (!t) return;
	BTNode* temp = t->lChild;
	t->lChild = t->rChild;
	t->rChild = temp;
	SwapSubtrees(t->lChild);
	SwapSubtrees(t->rChild);
}


int main() {
	BinaryTree bt;
	Create(&bt);
	BTNode* a = NewNode('A', NULL, NULL);
	BTNode* b = NewNode('B', NULL, NULL);
	BTNode* c = NewNode('C', NULL, NULL);
	BTNode* d = NewNode('D', NULL, NULL);
	BTNode* e = NewNode('E', NULL, NULL);

	bt.root = NewNode('F', a, b);
	a->lChild = c;
	a->rChild = d;
	b->rChild = e;

	printf("先序遍历: ");
	PreOrderTree(&bt);
	printf("\n结点总数: %d\n", CountNodes(bt.root));
	printf("叶结点个数: %d\n", CountLeafNodes(bt.root));
	printf("树的高度: %d\n", TreeHeight(bt.root));

	SwapSubtrees(bt.root);
	printf("交换子树后的先序遍历: ");
	PreOrderTree(&bt);
	printf("\n");
	return 0;
}

