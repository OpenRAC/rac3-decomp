#include "common.h"

typedef struct { u8 p0[0x23]; u8 f23; u8 p24[0x10]; u16 f34; } E_00318E78;

typedef struct { char pad[0x10]; unsigned int kind; } B;
typedef struct { char pad[0x68]; B *b; } A;

typedef struct { u8 p0[0x23]; s8 f23; } E_00318CA8;
typedef struct { u8 p0[0x1200]; E_00318CA8 *e[3]; u8 pad[0x50 - 0xC]; } S_00318CA8;
typedef struct { u8 p0[0x25C0]; E_00318CA8 *g; } T_00318CA8;

INCLUDE_ASM("asm/levels", func_L02_00317D28);
