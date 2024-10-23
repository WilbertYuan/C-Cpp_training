#include <stdio.h>
#include <stdlib.h>

// 哈夫曼树结点结构体定义
typedef struct hfmNode {
    int weight;                // 权重
    struct hfmNode* left;      // 左孩子
    struct hfmNode* right;     // 右孩子
} HfmNode;

// 创建哈夫曼树结点
HfmNode* CreateHfmNode(int weight) {
    HfmNode* node = (HfmNode*)malloc(sizeof(HfmNode));
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 定义哈夫曼树结点的比较函数（用于优先队列）
int Compare(const void* a, const void* b) {
    return ((HfmNode*)a)->weight - ((HfmNode*)b)->weight;
}

// 创建哈夫曼树
HfmNode* CreateHuffmanTree(int weights[], int n) {
    HfmNode** nodes = (HfmNode**)malloc(n * sizeof(HfmNode*));

    // 创建叶子结点
    for (int i = 0; i < n; i++) {
        nodes[i] = CreateHfmNode(weights[i]);
    }

    // 创建哈夫曼树
    while (n > 1) {
        // 排序
        qsort(nodes, n, sizeof(HfmNode*), Compare);

        // 取出权重最小的两个结点
        HfmNode* left = nodes[0];
        HfmNode* right = nodes[1];

        // 创建新结点，权重为左右子树的权重之和
        HfmNode* parent = CreateHfmNode(left->weight + right->weight);
        parent->left = left;
        parent->right = right;

        // 替换原有结点
        nodes[0] = parent;
        for (int i = 1; i < n - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        n--;
    }

    HfmNode* root = nodes[0];
    free(nodes);
    return root;
}

// 打印哈夫曼编码
void PrintHuffmanCodes(HfmNode* root, char* code, int length) {
    if (!root) return;

    // 如果是叶子结点，打印编码
    if (!root->left && !root->right) {
        code[length] = '\0'; // 结束字符串
        printf("权重 %d: %s\n", root->weight, code);
    }

    // 遍历左子树和右子树
    code[length] = '0'; // 左子树编码
    PrintHuffmanCodes(root->left, code, length + 1);

    code[length] = '1'; // 右子树编码
    PrintHuffmanCodes(root->right, code, length + 1);
}

// 主函数
int main() {
    int weights[] = { 5, 9, 12, 13, 16, 45 }; // 各字符的权重
    int n = sizeof(weights) / sizeof(weights[0]);

    // 创建哈夫曼树
    HfmNode* root = CreateHuffmanTree(weights, n);

    // 打印哈夫曼编码
    char code[100]; // 存储编码
    printf("哈夫曼编码:\n");
    PrintHuffmanCodes(root, code, 0);

    // 释放内存（略）

    return 0;
}
