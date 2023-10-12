#include "semaphore_tableau.h"

// Structure pour l'opération sur le sémaphore
struct sembuf operation;

// Cette fonction initialise un sémaphore avec la clé et la valeur spécifiées
int semtab_init(int *semid, key_t key, unsigned int value)
{
    // Crée un sémaphore avec la clé fournie sous la forme d'un tableau d'un sémaphore
    *semid = semget(key, 1, IPC_CREAT | 0666);
    if (*semid == -1)
    {
        perror("Erreur lors de la création du sémaphore");
        return -1;
    }

    // Initialise le sémaphore à la valeur spécifiée
    if (semctl(*semid, 0, SETVAL, value) == -1)
    {
        perror("Erreur lors de l'initialisation du sémaphore");
        return -1;
    }

    return 0; // Succès
}

// Cette fonction effectue l'opération P sur le sémaphore
int semtab_p(int semid)
{
    operation.sem_num = 0;
    operation.sem_op = -1;
    operation.sem_flg = 0;
    if (semop(semid, &operation, 1) == -1)
    {
        perror("Erreur lors de l'opération P");
        return -1;
    }
    return 0; // Succès
}

// Cette fonction effectue l'opération V sur le sémaphore
int semtab_v(int semid)
{
    operation.sem_num = 0;
    operation.sem_op = 1;
    operation.sem_flg = 0;
    if (semop(semid, &operation, 1) == -1)
    {
        perror("Erreur lors de l'opération V");
        return -1;
    }
    return 0; // Succès
}

// Cette fonction effectue l'opération P sur le sémaphore n fois
int semtab_p_n(int semid, int n)
{
    operation.sem_num = 0;
    operation.sem_op = -n;
    operation.sem_flg = 0;
    if (semop(semid, &operation, 1) == -1)
    {
        perror("Erreur lors de l'opération P_n");
        return -1;
    }
    return 0; // Succès
}

// Cette fonction effectue l'opération V sur le sémaphore n fois
int semtab_v_n(int semid, int n)
{
    operation.sem_num = 0;
    operation.sem_op = n;
    operation.sem_flg = 0;
    if (semop(semid, &operation, 1) == -1)
    {
        perror("Erreur lors de l'opération V_n");
        return -1;
    }
    return 0; // Succès
}

// Cette fonction détruit un sémaphore
int semtab_destroy(int semid)
{
    if (semctl(semid, 0, IPC_RMID) == -1)
    {
        perror("Erreur lors de la destruction du sémaphore");
        return -1;
    }
    return 0; // Succès
}

int main()
{
    int semid;
    key_t key = 1234; // Une clé arbitraire pour le sémaphore

    // Test d'initialisation du sémaphore
    if (semtab_init(&semid, key, 1) == 0)
    {
        printf("Sémaphore initialisé avec succès.\n");
    }

    // Test de l'opération P
    if (semtab_p(semid) == 0)
    {
        printf("Opération P effectuée avec succès.\n");
    }

    // Test de l'opération V
    if (semtab_v(semid) == 0)
    {
        printf("Opération V effectuée avec succès.\n");
    }

    // Test de l'opération P_n
    if (semtab_p_n(semid, 2) == 0)
    {
        printf("Opération P_n effectuée avec succès.\n");
    }

    // Test de l'opération V_n
    if (semtab_v_n(semid, 2) == 0)
    {
        printf("Opération V_n effectuée avec succès.\n");
    }

    // Test de la destruction du sémaphore

    if (semtab_destroy(semid) == 0)
    {
        printf("Sémaphore détruit avec succès.\n");
    }

    return 0;
}