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
    int i;
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
    
    for(i=0; i<jumlahData; i++){
        printf("| %-5s | %-19s | %-12s | %-7s | %-10s | %-16d |\n", prodi[i].kode, prodi[i].nama, prodi[i].status, prodi[i].jenjang, prodi[i].akreditasi, prodi[i].jumlahMahasiswa);
        printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    }
    
	return 0;
}
