#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3A53E8.c's earlier functions */
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
extern void func_003A56F8(O_3A02D8 *obj);

/* localdecomp:start func_003A58C0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A58C0;
typedef struct { V4_003A58C0 r[4]; } M_003A58C0;
typedef struct { u8 pad[0x10]; s32 f10; } K_003A58C0;
typedef struct {
    V4_003A58C0 f00;
    V4_003A58C0 pos;
    u8 pad20[4];
    K_003A58C0 *f24;
    u8 pad28[0x34 - 0x28];
    u16 f34;
    u8 pad36[0x68 - 0x36];
    u8 *f68;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
    u8 pad9C[0xBC - 0x9C];
    u8 fBC;
    u8 padBD[0xC0 - 0xBD];
    V4_003A58C0 m[4];
} O_003A58C0;
typedef struct {
    u8 pad[0x80];
    V4_003A58C0 f80;
    u8 pad90[0xB0 - 0x90];
    V4_003A58C0 fB0;
    u8 padC0[0xE0 - 0xC0];
    V4_003A58C0 fE0;
    u8 padF0[0x35C - 0xF0];
    O_003A58C0 *f35C;
    s32 f360;
    u8 pad364[0x25C0 - 0x364];
    s32 f25C0;
} C_003A58C0;
typedef struct { u8 pad[8]; f32 f8; } P_003A58C0;
extern C_003A58C0 D_001A4BE0;
extern O_003A58C0 *D_0022D8B0_003A58C0[20];
extern M_003A58C0 D_0016C650;
extern P_003A58C0 D_0022D900;
extern u128_t D_00227660[];
extern s32 D_001D5B94;
extern s32 D_001D5BEC;
extern s32 D_001D545C;
extern V4_003A58C0 D_001D6F00 __attribute__((section(".sdata")));
extern V4_003A58C0 D_001D6F10 __attribute__((section(".sdata")));
extern V4_003A58C0 D_001D6F20 __attribute__((section(".sdata")));
extern V4_003A58C0 D_001D6F30 __attribute__((section(".sdata")));
extern V4_003A58C0 D_001D6F40 __attribute__((section(".sdata")));
extern V4_003A58C0 D_001D6F50 __attribute__((section(".sdata")));
extern f32 D_001D6F60[3] __attribute__((section(".sdata")));
extern f32 D_001D6F6C;
extern f32 D_001D6F70;
extern f32 D_001D6F74[3] __attribute__((section(".sdata")));
extern V4_003A58C0 D_001D6F80 __attribute__((section(".sdata")));
__asm__(".extern D_001D6F00, 4");
__asm__(".extern D_001D6F10, 4");
__asm__(".extern D_001D6F20, 4");
__asm__(".extern D_001D6F30, 4");
__asm__(".extern D_001D6F40, 4");
__asm__(".extern D_001D6F50, 4");
__asm__(".extern D_001D6F60, 4");
__asm__(".extern D_001D6F6C, 4");
__asm__(".extern D_001D6F70, 4");
__asm__(".extern D_001D6F74, 4");
__asm__(".extern D_001D6F80, 4");
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038D570(void *, void *);
extern void func_0038CE50_003A58C0(void *, void *, f32);
extern s32 func_0038DC20(void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D590(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_003C5250(void *);
extern void func_003C5320(s32, s32, s32);
extern void func_003C48A8(f32 *, f32 *);
extern void func_003C2EC0(u8 *, s32, u8 *);
extern s32 func_003C3DA0_003A58C0(void *, void *, s32, s32, f32);
extern f32 func_003C3D30_003A58C0(void *, s32, s32, f32);
extern s32 func_003D3CB0_003A58C0(void *, void *, s32, s32, s32);
extern f32 func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_003C6680(void *, void *, s32, s32, void *, void *, void *, void *, void *, void *, void *);
extern void func_003C6990();
extern void func_003C7DD8(void *);
extern int func_003C4D58(unsigned char *);
extern void func_003C4DA8_003A58C0(u8 *, void *, void *, void *);
void func_003A58C0(O_003A58C0 *obj, s32 a1) {
    /* the stack slots the C++ original's block-scoped locals shared */
    union {
        M_003A58C0 m;                               /* the camera matrix of the last part */
        struct { V4_003A58C0 v, d, o, e; } s;       /* work vectors of the first two parts */
    } u;
    V4_003A58C0 base;
    union {
        struct { V4_003A58C0 at, dir; } aim;        /* turn towards the fixed point */
        struct { V4_003A58C0 pos, rot, tmp; } ch;   /* one child: old position and angles */
    } w;
    V4_003A58C0 *target;
    s32 flag;
    s32 r;
    s32 i;
    s32 j;
    s32 k;
    f32 s;
    f32 h;

    if (D_0022D8B0_003A58C0[0] == 0) {
        func_003A56F8((O_3A02D8 *)obj);
        if (D_001D5B94 == 0) {
            flag = 1;
            if (D_001D5BEC != 0) {
                if (D_001D545C == 11) {
                    u.s.v.x = 526.922f;
                    u.s.v.y = 200.0f;
                    u.s.v.z = 819.262f;
                    for (i = 0; i < 25; i++) {
                        s = 1.0f;
                        if (0.0f < D_001A4BE0.fB0.w) s = -1.0f;
                        vec_sub_ab(&u.s.d, &u.s.v, &obj->pos);
                        func_0038CF68(&u.s.d, &u.s.d, s);
                        func_0038CE20((f32 *)&u.s.d, &u.s.d, -1.0f);
                        func_003C5320((s32)obj->m, (s32)&u.s.d, 0);
                    }
                    func_003C48A8((f32 *)obj->m, (f32 *)&obj->m[3]);
                    if (func_0038CF00(&D_001A4BE0.fB0, &obj->pos) < 100.0f) {
                        s = 1.0f;
                        if (0.0f < D_001A4BE0.fB0.w) s = -1.0f;
                        vec_sub_ba(&u.s.e, &u.s.v, &obj->pos);
                        func_0038CF68(&u.s.e, &u.s.e, s);
                        u.s.d = u.s.v;
                        func_0038CE20((f32 *)&u.s.o, &u.s.e, 1.0f);
                        vec_add_ab(&u.s.o, &u.s.o, &obj->pos);
                        if (func_003D3CB0_003A58C0(&u.s.o, &u.s.d, 2, (s32)obj, 0) != 0) {
                            *(u128_t *)&obj->pos = D_00227660[0];
                        } else {
                            obj->pos = u.s.d;
                        }
                    }
                } else {
                    for (j = 0; j < 8; j++) {
                        ((void (*)(void *, void *, s32))func_003C5250)(obj, &u.s.v, 0);
                        func_003C5320((s32)obj->m, (s32)&u.s.v, 0);
                    }
                    func_003C48A8((f32 *)obj->m, (f32 *)&obj->m[3]);
                    if (func_0038CF00(&D_001A4BE0.fB0, &obj->pos) < 100.0f) {
                        func_003C3DA0_003A58C0(&obj->pos, &obj->pos, 0, 0, 0.5f);
                    }
                }
            } else {
                h = func_003C3D30_003A58C0(&obj->pos, 0, 0, 0.5f);
                if (h != 0.0f) {
                    obj->pos.z = h;
                } else {
                    flag = 0;
                }
            }
            func_0038D570(&D_0016C650, obj->m);
            D_0016C650.r[3] = obj->pos;
            if (flag) {
                func_0038CF68(&u.s.v, &obj->m[2], D_001D6F6C);
                vec_add_ab(&obj->pos, &obj->pos, &u.s.v);
            }
            D_001D6F70 = obj->pos.z;
        }
        func_003C6680(obj, &D_0022D900, 0, 0, &D_001D6F30, &D_001D6F40, &D_001D6F00, D_001D6F60,
                      &D_001D6F50, &D_001D6F10, &D_001D6F20);
    }
    target = 0;
    if (D_001D5B94 == 0) {
        func_0038CE50_003A58C0(&u.s.v, obj, 0.0009765625f);
        u.s.v.w += 1.0f;
        if (func_0038DC20(&u.s.v, 50.0f) == -1) return;
        if (D_001D5B94 == 0) {
            r = 0;
            if (func_0038CF38(&obj->pos, &D_001A4BE0.f80) < 6.0f) {
                if (obj->fBC != 0) {
                    V4_003A58C0 *pv = &u.s.v;      /* the probe point, tried twice */
                    *(u128_t *)&u.s.v = *(u128_t *)&D_001A4BE0.fE0;
                    u.s.v.z += 2.0f;
                    if (func_003D3CB0_003A58C0(&D_001A4BE0.fE0, pv, 0, D_001A4BE0.f25C0, 0) != 0) {
                        r = 1;
                    } else {
                        vec_sub_ab(&u.s.d, &obj->pos, &D_001A4BE0.f80);
                        u.s.d.z = 0.0f;
                        func_0038CF68(&u.s.d, &u.s.d, 0.4f);
                        vec_add_ab(&u.s.v, &u.s.v, &u.s.d);
                        r = func_003D3CB0_003A58C0(&D_001A4BE0.fE0, pv, 0, D_001A4BE0.f25C0, 0) != 0;
                    }
                } else {
                    *(u128_t *)&u.s.v = *(u128_t *)&D_001A4BE0.fE0;
                    u.s.v.z += 2.0f;
                    r = func_003D3CB0_003A58C0(&D_001A4BE0.fE0, &u.s.v, 0, D_001A4BE0.f25C0, 0) != 0;
                }
            }
            obj->fBC = r;
            if (obj->fBC != 0 && D_001D5BEC == 0) {
                func_003C41A0(&D_0022D900.f8, D_001D6F74, D_001D6F70 + 0.75f, 0.00080000004f, 0.00080000004f, 0.020000001f);
            } else {
                func_003C41A0(&D_0022D900.f8, D_001D6F74, D_001D6F70, 0.00080000004f, 0.00080000004f, 0.020000001f);
            }
        }
    }
    func_003C2EC0((u8 *)obj, 1, (u8 *)&u.m);
    base = u.m.r[3];
    if (a1 == 0 && D_001D545C == 11) {
        w.aim.at.x = 526.922f;
        w.aim.at.y = 200.0f;
        w.aim.at.z = 819.262f;
        s = 1.0f;
        if (0.0f < D_001A4BE0.fB0.w) s = -1.0f;
        vec_sub_ab(&w.aim.dir, &w.aim.at, &obj->pos);
        func_0038CF68(&w.aim.dir, &w.aim.dir, s);
        func_0038CE20((f32 *)&w.aim.dir, &w.aim.dir, -1.0f);
        func_003C5320((s32)obj->m, (s32)&w.aim.dir, 0);
        func_003C48A8((f32 *)obj->m, (f32 *)&obj->m[3]);
    }
    for (k = 0; D_0022D8B0_003A58C0[k] != 0; k++) {
        u8 *f68;

        if (obj->f34 & 1) {
            D_0022D8B0_003A58C0[k]->f98 = 0;
            D_0022D8B0_003A58C0[k]->f34 |= 0x41;
        } else {
            D_0022D8B0_003A58C0[k]->f34 &= ~0x41;
            D_0022D8B0_003A58C0[k]->f98 = D_0022D8B0_003A58C0[k]->f24->f10;
        }
        w.ch.pos = D_0022D8B0_003A58C0[k]->pos;
        w.ch.rot = D_0022D8B0_003A58C0[k]->m[3];
        D_0022D8B0_003A58C0[k]->pos = obj->pos;
        func_0038D590(D_0022D8B0_003A58C0[k]->m, &u.m);
        if (D_001D5B94 == 2 || D_001D5B94 == 6) {
            func_0038D000(&w.ch.tmp, &D_001D6F80, D_0022D8B0_003A58C0[k]->m);
            vec_add_ab(&D_0022D8B0_003A58C0[k]->pos, &base, &w.ch.tmp);
        }
        func_003C48A8((f32 *)D_0022D8B0_003A58C0[k]->m, (f32 *)&D_0022D8B0_003A58C0[k]->m[3]);
        func_003C7DD8(D_0022D8B0_003A58C0[k]);
        f68 = D_0022D8B0_003A58C0[k]->f68;
        vec_sub_ba(&w.ch.tmp, &D_0022D8B0_003A58C0[k]->pos, &w.ch.pos);
        if (func_003C4D58((unsigned char *)D_0022D8B0_003A58C0[k]) != 0) {
            func_003C4DA8_003A58C0(f68 + 0x30, &w.ch.tmp, &w.ch.rot, &D_0022D8B0_003A58C0[k]->m[3]);
        }
        if (D_001A4BE0.f360 >= 2 && D_001A4BE0.f35C == D_0022D8B0_003A58C0[k]) {
            target = &D_001A4BE0.f80;
        }
        if (D_001D5B94 != 0) {
            D_0022D8B0_003A58C0[k]->f98 = 0;
            obj->f98 = 0;
        } else if (obj->f98 != 0) {
            D_0022D8B0_003A58C0[k]->f98 = D_0022D8B0_003A58C0[k]->f24->f10;
        }
    }
    if (D_001D545C == 12 || D_001D545C == 18) {
        obj->m[3].x = 0.0f;
        obj->m[3].y = 0.0f;
    } else if (D_001D5B94 == 0) {
        func_003C6990(obj, &D_0022D900, target);
    }
}
/* localdecomp:end func_003A58C0 */

LINKER_REMNANT("asm/remnants", func_003A6140);
