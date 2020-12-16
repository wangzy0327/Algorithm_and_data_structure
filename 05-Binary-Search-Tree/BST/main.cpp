#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>
#include "SequenceST.h"
#include "FileOp.h"
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

};

// 测试二分搜索树和顺序查找表之间的性能差距
// 二分搜索树的性能远远优于顺序查找表
int main() {


    //二叉搜索树遍历
    srand(time(NULL));
    BST<int, int> bst = BST<int, int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int N = 10;
    int M = 100;
    for (int i = 0; i < N; i++) {
        int key = rand() % M;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout << key << " ";
        bst.insert(key, value);
    }
    cout << endl;

    // 测试二分搜索树的size()
    cout << "size: " << bst.size() << endl << endl;

    // 测试二分搜索树的前序遍历 preOrder
    cout << "preOrder: " << endl;
    bst.preOrder();
    cout << endl;

    // 测试二分搜索树的中序遍历 inOrder
    cout << "inOrder: " << endl;
    bst.inOrder();
    cout << endl;

    // 测试二分搜索树的后序遍历 postOrder
    cout << "postOrder: " << endl;
    bst.postOrder();
    cout << endl;

    // 测试二分搜索树的层序遍历 levelOrder
    cout << "levelOrder: " << endl;
    bst.levelOrder();
    cout << endl;

    // 使用圣经作为我们的测试用例
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // 测试 BST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst2 = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst2.search(*iter);
            if (res == NULL)
                bst2.nonRecurInsert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(bst2.contain("god"))
            cout << "No Recursion BST 'god' : " << *bst2.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "Non-Recurition BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // 测试顺序查找表 SST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }
    return 0;
}
