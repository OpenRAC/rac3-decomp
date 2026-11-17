#include "common.h"

/* localdecomp:start func_L09_003CE7A0 */
typedef int TI_003CE7A0 __attribute__((mode(TI)));

typedef struct {
    s32 timer;      /* 0x00 */
    f32 rate;       /* 0x04 */
    s32 hit;        /* 0x08 */
    f32 range;      /* 0x0C */
    f32 z;          /* 0x10 */
    s32 sound;      /* 0x14 */
    s32 flag;       /* 0x18 */
} V_003CE7A0;

typedef struct {
    u8 pad0[0xAA];
    s16 oclass;
} M_003CE7A0;

extern s32 func_L01_004561B8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_0038CAD0(void *);
extern void func_003A4F28(s32);
extern f32 func_003C3BE8(f32, f32, f32);
extern u8 D_001A4C60[];
extern void *D_001A71A0[];
extern u8 D_001A30B0[];
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern M_003CE7A0 *D_L09_001ED940[];
extern M_003CE7A0 *D_L09_001EEEA8[];
extern s32 D_L09_001D6774;

void func_L09_003CE7A0(u8 *self) {
    V_003CE7A0 *v = *(V_003CE7A0 **)(self + 0x68);

    switch (self[0x20]) {
    case 0:
        v->z = *(f32 *)(self + 0x18);
        if (v->flag == -1) {
            func_L01_004450F0(self, 1, -1);
        } else {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 1: {
        s32 n;
        s32 i;
        s32 j;
        s32 found;

        if (func_L01_004561B8(self) != 0) {
            *(f32 *)(self + 0x18) = v->z;
        }
        if (v->hit != -1 ? func_00382380(D_001A4C60, v->hit, 0) != 0
                         : func_0038CF38(self + 0x10, D_001A4C60) < v->range) {
            func_L01_004450F0(self, 2, -1);
        }
        n = func_003D4D00(self + 0x10, 1, D_001A71A0[0], 0, v->range);
        if (n != 0) {
            found = 0;
            for (i = 0; i < n; i++) {
                if (D_L09_001ED940[i]->oclass == 0x1AE6 || D_L09_001ED940[i]->oclass == 0x19C1) {
                    for (j = 0; j < D_L09_001D6774; j++) {
                        if (D_L09_001ED940[i] == D_L09_001EEEA8[j]) {
                            func_L01_004450F0(self, 2, -1);
                            found = 1;
                            break;
                        }
                    }
                }
                if (found) {
                    break;
                }
            }
        }
        break;
    }
    case 2: {
        u8 *e;

        if (func_L01_004561B8(self) != 0) {
            v->timer = 60;
            v->rate = 0.016666668f;
            if (v->sound == -1 || (e = D_001A30B0 + (v->sound << 7), *(void **)(e + 0xDC) != self)
                || e[0xD0] == 0) {
                v->sound = func_003A52A0(0, 4, self);
            }
        }
        if (func_0038CAD0(v) != 0) {
            if (v->sound != -1 && (e = D_001A30B0 + (v->sound << 7), *(void **)(e + 0xDC) == self)
                && e[0xD0] != 0) {
                func_003A4F28(v->sound);
            }
            v->sound = -1;
            func_L01_004450F0(self, 3, -1);
        } else {
            *(f32 *)(self + 0x18) = func_003C3BE8(v->z + 5.0f, v->z, (f32)v->timer * v->rate);
        }
        break;
    }
    case 3: {
        s32 n;
        s32 i;
        s32 j;
        s32 near;
        s32 found;
        union { TI_003CE7A0 q; f32 f[4]; } pos;

        if (func_L01_004561B8(self) != 0) {
            *(f32 *)(self + 0x18) = v->z + 5.0f;
            v->timer = 300;
        }
        near = 0;
        found = 0;
        if (v->flag != -1) {
            if (D_001BBC40[v->flag + D_001D545C * 16] & 0x80) {
                *(f32 *)(self + 0x18) = v->z;
                func_L01_004450F0(self, 5, -1);
            }
        } else if (v->hit != -1 ? func_00382380(D_001A4C60, v->hit, 0) != 0
                                : func_0038CF38(self + 0x10, D_001A4C60) < v->range) {
            near = 1;
        }
        if (v->flag == -1) {
            pos.q = *(TI_003CE7A0 *)(self + 0x18);
            pos.f[2] = v->z;
            n = func_003D4D00(&pos, 1, D_001A71A0[0], 0, v->range);
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    if (D_L09_001ED940[i]->oclass == 0x1AE6 || D_L09_001ED940[i]->oclass == 0x19C1) {
                        for (j = 0; j < D_L09_001D6774; j++) {
                            if (D_L09_001ED940[i] == D_L09_001EEEA8[j]) {
                                found = 1;
                                break;
                            }
                        }
                    }
                    if (found) {
                        break;
                    }
                }
            }
        }
        if (v->flag == -1 && !near && !found) {
            func_L01_004450F0(self, 4, -1);
        }
        break;
    }
    case 4: {
        u8 *e;

        if (func_L01_004561B8(self) != 0) {
            v->timer = 60;
            v->rate = 0.016666668f;
            if (v->sound == -1 || (e = D_001A30B0 + (v->sound << 7), *(void **)(e + 0xDC) != self)
                || e[0xD0] == 0) {
                v->sound = func_003A52A0(1, 4, self);
            }
        }
        if (func_0038CAD0(v) != 0) {
            if (v->sound != -1 && (e = D_001A30B0 + (v->sound << 7), *(void **)(e + 0xDC) == self)
                && e[0xD0] != 0) {
                func_003A4F28(v->sound);
            }
            v->sound = -1;
            func_L01_004450F0(self, 1, -1);
        } else {
            *(f32 *)(self + 0x18) = func_003C3BE8(v->z, v->z + 5.0f, (f32)v->timer * v->rate);
        }
        break;
    }
    }
}
/* localdecomp:end func_L09_003CE7A0 */
