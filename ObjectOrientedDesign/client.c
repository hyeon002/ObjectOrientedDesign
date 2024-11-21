#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

#define FIFO_PATH "fifo_temp"
#define SEM_NAME "/sem_pp"
#define BUF_SIZE 8
#define TURN 5

int main() {
    const char* msg = "pong\n";
    int fd;
    sem_t* p_sem;
    char buf[BUF_SIZE];

    // �������� ����
    p_sem = sem_open(SEM_NAME, 0);
    if (p_sem == SEM_FAILED) {
        perror("sem_open failed");
        return -1;
    }

    // FIFO ����
    fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    for (int i = 0; i < TURN; i++) {
        sem_wait(p_sem);  // �������� ���
        read(fd, buf, BUF_SIZE);
        printf("Your turn!\n%s", msg);
        write(fd, msg, strlen(msg) + 1);
        sem_post(p_sem);  // �������� ����
        sleep(1);  // ��� ���
    }

    close(fd);
    sem_close(p_sem);
    return 0;
}
