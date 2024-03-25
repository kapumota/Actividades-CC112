#include <iostream>
using namespace std;

static void radixsort(int Array[], int n);
static void countingsort(int Array[], int n, int lugar);
static void imprimirArreglo(int Array[], int n); 

void radixsort(int Array[], int n) {
  int max = Array[0];

  for (int i=1; i<n; i++) {  
      if(max < Array[i])
         max = Array[i];
  }

  for (int lugar = 1; max/lugar > 0; lugar *= 10) 
    countingsort(Array, n, lugar); 
}

static void countingsort(int Array[], int n, int lugar) {   
  int salida[n];

  int freq[10] = {0};

  for(int i = 0; i < n; i++)
    freq[(Array[i]/lugar)%10]++;

  for (int i = 1; i < 10; i++) 
    freq[i] += freq[i - 1];    
    
  for (int i = n - 1; i >= 0; i--) { 
    salida[freq[(Array[i]/lugar)%10] - 1] = Array[i]; 
    freq[(Array[i]/lugar)%10]--; 
  }  


  for (int i = 0; i < n; i++) 
    Array[i] = salida[i]; 
}
  
static void imprimirArreglo(int Array[], int n) { 
  for (int i=0; i<n; i++) 
    cout<<Array[i]<<" "; 
  cout<<"\n"; 
} 

// Prueba el codigo
int main (){
  int arreglo1[] = {101, 1, 20, 50, 9, 98, 27, 153, 35, 899};
  int n = sizeof(arreglo1) / sizeof(arreglo1[0]); 
  cout<<"Array original\n";
  imprimirArreglo(arreglo1, n);

  radixsort(arreglo1, n);
  cout<<"\nArreglo ordenado\n";
  imprimirArreglo(arreglo1, n);
  return 0;
}
