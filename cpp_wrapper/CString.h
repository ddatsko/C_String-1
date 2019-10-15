//
// Created by kumquat on 10/15/19.
//

#ifndef UNTITLED1_CSTRING_H
#define UNTITLED1_CSTRING_H


#include <cstdlib>

extern "C" {
#include "library.h"
};

class CString {
private:
    my_str_t str;
public:
    CString(size_t buf_size);

    ~CString();

    int from_cstr(const char *cstr, size_t buf_size);

    size_t size();

    size_t capacity();

    int empty();

    int getc(size_t index);

    int putc(size_t index, char c);

    int pushback(char c);

    int popback();

    int copy(my_str_t *to, int reserve);

    int insert_c(char c, size_t pos);

    int insert(const my_str_t *from, size_t pos);

    int insert_cstr(const char *from, size_t pos);

    int append(const my_str_t *from);

    int append_cstr(const char *from);

    int substr(my_str_t *to, size_t beg, size_t end);

    int substr_cstr(char *to, size_t beg, size_t end);

    int reserve(size_t buf_size);

    int resize(size_t new_size, char sym);

    int shrink_to_fit();

    size_t find(const my_str_t *tofind, size_t from);

    int cmp(const my_str_t *str2);

    int cmp_cstr(const char *cstr2);

    size_t find_c(char tofind, size_t from);

    size_t find_if(int (*predicat)(int));

    int read_file(FILE *file);

    int read();

    int write_file(FILE *file);

    int write();

    int read_file_delim(FILE *file, char delimiter);

};


#endif //UNTITLED1_CSTRING_H
