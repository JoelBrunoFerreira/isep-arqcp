# Guia de estudo — Ponteiros em C (ARQCP)

Mini-teste 15/10 · escrito em Geany/vim · foco: **escrever funções com ponteiros** e compilar com Makefile.

---

## 0. Os 6 padrões que se repetem (ficha + exame modelo)

| # | Padrão | Onde aparece | Ideia-chave |
|---|--------|--------------|-------------|
| 1 | **Ver um `int` como bytes** | Ficha 1, 8; Exame (`low_pressure`) | `unsigned char *p = (unsigned char *)x;` e percorrer `sizeof(*x)` bytes |
| 2 | **Percorrer array com ponteiro** | Ficha 5, 6, 9, 11, 12 | `while (n--) { ...; p++; }` ou `for (p = v; p < v + n; p++)` |
| 3 | **Percorrer string até `'\0'`** | Ficha 4, 7, 10, 14, 15, 16 | `while (*s != '\0') { ...; s++; }` |
| 4 | **Devolver resultados por parâmetro (output)** | Ficha 9 (`min`,`max`,`avg`) | Receber `int *min` e escrever `*min = ...` |
| 5 | **Filtrar e guardar endereços** | Ficha 21, 22; Exame (`fill`) | Receber `T **out`, escrever `*out = p; out++;` e devolver contagem |
| 6 | **Ponteiro para ponteiro** | Ficha 3, 21, 22 | Para alterar *onde um ponteiro aponta* é preciso `**` |

---

## 1. Fundamentos

```c
int x = 5;
int *p = &x;     // p guarda o ENDEREÇO de x
*p = 10;         // *p = "o valor para onde p aponta" -> x passa a 10
```

- `&x` → endereço de `x`
- `*p` → conteúdo apontado por `p`
- `p` → o endereço que `p` guarda
- `&p` → endereço do próprio `p`
- Imprimir endereço: `printf("%p", (void *)p);`

### Tamanhos (`sizeof`)
```c
int v[4]; int *p = v;
sizeof(v)  // 16  (array inteiro)
sizeof(p)  // 4 ou 8 (tamanho do ponteiro!)
sizeof(*p) // 4  (tamanho de um int)
```
Dentro de uma função, um parâmetro `int *v` **é um ponteiro**: `sizeof(v)` NÃO dá o tamanho do array. Por isso passa-se sempre `n`.

---

## 2. Aritmética de ponteiros

`p + k` avança **k elementos** (não k bytes): o endereço aumenta `k * sizeof(*p)`.

```c
int vec[] = {10, 20, 30, 40};
int *p = vec;       // vec decai para &vec[0]
*(p + 3)  == vec[3] // 40
p[3]      == *(p + 3)
&vec[i]   == vec + i
q - p               // nº de ELEMENTOS entre dois ponteiros (tipo ptrdiff_t, printf "%td")
```

### Precedência — a tabela da ficha 1 (não falhar!)
Assumindo `p = vec` antes de cada linha:

| Expressão | O que faz | Resultado típico |
|-----------|-----------|------------------|
| `a = *p++`   | lê `*p`, **depois** avança o ponteiro | `a=10`, `p` aponta para `vec[1]` |
| `a = (*p)++` | lê o valor, **depois** incrementa o valor | `a=10`, `vec[0]=11`, `p` não mexe |
| `a = *++p`   | avança o ponteiro, **depois** lê | `a=20`, `p` aponta para `vec[1]` |
| `a = ++*p`   | incrementa o valor, depois lê | `a=11`, `vec[0]=11` |

Regra: `*` e `++` (prefixo/sufixo) associam da direita para a esquerda; `(*p)++` mexe no **valor**, `*p++` mexe no **ponteiro**.

---

## 3. Arrays e funções

```c
void f(int *v, int n);    // equivalente a int v[]
f(vec, 4);                // passa &vec[0]
```

### Moldes de ciclos (decorar)
```c
/* A) estilo while com contador */
while (n > 0) {
    /* usar *v */
    v++;
    n--;
}

/* B) estilo for com ponteiro de fim */
int *end = v + n;
for (int *p = v; p < end; p++) {
    /* usar *p */
}
```
> Dica para o teste: declara `int i;` fora do `for` se o Makefile usar `-std=c89`/`-ansi`.

### Exemplos tipo
```c
/* soma dos pares (ficha 6) */
int sum_even(int *vec, int n) {
    int sum = 0;
    while (n > 0) {
        if (*vec % 2 == 0) sum += *vec;
        vec++; n--;
    }
    return sum;
}

/* copiar (ficha 5) */
void copy_vec(int *vec1, int n, int *vec2) {
    while (n > 0) { *vec2 = *vec1; vec1++; vec2++; n--; }
}
```

---

## 4. Strings

- `char s[] = "abc";` → array **modificável** na stack.
- `char *s = "abc";` → literal em memória **só de leitura**; escrever em `*s` dá *segfault*.
- Termina em `'\0'`.

```c
void capitalize(char *str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z')
            *str = *str - 'a' + 'A';   /* ou *str -= 32; */
        str++;
    }
}

char *where_is(char *str, char c) {      /* ficha 10 */
    while (*str != '\0') {
        if (*str == c) return str;        /* devolve o ENDEREÇO */
        str++;
    }
    return NULL;
}
```

### Contar palavras (ficha 14) — padrão "estado"
```c
int count_words(char *str) {
    int count = 0, in_word = 0;
    while (*str != '\0') {
        if (*str != ' ') { if (!in_word) { count++; in_word = 1; } }
        else in_word = 0;
        str++;
    }
    return count;
}
```

### `trim_string` (ficha 15) — padrão "dois ponteiros" (leitura `r` / escrita `w`)
```c
void trim_string(char *str) {
    char *r = str, *w = str;
    while (*r == ' ') r++;                       /* saltar espaços iniciais */
    while (*r != '\0') {
        if (*r != ' ') { *w = *r; w++; r++; }
        else {
            while (*r == ' ') r++;               /* saltar grupo de espaços */
            if (*r != '\0') { *w = ' '; w++; }   /* só 1 espaço, e não no fim */
        }
    }
    *w = '\0';
}
```

---

## 5. Ver um inteiro byte a byte (padrão do exame)

Cast para `unsigned char *` permite aceder a cada byte. **Usar `unsigned`** para evitar extensão de sinal (`0xFA` como `char` é negativo!).

```c
unsigned int d = 0xAABBCCDD;
unsigned char *p = (unsigned char *)&d;
for (unsigned int i = 0; i < sizeof(d); i++)
    printf("%p: %x\n", (void *)(p + i), *(p + i));
```
- RISC-V e x86 são **little-endian**: o byte menos significativo (`0xDD`) fica no endereço mais baixo → imprime `dd cc bb aa`.
- Soma dos bytes (ficha 8): `sum += *(p + i)` → 0xDD+0xCC+0xBB+0xAA = 782.

Alternativa sem cast (máscaras e shifts), independente de endianness:
```c
unsigned int v = *x;
for (int i = 0; i < 4; i++) { unsigned char b = (v >> (8 * i)) & 0xFF; ... }
```

---

## 6. Parâmetros de saída

Para uma função "devolver" vários valores, recebe endereços:
```c
void get_array_statistics(int *vec, int n, int *min, int *max, float *avg) {
    int sum = 0;
    *min = *max = *vec;
    for (int i = 0; i < n; i++, vec++) {
        if (*vec < *min) *min = *vec;
        if (*vec > *max) *max = *vec;
        sum += *vec;
    }
    *avg = (float)sum / n;     /* cast ANTES da divisão! */
}
```
Chamada: `get_array_statistics(v, 5, &mn, &mx, &avg);`

---

## 7. Ponteiros para ponteiros (`**`)

### 7.1 Trocar ponteiros (ficha 3 — o erro clássico)
C passa **por valor**: trocar `char *x, char *y` só troca cópias locais. Para alterar os ponteiros do `main`, recebe o **endereço dos ponteiros**:
```c
void swap_pointers(char **x, char **y) {
    char *tmp = *x;
    *x = *y;
    *y = tmp;
}
/* chamada: swap_pointers(&s1, &s2); */
```
Regra: *para alterar uma variável de tipo T numa função, passa `T *`*. Se T já é `char *`, passa `char **`.

### 7.2 Array de ponteiros (ficha 21, exame `fill`)
```c
int *ptrs[5];            /* array de 5 int*  ->  decai para int ** */
void init_data_ptrs(int *data, int n, int **ptrs) {
    while (n > 0) { *ptrs = data; ptrs++; data++; n--; }
}
```
- `*ptrs = data;` → guarda **endereço** no elemento atual.
- `**ptrs` → o valor `int` apontado.
- Ordenar o array de ponteiros troca **endereços** (os dados originais não se mexem), comparando `**a` com `**b`.

---

## 8. Padrão "filtrar e devolver contagem" (exame modelo)

```c
int check_tires(unsigned int *cars, int n, unsigned int **fill) {
    int count = 0;
    while (n > 0) {
        if (low_pressure(cars)) {
            *fill = cars;     /* guardar o endereço do carro */
            fill++;
            count++;
        }
        cars++;
        n--;
    }
    return count;
}
```
Recuperar o índice a partir do endereço: `fill[i] - cars` (diferença de ponteiros = nº de elementos).

---

## 9. Estrutura de projeto + Makefile (cai no teste!)

Ficheiros: `main.c`, `func1.c`, `func2.c`, `program_functions.h`, `Makefile`.

**Header com include guards:**
```c
#ifndef PROGRAM_FUNCTIONS_H
#define PROGRAM_FUNCTIONS_H
int low_pressure(unsigned int *x);
int check_tires(unsigned int *cars, int n, unsigned int **fill);
#endif
```

**Makefile** (as indentações são **TAB**, não espaços!):
```make
CC = gcc
CFLAGS = -Wall -Wextra -g

all: prog

prog: main.o func1.o func2.o
	$(CC) $(CFLAGS) -o prog main.o func1.o func2.o

main.o: main.c program_functions.h
	$(CC) $(CFLAGS) -c main.c

func1.o: func1.c program_functions.h
	$(CC) $(CFLAGS) -c func1.c

func2.o: func2.c program_functions.h
	$(CC) $(CFLAGS) -c func2.c

clean:
	rm -f *.o prog
```

**Checklist de entrega:** comentário de identificação (`/* nº: nome: turma : version X */`) em TODOS os `.c`/`.h` · `make clean` · zip só com código + Makefile.

---

## 10. Armadilhas comuns

1. **Esquecer `n--`/`p++`** → ciclo infinito.
2. **Escrever num literal** (`char *s = "abc"; *s = 'A';`) → segfault.
3. `sizeof(ptr)` ≠ tamanho do array.
4. `char` com sinal: usar `unsigned char` ao ler bytes.
5. `sum / n` com inteiros → divisão inteira. Usar `(float)sum / n`.
6. Esquecer `*w = '\0';` no fim de uma string reescrita.
7. Devolver o **endereço** (`return str;`) vs o **valor** (`return *str;`).
8. Chaves `{}` não fechadas (compilar com frequência!).
9. Ponteiro não inicializado / `NULL` desreferenciado.
10. Confundir `*p++` com `(*p)++`.

---

## 11. Mini-exercícios de variação (resolver à mão no Geany/vim)

1. Alterar o exame: devolver `1` se **todos** os pneus estão com pressão baixa.
2. Alterar o exame: `fill` guarda endereços de carros com **exatamente** um pneu em baixo.
3. `int count_bytes_equal(unsigned int *x, unsigned char b)` — nº de bytes de `*x` iguais a `b`.
4. `unsigned char *max_byte(unsigned int *x)` — devolve o **endereço** do maior byte.
5. `int check_even_cars(int *v, int n, int **out)` — guarda os endereços dos elementos pares.
6. `void reverse(char *s)` — inverter in place com dois ponteiros (início e fim).
7. `int *find_min(int **ptrs, int n)` — devolve o endereço do menor valor apontado.
8. Ordenar `int **ptrs` por ordem crescente (bubble sort sobre ponteiros).
9. `void swap_arrays(int **a, int **b)` — trocar para onde dois ponteiros apontam.
10. Contar quantos carros têm **todos** os pneus a `0xFF`.

---

## 12. Autoavaliação rápida

- O que imprime `printf("%d", *p++)` com `p = vec`? E `*++p`?
- Porque é que `swap_pointers(char *, char *)` não funciona?
- Qual a diferença entre `fill` e `*fill` e `**fill` no exame?
- Quantos bytes avança `p + 1` se `p` é `unsigned char *`? E `unsigned int *`? E `short *`?
- Porque se usa `unsigned char *` e não `char *` para ler bytes?