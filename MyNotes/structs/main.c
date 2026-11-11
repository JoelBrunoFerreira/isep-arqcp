#include <stdio.h>
#include <stdlib.h>

/* #1 */
/* Here, we define a single structure in a variable called “c1”. */
struct {
    unsigned char n_wheels;
    unsigned int n_passengers;
    float fuel_consumption;
}c1;

/* #2 */
/* Here, we declare a structure type called “s_car”. */
struct s_car {
    unsigned char n_wheels;
    unsigned int n_passengers;
    float fuel_consumption;
};

/* #3 */
/* Here, we declare a new data type called “t_car” using the keyword “typedef”. */
typedef struct { /* we can also write ’ typedef struct s_car ’ */
    unsigned char n_wheels;
    unsigned int n_passengers;
    float fuel_consumption;
} t_car; /* this is the name of the structure data type */

/* #4 */
/* Structs aninhadas (nested structs) - uma struct pode conter outra struct */
typedef struct {
    int day;
    int month;
    int year;
} t_date;

typedef struct {
    char plate[9];     /* 8 caracteres + '\0' (terminador de string) */
    t_car specs;      /* struct dentro de outra struct */
    t_date last_review;
} t_car_full;

/* #5 */
/* Funcoes com structs: por valor (copia) vs por referencia (ponteiro) */

/* Passagem por VALOR: recebe uma COPIA da struct.
 * Qualquer alteracao aqui dentro NAO afeta a struct original. */
void tentarAlterarPorValor(t_car car) {
    car.n_passengers = 99; /* so altera a copia local */
    printf("(dentro da funcao, copia local) passengers = %u\n", car.n_passengers);
}

/* Passagem por REFERENCIA (ponteiro): recebe o ENDERECO da struct.
 * As alteracoes afetam diretamente a struct original. */
void alterarPorPonteiro(t_car *car) {
    car->n_passengers = 99; /* equivalente a (*car).n_passengers = 99; */
}

/* Devolver uma struct por valor tambem e' possivel (o compilador copia-a) */
t_car criarCarro(unsigned char wheels, unsigned int passengers, float fuel) {
    t_car novo;
    novo.n_wheels = wheels;
    novo.n_passengers = passengers;
    novo.fuel_consumption = fuel;
    return novo;
}



int main(void) {
    /* #1 */
    /* Initialize and access the structure members */
    c1.n_wheels = 4;
    c1.n_passengers = 5;
    c1.fuel_consumption = 8.5f;
    printf("================================\n");
    printf("Car 1\n");
    printf("Number of wheels: %u\n", c1.n_wheels);
    printf("Number of passengers: %u\n", c1.n_passengers);
    printf("Fuel consumption: %.2f L/100km\n", c1.fuel_consumption);

    /* NOTE:
    * The structure has only one instantiation (in c1); no other instantiations of the
structure exist.
    */

    printf("================================\n");

    /* #2 */
    /* Define two structures of type s_car */
    struct s_car c2 = {4, 5, 8.5f};
    struct s_car c3 = {4, 2, 12.0f};
    // OR
    // struct s_car c2, c3;
    // c2.n_wheels = 4;
    // c2.n_passengers = 5;
    // c2.fuel_consumption = 8.5f;
    // c3.n_wheels = 2;
    // c3.n_passengers = 2;
    // c3.fuel_consumption = 12.0f;

    printf("Car 2 - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n", c2.n_wheels, c2.n_passengers, c2.fuel_consumption);
    printf("Car 3 - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n", c3.n_wheels, c3.n_passengers, c3.fuel_consumption);

    /* NOTE:
    To instantiate the s_car structure, we define new variables using the name of the
structure after the keyword struct.
    */

    printf("================================\n");

    /* #3 */
    /* Define two structures of type t_car */
    t_car c4 = {4, 5, 8.5f};
    t_car c5 = {4, 2, 12.0f};
    // OR
    // t_car c4, c5;
    // c4.n_wheels = 4;
    // c4.n_passengers = 5;
    // c4.fuel_consumption = 8.5f;
    // c5.n_wheels = 2;
    // c5.n_passengers = 2;
    // c5.fuel_consumption = 12.0f;

    printf("Car 4 - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n", c4.n_wheels, c4.n_passengers, c4.fuel_consumption);
    printf("Car 5 - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n", c5.n_wheels, c5.n_passengers, c5.fuel_consumption);

    /* NOTE:
    To instantiate the t_car structure, we can directly use the name of the structure as a
data type without the keyword struct.
    */

    printf("================================\n");
    printf("Structures and pointers\n");
    printf("================================\n");

    /* Initialize pointers */
    struct s_car *pt_scar; /* pointer to structure of type s_car */
    t_car *pt_tcar;       /* pointer to structure of type t_car */
    /* Point to the structures */
    pt_scar = &c2;
    pt_tcar = &c4;
    // OR
    // struct s_car *pt_scar = &c2;
    // t_car *pt_tcar = &c4;

    /* init and access the data in c2 using the pointer */
    pt_scar->n_wheels = 4;
    pt_scar->n_passengers = 2;
    pt_scar->fuel_consumption = 12.5f;
    printf("Using pointer to s_car - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n", pt_scar->n_wheels, pt_scar->n_passengers, pt_scar->fuel_consumption);

    /* init and access the data in c4 using the pointer */
    pt_tcar->n_wheels = 4;
    pt_tcar->n_passengers = 4;
    pt_tcar->fuel_consumption = 9.5f;
    printf("Using pointer to t_car - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n", pt_tcar->n_wheels, pt_tcar->n_passengers, pt_tcar->fuel_consumption);
    printf("================================\n");



    printf("================================\n");
    printf("#4 Arrays de structs\n");
    /* Um array de structs funciona como qualquer array, mas cada
     * elemento e' uma struct completa. Muito comum em exames para
     * representar "uma frota de carros", "uma turma de alunos", etc. */
    t_car frota[3] = {
        {4, 5, 8.5f},
        {4, 2, 12.0f},
        {6, 8, 15.0f}
    };
    for (int i = 0; i < 3; i++) {
        printf("Carro %d - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n",
               i, frota[i].n_wheels, frota[i].n_passengers, frota[i].fuel_consumption);
    }

    /* Percorrer o array de structs com ponteiro (equivalente a frota[i]) */
    printf("Percorrer a frota com ponteiro:\n");
    t_car *pFrota = frota;
    for (int i = 0; i < 3; i++) {
        printf("Carro %d via ponteiro - Passengers: %u\n", i, (pFrota + i)->n_passengers);
    }

    printf("================================\n");
    printf("#5 Structs aninhadas (nested structs)\n");
    t_car_full carroCompleto;
    /* strcpy seria necessario para strings normalmente, mas aqui usamos
     * inicializacao direta do array de chars para simplificar */
    t_car_full carroCompleto2 = {
        "AA-00-BB",
        {4, 5, 7.2f},
        {15, 3, 2024}
    };
    carroCompleto = carroCompleto2;
    /* Aceder a um campo dentro de uma struct aninhada: usa-se "." em cadeia */
    printf("Matricula: %s\n", carroCompleto.plate);
    printf("Rodas: %u, Passageiros: %u\n", carroCompleto.specs.n_wheels, carroCompleto.specs.n_passengers);
    printf("Ultima revisao: %02d/%02d/%04d\n", carroCompleto.last_review.day, carroCompleto.last_review.month, carroCompleto.last_review.year);

    printf("================================\n");
    printf("#6 Funcoes com structs: por valor vs por ponteiro\n");
    t_car carroTeste = {4, 2, 6.0f};
    printf("Antes de tentarAlterarPorValor: passengers = %u\n", carroTeste.n_passengers);
    tentarAlterarPorValor(carroTeste); /* recebe uma copia */
    printf("Depois de tentarAlterarPorValor: passengers = %u (NAO mudou!)\n", carroTeste.n_passengers);

    alterarPorPonteiro(&carroTeste); /* passa o endereco */
    printf("Depois de alterarPorPonteiro: passengers = %u (mudou!)\n", carroTeste.n_passengers);

    t_car carroNovo = criarCarro(2, 1, 4.0f); /* funcao que devolve uma struct */
    printf("Carro criado pela funcao - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n",
           carroNovo.n_wheels, carroNovo.n_passengers, carroNovo.fuel_consumption);

    printf("================================\n");
    printf("#7 Structs com alocacao dinamica (malloc)\n");
    /* Alocar uma unica struct dinamicamente */
    t_car *carroDinamico = malloc(sizeof(t_car));
    if (carroDinamico == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    carroDinamico->n_wheels = 4;
    carroDinamico->n_passengers = 5;
    carroDinamico->fuel_consumption = 5.5f;
    printf("Carro dinamico - Wheels: %u, Passengers: %u, Fuel Consumption: %.2f L/100km\n",
           carroDinamico->n_wheels, carroDinamico->n_passengers, carroDinamico->fuel_consumption);
    free(carroDinamico); /* IMPORTANTE: libertar sempre a memoria alocada */
    carroDinamico = NULL; /* boa pratica: evita "dangling pointer" */

    /* Alocar um ARRAY de structs dinamicamente (muito comum em exame) */
    int n = 3;
    t_car *frotaDinamica = malloc(n * sizeof(t_car));
    if (frotaDinamica == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        frotaDinamica[i].n_wheels = 4;
        frotaDinamica[i].n_passengers = i + 1;
        frotaDinamica[i].fuel_consumption = 5.0f + i;
    }
    printf("Frota dinamica:\n");
    for (int i = 0; i < n; i++) {
        printf("Carro %d - Passengers: %u, Fuel Consumption: %.2f L/100km\n",
               i, frotaDinamica[i].n_passengers, frotaDinamica[i].fuel_consumption);
    }
    free(frotaDinamica); /* liberta todo o array de uma vez */
    frotaDinamica = NULL;

    printf("================================\n");
    return 0;
}