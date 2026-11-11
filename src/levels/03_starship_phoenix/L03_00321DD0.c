#include "common.h"

typedef struct Obj_00322548 {
    u8 pad0[0x30];
    u8 f30;
    u8 pad31[0x33];
    void (*f64)(struct Obj_00322548 *);
    u8 pad68[0x98];
} Obj_00322548;

INCLUDE_ASM("asm/levels", func_L03_00321DD0);

/* localdecomp:start func_L03_003220D8 */
typedef struct { u8 pad0[0x20]; s32 f20; u8 pad24[0x30]; s32 f54; s32 f58; s32 f5C; s32 f60; } S_003220D8;
extern Obj_00322548 *D_L03_001DF99C;
extern u8 D_001A4C60[];
extern s16 D_001CD018[];
extern s32 func_L03_0032F660(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_0045F1E8(s32, s32);
void func_L03_003220D8(void *a) {
    S_003220D8 *s = *(S_003220D8 **)((u8 *)a + 0x68);
    s32 v = s->f54;
    if (func_L03_0032F660(D_L03_001DF99C + s->f20) != 0) {
        v = s->f58;
    } else if (func_00382380(D_001A4C60, s->f60, 0) != 0) {
        v = s->f5C;
    }
    if (D_001CD018[0] != v) {
        func_L01_0045F1E8(v, -1);
    }
}
/* localdecomp:end func_L03_003220D8 */

INCLUDE_ASM("asm/levels", func_L03_00322160);

/* localdecomp:start func_L03_00322548 */
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

extern Obj_00322548 *D_L03_001DF99C;

void func_L03_00322548(u8 *a, s32 b) {
    Obj_00322548 *p = D_L03_001DF99C + b;

    func_L01_00456230((u8 *)p, 1);
    p->f30 = 0xFF;
    p->f64(p);
    func_L01_004450F0(a, 4, -1);
}
/* localdecomp:end func_L03_00322548 */
