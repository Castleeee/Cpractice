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
    int value;
    Node *next;
public:
    Node(int value=0,Node *next=nullptr){
        this->value = value;
        this->next = next;
        num++;
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

};

class Liner{
private:
    Node *tali,*current,*temp;
public:
    Node *head;
    Liner(Node *node){
        this->head=node;
        this->tali=node;
        this->current=node;

    }
    void append(Node *node ){//单链表尾插法
        this->tali->SetNext(node);
        this->tali=node;
    }
    void headAppend(Node *node ){//头插法
        node->SetNext(this->head);
        this->head=node;
    }
    int len(){
        int length=0;
        this->current=this->head;
        while(this->current!=nullptr){
            length++;
            this->current=this->current->GetNext();
        }
        return length;
    }
    void del(int index=0){
        this->current=this->head;//头归位
        for(int i=0;i<index-1;i++){//循环到index前一个那里
            this->current=this->current->GetNext();
        }
        this->current->SetNext(this->current->GetNext()->GetNext());
    }
    void insert(Node *node,int index=0){
        this->current=this->head;//头归位
        for(int i=0;i<index-1;i++){//循环到index前一个那里
            this->current=this->current->GetNext();
        }
        node->SetNext(this->current->GetNext());
        this->current->SetNext(node);
    }
    void traversing(){//遍历
        this->current=this->head;
        while(this->current!= nullptr){
            cout<<this->current->GetValue()<<endl;
            this->current=this->current->GetNext();//不确定这一句
        }
    }
    void deduplicate(){//去重
        int flag=0;
        this->temp=new Node(0,head);//声明一个新节点，让他指向头节点，temp指针总是指向当前节点的上一个
        this->current=head;//current归位头
        Node *current_after;//声明一个新节点指针，指向当前节点的下一个
        while (this->current!= nullptr){//一直循环下去，直到尾节点
            current_after=current->GetNext();//每次current移动after归到current后面
            while(current_after!= nullptr){//这个节点指针，不断遍历后面的节点
                if (this->current->GetValue()==current_after->GetValue()){//值相同
                    this->temp->SetNext(this->current->GetNext());//current的上一个节点（temp指向的那个）指向current的下一个节点
                    flag=1;
                    cout<<this->current->GetValue()<<"去重"<<endl;
                    break;//更改之后，不再循环
                }
                current_after=current_after->GetNext();//后面节点的指针指向current的下一个
            }
            this->current=this->current->GetNext();//current向后移一个
            if (flag==0) {
                this->temp = this->temp->GetNext();//如果删除过节点temp向后移一个
                flag=0;
            }
        }
    }
    ~Liner(){
        this->tali=nullptr;
        this->temp= nullptr;
        this->current=this->head->GetNext();
        while(this->head!= nullptr){
            if(this->head->GetNext()!= nullptr){
                this->current=this->head->GetNext();
                cout<<"sss"<<endl;
            }else{
                break;
            }
            cout<<"deleting :"<<this->head->GetValue()<<endl;
            delete this->head;
            this->head=this->current;
        }

    }
};
Liner merge(Liner a,Liner b){
    Liner C(new Node());
    Node *aP=a.head,*bP=b.head,*cP=C.head;//a,b,c的当前节点的指针
    while(aP!= nullptr&&bP!= nullptr){//a，b的指针都不为空的时候就循环
        if (aP->GetValue()<=bP->GetValue()){//a当前节点和b当前节点值哪个小
            cP->SetNext(aP);//a小就把a链接到c后面
            aP=aP->GetNext();//a指针往后一个
        }else{
            cP->SetNext(bP);//b小就把b链接到c后面
            bP=bP->GetNext();//b指针往后一个
        }
        cP=cP->GetNext();//因为增加了节点，C也往后移一个
    }
    if (aP == nullptr){//如果是a指针空了
        cP->SetNext(bP);//把b后面的连C上
    }else{//要不然就是b空了
        cP->SetNext(aP);//把a后面的连C上
    }

    return C;
}
//entry
int main() {
    //cout << "hello world" << endl;
//    Node C("it is tali node");
//    Node B("12345");
//    Node A("12345");
//    Node A2("12345");
//    Node A3("12345");
//    Node A1("12345");


    //cout<<A.GetNext()->GetValue()<<endl;


//    Liner linerList(&A);
//    linerList.append(&B);
//    linerList.headAppend(&C);
//    linerList.headAppend(&A2);
//    linerList.append(&A1);
//    linerList.append(&A3);
//    linerList.traversing();
//    cout<<endl;
//    linerList.deduplicate();
//    linerList.traversing();
    Liner intLiner(new Node(0));
    for(int i=1;i<=10;i+=2){
        intLiner.append(new Node(i));
    }
    Liner intLiner2(new Node(0));
    intLiner2.append(new Node(4));
    intLiner2.append(new Node(5));
    intLiner2.append(new Node(8));
    intLiner.traversing();
    intLiner2.traversing();
    cout<<""<<endl;
    Liner mergeResult=merge(intLiner,intLiner2);
    mergeResult.traversing();
    cout<<"---------------------"<<endl;
    Liner intLiner3(new Node(0));
    for (int i =0;i<=10;i++){
        intLiner3.append(new Node(i));
    }
    for (int i =0;i<=10;i++){
        intLiner3.append(new Node(i));
    }
    intLiner3.deduplicate();
    intLiner3.insert(new Node(1234321),5);
    intLiner3.del(10);
    cout<<intLiner3.len()<<endl;
    intLiner3.traversing();

    Liner *intLiner4=new Liner (new Node(0));
    for(int i=1;i<=10;i+=2){
        intLiner4->append(new Node(i));
    }
    intLiner4->traversing();
    delete intLiner4;
    return 0;

}

//
//
//

/*
created by a_little_rubbish
have a nice day : )
*/
