#include "common.h"

/* localdecomp:start func_L34_003B2A38 */
typedef struct { f32 x, y, z, w; } V_003B2A38 __attribute__((aligned(16)));

typedef struct {
    f32 f[2];
    u8 pad08[8];
    f32 tbl[2][3];
    u8 pad28[0x18];
    u8 *e[2];
    u8 pad48[0x18];
    s32 count;
    u8 pad64[4];
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 timer;
    s32 timer2;
} Vars_003B2A38;

typedef struct {
    u8 pad0[0x80];
    V_003B2A38 pos;
    u8 pad90[0x1B08 - 0x90];
    s32 f1B08;
} Player_003B2A38;

extern Player_003B2A38 D_1A4BE0;
__asm__(".extern D_001DF7A8, 4");
__asm__(".extern D_001DF79C, 4");
extern u8 *D_001DF7A8;
extern u8 *D_001DF79C;

extern s32 func_00382380(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L31_0034E0F0(void *, s32, s32, s32, s32);
extern s32 func_L34_00351C18(s32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_003C7C38(void *);
extern void func_L34_00352018(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(u8 *, s32);

void func_L34_003B2A38(u8 *a0) {
    Vars_003B2A38 *v = *(Vars_003B2A38 **)(a0 + 0x68);
    s32 i;
    s32 idx;
    s32 n;
    s32 k;
    u8 *e;
    u8 *m;
    V_003B2A38 pos;

    switch (a0[0x20]) {
    case 0:
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_00382380(&D_1A4BE0.pos, v->f70, 0)) {
            if (__builtin_fabsf(*(f32 *)(a0 + 0x10) - D_1A4BE0.pos.x) > 2.5f) {
                func_L01_004450F0(a0, 2, -1);
            }
        }
        break;
    case 2:
        idx = -1;
        for (i = 0; i < 2 && v->f[i] != 0.0f; i++) {
            u8 *o = v->e[i];
            if (o == 0 || o[0x20] == 0xFE || o[0x20] == 0xFD || *(s16 *)(o + 0xAA) != 0x16F5) {
                idx = i;
                break;
            }
        }
        if (func_0038CAD0(&v->timer2) && D_1A4BE0.f1B08 < 5) {
            s32 busy = 0;
            u8 *q;
            for (q = D_001DF7A8; q != 0; q = *(u8 **)(q + 0x28)) {
                if (*(s16 *)(q + 0xAA) == 0x15D5 || *(s16 *)(q + 0xAA) == 0x1677) {
                    busy = 1;
                    break;
                }
            }
            if (!busy) {
                v->timer2 = 0x21;
                pos = *(V_003B2A38 *)(a0 + 0x10);
                pos.y = D_1A4BE0.pos.y;
                pos.z = 132.5f;
                pos.x = func_003824E0(290.0f, 303.0f);
                func_L31_0034E0F0(&pos, 1, 0x14, 1, -1);
            }
        }
        if (idx != -1 && func_0038CAD0(&v->timer)) {
            e = (u8 *)func_L34_00351C18((s32)a0);
            if (e != 0) {
                v->e[idx] = e;
                v->timer = (func_00382498(0x32, 0x78) * 5 + 2) / 6;
                n = 0;
                for (i = 0; v->tbl[idx][i] != 0.0f && i < 3; i++) {
                    n++;
                }
                if (n != 0) {
                    k = 1;
                    if (n != 1) {
                        k = func_00382468(n);
                    }
                    *(V_003B2A38 *)(e + 0x10) = *(V_003B2A38 *)(a0 + 0x10);
                    *(f32 *)(e + 0x10) = v->tbl[idx][k];
                    func_003C7C38(e);
                }
                m = *(u8 **)(e + 0x68);
                *(s32 *)(m + 0x140) = v->f68;
                func_L34_00352018(e);
                e[0x20] = 1;
                *(f32 *)(m + 0x16C) = v->f[idx];
                if (--v->count <= 0) {
                    func_L01_004450F0(a0, 3, -1);
                }
            }
        }
        break;
    case 3: {
        s32 j;
        s32 done = 1;
        for (j = 0; j < 2 && v->f[j] != 0.0f; j++) {
            u8 *o = v->e[j];
            if (o != 0 && o[0x20] != 0xFE && o[0x20] != 0xFD && *(s16 *)(o + 0xAA) == 0x16F5) {
                done = 0;
            }
        }
        if (done && v->f6C != -1) {
            func_L01_00456230(D_001DF79C + (v->f6C << 8), 1);
        }
        break;
    }
    }
}
/* localdecomp:end func_L34_003B2A38 */
