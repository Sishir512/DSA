#include<iostream>

class Node{
    public:
        int value;
        int height;
        Node* lchild;
        Node*rchild;
};

Node* Root = NULL;

int Height(Node* root){
    int x , y ;
    if(root == NULL) return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    return x > y ? x + 1 : y + 1;
}

int BalanceFactor(Node* root){
    
    return Height(root->lchild) - Height(root->rchild);
}

Node* LLRotation(Node* p){
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    pl->height = Height(pl);
    //plr->height = Height(plr);
    p->height = Height(p);
    if(p == Root)   Root = pl;
    return pl;
}

Node* RRRotation(Node* p){
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = Height(p);
    pr->height = Height(p);

    if(p == Root)
        Root = pr;
    return pr;
}

Node* RLRotation(Node* p){
    Node* pr = p->rchild; 
    Node* prl = pr->lchild ;
    pr->lchild = prl->lchild;
    p->rchild = prl->lchild;
    
    prl->lchild = p;
    prl->rchild = pr;

    pr->height = Height(pr);
    prl->height = Height(prl);
    p->height = Height(p);

    if(p == Root)
        Root = prl;
    return prl;
    

}

Node* LRRotation(Node* p){
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = Height(pl);
    plr->height = Height(plr);
    p->height = Height(p);

    if(p == Root)
        Root = plr;

    return plr;


}

Node* insert(Node* root , int value){
    if(root == NULL){
        Node* temp = new Node();
        temp->value = value;
        temp->lchild = NULL;
        temp->rchild = NULL;
        temp->height = 0;
        return temp;
    }
    if(value < root->value){
        root->lchild = insert(root->lchild , value);
    }else if(value > root->value){
        root->rchild = insert(root->rchild , value);
    }else{
        std::cout << "Value is repeated and cannot be inserted ." << std::endl;
    }
    root->height = Height(root);
    std::cout<<"Balance Factor " << BalanceFactor(root) << std::endl;
    if(BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == 1){
        return LLRotation(root);
    } else if(BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == -1){
        return LRRotation(root);
    } else if(BalanceFactor(root) == -2 && BalanceFactor(root->rchild) == -1){
        return RRRotation(root);
    }else if(BalanceFactor(root) == -2 && BalanceFactor(root->rchild) == 1){
        return RLRotation(root);
    }else{
        std::cout<<"";
    }
    
    return root;
    
}



int main(){
    Root = insert(Root , 10);
    insert(Root , 5);
    insert(Root , 2);
    std::cout<<"Root" << Root->value;
    return 0;
}