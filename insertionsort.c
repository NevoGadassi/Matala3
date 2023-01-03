
#include <stdio.h>
#include <string.h>
#define N 50



void shift_element(int* arr, int i){
    int* temp;
   for (int t = i-1; t >= 0; t--) {
        temp= (arr+t+1)+1;
      *(temp)=*(arr+t+1);
   }
   *(arr+1)=0;
}

void insertion_sort(int* arr , int len){
    int count;
    int temp;

    for(int i=1;i<len;i++){
        
        count=0;
        temp=*(arr + i);
         
        for(int t=i-1;t>=0;t--){
           
            if(t==0  &&  temp <= *(arr + t)){
                shift_element(arr,i-1);
                *(arr+1)=*(arr);
                *(arr)=temp;
            }
            if( temp > *(arr + t)){
                shift_element((arr + t),count);
                *(arr + t+1)=temp;
                t=-1;
            }
            count++;

        }
    }
}

int main(int argc, char **argv)
{
    int x[N];
    int num = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        *(x + i) = num;
    }
    
  
    insertion_sort(x,N);
    for (int i = 0; i < 49; i++)
    {
        printf("%d,", *(x + i));
    }
    printf("%d\n", *(x + 49));
 
    return 0;
}

