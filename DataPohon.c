/* NAMA     : AHMAD FATUR ROHMAN
   NIM      : 13223112
   PROGRAM  : MENENTUKAN PENAMBAHAN, PENGURANGAN, DAN PEMERIKSAAN POHON */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   
/* Struct untuk menyimpan data pohon */ 
struct Tree {
    int id; /*ID dari pohon*/
    float latitude; /* Lintang */
    float longitude; /* Bujur */
    int age; /* Usia pohon */
    float diameter; /* Diameter pohon */
    struct Tree* next; 
   };
/* Buat head nya null */
struct Tree* head = NULL;

/* MEMBUAT NODE BARU */
struct Tree* Buatnode(int id, float lat, float lon, int age, float diameter) {
    struct Tree* NodeBaru = (struct Tree*)malloc(sizeof(struct Tree)); /* Meminta memori saat akan membuat node baru */
    /* Identitas pohon yang baru */
    NodeBaru->id = id;
    NodeBaru->latitude = lat;
    NodeBaru->longitude = lon;
    NodeBaru->age = age;
    NodeBaru->diameter = diameter;
    NodeBaru->next = NULL;
    return NodeBaru;
}
   
/* MENAMBAHKAN NODE BARU KE LINKED LIST */
void TAMBAH(int id, float lat, float lon, int age, float diameter) {
    struct Tree* NodeBaru = Buatnode(id, lat, lon, age, diameter);
    /* Belum ada pohon, maka yang ditambahkan menjadi head */
    if (head == NULL) {
       head = NodeBaru;} 
    /* Sudah ada pohon sebelumnya */
    else {
       struct Tree* temp = head;
       while (temp->next != NULL) {
           temp = temp->next;
       }
       temp->next = NodeBaru;
    }
    printf("Pohon berhasil ditambahkan.\n");
}
   
/* MENAMPILKAN SEMUA POHON */
void LIHAT() {
    struct Tree* temp = head;
    /* Jika tidak ada pohon */
    if (temp == NULL) {
        printf("Tidak ada data pohon.\n");
        return;
    }
    printf("Daftar Pohon:\n");
    while (temp != NULL) {
        printf("ID: %d | Lokasi: (%.4f, %.4f) | Umur: %d tahun | Diameter: %.2f meter\n", temp->id, temp->latitude, temp->longitude, temp->age, temp->diameter);
        temp = temp->next;
    }
}
   
/* MENGHAPUS POHON YANG ADA */
void HAPUS(int id) {
    struct Tree *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
       prev = temp;
       temp = temp->next;
    }
    if (temp == NULL) {
       printf("Pohon dengan ID %d tidak ditemukan.\n", id);
       return;
    }
    if (prev == NULL) {
       head = head->next;
    } 
    else {
       prev->next = temp->next;
    }
    free(temp);
    printf("Pohon dengan ID %d berhasil dihapus.\n", id);
}
   
/* MAIN FUNGSI */
int main() {
   int menu, id, umur;
   float lat, lon, diameter;

    do {
       printf("\n==MENU INVENTORI POHON SAWIT==\n");
       printf("1. Tambah Pohon\n");
       printf("2. Lihat Semua Pohon\n");
       printf("3. Hapus Pohon berdasarkan ID\n");
       printf("4. Keluar\n");
       printf("Pilih menu (Angka saja): ");
       scanf("%d", &menu);
   
       /* Masuk ke menu yang dipilih */
        switch (menu){
            case 1:
                printf("Masukkan ID Pohon: ");
                scanf("%d", &id);
                printf("Masukkan Latitude: ");
                scanf("%f", &lat);
                printf("Masukkan Longitude: ");
                scanf("%f", &lon);
                printf("Masukkan Umur Pohon (tahun): ");
                scanf("%d", &umur);
                printf("Masukkan Diameter (meter): ");
                scanf("%f", &diameter);
                /* Panggil fungsi sebelumnya untuk menambah pohon */
                TAMBAH(id, lat, lon, umur, diameter);
                break;
            case 2:
                /* Panggil fungsi untuk melihat pohon */
                LIHAT();
                break;
            case 3:
                printf("Masukkan ID pohon yang ingin dihapus: ");
                scanf("%d", &id);
                HAPUS(id);
                break;
            case 4:
                printf("Keluar dari program...\n");
                break;
        }
    } while (menu != 4); /* Selama inputnya bukan 4 (keluar) */
   
    return 0;
}
   
