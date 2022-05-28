#include <stdio.h>
#include <stdlib.h>
//큐
inline void error (const char *str ) {
    fprintf(stderr, "%s\n", str);
}

#define MAX_QUEUE_SIZE 100

class BinaryNode{
    int data;
    BinaryNode *left;
    BinaryNode *right;
public:
    bool isLeaf() {return (left==NULL && right == NULL);}
    int getData() {return data; }
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    void setLeft(BinaryNode *n) {left = n;}
    void setRight(BinaryNode *n) {right = n;}
    void setData(int val) {data = val;}
    BinaryNode(int val = 0, BinaryNode *l = NULL, BinaryNode *r = NULL) {data = val; left = l, right = r;}

    BinaryNode* serach(int key){
        if(key == data)
            return this;
        else if(key < data && left != NULL)
            return left->serach(key);
        else if (key > data && right != NULL)
            return right->serach(key);
        else
            return NULL;
    }

};

class CircularQueue
{
protected:
    int front;
    int rear;
    BinaryNode *data[MAX_QUEUE_SIZE];
public:
    CircularQueue() {front = rear = 0; }
    ~CircularQueue() { }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear+1)%MAX_QUEUE_SIZE == front; };
    void enqueue( BinaryNode* n ) {
        if( isFull() )
            error(" error : 큐가 포화상태입니다\n");
        else{
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = n;
        }
    }
    BinaryNode* dequeue() {
        if( isEmpty() )
            error(" error : 큐가 공백상태입니다\n");
        else {
            front = (front + 1)%MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};


class BinaryTree{
    BinaryNode *root;
public:
    BinaryTree() {}
    ~BinaryTree() {}
    bool isEmpty() {return root == NULL; }
    void setRoot(BinaryNode *n){ root = n; }

    //이진트리의 inorder 순회 연산
    void inorder() {printf("\n inorder :"); inorder(root);}
    void inorder(BinaryNode *node){// 순환적인 트리의 순회 함수
        if(node != NULL){
            if(node->getLeft() != NULL) inorder(node->getLeft());
            printf("[\t%c]", node->getData());
            if(node->getRight() != NULL ) inorder(node->getRight());
        }
    }

    void preorder(){printf("\n preorder : "); preorder(root);}
    void preorder(BinaryNode *node){
        if(node != NULL){
            printf("[\t%c]", node->getData());
            if(node->getLeft() != NULL) preorder(node->getLeft());
            if(node->getRight() != NULL) preorder(node->getRight());
        }
    }

    void postorder(){ printf("\n postorder : "); postorder(root); }
    void postorder(BinaryNode *node){
        if(node != NULL){
            if(node->getLeft() != NULL) postorder(node->getLeft());
            if(node->getRight() != NULL) postorder(node->getRight());
            printf("[\t%c]", node->getData());
        }
    }

    void levelorder(){ printf("\n levelorder: "); levelorder(root);}
    void levelorder(BinaryNode *node){
        if(node != NULL){
            CircularQueue que;
            que.enqueue(root);
            while(!que.isEmpty()){
                BinaryNode *p = que.dequeue();
                if(p != NULL){
                    printf("[\t%c]", p->getData());
                    que.enqueue(p->getLeft());
                    que.enqueue(p->getRight());
                }
            }
        }
    }

    int evaluate() { return evaluate(root); }
    int evaluate(BinaryNode *node){
        int x = 0;
        int y = 0;
        char op = node->getData();
        if(node == NULL) return 0;
        if(!node->isLeaf()) return node->getData();
        else{
            x = evaluate(node->getLeft());
            y = evaluate(node->getRight());
            switch(op){
                case '+':
                    return x + y; break;
                case '-':
                    return x - y; break;
                case '*':
                    return x * y; break;
                case '/':
                    return x / y; break;       
            }
            return 0;
        }
    }

    int getLeafCount(){ return isEmpty() ? 0 : getLeafCount(root); }
    int getLeafCount(BinaryNode *node) {
		if( node == NULL ) return 0;
		if( node->isLeaf() ) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

    int calcSize(){return isEmpty() ? 0 : calcSize(root);}
    int calcSize(BinaryNode *node){
        if(node == NULL) return 0;
        return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
    }

    int getCount(){return isEmpty() ? 0 : getCount(root);}
    int getCount(BinaryNode *node) {
        if(node == NULL) return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }

    int getHeight() {return isEmpty() ? 0 : getHeight(root); }
    int getHeight(BinaryNode *node) {
        if(node ==NULL) return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
    }

    //탐색
    //삽입연산
    void insertRecur(BinaryNode *r, BinaryNode *n){
        if(n->getData() == r->getData())
            return;
        else if(n->getData() < r->getData()){
            if(r->getLeft() == NULL) r->setLeft(n);
            else insertRecur(r->getLeft(),n );
        }
        else{
            if(r->getRight() == NULL) r->setRight(n);
            else insertRecur(r->getRight(), n);
        }
    }

    //삭제연산
    void remove(int data){
        if(isEmpty()) return;
        BinaryNode *parent = NULL;
        BinaryNode *node = root;
        while( node != NULL && node->getData() != data){
            parent = node;
            node = (data < node->getData()) ? node->getLeft():node->getRight();
        }
        if(node== NULL){
            printf("Error : key is not in the tree\n");
            return;
        }
        else remove(parent, node);
    }
    void remove(BinaryNode *parent, BinaryNode *node){
        //case 1  자식이 0개일때
        if( node->isLeaf()){
            if(parent == NULL) root = NULL;
            else{
                if(parent->getLeft() == node)
                    parent->setLeft(NULL);
                else
                    parent->setRight(NULL);
            }
        }
        //case 2 자식이 1개일때
        else if(node->getLeft() == NULL || node ->getRight() == NULL){
            BinaryNode *child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
            if(node == root)
                root = child;
            else{
                if(parent->getLeft() == node)
                    parent->setLeft(child);
                else   
                    parent->setRight(child);
            }
        }

        //case 3 삭제할Subtree가 2개인 경우
        else{
            BinaryNode* succp = node;
            BinaryNode* succ = node->getRight();
            while(succ->getLeft() != NULL){
                succp = succ;
                succ = succ->getLeft();
            }

            if(succp->getLeft() == succ)
                succp->setLeft(succ->getRight());
            else
                succp->setRight(succ->getRight());
            node->setData(succ->getData());
            node = succ;
        }
        delete node;
    }


};


int main()
{
	BinaryTree tree;

	BinaryNode *d = new BinaryNode('D', NULL, NULL );
	BinaryNode *e = new BinaryNode('E', NULL, NULL );
	BinaryNode *b = new BinaryNode('B', d, e );
	BinaryNode *f = new BinaryNode('F', NULL, NULL );
	BinaryNode *c = new BinaryNode('C', f, NULL );
	BinaryNode *a = new BinaryNode('A', b, c );

	tree.setRoot(a);
	printf(" 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());
	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	BinaryTree tree2;
	//           +
	//       *       -
	//     3   2   5   6
	BinaryNode *n1 = new BinaryNode ( 3 , NULL, NULL );
	BinaryNode *n2 = new BinaryNode ( 2 , NULL, NULL );
	BinaryNode *n3 = new BinaryNode ('*', n1, n2 );
	BinaryNode *n4 = new BinaryNode ( 5 , NULL, NULL );
	BinaryNode *n5 = new BinaryNode ( 6 , NULL, NULL );
	BinaryNode *n6 = new BinaryNode ('-', n4, n5 );
	BinaryNode *n7 = new BinaryNode ('+', n3, n6 );
	tree2.setRoot(n7);
	printf(" \n 계산 결과 = %d\n",tree2.evaluate());


	BinaryTree tree3;
	BinaryNode *m4 = new BinaryNode ( 200, NULL, NULL );
	BinaryNode *m5 = new BinaryNode ( 500, NULL, NULL );
	BinaryNode *m3 = new BinaryNode ( 100, m4, m5 );
	BinaryNode *m2 = new BinaryNode (  50, NULL, NULL );
	BinaryNode *m1 = new BinaryNode (   0, m2, m3 );
	tree3.setRoot(m1);
	printf(" 디렉토리 용량 계산 결과 = %d KB\n",tree3.calcSize());
	
	return 0;
}

