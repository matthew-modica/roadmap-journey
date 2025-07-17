#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *dir = opendir(".");

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    return 0;
}