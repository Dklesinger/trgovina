#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

// Deklaracije funkcija korištenih u main.c
void meni_glavni(void);
void meni_admin(Komponenta** glava);
void meni_korisnik(Komponenta* skladiste);  // Dodaj deklaraciju

int main(void) {
    Komponenta* skladiste = NULL;

    skladiste = ucitaj_komponente_iz_datoteke("komponente.bin");

    meni_glavni();

    oslobodi_komponente(skladiste);
    return 0;
}

void meni_glavni(void) {
    Komponenta* skladiste = NULL;
    int izbor;
    bool kraj = false;

    skladiste = ucitaj_komponente_iz_datoteke("komponente.bin");

    while (!kraj) {
        printf("\n--- Glavni izbornik ---\n");
        printf("1. Administracija\n");
        printf("2. Korisnicki izbornik \n");
        printf("0. Izlaz\n");
        izbor = ucitaj_int("Odaberite opciju: ");

        switch (izbor) {
        case 1:
            meni_admin(&skladiste);
            break;
        case 2:
            meni_korisnik(skladiste);
            break;
        case 0:
            kraj = true;
            break;
        default:
            printf("Nepoznata opcija.\n");
        }
    }

    if (!sacuvaj_komponente_u_datoteku("komponente.bin", skladiste)) {
        printf("Greška pri spremanju komponenti.\n");
    }

    oslobodi_komponente(skladiste);
}

void meni_korisnik(Komponenta* skladiste);
