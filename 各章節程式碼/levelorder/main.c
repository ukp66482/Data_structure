// C++ code
void BinaryTree::Levelorder(){

    std::queue<TreeNode*> q;
    q.push(this->root);                     // 把root作為level-order traversal之起點
    // 推進queue中
    while (!q.empty()){                     // 若queue不是空的, 表示還有node沒有visiting

        TreeNode *current = q.front();      // 取出先進入queue的node
        q.pop();
        std::cout << current->str << " ";   // 進行visiting

        if (current->leftchild != NULL){    // 若leftchild有資料, 將其推進queue
            q.push(current->leftchild);
        }
        if (current->rightchild != NULL){   // 若rightchild有資料, 將其推進queue
            q.push(current->rightchild);
        }
    }
}