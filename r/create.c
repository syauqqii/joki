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
	char prodi[4][6][20] = {
		{"Administrasi Bisnis", "63211", "Aktif", "S1", "A", "1240"},
		{"Administrasi Publik", "63201", "Aktif", "S1", "Unggul", "1300"},
		{"Agribisnis", "54201", "Aktif", "S1", "A", "1105"},
		{"Agroteknologi", "54211", "Aktif", "S1", "A", "1418"}
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
		fprintf(filename, "%s|%s|%s|%s|%s|%s\n", prodi[i][0], prodi[i][1], prodi[i][2], prodi[i][3], prodi[i][4], prodi[i][5]);
	}

	fclose(filename);

	return 0;
}
