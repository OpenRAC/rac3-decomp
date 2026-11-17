#include "common.h"

/* NTSC-U counterpart of func_L33_0034D838 (src/levels/33_vidcomic_2/L33_0034D190.c) */
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
typedef struct { u8 pad[0x25C0]; void *f25C0; } S_1A4BE0_0034D190;
extern S_1A4BE0_0034D190 D_001A4BE0;
extern f32 D_L33_001DD7F8_0034CC38;

/* localdecomp:start func_L33_0034CC38 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0034D838;

typedef struct {
    u8 pad0[0x60];
    f32 f60;
    u8 pad64[4];
    f32 f68;
    u8 pad6C[0x14];
    V_0034D838 v80;
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    u8 padA0[4];
    s32 fA4;
    s32 fA8;
    f32 fAC;
    s32 fB0;
    u8 padB4[4];
    f32 fB8;
    f32 fBC;
    u8 padC0[4];
    s32 fC4;
} Vars_0034D838;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x30];
    u16 f44;
} Ref_0034D838;

typedef struct {
    u8 pad0[0x10];
    V_0034D838 pos;
    u8 state;
    u8 pad21[3];
    Ref_0034D838 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0x12];
    f32 f48;
    u8 pad4C[0x14];
    u8 flags;
    u8 pad61[7];
    Vars_0034D838 *vars;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0x24];
    V_0034D838 vC0;
    V_0034D838 vD0;
    u8 padE0[0x18];
    f32 fF8;
} Moby_0034D838;

extern s32 func_L31_00345C88(void *, f32, f32, f32);
extern s32 func_L31_00345CF0(void *, void *, s32, f32);
extern void func_L31_00345960(f32, f32, f32, f32, f32, f32);
extern void func_L31_003459B0(f32, f32, f32, f32, f32, f32, f32);
extern void func_L31_00346000(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034C308(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L30_0034B9C8(void *, void *);
extern void func_L30_0034BDF0(void *, f32 *, f32 *, f32 *, f32 *);
extern s32 func_L32_003489D0(u8 *, f32 *, f32, f32, f32, f32, f32, f32, f32);
extern void *func_L33_0034F2C8(void *, void *, void *, s32, f32, f32, f32, f32, f32, s32);
void func_L33_0034EDB8(u8 *, f32, f32, s32, s32, s32, f32, f32, f32);
void func_L33_0034DE80(u8 *);
void func_L33_0034E008(u8 *, s32);
void func_L33_0034DCC0(u8 *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L01_00452F60(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389410(f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_003887C8(void *, void *);
extern s32 func_00388398(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_003BEB48(f32, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BD360(void *);

typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
    u8 pad90[0x10];
} Hero_0034D838;

extern f32 D_001A4C60[];
extern u8 D_001A30B0[];
extern u8 *D_L33_001DFC80;
typedef struct {
    u8 pad0[0x88];
    u8 *p88;
    u8 pad8C[0x1A4 - 0x8C];
    u8 *p1A4;
} Tbl_0034D838;

extern Tbl_0034D838 D_L33_0021F618;
extern u8 D_L33_001D66B0_0034CC38[8];
typedef struct {
    u8 pad0[8];
    f32 f8;
    u8 padC[4];
} H_0034D838;

typedef struct {
    u8 obj[0x10];
    s32 val;
} E_0034D838;

extern H_0034D838 D_L33_001E1820_0034CC38 __attribute__((section(".sdata")));
extern E_0034D838 D_L33_001E1850_0034CC38 __attribute__((section(".sdata")));

extern f32 D_L33_001DD5C0_0034CC38;
__asm__(".extern D_L33_001DD5C0_0034CC38, 4");
extern f32 D_L33_001DD5C4;
__asm__(".extern D_L33_001DD5C4, 4");
extern f32 D_L33_001DD5D0_0034CC38;
__asm__(".extern D_L33_001DD5D0_0034CC38, 4");
extern f32 D_L33_001DD5D4_0034CC38;
__asm__(".extern D_L33_001DD5D4_0034CC38, 4");
extern f32 D_L33_001DD5E4;
__asm__(".extern D_L33_001DD5E4, 4");
extern f32 D_L33_001DD5E8;
__asm__(".extern D_L33_001DD5E8, 4");
extern f32 D_L33_001DD5F0_0034CC38;
__asm__(".extern D_L33_001DD5F0_0034CC38, 4");
extern f32 D_L33_001DD5F4_0034CC38;
__asm__(".extern D_L33_001DD5F4_0034CC38, 4");
extern f32 D_L33_001DD5F8_0034CC38;
__asm__(".extern D_L33_001DD5F8_0034CC38, 4");
extern f32 D_L33_001DD60C_0034CC38;
__asm__(".extern D_L33_001DD60C_0034CC38, 4");
extern f32 D_L33_001DD610_0034CC38;
__asm__(".extern D_L33_001DD610_0034CC38, 4");
extern f32 D_L33_001DD614_0034CC38;
__asm__(".extern D_L33_001DD614_0034CC38, 4");
extern f32 D_L33_001DD618_0034CC38;
__asm__(".extern D_L33_001DD618_0034CC38, 4");
extern f32 D_L33_001DD62C;
__asm__(".extern D_L33_001DD62C, 4");
extern f32 D_L33_001DD630_0034CC38;
__asm__(".extern D_L33_001DD630_0034CC38, 4");
extern f32 D_L33_001DD638_0034CC38;
__asm__(".extern D_L33_001DD638_0034CC38, 4");
extern f32 D_L33_001DD63C;
__asm__(".extern D_L33_001DD63C, 4");
extern f32 D_L33_001DD640;
__asm__(".extern D_L33_001DD640, 4");
extern f32 D_L33_001DD64C;
__asm__(".extern D_L33_001DD64C, 4");
extern f32 D_L33_001DD654;
__asm__(".extern D_L33_001DD654, 4");
extern f32 D_L33_001DD658;
__asm__(".extern D_L33_001DD658, 4");
extern f32 D_L33_001DD65C;
__asm__(".extern D_L33_001DD65C, 4");
extern f32 D_L33_001DD660;
__asm__(".extern D_L33_001DD660, 4");
extern f32 D_L33_001DD664;
__asm__(".extern D_L33_001DD664, 4");
extern f32 D_L33_001DD670;
__asm__(".extern D_L33_001DD670, 4");
extern s32 D_L33_001DD7A0_0034CC38;
__asm__(".extern D_L33_001DD7A0_0034CC38, 4");
extern s32 D_L33_001DD7A4_0034CC38;
__asm__(".extern D_L33_001DD7A4_0034CC38, 4");
extern f32 D_L33_001DD7A8_0034CC38;
__asm__(".extern D_L33_001DD7A8_0034CC38, 4");
extern f32 D_L33_001DD7AC_0034CC38;
__asm__(".extern D_L33_001DD7AC_0034CC38, 4");
extern f32 D_L33_001DD7B0_0034CC38;
__asm__(".extern D_L33_001DD7B0_0034CC38, 4");
extern f32 D_L33_001DD7BC_0034CC38;
__asm__(".extern D_L33_001DD7BC_0034CC38, 4");
extern f32 D_L33_001DD7C0_0034CC38;
__asm__(".extern D_L33_001DD7C0_0034CC38, 4");
extern s32 D_L33_001DD7C4;
__asm__(".extern D_L33_001DD7C4, 4");
extern f32 D_L33_001DD7C8_0034CC38;
__asm__(".extern D_L33_001DD7C8_0034CC38, 4");
extern f32 D_L33_001DD7CC_0034CC38;
__asm__(".extern D_L33_001DD7CC_0034CC38, 4");
extern f32 D_L33_001DD7D0_0034CC38;
__asm__(".extern D_L33_001DD7D0_0034CC38, 4");
extern f32 D_L33_001DD7D4_0034CC38;
__asm__(".extern D_L33_001DD7D4_0034CC38, 4");
extern f32 D_L33_001DD7D8;
__asm__(".extern D_L33_001DD7D8, 4");
extern f32 D_L33_001DD7DC_0034CC38;
__asm__(".extern D_L33_001DD7DC_0034CC38, 4");
extern s32 D_L33_001DD7E0_0034CC38;
__asm__(".extern D_L33_001DD7E0_0034CC38, 4");
extern s32 D_L33_001DD7E4_0034CC38;
__asm__(".extern D_L33_001DD7E4_0034CC38, 4");
extern f32 D_L33_001DD7E8;
__asm__(".extern D_L33_001DD7E8, 4");
extern f32 D_L33_001DD7EC;
__asm__(".extern D_L33_001DD7EC, 4");
extern f32 D_L33_001DD7F0;
__asm__(".extern D_L33_001DD7F0, 4");
extern f32 D_L33_001DD7F4;
__asm__(".extern D_L33_001DD7F4, 4");
extern f32 D_L33_001DD7F8_0034CC38;
__asm__(".extern D_L33_001DD7F8_0034CC38, 4");
extern f32 D_L33_001DD7FC_0034CC38;
__asm__(".extern D_L33_001DD7FC_0034CC38, 4");
extern f32 D_L33_001DD800;
__asm__(".extern D_L33_001DD800, 4");

void func_L33_0034CC38(Moby_0034D838 *p) {
    Vars_0034D838 *s = p->vars;
    f32 rateB = D_L33_001DD7AC_0034CC38 * s->fAC / D_L33_001DD7B0_0034CC38;
    f32 rateA = D_L33_001DD658 * fabs_asm(s->f60) / D_L33_001DD660;
    s32 facing = func_L31_00345C88(p, D_L33_001DD5C0_0034CC38, D_L33_001DD5C4, D_L33_001DD60C_0034CC38) != 0;
    s32 left;
    s32 inZ;
    s32 inX;
    s32 seen;
    s32 ground;
    u8 *e;
    u8 *r;
    s32 v;
    s32 w;
    s32 i;
    u8 *o;
    f32 side;
    f32 spd;
    f32 a;
    f32 b;
    V_0034D838 v10;
    V_0034D838 v20;
    V_0034D838 v30;
    V_0034D838 v40;
    V_0034D838 v50;
    f32 x;
    f32 x2;
    f32 e2;
    f32 r2;
    f32 m2;
    f32 z;
    f32 lo;
    f32 hi;

    a = fabs_asm(func_003893C8(D_L33_001DD5C0_0034CC38, p->fF8));
    left = 1;
    if (!(a < fabs_asm(func_003893C8(D_L33_001DD5C4, p->fF8)))) {
        left = 0;
    }
    inZ = 0;
    if (((Hero_0034D838 *)&D_001A4BE0)->pos[2] < s->fBC + p->pos.z) {
        if (p->pos.z - s->fBC < ((Hero_0034D838 *)&D_001A4BE0)->pos[2]) {
            inZ = 1;
        }
    }
    inX = fabs_asm(((Hero_0034D838 *)&D_001A4BE0)->pos[0] - p->pos.x) < s->fB8;
    seen = 0;
    if (s->f90 == -1 || func_0037E0F0(((Hero_0034D838 *)&D_001A4BE0)->pos, s->f90, 0) != 0) {
        seen = 1;
    }
    ground = func_L31_00345CF0(p, &p->pos, 0, D_L33_001DD65C) != 0;

    switch (p->state) {
    case 1:
        D_L33_001E1820_0034CC38.f8 = 0.0f < s->f68 ? D_L33_001DD5F8_0034CC38 : D_L33_001DD5F4_0034CC38;
        if (func_L01_00452EC8(p)) {
            *(vu0_q *)&s->v80 = *(vu0_q *)&p->vC0;
            s->v80.w = p->pos.z + 2.4f;
            func_L30_0034C308(p, &p->pos, &s->f60, &D_L33_001E1820_0034CC38, D_L33_001DD65C, D_L33_001DD65C,
                              D_L33_001DD610_0034CC38, 0.0f, 0.0f, D_L33_001DD5F0_0034CC38, 1, 1, 1, 1);
        }
        v10 = p->pos;
        z = v10.z;
        if (z < s->v80.w) {
            z = s->v80.w - 0.08f;
        }
        v10.z = z;
        func_003886E8(&v20, &p->vD0, -1.0f);
        func_00389158(&s->v80, &s->v80, &v20, D_L33_001DD7FC_0034CC38);
        func_003886E8(&v30, &s->v80, D_L33_001DD7F8_0034CC38 * 0.01666666753590107f);
        func_L33_0034C5D0((u8 *)p, (vu0_v4 *)&v10, (vu0_v4 *)&v30);
        s->v80.w = v10.z;
        func_L30_0034C308(p, &p->pos, &s->f60, &D_L33_001E1820_0034CC38, D_L33_001DD65C, D_L33_001DD65C,
                          D_L33_001DD610_0034CC38, 0.0f, 0.0f, D_L33_001DD5F0_0034CC38, 1, 1, 1, 1);
        func_L32_003489D0((u8 *)p, &p->pos.x, D_L33_001DD65C, s->f68, D_L33_001DD5F8_0034CC38, D_L33_001DD5E8,
                          D_L33_001DD5E4, D_L33_001DD5F4_0034CC38, -1.0f);
        if (!(p->flags & 2)) {
            break;
        }
        for (i = 0; i < 30; i++) {
            func_0037E2F0(&v50, D_L33_001DD800 * 0.5f * 0.01666666753590107f, D_L33_001DD800 * 0.01666666753590107f);
            v50.y = -fabs_asm(v50.y);
            v50.z += D_L33_001DD800 * 0.4f * 0.01666666753590107f;
            func_0037E2F0(&v40, 0.0f, 0.0133333345875144f);
            vec_add_ab(&v40, &v40, &p->pos);
            o = func_L01_00472438(&v40, &v50, 0x1E, func_0037E208(-3, 3), 0x7F05A182, 0x1005A182, 0,
                                  252000.02f, 42000.0f, 20.0f);
            if (o != 0) {
                o[3] = func_0037E1D8(2) ? 0x48 : 0x44;
                o[2] = func_0037E1D8(2) ? *D_L33_0021F618.p1A4 : *D_L33_0021F618.p88;
            }
        }
        func_L01_0044ED60(p, 0xFF, D_L33_001D66B0_0034CC38, 2.5f, 5.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23,
                          1.0f, 1.0f, 0, 3);
        func_0039FE80(9, 0, p);
        func_003BD360(p);
        return;
    case 2:
        func_L30_0034C308(p, &p->pos, &s->f60, &D_L33_001E1820_0034CC38, D_L33_001DD65C, D_L33_001DD65C,
                          D_L33_001DD610_0034CC38, ground ? 0.0f : D_L33_001DD660, 0.0f, D_L33_001DD664, 1, 1, 1, 0);
        if (!ground) {
            break;
        }
        if (facing && inX && inZ) {
            func_L33_0034E008((u8 *)p, 3);
        } else if (seen && inZ) {
            func_L33_0034E008((u8 *)p, 9);
        } else {
            func_L33_0034E008((u8 *)p, 7);
        }
        break;
    case 3:
        if (func_L01_00452EC8(p)) {
            if (s->fB0 > 0) {
                s->fA8 = s->fB0;
            } else {
                s->fA8 = D_L33_001DD7A0_0034CC38;
            }
            func_0039FE80(8, 0, p);
        }
        func_L30_0034B9C8(D_L33_001E1850_0034CC38.obj, p);
        if (!ground) {
            func_L33_0034E008((u8 *)p, 2);
        }
        if (func_00388398(&s->fA8)) {
            func_L33_0034E008((u8 *)p, 5);
        }
        break;
    case 4:
        if (!ground) {
            func_L33_0034E008((u8 *)p, 2);
        }
        if (facing && inX && inZ) {
            func_L33_0034E008((u8 *)p, 3);
        } else if (p->flags & 2) {
            if (seen && inZ) {
                func_L33_0034E008((u8 *)p, 9);
            } else {
                func_L33_0034E008((u8 *)p, 7);
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(p)) {
            s->fA8 = -1;
            s->fA4 = 1;
            s->fAC = 0.0f;
        }
        if (func_L01_0044AF40(p, D_L33_001DD614_0034CC38)) {
            p->f48 = 0.0f;
            s->fA8 = D_L33_001DD7A4_0034CC38;
        }
        if (s->fA8 >= 0) {
            if (func_00388398(&s->fA8)) {
                p->f48 = 1.0f;
                v = s->fC4;
                if (v != -1 && (e = D_001A30B0 + v * 128, *(u8 **)(e + 0xDC) == (u8 *)p) && e[0xD0] != 0) {
                    func_0039FB08(v);
                }
                s->fC4 = -1;
            } else if (s->fA8 % D_L33_001DD7C4 == 0) {
                w = s->fC4;
                if (w == -1 || (e = D_001A30B0 + w * 128, *(u8 **)(e + 0xDC) != (u8 *)p) || e[0xD0] == 0) {
                    s->fC4 = func_0039FE80(0, 4, p);
                }
                func_003BDA38(p, 1, &v10);
                if (fabs_asm(func_003893C8(D_L33_001DD5C0_0034CC38, p->fF8)) <
                    fabs_asm(func_003893C8(D_L33_001DD5C4, p->fF8))) {
                    a = 3.1415927f;
                    v20.x = func_00388960(a) * D_L33_001DD7F4;
                    v20.z = func_00388978(a) * D_L33_001DD7F4;
                    v20.y = 0.0f;
                } else {
                    a = 0.0f;
                    v20.x = func_00388960(a) * D_L33_001DD7F4;
                    v20.z = func_00388978(a) * D_L33_001DD7F4;
                    v20.y = 0.0f;
                }
                a = func_003BEB48(D_L33_001DD7C0_0034CC38, D_L33_001DD7BC_0034CC38, (f32)s->fA8 / (f32)D_L33_001DD7A4_0034CC38);
                b = func_003BEB48(D_L33_001DD7D0_0034CC38, D_L33_001DD7D4_0034CC38, (f32)s->fA8 / (f32)D_L33_001DD7A4_0034CC38);
                r = func_L33_0034F2C8(&v10, &v20, p, 0, a, 0.0f, D_L33_001DD7C8_0034CC38, b, D_L33_001DD7CC_0034CC38, s->fA4);
                s->fA4 = 0;
                if (r != 0) {
                    func_L33_0034EDB8(r, D_L33_001DD7D8, D_L33_001DD7DC_0034CC38, D_L33_001DD7E0_0034CC38, D_L33_001DD7E4_0034CC38, 0x174B,
                                      D_L33_001DD7E8, D_L33_001DD7EC, D_L33_001DD7F0);
                }
            }
        }
        ((void (*)(void *, void *, f32, f32, f32, f32, f32, f32))func_L31_00345960)(
            p, &s->fAC, D_L33_001DD5C0_0034CC38, D_L33_001DD5C4, D_L33_001DD7B0_0034CC38, D_L33_001DD7A8_0034CC38, D_L33_001DD7A8_0034CC38, D_L33_001DD60C_0034CC38);
        if (!ground) {
            func_L33_0034E008((u8 *)p, 2);
        }
        if (!(p->flags & 2)) {
            break;
        }
        if (facing && inX && inZ) {
            func_L33_0034E008((u8 *)p, 3);
        } else if (seen && !facing && inZ) {
            func_L33_0034E008((u8 *)p, 9);
        } else {
            func_L33_0034E008((u8 *)p, 4);
        }
        break;
    case 6:
        D_L33_001E1820_0034CC38.f8 = 0.0f < s->f68 ? D_L33_001DD640 : D_L33_001DD63C;
        if (func_L01_00452EC8(p)) {
            func_L30_0034C308(p, &p->pos, &s->f60, &D_L33_001E1820_0034CC38, D_L33_001DD65C, D_L33_001DD65C,
                              D_L33_001DD610_0034CC38, 0.0f, 0.0f, D_L33_001DD638_0034CC38, 1, 1, 1, 1);
        }
        func_L30_0034C308(p, &p->pos, &s->f60, &D_L33_001E1820_0034CC38, D_L33_001DD65C, D_L33_001DD65C,
                          D_L33_001DD610_0034CC38, 0.0f, 0.0f, D_L33_001DD638_0034CC38, 1, 1, 1, 1);
        func_L32_003489D0((u8 *)p, &p->pos.x, D_L33_001DD65C, s->f68, D_L33_001DD640, D_L33_001DD630_0034CC38,
                          D_L33_001DD62C, D_L33_001DD63C, -1.0f);
        if (!(p->flags & 2)) {
            break;
        }
        D_L33_001E1820_0034CC38.f8 = D_L33_001DD618_0034CC38;
        if (ground) {
            if (facing && inX && inZ) {
                func_L33_0034E008((u8 *)p, 3);
            } else if (seen && inZ) {
                func_L33_0034E008((u8 *)p, 9);
            } else {
                func_L33_0034E008((u8 *)p, 7);
            }
        } else {
            func_L33_0034E008((u8 *)p, 2);
        }
        break;
    case 7:
        if (!ground) {
            func_L33_0034E008((u8 *)p, 2);
        } else if (facing && inX && inZ) {
            func_L33_0034E008((u8 *)p, 3);
        } else if (seen && inZ) {
            func_L33_0034E008((u8 *)p, 9);
        } else if (p->flags & 2) {
            func_L33_0034E008((u8 *)p, 8);
        }
        break;
    case 8:
        side = s->v80.x < p->pos.x ? D_L33_001DD5C0_0034CC38 : D_L33_001DD5C4;
        if (func_L01_00452EC8(p)) {
            s->fAC = 0.0f;
            *(vu0_q *)&s->v80 = *(vu0_q *)&p->pos;
            w = s->f94;
            if (w == -1) {
                x = s->v80.x;
                if (left) {
                    s->v80.x = x + D_L33_001DD64C;
                } else {
                    s->v80.x = x - D_L33_001DD64C;
                }
            } else {
                func_L30_0034BDF0(D_L33_001DFC80 + w * 128, &lo, &hi, 0, 0);
                x2 = s->v80.x;
                if (left) {
                    e2 = hi;
                    s->v80.x = x2 + func_003BEB48(p->pos.x, e2, func_0037E250(0.4f, 0.8f));
                } else {
                    e2 = lo;
                    s->v80.x = x2 + func_003BEB48(e2, p->pos.x, func_0037E250(0.4f, 0.8f));
                }
            }
        }
        if (!((s32 (*)(void *, void *, f32, f32, f32, f32, f32, f32, f32))func_L31_003459B0)(
                p, &s->fAC, s->v80.x, D_L33_001DD5C0_0034CC38, D_L33_001DD5C4, D_L33_001DD7B0_0034CC38, D_L33_001DD7A8_0034CC38,
                D_L33_001DD7A8_0034CC38, D_L33_001DD60C_0034CC38)) {
            f32 c = func_00388960(func_00389410(func_003893C8(
                s->v80.x < p->pos.x ? D_L33_001DD5C0_0034CC38 : D_L33_001DD5C4, p->fF8)));
            if (c < 0.0f) {
                c = 0.0f;
            }
            spd = D_L33_001DD660 * fabs_asm(c);
        } else {
            spd = D_L33_001DD660;
        }
        func_L31_00346000(p, &s->f60, s->v80.x, 0.0f, spd, D_L33_001DD654, D_L33_001DD654);
        func_L30_0034C308(p, &p->pos, &s->f60, &D_L33_001E1820_0034CC38, D_L33_001DD65C, D_L33_001DD65C,
                          D_L33_001DD610_0034CC38, spd, 0.0f, D_L33_001DD664, 1, 1, 1, 0);
        r2 = fabs_asm(func_003893C8(p->fF8, side));
        m2 = func_003BEB48(rateA, rateB, r2 / fabs_asm(func_003893C8(D_L33_001DD5C0_0034CC38, D_L33_001DD5C4)));
        p->f48 = m2;
        if (m2 < D_L33_001DD5D0_0034CC38) {
            p->f48 = D_L33_001DD5D0_0034CC38;
        }
        if (!ground) {
            func_L33_0034E008((u8 *)p, 2);
        } else if (facing && inX && inZ) {
            func_L33_0034E008((u8 *)p, 3);
        } else if (seen && inZ) {
            func_L33_0034E008((u8 *)p, 9);
        } else if (func_003887C8(&s->v80, &p->pos) < D_L33_001DD5D4_0034CC38) {
            func_L33_0034E008((u8 *)p, 7);
        }
        break;
    case 0:
        func_L33_0034DE80((u8 *)p);
        func_L33_0034E008((u8 *)p, 10);
        break;
    case 9:
        side = ((Hero_0034D838 *)&D_001A4BE0)->pos[0] < p->pos.x ? D_L33_001DD5C0_0034CC38 : D_L33_001DD5C4;
        if (func_L01_00452EC8(p)) {
            s->fAC = 0.0f;
        }
        if (!((s32 (*)(void *, void *, f32, f32, f32, f32, f32, f32))func_L31_00345960)(
                p, &s->fAC, D_L33_001DD5C0_0034CC38, D_L33_001DD5C4, D_L33_001DD7B0_0034CC38, D_L33_001DD7A8_0034CC38, D_L33_001DD7A8_0034CC38,
                D_L33_001DD60C_0034CC38)) {
            f32 c = func_00388960(func_00389410(func_003893C8(
                ((Hero_0034D838 *)&D_001A4BE0)->pos[0] < p->pos.x ? D_L33_001DD5C0_0034CC38 : D_L33_001DD5C4,
                p->fF8)));
            if (c < 0.0f) {
                c = 0.0f;
            }
            spd = D_L33_001DD660 * fabs_asm(c);
        } else {
            spd = D_L33_001DD660;
        }
        func_L31_00346000(p, &s->f60, ((Hero_0034D838 *)&D_001A4BE0)->pos[0], 0.0f, spd, D_L33_001DD654, D_L33_001DD654);
        func_L30_0034C308(p, &p->pos, &s->f60, &D_L33_001E1820_0034CC38, D_L33_001DD65C, D_L33_001DD65C,
                          D_L33_001DD610_0034CC38, spd, 0.0f, D_L33_001DD664, 1, 1, 1, 0);
        r2 = fabs_asm(func_003893C8(p->fF8, side));
        m2 = func_003BEB48(rateA, rateB, r2 / fabs_asm(func_003893C8(D_L33_001DD5C0_0034CC38, D_L33_001DD5C4)));
        p->f48 = m2;
        if (m2 < D_L33_001DD5D0_0034CC38) {
            p->f48 = D_L33_001DD5D0_0034CC38;
        }
        if (!ground) {
            func_L33_0034E008((u8 *)p, 2);
        } else if (facing && inX && inZ) {
            func_L33_0034E008((u8 *)p, 3);
        } else if (!seen || (inX && !inZ)) {
            func_L33_0034E008((u8 *)p, 7);
        }
        break;
    case 10:
        if (func_L01_00452EC8(p) && s->f9C != 0) {
            p->f98 = 0;
            p->f34 = (p->f34 | 0x41) & ~0x1000;
            func_L01_004A6DF8(p, 1);
        }
        if (s->f9C == 0) {
            func_L30_0034C308(p, &p->pos, &s->f60, &D_L33_001E1820_0034CC38, D_L33_001DD65C, D_L33_001DD65C, 1.0f,
                              0.0f, D_L33_001DD670, 0.0f, 1, 1, 0, 0);
        }
        if ((s->f98 == -1 && func_0037E0F0(D_001A4C60, s->f90, 0)) ||
            func_0037E0F0(D_001A4C60, s->f98, 0)) {
            if (s->f9C != 0) {
                if (!func_L01_00452F60(p)) {
                    break;
                }
                if (s->f9C != 0) {
                    Ref_0034D838 *q;
                    p->f34 &= 0xFFBE;
                    q = p->f24;
                    p->f34 |= q->f44 & 0x1000;
                    p->f98 = q->f10;
                }
            }
            func_L33_0034E008((u8 *)p, 7);
        }
        break;
    }
    func_L33_0034DCC0((u8 *)p);
}
/* localdecomp:end func_L33_0034CC38 */
