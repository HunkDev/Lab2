#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>

void write(struct gun *arr, int n){
    if (n<=0)
        return;
    FILE *f=fopen("file.txt", "w");
    if (!f)
        return;
    fprintf(f, "%d\n", n);
    for(int i=0;i<n;i++)
        fprintf(f, "%s %s %d %s\n", arr[i].name, arr[i].caliber, arr[i].range, arr[i].country);
    fclose(f);
}
void read(struct gun **arr, int *n){
    FILE *f=fopen("file.txt", "r");
    if(!f)
        return;
    if(fscanf(f,"%d", n)!=1)
        return;
    if(*n<=0)
        return;
    *arr=(struct gun *)calloc(*n, sizeof(struct gun));
    for(int i=0;i<*n;i++)
        fscanf(f, "%s %s %d %s",(*arr)[i].name, (*arr)[i].caliber, &((*arr)[i].range), (*arr)[i].country);
        fclose(f);
}
void create(struct gun **arr, int *n){
    printf("n=");
    if(scanf("%d",n)!=1){
        printf("error\n");
        while(getchar() != '\n');
        return;
    }
    if(*n<=0)
        return;
    *arr=(struct gun *)calloc(*n, sizeof(struct gun));
    for(int i=0;i<*n;i++){
        printf("name=");
        scanf("%s", (*arr)[i].name);
        printf("caliber=");
        scanf("%s", (*arr)[i].caliber);
        printf("range=");
        if(scanf("%d", &((*arr)[i].range))!=1){
            printf("error\n");
            while(getchar() != '\n');
            return;
        }
        printf("country=");
        scanf("%s", (*arr)[i].country);
    }
}
void search(struct gun *arr, int n){
    printf("1-name, 2-caliber, 3-range, 4-country\n");
    int key;
    char par[40];
    int r;
    scanf("%d", &key);
    switch(key){
        case 1:
            printf("name=");
            scanf("%41s",par);
            while(getchar() != '\n');
            for(int i=0;i<n;i++){
                if (!strcmp(arr[i].name, par)){
                    printf("%s %s %d %s\n",arr[i].name, arr[i].caliber, arr[i].range, arr[i].country);
                }
            }
        break;
        case 2:
            printf("caliber=");
            scanf("%41s", par);
            while(getchar() != '\n');
            for(int i=0;i<n;i++){
                if (!strcmp(arr[i].caliber, par)){
                    printf("%s %s %d %s\n",arr[i].name, arr[i].caliber, arr[i].range, arr[i].country);
                }
            }
        break;
        case 3:
            printf("range=");
            if(scanf("%d", &r)==1){
                if(r<0){
                    return;
                }  
                for(int i=0;i<r;i++){
                    if(arr[i].range==r){
                        printf("%s %s %d %s\n",arr[i].name, arr[i].caliber, arr[i].range, arr[i].country);
                    }
                        
                }    
            }
            while(getchar() != '\n');
        break;
        case 4:
            printf("country=");
            scanf("%41s", par);
            while(getchar() != '\n');
            for(int i=0;i<n;i++){
                if (!strcmp(arr[i].country, par)){
                    printf("%s %s %d %s\n",arr[i].name, arr[i].caliber, arr[i].range, arr[i].country);
                }
            }
        break;
        default:
            printf("Invalid number\n");
            break;
    }

}