#include <iostream>
#include <string>
using namespace std;

struct TNode{
    char data;
    TNode *LTree, *RTree;
};

TNode *TreeBuild(string First,string Mid){
    if(First.length() == 0)
        return nullptr;

    TNode *tmp =new TNode;
    tmp->data =First[0];

    if(First.length() == 1){
        tmp->LTree = nullptr;
        tmp->RTree = nullptr;
        return tmp;
    }

    int pos = Mid.find(First[0]);
    tmp->LTree = TreeBuild(First.substr(1,pos),Mid.substr(0,pos));
    tmp->RTree = TreeBuild(First.substr(pos+1,First.length()-pos-1),Mid.substr(pos+1,First.length()-pos-1));
    return tmp;
}

void Last(TNode *root){
    if(root->LTree != nullptr)
        Last(root->LTree);
    if(root->RTree != nullptr)
        Last(root->RTree);
    cout << root->data;
}




int main(){
    string First,Mid;
    getline(cin,First);
    getline(cin,Mid);

    TNode *root = TreeBuild(First,Mid);

    Last(root);

    return 0;
}


