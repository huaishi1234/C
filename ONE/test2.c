#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 动态交互建立二叉树
struct TreeNode* insertNode() {
    int value;
    printf("请输入节点值 (输入-1结束): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL; // 输入-1表示结束当前分支
    }

    // 分配内存并初始化新节点
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("内存分配失败\n");
        exit(1); // 内存分配失败时退出程序
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // 递归插入左子节点
    printf("请输入 %d 的左子节点:\n", value);
    newNode->left = insertNode();

    // 递归插入右子节点
    printf("请输入 %d 的右子节点:\n", value);
    newNode->right = insertNode();

    return newNode; // 返回新创建的节点
}

// 先序遍历 (DLR)
void preOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return; // 空节点直接返回
    }
    printf("%d ", root->data); // 访问根节点
    preOrderTraversal(root->left); // 遍历左子树
    preOrderTraversal(root->right); // 遍历右子树
}

// 中序遍历 (LDR)
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return; // 空节点直接返回
    }
    inOrderTraversal(root->left); // 遍历左子树
    printf("%d ", root->data); // 访问根节点
    inOrderTraversal(root->right); // 遍历右子树
}

// 后序遍历 (LRD)
void postOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return; // 空节点直接返回
    }
    postOrderTraversal(root->left); // 遍历左子树
    postOrderTraversal(root->right); // 遍历右子树
    printf("%d ", root->data); // 访问根节点
}

// 计算二叉树中的结点个数
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // 空节点返回0
    }
    // 递归计算左右子树的节点数并加1（根节点）
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 计算二叉树的深度
int calculateDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // 空节点返回0
    }
    // 递归计算左右子树的深度，取较大者并加1（根节点）
    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 释放二叉树内存
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return; // 空节点直接返回
    }
    freeTree(root->left); // 释放左子树内存
    freeTree(root->right); // 释放右子树内存
    free(root); // 释放当前节点内存
}

// 菜单函数，供用户选择操作
void menu() {
    struct TreeNode* root = NULL;
    int choice;

    do {
        printf("\n请选择操作:\n");
        printf("1. 建立二叉树\n");
        printf("2. 先序遍历 (DLR)\n");
        printf("3. 中序遍历 (LDR)\n");
        printf("4. 后序遍历 (LRD)\n");
        printf("5. 计算二叉树中的结点个数\n");
        printf("6. 计算二叉树的深度\n");
        printf("7. 退出\n");
        printf("输入选项编号: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("开始建立二叉树:\n");
                root = insertNode(); // 建立二叉树
                break;
            case 2:
                printf("先序遍历结果: ");
                preOrderTraversal(root); // 先序遍历
                printf("\n");
                break;
            case 3:
                printf("中序遍历结果: ");
                inOrderTraversal(root); // 中序遍历
                printf("\n");
                break;
            case 4:
                printf("后序遍历结果: ");
                postOrderTraversal(root); // 后序遍历
                printf("\n");
                break;
            case 5:
                printf("二叉树中的结点个数: %d\n", countNodes(root)); // 计算节点个数
                break;
            case 6:
                printf("二叉树的深度: %d\n", calculateDepth(root)); // 计算树的深度
                break;
            case 7:
                printf("退出程序\n");
                break;
            default:
                printf("无效的选择，请重新输入\n");
        }
    } while (choice != 7);

    // 释放二叉树内存
    freeTree(root);
}

// 主函数
int main() {
    menu(); // 进入菜单循环
    return 0;
}



