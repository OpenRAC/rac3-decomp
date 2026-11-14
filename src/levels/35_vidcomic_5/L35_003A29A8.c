#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x1C]; s32 kind; } Entry_003A42F8;
typedef struct { u8 pad[0x100]; Entry_003A42F8 entries[4]; } State_003A42F8;

typedef struct { u8 pad[0x1C]; s32 mode; } Row;
typedef struct { u8 pad[0x100]; Row rows[4]; } State;

INCLUDE_ASM("asm/levels", func_L35_003A29A8);
