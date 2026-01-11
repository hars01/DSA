#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;

    ListNode(int val){
        value=val;
        next=NULL;
    }
};

ListNode* create(){
      int n;
      cin>>n;

      ListNode* head=NULL;
      ListNode* tail=NULL;

      for(int i=0; i<n; i++){
          int val;
          cin>>val;
          
          ListNode* temp=new ListNode(val);
          if(head==NULL){
            head=temp;
            tail=temp;
          }
          else{
            tail->next=temp;
            tail=temp;
          }
      }
      return head;
}

ListNode* createWithStringSpaceSeparated(){ 
      string n;
      getline(cin, n);
       
      stringstream ss(n);

      int num;
      ListNode* head=NULL;
      ListNode* tail=NULL;

      while(ss>>num){
          ListNode* temp=new ListNode(num);
          if(head==NULL){
            head=temp;
            tail=temp;
          }
          else{
            tail->next=temp;
            tail=temp;
          }
      }
      return head;
}

ListNode* createWithStringWithComma(){ 
      string n;
      getline(cin, n);
       
      stringstream ss(n);

      string tempNum;
      ListNode* head=NULL;
      ListNode* tail=NULL;

      while(getline(ss, tempNum, ',')){
          int num=stoi(tempNum);
          ListNode* temp=new ListNode(num);
          if(head==NULL){
            head=temp;
            tail=temp;
          }
          else{
            tail->next=temp;
            tail=temp;
          }
      }
      return head;
}

void print(ListNode* head){
    ListNode* temp=head;

    while(temp->next!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }

    cout<<temp->value;
}

int main(){
    ListNode* p=create();
    // ListNode* q=createWithStringWithComma();
    // ListNode* r=createWithStringSpaceSeparated();


    print(p);
    return 0;

}