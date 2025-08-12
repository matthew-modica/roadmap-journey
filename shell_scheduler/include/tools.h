#ifndef TOOLS_H
#define TOOLS_H

#include <stdbool.h>
#include <dirent.h>

// TODO: Only include actual ls options
struct LsOpts {
    bool per_line;
    bool include_dotfiles;
    char *path;
}; 

void print_ls(DIR *dir, struct dirent *entry, struct LsOpts *ls_opts);
void print_cat(char *file_name, int fd);

#endif
