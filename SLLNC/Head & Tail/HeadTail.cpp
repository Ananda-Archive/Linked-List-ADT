/*
	Nama			: Ananda Prabu Tritya Vijaya
	NIM				: 24060117130048
	Kelas 			: B
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

typedef struct TNode{
	int data;
	TNode *next;
}TNode;

TNode *head;
TNode *tail;

int isEmpty(){
	if(head == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void insertDepan(int databaru){
	TNode *baru;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	tail = head;
	if(isEmpty()){
		tail = baru;
		head = tail;
		tail->next = NULL;
	}
	else{
		baru->next = head;
		head = baru;
		while(tail->next!=NULL){
			tail=tail->next;
		}
	}
}
void insertdiantara(int databaru, int node_kanan, int node_kiri){
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	int flag=0;
	bantu = head;
	if(isEmpty()){
		printf("Invalid!");
	}
	else{
		while(bantu->next != NULL){
			if(bantu->data == node_kiri && bantu->next->data == node_kanan){
				baru->next = bantu->next;
				bantu->next = baru;
				flag=1;
			}
			else{
				bantu = bantu->next;
			}
		}
	}
	if(flag==0){
		printf("Invalid!");
	}
}
void insertBelakang(int databaru){
	TNode *baru;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	tail = head;
	if(isEmpty()){
		tail = baru;
		head = tail;
		tail->next = NULL;
	}
	else{
		while(tail->next!=NULL){
			tail=tail->next;
		}
		baru->next = tail->next;
		tail->next = baru;
		tail = baru;
	}
}
void insertTengah(int databaru){
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	bantu = head;
	int count=0;
	int cari=1;
	if(isEmpty()){
		insertDepan(databaru);
	}
	else{
		while(bantu!=NULL){
			count++;
			bantu=bantu->next;
		}
		bantu = head;
		if(count==1){
			insertBelakang(databaru);
		}
		else{
			count = count/2;
			while(cari!=count){
				bantu=bantu->next;
				cari++;
			}
			baru->next=bantu->next;
			bantu->next=baru;
		}
	}
}
void hapusDepan(){
	TNode *hapus;
	int d;
	if(!isEmpty()){
		if(head!=tail){
			hapus = head;
			d = hapus->data;
			head = head->next;
			delete hapus;
		}
		else{
			d = tail->data;
			head = NULL;
			tail = NULL;
		}
		printf("%d terhapus\n",d);
	}
	else{
		printf("Data masih kosong\n");	
	}
}
void hapusdiantara(int node_kiri, int node_kanan){
	TNode *hapus, *bantu;
	int d;
	bantu = head;
	int count;
	int flag = 0;
	if(!isEmpty()){
		while(bantu!=NULL){
			count++;
			bantu=bantu->next;
		}
		if(count<=2){
			printf("Invalid1");
		}
		else{
			bantu=head;
			while(bantu->next!=NULL){
				if(bantu->data == node_kiri && bantu->next->next->data == node_kanan){
					hapus = bantu->next;
					d = hapus->data;
					bantu->next = bantu->next->next;
					d=hapus->data;
					printf("%d terhapus",d);
					delete hapus;
					flag = 1;
					break;
				}
				else{
					bantu = bantu->next;
				}
			}	
		}
	}
	else{
		printf("Invalid!2");
	}
	if(flag == 0){
		printf("Invalid!3");
	}
}
void hapusTengah(){
	TNode *hapus, *bantu;
	int d;
	bantu = head;
	int count=0;
	int cari=1;
	if(isEmpty()){
		printf("List kosong");
	}
	else{
		while(bantu!=NULL){
		count++;
		bantu=bantu->next;
		}
		bantu=head;
		if(count%2==0){
			if(count==2){
				hapus=head;
				head=bantu->next;
				d=hapus->data;
				printf("%d terhapus",d);
				delete hapus;
			}
			else{
				count=count/2;
				while(cari!=count){
					if(cari+1==count){
						hapus=bantu->next;
						bantu->next=bantu->next->next;
						d=hapus->data;
						printf("%d terhapus",d);
						delete hapus;
						break;
					}
					else{
						bantu=bantu->next;
						cari++;
					}
				}
			}
		}
		else{
			if(count==1){
				hapusDepan();
			}
			else{
				count=count/2;
				while(cari!=count){
					bantu=bantu->next;
					cari++;
				}
				hapus=bantu->next;
				bantu->next=bantu->next->next;
				d=hapus->data;
				printf("%d terhapus",d);
				delete hapus;
			}
		}
	}
}
void hapusBelakang(){
	TNode *hapus,*bantu;
	int d;
	if(!isEmpty()){
		if(head!=tail){
			bantu = head;
			while(bantu->next!=tail){
				bantu=bantu->next;
			}
			tail = bantu;
			hapus = tail->next;
			tail->next = NULL;
			d = hapus->data;
			delete hapus;
		}
		else{
			d = tail->data;
			head = NULL;
			tail = NULL;
		}
		printf("%d terhapus\n",d);
	}
	else{
		printf("Data masih kosong\n");	
	}
}
void tampilLIST(){
	TNode *bantu;
	bantu = head;
	while(bantu!=NULL){
		printf("%d->",bantu->data);
		bantu=bantu->next;
	}
	printf("NULL");
	if(head==NULL){
		printf("\nHEAD : NULL");
		printf("\nTAIL : NULL");
	}
	else{
		printf("\nHEAD : %d",head->data);
		printf("\nTAIL : %d",tail->data);
	}
}
bool cariElemen(int node){
	TNode *bantu=head;
	if(isEmpty()){
		printf("list kosong");
	}
	else{
		while(bantu!=NULL){
			if(bantu->data==node){
				return true;
			}
			else{
				bantu=bantu->next;
			}
		}
	}
	return false;
}
