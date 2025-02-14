#include <stdlib.h>
#include <stdio.h>


#ifndef CSTRING_LIBRARY_H
#define CSTRING_LIBRARY_H


typedef struct {
    size_t capacity_m; // Block size
    size_t size_m;     // Actual size of the string
    char *data;       // Pointer on data block
} my_str_t;

int my_str_create(my_str_t *str, size_t buf_size);

void my_str_free(my_str_t *str);

int my_str_from_cstr(my_str_t *str, const char *cstr, size_t buf_size);

size_t my_str_size(const my_str_t *str);

size_t my_str_capacity(const my_str_t *str);

int my_str_empty(const my_str_t *str);

int my_str_getc(const my_str_t *str, size_t index);

int my_str_putc(my_str_t *str, size_t index, char c);

const char *my_str_get_cstr(my_str_t *str);

int my_str_pushback(my_str_t *str, char c);

int my_str_popback(my_str_t *str);

int my_str_copy(const my_str_t *from, my_str_t *to, int reserve);

void my_str_clear(my_str_t *str);

int my_str_insert_c(my_str_t *str, char c, size_t pos);

int my_str_insert(my_str_t *str, const my_str_t *from, size_t pos);

int my_str_insert_cstr(my_str_t *str, const char *from, size_t pos);

int my_str_append(my_str_t *str, const my_str_t *from);

int my_str_append_cstr(my_str_t *str, const char *from);

int my_str_substr(const my_str_t *from, my_str_t *to, size_t beg, size_t end);

int my_str_substr_cstr(const my_str_t *from, char *to, size_t beg, size_t end);

int my_str_reserve(my_str_t *str, size_t buf_size);

int my_str_shrink_to_fit(my_str_t *str);

int my_str_resize(my_str_t *str, size_t new_size, char sym);

size_t my_str_find(const my_str_t *str, const my_str_t *tofind, size_t from);

int my_str_cmp(const my_str_t *str1, const my_str_t *str2);

int my_str_cmp_cstr(const my_str_t *str1, const char *cstr2);

size_t my_str_find_c(const my_str_t *str, char tofind, size_t from);

size_t my_str_find_if(const my_str_t *str, int (*predicat)(int));

int my_str_read_file(my_str_t *str, FILE *file);

int my_str_read(my_str_t *str);

int my_str_write_file(const my_str_t *str, FILE *file);

int my_str_write(const my_str_t *str);

int my_str_read_file_delim(my_str_t *str, FILE *file, char delimiter);


/*******************HELPER_FUNCTIONS**********************************/
int my_str_realloc(my_str_t *str, size_t buffer);

void char_arr_copy(const char *arr, size_t to_index, char *arr_copy);

size_t char_arr_len(const char *s);

static int check_borders(const my_str_t *str, size_t beg, size_t *end);
/*********************************************************************/
#endif //CSTRING_LIBRARY_H