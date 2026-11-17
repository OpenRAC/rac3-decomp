#include "common.h"

typedef struct S_L30_00346278_inner {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    s32 f20;
} S_L30_00346278_inner;
typedef struct S_L30_00346278 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x4C];
    S_L30_00346278_inner *f68;
} S_L30_00346278;

/* declared by functions of L30_00346230.c, which this file was cut from */
void func_L30_00346320(void *);
void func_L30_00346600(void *);

/* localdecomp:start func_L30_00346320 */
typedef struct S_00346320 {
    f32 f0;
    u8 pad4[0x14];
    f32 f18;
    f32 f1C;
    s32 sound;
} S_00346320;

typedef struct H_00346320 {
    u8 pad0[0x25C0];
    void *p25C0;
} H_00346320;

extern H_00346320 D_1A4BE0_00346320;
extern u8 D_1A30B0[];
extern void *D_001ED080[];
extern f32 D_L30_001DCF38;
__asm__(".extern D_L30_001DCF38, 4");

extern s32 func_L01_004561B8(void *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038D0B0(f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L30_003467C0(void *);

void func_L30_00346320(void *arg0) {
    u8 *moby = arg0;
    S_00346320 *pv = *(S_00346320 **)(moby + 0x68);
    u8 *e;
    f32 s;
    s32 n;
    s32 i;

    switch (moby[0x20]) {
    case 3:
        if (func_L01_004561B8(moby) != 0) {
            if (pv->sound != -1) {
                e = D_1A30B0 + (pv->sound << 7);
                if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                    func_003A4F28(pv->sound);
                }
            }
            pv->sound = -1;
            pv->sound = func_003A52A0(1, 0, moby);
        }
        *(f32 *)(moby + 0x18) = pv->f1C - pv->f18;
        break;
    case 1:
        if (func_L01_004561B8(moby) != 0) {
            if (pv->sound != -1) {
                e = D_1A30B0 + (pv->sound << 7);
                if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                    func_003A4F28(pv->sound);
                }
            }
            pv->sound = -1;
        }
        *(f32 *)(moby + 0x18) = pv->f1C;
        break;
    case 2:
        if (pv->sound != -1) {
            e = D_1A30B0 + (pv->sound << 7);
            if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                goto play2;
            }
        }
        pv->sound = func_003A52A0(0, 4, moby);
    play2:
        *(f32 *)(moby + 0x18) = pv->f1C - pv->f0 * pv->f18;
        func_L30_003467C0(moby);
        break;
    case 4:
        if (pv->sound != -1) {
            e = D_1A30B0 + (pv->sound << 7);
            if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                goto play4;
            }
        }
        pv->sound = func_003A52A0(0, 4, moby);
    play4:
        s = func_0038D0B0(pv->f0 * 3.1415927f + -1.5707964f);
        *(f32 *)(moby + 0x18) = pv->f1C - (1.0f - (s * 0.5f + 0.5f)) * pv->f18;
        if (*(s32 *)(moby + 0x98) == 0) {
            n = func_003D4D00(moby + 0x10, 0x10, moby, 0, D_L30_001DCF38);
            i = 0;
            if (n != 0) {
                for (; i < n; i++) {
                    if (D_001ED080[i] == D_1A4BE0_00346320.p25C0) {
                        break;
                    }
                }
                if (i != n) {
                    break;
                }
            }
            *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
        }
        break;
    }
}
/* localdecomp:end func_L30_00346320 */

/* localdecomp:start func_L30_00346600 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L30_00427F30(void *, s32, f32, f32, f32, f32, s32);
__asm__(".extern D_L30_001DF2C0, 16");
extern s32 D_L30_001DF2C0;

typedef struct {
    f32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} S_00346600;

void func_L30_00346600(void *arg0) {
    u8 *o = arg0;
    S_00346600 *s = *(S_00346600 **)(o + 0x68);
    s32 t;

    t = (D_L30_001DF2C0 + s->f14) % (s->f10 + s->f4 + s->fC + s->f8);
    if (t < s->f10) {
        s->f0 = (f32)t / (f32)s->f10;
        if (o[0x20] != 1) {
            func_L01_004450F0(o, 1, -1);
            *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
        }
        return;
    }
    t -= s->f10;
    if (t < s->f4) {
        s->f0 = (f32)t / (f32)s->f4;
        if (o[0x20] != 2) {
            func_L01_004450F0(o, 2, -1);
        }
        return;
    }
    t -= s->f4;
    if (t < s->fC) {
        s->f0 = (f32)t / (f32)s->fC;
        if (o[0x20] != 3) {
            func_L01_004450F0(o, 3, -1);
            func_L30_00427F30(o + 0x10, 0x10, 4.0f, 0.5f, 0.5f, 2.0f, 0x20);
        }
        return;
    }
    t -= s->fC;
    s->f0 = (f32)t / (f32)s->f8;
    if (o[0x20] != 4) {
        func_L01_004450F0(o, 4, -1);
    }
}
/* localdecomp:end func_L30_00346600 */

/* localdecomp:start func_L30_003467C0 */
#include "vu0.h"

typedef struct E_003467C0 {
    u8 pad0[0x20];
    s32 flags;
    u8 pad24[0xC];
} E_003467C0;

typedef struct H_003467C0 {
    u8 pad0[0x25C0];
    void *p25C0;
} H_003467C0;

extern H_003467C0 D_1A4BE0;
extern void *D_001ED080[];
extern f32 D_L30_001DCF38;
__asm__(".extern D_L30_001DCF38, 4");

extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);

void func_L30_003467C0(void *arg0) {
    u8 *moby = arg0;
    f32 v[4] __attribute__((aligned(16)));
    E_003467C0 e;
    s32 n;
    s32 i;

    qzero(v);
    v[2] = -1.0f;
    v[3] = 1.0f;
    func_L01_00446760(&e, moby, 1, v, 20.0f);
    e.flags |= 1;
    n = func_003D4D00(moby + 0x10, 0x10, moby, &e, D_L30_001DCF38);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            if (D_001ED080[i] == D_1A4BE0.p25C0) {
                *(s32 *)(moby + 0x98) = 0;
                break;
            }
        }
        v[2] += 1.0f;
    }
}
/* localdecomp:end func_L30_003467C0 */
