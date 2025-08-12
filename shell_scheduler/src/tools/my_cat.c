#include "tools.h"
#include <bits/getopt_core.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
    char *file_path;
    int fd;

    int opt;
    while ((opt = getopt(argc, argv, "")) != -1) {
        //  TODO: Handle options
        break;
    } 

    //  BUG: Does not allow '-' followed by another argument
    if (optind >= argc || strcmp("-", argv[optind]) == 0){
        file_path = "STDIN";
        fd = STDIN_FILENO;
        print_cat(file_path, fd);
    } else {
        for (int i = optind; i < argc; i++) {
            file_path = argv[i];
            if ((fd = open(file_path, O_RDONLY)) == -1) {
                perror(file_path);
                return EXIT_FAILURE;
            }
            print_cat(file_path, fd);
        }
    }

    return 0;
}

//  TODO: Get fd in function, use "" for STDIN file_path?
void print_cat(char *file_path, int fd) {
    char buffer[BUFSIZ];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);

        if (bytes_read == -1) {
            int e = errno;
            fprintf(stderr, "Error reading from file %s : %s", file_path, strerror(e));
        }
        if (fd != STDIN_FILENO && close(fd) == -1) {
            int e = errno;
            fprintf(stderr, "Error closing file %s : %s", file_path, strerror(e));
            exit(EXIT_FAILURE);
        }
    }
    printf("\n");
}
