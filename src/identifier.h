# include <stdio.h>
# include <stdbool.h>
# include <string.h>

# pragma once

void initialize_identifier_list();
void add_identifier(char* name);
bool check_identifier_exist(char* name);
int get_identifier_number(char* name);