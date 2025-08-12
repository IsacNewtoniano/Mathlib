#pragma once



#include "..\GlobalTypes.h"
#include <assert.h>

bool ijolIntsEqual(       ijolInt **X, ijolInt **Y);  //^ X == -Y; X == Y; -X == Y; -X == -Y
bool ijolIntEqual(        ijolInt **X, ijolInt **Y);  //^ X ==  Y
bool ijolIntsInequal(     ijolInt **X, ijolInt **Y);  //^ X != -Y; X != Y; -X != Y; -X != -Y
bool ijolIntInequal(      ijolInt **X, ijolInt **Y);  //^ X !=  Y

bool ijolIntsGreater(     ijolInt **X, ijolInt **Y);  //^ X >  -Y; X >  Y; -X >  Y; -X >  -Y
bool ijolIntGreater(      ijolInt **X, ijolInt **Y);  //^ X >   Y
bool ijolIntsGreaterEqual(ijolInt **X, ijolInt **Y);  //^ X >= -Y; X >= Y; -X >= Y; -X >= -Y
bool ijolIntGreaterEqual( ijolInt **X, ijolInt **Y);  //^ X >=  Y

bool ijolIntsLesser(      ijolInt **X, ijolInt **Y);  //^ X <  -Y; X <  Y; -X <  Y; -X <  -Y
bool ijolIntLesser(       ijolInt **X, ijolInt **Y);  //^ X <   Y
bool ijolIntsLesserEqual( ijolInt **X, ijolInt **Y);  //^ X <= -Y; X <= Y; -X <= Y; -X <= -Y
bool ijolIntLesserEqual(  ijolInt **X, ijolInt **Y);  //^ X <=  Y

bool __attribute__((always_inline))  ijolIntOr(    ijolInt **X, ijolInt **Y);  //^ X  == 1 || Y == 1
bool __attribute__((always_inline))  ijolIntAnd(   ijolInt **X, ijolInt **Y);  //^ X  == 1 && Y == 1
bool __attribute__((always_inline))  ijolIntNot(   ijolInt **X             );  //^ X == 1 = 0; X == 0 = 1;

bool __attribute__((always_inline))  ijolIntsOr(    ijolInt **X, ijolInt **Y);  //^ X  == 1 || Y == 1      This for safe (this is precary)
bool __attribute__((always_inline))  ijolIntsAnd(   ijolInt **X, ijolInt **Y);  //^ X  == 1 && Y == 1      This for safe (this is precary)


#define AllNumbersSafe do { \
    assert((X) != NULL && (Y) != NULL && "Null input"); \
    assert((*(X)) != NULL && (*(Y)) != NULL && "Dereferenced null"); \
    assert((*(X))->Data != NULL && (*(Y))->Data != NULL && "Null data"); \
} while (0);

bool ijolIntEqual(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
  if (SizeX != (*Y)->size) return 0;
    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;
  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX ==  PtrX) return (*DataX == *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return 0;
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX == *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 0;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX == *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 0;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX == *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 0;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX == *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 0;
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}

bool ijolIntsEqual(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu Sign = (*X)->sign;
  if (SizeX != (*Y)->size) return 0;
  if (Sign != (*Y)->sign) return 0;
    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;    
  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX ==  PtrX) return (*DataX == *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return 0;
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX == *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 0;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX == *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 0;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX == *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 0;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX == *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 0;
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}


bool ijolIntInequal(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
  if (SizeX != (*Y)->size) return 0;
    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX ==  PtrX) return (*DataX != *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return 0;
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if ( DataX ==  PtrX) return (*DataX != *DataY);
  if (*DataX != *DataY) return 0;
  ++DataX;
  ++DataY;  if ( DataX ==  PtrX) return (*DataX != *DataY);
  if (*DataX != *DataY) return 0;
  ++DataX;
  ++DataY;  if ( DataX ==  PtrX) return (*DataX != *DataY);
  if (*DataX != *DataY) return 0;
  ++DataX;
  ++DataY;  if ( DataX ==  PtrX) return (*DataX != *DataY);
  if (*DataX != *DataY) return 0;
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}

bool ijolIntsInequal(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu Sign = (*X)->sign;

  if (SizeX != (*Y)->size) return 1;
  if (Sign != (*Y)->sign) return 1;
    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;    
  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX ==  PtrX) return (*DataX != *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return 1;
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX != *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 1;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX != *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 1;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX != *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 1;
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX ==  PtrX, 1)) return (*DataX != *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return 1;
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}



bool ijolIntGreater(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu SizeY = (*Y)->size;
//* (SizeX > SizeY && SignX == 0 && SignY == 1) = true
//* (SizeX > SizeY && SignX == 0 && SignY == 0) = true
//^ |||||||||||||||||||||||||||||||||||||||||||||||||||
//* (SizeX < SizeY && SignX == 1 && SignY == 1) = false
//* (SizeX < SizeY && SignX == 0 && SignY == 1) = false

  if (SizeX != SizeY) return (SizeX > SizeY);

    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX == PtrX ) return (*DataX > *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return (*DataX > *DataY);
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX > *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX > *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX > *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX > *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX > *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX > *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX > *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX > *DataY);
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}

bool ijolIntsGreater(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu SizeY = (*Y)->size;
    llu SignX = (*X)->sign;
    llu SignY = (*Y)->sign;
//* (SizeX > SizeY && SignX == 1 && SignY == 0) = false
//* (SizeX > SizeY && SignX == 1 && SignY == 1) = false
//* (SizeX < SizeY && SignX == 1 && SignY == 0) = false
//* (SizeX < SizeY && SignX == 0 && SignY == 0) = false
//^ |||||||||||||||||||||||||||||||||||||||||||||||||||
//* (SizeX > SizeY && SignX == 0 && SignY == 1) = true
//* (SizeX > SizeY && SignX == 0 && SignY == 0) = true
//* (SizeX < SizeY && SignX == 1 && SignY == 1) = true
//* (SizeX < SizeY && SignX == 0 && SignY == 1) = true

  if (SizeX != SizeY) return (SizeX > SizeY) ? (bool)!SignX:(bool)SignY;

//* (SignX == 0 && SignY == 1) = true
//* (SignX == 1 && SignY == 0) = false
  if (SignX != SignY) return (SignX < SignY);

    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX == PtrX ) return (*DataX > *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return (*DataX > *DataY);
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX > *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX > *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX > *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX > *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX > *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX > *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX > *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX > *DataY);
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}


bool ijolIntGreaterEqual(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu SizeY = (*Y)->size;
//* (SizeX > SizeY && SignX == 0 && SignY == 1) = true
//* (SizeX > SizeY && SignX == 0 && SignY == 0) = true
//^ |||||||||||||||||||||||||||||||||||||||||||||||||||
//* (SizeX < SizeY && SignX == 1 && SignY == 1) = false
//* (SizeX < SizeY && SignX == 0 && SignY == 1) = false

  if (SizeX != SizeY) return (SizeX > SizeY);

    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX == PtrX ) return (*DataX >= *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return (*DataX >= *DataY);
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX >= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX >= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX >= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX >= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX >= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX >= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX >= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX >= *DataY);
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}

bool ijolIntsGreaterEqual(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu SizeY = (*Y)->size;
    llu SignX = (*X)->sign;
    llu SignY = (*Y)->sign;
//* (SizeX > SizeY && SignX == 1 && SignY == 0) = false
//* (SizeX > SizeY && SignX == 1 && SignY == 1) = false
//* (SizeX < SizeY && SignX == 1 && SignY == 0) = false
//* (SizeX < SizeY && SignX == 0 && SignY == 0) = false
//^ |||||||||||||||||||||||||||||||||||||||||||||||||||
//* (SizeX > SizeY && SignX == 0 && SignY == 1) = true
//* (SizeX > SizeY && SignX == 0 && SignY == 0) = true
//* (SizeX < SizeY && SignX == 1 && SignY == 1) = true
//* (SizeX < SizeY && SignX == 0 && SignY == 1) = true

  if (SizeX != SizeY) return (SizeX > SizeY) ? (bool)!SignX:(bool)SignY;

//* (SignX == 0 && SignY == 1) = true
//* (SignX == 1 && SignY == 0) = false
  if (SignX != SignY) return (SignX < SignY);

    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX == PtrX ) return (*DataX >= *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return (*DataX >= *DataY);
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX >= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX >= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX >= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX >= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX >= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX >= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX >= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX >= *DataY);
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}



bool ijolIntLesser(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu SizeY = (*Y)->size;
//* (SizeX > SizeY && SignX == 0 && SignY == 1) = true
//* (SizeX > SizeY && SignX == 0 && SignY == 0) = true
//^ |||||||||||||||||||||||||||||||||||||||||||||||||||
//* (SizeX < SizeY && SignX == 1 && SignY == 1) = false
//* (SizeX < SizeY && SignX == 0 && SignY == 1) = false

  if (SizeX != SizeY) return (SizeX < SizeY);

    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX == PtrX ) return (*DataX < *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return (*DataX < *DataY);
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX < *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX < *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX < *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX < *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX < *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX < *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX < *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX < *DataY);
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}

bool ijolIntsLesser(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu SizeY = (*Y)->size;
    llu SignX = (*X)->sign;
    llu SignY = (*Y)->sign;
;
//* (SizeX > SizeY && SignX == 0 && SignY == 1) = false
//* (SizeX > SizeY && SignX == 0 && SignY == 0) = false
//* (SizeX < SizeY && SignX == 1 && SignY == 1) = false
//* (SizeX < SizeY && SignX == 0 && SignY == 1) = false
//^ |||||||||||||||||||||||||||||||||||||||||||||||||||
//* (SizeX > SizeY && SignX == 1 && SignY == 0) = true
//* (SizeX > SizeY && SignX == 1 && SignY == 1) = true
//* (SizeX < SizeY && SignX == 1 && SignY == 0) = true
//* (SizeX < SizeY && SignX == 0 && SignY == 0) = true

  if (SizeX != SizeY) return (SizeX < SizeY) ? (bool)!SignY:(bool)SignX;

//* (SignX == 1 && SignY == 0) = true
//* (SignX == 0 && SignY == 1) = false
  if (SignX != SignY) return (SignX > SignY);

    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX == PtrX ) return (*DataX < *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return (*DataX < *DataY);
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX < *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX < *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX < *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX < *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX < *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX < *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX < *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX < *DataY);
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}


bool ijolIntLesserEqual(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu SizeY = (*Y)->size;
//* (SizeX > SizeY && SignX == 0 && SignY == 1) = true
//* (SizeX > SizeY && SignX == 0 && SignY == 0) = true
//^ |||||||||||||||||||||||||||||||||||||||||||||||||||
//* (SizeX < SizeY && SignX == 1 && SignY == 1) = false
//* (SizeX < SizeY && SignX == 0 && SignY == 1) = false

  if (SizeX != SizeY) return (SizeX < SizeY);

    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX == PtrX ) return (*DataX <= *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return (*DataX <= *DataY);
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX <= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX <= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX <= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX <= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX <= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX <= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX <= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX <= *DataY);
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}

bool ijolIntsLesserEqual(ijolInt **X, ijolInt **Y){
    AllNumbersSafe
    llu SizeX = (*X)->size;
    llu SizeY = (*Y)->size;
    llu SignX = (*X)->sign;
    llu SignY = (*Y)->sign;
//* (SizeX > SizeY && SignX == 0 && SignY == 1) = false
//* (SizeX > SizeY && SignX == 0 && SignY == 0) = false
//* (SizeX < SizeY && SignX == 1 && SignY == 1) = false
//* (SizeX < SizeY && SignX == 0 && SignY == 1) = false
//^ |||||||||||||||||||||||||||||||||||||||||||||||||||
//* (SizeX > SizeY && SignX == 1 && SignY == 0) = true
//* (SizeX > SizeY && SignX == 1 && SignY == 1) = true
//* (SizeX < SizeY && SignX == 1 && SignY == 0) = true
//* (SizeX < SizeY && SignX == 0 && SignY == 0) = true

  if (SizeX != SizeY) return (SizeX < SizeY) ? (bool)!SignY:(bool)SignX;

//* (SignX == 1 && SignY == 0) = true
//* (SignX == 0 && SignY == 1) = false
  if (SignX != SignY) return (SignX > SignY);

    llu *DataX = (*X)->Data;
    llu *DataY = (*Y)->Data;
    llu *PtrX = (*X)->Data + SizeX - 1;  goto unrolling_loop;
unrolling_loop:
  //& (&DataX"&DataY" == &DataX[0]"&DataY[0]") = end
  if ( DataX == PtrX ) return (*DataX <= *DataY);
  //& (*DataX != *DataY) = end
  if (*DataX != *DataY) return (*DataX <= *DataY);
  //& DataX to prev index
  ++DataX;
  //& DataY to prev index
  ++DataY;  //& Repetitions code for unrolling
  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX <= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX <= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX <= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX <= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX <= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX <= *DataY);
  ++DataX;
  ++DataY;  if (__builtin_expect( DataX == PtrX, 1 )) return (*DataX <= *DataY);
  if (__builtin_expect(*DataX != *DataY, 1)) return (*DataX <= *DataY);
  ++DataX;
  ++DataY;  goto unrolling_loop; //& Reset the Unroll Loop
}

bool inline ijolIntOr(ijolInt **X, ijolInt **Y){
  //^ (DataX[0] == 0 && DataY[0] == 0) = 0
  //^ (DataX[0] == 1 && DataY[0] == 0) = 1
  //^ (DataX[0] == 0 && DataY[0] == 1) = 1
  //^ (DataX[0] == 1 && DataY[0] == 1) = 1
  return (*(*X)->Data) || (*(*Y)->Data);
}

bool inline ijolIntAnd(ijolInt **X, ijolInt **Y){
  //^ (DataX[0] == 0 && DataY[0] == 0) = 0
  //^ (DataX[0] == 1 && DataY[0] == 0) = 0
  //^ (DataX[0] == 0 && DataY[0] == 1) = 0
  //^ (DataX[0] == 1 && DataY[0] == 1) = 1
  return (*(*X)->Data) && (*(*Y)->Data);
}

bool __attribute__((always_inline)) ijolIntNot(ijolInt **X){
  //^ (Data[0] == 0) = 1
  //^ (Data[0] == 1) = 0
  return !(*(*X)->Data);
}

bool __attribute__((always_inline)) ijolIntsOr(ijolInt **X, ijolInt **Y){
  //^ (DataX[0] == 0 && DataY[0] == 0) = 0
  //^ (DataX[0] == 1 && DataY[0] == 0) = 1
  //^ (DataX[0] == 0 && DataY[0] == 1) = 1
  //^ (DataX[0] == 1 && DataY[0] == 1) = 1
  return (*(*X)->Data > 0) || (*(*Y)->Data > 0);
}

bool __attribute__((always_inline)) ijolIntsAnd(ijolInt **X, ijolInt **Y){
  //^ (DataX[0] == 0 && DataY[0] == 0) = 0
  //^ (DataX[0] == 1 && DataY[0] == 0) = 0
  //^ (DataX[0] == 0 && DataY[0] == 1) = 0
  //^ (DataX[0] == 1 && DataY[0] == 1) = 1
  return (*(*X)->Data > 0) && (*(*Y)->Data > 0);
}