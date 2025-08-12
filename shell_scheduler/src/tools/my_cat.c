#include <stdio.h>
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

    file_path = argv[optind];
    if ((fd = open(file_path, O_RDONLY)) == -1) {
        perror(file_path);
        return 1;
    }

    //  BUG: Must write the exact size of bytes_read, not buffer
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, sizeof(buffer));
    }

    if (bytes_read == -1) {
        perror("Error reading from file");
    }

    if (close(fd) == -1) {
        perror("Error closing file");
    }

    return 0;
}
