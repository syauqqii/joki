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
	long kode;
	char status[15];
	char jenjang[5];
	char akreditasi[15];
	int jumlahMahasiswa;
} prodi[jumlahProdi];

int getMax(int arr[], int n){
	int i;
	
	if(n != 0){
		if(arr[n] > getMax(arr, n-1)){
			return arr[n];
		} else{
			return getMax(arr, n-1);
		}
	} else{
		return arr[0];
	}
}

int getMin(int arr[], int n){
	int i;
	
	if(n != 0){
		if(arr[n] <= getMin(arr, n-1)){
			return arr[n];
		} else{
			return getMin(arr, n-1);
		}
	} else{
		return arr[0];
	}
}

long get_Max(long a[], int n){
    int i, max=a[0];
    for(i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;//maximumelementfromthearray
}

void countingSort(long a[], int n, int place){
    int i, output[n+1];
    int count[10]={0};

    //Calculatecountofelements
    for(i=0;i<n;i++)
    count[(a[i]/place)%10]++;

    //Calculatecumulativefrequency
    for(i=1;i<10;i++)
        count[i]+=count[i-1];

    //Placetheelementsinsortedorder
    for(i=n-1;i>=0;i--){
       output[count[(a[i]/place)%10]-1]=a[i];
       count[(a[i]/place)%10]--;
    }

    for(i=0;i<n;i++)
        a[i]=output[i];
}

//functiontoimplementradixsort
void radixsort(long a[], int n){
    //getmaximumelementfromarray
    int place, max=get_Max(a,n);

    //Applycountingsorttosortelementsbasedonplacevalue
    for(place=1;max/place>0;place*=10)
    countingSort(a,n,place);
}

// main program
int main(){
	int arr[jumlahProdi];
	long kode[jumlahProdi];
	long temp[jumlahProdi];
	
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
		fscanf(filename, " %[^|]|%ld|%[^|]|%[^|]|%[^|]|%d", prodi[jumlahData].nama, &prodi[jumlahData].kode, prodi[jumlahData].status, prodi[jumlahData].jenjang, prodi[jumlahData].akreditasi, &prodi[jumlahData].jumlahMahasiswa);
		temp[jumlahData] = prodi[jumlahData].kode;
		jumlahData++;
	}
	
	// close file
	fclose(filename);
	
	// initialization i for looping n rata to get value from all jumlahMahasiswa variable
    int i = 0, tmp = 0;
    float rata = 0.0;
	
	for(i=0; i<jumlahData; i++){
		kode[i] = prodi[i].kode;
	}

	radixsort(kode, jumlahData);

	// make table header
    printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    printf("| Kode  |     Nama Prodi      | Status Prodi | Jenjang | Akreditasi | Jumlah Mahasiswa |\n");
    printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
    
    
    
    // initialization max n min to get max n min value from jumlahMahasiswa variable
    int max = 0, min = 0, j;
    
    // looping to print all data needed
    for(i=0; i<jumlahData; i++){
        // print data
		for(j=jumlahData-1; j>0; j--){
			if(kode[i] == temp[j]){
				printf("| %-5ld | %-19s | %-12s | %-7s | %-10s | %-16d |\n", prodi[j].kode, prodi[j].nama, prodi[j].status, prodi[j].jenjang, prodi[j].akreditasi, prodi[j].jumlahMahasiswa);
        		printf("+-------+---------------------+--------------+---------+------------+------------------+\n");
				temp[j] = 0;
			}
		}
    	
    	// get rata rata
		rata += prodi[i].jumlahMahasiswa;
    	
		arr[i] = prodi[i].jumlahMahasiswa;
		tmp++;
	}
    
    // show rata rata 
    printf("\nRata-rata jumlah mahasiswa UPN dalam 30 prodi di UPN adalah %.2f\n", (rata/jumlahData));

	max = getMax(arr, tmp-1);
	min = getMin(arr, tmp-1);
	
	int indexMax = 0;
	int indexMin = 0;
	
	for(i=0; i<tmp; i++){
		if(max == prodi[i].jumlahMahasiswa){
			indexMax = i;
			break;
		}
	}
	
	for(i=0; i<tmp; i++){
		if(min == prodi[i].jumlahMahasiswa){
			indexMin = i;
			break;
		}
	}
	
	// show max n min
    printf("\nProdi dengan mahasiswa paling banyak  : %-19s | Dengan jumlah mahasiswa : %d", prodi[indexMax].nama, prodi[indexMax].jumlahMahasiswa);
    printf("\nProdi dengan mahasiswa paling sedikit : %-19s | Dengan jumlah mahasiswa : %d\n", prodi[indexMin].nama, prodi[indexMin].jumlahMahasiswa);
    
    // return to make sure the program not error
	return 0;
}
