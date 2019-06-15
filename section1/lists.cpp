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
    if(i>=this->length||i<0){
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
int listInsert(int i,int e){
        //指定下标后面插入
    if(i>=this->length||i<0){
        cout<<"下标越界"<<endl;
        return 0;
        }
    for(int j=this->length;j>i+1;j--){//想在指定下标前面就把i+1改成i
        this->data[j]=this->data[j-1];
    }
    this->length++;
    this->data[i+1]=e;
        return 1;
}
int listPop(int i){
        //指定下标删除并返回
    if(i>=this->length||i<0){
        cout<<"下标越界"<<endl;
        return 0;
    }
    int e=this->data[i];
    for(int j=i;j<this->length-1;j++){
        this->data[j]=this->data[j+1];
    }
    this->length--;
    return e;
}
//综合应用题
// 1删除最小
int popMin(){
        int min=this->data[0];
        int index=0;
        for(int i=0;i<this->length;i++){
            if(min>=this->data[i]){
                min=this->data[i];
                index=i;
            }
        }
        this->data[index]=this->data[this->length-1];
        this->length--;
    return min;
    }
//2就地逆置
int Reverse(){
        for(int i=0;i<=(this->length-1)/2;i++){
            int temp;
            temp=this->data[i];
            this->data[i]=this->data[this->length-i-1];
            this->data[this->length-i-1]=temp;
        }
            return 1;
    }
//3去重
    int filter(int x){
        for(int i=0;i<this->length;i++){
            if(x==this->data[i]){
                this->listPop(i);
            }
        }
        return 1;
    }
//4区间删除
int intervalDel(int s,int t){
        if(s>=t||this->length<=0){
            throw "error";
        }
        for(int i=0;i<this->length;i++){
            if(this->data[i]>=s&&this->data[i]<=t){
                this->listPop(i);
                i--;
                cout<<"deling "<<data[i]<<" - "<<i<<endl;
            }
        }
        return 0;
}
////5 有序版
//int intervalDel2(int s,int t){
//    if(s>=t||this->length<=0){
//        throw "error";
//    }
//    int mins=0,maxs=0;
//    for(int i=0;i<this->length;i++){
//        if(this->data[i]>=s){
//            mins=i;
//            for (int j=i;j<=this->length;j++){
//                if (this->data[j]>=t){
//                    maxs=j;
//                    break;
//                }
//            }
//            break;
//        }
//    }
//    for(int i=mins;i<this->length;i++){
//        this->data[i]=this->data[i+maxs-mins];
//    }
//
//    return 0;
//}
//6有序表去重
int deWeighting(){
        for(int i=0;i<=this->length;i++){
            if(this->data[i]==this->data[i+1]){
                this->listPop(i+1);
            }

        }
        return 1;
    }
//合并
int merge(linerList *b){//传入个b
        linerList result=linerList(this->length+b->length) ;//结果数组
        int index=0;
        while(1){
            if(this->length==0) {
                for(int i=1;i<b->length;i++){
                    result.data[index+i]=b->data[i];
                }
                break;
            }
            if(b->length==0){
                for(int i=1;i<this->length;i++){
                    result.data[index+i]=this->data[i];
                }
                    break;

                }
            if(this->data[0]<=b->data[0]){
                result.data[index]=this->data[0];
                this->listPop(0);
                result.length++;
                this->length--;
            }
            else{
                result.data[index]=b->data[0];
                b->listPop(0);
                result.length++;
                b->length--;
            }
            index++;
        }
        return 1;
    };
};
//entry
int main() {
    cout << "hello world" << endl;
    linerList *l=new linerList(7);
    for (int i=0;i<5;i++){
        l->headInsert(i);
    }
    cout <<"Length:"<<l->Length()<<endl;
    cout <<"Empty:"<<l->Empty()<<endl;
    l->PrintList();
    l->tailInsert(100);
    l->tailInsert(1156);
    l->tailInsert(1234);
    cout<<l->listPop(4)<<endl;
    cout<<l->listInsert(4,6);
    l->PrintList();
    cout<<l->listInsert(2,6);
    l->Reverse();
    l->filter(6);
    l->PrintList();
    l->intervalDel(1,100);
    l->PrintList();
    cout <<l->Destory()<<endl;
    return 0;
}
/*
created by a_little_rubbish
have a nice day : )
*/
