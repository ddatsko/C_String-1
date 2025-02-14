#include "lib/include/c_string.h"
#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[]) {
    if (argc == 3) {
        FILE *read_file = fopen(argv[1], "r");
        if (read_file == NULL) return 1;
        FILE *write_file = fopen(argv[2], "w");
        if (write_file == NULL) {
            fclose(read_file);
            return 1;
        }

        my_str_t line;
        my_str_create(&line, 360000);
        my_str_read_file(&line, read_file);

//        my_str_sort_words(&line);

        my_str_write_file(&line, write_file);

        my_str_free(&line);
        fclose(read_file);
        fclose(write_file);
    } else {
        printf("! please enter file names in the command row\n");
    }
    return 0;
}

char to_lower(char c) {
//    if (c >= 'A' && c <= 'Z') return (char) c + 'z' - 'a';
    char letters[52] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e',
                        'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j',
                        'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o',
                        'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't',
                        'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};
    for (int i = 0; i < 52; i++)
        if (c == letters[i]) {
            if (i % 2 == 0)
                return letters[++i];
            else
                return letters[i];
        }
    return c;
}

void swap(char *elements, size_t k, size_t t) {
    // helper function to swap two elements within one array
    char tmp = elements[k];
    elements[k] = elements[t];
    elements[t] = tmp;
}

int is_alpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


size_t partition(char *elements, size_t a, size_t b) {
    // partition function for quick sort
    char x = elements[b];
    size_t i = a - 1;

    for (size_t j = a; j < b + 1; j++) {
        if (to_lower(elements[j]) < to_lower(x)) {
            i++;
            swap(elements, i, j);
        }
    }
    swap(elements, i + 1, b);
    return ++i;
}

void quickSort(char *elements, size_t a, size_t b) {
    if (a < b) {
        size_t q = partition(elements, a, b);
        quickSort(elements, a, q - 1);
        quickSort(elements, q + 1, b);
    }
}

void my_str_sort_words(my_str_t *str) {
    size_t n = my_str_size(str);
    size_t word_start = 0;
    int word_end = -1; // no size_t since we need negative value
    for (size_t i = 0; i < n; i++) {
        if (is_alpha(str->data[i]) == 0) {
            word_end++;
        } else {
            quickSort(str->data, word_start, word_end);
            word_start = i + 1;
            word_end = i;
        }
    }
}
