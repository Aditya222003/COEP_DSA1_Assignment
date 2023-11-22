#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef node* list;

void init(list *l){
     *l = NULL;
     return;
}
//1 -> 1
void append(list *l,int data){
     node* nn = (node*) malloc (sizeof(node));
     nn -> data = data;
     nn -> next = NULL;

     node* head = *l;

     if(!nn){
         return;
     }

     if(*l == NULL){
        *l = nn;
         nn -> next = nn;
        return;
     }

     else{
        node* temp = *l;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = nn;
        nn -> next = head;
        return;
             
             }
             

}

    void display(list l){
            node* disp = l;
            node* head = l;
            if(!disp){
                printf("Empty List");
                    return;
            }
                printf("\n");
            
          do{
                printf("%d\t",disp -> data);
                disp = disp -> next;
            }
            while(disp != head);
                printf("\n");

            return;
    }

    void deleteNode(list *l1){
        node *temp = *l1;
        node* delnode = temp;

        if(!(*l1))
        return ;
// 1 2 3 4 5
        else if(temp -> next == temp){
                free(delnode);
                *l1 = NULL;
        }
        else{
             node* targetNode = delnode -> next;
             node* temperary = targetNode;
           

             while(temperary -> next != delnode){
                temperary = temperary -> next;
             }   
             temperary -> next = targetNode;

              delnode -> next = NULL;
             free(delnode);
            (*l1) = targetNode;
             return ;
        }
    }

    void insertAtPosition(list *l,int pos,int data){
            node* newnode = (node*)malloc(sizeof(node));
            if(!newnode)
            return ;

            newnode -> data = data;
            newnode -> next = NULL;

            if(!*l && pos == 1){
                *l = newnode;
                newnode -> next = newnode;
                return ;
            }
            else if(!(*l)){
                return ;
            }
            else{
                node* temp = *l;
                node* head = temp;
                int ct = 1 ;
                while( ct != pos-1){
                    if(temp -> next == head ){
                        printf("Behenchod neet enter kr");
                        return;
                    }
                    temp = temp -> next;
                    ct++;
                }
                node* ab = temp -> next;
                temp -> next = newnode ;
                newnode -> next = ab;
            }

    }
     int main(){
        list l1;

        init(&l1);
        append(&l1,10);
        append(&l1,20);
        append(&l1,30);
        append(&l1,40);
        display(l1);
        // deleteNode(&l1);
        // display(l1);
    insertAtPosition(&l1,10,5);
        display(l1);
        return 0;

     }


