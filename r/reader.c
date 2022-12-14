#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ganti sesuai jumlah prodi
#define jumlahProdi 20

int jumlahData  =  0;

struct kampus{
	char nama[50];
	char kode[10];
	char status[15];
	char jenjang[5];
	char akreditasi[15];
	int jumlahMahasiswa;
} prodi[jumlahProdi];

int main(){
	char *fname = "data.txt";
	FILE *filename = fopen(fname, "r");
	
	if(filename == NULL){
		exit(1);
	}
	
	while(!feof(filename)){
		fscanf(filename, " %[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d", prodi[jumlahData].nama, prodi[jumlahData].kode, prodi[jumlahData].status, prodi[jumlahData].jenjang, prodi[jumlahData].akreditasi, &prodi[jumlahData].jumlahMahasiswa);
		jumlahData++;
	}
	
	fclose(filename);

    printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    printf("| Kode  |     Nama Prodi      | Status Prodi | Jenjang | Akreditasi | Jumlah Mahasiswa |\n");
    printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    
    int i = 0;
    float rata = 0.0;
    
    int max = 0, min = 0;
    
    for(i=0; i<jumlahData; i++){
        printf("| %-5s | %-19s | %-12s | %-7s | %-10s | %-16d |\n", prodi[i].kode, prodi[i].nama, prodi[i].status, prodi[i].jenjang, prodi[i].akreditasi, prodi[i].jumlahMahasiswa);
        printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    	rata += prodi[i].jumlahMahasiswa;
    	
    	if(prodi[max].jumlahMahasiswa < prodi[i].jumlahMahasiswa){
    		max = i;
		}
		
		if(prodi[max].jumlahMahasiswa > prodi[i].jumlahMahasiswa){
    		min = i;
		}
	}
    
    printf("\nRata-rata jumlah mahasiswa UPN dalam 30 prodi di UPN adalah %.2f\n", (rata/jumlahData));

    printf("\nProdi dengan mahasiswa paling banyak  : %-19s | Dengan jumlah mahasiswa : %d", prodi[max].nama, prodi[max].jumlahMahasiswa);
    printf("\nProdi dengan mahasiswa paling sedikit : %-19s | Dengan jumlah mahasiswa : %d", prodi[min].nama, prodi[min].jumlahMahasiswa);
    
	return 0;
}
