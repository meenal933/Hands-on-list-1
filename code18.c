/*
 QUE_18
Author: Meenal Hirwani
Description: Write a program to perform Record locking.
a).Implement write lock
b).Implement read lock 
 Create three records in a file. whenever you access a particular record, first lock it then modify/access to avoid race condition.

Date: August 21 , 2025
 
=======================================================================================================================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_RECORDS 3
#define RECORD_SIZE sizeof(struct record)

struct record {
    int id;
    char name[50];
};

// Function to write a record to the file
void write_record(int fd, int record_num, struct record *rec) {
    off_t offset = record_num * RECORD_SIZE;
    lseek(fd, offset, SEEK_SET);
    write(fd, rec, RECORD_SIZE);
}

// Function to read a record from the file
void read_record(int fd, int record_num, struct record *rec) {
    off_t offset = record_num * RECORD_SIZE;
    lseek(fd, offset, SEEK_SET);
    read(fd, rec, RECORD_SIZE);
}

// Function to apply a write lock
void write_lock(int fd, int record_num) {
    struct flock lock;
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error applying write lock");
        exit(EXIT_FAILURE);
    }
}

// Function to apply a read lock
void read_lock(int fd, int record_num) {
    struct flock lock;
    lock.l_type = F_RDLCK;  // Read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error applying read lock");
        exit(EXIT_FAILURE);
    }
}

// Function to release the lock
void release_lock(int fd, int record_num) {
    struct flock lock;
    lock.l_type = F_UNLCK;  // Unlock
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error releasing lock");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int fd;
    struct record records[MAX_RECORDS] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    // Open the file to read and write (create it if it doesn't exist)
    fd = open("records.dat", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Initialize file with records (Write records to file initially)
    for (int i = 0; i < MAX_RECORDS; i++) {
        write_record(fd, i, &records[i]);
    }

    // Reading and writing operations with locking
    printf("Reading Record 1 (Read Lock)\n");
    read_lock(fd, 0);  // Apply read lock on record 0
    struct record rec;
    read_record(fd, 0, &rec);
    printf("Record: ID=%d, Name=%s\n", rec.id, rec.name);
    release_lock(fd, 0);  // Release the lock

    printf("\nWriting to Record 2 (Write Lock)\n");
    struct record new_record = {2, "Updated Bob"};
    write_lock(fd, 1);  // Apply write lock on record 1
    write_record(fd, 1, &new_record);
    release_lock(fd, 1);  // Release the lock

    printf("\nReading Record 2 (Read Lock)\n");
    read_lock(fd, 1);  // Apply read lock on record 1
    read_record(fd, 1, &rec);
    printf("Record: ID=%d, Name=%s\n", rec.id, rec.name);
    release_lock(fd, 1);  // Release the lock

    // Clean up and close the file
    close(fd);

    return 0;
}


/*
 OUTPUT
 Reading Record 1 (Read Lock)
 Record: ID=1, Name=Alice

 Writing to Record 2 (Write Lock)

 Reading Record 2 (Read Lock)
 Record: ID=2, Name=Updated Bob

 
 */
