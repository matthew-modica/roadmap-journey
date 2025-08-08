#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <getopt.h>
#include <stdbool.h>

#include "tools.h"

int main(int argc, char *argv[]) {
    struct LsOpts ls_opts;

    int opt;
    while ((opt = getopt(argc, argv, "la")) != -1) {
        switch (opt) {
            case 'l':
                ls_opts.per_line = true;
                break;
            case 'a':
                ls_opts.include_dotfiles = true;
                break;
            default :
                break;
        }
    }

    ls_opts.path = (optind < argc) ? argv[optind] : "."; // Use current directory if none specified
    ls_opts.dir = opendir(ls_opts.path);

    print_ls(&ls_opts);

    return 0;
}

void print_ls(struct LsOpts *ls_opts) {
    struct stat entry_stats;

    while ((ls_opts->entry = readdir(ls_opts->dir)) != NULL) {
        if (!ls_opts->include_dotfiles && ls_opts->entry->d_name[0] == '.') {
            continue;
        }

        if (ls_opts->per_line) {
            if (stat(ls_opts->entry->d_name, &entry_stats) == -1) { // TODO: Can't use d_name here, must be path + d_name
                perror("Error populating stats\n");
            } else {
                printf("%li ", entry_stats.st_size);
            }
            printf("%s\n", ls_opts->entry->d_name);
        } else {
            printf("%s ", ls_opts->entry->d_name);    
        }
    }
    if (!ls_opts->per_line) {
        printf("\n");
    }
}

