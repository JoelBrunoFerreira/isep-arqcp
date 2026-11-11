/*
 * main.c — Reference template for Dynamic Memory Allocation (DMA) in C
 * Focus: malloc/calloc/realloc/free + structs + matrices (T**) + safe patterns
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // strlen, strcpy, memcpy
#include <stdbool.h>

#define CHECK_ALLOC(ptr) \
    do { if ((ptr) == NULL) { fprintf(stderr, "Allocation failed: %s:%d\n", __FILE__, __LINE__); exit(EXIT_FAILURE);} } while (0)

/* ------------------------------------------------------------
   1) Basic DMA: allocate / use / free
------------------------------------------------------------ */
static void demo_basic_malloc(void) {
    int *p = (int *)malloc(sizeof(int));
    CHECK_ALLOC(p);

    *p = 42;
    printf("[basic] *p = %d\n", *p);

    free(p);
}

/* ------------------------------------------------------------
   2) calloc vs malloc: zero-initialization
------------------------------------------------------------ */
static void demo_calloc_array(void) {
    size_t n = 5;

    int *a = (int *)calloc(n, sizeof(int)); // all zeros
    CHECK_ALLOC(a);

    printf("[calloc] a = ");
    for (size_t i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    free(a);
}

/* ------------------------------------------------------------
   3) Safe realloc pattern (avoid losing the original pointer)
------------------------------------------------------------ */
static void demo_realloc_grow(void) {
    size_t n = 3;
    int *a = (int *)malloc(n * sizeof(int));
    CHECK_ALLOC(a);

    for (size_t i = 0; i < n; i++) a[i] = (int)(i + 1);

    size_t new_n = 6;
    int *tmp = (int *)realloc(a, new_n * sizeof(int));
    if (tmp == NULL) {
        // a is still valid here
        free(a);
        fprintf(stderr, "[realloc] failed\n");
        exit(EXIT_FAILURE);
    }
    a = tmp;

    // initialize the new elements (realloc does NOT zero them)
    for (size_t i = n; i < new_n; i++) a[i] = 0;

    printf("[realloc] a = ");
    for (size_t i = 0; i < new_n; i++) printf("%d ", a[i]);
    printf("\n");

    free(a);
}

/* ------------------------------------------------------------
   4) String duplication: new_str (classic exam function)
   Returns heap string => caller must free()
------------------------------------------------------------ */
static char *new_str(const char *s) {
    if (s == NULL) return NULL;

    size_t len = strlen(s);
    char *copy = (char *)malloc((len + 1) * sizeof(char));
    CHECK_ALLOC(copy);

    strcpy(copy, s); // includes '\0'
    return copy;
}

static void demo_new_str(void) {
    char *x = new_str("Arquitetura de Computadores");
    printf("[new_str] %s\n", x);
    free(x);
}

/* ------------------------------------------------------------
   5) Struct + DMA inside struct (ownership rules)
------------------------------------------------------------ */
typedef struct {
    int id;
    char *name;     // dynamically allocated
} Student;

static Student *student_create(int id, const char *name) {
    Student *s = (Student *)malloc(sizeof(*s));
    CHECK_ALLOC(s);

    s->id = id;
    s->name = new_str(name); // may return NULL if name == NULL (handled)
    CHECK_ALLOC(s->name);

    return s;
}

static void student_destroy(Student *s) {
    if (s == NULL) return;
    free(s->name);
    free(s);
}

static void demo_student(void) {
    Student *a = student_create(1, "Joel");
    printf("[student] id=%d name=%s\n", a->id, a->name);
    student_destroy(a);
}

/* ------------------------------------------------------------
   6) Array of structs (allocated as a block)
------------------------------------------------------------ */
typedef struct {
    unsigned int n_passengers;
    unsigned char n_wheels;
    float fuel_consumption;
} Car;

static Car *cars_create(size_t n) {
    Car *arr = (Car *)calloc(n, sizeof(*arr));
    CHECK_ALLOC(arr);
    return arr;
}

static void cars_destroy(Car *arr) {
    free(arr);
}

static void demo_cars_array(void) {
    size_t n = 3;
    Car *cars = cars_create(n);

    cars[0].n_passengers = 2;
    cars[0].n_wheels = 4;
    cars[0].fuel_consumption = 5.6f;

    printf("[cars] passengers=%u wheels=%u consumption=%.2f\n",
           cars[0].n_passengers,
           (unsigned)cars[0].n_wheels,
           cars[0].fuel_consumption);

    cars_destroy(cars);
}

/* ------------------------------------------------------------
   7) Matrix (T**) allocation and free (row-by-row)
   new_matrix(rows, cols) returns short** and must be freed with free_matrix()
------------------------------------------------------------ */
static short **new_matrix(size_t rows, size_t cols) {
    short **m = (short **)malloc(rows * sizeof(*m));
    CHECK_ALLOC(m);

    for (size_t i = 0; i < rows; i++) {
        m[i] = (short *)calloc(cols, sizeof(**m));
        if (m[i] == NULL) {
            // rollback
            for (size_t k = 0; k < i; k++) free(m[k]);
            free(m);
            fprintf(stderr, "Allocation failed in new_matrix\n");
            exit(EXIT_FAILURE);
        }
    }
    return m;
}

static void free_matrix(short **m, size_t rows) {
    if (m == NULL) return;
    for (size_t i = 0; i < rows; i++) free(m[i]);
    free(m);
}

static bool find_matrix(short **m, size_t rows, size_t cols, short x,
                        size_t *out_i, size_t *out_j) {
    if (m == NULL) return false;

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (m[i][j] == x) {
                if (out_i) *out_i = i;
                if (out_j) *out_j = j;
                return true;
            }
        }
    }
    return false;
}

static void demo_matrix(void) {
    size_t rows = 2, cols = 3;
    short **m = new_matrix(rows, cols);

    m[1][2] = 7;

    size_t i, j;
    if (find_matrix(m, rows, cols, 7, &i, &j)) {
        printf("[matrix] found 7 at (%zu, %zu)\n", i, j);
    } else {
        printf("[matrix] 7 not found\n");
    }

    free_matrix(m, rows);
}

/* ------------------------------------------------------------
   8) Matrix as one contiguous block (fast + simple free)
   Access via m[i][j] using pointer arithmetic.
------------------------------------------------------------ */
static short *new_matrix_contig(size_t rows, size_t cols) {
    short *data = (short *)calloc(rows * cols, sizeof(short));
    CHECK_ALLOC(data);
    return data;
}

static short get_contig(short *data, size_t cols, size_t i, size_t j) {
    return data[i * cols + j];
}

static void set_contig(short *data, size_t cols, size_t i, size_t j, short v) {
    data[i * cols + j] = v;
}

static void demo_matrix_contig(void) {
    size_t rows = 2, cols = 3;
    short *data = new_matrix_contig(rows, cols);

    set_contig(data, cols, 1, 2, 9);
    printf("[matrix_contig] (1,2)=%hd\n", get_contig(data, cols, 1, 2));

    free(data);
}

/* ------------------------------------------------------------
   main: run demos
------------------------------------------------------------ */
int main(void) {
    demo_basic_malloc();
    demo_calloc_array();
    demo_realloc_grow();
    demo_new_str();
    demo_student();
    demo_cars_array();
    demo_matrix();
    demo_matrix_contig();
    return 0;
}
