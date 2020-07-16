#include<iostream>

class Node{
    public:
        int value;
        Node* lchild;
        Node* rchild;
       
};


Node* insert(Node* root , int value){
    if(root == NULL){
        Node* temp = new Node();
        temp->value = value;
        temp->lchild = NULL;
        temp->rchild = NULL;
        return temp;
    }
    if(value < root->value){
        root->lchild = insert(root->lchild , value);
    }else if(value > root->value){
        root->rchild = insert(root->rchild , value);
    }else{
        std::cout << "Value is repeated and cannot be inserted ." << std::endl;
    }
    return root;
}

int Height(Node* root){
    int x , y ;
    if(root == NULL) return 0;
    x = Height(root->lchild) + 1;
    y = Height(root->rchild ) + 1;
    return x > y ? x : y;
}

Node* InOrderPredecessor(Node* node){
    while(node && node->rchild){
        node = node->rchild;
    }
    return node;
}

Node* InOrderSuccessor(Node* node){
    while(node && node->lchild){
        node = node->lchild;
    }
    return node;
} 



Node* Delete(Node* p, int value){  //value = Value to delete
    Node* q = new Node();
    if (p == NULL)  
        return NULL;
    
    if(p->lchild == NULL && p->rchild == NULL){

        p = NULL;
        return NULL;
    }

    if(value < p->value){
        p->lchild = Delete(p->lchild , value);
    }else if(value > p->value){
        p->rchild = Delete(p->rchild , value);
    }else{
        if(Height(p->lchild) > Height(p->rchild)){
            q=InOrderPredecessor(p->lchild);
            p->value = q->value;
            p->lchild = Delete(p->lchild , q->value);
        }
        else{
            q=InOrderSuccessor(p->rchild);
            p->value = q->value;
            p->rchild = Delete(p->rchild , q->value);
        }
    }
    return p;
}



void InOrder(Node* root){
    if(root != NULL){
        InOrder(root->lchild);
        std::cout<< root->value << std::endl;
        InOrder(root->rchild); 

    }
}

int main(){
    Node* root = NULL;
    root = insert(root , 10);
    insert(root , 5);
    insert(root , 20);
    insert(root , 8);
    insert(root , 30);
    Delete(root , 20);
    InOrder(root);
    std::cout <<"Height :: " << Height(root) << std::endl;
    return 0;
}
