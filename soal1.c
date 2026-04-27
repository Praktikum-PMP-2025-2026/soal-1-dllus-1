/** Praktikum Pemecahan Masalah Dengan Pemrograman 2025/2026
 * Modul: 3 - Structures dan Dynamic Arrays
 * Nama: Adlu Naafi Firdaus
 * nim: 13224029
 * Nama_File: Soal1_Modul3.c
 * Soal: 1
 * Deskripsi: Menentukan Frekuensi data, Mengurutkan data dan median
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int *data = NULL;
    int input, n = 0;
    int capacity = 0;

    while (1) {
        scanf("%d", &input);
        if (input == -1) break;

        if (n >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int *temp = realloc(data, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory allocation failed!");
                free(data);
                return 1;
            }
            data = temp;
        }
        data[n] = input;
        n++;
    }

    if (n == 0) {
        printf("Tidak ada data yang dimasukkan.");
        return 0;
    }

    qsort(data, n, sizeof(int), compare);

    printf("COUNT %d ", n); 
    
    printf("SORTED ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]); 
    }

    double median;
    if (n % 2 == 0) {
        median = (double)(data[n / 2 - 1] + data[n / 2]) / 2.0;
        printf("MEDIAN %.2f", median);
    } else {
        median = (double)data[n / 2];
        printf("MEDIAN %.0f", median);
    }

    free(data);

    return 0;
}
