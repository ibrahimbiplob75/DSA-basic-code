#include <iostream>
using namespace std;
char choice;
int value;
int position;


class Node{
public:
    int value;
    Node* next;
    Node(int val){
        value=val;
        next=NULL;
    }
};

void singleLinkList();
void doublyLinkList();
void circularLinkList();
int countSingleList(Node *&head);
void insertIntoHeadSingle(Node *&head,int value);

void insertIntoTailSingle(Node *&head, int value);

int display(Node *head);

void insertIntoSPsingle(Node *&head, int position, int value);

int main() {

    cout<<"Choice to operation on below Linked list"<<endl;
    cout<<"1-> single Linked list"<<endl;
    cout<<"2-> Doubly Linked list"<<endl;
    cout<<"3-> Circular Linked list"<<endl;
    cout<<"Make your choice -> ";
    cin>>choice;
    if(choice=='1'){
      singleLinkList();
    }
    else if(choice=='2'){
        doublyLinkList();
    }
    else if(choice=='3'){
        circularLinkList();
    }
    else{
        cout<<"You have chose wrong decision"<<endl;
        main();
    }

}






void circularLinkList() {
    cout<<"circular Link list is updating ....."<<endl;
}

void doublyLinkList() {
    cout<<"Doubly Link list is updating ......."<<endl;
}







void singleLinkList() {
    Node* head=NULL;
    cout<<"Choice operation from the (Single link list)"<<endl;
    cout<<"1-> Count the length of the link list"<<endl;
    cout<<"2-> Insert into Head of the link list"<<endl;
    cout<<"3-> Insert into Tail of the link list"<<endl;
    cout<<"4-> Insert at specific position of the link list"<<endl;
    cout<<"5-> Insert after specific value of the link list"<<endl;
    cout<<"6-> Search a value in the (unique) link list"<<endl;
    cout<<"0->Exits From the single Link List"<<endl;

    cout << "Enter a choice =";
    cin>>choice;
    while(choice!=0){
        switch(choice){
            case '1':{
                int length=countSingleList(head);
                if(length>=1)cout<<"Length of list ->"<<length<<endl;
                break;
            }
            case '2':{
                cout << "Enter a value ->" ;
                cin >> value;
                insertIntoHeadSingle(head,value);
                break;
            }

            case '3': {
                cout << "Enter a value ->" ;
                cin >> value;
                insertIntoTailSingle(head, value);
                break;
            }
            case '4': {
                cout << "Enter inserted position =>" ;
                cin >> position;
                cout << "Enter a value ->" ;
                cin >> value;
                insertIntoSPsingle(head,position, value);
                break;
            }

            default:{
                display(head);
                main();
                break;
            }
        }

        cout << "Enter next choice =>" ;
        cin >> choice;
    }


}

void insertIntoSPsingle(Node *&head, int position, int value) {
    Node* newnode=new Node(value);
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    newnode->next=temp->next;
    temp->next=newnode;


}


int display(Node *head) {
    cout<<"single Link List -> ";
    while(head!=NULL){

        cout<<head->value;
        if(head->next!=NULL){
            cout<<"->";
        }
        head=head->next;

    }
    cout<<endl<<endl<<endl;
    return 0;

}

void insertIntoTailSingle(Node *&head, int value) {
        Node* newnode=new Node(value);
        Node* temp=head;
        if(temp==NULL){
            head=newnode;
        }
        
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
}

void insertIntoHeadSingle(Node* &head,int value) {
    Node* newnode=new Node(value);

    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

int countSingleList(Node* &head) {
    int count=0;
    Node* temp=head;
    if(temp==NULL){
        cout<<"No value into the list"<<endl;
    }

    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
