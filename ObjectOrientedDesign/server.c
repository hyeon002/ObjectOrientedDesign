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
    const char* msg = "ping\n";
    int fd;
    int score = 100;
    sem_t* p_sem;
    char buf[BUF_SIZE];

    // �������� �ʱ�ȭ
    p_sem = sem_open(SEM_NAME, O_CREAT, 0644, 1);
    if (p_sem == SEM_FAILED) {
        perror("sem_open failed");
        return -1;
    }

    // FIFO ���� �� ����
    mkfifo(FIFO_PATH, 0666);
    fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    for (int i = 0; i < TURN; i++) {
        sem_wait(p_sem);  // �������� ���
        printf("Your turn!\n%s", msg);
        write(fd, msg, strlen(msg) + 1);

        // Ŭ���̾�Ʈ�� ������ ��ٸ�
        sem_post(p_sem);  // �������� ����
        sleep(1);  // ��� ���
    }

    close(fd);
    sem_close(p_sem);
    sem_unlink(SEM_NAME);
    unlink(FIFO_PATH);
    printf("Done! Your score: %d\n", score);
    return 0;
}
