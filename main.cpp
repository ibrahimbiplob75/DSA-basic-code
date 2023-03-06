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
struct TEST{
    int array[100];
};

void singleLinkList();
void doublyLinkList();
void circularLinkList();
int countSingleList(Node *&head);
void insertIntoHeadSingle(Node *&head,int value);

void insertIntoTailSingle(Node *&head, int value);

int display(Node *head);

void insertIntoSPsingle(Node *&head, int position, int value);

void insert_after_SpecificValue_single(Node *&head, int position, int value);

int searchInUniquesingle(Node *&head, int value);

TEST searchInDuplicatesingle(Node *&head, int value);

void insert_after_SpecificValue_duplicateList(Node *&head, int position, int value);

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
    cout<<endl<<endl<<"Choice operation from the (Single link list)"<<endl;
    cout<<"1-> Count the length of the link list"<<endl;
    cout<<"2-> Insert into Head of the link list"<<endl;
    cout<<"3-> Insert into Tail of the link list"<<endl;
    cout<<"4-> Insert at specific position of the link list"<<endl;
    cout<<"5-> Search a value in the (unique) link list"<<endl;
    cout<<"6-> Search a value in the (duplicate) link list"<<endl;
    cout<<"7-> Insert after specific value of the (unique) list"<<endl;
    cout<<"8-> Insert after specific value of the (duplicate) list"<<endl;
    cout<<"9-> Print linked list reverse(Non-recursive)"<<endl;
    cout<<"10->Mid point linked list (New Concept)"<<endl;
    cout<<"11->Insert Circle into the link list"<<endl;
    cout<<"12->Check  Circle into the link list"<<endl;
    cout<<"13->Remove Circle from the link list"<<endl;
    cout<<"14->Delete From the Head of linked list"<<endl;
    cout<<"15->Delete From the tail of linked list"<<endl;
    cout<<"16->Delete From the specific position of linked list"<<endl;
    cout<<"17->Delete after a specific value of linked list"<<endl;
    cout<<"0-> Exits From the single Link List"<<endl;

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
            case '5': {
                cout << "Enter searched value =>" ;
                cin >> value;
                position=searchInUniquesingle(head,value);
                if(position==1){
                    cout<<"There has no value in the list"<<endl;
                }
                if(position>1){
                    cout<<"Your value at position ->"<<position<<endl;
                }
                break;
            }
            case '6': {
                cout << "Enter searched value ->" ;
                cin >> value;
                TEST T;
                T=searchInDuplicatesingle(head,value);
                if(T.array[0]==1){
                    cout<<"Value didn't find in Link List"<<endl;
                }

                else{
                    int size=T.array[0];

                    for(int i=1;i<size;i++){
                        cout<<T.array[i];
                        if(i<size-1){
                            cout<<"->";
                        }
                    }
                    cout<<endl;
                }
                break;
            }

            case '7': {
                cout << "Enter a value after you want to insert =>" ;
                cin >> position;
                cout << "Enter a value ->" ;
                cin >> value;
                insert_after_SpecificValue_single(head,position, value);
                break;
            }
            case '8': {
                cout << "Enter a value after you want to insert =>" ;
                cin >> position;
                cout << "Enter a value ->" ;
                cin >> value;
                insert_after_SpecificValue_duplicateList(head,position, value);
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

void insert_after_SpecificValue_duplicateList(Node *&head, int position, int value) {
    Node *newnode = new Node(value);
    Node *temp = head;
    TEST T;
    T = searchInDuplicatesingle(head, position);

            int size = T.array[0];

            for (int i = 1; i < size; i++) {
                insertIntoSPsingle(head, T.array[i]+1, value);
            }
            //temp = temp->next;

}
TEST searchInDuplicatesingle(Node *&head, int value) {
    Node* temp=head;
    TEST T;
    int key=1,count=1;
    while(temp!=NULL){
        if(temp->value==value){

                T.array[key]=count;
                key++;
            }
            count++;
            temp=temp->next;
    }
    T.array[0]=key;
    return T;

}

int searchInUniquesingle(Node *&head, int value) {
    Node* temp=head;
    int count=1;

    while(temp->value!=value){
        temp=temp->next;
        count++;
    }
    return count;
}

void insert_after_SpecificValue_single(Node *&head, int position, int value) {
    Node* newnode=new Node(value);
    position=searchInUniquesingle(head,position);
    insertIntoSPsingle(head,position+1,value);


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
            return;
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
