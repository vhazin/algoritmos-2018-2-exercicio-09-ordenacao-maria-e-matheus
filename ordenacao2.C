#include<stdio.h>
#include <time.h>
void bubbleSort(int [], int ) ;
void swap(int *, int *) ;
void selectionSort(int [], int ) ;
void insertionSort(int [], int ) ;
void merge(int [], int , int , int ) ;
void mergeSort(int [], int , int ) ;
void create(int []);
void down_adjust(int [],int);
void heapsort(int [], int );
void quicksortinicio(int [],int ,int);
void quicksortfim(int [],int ,int);
 
void heapsort(int heap[], int n)
{
    int last,temp;
    
    heap[0]=n;
    create(heap);
    while(heap[0] > 1)
    {
        last=heap[0];
        temp=heap[1];
        heap[1]=heap[last];
        heap[last]=temp;
        heap[0]--;
        down_adjust(heap,1);
    }

}
 
void create(int heap[])
{
    int i,n;
    n=heap[0]; 
    for(i=n/2;i>=1;i--)
        down_adjust(heap,i);
}
 
void down_adjust(int heap[],int i)
{
    int j,temp,n,flag=1;
    n=heap[0];
    
    while(2*i<=n && flag==1)
    {
        j=2*i;   
        if(j+1<=n && heap[j+1] > heap[j])
            j=j+1;
        if(heap[i] > heap[j])
            flag=0;
        else
        {
            temp=heap[i];
            heap[i]=heap[j];
            heap[j]=temp;
            i=j;
        }
    }
}

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
  


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 
} 


void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 

       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int w = m + 1;
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]; 
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[w + j]; 
         }
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
   
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
        

    } 

    
    
} 

void quicksortinicio(int arr[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            swap(&arr[i], &arr[j]); 
         }
      }

      swap(&arr[pivot], &arr[j]); 
      quicksortinicio(arr,first,j-1);
      quicksortinicio(arr,j+1,last);

   }
}

void quicksortfim(int arr[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=last;
      i=last;
      j=first;

      while(i>j){
         while(arr[i]>=arr[pivot]&&i>first)
            i--;
         while(arr[j]<arr[pivot])
            j++;
         if(i>j){
            swap(&arr[i], &arr[j]); 
         }
      }

      swap(&arr[pivot], &arr[j]); 
      quicksortfim(arr,first,j-1);
      quicksortfim(arr,j+1,last);

   }
}

int main() 
{ 
    int numero, na,nb,nc,nd,ne,nf,ng, i; 
    clock_t begin,end;
    clock_t begin2,end2;
    clock_t begin3,end3;
    clock_t begin4,end4;
    clock_t begin5,end5;
    clock_t begin6,end6;
    clock_t begin7,end7;
    double times ;
    
    
    scanf("%d", &na);
    nb = na;
    nc = nb;
    nd = nc;
    ne = nd;
    nf = ne;
    ng = nf;

    int arra[na];
    int arrb[nb];
    int arrc[nc];
    int arrd[nd];
    int arre[ne];
    int arrf[nf];
    int arrg[ng];

    for(i=0;i<na;i++){
      scanf("%d", &numero);
      arra[i]=numero;
      arrb[i]=numero;
      arrc[i]=numero;
      arrd[i]=numero;
      arre[i]=numero;
      arrf[i]=numero;
      arrg[i]=numero;
    }
    begin = clock();
    mergeSort(arrb, 0, nb - 1);
    end = clock();
    times = (double)(end - begin)/ CLOCKS_PER_SEC;
    printf("\n%f merge",times);

    begin3 = clock();
    insertionSort(arra, na);
    end3 = clock();
    times =( (double)(end3 - begin3)/ CLOCKS_PER_SEC)*1000;
    printf("\n%f insertion",times); 

    begin2 = clock();
    selectionSort(arrc, nc);
    end2 = clock();
    times = (double)(end2 - begin2)/ CLOCKS_PER_SEC;
    printf("\n%f selection",times);
    
    begin4 = clock();
    bubbleSort(arrd, nd);
    end4 = clock();
    times = (double)(end4 - begin4)/ CLOCKS_PER_SEC;
    printf("\n%f bubble",times);

    begin5 = clock();
    heapsort(arre, ne);
    end5 = clock();
    times = (double)(end5 - begin5)/ CLOCKS_PER_SEC;
    printf("\n%f heap",times);

    begin6 = clock();
    quicksortinicio(arrf,0,nf-1);
    end6 = clock();
    times = (double)(end6 - begin6)/ CLOCKS_PER_SEC;
    printf("\n%f quick sort pivot inicio ",times);

    begin7 = clock();
    quicksortfim(arrg,0,ng-1);
    end7 = clock();
    times = (double)(end7 - begin7)/ CLOCKS_PER_SEC;
    printf("\n%f quick sort pivot fim ",times);
    
    return 0; 
} 
