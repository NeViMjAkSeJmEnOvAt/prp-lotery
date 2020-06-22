/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 22. června 2020, 8:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VELIKOST 49

/*
 * 
 */
void rng(int pole[VELIKOST]){
    int r;
    srand((unsigned)time(NULL));
    for(int y=0;y<VELIKOST;y++){
        for(int i=0;i<VELIKOST;i++){
            r=rand()%50;
            pole[i]= rand()%50;
            if(pole[y]== pole[i] && pole[i] != r){
                pole[i]=r;
            }
            else
              i--;
            r=rand()%50;    
          }
    }
    
}
void vypis(int pole[VELIKOST], int velikost){
    for(int i=0;i<velikost;i++){
        printf("%d ", pole[i]);
    }
    printf("\n");
}
int main(int argc, char** argv) {
    int pole[VELIKOST];
    int velikost = 50;
    int pocetZnaku;
    int i=0;
    rng(pole);
    printf("Zadej pocet cisel, ktera budou vylosovana: ");
    do{
        scanf("%d", &velikost);
        pocetZnaku=0;
        while(getchar()!='\n'){
            pocetZnaku++;
        }
        if(pocetZnaku > 0){
            printf("Zadejte prosim cele cislo: ");
        }
        else if(velikost<0){
            printf("Zadejte prosim cele kladne cislo: ");
        }
        else if(velikost == 0){
            printf("Zadejte prosim cele cislo(ne nulu): ");
        }
        else if(velikost > VELIKOST){
            printf("Cislo je prilis velke!:");
        }
        else{
            vypis(pole, velikost);
            return (EXIT_SUCCESS);
        }
            
    }while(pocetZnaku > 0 || velikost<0 || velikost != 0 || velikost < VELIKOST );

    
    return (EXIT_SUCCESS);
}

