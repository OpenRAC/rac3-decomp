#include "common.h"

typedef struct Obj_004CE458 Obj_004CE458;
typedef struct {
    u8 pad[8];
    void (*fn8)(Obj_004CE458 *);
} Vt_004CE458;
struct Obj_004CE458 {
    u8 pad[36];
    Vt_004CE458 *vt;
    u8 pad2[20];
};

INCLUDE_ASM("asm/levels", func_L01_004D24C0);
