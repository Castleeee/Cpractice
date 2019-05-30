#include "iostream"
#include "string"

using namespace std;
class Node {
private:
    int value;
    Node *next;
public:
    Node(int value=0,Node *next= nullptr){
        this->next=next;
        this->value=value;
    }
    int GetValue(){
        return this->value;
    }
    void SetValue(int value){
        this->value=value;
    }
    Node* GetNext(){
        return this->next;
    }
    void SetNext(Node *next){
        this->next=next;
    }
};

class LinerTable{
private:
public:
    Node *head;
    Node *tail;
    Node *temp;
    LinerTable(Node *h){
        this->head=h;
        this->tail=h;
        this->temp=h;
    }
    void Append(Node *n){//尾插法
        this->tail->SetNext(n);
        this->tail=n;
    }
    void HAppend(Node *n){//Head append
        n->SetNext(head);
        this->head=n;
    }
    void Insert(Node *n,int p){
        while (p > 0){//p>0后插p-1>0是前插(自己试试吧
            this->temp=this->temp->GetNext();
            p--;
        }
        n->SetNext(this->temp->GetNext());
        this->temp->SetNext(n);
        this->temp=this->head;
    }//指定位置插
    void Hdel(){
        this->temp=this->head->GetNext();
        this->head=this->temp;
    }//头尾删除差不多，写一个
    void Del(int p){//指定位置删除
        while (p>0){
            this->temp=this->temp->GetNext();
            p--;
        }
        this->temp->SetNext(this->temp->GetNext()->GetNext());
    }
    void traversing(){
        while(this->temp!= nullptr){
            cout<<"node:"<<this->temp->GetValue()<<endl;
            this->temp=this->temp->GetNext();
        }
        cout<<"node:"<<this->temp->GetValue()<<endl;
    }
//    ~LinerTable(){
//
//    }
};
int main(){
    cout<<"start:------------------"<<endl;
    Node *a=new Node(5);

    return 0;
}

