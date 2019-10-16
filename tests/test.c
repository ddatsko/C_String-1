#include "test.h"
#include "../lib/include/c_string.h"
#include <ctype.h>

int tests(void) {
    if (test_my_str_create()) printf("fail test 1\n");
    if (test_my_str_from_cstr()) printf("fail test 2\n");
    if (test_my_str_size()) printf("fail test 3\n");
    if (test_my_str_capacity()) printf("fail test 4\n");
    if (test_my_str_empty()) printf("fail test 5\n");
    if (test_my_str_getc()) printf("fail test 6\n");
    if (test_my_str_putc()) printf("fail test 7\n");
    if (test_my_str_get_cstr()) printf("fail test 8\n");
    if (test_my_str_pushback()) printf("fail test 9\n");
    if (test_my_str_popback()) printf("fail test 10\n");
    if (test_my_str_copy()) printf("fail test 11\n");
    if (test_my_str_insert_c()) printf("fail test 13\n");
    if (test_my_str_insert()) printf("fail test 14\n");
    if (test_my_str_insert_cstr()) printf("fail test 15\n");
    if (test_my_str_append()) printf("fail test 16\n");
    if (test_my_str_append_cstr()) printf("fail test 17\n");
    if (test_my_str_substr()) printf("fail test 18\n");
    if (test_my_str_substr_cstr()) printf("fail test 19\n");
    if (test_my_str_reserve()) printf("fail test 20\n");
//    if (test_my_str_shrink_to_fit()) printf("fail test 21\n");
//    if (test_my_str_resize()) printf("fail test 22\n");
//    if (test_my_str_cmp()) printf("fail test 23\n");
//    if (test_my_str_cmp_cstr()) printf("fail test 24\n");
//    if (test_my_str_find_c()) printf("fail test 25\n");
//    if (test_my_str_find_if()) printf("fail test 26\n");
//    if (test_my_str_read_file()) printf("fail test 27\n");
//    if (test_my_str_read()) printf("fail test 28\n");
//    if (test_my_str_write_file()) printf("fail test 29\n");
//    if (test_my_str_write()) printf("fail test 30\n");
//    if (test_my_str_read_file_delim()) printf("fail test 31\n");
    return 0;
}

int test_my_str_create() {
    my_str_t str;
    my_str_create(&str, 1);
    if (!my_str_create(NULL, 0)) return -1;
    if (str.data == NULL) return -1;
    my_str_free(&str);
    return 0;
}

int test_my_str_from_cstr() {
    my_str_t str;
    my_str_create(&str, 0);
    char *ccc = "hello my dear";
    my_str_from_cstr(&str, ccc, 0);
    for (size_t i = 0; i < str.size_m; i++) {
        if (str.data[i] != ccc[i]) return 1;
    }
    if (str.size_m != 13) return 1;
    if (str.capacity_m != str.size_m + 1) return 1;

    my_str_free(&str);
    return 0;
}

int test_my_str_size() {
    my_str_t str1;
    my_str_create(&str1, 7);
    if (str1.size_m != my_str_size(&str1)) return 1;
    my_str_free(&str1);
    return 0;
}

int test_my_str_capacity() {
    my_str_t str;
    my_str_create(&str, 0);
    char *ccc = "hello";
    my_str_from_cstr(&str, ccc, 0);
    if (str.capacity_m != my_str_capacity(&str)) return 1;
    my_str_free(&str);
    return 0;
}

int test_my_str_empty() {
    my_str_t str;
    my_str_t empty_str;
    my_str_create(&str, 1);
    my_str_create(&empty_str, 1);
    my_str_from_cstr(&str, "hello", 0);
    if (!my_str_empty(&empty_str)) return -1;
    if (my_str_empty(&str)) return -1;
    my_str_free(&str);
    my_str_free(&empty_str);
    return 0;
}

int test_my_str_getc() {
    my_str_t str;
    my_str_create(&str, 1);
    my_str_from_cstr(&str, "hello world", 0);
    if (my_str_getc(&str, 0) != 'h') return 1;
    if (my_str_getc(&str, 6) != 'w') return 1;
    if (my_str_getc(&str, 10) != 'd') return 1;
    if (!my_str_getc(&str, -45)) return 1;
    if (!my_str_getc(&str, 12)) return 1;
    my_str_free(&str);
    return 0;
}

int test_my_str_putc() {
    my_str_t str;
    my_str_create(&str, 1);
    my_str_from_cstr(&str, "hello my dear friend", 0);
    my_str_putc(&str, 0, 'p');
    my_str_putc(&str, str.size_m - 1, 'a');
    if (str.data[0] != 'p') return 1;
    if (str.data[str.size_m - 1] != 'a') return 1;
    if (!my_str_putc(&str, -1, 'a')) return 1;
    if (!my_str_putc(&str, str.size_m, 'a')) return 1;
    my_str_free(&str);
    return 0;
}

int test_my_str_get_cstr() {
    char* sample = "hello world";
    my_str_t str;
    my_str_create(&str, 1);
    my_str_from_cstr(&str, sample, 0);
    const char* res =  my_str_get_cstr(&str);

    if (char_arr_len(res) != char_arr_len(sample)) return -1;

    for (size_t i = 0; i < char_arr_len(res); ++i)
        if (res[i] != sample[i]) return -1;
    return 0;
}

int test_my_str_pushback() {
    my_str_t str;
    my_str_create(&str, 1);
    my_str_from_cstr(&str, "hello world", 0);
    my_str_pushback(&str, ' ');
    my_str_pushback(&str, 'n');
    my_str_pushback(&str, 'o');
    if (str.data[str.size_m - 1] != 'o') return -1;
    my_str_free(&str);
    return 0;
}

int test_my_str_popback() {
    my_str_t str;
    my_str_create(&str, 1);
    if (!my_str_popback(&str)) return -1;
    my_str_from_cstr(&str, "hello world", 0);
    int c = my_str_popback(&str);
    if (str.data[str.size_m - 1] != 'l') return -1;
    if (c != 'd') return -1;
    my_str_free(&str);
    return 0;
}

int test_my_str_copy() {
    my_str_t str1;
    my_str_t str2;
    my_str_create(&str1, 1);
    my_str_create(&str2, 1);
    my_str_from_cstr(&str1, "hello world", 0);
    my_str_copy(&str1, &str2, 1);
    if (str2.data[str2.size_m - 1] != 'd') return -1;
    my_str_free(&str1);
    my_str_free(&str2);
    return 0;
}

int test_my_str_insert_c() {
    my_str_t str;
    my_str_create(&str, 1);
    my_str_from_cstr(&str, "hello world", 0);
    my_str_insert_c(&str, 'A', 0);
    if (str.data[0] != 'A') return -1;
    my_str_insert_c(&str, 'A', str.size_m);
    if (str.data[str.size_m - 1] != 'A') return -1;
    my_str_insert_c(&str, 'A', 4);
    if (str.data[4] != 'A') return -1;
    my_str_free(&str);
    return 0;
}

int test_my_str_insert() {
    my_str_t str1;
    my_str_t str2;
    my_str_create(&str1, 1);
    my_str_create(&str2, 1);
    my_str_from_cstr(&str1, "hello", 0);
    my_str_from_cstr(&str2, " world", 0);
    my_str_insert(&str1, &str2, str1.size_m);
    if (str2.data[str2.size_m - 1] != 'd') return -1;
    my_str_insert(&str1, &str2, 0);
    if (!isspace(str2.data[0])) return -1;
    my_str_free(&str1);
    my_str_free(&str2);
    return 0;
}

int test_my_str_insert_cstr() {
    my_str_t str;
    my_str_create(&str, 0);
    char *c = " world";
    my_str_from_cstr(&str, "hello", 0);
    my_str_insert_cstr(&str, c, str.size_m);
    if (str.data[str.size_m - 1] != 'd') return -1;
    my_str_free(&str);
    return 0;
}

int test_my_str_append() {
    my_str_t str1;
    my_str_t str2;
    my_str_create(&str1, 1);
    my_str_create(&str2, 1);
    my_str_from_cstr(&str1, "hello", 0);
    my_str_from_cstr(&str2, " world", 0);
    my_str_append(&str1, &str2);
    if (str2.data[str2.size_m - 1] != 'd') return -1;
    my_str_free(&str1);
    my_str_free(&str2);
    return 0;
}

int test_my_str_append_cstr() {
    my_str_t str;
    my_str_create(&str, 0);
    char *c = " world";
    my_str_from_cstr(&str, "hello", 0);
    my_str_append_cstr(&str, c);
    if (str.data[str.size_m - 1] != 'd') return -1;
    my_str_free(&str);
    return 0;
}

int test_my_str_substr() {
    my_str_t str1;
    my_str_t str2;
    my_str_create(&str1, 0);
    my_str_create(&str2, 0);
    my_str_from_cstr(&str1, "hello world", 0);
    my_str_substr(&str1, &str2, 0, 5);
    if (str2.data[str2.size_m-1] != 'o') return -1;
    my_str_free(&str1);
    my_str_free(&str2);
    return 0;
}

int test_my_str_substr_cstr() {
    my_str_t str;
    char c[10];
    my_str_create(&str, 1);
    my_str_from_cstr(&str, "hello world", 0);
    my_str_substr_cstr(&str, c, 0, 5);
    if (c[4] != 'o') return -1;
    if (!my_str_substr_cstr(&str, c, -3, 5)) return -1;
    if (my_str_substr_cstr(&str, c, 3, 45)) return -1;
    my_str_free(&str);
    return 0;
}

int test_my_str_reserve() {
    return -1;
}

int test_my_str_shrink_to_fit() {
    return -1;
}

int test_my_str_resize() {
    return -1;
}

int test_my_str_cmp() {
    return -1;
}

int test_my_str_cmp_cstr() {
    return -1;
}

int test_my_str_find_c() {
    return -1;
}

int test_my_str_find_if() {
    return -1;
}

int test_my_str_read_file() {
    return -1;
}

int test_my_str_read() {
    return -1;
}

int test_my_str_write_file() {
    return -1;
}

int test_my_str_write() {
    return -1;
}

int test_my_str_read_file_delim() {
    return -1;
}
