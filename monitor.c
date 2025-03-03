#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N 5
enum { THINKING, HUNGRY, EATING } state[N];
pthread_cond_t self[N];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void pickup(int i);
void putdown(int i);
void test(int i);
void* philosopher(void* arg);
int main() {
    pthread_t threads[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        state[i] = THINKING;
        pthread_cond_init(&self[i], NULL);
    }
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
void pickup(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    test(i);
    if (state[i] != EATING) {
        pthread_cond_wait(&self[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}
void putdown(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    test((i + 4) % N);
    test((i + 1) % N);
    pthread_mutex_unlock(&mutex);
}
void test(int i) {
    if (state[(i + 4) % N] != EATING && state[i] == HUNGRY && state[(i + 1) % N] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&self[i]);
    }
}
void* philosopher(void* arg) {
    int i = *((int*)arg);
    while (1) {
        printf("Philosopher %d is thinking.\n", i);
        sleep(1);
        pickup(i);
        printf("Philosopher %d is eating.\n", i);
        sleep(2);
        putdown(i);
    }
    return NULL;
}
