#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>

#include "tools.h"

#define PATH_PADDING 5

int main(int argc, char *argv[]) {
    struct LsOpts ls_opts;
    struct dirent entry;
    DIR *dir;

    int opt;
    while ((opt = getopt(argc, argv, "la")) != -1) {
        switch (opt) {
            case 'l':
                ls_opts.per_line = true;
                break;
            case 'a':
                ls_opts.include_dotfiles = true;
                break;
            case '?' :
                return EXIT_FAILURE;
        }
    }

    ls_opts.path = (optind < argc) ? argv[optind] : "."; // Use current directory if none specified
    dir = opendir(ls_opts.path);

    print_ls(dir, &entry, &ls_opts);

    return 0;
}

void print_ls(DIR *dir, struct dirent *entry, struct LsOpts *ls_opts) {
    struct stat entry_stats;

    while ((entry = readdir(dir)) != NULL) {
        if (!ls_opts->include_dotfiles && entry->d_name[0] == '.') {
            continue;
        }

        if (ls_opts->per_line) {
            int path_length = strlen(ls_opts->path) + strlen(entry->d_name) + PATH_PADDING;
            char full_path[path_length];
            snprintf(full_path, sizeof(full_path), "%s/%s", ls_opts->path, entry->d_name);

            if (stat(full_path, &entry_stats) == -1) { 
                perror("Error populating stats\n");
            } else {
                printf("%li ", entry_stats.st_size);
            }
            printf("%s\n", entry->d_name);
        } else {
            printf("%s ", entry->d_name);    
        }
    }
    if (!ls_opts->per_line) {
        printf("\n");
    }
}

