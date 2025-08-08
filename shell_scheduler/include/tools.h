#ifndef TOOLS_H
#define TOOLS_H

#include <stdbool.h>
#include <dirent.h>

struct LsOpts {
    bool per_line;
    bool include_dotfiles;
    char *path;
    struct dirent *entry;
    DIR *dir;
}; 

void print_ls(struct LsOpts *ls_opts);

#endif
