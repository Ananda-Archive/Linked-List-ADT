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
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = baru;
	if(isEmpty()){
		head = baru;
		head->next = head;
	}
	else{
		bantu = head;
		baru->next = head;
		while (bantu->next != head){
			bantu = bantu->next;
		}
		bantu->next = baru;
		head = baru;
	}
}
void insertdiantara(int databaru, int node_kanan, int node_kiri){
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = baru;
	int flag=0;
	bantu = head;
	if(isEmpty()){
		printf("Invalid!");
	}
	else{
		while(bantu->next != head){
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
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = baru;
	if(isEmpty()){
		head = baru;
		head->next = head;
	}
	else{
		bantu = head;
		while(bantu->next != head){
			bantu = bantu->next;
		}
		bantu->next = baru;
		baru->next = head;
	}
}
void insertTengah(int databaru){
	TNode *baru, *bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = baru;
	bantu = head;
	int count=0;
	int cari=1;
	if(isEmpty()){
		insertDepan(databaru);
	}
	else{
		while(bantu->next!=head){
			count++;
			bantu=bantu->next;
		}
		count++;
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
	TNode *hapus, *bantu;
	if(!isEmpty()){
		if(head->next != head){
			bantu = head;
			while(bantu->next != head){
				bantu = bantu->next;
			}
			hapus = head;
			head = head->next;
			bantu->next = head;
			delete hapus;
		}
		else{
			head = NULL;
		}
	}
	else printf("Masih kosong\n");
}
void hapusdiantara(int node_kiri, int node_kanan){
	TNode *hapus, *bantu;
	bantu = head;
	int count;
	int flag = 0;
	if(!isEmpty()){
		while(bantu->next!=head){
			count++;
			bantu=bantu->next;
		}
		count++;
		if(count<=2){
			printf("Invalid1");
		}
		else{
			bantu=head;
			while(bantu->next!=head){
				if(bantu->data == node_kiri && bantu->next->next->data == node_kanan){
					hapus = bantu->next;
					bantu->next = bantu->next->next;
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
	bantu = head;
	int count=0;
	int cari=1;
	if(isEmpty()){
		printf("List kosong");
	}
	else{
		while(bantu->next!=head){
			count++;
			bantu=bantu->next;
		}
		count++;
		bantu=head;
		if(count%2==0){
			if(count==2){
				hapus=head;
				head=bantu->next;
				head->next = head;
				delete hapus;
			}
			else{
				count=count/2;
				while(cari!=count){
					if(cari+1==count){
						hapus=bantu->next;
						bantu->next=bantu->next->next;
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
				delete hapus;
			}
		}
	}
}
void hapusBelakang(){
	TNode *hapus, *bantu;
	if(!isEmpty()){
		if(head->next != head){
			bantu = head;
			while(bantu->next->next != head){
				bantu = bantu->next;
			}
			hapus = bantu->next;
			bantu->next = head;
			delete hapus;
		}
		else{
			head = NULL;
		}
	}
	else printf("Masih kosong\n");
}
void tampilLIST(){
	TNode *bantu;
	bantu = head;
	if(!isEmpty()){
		while(bantu->next!=head){
			printf("%d->",bantu->data);
			bantu = bantu->next;
		}
		printf("%d",bantu->data);
	}
	else{
		printf("Data kosong!\n");
	}
}
bool cariElemen(int node){
	TNode *bantu=head;
	if(isEmpty()){
		printf("list kosong");
	}
	else{
		while(bantu->next!=head){
			if(bantu->data==node){
				return true;
			}
			else{
				bantu=bantu->next;
			}
		}
		if(bantu->data==node){
			return true;
		}
	}
	return false;
}
void sort(){
	if(isEmpty()){
		printf("DATA KOSONG!\n");
	}
	else{
		TNode *bantu, *sort, *sorthead;
		int count;
		bantu = head;
		while(bantu->next!=head){
			count++;
			bantu=bantu->next;
		}
		count++;
		int data[count];
		int i,j;
		bantu = head;
		// Simpan data dalam list
		for(i=0;i<count;i++){
			data[i] = bantu->data;
			bantu = bantu->next;
		}
		// Sorting list
		int min,temp;
		for(i=0;i<count-1;i++){
			min = data[i];
			for(j=i+1;j<count;j++){
				if(min>data[j]){
					temp = min;
					min = data[j];
					data[j] = temp;
				}
			}
			data[i] = min;
		}
		sort = new TNode;
		sort->next = sort;
		sorthead = sort;
		sorthead->data = data[0];
		bantu = sorthead;
		for(i=1;i<count;i++){
			sort = new TNode;
			sort->data = data[i];
			sort->next = sorthead;
			bantu->next = sort;
			bantu = bantu->next;
		}
		bantu = sorthead;
		printf("\n[SEBELUM SORTING]\n");
		tampilLIST();
		printf("\n[SETELAH SORTING]\n");
		while(bantu->next!=sorthead){
			printf("%d->",bantu->data);
			bantu = bantu->next;
		}
		printf("%d",bantu->data);
	}
}
