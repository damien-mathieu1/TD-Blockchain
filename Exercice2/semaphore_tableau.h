#ifndef _SEM_TAB_
#define _SEM_TAB_
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
int semtab_init(int *semid, key_t key, unsigned int value); // : Initialise un sé
int semtab_p(int semid);                                    // : Effectue l'opération P (wait) sur le sémaphore (d'
int semtab_v(int semid);                                    // : Effectue l'opération V (signal) sur le sémaphore (
int semtab_p_n(int semid, int n);                           // : Effectue l'opération P (wait) sur le sémap
int semtab_v_n(int semid, int n);                           // : Effectue l'opération V (signal) sur le sé
int semtab_destroy(int semid);                              // : Détruit un sémaphore.
#endif