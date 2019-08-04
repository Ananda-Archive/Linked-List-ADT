/*
	Nama			: Ananda Prabu Tritya Vijaya
	NIM				: 24060117130048
	Kelas Praktikum	: B
*/
#include <bits/stdc++.h>
#include "functionDLLNC.cpp"

using namespace std;

int main(){
	int n, databaru, node_kanan, node_kiri;

	menu:
	system("cls");
	cout << "\nMENU SLLNC (DOUBLE LINKED LIST NON CIRCULAR)" << endl;
	cout << "[1]Tambah LIST\n[2]Hapus LIST\n[3]Tampil LIST\n[4]Cari Elemen LIST\n[5]Tampil terbalik\n[6]Keluar\n";
	cout << "Masukkan nomor menu >>>";
	cin >> n;
	switch(n){
		case 1: system("cls");
				cout << "\nTambah LIST\n[1]Tambah Depan\n[2]Tambah Belakang\n[3]Tambah Tengah (antara node tertentu)\n[4]Tambah Tengah\n";
				cout << "Masukkan nomor menu >>>";
				cin >> n;
				switch(n){
					case 1: cout << "[Tambah Depan]\nMasukkan data baru: \n";
							cin >> databaru;
							insertDepan(databaru);
							cout << "\nPress any key!"; getch();
							goto menu;
					case 2: cout << "[Tambah Belakang]\nMasukkan data baru: \n";
							cin >> databaru;
							insertBelakang(databaru);
							cout << "\nPress any key!"; getch();
							goto menu;
					case 3: cout << "[Tambah tengah (antara node tertentu)]\nMasukkan data baru: "; cin >> databaru;
							cout << "Masukkan node sebelah kiri: "; cin >> node_kiri;
							cout << "Masukkan node sebelah kanan: "; cin >> node_kanan;
							insertdiantara(databaru, node_kanan, node_kiri);
							cout << "\nPress any key!"; getch();
							//???
							goto menu;
					case 4: cout << "[Tambah Tengah]\nMasukkan data baru: \n";
							cin >> databaru;
							insertTengah(databaru);
							cout << "\nPress any key!"; getch();
							goto menu;
					default: cout << "Masukan salah! Mohon coba lagi...\n";
							 cout << "\nPress any key!"; getch();
							 goto menu;
				}
		case 2: system("cls");
				cout << "\nHapus LIST\n[1]Hapus Depan\n[2]Hapus Belakang\n[3]Hapus Tengah (antara node tertentu)\n[4]Hapus Tengah\n";
				cout << "Masukkan nomor menu >>> ";
				cin >> n;
				switch(n){
					case 1: cout << "[Hapus Depan]\n";
							hapusDepan();
							cout << "\nPress any key!"; getch();
							goto menu;
					case 2: cout << "[Hapus Belakang]\n";
							hapusBelakang();
							cout << "Belakang terhapus!";
							cout << "\nPress any key!"; getch();
							goto menu;
					case 3: cout << "[Hapus Tengah (antara node tertentu)]\n";
							cout << "Masukkan node kiri: "; cin >> node_kiri;
							cout << "Masukkan node kanan:"; cin >> node_kanan;
							hapusdiantara(node_kiri, node_kanan);
							cout << "\nPress any key!"; getch();
							goto menu;
					case 4: cout << "[Hapus Tengah]\n";
							hapusTengah();
							cout << "\nPress any key!"; getch();
							goto menu;
					default: cout << "Masukan salah! Mohon coba lagi...\n";
							 cout << "\nPress any key!"; getch();
							 goto menu;
				}
		case 3: system("cls");
				cout << "\n[Tampil LIST]\n";
				tampilLIST();
				cout << "\nPress any key!"; getch();
				goto menu;
		case 4: system("cls");
				int node;
				cout << "\nCari Elemen LIST\n";
				cout << "Masukkan node yang dicari: "; cin >> node;
				cariElemen(node);
				if(cariElemen(node)){
					printf("Ketemu!\n");
				}
				else{
					printf("Tidak ketemu!\n");
				}
				cout << "\nPress any key!"; getch();
				goto menu;
		case 5: system("cls");
				cout << "\n[Tampil LIST SEBELUM DI BALIK]\n";
				tampilLIST();
				cout << "\n[Tampil LIST SETELAH DI BALIK]\n";
				tampilTerbalik();
				getch();
				goto menu;
		case 6: return 0;
		default: cout << "\nMasukan salah! Mohon coba lagi...\n";
				 cout << "\nPress any key!"; getch();
				 goto menu;

	}
	
}
