//
//  main.c
//  jeux de carte
//
//  Created by Nicolas Garnier on 03/11/2016.
//  Copyright © 2016 Nicolas Garnier. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("========================================================================= \n");
    printf("=====                                                               ===== \n");
    printf("=====                           BLACK JACK                          ===== \n");
    printf("=====                                                               ===== \n");
    printf("========================================================================= \n\n");
    
    char* cartes[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi", "AS"};
    int cartesValeur[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    int nbCartes = sizeof(cartes) / sizeof(char*);
    
// On tire aléatoire 3 cartes pour le croupier et le joueur
    srand(time(NULL));
    int carteJoueur1 = rand() % nbCartes;
    int carteJoueur2 = rand() % nbCartes;
    int carteJoueur3 = rand() % nbCartes;
    int carteCroupier1 = rand() % nbCartes;
    int carteCroupier2 = rand() % nbCartes;
    int totalJoueur = 0;
    int totalCroupier = 0;
    int choix = 1;
    
        printf("==== Joueur 1 ====\n");
        printf("Carte 1: %s\n", cartes[carteJoueur1]);
        printf("Carte 2: %s\n\n", cartes[carteJoueur2]);
        printf("Joueur 1: %d points\n\n", cartesValeur[carteJoueur1]+cartesValeur[carteJoueur2]);
        totalJoueur =cartesValeur[carteJoueur1]+cartesValeur[carteJoueur2];
        
        printf("==== Croupier ====\n");
        printf("Carte 1: %s\n\n", cartes[carteCroupier1]);
        totalCroupier = cartesValeur[carteCroupier1];
        
        //    printf("Carte 2: %s\n\n", cartes[carteCroupier2]);
        
        //    printf("Croupier: %d\n\n", cartesValeur[carteCroupier1]+cartesValeur[carteCroupier2]);
    while (choix == 1) {
        
        printf("Voulez vous tirer une nouvelle cartes ?\n");
        printf("1 - Tirer\n");
        printf("2 - Rester\n");
        scanf("%d", &choix);
        
        printf("-------------------------------------------------------------------------\n\n");

        if (choix == 1) {
            printf("==== Joueur 1 ====\n");
            printf("Carte 1: %s\n", cartes[carteJoueur1]);
            printf("Carte 2: %s\n", cartes[carteJoueur2]);
            printf("Carte 3: %s\n\n", cartes[carteJoueur3]);
            printf("Joueur 1: %d points\n\n", cartesValeur[carteJoueur1]+cartesValeur[carteJoueur2]+cartesValeur[carteJoueur3]);
            totalJoueur = totalJoueur+cartesValeur[carteJoueur3];
            
            printf("==== Croupier ====\n");
            printf("Carte 1: %s\n", cartes[carteCroupier1]);
            printf("Carte 2: %s\n\n", cartes[carteCroupier2]);
            printf("Croupier: %d points\n\n", cartesValeur[carteCroupier1]+cartesValeur[carteCroupier2]);
            totalCroupier = totalCroupier+cartesValeur[carteCroupier2];

            
            if (totalJoueur > 21) {
                printf("Vous avez perdu !!\n\n");
                
            } else {
                if (totalCroupier > 21) {
                    printf("Vous avez gagné !!\n\n");

                } else {
                    if (totalJoueur > totalCroupier) {
                        printf("Vous avez gagné !!\n\n");

                    } else {
                        printf("Vous avez perdu !!!\n\n");

                    }
                }
            }
        }else {
            if (choix == 2) {
                printf("==== Joueur 1 ====\n");
                printf("Carte 1: %s\n", cartes[carteJoueur1]);
                printf("Carte 2: %s\n", cartes[carteJoueur2]);
                printf("Joueur 1: %d points\n\n", cartesValeur[carteJoueur1]+cartesValeur[carteJoueur2]);
                
                printf("==== Croupier ====\n");
                printf("Carte 1: %s\n", cartes[carteCroupier1]);
                printf("Carte 2: %s\n\n", cartes[carteCroupier2]);
                printf("Croupier: %d points\n\n", cartesValeur[carteCroupier1]+cartesValeur[carteCroupier2]);
                totalCroupier = totalCroupier+cartesValeur[carteCroupier2];
                
                if (totalJoueur > 21) {
                    printf("Vous avez perdu !!\n\n");

                } else {
                    if (totalCroupier > 21) {
                        printf("Vous avez gagné !!\n\n");

                    } else {
                        if (totalJoueur > totalCroupier) {
                            printf("Vous avez gagné !!\n\n");

                        } else {
                            printf("Vous avez perdu !!!\n\n");

                        }
                    }
                }
                
                
            }
        }
    }
}
