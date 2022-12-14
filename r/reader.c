#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Switch 20 to total prodi
#define jumlahProdi 20

// initialization jumlahData to get total of line in file
int jumlahData  =  0;

// make struct to get all data from file
struct kampus{
	char nama[50];
	char kode[10];
	char status[15];
	char jenjang[5];
	char akreditasi[15];
	int jumlahMahasiswa;
} prodi[jumlahProdi];

// main program
int main(){
	// initialization fname for file name
	char *fname = "data.txt";
	// initialization file aklsjdflkasjlikfdjalsejf males ngetik cok
	FILE *filename = fopen(fname, "r");
	
	// make sure file is not null, if null then exit with return code 1
	if(filename == NULL){
		exit(1);
	}
	
	// process read data with format, while next file line not null
	while(!feof(filename)){
		fscanf(filename, " %[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d", prodi[jumlahData].nama, prodi[jumlahData].kode, prodi[jumlahData].status, prodi[jumlahData].jenjang, prodi[jumlahData].akreditasi, &prodi[jumlahData].jumlahMahasiswa);
		jumlahData++;
	}
	
	// close file
	fclose(filename);

	// make table header
    printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    printf("| Kode  |     Nama Prodi      | Status Prodi | Jenjang | Akreditasi | Jumlah Mahasiswa |\n");
    printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    
    // initialization i for looping n rata to get value from all jumlahMahasiswa variable
    int i = 0;
    float rata = 0.0;
    
    // initialization max n min to get max n min value from jumlahMahasiswa variable
    int max = 0, min = 0;
    
    // looping to print all data needed
    for(i=0; i<jumlahData; i++){
        // print data
		printf("| %-5s | %-19s | %-12s | %-7s | %-10s | %-16d |\n", prodi[i].kode, prodi[i].nama, prodi[i].status, prodi[i].jenjang, prodi[i].akreditasi, prodi[i].jumlahMahasiswa);
        printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    	
    	// get rata rata
		rata += prodi[i].jumlahMahasiswa;
    	
    	// get max
    	if(prodi[max].jumlahMahasiswa < prodi[i].jumlahMahasiswa){
    		max = i;
		}
		
		// get min
		if(prodi[max].jumlahMahasiswa > prodi[i].jumlahMahasiswa){
    		min = i;
		}
	}
    
    // show rata rata 
    printf("\nRata-rata jumlah mahasiswa UPN dalam 30 prodi di UPN adalah %.2f\n", (rata/jumlahData));

	// show max n min
    printf("\nProdi dengan mahasiswa paling banyak  : %-19s | Dengan jumlah mahasiswa : %d", prodi[max].nama, prodi[max].jumlahMahasiswa);
    printf("\nProdi dengan mahasiswa paling sedikit : %-19s | Dengan jumlah mahasiswa : %d", prodi[min].nama, prodi[min].jumlahMahasiswa);
    
    // return to make sure the program not error
	return 0;
}
