#include <stdio.h>

// ---------------------------------------------------------
// Funções com ponteiros (passagem por referência)
// ---------------------------------------------------------

// Troca os valores de duas variáveis usando ponteiros.
// Sem ponteiros, os parâmetros seriam copiados (pass by value)
// e a troca não teria efeito fora da função.
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Duplica cada elemento de um array. Arrays "decaem" para ponteiro
// quando passados como argumento, por isso o tamanho tem de ser
// passado à parte (n).
void duplicarArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] * 2; // equivalente a *(arr + i) = *(arr + i) * 2;
	}
}

// Devolve, via ponteiros de saída, o maior e o menor valor de um array.
void maxMin(int *arr, int n, int *max, int *min) {
	*max = arr[0];
	*min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > *max) *max = arr[i];
		if (arr[i] < *min) *min = arr[i];
	}
}

// ATENÇÃO - erro clássico de exame: NUNCA devolver o endereço
// de uma variável local. Quando a função termina, "local" deixa
// de existir e o ponteiro fica "pendurado" (dangling pointer).
int *exemploErrado(void) {
	int local = 42;
	return &local; // ERRADO: comportamento indefinido ao usar depois
}

int main(void) {
	printf("================================\n");
	printf("Pointers in C\n");
	printf("Pointers are variables that store memory addresses of other variables.\n");
	printf("& is the \"address of\" operator\n");
	printf("* is the \"dereference\" operator\n");
	printf("\n");




	printf("================================\n");
	printf("Changing values through pointers\n");
	int a = 5;
	int *ptr = &a;
	printf("Value of a: %d\n", *ptr);
	//printf("Address of a: %p\n", (void*)&a);
	printf("Address of a: %p\n", &a);
	// printf("Address stored in ptr: %p\n", (void*)ptr);
	printf("Address stored in ptr: %p\n", ptr);

	a  = 10;
	printf("New value of a: %d\n", *ptr);




	printf("================================\n");
	printf("Changing values without pointers\n");
	// It is possible to change the value of a variable without using pointers
	int b = 20;
	printf("Value of b: %d\n", b);
	b = 30;
	printf("New value of b: %d\n", b);



	printf("================================\n");
	printf("Changing values with arrays\n");
	// But with arrays, pointers are necessary to change values
	int arr[3] = {1, 2, 3};
	printf("Original arr[0]: %d\n", arr[0]);
	int *arrPtr = arr; // arr decays to &arr[0]
	*(arrPtr + 0) = 10; // Change arr[0] to 10
	printf("Modified arr[0]: %d\n", arr[0]);
	*(arrPtr + 1) = 20; // Change arr[1] to 20
	printf("Modified arr[1]: %d\n", arr[1]);
	*(arrPtr + 2) = 30; // Change arr[2] to 30
	printf("Modified arr[2]: %d\n", arr[2]);



	printf("================================\n");
	printf("Changing values with strings\n");
	// And with strings too
	char str[] = "Hello";
	printf("Original str: %s\n", str);
	char *strPtr = str; // str decays to &str[0]
	*(strPtr + 0) = 'h'; // Change 'H' to 'h'
	printf("Modified str: %s\n", str);



	printf("================================\n");
    printf("Double pointers (pointer to pointer)\n");
    // Exemplo do exame:
    // int a = 10;
    // int *p = &a;
    // int **q = &p; Representa um ponteiro para um ponteiro, ou seja, q aponta para p, que por sua vez aponta para a.
    // A instrução **q = **q * 2; altera o valor apontado por p (i.e., altera a).
    int a2 = 10;
    int *p = &a2;
    int **q = &p;
    printf("Initial a2: %d\n", a2);
    printf("Value via p: %d\n", *p);
    printf("Value via q: %d\n", **q);
    printf("Addresses: &a2=%p, p=%p, &p=%p, q=%p\n", (void*)&a2, (void*)p, (void*)&p, (void*)q);

    // Multiplica o valor apontado por p através de q (pointer to pointer)
    **q = **q * 2;
    printf("After **q = **q * 2;\n");
    printf("a2: %d\n", a2);
    printf("Value via p: %d\n", *p);
    printf("Value via q: %d\n", **q);



	printf("================================\n");
	printf("Aritmetica de ponteiros\n");
	// Quando somamos 1 a um ponteiro, ele avança "sizeof(tipo)" bytes,
	// não 1 byte. Isto é o que permite percorrer arrays com ponteiros.
	int nums[5] = {10, 20, 30, 40, 50};
	int *p2 = nums;
	printf("sizeof(int) = %zu bytes\n", sizeof(int));
	printf("p2 aponta para: %d (endereço %p)\n", *p2, (void*)p2);
	p2++; // avança sizeof(int) bytes -> aponta para nums[1]
	printf("Depois de p2++: %d (endereço %p)\n", *p2, (void*)p2);
	p2 += 2; // avança 2 * sizeof(int) bytes -> aponta para nums[3]
	printf("Depois de p2 += 2: %d (endereço %p)\n", *p2, (void*)p2);

	// Percorrer um array só com aritmética de ponteiros (sem [])
	printf("Percorrer array via ponteiro: ");
	int *inicio = nums;
	int *fim = nums + 5; // aponta para "um a seguir ao último" elemento
	while (inicio < fim) {
		printf("%d ", *inicio);
		inicio++;
	}
	printf("\n");

	// Diferença entre dois ponteiros = número de elementos entre eles
	int *pA = &nums[1];
	int *pB = &nums[4];
	printf("pB - pA = %ld elementos de distancia\n", (long)(pB - pA));



	printf("================================\n");
	printf("Funcoes com ponteiros (passagem por referencia)\n");
	int x = 5, y = 10;
	printf("Antes do swap: x=%d, y=%d\n", x, y);
	swap(&x, &y); // passamos os enderecos, nao os valores
	printf("Depois do swap: x=%d, y=%d\n", x, y);

	int valores[4] = {1, 2, 3, 4};
	printf("Array antes de duplicar: ");
	for (int i = 0; i < 4; i++) printf("%d ", valores[i]);
	printf("\n");
	duplicarArray(valores, 4); // o array e' alterado dentro da funcao
	printf("Array depois de duplicar: ");
	for (int i = 0; i < 4; i++) printf("%d ", valores[i]);
	printf("\n");

	int maior, menor;
	maxMin(valores, 4, &maior, &menor);
	printf("Maior: %d, Menor: %d\n", maior, menor);

	return 0;
}