#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main program
int main(){
	/*
		[0]: "nama prodi", [1]: "kode prodi", [2]: "status prodi", [3]: "jenjang prodi", [4]: "Akreditasi Prodi", [5]: "jumlah mahasiswa"
		
		ex:
		"", "", "", "", "", ""
		
		"agribisnis", "12345", "aktif", "s1", "a", "3200"
	*/
	char prodi[20][6][30] = {
		{"Administrasi Bisnis", "63211", "Aktif", "S1", "A", "1240"},
		{"Administrasi Publik", "63201", "Aktif", "S1", "Unggul", "1300"},
		{"Agribisnis", "54201", "Aktif", "S1", "A", "1105"},
		{"Agroteknologi", "54211", "Aktif", "S1", "A", "1418"},
		{"Akutansi", "62201", "Aktif", "S1", "A", "1538"},
		{"Arsitektur", "23201", "Aktif", "S1", "B", "521"},
		{"DKV", "90241", "Aktif", "S1", "-", "601"},
		{"Ekonomi Pembangunan", "60201", "Aktif", "S1", "-", "981"},
		{"HI", "64201", "Aktif", "S1", "Unggul", "754"},
		{"Hukum", "74201", "Aktif", "S1", "B", "1422"},
		{"Ilmu Komunikasi", "70201", "Aktif", "S1", "Unggul", "1632"},
		{"Informatika", "55202", "Aktif", "S1", "B", "1334"},
		{"Manajemen", "61202", "Aktif", "S1", "A", "2122"},
		{"Pariwisata", "85202", "Aktif", "S1", "Baik", "272"},
		{"Sains Data", "49202", "Aktif", "S1", "Baik", "274"},
		{"Sistem Informasi", "57201", "Aktif", "S1", "B", "951"},
		{"Teknik Industri", "26201", "Aktif", "S1", "B", "1039"},
		{"Teknik Kimia", "24201", "Aktif", "S1", "A", "1144"},
		{"Teknik Linngkungan", "25201", "Aktif", "S1", "Unggul", "623"},
		{"Teknik Mesin", "21201", "Aktif", "S1", "B", "191"}
	};
	
  // untuk mempermudah perulangan saja sii, dari pada input index nya di perulangan jdi ribet cuy
	int row = sizeof(prodi) / sizeof(prodi[0]);
	
	char *fname = "data.txt";
	FILE *filename = fopen(fname, "w");

	if(filename == NULL){
		exit(1);
	}
	
	int i;
	
	for(i=0; i<row; i++){
		if(i == row-1){
			fprintf(filename, "%s|%s|%s|%s|%s|%s", prodi[i][0], prodi[i][1], prodi[i][2], prodi[i][3], prodi[i][4], prodi[i][5]);
		} else{
			fprintf(filename, "%s|%s|%s|%s|%s|%s\n", prodi[i][0], prodi[i][1], prodi[i][2], prodi[i][3], prodi[i][4], prodi[i][5]);
		}
	}

	fclose(filename);

	return 0;
}
