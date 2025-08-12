#pragma once

typedef unsigned long long int llu;
typedef long long int lli;
typedef char bool;

#define nullerr(name)                                                          \
  if (name == NULL) {                                                          \
    exit(1);                                                                   \
  }
#define ntnullerr(name)                                                        \
  if (name != NULL) {                                                          \
    exit(1);                                                                   \
  }

//^ Estrutura para um nó do deque
typedef struct Node {
  lli data;
  struct Node *next;
  struct Node *prev;
} Node;

//^ Estrutura para o deque
typedef struct Deque {
  Node *front;
  Node *rear;
} Deque_toInt;

//^ Estrutura para o Int(BigInt)
typedef struct {
  llu *Data;
  llu sign;
  llu size;
} ijolInt;

#define MaxUint64bits 18446744073709551615
#define MaxBigUintDigit 999999999999999999
#define AMaxBigUintDigit 99999999999999999