/*include here*/
#include "iostream"
/*define here*/

using namespace std;
/*function&class*/
class linerList{
    int maxsize=0;
//    int (*data)[];
    int *data;
    int length=0;
public:
    linerList(int n){
        this->maxsize=n;
        this->data=new int[this->maxsize];


    }
    ~linerList(){
        delete[] this->data;
    }
    int Length(){
    return length;
    }
void PrintList(){
        for (int i=0;i<this->length;i++){
            cout<<this->data[i]<<" ";
        }

    cout<<"遍历完毕"<<endl;
    }
int Empty(){
        if(this->length==0){
            return 1;
        } else{
            return 0;
        }
    }
int Destory(){
    delete[] this->data;
    return 1;
    }
int headInsert(int e){
        if (this->length>=this->maxsize){//超长就插入不成功
            return 0;
        }
        if (this->length!=0){
            for (int i=this->length;i>0;i--){
                this->data[i] = this->data[i-1];
            }
        }
        this->data[0]=e;
        this->length++;

        return 1;
    }
int tailInsert(int e){
        if(this->length>=this->maxsize){//如果满了，执行扩展逻辑
            this->maxsize=2*this->maxsize;
            int *temp=new int[this->maxsize];
            for (int i=0;i<this->length;i++){
                temp[i]=this->data[i];
            }
            delete [] this->data;
            this->data=temp;
            //return 0;//或者直接return 0不成功
        }
        this->data[this->length]=e;
        this->length++;
        return 1;
    }
int getItem(int i){//位查找
    if(i>=this->length){
        cout<<"下标越界"<<endl;
        return 0;
    }
    return this->data[i];
    }
void getElem(int e){
        int f=0;
        for(int i=0;i<this->length;i++){
            if (this->data[i]==e){
                cout<<"第"<<i<<"个元素为"<<e<<endl;
                f=1;
            }
        }
        if (f==0){
            cout<<"没找到！"<<endl;
        }
    }
int listInsert(int i){
        //指定位插入
        return 0;
}
int listPop(int i){
        //指定位删除并返回
    return 0;
    }
};

//entry
int main() {
    cout << "hello world" << endl;
    linerList *l=new linerList(5);
    for (int i=0;i<5;i++){
        l->headInsert(i);
    }
    cout <<"Length:"<<l->Length()<<endl;
    cout <<"Empty:"<<l->Empty()<<endl;
    l->PrintList();
    l->tailInsert(100);
    l->tailInsert(1156);
    l->PrintList();
    cout <<l->Destory()<<endl;
    return 0;
}
/*
created by a_little_rubbish
have a nice day : )
*/
