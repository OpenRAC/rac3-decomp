#include "common.h"

/* localdecomp:start func_L03_0039AA48 */
extern f32 D_L03_001DE354;
__asm__(".extern D_L03_001DE354, 4");
extern f32 D_L03_001DE358;
__asm__(".extern D_L03_001DE358, 4");
extern f32 D_L03_001DE35C;
__asm__(".extern D_L03_001DE35C, 4");
extern f32 D_L03_001DE360;
__asm__(".extern D_L03_001DE360, 4");
extern f32 D_L03_001DE364;
__asm__(".extern D_L03_001DE364, 4");
extern f32 D_L03_001DE368;
__asm__(".extern D_L03_001DE368, 4");
extern f32 D_L03_001DE36C;
__asm__(".extern D_L03_001DE36C, 4");
extern f32 D_L03_001DE370;
__asm__(".extern D_L03_001DE370, 4");

extern void func_L03_0039AE90(u8 *m);
extern void func_L01_0044F450(void *, void *);
extern f32 func_003C41A0(void *, void *, f32, f32, f32, f32);
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);
extern s32 func_L03_0039AFB0();
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

typedef struct T_0039AA48 {
    u8 p0[0x4B0];
    f32 f4B0;
    u8 p4B4[0x1C];
    f32 f4D0;
    u8 p4D4[0x10];
    f32 f4E4;
    f32 f4E8;
    u8 p4EC[0x10];
    f32 f4FC;
    u8 p500[8];
    f32 f508;
} T_0039AA48;

void func_L03_0039AA48(u8 *o) {
    T_0039AA48 *t;
    f32 s;
    f32 w;

    t = *(T_0039AA48 **)(o + 0x68);
    func_L03_0039AE90(o);
    func_L01_0044F450(o, t);
    switch (o[0x20]) {
    case 1:
        break;
    case 2:
        func_003C41A0(o + 0x18, (u8 *)t + 0x500, D_L03_001DE35C, D_L03_001DE358 * 0.00040000002f, D_L03_001DE358 * 0.00040000002f, D_L03_001DE354 * 0.020000001f);
        if (*(f32 *)(o + 0x18) <= D_L03_001DE35C) {
            func_L01_004450F0(o, 3, -1);
        }
        if (func_L03_0039AFB0(o) != 0) {
            return;
        }
        func_L01_004450F0(o, 8, -1);
        return;
    case 3:
        func_L01_00448890(&t->f4B0, (u8 *)t + 0x504, 0, D_L03_001DE368 * 0.017453292f, D_L03_001DE364 * 0.017453292f * 0.00040000002f, D_L03_001DE364 * 0.017453292f * 0.00040000002f, D_L03_001DE360 * 0.017453292f * 0.020000001f);
        t->f4D0 = t->f4B0;
        if (t->f4B0 == D_L03_001DE368 * 0.017453292f) {
            func_L01_004450F0(o, 4, -1);
        }
        if (func_L03_0039AFB0(o) != 0) {
            return;
        }
        func_L01_004450F0(o, 7, -1);
        return;
    case 4:
        t->f508 = t->f508 + D_L03_001DE370 * 1.2f;
        if (1.0f <= t->f508) {
            t->f508 = 1.0f;
            func_L01_004450F0(o, 5, -1);
        }
        s = (1.0f - func_0038D098(t->f508 * 3.1415927f)) * 0.5f;
        t->f4E4 = -D_L03_001DE36C * func_0038D0B0(t->f4D0) * s;
        t->f4E8 = D_L03_001DE36C * func_0038D098(t->f4D0) * s;
        if (func_L03_0039AFB0(o) != 0) {
            return;
        }
        func_L01_004450F0(o, 6, -1);
        return;
    case 5:
        if (func_L03_0039AFB0(o) != 0) {
            return;
        }
        func_L01_004450F0(o, 6, -1);
        return;
    case 6:
        t->f508 = t->f508 - D_L03_001DE370 * 1.2f;
        if (t->f508 <= 0.0f) {
            t->f508 = 0.0f;
            func_L01_004450F0(o, 7, -1);
        }
        w = (1.0f - func_0038D098(t->f508 * 3.1415927f)) * 0.5f;
        t->f4E4 = -D_L03_001DE36C * func_0038D0B0(t->f4D0) * w;
        t->f4E8 = D_L03_001DE36C * func_0038D098(t->f4D0) * w;
        if (func_L03_0039AFB0(o) == 0) {
            return;
        }
        func_L01_004450F0(o, 4, -1);
        return;
    case 7:
        func_L01_00448890(&t->f4B0, (u8 *)t + 0x504, 0, 0.0f, D_L03_001DE364 * 0.017453292f * 0.00040000002f, D_L03_001DE364 * 0.017453292f * 0.00040000002f, D_L03_001DE360 * 0.017453292f * 0.020000001f);
        t->f4D0 = t->f4B0;
        if (t->f4B0 == 0.0f) {
            func_L01_004450F0(o, 8, -1);
        }
        if (func_L03_0039AFB0(o) == 0) {
            return;
        }
        func_L01_004450F0(o, 3, -1);
        return;
    case 8:
        func_003C41A0(o + 0x18, (u8 *)t + 0x500, t->f4FC, D_L03_001DE358 * 0.00040000002f, D_L03_001DE358 * 0.00040000002f, D_L03_001DE354 * 0.020000001f);
        if (t->f4FC <= *(f32 *)(o + 0x18)) {
            func_L01_004450F0(o, 1, -1);
        }
        if (func_L03_0039AFB0(o) != 0) {
            func_L01_004450F0(o, 2, -1);
        }
        return;
    }
}
/* localdecomp:end func_L03_0039AA48 */

/* localdecomp:start func_L03_0039AE90 */
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044F888(void *, s32, s32, void *, s32);
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);

void func_L03_0039AE90(u8 *m) {
    u8 *v;
    s32 i;
    if (m[0x20] != 0) {
        return;
    }
    v = *(u8 **)(m + 0x68);
    *(f32 *)(v + 0x4FC) = *(f32 *)(m + 0x18);
    *(s32 *)(v + 0x500) = 0;
    func_L01_0044ED88(m, v, 0xF, *(s32 *)(v + 0x4F0), *(s32 *)(v + 0x4F4), -1, 7, 0);
    for (i = 0; i < 15; i++) {
        u8 *e = (u8 *)((s32)v + i * 0x50);
        if (e[0x4C] == 0) {
            u8 *t = (u8 *)D_L03_001DF99C + (*(s16 *)(e + 0x48) << 8);
            if (*(s16 *)(t + 0xAA) == 0x191F) {
                func_L01_0044F888(v, 0, *(s16 *)(e + 0x48), v + 0x4B0, 0);
            }
            if (*(s16 *)(t + 0xAA) == 0x1920) {
                func_L01_0044F888(v, 0, *(s16 *)(e + 0x48), v + 0x4D0, 0);
            }
        }
    }
    func_L01_004450F0(m, 1, -1);
}
/* localdecomp:end func_L03_0039AE90 */

/* localdecomp:start func_L03_0039AFB0 */
typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003998B0;

extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);

s32 func_L03_0039AFB0(Moby_003998B0 *m) {
    s32 r;
    s32 id = *(s32 *)(m->w68 + 1272);
    if (id == -1) {
        r = 0;
    } else {
        r = func_00382380(D_001A4C60, id, 0) != 0;
    }
    return r;
}
/* localdecomp:end func_L03_0039AFB0 */
