#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(){
    struct gun *arr = NULL;
    int n=0;
    int stop = 0;
    while(stop!=1){
        int key;
        printf("1-create,2-read,3-print,4-search\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                create(&arr,&n);
                if(arr)
                    write(arr,n);
            break;
            case 2:
                read(&arr, &n);
                if(!arr)
                    printf("read eror\n");
                else
                    printf("loaded %d\n", n);
            break;
            case 3:
                for(int i=0;i<n;i++)
                    printf("%s %s %d %s\n", arr[i].name, arr[i].caliber, arr[i].range, arr[i].country);
            break;
            case 4:
                if(arr)
                    search(arr, n);
                else
                    printf("read error\n");
            break;
            default:
                stop=1;
                break;
        }
    }
    if(arr)
        free(arr);
    return 0;
}