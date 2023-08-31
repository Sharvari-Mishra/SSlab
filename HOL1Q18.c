#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define RECORD_SIZE 25

// Function to acquire a write lock on a record
void acquire_write_lock(int file_descriptor, int record_number) {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = record_number * RECORD_SIZE;
    lock.l_whence = SEEK_SET;
    lock.l_len = RECORD_SIZE;

    if (fcntl(file_descriptor, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire write lock");
        exit(1);
    }
}

// Function to release a write lock on a record
void release_write_lock(int file_descriptor, int record_number) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_start = record_number * RECORD_SIZE;
    lock.l_whence = SEEK_SET;
    lock.l_len = RECORD_SIZE;

    if (fcntl(file_descriptor, F_SETLK, &lock) == -1) {
        perror("Failed to release write lock");
        exit(1);
    }
}

// Function to acquire a read lock on a record
void acquire_read_lock(int file_descriptor, int record_number) {
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_start = record_number * RECORD_SIZE;
    lock.l_whence = SEEK_SET;
    lock.l_len = RECORD_SIZE;

    if (fcntl(file_descriptor, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire read lock");
        exit(1);
    }
}

// Function to release a read lock on a record
void release_read_lock(int file_descriptor, int record_number) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_start = record_number * RECORD_SIZE;
    lock.l_whence = SEEK_SET;
    lock.l_len = RECORD_SIZE;

    if (fcntl(file_descriptor, F_SETLK, &lock) == -1) {
        perror("Failed to release read lock");
        exit(1);
    }
}

int main() {
    const char *file_name = "dataQ18.txt";
    int file_descriptor;

    // Open the file
    if ((file_descriptor = open(file_name, O_RDWR)) == -1) {
        perror("Failed to open file");
        return 1;
    }

    int record_number;
    printf("Enter the Record Number to be locked:");
    scanf("%d",&record_number);

    // Acquire write lock and update a record
    printf("Accquring Record Write Lock.\n");
    acquire_write_lock(file_descriptor, record_number);
    lseek(file_descriptor, record_number * RECORD_SIZE, SEEK_SET);
    write(file_descriptor, " Given Record Updated.\n", RECORD_SIZE);
    release_write_lock(file_descriptor, record_number);
    printf("Releasing Write Lock on the record.\n");
    printf("\n");

    // Acquire read lock and read a record
    printf("Accquring Record Read Lock.\n");
    acquire_read_lock(file_descriptor, record_number);
    lseek(file_descriptor, record_number * RECORD_SIZE, SEEK_SET);
    char data[RECORD_SIZE + 1];
    read(file_descriptor, data, RECORD_SIZE);
    data[RECORD_SIZE] = '\0';
    release_read_lock(file_descriptor, record_number);
 
    printf("Read data: %s\n", data);
    printf("Releasing Read Lock on the record.\n");
    printf("\n");


    // Close the file
    close(file_descriptor);

    return 0;
}

