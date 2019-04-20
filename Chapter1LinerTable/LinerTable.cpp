/*include here*/
#include "iostream"
#include "string"
/*define here*/

using namespace std;
/*function&class*/

static int num=0;//表示这是创建的第几个node
class Liner {
private :
    string value;
    Liner *next;
public:
    string GetValue(){//get 方法
        return this->value;
    }
    int SetValue(string &v){//set方法
        this->value=v;
        return 1;
    }
    Liner GetNext(){
        if (this->next!= nullptr){
            return *this->next;//取值
        }
        else{
            cout<<"no next node"<<endl;
        }
    }

    Liner(string value="no first data set!",Liner *next=nullptr){
        this->value = value;
        this->next = next;
    }
};

//entry
int main() {
    cout << "hello world" << endl;
    Liner B("you succeed");
    Liner A("12345",&B);
    cout<<A.GetNext().GetValue()<<endl;

    return 0;
}
/*
created by a_little_rubbish
have a nice day : )
*/
