#ifndef SEMAPHORE_SIMPLE_H
#define SEMAPHORE_SIMPLE_H
#include <semaphore.h>

int sem_initilise(sem_t *sem, unsigned int value);
int sem_p(sem_t *sem);
int sem_v(sem_t *sem);
int sem_destruire(sem_t *sem);

#endif // SEMAPHORE_SIMPLE_H