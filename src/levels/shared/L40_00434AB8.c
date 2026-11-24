#include "common.h"

/* localdecomp:start func_L40_00434AB8 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} E_00434AB8;

typedef struct {
    u8 pad0[0x10];
    s32 w10;
    s32 w14;
    u8 pad18[0x18];
    s32 w30[8];
    u8 b50[8];
    E_00434AB8 e[8];
} V_00434AB8;

typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padC[0x11C];
    s32 f128;
} G_00434AB8;

extern G_00434AB8 D_001A5CD0;
extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));
extern void func_0011D534(void *, s32, s32);
extern void func_L40_004343F0(u8 *);
extern s32 func_L40_004341E8(E_00434AB8 *);
extern void func_L40_00434398(u8 *, s32, s32);

void func_L40_00434AB8(u8 *m) {
    V_00434AB8 *v = *(V_00434AB8 **)(m + 0x68);
    s32 idx = D_001A5CD0.f8;
    s32 i;
    u8 buf[8];

    if (v->w10 != 0) {
        s32 key = 0;
        s32 all = 1;
        s32 same = 1;
        s32 done = 0;
        if (v->e[idx].w4 == 0) {
            key = v->e[idx].w0;
            func_0011D534(buf, 0, 8);
            for (i = 0; i < 8; i++) {
                u8 *p = D_L40_00249330[i];
                if (p != 0) {
                    s32 *q = *(s32 **)(p + 0x2558);
                    if (q != 0) {
                        buf[*q] = 1;
                    }
                }
            }
        } else {
            all = 0;
        }
        if (all) {
            for (i = 0; i < 8; i++) {
                if (buf[i]) {
                    if (v->b50[i] == 0) {
                        all = 0;
                        break;
                    }
                    if (v->w30[i] != key) {
                        same = 0;
                    }
                }
            }
            if (all) {
                done = 1;
                if (!same) {
                    func_L40_004343F0(m);
                }
            } else if (v->w14 > 0 && v->w14 + 30000 < D_001A5CD0.f128) {
                func_L40_004343F0(m);
                done = 1;
            }
        }
        if (done) {
            v->w10 = 0;
            v->w14 = 0;
            func_0011D534(&v->e[idx], 0, 12);
        }
    }
    for (i = 0; i < 8; i++) {
        if (v->e[i].w4 != 0) {
            if (func_L40_004341E8(&v->e[i])) {
                func_L40_00434398(m, i & 0xFF, v->e[i].w0);
            }
        }
    }
}
/* localdecomp:end func_L40_00434AB8 */

/* localdecomp:start func_L40_00434CD0 */
extern s32 D_001A5E40[];
extern s32 D_001A6A80[];
extern void func_003C2880(u8 *);
extern u8 *func_L39_0066C828(u8 *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L40_00434CD0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    if (m[0x20] == 0) {
        if (D_001A5E40[0] != 0 || D_001A6A80[0] == 0) {
            func_003C2880(m);
        } else {
            func_L39_0066C828(m, -1, 1);
            m[0x30] = 0x10;
            *(s16 *)(v + 0x1E) = 0xA0;
            *(s16 *)(v + 0x1C) = -3;
            func_L01_004450F0(m, 1, -1);
        }
    }
}
/* localdecomp:end func_L40_00434CD0 */
