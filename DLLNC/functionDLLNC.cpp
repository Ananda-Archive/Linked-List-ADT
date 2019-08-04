/*
	Nama			: Ananda Prabu Tritya Vijaya
	NIM				: 24060117130048
	Kelas Praktikum	: B
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

typedef struct TNode{
	int data;
	TNode *next;
	TNode *prev;
}TNode;

TNode *head;

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
	baru->prev = NULL;
	if(isEmpty()){
		head = baru;
		head->next = NULL;
		head->prev = NULL;
	}
	else{
		baru->next = head;
		baru->prev = NULL;
		head->prev = baru;
		head = baru;
	}
}
void insertdiantara(int databaru, int node_kanan, int node_kiri){
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	baru->prev = NULL;
	int flag=0;
	bantu = head;
	if(isEmpty()){
		printf("Invalid!");
	}
	else{
		while(bantu->next != NULL){
			if(bantu->data == node_kiri && bantu->next->data == node_kanan){
				baru->next = bantu->next;
				baru->prev = bantu;
				bantu->next->prev = baru;
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
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	baru->prev = NULL;
	if(isEmpty()){
		head = baru;
		head->next = NULL;
		head->prev = NULL;
	}
	else{
		bantu = head;
		while(bantu->next != NULL){
			bantu = bantu->next;
		}
		baru->next = NULL;
		baru->prev = bantu;
		bantu->next = baru;
	}
}
void insertTengah(int databaru){
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	baru->prev = NULL;
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
			baru->prev=bantu;
			bantu->next->prev=baru;
			bantu->next=baru;
		}
	}
}
void hapusDepan(){
	TNode *hapus;
	if(isEmpty()){
		printf("List Kosong!\n");
	}
	else{
		if(head->next == NULL){
			head = NULL;
		}
		else{
			hapus = head;
			head = head->next;
			head->prev = NULL;
			delete hapus;
		}
	}
}
void hapusdiantara(int node_kiri, int node_kanan){
	TNode *hapus, *bantu;
	bantu = head;
	int count;
	int flag = 0;
	if(!isEmpty()){
		while(bantu !=NULL){
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
					bantu->next = bantu->next->next;
					bantu->next->prev = bantu;
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
void hapusBelakang(){
	TNode *hapus, *bantu;
	if(isEmpty()){
		printf("List Kosong!\n");
	}
	else{
		if(head->next == NULL){
			head = NULL;
		}
		else{
			bantu = head;
			while(bantu->next->next != NULL){
				bantu = bantu->next;
			}
			hapus = bantu->next;
			bantu->next = NULL;
			delete hapus;
		}
	}
}
void hapusTengah(){
	TNode *hapus, *bantu;
	bantu = head;
	int count=0;
	int cari=1;
	if(isEmpty()){
		printf("List kosong");
	}
	else{
		while(bantu !=NULL){
		count++;
		bantu=bantu->next;
		}
		bantu=head;
		if(count%2==0){
			if(count==2){
				hapus=head;
				head = bantu->next;
				head->prev = NULL;
				delete hapus;
			}
			else{
				count=count/2;
				while(cari!=count){
					if(cari+1==count){
						hapus=bantu->next;
						bantu->next=bantu->next->next;
						bantu->next->prev=bantu;
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
				bantu->next->prev=bantu;
				delete hapus;
			}
		}
	}
}
void tampilLIST(){
	TNode *bantu;
	bantu = head;
	if(isEmpty()){
		printf("LIST KOSONG\n");
	}
	else{
		while(bantu!=NULL){
			printf("%d->",bantu->data);
			bantu=bantu->next;
		}
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

void tampilTerbalik(){
	if(isEmpty()){
		printf("LIST KOSONG\n");
	}
	else{
		TNode *bantu;
		bantu = head;
		while(bantu->next!=NULL){
			bantu = bantu->next;
		}
		while(bantu!=NULL){
			printf("%d<-",bantu->data);
			bantu = bantu->prev;
		}
	}
}
