# Tipos de Dados em C e a sua Relação com RISC-V32

Este documento resume os principais tipos de dados em C, os seus tamanhos, intervalos de valores
e como são representados/operados numa arquitetura **RISC-V32 (RV32I / RV32IM)**.

---

## 1. Premissas (RISC-V32)

- Arquitetura: **32 bits**
- Tamanho de um registo: **32 bits**
- Endianness: **Little-endian**
- ABI típica: **ILP32**
  - int  → 32 bits = 4 bytes
  - long → 32 bits = 4 bytes
  - pointer → 32 bits = 4 bytes

---

## 2. Tipos Inteiros Fundamentais

### `char`

| Propriedade | Valor |
|------------|------|
| Tamanho | 8 bits (1 byte) |
| Signed | implementação-dependente |
| Intervalo (signed) | -128 a 127 |
| Intervalo (unsigned) | 0 a 255 |

#### Em RISC-V
- Carregado com:
  - `lb`  → signed
  - `lbu` → unsigned (mais comum para strings)
- Armazenado com:
  - `sb`

📌 **Strings em C usam sempre `char` + `'\0'`**

---

### `short` / `unsigned short`

| Propriedade | Valor |
|------------|------|
| Tamanho | 16 bits (2 bytes) |
| Intervalo (signed) | -32 768 a 32 767 |
| Intervalo (unsigned) | 0 a 65 535 |

#### Em RISC-V
- Carregado com:
  - `lh`  → signed
  - `lhu` → unsigned
- Armazenado com:
  - `sh`

---

### `int` / `unsigned int`

| Propriedade | Valor |
|------------|------|
| Tamanho | 32 bits (4 bytes) |
| Intervalo (signed) | -2³¹ a 2³¹-1 |
|                    |-2147483648 a 2147483647
| Intervalo (unsigned) | 0 a 4 294 967 295 |

#### Em RISC-V
- Cabe exatamente num registo (`x0–x31`)
- Carregado com:
  - `lw`
- Armazenado com:
  - `sw`
- Operações aritméticas diretas (`add`, `sub`, `mul`, etc.)

📌 **Tipo mais eficiente em RV32**

---

### `long` / `unsigned long` (ILP32)

| Propriedade | Valor |
|------------|------|
| Tamanho | 32 bits (4 bytes) |
| Igual a `int`? | Sim (em RV32) |


---

### `long long` / `unsigned long long`

| Propriedade | Valor |
|------------|------|
| Tamanho | 64 bits (8 bytes) |
| Intervalo (signed) | -2⁶³ a 2⁶³-1 |

#### Em RISC-V32
- **Não cabe num registo**
- Usa **dois registos** (low / high)
- Operações são feitas por software (`libgcc`)
- Mais lento

📌 Evitar em código crítico de performance.

---

## 3. Tipos de Ponto Flutuante

### `float`

| Propriedade | Valor |
|------------|------|
| Tamanho | 32 bits (4 bytes) |
| IEEE 754 | Sim |

#### Em RISC-V
- Só existe se tiveres extensão **F**
- Caso contrário → emulação por software

---

### `double`

| Propriedade | Valor |
|------------|------|
| Tamanho | 64 bits (8 bytes) |
| IEEE 754 | Sim |

#### Em RISC-V32
- Requer extensão **D**
- Caso contrário → software (lento)

---

## 4. Ponteiros (`T*`)

| Propriedade | Valor |
|------------|------|
| Tamanho | 32 bits (4 bytes) |
| Conteúdo | Endereço de memória |

---