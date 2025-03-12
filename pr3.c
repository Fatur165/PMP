/*
    Ahmad Fatur Rohman
    13223112 
    PR 3 - MATRIKS DAN ARRAY 
        Program berguna untuk menghitung proyeksi obyek dari 3D menjadi 2D dengan 
        menggunakan transformasi koordinat world ke kamera 
*/

#include <stdio.h>

int main(void) {
    /* Variabel yang akan digunakan, yaitu matriks dan lambda*/
    float lambda, K[3][3], RT[3][4], XX[4][1], RTXX[3][1], UV[3][1];

    /*Insialisasi nilai matriks bernilai 0 semua*/
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j){
            K[i][j] = 0;
            RT[i][j] = 0;
        }
    }

    for(int i = 0; i<3; ++i){
        RT[i][3] = 0;
        XX[i][0] = 0;
    }

    K[2][2] = 1;
    XX[3][0] = 1;
    /*Masukkan input untuk lambda dan matriks yang dibutuhkan*/
    printf("Masukkan nilai fx >>> ");
    scanf("%f", &K[0][0]);

    printf("Masukkan nilai fy >>> ");
    scanf("%f", &K[1][1]);

    printf("Masukkan nilai cx >>> ");
    scanf("%f", &K[0][2]);

    printf("Masukkan nilai cy >>> ");
    scanf("%f", &K[1][2]);

    printf("Masukkan nilai X >>> ");
    scanf("%f", &XX[0][0]);

    printf("Masukkan nilai Y >>> ");
    scanf("%f", &XX[1][0]);

    printf("Masukkan nilai Z >>> ");
    scanf("%f", &XX[2][0]);

    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j){
            printf("Masukkan nilai r[%d][%d]>>> ", i+1, j+1);
            scanf("%f", &RT[i][j]);
        }
    }

    for(int i = 0; i<3; ++i){
        printf("Masukkan nilai t[%d]>>> ", i+1);
        scanf("%f", &RT[i][3]);
    }

    /*Tahap perkalian matriks RT dengan XX*/
    for(int i = 0; i<3; ++i){
        RTXX[i][0] = 0; /*Inisialisasi hasil perkalian dengan matriks RTXX bernilai 0*/
        for(int j = 0; j<4; ++j){
            RTXX[i][0] += RT[i][j] * XX[j][0]; /*Perkalian baris dengan kolom dan dijumlahkan*/
        }
    }

    /*Tahap perkalian K dengan RTXX*/
    for(int i = 0; i<3; ++i){
        UV[i][0] = 0;  /*Inisialisasi hasil perkalian dengan matriks UV bernilai 0*/
        for(int j = 0; j<3; ++j){
            UV[i][0] += K[i][j] * RTXX[j][0]; /*Perkalian baris dengan kolom dan dijumlahkan*/
        }
    }

    if(UV[2][0] == 1){lambda = 1;} /*Jika sudah berbentuk [u, v, 1] maka sudah selesai dan lambda bernilai 1*/
    else {
        lambda = UV[2][0]; /*Elemen ketiga menjadi nilai lambda*/
        UV[0][0] = UV[0][0]/lambda; /*Dibagi dengan lambda*/
        UV[1][0] = UV[1][0]/lambda;
        UV[2][0] = 1; /*Elemen ketiga menjadi bernilai 1*/
    }

    /*Menampilkan output program*/
    for(int i = 0; i<3; ++i){
        printf("Nilai untuk UV[%d] adalah %.2f\n", i+1, UV[i][0]); 
    }

    printf("Diperoleh nilai lambda yaitu %.0f", lambda);



    
}
