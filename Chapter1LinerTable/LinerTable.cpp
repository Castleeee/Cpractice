/*include here*/
#include "iostream"
#include "string"
/*define here*/

using namespace std;
/*function&class*/

//
//这是单链表
//

static int num=0;//表示这是创建的第几个node
class Node { //单向节点
private :
    string value;
    Node *next;
public:
    Node(string value="no first data set!",Node *next=nullptr){
        this->value = value;
        this->next = next;
        num++;
    }
    string GetValue(){//get 方法
        return this->value;
    }
    int SetValue(string &v){//set方法
        this->value=v;
        return 1;
    }
    Node* GetNext(){//拿到本节点的下一个节点
        return this->next;
//        if (this->next!= nullptr){
//            return *this->next;//取值
//        }
//        else{
//            cout<<"no next node"<<endl;
//
//        }
    }
    Node SetNext(Node *node){//设置本节点的下一个节点
        this->next=node;
    }

};

class Liner{
private:
    Node *head,*tali,*current;
    int position=0;//这干嘛用的???
public:
    Liner(Node *node){
        this->head=node;
        this->tali=node;
        this->current=node;
    }
    void append(Node *node ){//单链表追加
        this->tali->SetNext(node);
        this->tali=node;
    }
    void headAppend(Node *node ){//头插法
        node->SetNext(this->head);
        this->head=node;
    }
    void traversing(){
        while(this->current->GetNext()!= nullptr){
            cout<<this->current->GetValue()<<endl;
            this->current=this->current->GetNext();//不确定这一句
        }
    }//遍历
};
//entry
int main() {
    //cout << "hello world" << endl;
    Node C("it is tali node");
    Node B("you succeed");
    Node A("12345");
    //cout<<A.GetNext()->GetValue()<<endl;


    Liner linerList(&A);
    linerList.append(&B);
    linerList.headAppend(&C);
    linerList.traversing();
    cout<<A.GetValue();

    return 0;

}

//
//
//

/*
created by a_little_rubbish
have a nice day : )
*/
