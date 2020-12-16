#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>
#include <algorithm>
#include "FileOp.h"
#include "SequenceST.h"

using namespace std;

template<typename Key,typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;
        Node(Key key,Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };
    Node* root;
    int count;
public:
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        //TODO:~BST()
        destory(root);
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;
    }
    void insert(Key key, Value value){
        root = insert(root,key,value);
    }
    //插入元素 非递归
    void nonRecurInsert(Key key, Value value){
        nonRecurInsert(root,key,value);
    }
    bool contain(Key key){
        return contain(root,key);
    }
    Value* search(Key key){
        return search(root,key);
    }
    //先序遍历
    void preOrder(){
        preOrder(root);
    }
    //中序遍历
    void inOrder(){
        inOrder(root);
    }
    //后序遍历
    void postOrder(){
        postOrder(root);
    }
    //层序遍历
    void levelOrder(){
        queue<Node*> q;
        if(root == NULL)
            return;
        q.push(root);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            cout<<cur->key<<endl;
            if(cur->left != NULL)
                q.push(cur->left);
            if(cur->right != NULL)
                q.push(cur->right);
        }
    }

    //寻找最小的键值
    Key minimum(){
        assert(count != 0);
        Node* minNode = minimum(root);
        return minNode->key;
    }

    //寻找最小的键值
    Key maximum(){
        assert(count != 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }

    //从二叉搜索树中删除最小键值所在节点
    void removeMin(){
        if(root)
            root = removeMin(root);
    }

    //从二叉搜索树中删除最大键值所在节点
    void removeMax(){
        if(root)
            root = removeMax(root);
    }

    //从二叉树中删除键值为key的节点
    void remove(Key key){
        root = remove(root,key);
    }


private:
    //向以Node为根的二叉搜索树中，插入节点（key,value）
    //返回插入新节点后的二叉搜索树的根
    Node* insert(Node* node,Key key,Value value){
        if(node == NULL){
            count ++;
            return new Node(key,value);
        }
        if(key == node->key)
            node->value = value;
        else if(key < node->key)
            node->left =  insert(node->left,key,value);
            //else if key > node->key
        else
            node->right = insert(node->right,key,value);
        return node;
    }
    //非递归插入新节点
    void nonRecurInsert(Node* node,Key key,Value value){
        if(this->root == NULL){
            this->root = new Node(key,value);
            count++;
            return;
        }
        Node* cur = node;
        Node* par = NULL;
        while(cur != NULL){
            if(cur->key == key){
                cur->value = value;
                return;
            }
            par = cur;
            if(cur->key > key)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if(par->key > key)
            par->left = new Node(key,value);
        else
            par->right = new Node(key,value);
        count++;
    }
    //查看以Node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node* node,Key key){
        if(node == NULL)
            return false;
        if(key == node->key)
            return true;
        else if(node->key < key)
            return contain(node->right,key);
            //else if node->key > key
        else
            return contain(node->left,key);
    }
    //在以Node为根的二叉搜索树中查找key所对应的value
    Value* search(Node* node,Key key){
        if(node == NULL)
            return NULL;
        if(node->key == key)
            return &(node->value);
        else if(node->key > key)
            return search(node->left,key);
        else
            return search(node->right,key);
    }

    //对以node为根的二叉搜索树进行前序遍历
    void preOrder(Node* node){
        if(node != NULL){
            cout<<node->key<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    //对以node为根的二叉搜索树进行中序遍历
    void inOrder(Node* node){
        if(node != NULL){
            cout<<node->key<<endl;
            inOrder(node->left);
            inOrder(node->right);
        }
    }

    //对以node为根的二叉搜索树进行后序遍历
    void postOrder(Node* node){
        if(node != NULL){
            cout<<node->key<<endl;
            postOrder(node->left);
            postOrder(node->right);
        }
    }


    void destory(Node* node){
        if(node != NULL){
            destory(node->left);
            destory(node->right);
            delete node;
            count--;
        }
    }
    //在以node为根的二叉搜索树中，返回最小键值的节点
    Node* minimum(Node* node){
        while(node->left != NULL)
            node = node->left;
        return node;
    }

    //在以node为根的二叉搜索树中，返回最大键值的节点
    Node* maximum(Node* node){
        while(node->right != NULL)
            node = node->right;
        return node;
    }

    //删除掉以node为根的二叉搜索树中的最小节点
    //返回删除节点后新的二叉搜索树的根
    Node* removeMin(Node* node){
        if(node->left == NULL){
            Node* rightNode = node->right;
            delete node;
            count --;
            return rightNode;
        }
        node->left = removeMin(node);
        return node;
    }

    //删除掉以node为根的二叉搜索树中的最大节点
    //返回删除节点后新的二叉搜索树的根
    Node* removeMax(Node* node){
        if(node->right == NULL){
            Node* leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }
        node->right = removeMax(node);
        return node;
    }

    //删除掉以node为根的二叉搜索树中键值为key的节点
    //返回删除节点后新的二叉搜索树的根
    Node* remove(Node* node,Key key){
        if(node == NULL)
            return NULL;
        if(key < node->key){
            node->left = remove(node->left,key);
            return node;
        }
        else if(key > node->key){
            node->right = remove(node->right,key);
            return node;
        }
            //key == node->key
        else{
            if(node->left == NULL){
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if(node->right == NULL){
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            //node->left != NULL && node->right != NULL
            Node* successor = new Node(minimum(node->right));
            count++;
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            count--;
            return successor;
        }
    }

};

// 实验二分搜索树的局限性
//二分搜索树在有序的情况下会退化为链表O(n)
//二分搜索树退化为链表后
// 1、每次都会查找左右子树
// 2、递归也会降低效率

//解决办法：平衡二叉树
//平衡二叉树具体实现有：红黑树、AVL树、2-3树等
int main() {

    // 我们使用文本量更小的共产主义宣言进行试验:)
    string filename = "communist.txt";
    vector<string> words;

    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试1, 我们按照文本原有顺序插入进二分搜索树
        time_t startTime = clock();
        BST<string, int> *bst = new BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst).search(*iter);
            if (res == NULL)
                (*bst).insert(*iter, 1);
            else
                (*res)++;
        }

        // 我们查看unite一词的词频
        if( bst->contain("unite") )
            cout << "'unite' : " << *(*bst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete bst;


        // 测试2, 我们按照文本原有顺序插入顺序查找表
        startTime = clock();
        SequenceST<string, int> *sst = new SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*sst).search(*iter);
            if (res == NULL)
                (*sst).insert(*iter, 1);
            else
                (*res)++;
        }

        // 我们查看unite一词的词频
        if( sst->contain("unite") )
            cout << "'unite' : " << *(*sst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete sst;


        sort( words.begin() , words.end() );

        // 测试3, 我们将原文本排序后插入二分搜索树, 查看其效率
        startTime = clock();
        BST<string, int> *bst2 = new BST<string, int>();

        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst2).search(*iter);
            if (res == NULL)
                (*bst2).insert(*iter, 1);
            else
                (*res)++;
        }

        // 我们查看unite一词的词频
        cout << "'unite' : " << *(*bst2).search("unite") << endl;
        endTime = clock();

        cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete bst2;
    }




    return 0;
}
