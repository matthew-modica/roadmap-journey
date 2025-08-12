#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    char buffer[BUFSIZ];
    char *file_path;
    ssize_t bytes_read;
    int fd;

    int opt;
    while ((opt = getopt(argc, argv, "")) != -1) {
        //  TODO: Handle options
        break;
    } 

    //  TODO: Handle no path given, '-', '~', etc.
    if (optind >= argc) {
        printf("Missing required argument\n");
        return EXIT_FAILURE;
    }
    file_path = argv[optind];

    if ((fd = open(file_path, O_RDONLY)) == -1) {
        perror(file_path);
        return EXIT_FAILURE;
    }

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Error reading from file\n");
    }

    if (close(fd) == -1) {
        perror("Error closing file\n");
        return EXIT_FAILURE;
    }

    return 0;
}
