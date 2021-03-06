#ifndef SYSTEM_FUNCTION_H
#define SYSTEM_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#define TRUE  1
#define FALSE 0

int create_swap_directory(char *dir_name);
int command_git(char *cmd_exec,char *dir_name);
int init_dir(char *dir_name);
int add_swap_file(char *dir_name);
int commit_swap_file(char *dir_name,char *file_name);
node* show_changes(char *dir_name);

#endif
