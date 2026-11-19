#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003B7408);

INCLUDE_ASM("asm/levels", func_L07_003B7548);

/* localdecomp:start func_L07_003B7E40 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0044E7D8(void *);
extern void func_L07_003B8448(void *);
extern void func_L07_003B84C0(void *);

void func_L07_003B7E40(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 t;

    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    *(f32 *)(p + 0x40) = 1.0f;
    p[0x3E] = 3;
    *(u16 *)(p + 0x2A0) = *(u16 *)(p + 0x34);
    p[0x3F] = 0;
    p[0x64] = 0;
    t = *(u16 *)(a0 + 0xB6);
    p[0x39] = 0;
    *(f32 *)(p + 0x90) = 2.5f;
    *(f32 *)(p + 0x94) = 1.2f;
    *(f32 *)(p + 0x98) = 1.2f;
    *(f32 *)(p + 0x9C) = 1.2f;
    *(f32 *)(p + 0xA0) = 3.1415927f;
    *(f32 *)(p + 0xC0) = 0.78539819f;
    *(f32 *)(p + 0xBC) = 0.00392f;
    *(f32 *)(p + 0xC4) = 0.5f;
    *(u16 *)(p + 0x2A2) = t;
    func_L01_0045BD78(a0, 0.0028000002f, 0.14000002f, 0.0050265486f, 0.12566371f);
    *(void **)(p + 0x194) = func_L07_003B84C0;
    *(void **)(p + 0x198) = func_L07_003B8448;
    *(u8 *)(p + 0x1AD) = 0xFF;
    *(s16 *)(p + 0x19C) = -1;
    *(s32 *)(p + 0x2A4) = func_L01_0044E7D8(a0);
    func_L07_003B8448(a0);
}
/* localdecomp:end func_L07_003B7E40 */

/* localdecomp:start func_L07_003B7F80 */
typedef struct { u8 pad[0x144]; u8 *owner; s32 ticks; } State_003B7F80;
typedef struct { u8 pad[0xBC]; u8 status; u8 padBD[0x100-0xBD]; } Row_003B7F80;
extern u8 D_L07_001E1EC0[];
extern u8 *D_L07_001DF41C;
void func_L07_003B7F80(u8 *self) {
    extern u8 *func_L01_00447490(void *, s32, s32);
    extern f32 func_L01_004474E8(void *, void *);
    extern void func_L01_00459BE8(void *, s32, f32);
    extern void func_003C4A40(void *, void *);
    extern void func_L01_0044ABD0(void *, void *);
    extern void func_L01_0044E820(void *, s32);
    extern void func_L07_003A7488(s32, s32, s32);
    extern void func_L07_003B8690(void *, s32);
    extern void func_L07_003A2380(s32, void *, s32, s32);
    extern void func_L07_003315B0(void *);
    extern void func_L01_0047C990(s32, s32, s32, f32);
    extern void func_L01_00456BD0(void *, s32);
    extern s32 func_L07_00333D20(void *);
    extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_L07_003B8870(u8 *);
    extern s32 func_L01_00456250(void *);
    extern s32 func_00382468(s32);
    extern void func_L01_00456230(void *, s32);
    extern s32 func_0038CB00(void *);
    extern void func_L07_004522E8(void *, s32, void *, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_004472C0(void *);
    u8 *vars;
    u8 *hit;
    s32 animation;
    f32 damage;
    vars = *(u8 **)(self + 0x68);
    if (self[0x20] == 1) return;
    hit = func_L01_00447490(self, -1, 0);
    damage = func_L01_004474E8(self, hit);
    self[0xA8] = 255;
    if ((*(u16 *)(self + 0x34) & 0x4000) && damage > 0.0f) {
        if (hit && *(u8 **)(hit + 0x20) && *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x1A1C) damage = 1.0f;
        *(f32 *)(vars + 0x30) -= damage;
        func_L01_00459BE8(self, vars[0x47], damage);
        vars[0x187] = 255;
        func_003C4A40(self, vars + 0x180);
        if (*(s16 *)(vars + 0x34) * 0.1f <= damage) {
            Row_003B7F80 *row = (Row_003B7F80 *)(D_L07_001DF41C + (*(s32 *)(vars + 0x280) << 8));
            if (!row->status) row->status = 2;
        }
    }
    func_L01_0044ABD0(self, vars + 0x180);
    if (*(s16 *)(vars + 0x180) == 0) func_L01_0044E820(self, *(s32 *)(vars + 0x2A4));
    if (vars[0x296] == 0) {
        if (*(f32 *)(vars + 0x30) < *(s16 *)(vars + 0x34) * 0.65f) {
            func_L07_003A7488(*(s32 *)(vars + 0x288), 0, 8);
            func_L07_003B8690(self, 13);
            vars[0x296] = 1;
            {
                Row_003B7F80 *row = (Row_003B7F80 *)((*(s32 *)(vars + 0x280) << 8) + (s32)D_L07_001DF41C);
                *(f32 *)(vars + 0x30) = *(s16 *)(vars + 0x34) * 0.65f;
                row->status = 3;
            }
        }
    } else if (vars[0x296] == 1) {
        if (*(f32 *)(vars + 0x30) < *(s16 *)(vars + 0x34) * 0.3f) {
            func_L07_003A7488(*(s32 *)(vars + 0x288), 0, 8);
            vars[0x296] = 2;
            {
                Row_003B7F80 *row = (Row_003B7F80 *)((*(s32 *)(vars + 0x280) << 8) + (s32)D_L07_001DF41C);
                *(f32 *)(vars + 0x30) = *(s16 *)(vars + 0x34) * 0.3f;
                row->status = 4;
            }
            func_L07_003A2380(10, self, 0, 100);
        }
    }
    if (*(f32 *)(vars + 0x30) <= 0.0f) {
        vars[0x299] = 0;
        func_L07_003A7488(*(s32 *)(vars + 0x288), 0, 8);
        func_L07_003B8690(self, 17);
        return;
    }
    if (vars[0x5E]) {
        func_L07_003315B0(self);
        vars[0x5E] = 0;
        return;
    }
    if (vars[0x60]) {
        func_L07_003315B0(self);
        vars[0x60] = 0;
        return;
    }
    if (vars[0x299]) {
        if ((*(State_003B7F80 *)D_L07_001E1EC0).owner != self && (*(State_003B7F80 *)D_L07_001E1EC0).owner == 0) {
            (*(State_003B7F80 *)D_L07_001E1EC0).owner = self;
            (*(State_003B7F80 *)D_L07_001E1EC0).ticks = 0;
        }
    } else if ((*(State_003B7F80 *)D_L07_001E1EC0).owner == self) (*(State_003B7F80 *)D_L07_001E1EC0).owner = 0;
    func_L01_0047C990(3, 2, (*(State_003B7F80 *)D_L07_001E1EC0).owner != self, *(f32 *)(vars + 0x30) / *(s16 *)(vars + 0x34));
    func_L01_00456BD0(self, 3);
    animation = func_L07_00333D20(*(void **)(vars + 0x190));
    func_L01_00456C98(self, 0.0f, 0.0f, 1.0f, animation, 0, 0, 0, 0, 1, 0, 0, 0);
    func_L07_003B8870(self);
    if (func_L01_00456250(self)) {
        if (*(s16 *)(vars + 0x29E) == 0) {
            Row_003B7F80 *row = (Row_003B7F80 *)(D_L07_001DF41C + (*(s32 *)(vars + 0x280) << 8));
            if (!row->status) row->status = 1;
            if (func_00382468(2)) func_L07_003A2380(0, self, 0, 100);
            else func_L07_003A2380(1, self, 0, 100);
            *(s16 *)(vars + 0x29E) = 1000;
        }
        func_L01_00456230(self, 0);
    }
    func_0038CB00(vars + 0x29C);
    func_L07_004522E8(self, 4, vars + 0x230, 2.5f);
    if (func_L01_0040E548(D_L07_001E1EC0, self + 0x10) < 5625.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 70;
    }
}
/* localdecomp:end func_L07_003B7F80 */

/* localdecomp:start func_L07_003B8448 */
extern void func_003C2880(s32 p);
extern void func_L07_00334740(void *);
extern void func_L07_003B8690(void *, s32);
extern u8 D_L07_001E1EC0[];

void func_L07_003B8448(void *arg0) {
    u8 *temp_s0;
    s32 temp_a0;
    u8 *g;

    temp_s0 = *(u8 **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x288);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x288) = 0;
    }
    *(u8 *)(temp_s0 + 0x187) = 0;
    *(u8 *)(temp_s0 + 0x188) = 0;
    *(u8 *)(temp_s0 + 0x189) = 0;
    g = D_L07_001E1EC0;
    if (*(void **)(g + 0x144) == arg0) {
        *(void **)(g + 0x144) = 0;
    }
    func_L07_00334740(arg0);
    func_L07_003B8690(arg0, 1);
}
/* localdecomp:end func_L07_003B8448 */

INCLUDE_ASM("asm/levels", func_L07_003B84C0);

/* localdecomp:start func_L07_003B8690 */
void func_L07_003B8690(void *arg, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *m=arg;
    switch(state) {
    case 1: break;
    case 2:
        if(m[0x43] != 12) func_003C3A10(m,12,0,0);
        break;
    case 5:
        if(m[0x43] != 9) func_003C3A10(m,9,0,3);
        break;
    case 6:
        if(m[0x43] != 6) func_003C3A10(m,6,0,3);
        break;
    case 7:
        if(m[0x43] != 10) func_003C3A10(m,10,0,3);
        break;
    case 8:
        if(m[0x43] != 4) func_003C3A10(m,4,0,3);
        break;
    case 9:
        if(m[0x43] != 5) func_003C3A10(m,5,0,3);
        break;
    case 10:
        if(m[0x43] != 1) func_003C3A10(m,1,0,3);
        break;
    case 11:
        if(m[0x43] != 2) func_003C3A10(m,2,0,3);
        break;
    case 12:
        if(m[0x43] != 3) func_003C3A10(m,3,0,3);
        break;
    case 13:
        if(m[0x43] != 15) func_003C3A10(m,15,0,3);
        break;
    case 14:
        if(m[0x43] != 12) func_003C3A10(m,12,0,3);
        break;
    case 15:
        if(m[0x43] != 14) func_003C3A10(m,14,0,3);
        break;
    case 16:
        if(m[0x43] != 13) func_003C3A10(m,13,0,3);
        break;
    case 17:
        if(m[0x43] != 16) func_003C3A10(m,16,0,3);
        break;
    }
    func_L01_004450F0(m,state,-1);
}
/* localdecomp:end func_L07_003B8690 */

/* localdecomp:start func_L07_003B8870 */
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L07_003B8870(u8 *arg0) {
    u8 *o = *(u8 **)(arg0 + 0x68);

    if (*(f32 *)(o + 0x218) > 1.3962634f) {
        *(f32 *)(o + 0x218) = 1.3962634f;
    } else if (*(f32 *)(o + 0x218) < -1.3962634f) {
        *(f32 *)(o + 0x218) = -1.3962634f;
    }
    func_L01_0044E850(arg0, o + 0x1B0, 1, 0.0432f, 0.43200005f);
}
/* localdecomp:end func_L07_003B8870 */

/* localdecomp:start func_L07_003B88F0 */
extern u8 *D_L07_001DF41C_sda;
__asm__(".extern D_L07_001DF41C_sda, 4");

extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);

void func_L07_003B88F0(u8 *arg0) {
    u8 *s;
    u8 *p;
    u8 *q;
    f32 r;

    s = *(u8 **)(arg0 + 0x68);
    if (s[0x298] & 4) {
        p = D_L07_001DF41C_sda + (*(s32 *)(s + 0x280) << 8) + 0x10;
    } else {
        u8 flag = s[0x298];
        if (0.0f < *(f32 *)(s + 0x138)) {
            if (flag & 1) {
                p = *(u8 **)(s + 0x190) + 0x10;
            } else {
                p = s + 0x70;
            }
        } else {
            if (flag & 2) {
                p = *(u8 **)(s + 0x190) + 0x10;
            } else {
                p = s + 0x70;
            }
        }
    }
    q = arg0 + 0xF8;
    r = func_0038D160(*(f32 *)p - *(f32 *)(arg0 + 0x10),
                      *(f32 *)(p + 4) - *(f32 *)(arg0 + 0x14));
    func_L01_00448890((char *)q, (char *)s + 0x144, 0, r, *(f32 *)(s + 0xA4),
                  *(f32 *)(s + 0xA8), *(f32 *)(s + 0xAC));
}
/* localdecomp:end func_L07_003B88F0 */

/* localdecomp:start func_L07_003B89C0 */
void func_L07_003B89C0(int a, void (*fn)(void)) {
    if (fn)
        fn();
}
/* localdecomp:end func_L07_003B89C0 */

INCLUDE_ASM("asm/levels", func_L07_003B89E0);

INCLUDE_ASM("asm/levels", func_L07_003B8AE0);

/* localdecomp:start func_L07_003B8BA0 */
extern f32 func_0038D160(f32, f32);
extern void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
extern void func_L07_003B8690(void *, s32);

void func_L07_003B8BA0(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u8 *t = *(u8 **)(s + 0x190);
    f32 a;

    a = func_0038D160(*(f32 *)(t + 0x10) - *(f32 *)(s + 0x70),
                      *(f32 *)(t + 0x14) - *(f32 *)(s + 0x74));
    func_L03_0032FAF0((f32 *)(s + 0x270), (f32 *)(*(u8 **)(s + 0x190) + 0x10),
                      (f32)(s32)(a / 0.785398f) * 0.785398f, 20.0f);
    *(s32 *)(s + 0x290) = 0;
    *(u8 *)(s + 0x298) = 0;
    *(u8 *)(s + 0x297) = 6;
    func_L07_003B8690(arg0, 10);
}
/* localdecomp:end func_L07_003B8BA0 */

/* localdecomp:start func_L07_003B8C50 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L07_001DF500_003B8C50;
extern void func_L07_003A2380(s32, void *, s32, s32);
extern void func_L07_003B8690(void *, s32);

void func_L07_003B8C50(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (s[0x296] == 1) {
        func_L07_003A2380(0xF, a0, 0, 0x64);
    }
    s[0x299] = 0;
    *(u128_t *)(s + 0x270) = *(u128_t *)(&D_L07_001DF500_003B8C50[(*(s32 *)(s + 0x284) << 7) + 0x30]);
    s[0x298] = 2;
    s[0x297] = 0xE;
    *(s32 *)(s + 0x290) = 0;
    func_L07_003B8690(a0, 10);
}
/* localdecomp:end func_L07_003B8C50 */

/* localdecomp:start func_L07_003B8CE0 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern void func_L07_003B8690(void *, s32);

void func_L07_003B8CE0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    s[0x299] = 1;
    vec_sub_ab(s + 0x270, a0 + 0x10, *(u8 **)(s + 0x190) + 0x10);
    *(s32 *)(s + 0x278) = 0;
    func_0038CF68(s + 0x270, s + 0x270, 20.0f);
    vec_add_ba(s + 0x270, *(u8 **)(s + 0x190) + 0x10, s + 0x270);
    s[0x298] = 1;
    *(s32 *)(s + 0x290) = 0;
    s[0x297] = 5;
    func_L07_003B8690(a0, 10);
    a0[0xBC] = 0;
}
/* localdecomp:end func_L07_003B8CE0 */

INCLUDE_ASM("asm/levels", func_L07_003B8D80);

/* localdecomp:start func_L07_003B8F88 */
void func_L07_003B8FC0(void *, s32);

void func_L07_003B8F88(void *arg0) {
    func_L07_003B8FC0(arg0, 2);
    func_L07_003B8FC0(arg0, 3);
}
/* localdecomp:end func_L07_003B8F88 */

INCLUDE_ASM("asm/levels", func_L07_003B8FC0);
