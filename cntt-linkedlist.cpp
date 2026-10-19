#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node {
    int data ; 
    int key ;
    struct node *next ; 
};

struct node *head = NULL ; 
struct node *current = NULL ; 

void indsach(){

    struct node *ptr = head ; 
    printf("\n[ ");

    // doan dau dsach 
    while( ptr != NULL){
        printf("(%d , %d)" , ptr->key , ptr->data);
        ptr = ptr->next ; 
    }

    printf(" ]"); 
}

// chen link o vtri dau tien
void nhapso(int key , int data){
    // tao mot lien ket 
    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->key = key ;
    link->data = data;

    // tro link toi first node cu 
    link->next = head ; 

    // tro link toi first node moi 
    head = link ; 

}

// xoa phan tu dau tien 
struct node* xoaptdau(){
    // luu tham chieu toi dau link 
    struct node *templink = head ; 

    // danh dau next toi first link la first 
    head = head->next; 

    // tra ve link bi xoa 
    return templink ; 
}

// kiem tra lisst ton tai hay kh 
bool ktra(){
    return head == NULL ;
}

int dodai(){
    int dodai = 0 ; 
    struct node *current ; 

    for( current = head ; current != NULL ; current = current -> next){
        dodai++;
    }

    return dodai;
}

//tim mot link voi key da cho 
struct node* timlink(int key){

    // bat dau tim tu firt link 
    struct node* current = head ; 

    // neu lisst rong 
    if(head == NULL){
        return NULL ; 
    }

    // duyet qua list
    while( current->key != key){

        // neu la last node
        if( current -> next == NULL){
            return NULL;
        }

        else {
            // di chuyen toi next link
            current = current->next;
        }
    }

     // neu tim thay du lieu 
     return current ; 
}

// xoa mot link voi key da cho 
struct node* xoakey(int key){
    
    // batdau voi fir link 
    struct node* current = head ;
    struct node* phiatruoc = NULL ; 

    // neu lisst rong 
    if( head == NULL) return NULL ; 

    // duyet qua lisst 
    while( current->key != key){

        // neu la last node 
        if(current->next == NULL){
            return NULL;
        }

        else {
            // luu tham chieu voi link dang co 
            phiatruoc = current ;
            // di chuyen toi next link 
            current = current -> next ; 
        }
    }

    // cap nhat link 
    if( current == head){
        // thay doi first de tro toi next link
        head = head -> next ; 
    }
    else {
        // bo qua link hien tai 
        phiatruoc->next = current->next ;
    }

    return current;
}

// ham sap xep  
void sort(){
    int i , j , k , tempKey , tempData ; 
    struct node *current ; 
    struct node *next ; 

    int size = dodai();
    k = size ; 

    for( i = 0 ; i < size - 1 ; i++ , k--){
        current = head ; 
        next = head -> next ; 

        for( j = 1 ; j < k ; j++){
            if( current->data > next->data){
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }

            current = current -> next ; 
            next = next->next ; 
        }
    }
}

// ham dao nguoc list
void daonguoc(struct node** head_def){
    struct node* prev = NULL ;
    struct node* current = *head_def ; 
    struct node* next ; 

    while ( current != NULL){
        next = current -> next ; 
        current->next = prev ; 
        prev = current ;
        current = next ; 
    }

    *head_def = prev ; 
}

int main() {
    nhapso(3,4);
    nhapso(6,8);
    nhapso(1,20); 

    indsach();

    while( !ktra() ){
        struct node *temp = xoaptdau();
        printf("\nGia tri bi xoa : (%d,%d)" , temp ->key , temp ->data);
    }

    indsach();
}