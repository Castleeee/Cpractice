#include "iostream"
#include "string"

using namespace std;
class Node { //单向节点
private :
    int value;
    Node *next,*pre;

public:
    Node(int value=0,Node *next=nullptr){
        this->value = value;
        this->next = next;

    }
    int GetValue(){//get 方法
        return this->value;
    }
    int SetValue(int &v){//set方法
        this->value=v;
        return 1;
    }
    Node* GetNext(){//拿到本节点的下一个节点
        return this->next;
    }
    void SetNext(Node *node){//设置本节点的下一个节点
        this->next=node;
    }
    Node* GetPer(){//拿到本节点的上一个节点
        return this->pre;
    }
    void SetPer(Node *node){//设置本节点的上一个节点
        this->pre=node;
    }

};

class doubleLiner{
private:
    Node *head,*tali,*current;
public:

};
int main(){
    cout<<"hello"<<endl;
    return 0;
}

