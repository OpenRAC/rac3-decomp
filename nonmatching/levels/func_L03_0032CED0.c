/* near miss (level 3, Starship Phoenix): 17 differences, scheduling and register allocation: retail loads D_L03_001DFA80 (lui/lw into $v1) in the prologue before lw $s0,0x68($s1) and keeps the table pointer in $v1, the C loads it after the object field and builds the address in $a0/$a1; inline expression, local base, struct-array indexing, entry pointer and assignment inside the argument all give the same bytes */
#include "common.h"

/* localdecomp:start func_L03_0032CED0 */
typedef struct S_0032CED0 {
    u8 pad0[0xD0];
    s32 fD0;
    u8 padD4[4];
    s32 fD8;
    u8 padDC[0x100 - 0xDC];
    s32 f100;
    s32 f104;
    s32 f108;
} S_0032CED0;

typedef struct E_0032CED0 {
    u8 pad0[0x30];
    u8 f30[0x40];
    u8 f70[0x10];
} E_0032CED0;

extern E_0032CED0 *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
extern s32 D_L03_001DF514;
__asm__(".extern D_L03_001DF514, 16");
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_003EB438(s32, u8 *, u8 *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_0032CED0(void *arg0) {
    E_0032CED0 *t = D_L03_001DFA80;
    S_0032CED0 *s = *(S_0032CED0 **)((u8 *)arg0 + 0x68);
    E_0032CED0 *e = &t[s->fD0];
    func_L01_004F50C8(e->f30, e->f70, 0x74, 1);
    func_L01_003EB438(0, D_L03_001DFA80[s->fD8].f30, D_L03_001DFA80[s->fD8].f70, 1, 0, 0);
    D_L03_001DF514 = 0;
    s->f100 = 0;
    s->f108 = 0;
    func_L01_004450F0(arg0, 2, -1);
}
/* localdecomp:end func_L03_0032CED0 */
