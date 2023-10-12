#include "semaphore_simple.h"
#include <stdio.h>

// Initialiser le sémaphore
sem_initilise(sem_t *sem, unsigned int value)
{
    if (sem_init(sem, 0, value) == 0)
    {
        return 0; // Succès
    }
    perror("Erreur lors de l'initialisation du sémaphore");
    return -1; // Échec
}

// Opération P
sem_p(sem_t *sem)
{
    if (sem_wait(sem) == 0)
    {
        return 0; // Succès
    }
    perror("Erreur lors de l'opération P sur le sémaphore");
    return -1; // Échec
}

// Opération V
sem_v(sem_t *sem)
{
    if (sem_post(sem) == 0)
    {
        return 0; // Succès
    }
    perror("Erreur lors de l'opération V sur le sémaphore");
    return -1; // Échec
}

// Détruire le sémaphore
sem_destruire(sem_t *sem)
{
    if (sem_destroy(sem) == 0)
    {
        return 0; // Succès
    }
    perror("Erreur lors de la destruction du sémaphore");
    return -1; // Échec
}

int main()
{
    sem_t sem;

    if (sem_initilise(&sem, 1) == 0)
    {
        printf("Sémaphore initialisé avec succès.\n");
    }

    if (sem_p(&sem) == 0)
    {
        printf("Opération P effectuée avec succès.\n");
    }

    if (sem_v(&sem) == 0)
    {
        printf("Opération V effectuée avec succès.\n");
    }

    if (sem_destruire(&sem) == 0)
    {
        printf("Sémaphore détruit avec succès.\n");
    }

    return 0;
}