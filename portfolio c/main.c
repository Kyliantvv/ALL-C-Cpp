#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVRES 100 // Défini le max de livres

struct Livre {
    char titre[50];
    char auteur[50];
    int annee;
    char avis[100];
};

void ajouterLivre(struct Livre *bibliotheque, int *nombreLivres) {  // ajouter un livre
    if (*nombreLivres < MAX_LIVRES) {
        printf("Titre du livre : ");
        scanf(" %[^\n]s", bibliotheque[*nombreLivres].titre);
        printf("Auteur du livre : ");
        scanf(" %[^\n]s", bibliotheque[*nombreLivres].auteur);
        printf("Année de publication : ");
        scanf("%d", &bibliotheque[*nombreLivres].annee);
        printf("Ton avis sur le livre : ");
        scanf(" %[^\n]s", bibliotheque[*nombreLivres].avis);

        (*nombreLivres)++;
        printf("Livre ajouté avec succès.\n");
    } else {
        printf("La bibliothèque est pleine. Impossible d'ajouter un nouveau livre.\n");
    }
}

void afficherBibliotheque(struct Livre *bibliotheque, int nombreLivres) {  // afficher la bibliothèque
    printf("\nBibliothèque:\n");
    for (int i = 0; i < nombreLivres; i++) {
        printf("\nLivre #%d\n", i + 1);
        printf("Titre : %s\n", bibliotheque[i].titre);
        printf("Auteur : %s\n", bibliotheque[i].auteur);
        printf("Année : %d\n", bibliotheque[i].annee);
        printf("Avis : %s\n", bibliotheque[i].avis);
    }
}

void sauvegarderBibliotheque(struct Livre *bibliotheque, int nombreLivres) { // save la bibliothèque
    FILE *fichier = fopen("bibliotheque.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < nombreLivres; i++) {
        fprintf(fichier, "%s|%s|%d|%s\n", bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].annee, bibliotheque[i].avis);
    }

    fclose(fichier);
    printf("Bibliothèque sauvegardée dans le fichier.\n");
}

int main(void) {                                    //afficher le menu
    struct Livre bibliotheque[MAX_LIVRES];
    int nombreLivres = 0;

    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher la bibliothèque\n");
        printf("3. Sauvegarder la bibliothèque\n");
        printf("4. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterLivre(bibliotheque, &nombreLivres);
                break;
            case 2:
                afficherBibliotheque(bibliotheque, nombreLivres);
                break;
            case 3:
                sauvegarderBibliotheque(bibliotheque, nombreLivres);
                break;
            case 4:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
        }

    } while (choix != 4);   // continue tant qu'on a pas entrer 4

    return 0;
}
