# pragma once
# include <stdlib.h>
# include "identifier.c"
# include "object.c"

Object sapphire_nil;

void initialize_runtime() {
    sapphire_nil.type = nil; // initialize nil object 
    initialize_identifier_list(); // initialize identifier list. 
}