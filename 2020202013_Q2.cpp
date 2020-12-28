#include<bits/stdc++.h>
using namespace std;
template<class P,class Q>
class Node{
public:
    P key;
    Q value;
    Node<P,Q>*next;

    Node(P key,Q val){


        this->key=key;
        value=val;
        next=NULL ;

    }
};

template<class P,class Q>
class map_u{
    int cs,ts;

    Node<P,Q>** t; //pointer to an array of pointers

    int h_function(P key){
        int ind=0;
        int p=1;
        for(int s=0;s<key.length();s++){
            ind=ind+(key[s]*p)%ts;
            ind=ind%ts;
            p=(p*29)%ts;
        }
        return ind;
    }
public:
    map_u(int ts1=1000){
        ts=ts1;
        t = new Node<P,Q>*[ts];
        cs=0;
        for(int i=0;i<ts;i++){
            t[i]=NULL ;
        }
    }
    void _insert(Q v,P k,int idx){
        Node<P,Q>*n=new Node<P,Q>(k,v);
        n->next=t[idx];
        t[idx]=n;
        cs++;
    }
    void insert(P k,Q v){

        int index=h_function(k);
        _insert(v,k,index);

    }
    void print(){

        for(int i=0;i<ts;i++){
            cout<<"index "<<i<<"->";
            Node<P,Q>*temp=t[i];
            while(temp!=NULL){

                cout<<temp->key<<"--->";
                temp=temp->next;

            }
            cout<<endl;
        }
    }
    string find(P key){
        int idx=h_function(key);
        Node<P,Q>*temp=t[idx];
        while(temp!=NULL ){
            if(temp->key==key){
                return "true";
            }
            temp=temp->next;
        }
        return "false";
    }
    Q* search(P key){
        int idx=h_function(key);
        Node<P,Q>*temp=t[idx];
        while(temp!=NULL ){
            if(temp->key==key){
                return &temp->value;
            }
            temp=temp->next;
        }
        return NULL ;
    }
  void _delete(Node<P,Q>*t){
        delete t;

    }

    void remove(P k){
        int j=h_function(k);
        if(search(k)==NULL)return;
        Node<P,Q>*temp=t[j];
        if(temp->key==k){
            t[j]=temp->next;
            temp->next=NULL ;
            _delete(temp);
            cs--;
            return;
        }
        while(temp!=NULL ){
            if(temp->next->key==k){
                Node<P,Q>*ptr=temp->next;
                temp->next=ptr->next;
                ptr->next=NULL ;
                delete ptr;
                return;
            }
            temp=temp->next;
        }
    }
    Q& search_insert(P k,Q x){
        insert(k,x);
        Q * f1=search(k);
        return *f1;
    }

    Q& operator[](P key){
        Q * f=search(key);
        if(f==NULL ){
            Q x;
            return search_insert(key,x);

        }
        return *f;
    }
};



int main(){
map_u<string,string>cricket;
    cricket.insert("sachin","15,000");
    cricket.insert("pujara","1,000");
    cricket.insert("kohli","10,000");
    cout<<cricket.find("z")<<endl;
    cricket.remove("kohli");
    cout<<cricket["sachin"]<<endl;
    cout<<cricket["kohli"]<<endl;

   // cricket.print();
    return 0;
    
    return 0;
}
