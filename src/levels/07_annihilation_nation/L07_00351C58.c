#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00351C58);

/* localdecomp:start func_L07_00352510 */
typedef struct {
    u8 pad0[48];
    f32 hp;
    s16 life;
    u8 pad36[14];
    u8 d0;
    u8 d1;
    u8 d2;
    u8 pad47[57];
    u8 b80;
    u8 pad81[31];
    f32 a0;
    f32 a4;
    u8 padA8[4];
    f32 ac;
    u8 padB0[8];
    u8 b8;
    u8 padB9[103];
    f32 f120;
    s32 flags;
    u8 pad128[40];
    f32 f150;
    f32 f154;
    f32 f158;
    f32 f15c;
    f32 f160;
    u8 pad164[24];
    f32 f17c;
    f32 f180;
    f32 f184;
    u8 pad188[188];
    void (*cb244)(s32);
    void (*cb248)(s32);
    s16 h24c;
    u8 pad24E[15];
    u8 b25d;
    u8 pad25E[1];
    u8 b25f;
    u8 pad260[512];
    s32 f460;
} Vars_00352510;
void func_L07_00352510(u8 *self) {
    extern s32 func_L07_003C1AF8(void);
    extern f32 func_L07_003C1B40(s32);
    extern void func_L01_00446058(void *, s32, s32);
    extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
    extern void func_L07_00352A88(s32);
    extern void func_L07_00352A58(s32);
    Vars_00352510 *v = *(Vars_00352510 **)(self + 0x68);
    s32 mode = func_L07_003C1AF8();
    u8 *p = (u8 *)v + 0x30;
    f32 factor = func_L07_003C1B40(mode);
    *(s16 *)(p + 4) = v->life * factor;
    v->hp = *(s16 *)(p + 4);
    p[0x14] = v->d0 * factor;
    p[0x15] = v->d1 * factor;
    p[0x16] = v->d2 * factor;
    if (mode == 1 || mode == 3) func_L01_00446058(self, 0x1D8B, 0x1769);
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = 1.25f;
    p[0xF] = 0;
    p[9] = 0;
    v->b8 = 255;
    v->b80 = 5;
    v->f120 = 1.0f;
    v->flags |= 1;
    v->f150 = 0.65f;
    v->a4 = v->a0 = 0.5f;
    v->f154 = v->ac = 0.15f;
    v->f15c = v->f158 = 0.5f;
    v->f160 = 3.1415927f;
    v->f180 = 0.7853982f;
    v->f17c = 0.003920000046491623f;
    v->f184 = 0.2f;
    func_L01_0045BD78(self, 0.003200000151991844f, 0.05000000447034836f, 0.005026548635214567f, 0.12566371262073517f);
    { void (*cb244)(s32) = func_L07_00352A88;
    void (*cb248)(s32) = func_L07_00352A58;
    v->f460 = 0;
    v->cb248 = cb248;
    v->b25d = 2;
    v->h24c = -1;
    v->b25f = 7;
    v->cb244 = cb244; }
    func_L07_00352A58((s32)self);
}
/* localdecomp:end func_L07_00352510 */

/* localdecomp:start func_L07_00352758 */
#include "vu0.h"
void func_L07_00352758(u8 *self)
{
    extern u8 D_L07_001E1EC0[];
    extern s32 func_L01_00452FB0(u8 *, u8 *, s32, s32, s32);
    extern void func_L07_003333F8(s32, f32, f32);
    extern void func_L07_00334588(u8 *);
    extern void func_L01_00446A70(u8 *, u8 *, s32, void *, void *, f32);
    extern void func_L07_003315B0(u8 *);
    extern void func_L07_00331158(u8 *);
    extern void func_L01_00404808(void *, void *);
    extern void func_L07_00353E10(u8 *);
    extern void func_003C2F58(u8 *, s32, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_0044E850(u8 *, u8 *, s32, f32, f32);
    extern void func_L07_004522E8(u8 *, s32, u8 *, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_004472C0(u8 *);
    extern void func_L01_00446780(u8 *, u8 *, s32, f32, f32, f32, s32, s32, s32);
    vu0_v4 pos;
    u8 *p = *(u8 **)(self + 0x68);
    f32 health, angle;
    if (self[0x20] == 1) return;
    health = *(f32 *)(p + 0x30);
    if (func_L01_00452FB0(self, p + 0x70, 0, 0, 0)) {
        func_L07_003333F8(*(s32 *)(p + 0x240), health, *(f32 *)(p + 0x30));
        p[0x467] = 0;
        func_L07_00334588(self);
    }
    if (*(s32 *)(p + 0x228) == 1) {
        qzero(&pos);
        func_L01_00446A70(self, self, 0x10000, &pos, &pos, *(s16 *)(p + 0x34));
    } else if (p[0x5E] || p[0x60] || p[0x3E] == 2) {
        func_L07_003315B0(self);
        return;
    }
    func_L07_00331158(self);
    *(f32 *)(p + 0x460) -= -0.120000005f;
    if (*(f32 *)(p + 0x460) < 0.0f) *(f32 *)(p + 0x460) += 1.0f;
    func_L01_00404808(func_L07_00353E10, self);
    if (*(s16 *)(p + 0x144) == 1) {
        func_003C2F58(self, 9, &pos);
        angle = func_0038D160(*(f32 *)(*(u8 **)(p + 0x140) + 0x10) - pos.x,
                             *(f32 *)(*(u8 **)(p + 0x140) + 0x14) - pos.y);
        *(f32 *)(p + 0x2C8) = func_0038DB00(angle, *(f32 *)(self + 0xF8));
        if (*(f32 *)(p + 0x2C8) > 0.78539819f) *(f32 *)(p + 0x2C8) = 0.78539819f;
        else if (*(f32 *)(p + 0x2C8) < -0.78539819f) *(f32 *)(p + 0x2C8) = -0.78539819f;
        angle = func_0038CF38(&pos, *(u8 **)(p + 0x140) + 0x10);
        *(f32 *)(p + 0x2C4) = -func_0038D160(angle, *(f32 *)(*(u8 **)(p + 0x140) + 0x18) - pos.z);
        if (*(f32 *)(p + 0x2C4) > 0.52359879f) *(f32 *)(p + 0x2C4) = 0.52359879f;
        else if (*(f32 *)(p + 0x2C4) < -0.52359879f) *(f32 *)(p + 0x2C4) = -0.52359879f;
    }
    func_L01_0044E850(self, p + 0x260, 9, 0.0432f, 0.43200004f);
    func_L07_004522E8(self, 10, p + 0x2E0, 2.5f);
    if (self[0x31] && func_L01_0040E548(D_L07_001E1EC0, self + 0x10) < 576.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 22;
    }
    func_L01_00446780(self, self + 0x10, 0x8000000, 0.8f, 1.0f, 1.0f, 0, 1, 0);
}
/* localdecomp:end func_L07_00352758 */

/* localdecomp:start func_L07_00352A58 */
void func_L07_00334740();
void func_L07_00352AC8(s32, s32);

void func_L07_00352A58(s32 arg0) {
    func_L07_00334740();
    func_L07_00352AC8(arg0, 1);
}
/* localdecomp:end func_L07_00352A58 */

/* localdecomp:start func_L07_00352A88 */
void func_L07_00352AC8(s32, s32);
void func_L07_00334800();

void func_L07_00352A88(s32 arg0) {
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(*(s32 *)(arg0 + 0x24) + 0x24);
    func_L07_00334800();
    func_L07_00352AC8(arg0, 2);
}
/* localdecomp:end func_L07_00352A88 */

/* localdecomp:start func_L07_00352AC8 */
void func_L07_00352AC8(s32 arg, s32 state)
{
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L07_00353D88();
    u8 *obj = (u8 *)arg;
    u8 *p = *(u8 **)(obj + 0x68);
    switch (state) {
    case 1: case 3: case 5: break;
    case 2:
        if (obj[0x43]) func_003C3A10(obj, 0, 0, 0);
        break;
    case 4:
        *(u16 *)(obj + 0x34) |= 0x5000;
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0048f;
        *(f32 *)(p + 0x178) = 0.100000009f;
        if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 7);
        break;
    case 6: case 7:
        if (obj[0x43]) func_003C3A10(obj, 0, 0, 4);
        break;
    case 8: case 24:
        *(f32 *)(p + 0x178) = 0.050000004f;
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0032000002f;
        if (*(f32 *)(p + 0x200) > *(f32 *)(p + 0x178)) {
            func_0038CF68(p + 0x1F0, p + 0x1F0, *(f32 *)(p + 0x178));
            *(f32 *)(p + 0x200) = *(f32 *)(p + 0x178);
        }
        if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 2);
        break;
    case 9:
        *(f32 *)(p + 0x178) = 0.100000009f;
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0048f;
        if (*(f32 *)(p + 0x200) > *(f32 *)(p + 0x178)) {
            func_0038CF68(p + 0x1F0, p + 0x1F0, *(f32 *)(p + 0x178));
            *(f32 *)(p + 0x200) = *(f32 *)(p + 0x178);
        }
        if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 2);
        break;
    case 10:
        *(f32 *)(p + 0x174) = *(f32 *)(p + 0x170) = 0.0072000003f;
        *(f32 *)(p + 0x178) = 0.16000001f;
        if (obj[0x43] != 4) func_003C3A10(obj, 4, 0, 2);
        break;
    case 11:
        if (obj[0x43] != 5) func_003C3A10(obj, 5, 0, 2);
        break;
    case 12:
        if (obj[0x43] != 6) func_003C3A10(obj, 6, 0, 7);
        break;
    case 13:
        if (obj[0x43] != 10) func_003C3A10(obj, 10, 8, 7);
        break;
    case 14:
        if (obj[0x43] != 11) func_003C3A10(obj, 11, 8, 7);
        break;
    case 15:
        func_L07_00353D88(obj);
        p[0x467] = 1;
        if (obj[0x43] != 12) func_003C3A10(obj, 12, 10, 7);
        break;
    case 16:
        func_L07_00353D88(obj);
        p[0x467] = 1;
        if (obj[0x43] != 13) func_003C3A10(obj, 13, 4, 2);
        break;
    case 17:
        if (obj[0x43] != 14) func_003C3A10(obj, 14, 0, 2);
        break;
    case 18:
        if (obj[0x43] != 8) func_003C3A10(obj, 8, 0, 2);
        break;
    case 19:
        if (obj[0x43] != 7) func_003C3A10(obj, 7, 0, 2);
        break;
    case 20:
        if (obj[0x43] != 9) func_003C3A10(obj, 9, 5, 5);
        break;
    case 21:
        func_L07_00353D88(obj);
        p[0x467] = 1;
        if (obj[0x43] != 15) func_003C3A10(obj, 15, 10, 5);
        break;
    case 22:
        if (obj[0x43] != 16) func_003C3A10(obj, 16, 9, 6);
        break;
    case 23:
        if (obj[0x43] != 17) func_003C3A10(obj, 17, 0, 2);
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_00352AC8 */

/* localdecomp:start func_L07_00352E88 */
extern f32 func_L07_00353D60(u8 *);
extern void func_L07_00352AC8(s32, s32);
extern void func_L07_00352F30(u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045AA10(u8 *);
extern u8 D_L07_001DD604[];

void func_L07_00352E88(u8 *self) {
    u8 *o;
    f32 r;
    f32 t;
    f32 *p;

    o = *(u8 **)(self + 0x68);
    t = func_L07_00353D60(self);
    p = (f32 *)(D_L07_001DD604 + (s32)o[0x464] * 8);
    r = *p - 0.5f;
    if (r > t) {
        f32 d;
        func_L07_00352AC8((s32)self, 8);
        d = func_0038D160(*(f32 *)(o + 0x130) - *(f32 *)(self + 0x10),
                          *(f32 *)(o + 0x134) - *(f32 *)(self + 0x14));
        ((void (*)(u8 *, f32))func_L01_0045AA10)(self, d);
    } else {
        func_L07_00352F30(self, r);
    }
}
/* localdecomp:end func_L07_00352E88 */

/* localdecomp:start func_L07_00352F30 */
extern s32 D_L07_001DEF40[1];
extern void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L07_00332CF0(s32, void *, f32 *, f32);
extern void func_L07_00333DB8(s32, void *, s32, s32, f32);
extern s32 func_L01_0045A7A8(void *, f32 *, f32);

void func_L07_00352F30(u8 *arg0, f32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 buf[4];
    f32 d;
    s32 g;
    s32 b;

    func_L03_0032FAF0(buf, (f32 *)(p + 0x130), *(f32 *)(p + 0x254), arg1);
    g = D_L07_001DEF40[0] & 7;
    b = ((s32)arg0 >> 8) & 7;
    if (g == b) {
        d = func_0038DB00(*(f32 *)(p + 0x250), *(f32 *)(p + 0x254));
        *(f32 *)(p + 0x258) = func_L07_00332CF0(*(s32 *)(p + 0x240), arg0, buf,
                                               d * 0.15f);
        func_L07_00333DB8(*(s32 *)(p + 0x240), arg0, 0, 0, arg1);
    }
    func_L01_0045A7A8(arg0, buf, *(f32 *)(p + 0x258));
}
/* localdecomp:end func_L07_00352F30 */

/* localdecomp:start func_L07_00352FF0 */
void func_L07_00352E88(u8 *);
s32 func_L07_00331008(s32, s32);
void func_L07_00352AC8(s32, s32);
s32 func_L07_00334408(u8 *);
s32 func_L07_003346D8(u8 *);
f32 func_L07_00353D60(u8 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern u8 D_L07_001DD604_sdata[] __attribute__((section(".sdata")));

void func_L07_00352FF0(u8 *arg0, f32 arg1) {
    u8 *o = *(u8 **)(arg0 + 0x68);
    f32 tab;
    f32 a;
    f32 ang;

    func_L07_00352E88(arg0);
    if (func_L07_00331008(*(s32 *)(o + 0x240), (s32)arg0) == 0) {
        func_L07_00352AC8((s32)arg0, 6);
        return;
    }
    a = func_0038DBA0(func_0038D160(*(f32 *)(o + 0x130) - *(f32 *)(arg0 + 0x10),
                                    *(f32 *)(o + 0x134) - *(f32 *)(arg0 + 0x14)),
                      *(f32 *)(arg0 + 0xF8));
    if (a < 0.7853982f) {
        ang = func_L07_00353D60(arg0);
        if (0.0f < arg1) {
            tab = *(f32 *)(D_L07_001DD604_sdata + o[0x464] * 8);
            if (ang < tab) {
                *(u16 *)(o + 0x24C) = func_L07_00334408(arg0);
                if (func_L07_003346D8(arg0) != 0) {
                    func_L07_00352AC8((s32)arg0, o[0x464] + 0xD);
                }
            } else if (arg1 + tab < ang) {
                func_L07_00352AC8((s32)arg0, 0xA);
            }
        } else {
            tab = *(f32 *)(D_L07_001DD604_sdata + o[0x464] * 8);
            if (ang < tab) {
                *(u16 *)(o + 0x24C) = func_L07_00334408(arg0);
                if (func_L07_003346D8(arg0) != 0) {
                    func_L07_00352AC8((s32)arg0, 0xC);
                }
            }
        }
    }
}
/* localdecomp:end func_L07_00352FF0 */

INCLUDE_ASM("asm/levels", func_L07_00353178);

/* localdecomp:start func_L07_003532D0 */
extern f32 func_L07_00353D60(u8 *);
void func_L07_00352AC8(s32, s32);

void func_L07_003532D0(u8 *arg0) {
    u8 *p;
    f32 t;

    p = *(u8 **)(arg0 + 0x68);
    t = func_L07_00353D60(arg0) - *(f32 *)(D_L07_001DD604 + p[0x464] * 8);
    if (t < 4.0f) {
        func_L07_00352AC8((s32)arg0, 8);
    } else if (t < 8.0f) {
        func_L07_00352AC8((s32)arg0, 9);
    } else {
        func_L07_00352AC8((s32)arg0, 10);
    }
}
/* localdecomp:end func_L07_003532D0 */

/* localdecomp:start func_L07_00353378 */
extern f32 func_L07_00353D60(u8 *);
extern s32 func_00382498(s32, s32);
extern f32 D_L07_001DD600;
extern u8 D_L07_001DD604_sdata[] __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DD600, 4");

s32 func_L07_00353378(u8 *arg0, u8 arg1) {
    u8 bits;
    u8 *o;
    f32 t;
    s32 i;

    o = *(u8 **)(arg0 + 0x68);
    t = func_L07_00353D60(arg0);
    bits = 0;
    i = 4;
    do {
        u8 n = func_00382498(0, --i);
        s32 k;

        do {
            for (k = 0; k < 4; k++) {
                if (n < k)
                    continue;
                if ((bits >> k) & 1)
                    n = n + 1;
            }
        } while (0);
        if (*(f32 *)((u8 *)&D_L07_001DD600 + n * 8) <= t) {
            if (arg1 == 0)
                return n;
            if (n != o[0x464] && t <= *(f32 *)(D_L07_001DD604_sdata + n * 8))
                return n;
        }
        bits |= 1 << n;
    } while (i > 0);
    return -1;
}
/* localdecomp:end func_L07_00353378 */

/* localdecomp:start func_L07_00353498 */
extern s32 func_00382498(s32, s32);
extern s32 func_L07_00353820(s32, s32, s32, f32);
extern void func_L07_00352AC8(s32, s32);

s32 func_L07_00353498(s32 arg0) {
    u8 used = 0;
    s32 count;
    s32 slot;
    s32 i;
    s32 kind;
    s32 dir;
    f32 delay;

    for (count = 3; count > 0; count--) {
        slot = func_00382498(0, count - 1);
        for (i = 0; i < 3; i++) {
            if (slot < i) continue;
            slot += (used >> i) & 1;
        }
        if (slot == 2) {
            delay = 1.5f;
            kind = 0;
            dir = -1;
        } else {
            dir = slot == 1 ? -1 : 1;
            delay = 1.8f;
            kind = 1;
        }
        if (func_L07_00353820(arg0, kind, dir, delay) != 0) {
            func_L07_00352AC8(arg0, slot + 0x12);
            return 1;
        }
        used = (used | (1 << slot)) & 0xFF;
    }
    return 0;
}
/* localdecomp:end func_L07_00353498 */

/* localdecomp:start func_L07_003535B0 */
extern s32 func_00382498(s32, s32);
extern void func_L07_00352AC8(s32, s32);

void func_L07_003535B0(s32 arg0) {
    func_L07_00352AC8(arg0, func_00382498(0, 1) + 0x15);
}
/* localdecomp:end func_L07_003535B0 */

/* localdecomp:start func_L07_003535E8 */
extern s32 func_L01_0044E1B8_003535E8(void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_L07_00353378(u8 *, u8);
extern s32 func_L07_00331008(s32, s32);
extern void func_L07_00334588(s32);
extern s32 func_L07_00353820(s32, s32, s32, f32);
extern void func_L07_00352AC8(s32, s32);
extern s32 func_L07_00353498(s32);

void func_L07_003535E8(u8 *arg0) {
    u8 *o = *(u8 **)(arg0 + 0x68);
    s32 r;

    if (arg0[0x42] == arg0[0x43]) {
        if (func_L01_0044E1B8_003535E8(arg0) != 0) {
            r = -1;
            o[0x465] = o[0x465] + 1;
            o[0x467] = 0;
            if (o[0x466] == 0) {
                if (func_003824E0(0.0f, 1.0f) < 0.7f) {
                    r = func_L07_00353378(arg0, 1);
                }
            }
            if (func_L07_00331008(*(s32 *)(o + 0x240), arg0) == 0) {
                func_L07_00334588((s32)arg0);
                if (func_L07_00353820((s32)arg0, 0, -1, 3.0f) != 0) {
                    func_L07_00352AC8((s32)arg0, 0x14);
                } else {
                    func_L07_00352AC8((s32)arg0, 6);
                }
            } else {
                if (r == -1) {
                    func_L07_00334588((s32)arg0);
                    if (func_L07_00353498((s32)arg0) == 0) {
                        func_L07_00352AC8((s32)arg0, 7);
                    }
                } else {
                    o[0x464] = r;
                    func_L07_00352AC8((s32)arg0, r + 13);
                }
            }
        }
    }
}
/* localdecomp:end func_L07_003535E8 */

/* localdecomp:start func_L07_00353730 */
s32 func_L07_00331008(s32, s32);
void func_L07_003535B0(s32);
void func_L07_00352AC8(s32, s32);

void func_L07_00353730(s32 arg0) {
    u8 *handle = *(u8 **)(arg0 + 0x68);

    if (*(u8 *)(arg0 + 0x60) & 2) {
        if (handle[0x466] != 0) {
            func_L07_003535B0(arg0);
            handle[0x466] = 0;
        } else {
            if (func_L07_00331008(*(s32 *)(handle + 0x240), arg0) == 0) {
                func_L07_00352AC8(arg0, 6);
            } else {
                func_L07_00352AC8(arg0, 7);
            }
        }
    }
}
/* localdecomp:end func_L07_00353730 */

/* localdecomp:start func_L07_003537B0 */
extern s32 func_L01_0045A9F0(void *);
extern s32 func_L07_00331008(s32, s32);
extern void func_L07_00352AC8(s32, s32);

void func_L07_003537B0(s32 arg0) {
    u8 *handle = *(u8 **)(arg0 + 0x68);

    func_L01_0045A9F0((void *)arg0);
    if (*(u8 *)(arg0 + 0x60) & 2) {
        handle[0x467] = 0;
        if (func_L07_00331008(*(s32 *)(handle + 0x240), arg0) == 0) {
            func_L07_00352AC8(arg0, 6);
        } else {
            func_L07_00352AC8(arg0, 7);
        }
    }
}
/* localdecomp:end func_L07_003537B0 */

/* localdecomp:start func_L07_00353820 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L07_00333200(u8 *, u8 *, u8 *);

s32 func_L07_00353820(s32 arg0, s32 idx, s32 n, f32 scale) {
    u8 *self = (u8 *)arg0;
    u8 *s = *(u8 **)(self + 0x68);
    vu0_v4 tmp;

    func_0038CF68(&tmp, self + (idx * 16 + 0xC0), scale * (f32)n * 2.2f);
    vec_add_ba(&tmp, self + 0x10, &tmp);
    return func_L07_00333200(*(u8 **)(s + 0x240), self, (u8 *)&tmp);
}
/* localdecomp:end func_L07_00353820 */

/* localdecomp:start func_L07_003538A0 */
extern s32 func_L01_004468C8(u8 *, s32, s32, f32, f32, f32, s32, s32, s32);
extern s32 func_L07_00353D20(s32);

void func_L07_003538A0(u8 *arg0) {
    u8 *h = *(u8 **)(arg0 + 0x68);

    if (func_L07_00353D20(func_L01_004468C8(arg0, 4, 0x10001, 0.3f, (f32)h[0x44], 1.0f, 0, 1, 0)) != 0) {
        h[0x466]++;
    } else if (func_L07_00353D20(func_L01_004468C8(arg0, 5, 0x10001, 0.5f, (f32)h[0x44], 1.0f, 0, 1, 0)) != 0) {
        h[0x466]++;
    }
}
/* localdecomp:end func_L07_003538A0 */

/* localdecomp:start func_L07_00353980 */
extern s32 func_L07_00353D20(s32);

void func_L07_00353980(u8 *arg0) {
    u8 *h = *(u8 **)(arg0 + 0x68);

    if (func_L07_00353D20(func_L01_004468C8(arg0, 8, 0x10001, 0.75f, (f32)h[0x45], 1.0f, 0, 1, 0)) != 0) {
        h[0x466]++;
    } else if (func_L07_00353D20(func_L01_004468C8(arg0, 7, 0x10001, 0.45f, (f32)h[0x45], 1.0f, 0, 1, 0)) != 0) {
        h[0x466]++;
    } else if (func_L07_00353D20(func_L01_004468C8(arg0, 6, 0x10001, 0.25f, (f32)h[0x45], 1.0f, 0, 1, 0)) != 0) {
        h[0x466]++;
    }
}
/* localdecomp:end func_L07_00353980 */

INCLUDE_ASM("asm/levels", func_L07_00353AB0);

/* localdecomp:start func_L07_00353D20 */
extern s32 D_001A71A0[];
extern s32 D_L07_001ECC80[];

s32 func_L07_00353D20(s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (D_L07_001ECC80[i] == D_001A71A0[0]) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_00353D20 */

/* localdecomp:start func_L07_00353D60 */
void func_0038CF38(void *, s32);

void func_L07_00353D60_00353D60(void *arg0) __asm__("func_L07_00353D60");
void func_L07_00353D60_00353D60(void *arg0) {
    func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)arg0 + 0x68)) + 0x130);
}
/* localdecomp:end func_L07_00353D60 */

/* localdecomp:start func_L07_00353D88 */
typedef struct {
    u8 pad[0x68];
    u8 *p68;
} S_353D88;

void func_L07_00353D88(S_353D88 *a0) {
    u8 *p = a0->p68;

    p[0x468] = 0;
    p[0x469] = 0;
}
/* localdecomp:end func_L07_00353D88 */

/* localdecomp:start func_L07_00353D98 */
typedef int Q_00353D98 __attribute__((mode(TI)));

static __inline__ void copy_00353D98(Q_00353D98 *d, Q_00353D98 *s) {
    *d = *s;
}

typedef struct {
    u8 pad0[0x320];
    Q_00353D98 a[10];
    Q_00353D98 b[10];
    u8 pad460[0x8];
    u8 head;
    u8 count;
} S_00353D98;

void func_L07_00353D98(u8 *arg0, void *arg1, void *arg2) {
    S_00353D98 *s = *(S_00353D98 **)(arg0 + 0x68);
    int i;

    s->count++;
    if (s->count > 10) {
        s->head = (s->head + 1) % 10;
        s->count = 10;
    }
    i = (s->head + s->count - 1) % 10;
    copy_00353D98(&s->a[i], (Q_00353D98 *)arg1);
    copy_00353D98(&s->b[i], (Q_00353D98 *)arg2);
}
/* localdecomp:end func_L07_00353D98 */

/* localdecomp:start func_L07_00353E10 */
void func_L07_00353E10(u8 *self) {
    extern void func_003C2F58(u8 *, s32, void *);
    extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, f32);
    extern void func_L07_00353D98(u8 *, void *, void *);
    extern void func_L07_00353FF0(void *, void *, s32, s32, s32);
    f32 first[4] __attribute__((aligned(16)));
    f32 second[4] __attribute__((aligned(16)));
    u8 *vars = *(u8 **)(self+0x68);
    func_003C2F58(self,0,first);
    func_003C2F58(self,1,second);
    func_L01_0040A8C0(first,second,14,1,0.08f,0.75f,0x7F000080,0x7F000080,0x7F000080,0x7F000080,*(f32 *)(vars+0x460));
    func_L01_0040A8C0(first,second,14,1,0.018f,0.75f,0x6FFFFFFF,0x6FFFFFFF,0x6FFFFFFF,0x6FFFFFFF,*(f32 *)(vars+0x460));
    if (vars[0x467]) {
        func_L07_00353D98(self,first,second);
        func_L07_00353FF0(vars+0x320,vars+0x3C0,vars[0x469],vars[0x468],vars[0x46A]+100);
    }
    func_003C2F58(self,2,first);
    func_003C2F58(self,3,second);
    func_L01_0040A8C0(first,second,14,1,0.08f,0.75f,0x7F000080,0x7F000080,0x7F000080,0x7F000080,*(f32 *)(vars+0x460));
    func_L01_0040A8C0(first,second,14,1,0.018f,0.75f,0x6FFFFFFF,0x6FFFFFFF,0x6FFFFFFF,0x6FFFFFFF,*(f32 *)(vars+0x460));
}
/* localdecomp:end func_L07_00353E10 */

INCLUDE_ASM("asm/levels", func_L07_00353FF0);
