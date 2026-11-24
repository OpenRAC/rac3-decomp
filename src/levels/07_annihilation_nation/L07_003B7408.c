#include "common.h"

/* localdecomp:start func_L07_003B7408 */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_003B7408;
__asm__(".extern D_L07_001DE480,4");
extern V_003B7408 D_L07_001DE480 __attribute__((section(".sdata")));
void func_L07_003B7408(void *a, s32 b, f32 scale, f32 amount) {
    extern void func_003C2EC0(void *,s32,void *);
    extern void func_0038D890(void *,void *,void *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C4C18(void *,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_L01_0046E078(s32,void *,void *,void *,s32);
    V_003B7408 matrix[4],dir,scaled,pos,p,vel;
    V_003B7408 *color=&D_L07_001DE480;
    s32 i;
    func_003C2EC0(a,b,matrix);
    vec_neg(&dir,&matrix[2]);
    func_0038D890(&dir,&dir,&matrix[1],amount);
    func_0038CF68(&dir,&dir,1.0f);
    func_0038CE20(&scaled,&dir,scale);
    vec_add_ab(&pos,&matrix[3],&scaled);
    for(i=0;i<3;i++) {
        p.q=pos.q;
        func_003C4C18(&p,0.1f);
        func_0038CE20(&vel,&dir,func_003824E0(0.20000001788139343f,0.24000000953674316f));
        func_L01_0046E078(0,&p,&vel,color,i<2);
        color++;
    }
}
/* localdecomp:end func_L07_003B7408 */

/* localdecomp:start func_L07_003B7548 */
#include "vu0.h"
typedef struct { u8 b[16]; } Hit_003B7548;
extern u8 D_L07_001E1EC0[];
extern u8 *D_L07_001DF41C;
extern s32 D_L07_001D66B0;
__asm__(".extern D_L07_001D66B0, 16");
extern void func_L07_003B7E40(u8 *);
extern void func_L07_003B7F80(u8 *);
extern s32 func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L07_003B8690(void *, s32);
extern void func_L07_003B8C50(u8 *);
extern s32 func_L01_004561B8(void *);
extern void func_L07_003A2380(s32, void *, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L07_003B8D80(u8 *);
extern void func_L07_0030FFE8(void *, void *, s32, f32);
extern void func_L07_003B89E0(u8 *);
extern f32 func_L01_004395E0(void *);
extern void func_L07_003A7540(s32);
extern void func_L07_003A7488(s32, s32, s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L07_003B8BA0(u8 *);
extern void func_L07_003B8F88(void *);
extern void func_L07_003B88F0(u8 *);
extern s32 func_L01_0045A748(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_00382468(s32);
extern void func_L07_003B8CE0(u8 *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003315B0(void *);
extern void func_L07_003B89C0(int, void (*)(void));

void func_L07_003B7548(u8 *self) {
    u8 *p;

    if (self[0x20] == 0) func_L07_003B7E40(self);
    func_L07_003B7F80(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045A9F0(self);
        if (func_0038CB00(p + 0x19E)) func_L07_003B8690(self, 3);
        break;
    case 3:
        p[0x1AE] = 1;
        func_L07_003B8C50(self);
        break;
    case 5:
        if (func_L01_004561B8(self)) {
            *(u16 *)(self + 0x34) |= 0x5000;
            if (*(s16 *)(p + 0x29C) == 0) {
                ((s32 (*)(s32, void *, s32, s32))func_L07_003A2380)(16, self, 0, 100);
                *(s16 *)(p + 0x29C) = 333;
            }
        }
        if (self[0x60] & 2) func_L07_003B8690(self, 6);
        break;
    case 6:
        if (func_L01_004561B8(self)) p[0x29A] = 0;
        func_L01_0045A9F0(self);
        *(f32 *)(p + 0x218) = func_0038DB00(func_0038D160(*(f32 *)(p + 0x70) - *(f32 *)(self + 0x10),
                                                          *(f32 *)(p + 0x74) - *(f32 *)(self + 0x14)),
                                            *(f32 *)(self + 0xF8));
        if (self[0x42] == 6 && func_L01_0044E1B8(self, 20.5f)) {
            vu0_v4 pos;
            {
                u8 *g = D_L07_001E1EC0;
                f32 a;
                p[0x29A]++;
                *(f32 *)(g + 0x20) = 0.1f;
                *(s32 *)(g + 0x28) = 25;
                *(s32 *)(g + 0x2C) = 0;
                *(f32 *)(g + 0x40) = 0.1f;
                *(s32 *)(g + 0x48) = 25;
                func_L07_003B8D80(self);
                pos = *(vu0_v4 *)(self + 0x10);
                a = func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(p + 0x1F8));
                func_L07_0030FFE8(self, &pos, p[0x44], a);
            }
        }
        if (self[0x60] & 2) {
            if (p[0x296] == 0) {
                if (p[0x29A] >= 4) func_L07_003B8690(self, 7);
            } else if (p[0x29A] >= 5) {
                func_L07_003B89E0(self);
            }
        }
        break;
    case 7:
        func_L01_0045A9F0(self);
        if (self[0x60] & 2) func_L07_003B89E0(self);
        break;
    case 8:
        if (self[0x42] == 4) {
            f32 d = func_L01_004395E0(self);
            if (d >= 30.0f && d <= 50.0f) func_L07_003A7540(*(s32 *)(p + 0x288));
            if (func_L01_0044E1B8(self, 20.0f)) func_L07_003A7488(*(s32 *)(p + 0x288), 1, 8);
            if (func_L01_0044E1B8(self, 45.0f)) {
                func_L01_004AAC98(10, 0, self, 0x1A1F);
                func_L07_003A7488(*(s32 *)(p + 0x288), 2, 8);
            }
        }
        func_L01_0045A9F0(self);
        if (self[0x60] & 2) {
            func_L07_003A7488(*(s32 *)(p + 0x288), 0, 8);
            func_L07_003B8BA0(self);
        }
        break;
    case 9:
        if (self[0x42] == 5) {
            f32 d = func_L01_004395E0(self);
            if (d >= 30.0f && d <= 90.0f) func_L07_003A7540(*(s32 *)(p + 0x288));
            if (func_L01_0044E1B8(self, 15.0f) || func_L01_0044E1B8(self, 55.0f))
                func_L07_003A7488(*(s32 *)(p + 0x288), 1, 8);
            if (func_L01_0044E1B8(self, 45.0f) || func_L01_0044E1B8(self, 80.0f)) {
                func_L01_004AAC98(10, 0, self, 0x1A1F);
                func_L07_003A7488(*(s32 *)(p + 0x288), 2, 8);
            }
        }
        func_L01_0045A9F0(self);
        if (self[0x60] & 2) {
            func_L07_003A7488(*(s32 *)(p + 0x288), 0, 8);
            func_L07_003B8BA0(self);
        }
        break;
    case 10:
        if (func_L01_004561B8(self)) {
            u8 *q = p + 0x90;
            *(s32 *)(q + 0x38) |= 0x415;
            *(f32 *)(q + 0x20) = 0.072000004f;
            *(f32 *)(q + 0x28) = 0.40000004f;
            *(f32 *)(q + 0x24) = 0.072000004f;
        }
        if (self[0x42] == 1 && func_L01_004395E0(self) > 5.0f) {
            func_L07_003B8F88(self);
            func_L07_003B88F0(self);
            func_L01_0045A748(self, p + 0x270);
        } else {
            func_L01_0045A9F0(self);
        }
        if (self[0x60] & 2) func_L07_003B8690(self, 11);
        break;
    case 11: {
        vu0_v4 v;
        vu0_v4 *pv;
        f32 t;
        if (func_L01_004561B8(self)) *(f32 *)(p + 0x28C) = func_0038CF38(self + 0x10, p + 0x270);
        func_L07_003B8F88(self);
        func_L07_003B89C0((s32)self, *(void (**)(void))(p + 0x290));
        func_L07_003B88F0(self);
        pv = &v;
        *pv = *(vu0_v4 *)(p + 0x270);
        t = func_0038CF38(self + 0x10, pv);
        v.z += t * 20.0f / *(f32 *)(p + 0x28C) + 2.0f;
        if (func_L01_0045A748(self, pv) & 0x80) func_L07_003B8690(self, 12);
        break;
    }
    case 12:
        func_L07_003B89C0((s32)self, *(void (**)(void))(p + 0x290));
        if (self[0x42] != 3 || func_L01_004395E0(self) <= 3.0f) {
            func_L07_003B8F88(self);
            func_L07_003B88F0(self);
            func_L01_0045A748(self, p + 0x270);
        } else {
            if (func_L01_004561B8(self)) {
                if (p[0x297] != 14) {
                    u8 *g = D_L07_001E1EC0;
                    *(s32 *)(g + 0x2C) = 0;
                    *(f32 *)(g + 0x20) = 0.05f;
                    *(s32 *)(g + 0x28) = 12;
                    *(s32 *)(g + 0x48) = 12;
                    *(f32 *)(g + 0x40) = 0.05f;
                }
                func_L07_003B8D80(self);
            }
            *(s32 *)(p + 0xC8) &= ~0x415;
            func_L01_0045A9F0(self);
        }
        if (self[0x60] & 2) {
            if (p[0x296] == 0 && (p[0x29B] & 1)) {
                ((s32 (*)(s32, void *, s32, s32))func_L07_003A2380)(9, self, 0, 100);
                p[0x29B] |= 1;
            }
            func_L07_003B8690(self, p[0x297]);
        }
        break;
    case 13:
        if (func_L01_004561B8(self)) {
            *(s32 *)(p + 0xC8) &= ~0x415;
            *(u16 *)(self + 0x34) &= ~0x5000;
            if (*(f32 *)(p + 0x138) > 0.0f) *(f32 *)(p + 0x138) = 0.0f;
            if (p[0x296] == 1) func_L07_003A2380(3, D_L07_001DF41C + (*(s32 *)(p + 0x280) << 8), 0, 100);
        }
        func_L01_0045A9F0(self);
        if (self[0x60] & 2) func_L07_003B8C50(self);
        break;
    case 14:
        if (func_L01_004561B8(self)) *(s16 *)(p + 0x294) = func_00382468(100) + 200;
        func_L01_0045A9F0(self);
        func_0038CB00(p + 0x294);
        if (self[0xBC] == 3) {
            func_L07_003B8CE0(self);
        } else if (*(s16 *)(p + 0x294) == 0) {
            if (self[0xBC] == 2) {
                func_L07_003B8690(self, 15);
                self[0xBC] = 0;
            } else if (self[0xBC] == 1) {
                func_L07_003B8690(self, 16);
                self[0xBC] = 0;
            }
        }
        break;
    case 15:
    case 16:
        func_L01_0045A9F0(self);
        if (self[0x60] & 2) func_L07_003B8690(self, 14);
        break;
    case 17:
        func_L01_0045A9F0(self);
        if (self[0x60] & 2) {
            Hit_003B7548 saved = *(Hit_003B7548 *)(p + 0x180);
            func_L01_0043B9E8(self, saved.b[4], saved.b[5], saved.b[6]);
            func_L07_003A2380(7, D_L07_001DF41C + (*(s32 *)(p + 0x280) << 8), 0, 100);
            func_L01_00451FE0(self, 0x3FFF, &D_L07_001D66B0, 3.0f, 6.0f, 10.0f, 16.0f, -1.0f, -1.0f, 1.0f, 1.0f,
                              255, 180, 0, 0, 35, 0, 3);
            func_L07_003315B0(self);
        }
        break;
    }
}
/* localdecomp:end func_L07_003B7548 */

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

/* localdecomp:start func_L07_003B84C0 */
extern u8 D_001426E0[];
extern u8 D_00142660[];
extern s32 func_L07_003A7378(f32, u8 *, s32, void *, s32);
void func_L07_003B84C0(void *arg0) {
    u8 *self = arg0;
    extern s32 func_L01_0041A4F0(void);
    extern f32 func_L07_00334A98(s32);
    extern f32 func_L01_004DFE88(s32);
    extern void func_L07_00334800(u8 *);
    u8 *g = D_001426E0;
    u8 *p = *(u8 **)(self + 0x68);
    f32 ratio, health;
    u8 tint;
    vu0_v4 v;
    if (!g[0x83]) {
        g[0x83] = D_00142660[8];
        g[0xD7] = D_00142660[0x40];
    }
    if (func_L01_0041A4F0()) {
        *(s16 *)(p + 0x34) = 1000;
        *(f32 *)(p + 0x30) = 1000.0f;
        ratio = 1000.0f / (f32)*(s16 *)(p + 0x2A0);
    } else {
        ratio = func_L07_00334A98(g[0x83]);
        *(s16 *)(p + 0x34) = (f32)*(s16 *)(p + 0x2A0) * ratio;
        *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34);
    }
    health = ratio * (f32)*(s16 *)(p + 0x2A2);
    if (health > 65535.0f) health = 65535.0f;
    *(s16 *)(self + 0xB6) = health;
    tint = (u8)(((f32)D_001426E0[0x83] / func_L01_004DFE88(D_001426E0[0xD7])) * 0.125f);
    p[0x296] = 0;
    p[0x44] = tint;
    p[0x45] = tint;
    p[0x46] = tint;
    *(vu0_q *)&v = 0;
    v.z = 3.0f;
    *(s32 *)(p + 0x288) = func_L07_003A7378(*(f32 *)(*(u8 **)(p + 0x190) + 0x18), self, 0, &v, p[0x45]);
    p[0x299] = 0;
    p[0x29B] = 0;
    *(s16 *)(p + 0x29C) = 0;
    *(s16 *)(p + 0x29E) = 0;
    func_L07_00334800(self);
    func_L07_003B8690(self, 2);
}
/* localdecomp:end func_L07_003B84C0 */

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

/* localdecomp:start func_L07_003B89E0 */
extern void func_L07_003A2380(s32, void *, s32, s32);

extern f32 func_L01_0040E4C0(void *);
extern void func_L07_003B8690(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L07_003B8AE0(u8 *);

void func_L07_003B89E0(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    vu0_v4 d;
    s32 r;

    if (*(s16 *)(sub + 0x29E) == 0) {
        ((s32 (*)(s32, void *, s32, s32))func_L07_003A2380)(8, obj, 0, 100);
        *(s16 *)(sub + 0x29E) = 0x3E8;
    }
    vec_sub_ba(&d, obj + 0x10, sub + 0x70);
    d.z = 0.0f;
    r = 8;
    if (sub[0x296] != 0) {
        r = 9;
    }
    if (func_L01_0040E4C0(&d) < 144.0f) {
        func_L07_003B8690(obj, r);
        return;
    }
    func_0038CF68(&d, &d, 7.0f);
    vec_add_ab(sub + 0x270, sub + 0x70, &d);
    *(f32 *)(sub + 0x278) = *(f32 *)(*(u8 **)(sub + 0x190) + 0x18);
    sub[0x297] = r;
    sub[0x298] = 0;
    *(void **)(sub + 0x290) = func_L07_003B8AE0;
    func_L07_003B8690(obj, 10);
}
/* localdecomp:end func_L07_003B89E0 */

/* localdecomp:start func_L07_003B8AE0 */
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L07_003B8AE0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 loc;
    f32 d;
    f32 d2;

    d = func_0038CF38(a0 + 0x10, s + 0x270);
    vec_sub_ba(&loc, a0 + 0x10, s + 0x70);
    loc.z = 0.0f;
    func_0038CF68(&loc, &loc, 7.0f);
    vec_add_ab(s + 0x270, s + 0x70, &loc);
    *(f32 *)(s + 0x278) = *(f32 *)(*(u8 **)(s + 0x190) + 0x18);
    d2 = func_0038CF38(a0 + 0x10, s + 0x270);
    *(f32 *)(s + 0x28C) += d2 - d;
}
/* localdecomp:end func_L07_003B8AE0 */

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

/* localdecomp:start func_L07_003B8D80 */
/* localdecomp:start func_L07_003B8D80 */
typedef int Q_003B8D80 __attribute__((mode(TI)));
extern u8 *D_L07_0021EC98[];
void func_L07_003B8D80(u8 *obj) {
    extern void func_003C4C18(void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    Q_003B8D80 pos, vel;
    f32 speed, angle, pitch, x, y, z;
    s32 time, color;
    s32 i;
    u8 *particle;
    i = 119;
    do {
        pos=*(Q_003B8D80 *)(obj+0x10);
        func_003C4C18(&pos, 2.0f);
        speed=func_003824E0(0.10000000894069672f,0.20000001788139343f);
        angle=func_00382538();
        pitch=func_003824E0(0.0f,0.785398006439209f);
        func_00382760(&vel,speed,angle,pitch);
        func_003C4C18(&vel,0.06000000238418579f);
        time=func_00382498(40,80);
        color=func_0038DBD8(0x808080,0xFFFFFF,func_003824E0(0.0f,1.0f));
        x=func_003824E0(210000.0f,315000.0f);
        y=func_003824E0(630000.0f,1050000.0f);
        z=func_003824E0(0.0020000000949949026f,0.004000000189989805f);
        particle=func_L01_0046FB40(&pos,&vel,time,color,func_00382468(2)?3:-3,96,0,x,y,z,0);
        if (particle) {
            u8 value=D_L07_0021EC98[0x7C][1];
            particle[3]=68;
            particle[2]=value;
        }
    } while (--i >= 0);
}
/* localdecomp:end func_L07_003B8D80 */
/* localdecomp:end func_L07_003B8D80 */

/* localdecomp:start func_L07_003B8F88 */
void func_L07_003B8FC0(void *, s32);

void func_L07_003B8F88(void *arg0) {
    func_L07_003B8FC0(arg0, 2);
    func_L07_003B8FC0(arg0, 3);
}
/* localdecomp:end func_L07_003B8F88 */

/* localdecomp:start func_L07_003B8FC0 */
typedef union { u128_t q; f32 f[4]; } V_003B8FC0;
__asm__(".extern D_L07_001DE4B0,4");
extern V_003B8FC0 D_L07_001DE4B0 __attribute__((section(".sdata")));
void func_L07_003B8FC0(void *o,s32 n) {
    extern void func_003C2EC0(void *,s32,void *);
    extern void func_0038D890(void *,void *,void *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C4C18(void *,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_L01_0046E078(s32,void *,void *,void *,s32);
    V_003B8FC0 matrix[4],dir,pos,vel;
    V_003B8FC0 *color=&D_L07_001DE4B0;
    s32 i;
    f32 speed;
    func_003C2EC0(o,n,matrix);
    vec_neg(&dir,&matrix[2]);
    func_0038D890(&dir,&dir,&matrix[1],0.7853981852531433f);
    func_0038CF68(&dir,&dir,1.0f);
    for(i=0;i<3;i++) {
        pos.q=matrix[3].q;
        func_003C4C18(&pos,0.1f);
        speed=func_003824E0(0.20000001788139343f,0.24000000953674316f);
        func_0038CE20(&vel,&dir,speed);
        func_L01_0046E078(0,&pos,&vel,color,i<2);
        color++;
    }
}
/* localdecomp:end func_L07_003B8FC0 */
