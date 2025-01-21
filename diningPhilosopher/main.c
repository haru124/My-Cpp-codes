#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Monitor structure
typedef struct {
    enum { THINKING, HUNGRY, EATING } state[5];
    pthread_mutex_t mutex;
    pthread_cond_t self[5];
} MonitorDP;

MonitorDP dp;

void pickup(int i) {
    pthread_mutex_lock(&dp.mutex);
    dp.state[i] = HUNGRY;
    test(i);
    if (dp.state[i] != EATING) {
        pthread_cond_wait(&dp.self[i], &dp.mutex);
    }
    pthread_mutex_unlock(&dp.mutex);
}

void putdown(int i) {
    pthread_mutex_lock(&dp.mutex);
    dp.state[i] = THINKING;
    test((i + 4) % 5);
    test((i + 1) % 5);
    pthread_mutex_unlock(&dp.mutex);
}

void test(int i) {
    if ((dp.state[(i + 4) % 5] != EATING) &&
        (dp.state[i] == HUNGRY) &&
        (dp.state[(i + 1) % 5] != EATING)) {
        dp.state[i] = EATING;
        pthread_cond_signal(&dp.self[i]);
        printf("\nIn test func dp.self[%d] = %d\n",i,*((int *)dp.self[i]));
    }
}

void *philosopher(void *arg) {
    int i = *((int *)arg);
    int c=0;
    while (c!=10) {
        c++;
        printf("Philosopher %d is thinking\n", i);
        usleep(1000000); // Simulate thinking time

        pickup(i);

        printf("Philosopher %d is eating\n", i);
        usleep(1000000); // Simulate eating time

        putdown(i);
    }
}

int main() {
    pthread_t philosophers[5];
    int ids[5] = {0, 1, 2, 3, 4};

    // Initialize the monitor
    for (int i = 0; i < 5; i++) {
        dp.state[i] = THINKING;
        pthread_cond_init(&dp.self[i], NULL);
    }
    pthread_mutex_init(&dp.mutex, NULL);

    for (int i = 0; i < 5; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(philosophers[i], NULL);
    }

    pthread_mutex_destroy(&dp.mutex);
    for (int i = 0; i < 5; i++) {
        pthread_cond_destroy(&dp.self[i]);
    }

    return 0;
}
