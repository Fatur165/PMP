/*
Nama    : Ahmad Fatur Rohman
NIM     : 13223112
Program : Menghitung posisi x dan y suatu mobil setelah 1 detik
*/

#include <stdio.h>
#define delta_t 1

/* Fungsi untuk menghitung nilai faktorial */
int factorial (int x){
    int fact = 1;
    for(int i = 1; i<=x; ++i){
        fact *= i; /* Terus dilakukan perkalian dengan nilainya mulai 1 */
    }
    return fact;
}

/* Fungsi untuk menghitung nilai x pangkay y */
double pangkat (double x, int y){
    double pngkt = 1;
    for(int i = 1; i<=y; ++i){
        pngkt *= x;
    }
    return pngkt;
}

/* sin x = sigma (-1)^n x^(2n+1)/(2n+1)! dari n=0 sampai tak hingga*/
double sinus (double x, int y){
    double nilai_sin = 0;
    for(int n = 0; n<y; ++n){
        nilai_sin += pangkat(-1, n)*pangkat(x,2*n+1)/factorial(2*n+1);
    }
    return nilai_sin;
}

/* cos x = sigma (-1)^n x^(2n)/(2n)! dari n=0 sampai tak hingga*/
double cosinus (double x, int y){
    double nilai_cos = 0;
    for(int n = 0; n<y; ++n){
        nilai_cos += pangkat(-1, n)*pangkat(x,2*n)/factorial(2*n);
    }
    return nilai_cos;
}

/* PROGRAM UTAMA */
int main (void){
    double kec, r_awal[2][1], r_akhir[2][1], matriks_sincos[2][1];
    double sudut;
    int iterasi;

    /*Inisialisasi nilai awal matriks yaitu 0*/
    for(int i = 0; i<2; ++i){
        r_awal[i][0] = 0;
        r_akhir[i][0] = 0;
        matriks_sincos[i][0] = 0;
    }

    /* INPUT */
    printf("Masukkan nilai kecepatan sesaat (m/s)>>>");
    scanf("%lf", &kec);

    printf("Masukkan posisi x (m)>>>");
    scanf("%lf", &r_awal[0][0]);

    printf("Masukkan posisi y (m)>>>");
    scanf("%lf", &r_awal[1][0]);

    printf("Sedang ada di sudut berapa nich (radian)>>>");
    scanf("%lf", &sudut);

    printf("Mau berapa suku pertama untuk sin-cos nya >>>");
    scanf("%d", &iterasi);

    /* Mengganti nilai matriks sin cosnya dengan nilai sinus cosinus
    berdasarkan sudut masukan dan dihitung dengan fungsi sebelumnya*/
    matriks_sincos[0][0] = cosinus(sudut, iterasi);
    matriks_sincos[1][0] = sinus(sudut, iterasi);

    /*PROSES PERHITUNGAN*/
    for(int i = 0; i<2; ++i){
        r_akhir[i][0] = r_awal[i][0] + (delta_t*kec*matriks_sincos[i][0]);
    }

    /*OUTPUT*/
    printf("Anda 1 detik lagi akan berada pada posisi x = %.2lfm dan y = %.2lfm", r_akhir[0][0], r_akhir[1][0]);
}