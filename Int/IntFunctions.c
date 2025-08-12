#pragma once

#include "..\GlobalTypes.h"
#include <stdio.h>
#include <stdlib.h>

llu LenghtString(char *String) {
  if (*String == '-')
    String++;
  char *Init = String;
  goto unrolling_loop;
unrolling_loop:
  if (*String == '\0')
    return String - Init;
  if (*String < '0' || *String > '9')
    goto err;
  ++String;
  if (*String == '\0')
    return String - Init;
  if (*String < '0' || *String > '9')
    goto err;
  ++String;
  if (*String == '\0')
    return String - Init;
  if (*String < '0' || *String > '9')
    goto err;
  ++String;
  if (*String == '\0')
    return String - Init;
  if (*String < '0' || *String > '9')
    goto err;
  ++String;
  if (*String == '\0')
    return String - Init;
  if (*String < '0' || *String > '9')
    goto err;
  ++String;
  goto unrolling_loop;
err:
  printf("LengthString-ERROR");
  exit(1);
}

void InitInt(ijolInt **Integer) {
  *Integer = (ijolInt *)malloc(sizeof(*(*Integer)));
  (*Integer)->Data = (llu *)malloc(sizeof((*Integer)->Data));
  *((*Integer)->Data) = 0;
  (*Integer)->size = 1;
  (*Integer)->sign = 0;
}
void EndInt(ijolInt **Integer) {
  free((*Integer)->Data);
  free(*Integer);
}

void SetInt(ijolInt **Integer, char *String) {
  if (*String == '-')
    (*Integer)->sign = 1;
  llu Size = LenghtString(String);
  llu MemorySize = (Size / 18) + ((Size % 18) ? 1 : 0);
  llu Value = 0;
  char *Pointer = ((*String == '-') ? String + 1 : String) + Size - 1;
  if (MemorySize != (*Integer)->size) {
    (*Integer)->size = MemorySize;
    free((*Integer)->Data);
    (*Integer)->Data = (llu *)malloc(sizeof(*((*Integer)->Data)) * MemorySize);
  }
  llu *Pointer_Integer = (*Integer)->Data + (MemorySize - 1);

  if (Size > 17)
    goto unrolling;
  goto check;

unrolling:
  Value += *(Pointer - 17) - '0';
  Value *= 10;
  Value += *(Pointer - 16) - '0';
  Value *= 10;
  Value += *(Pointer - 15) - '0';
  Value *= 10;
  Value += *(Pointer - 14) - '0';
  Value *= 10;
  Value += *(Pointer - 13) - '0';
  Value *= 10;
  Value += *(Pointer - 12) - '0';
  Value *= 10;
  Value += *(Pointer - 11) - '0';
  Value *= 10;
  Value += *(Pointer - 10) - '0';
  Value *= 10;
  Value += *(Pointer - 9) - '0';
  Value *= 10;
  Value += *(Pointer - 8) - '0';
  Value *= 10;
  Value += *(Pointer - 7) - '0';
  Value *= 10;
  Value += *(Pointer - 6) - '0';
  Value *= 10;
  Value += *(Pointer - 5) - '0';
  Value *= 10;
  Value += *(Pointer - 4) - '0';
  Value *= 10;
  Value += *(Pointer - 3) - '0';
  Value *= 10;
  Value += *(Pointer - 2) - '0';
  Value *= 10;
  Value += *(Pointer - 1) - '0';
  Value *= 10;
  Value += *(Pointer) - '0';
  *Pointer_Integer = Value;
  Size -= 18;
  Pointer -= 18;
  Value = 0;
  --Pointer_Integer;
  if (Size < 18)
    goto check;
  goto unrolling;

check:
  if (Size == 0)
    goto end;
  Value += *(Pointer - Size + 1) - '0';
  if (--Size == 0)
    goto end;
  Value *= 10;
  Value += *(Pointer - Size + 1) - '0';
  if (--Size == 0)
    goto end;
  Value *= 10;
  Value += *(Pointer - Size + 1) - '0';
  if (--Size == 0)
    goto end;
  Value *= 10;
  goto check;
end:
  if (Value)
    *Pointer_Integer = Value;
}

void PrintInt(ijolInt **Integer) {
  putchar((*Integer)->sign * '-');
  llu *Pointer = (*Integer)->Data;
  llu *Checker = Pointer + (*Integer)->size - 1;
  llu Value = 0;
  goto unrolling_loop;
unrolling_loop:
  if (Pointer == Checker)
    goto end;
  printf("%llu", *Pointer);
  Pointer++;
  if (Pointer == Checker)
    goto end;
  printf("%llu", *Pointer);
  Pointer++;
  if (Pointer == Checker)
    goto end;
  printf("%llu", *Pointer);
  Pointer++;
  if (Pointer == Checker)
    goto end;
  printf("%llu", *Pointer);
  Pointer++;
  if (Pointer == Checker)
    goto end;
  printf("%llu", *Pointer);
  Pointer++;
  goto unrolling_loop;
end:
  printf("%llu\n", *Pointer);
  return;
}