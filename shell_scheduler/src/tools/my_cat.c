#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

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
    for (int i = optind; i < argc; i++) {
        file_path = argv[i];
        if ((fd = open(file_path, O_RDONLY)) == -1) {
            perror(file_path);
            return EXIT_FAILURE;
        }

        while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytes_read);
        }

        if (bytes_read == -1) {
            int e = errno;
            fprintf(stderr, "Error reading from file %s : %s", file_path, strerror(e));
        }
        if (close(fd) == -1) {
            int e = errno;
            fprintf(stderr, "Error closing file %s : %s", file_path, strerror(e));
            return EXIT_FAILURE;
        }
    }
    printf("\n");

    return 0;
}
