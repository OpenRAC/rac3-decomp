#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_0032A4D8);

/* localdecomp:start func_L05_0032AB50 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_0032AB50;
typedef struct {
    u8 p0[0x70];
    s32 f70;
    u8 p74[0x80 - 0x74];
    s32 f80;
    u8 p84[4];
    s32 f88;
    s32 f8C;
    s32 t90[4];
    s32 tA0[4];
    s32 tB0[4];
    u8 pC0[0xE0 - 0xC0];
    s32 tE0[4];
    s32 tF0[4];
    u8 p100[0x130 - 0x100];
    s32 t130[8];
    f32 f150;
    f32 f154;
    f32 f158;
    s32 f15C;
    u8 p160[0x16C - 0x160];
    s32 f16C;
} S_0032AB50;
extern u8 *D_L05_001DFC80;
extern void func_L01_00477BC0(s32, s32);
extern void func_L05_00328E98(void *obj, Vec4_0032AB50 a, Vec4_0032AB50 b);
extern void func_L05_00328EC0(void *obj, void *target, Vec4_0032AB50 a, Vec4_0032AB50 b);
extern f32 func_003824E0(f32, f32);
extern void func_L05_00328F00(u8 *, S_0032AB50 *);
extern void func_L05_00329618(u8 *, S_0032AB50 *);
extern void func_L05_003298C0(u8 *, S_0032AB50 *);
extern s32 func_L05_00329DA8(u8 *, S_0032AB50 *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L05_0032AB50(u8 *a0, S_0032AB50 *s) {
    s32 i;
    s32 k;
    s32 j;
    s32 idx;
    u8 *e;
    Vec4_0032AB50 va;
    Vec4_0032AB50 vb;

    for (i = 0; i < 4; i++) {
        if (s->t90[i] != -1) {
            func_L01_00477BC0(s->tA0[i], 0);
            if (s->tB0[i] != -1) {
                func_L01_00477BC0(s->tB0[i], 0);
            }
        }
    }
    for (k = 0; k < 4; k++) {
        if (s->tE0[k] != -1) {
            func_L01_00477BC0(s->tF0[k], 0);
        }
    }
    *(u16 *)(a0 + 0x32) = 0x80;
    a0[0x30] = 0xFF;
    s->f16C = -1;
    s->f80 = 0;
    s->f8C = 0;
    va = *(Vec4_0032AB50 *)(a0 + 0x10);
    vb = *(Vec4_0032AB50 *)(a0 + 0xF0);
    func_L05_00328E98(s, va, vb);
    s->f150 = func_003824E0(-0.2f, 0.2f);
    s->f154 = func_003824E0(0.0f, 3.1415927f);
    s->f158 = func_003824E0(0.0f, 3.1415927f);
    s->f88 = 0;
    for (j = 7; j >= 0; j--) {
        s->t130[j] = 0;
    }
    if (s->f70 == 0) {
        func_L05_00328F00(a0, s);
    }
    func_L05_00329618(a0, s);
    func_L05_003298C0(a0, s);
    if (s->f70 != 0) {
        func_L01_004450F0(a0, 2, -1);
        idx = func_L05_00329DA8(a0, s);
        s->f15C = idx;
        e = D_L05_001DFC80 + (s->t90[idx] << 7);
        va = *(Vec4_0032AB50 *)(e + 0x30);
        vb = *(Vec4_0032AB50 *)(e + 0x70);
        func_L05_00328EC0(a0, s, va, vb);
    } else {
        s->f15C = -1;
        func_L01_004450F0(a0, 1, -1);
        *(u16 *)(a0 + 0x34) |= 1;
        *(s32 *)(a0 + 0x98) = 0;
    }
}
/* localdecomp:end func_L05_0032AB50 */
