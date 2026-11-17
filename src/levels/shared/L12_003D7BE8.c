#include "common.h"

typedef struct { u8 pad[0x60]; u8 x60; } V_3D6A28;
typedef struct { u8 pad[0x68]; V_3D6A28 *x68; } M_3D6A28;
typedef struct { u8 pad[0x70]; u8 x70[0x100]; s32 x170; u8 pad174[0x18C - 0x174]; M_3D6A28 *x18C; } B_3D6A28;
typedef struct { u8 pad[0xA8]; u8 xA8; } O_3D6A28;

typedef struct { s32 x0; f32 x4; s32 x8; f32 xC; u8 pad10[0x20 - 0x10]; s32 x20; s32 x24; u8 pad28[0x3C - 0x28]; s32 x3C; u8 pad40[0x54 - 0x40]; s32 x54; } Src_003D9000;
typedef struct { u8 pad[0x68]; Src_003D9000 *x68; } Req_003D9000;
typedef struct { u8 pad[0x160]; f32 x160; s32 x164; f32 x168; s32 x16C; s32 x170; s32 x174; u8 pad178[0x180 - 0x178]; s32 x180; s32 x184; } Dst_003D9000;
typedef struct { u8 pad[0x68]; Dst_003D9000 *x68; } Obj_003D9000;

/* localdecomp:start func_L12_003D7BE8 */
#include "vu0.h"

typedef int u128_003D7BE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D7BE8;
typedef struct { V4_003D7BE8 r[4]; } M4_003D7BE8;
typedef struct {
    u8 pad0[0x130];
    V4_003D7BE8 x130;
    u8 pad140[0x14C - 0x140];
    s16 x14C;
    u8 pad14E[0x174 - 0x14E];
    s32 x174;
    u8 pad178[0x17C - 0x178];
    s32 x17C;
    u8 pad180[0x190 - 0x180];
    f32 x190;
    f32 x194;
    s32 x198;
    f32 x19C;
    u8 pad1A0[0x220 - 0x1A0];
    u8 x220[0x284 - 0x220];
    f32 x284;
} Vars_003D7BE8;
typedef struct {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x43 - 0x21];
    u8 x43;
    u8 pad44[0x60 - 0x44];
    u8 x60;
    u8 pad61[0x68 - 0x61];
    Vars_003D7BE8 *x68;
    u8 pad6C[0x96 - 0x6C];
    u16 x96;
} Moby_003D7BE8;
typedef struct {
    u8 pad0[0xD0];
    u8 xD0;
    u8 padD1[0xDC - 0xD1];
    void *xDC;
} Ent_003D7BE8;

extern u8 D_001A30B0[];
extern u8 D_L12_001D6700[] __attribute__((section(".sdata")));
extern f32 D_L12_001DF018;
extern f32 D_L12_001DF01C;
extern f32 D_L12_001DF020;
extern s32 D_L12_001DF094;
extern s32 D_L12_001DF098;
extern s32 D_L12_001DF09C;
extern s32 D_L12_001DF0A0;
extern s32 D_L12_001DF0A4;
extern s32 D_L12_001DF0A8;
extern s32 D_L12_001DF0AC;
extern f32 D_L12_001DF0B0;
extern s32 D_L12_001DF0B4;
extern s32 D_L12_001DF0B8;
extern f32 D_L12_001DF0BC;
extern f32 D_L12_001DF0C0;
extern f32 D_L12_001DF0C4;
extern f32 D_L12_001DF0C8;
extern f32 D_L12_001DF0CC;
extern f32 D_L12_001DF0D0;
extern f32 D_L12_001DF0D4;
extern f32 D_L12_001DF0D8;
extern s32 D_L12_001DF840;
__asm__(".extern D_L12_001DF018, 4");
__asm__(".extern D_L12_001DF01C, 4");
__asm__(".extern D_L12_001DF020, 4");
__asm__(".extern D_L12_001DF094, 4");
__asm__(".extern D_L12_001DF098, 4");
__asm__(".extern D_L12_001DF09C, 4");
__asm__(".extern D_L12_001DF0A0, 4");
__asm__(".extern D_L12_001DF0A4, 4");
__asm__(".extern D_L12_001DF0A8, 4");
__asm__(".extern D_L12_001DF0AC, 4");
__asm__(".extern D_L12_001DF0B0, 4");
__asm__(".extern D_L12_001DF0B4, 4");
__asm__(".extern D_L12_001DF0B8, 4");
__asm__(".extern D_L12_001DF0BC, 4");
__asm__(".extern D_L12_001DF0C0, 4");
__asm__(".extern D_L12_001DF0C4, 4");
__asm__(".extern D_L12_001DF0C8, 4");
__asm__(".extern D_L12_001DF0CC, 4");
__asm__(".extern D_L12_001DF0D0, 4");
__asm__(".extern D_L12_001DF0D4, 4");
__asm__(".extern D_L12_001DF0D8, 4");

extern s32 func_L12_003D84A0(void *, void *);
extern void func_L12_003D89F8(void *, s32);
extern void func_L12_003D8B20(void *, void *, s32);
extern void func_L12_003D8C30(void *);
extern void func_L12_003D8DB8(void *);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_L07_003CAE10(void *, void *, void *, s32, void *, s32, u32, f32, f32);
extern void func_L01_0046B458(void *, f32, s32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00456230(void *, s32);

void func_L12_003D7BE8(Moby_003D7BE8 *o) {
    Vars_003D7BE8 *v = o->x68;
    Ent_003D7BE8 *e;
    s32 h;
    f32 f;
    s32 i;
    V4_003D7BE8 pos;
    V4_003D7BE8 dir;
    V4_003D7BE8 rnd;
    M4_003D7BE8 m;
    V4_003D7BE8 end;
    V4_003D7BE8 start;
    V4_003D7BE8 at;

    if (o->x20 == 0 && func_L12_003D84A0(o, v) == 0) {
        return;
    }
    if (func_L12_003D8808((O_3D6A28 *)o, (B_3D6A28 *)v) == 0) {
        func_L12_003D89F8(o, 1);
        return;
    }
    switch (o->x20) {
    case 1:
        if (func_L01_004561B8(o)) {
            func_003C3A10(o, 1, 0, 12);
        }
        h = v->x17C;
        if (h != -1) {
            e = (Ent_003D7BE8 *)(D_001A30B0 + h * 0x80);
            if (e->xDC == o && e->xD0 != 0) {
                func_003A4F28(h);
            }
        }
        v->x17C = -1;
        func_L12_003D8B20(o, v, 0);
        func_L12_003D8C30(o);
        if (v->x14C != 0) {
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            func_003C3A10(o, 2, 0, 4);
        }
        func_L12_003D8B20(o, v, 1);
        if (o->x60 & 2) {
            func_003C3A10(o, 3, 0, 4);
            func_L01_004450F0(o, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(o)) {
            if (v->x17C == -1 || ((Ent_003D7BE8 *)(D_001A30B0 + v->x17C * 0x80))->xDC != o
                || ((Ent_003D7BE8 *)(D_001A30B0 + v->x17C * 0x80))->xD0 == 0) {
                v->x17C = func_003A52A0(0, 4, o);
            }
        }
        if (o->x43 != 3) {
            func_003C3A10(o, 3, 0, 10);
        }
        func_L12_003D8B20(o, v, 1);
        func_L12_003D8C30(o);
        v->x190 += D_L12_001DF01C;
        if (D_L12_001DF018 <= v->x190) {
            v->x190 = D_L12_001DF018;
            func_L01_004450F0(o, 5, -1);
        }
        v->x284 = v->x194 = func_0038DAB8(v->x194, v->x190);
        func_L01_0044E850(o, v->x220, 2, 0.043200001f, 0.43200004f);
        if (v->x14C == 0) {
            func_L01_004450F0(o, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(o)) {
            func_003C3A10(o, 1, 0, 12);
        }
        func_L12_003D8B20(o, v, 1);
        func_L12_003D8C30(o);
        v->x190 -= D_L12_001DF020;
        if (v->x190 <= 0.0f) {
            v->x190 = 0.0f;
            func_L01_004450F0(o, 1, -1);
        }
        v->x284 = v->x194 = func_0038DAB8(v->x194, v->x190);
        func_L01_0044E850(o, v->x220, 2, 0.043200001f, 0.43200004f);
        h = v->x17C;
        if (h != -1) {
            e = (Ent_003D7BE8 *)(D_001A30B0 + h * 0x80);
            if (e->xDC == o && e->xD0 != 0) {
                func_003A4F28(h);
            }
        }
        v->x17C = -1;
        if (v->x14C != 0) {
            func_L01_004450F0(o, 3, -1);
        }
        break;
    case 5:
        o->x96++;
        if (o->x43 != 3) {
            func_003C3A10(o, 3, 0, 10);
        }
        func_L12_003D8B20(o, v, 1);
        func_L12_003D8C30(o);
        v->x284 = v->x194 = func_0038DAB8(v->x194, v->x190);
        func_L01_0044E850(o, v->x220, 2, 0.043200001f, 0.43200004f);
        if (v->x198 != 0) {
            func_L01_00404A10(func_L12_003D8DB8, o);
        }
        if (v->x14C == 0) {
            func_L01_004450F0(o, 4, -1);
        } else {
            func_003C2F58(o, 3, &pos);
            for (i = 0; i < D_L12_001DF0B4; i++) {
                *(u128_003D7BE8 *)&rnd = 0;
                rnd.x = func_003824E0(D_L12_001DF0BC, D_L12_001DF0C0);
                rnd.y = func_003824E0(D_L12_001DF0BC, D_L12_001DF0C0);
                rnd.z = func_003824E0(D_L12_001DF0C4, D_L12_001DF0C8);
                dir = rnd;
                func_0038CF68(&dir, &dir, D_L12_001DF0B0 * 0.020000001f);
                func_L01_004637C8(&pos, &dir,
                                  (D_L12_001DF0A0 << 24) | (D_L12_001DF09C << 16) | (D_L12_001DF098 << 8) | D_L12_001DF094,
                                  (D_L12_001DF09C << 16) | (D_L12_001DF098 << 8) | D_L12_001DF094,
                                  D_L12_001DF0A4, D_L12_001DF0A8, D_L12_001DF0AC, D_L12_001DF0B8);
            }
            if (o->x96 >= 9) {
                v->x198 = 4;
                o->x96 = 0;
                func_003C2EC0(o, 3, &m);
                dir = m.r[1];
                rnd = m.r[3];
                func_0038CF68(&dir, &dir, D_L12_001DF0CC * 0.020000001f);
                start = m.r[3];
                at = m.r[3];
                vec_add_ab(&end, &start, &dir);
                func_L07_003CAE10(&start, &dir, o, 0, 0, -1, 0xFFFFFFFF, D_L12_001DF0D0, v->x19C);
                func_L01_0046B458(&at, D_L12_001DF0D4 * 7.0f, 7, 0.1f, 0xBF204080, 2, 1, D_L12_001D6700, 0.0f, 1);
                func_L01_0046B458(&at, D_L12_001DF0D4 * 5.0f, 7, 0.1f, 0xBF2040A0, 2, -1, D_L12_001D6700, 0.0f, 1);
                func_L01_0046B458(&at, D_L12_001DF0D4 * 3.5f, 7, 0.1f, 0xC0FFFFFF, 2, 1, D_L12_001D6700, 0.0f, 1);
                func_L01_0046B458(&at, D_L12_001DF0D4 * 2.5f, 7, 0.1f, 0xB0FFFFFF, 2, -1, D_L12_001D6700, 0.0f, 1);
                func_L01_00470C78(&at, 6, 1.08f, 0.84000003f, 0x46787878, 2, 2, D_L12_001D6700, 0, 2, 6, 1);
                func_L01_00470C78(&at, 8, 2.0400002f, 0.84000003f, 0x46787878, 2, -1, D_L12_001D6700, 1, 2, 6, 1);
                func_L01_00470C78(&at, 8, 2.4f, 1.8000001f, 0x2D787878, 2, 1, D_L12_001D6700, 1, 2, 6, 1);
            }
            if ((D_L12_001DF840 & 0xC) == (((s32)o >> 8) & 0xC)) {
                f = D_L12_001DF0D8 * D_L12_001DF0D8;
                if (func_L01_0040E548(&pos, &v->x130) < f) {
                    func_L01_00446780((u8 *)o, (u8 *)&v->x130, 0x10001, 1, 1, 0, 0.5f, v->x19C * 3.0f, 1.0f);
                }
            }
        }
        break;
    }
    if (v->x14C == 0 || v->x174 != 0) {
        func_L01_00456230(o, 1);
    } else {
        func_L01_00456230(o, 0);
    }
}
/* localdecomp:end func_L12_003D7BE8 */

/* localdecomp:start func_L12_003D84A0 */
typedef int u128_003D84A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D84A0;

typedef struct {
    u8 pad0[0x10]; u128_003D84A0 x10; u8 pad20[0x38 - 0x20]; unsigned long x38; u8 pad40[0x100 - 0x40];
} Moby_003D84A0;

typedef struct {
    u8 pad0[0x10]; u128_003D84A0 x10; u8 x20; u8 pad21[0x30 - 0x21];
    u8 x30; u8 x31; s16 x32; u16 x34; u8 pad36[0x38 - 0x36]; unsigned long x38;
    u8 pad40[0xC0 - 0x40]; u8 xC0[0x30]; V4_003D84A0 xF0;
} Part_003D84A0;

typedef struct {
    u8 pad0[0x40]; f32 x40; f32 x44; f32 x48; u8 pad4C[0x50 - 0x4C];
    s32 x50; s32 x54; s32 x58; u8 pad5C[0x61 - 0x5C]; u8 x61; u8 x62;
} Fx_003D84A0;

typedef struct S18C_003D84A0 {
    u8 pad0[0x10]; u128_003D84A0 x10; u8 pad20[0x30 - 0x20]; u8 x30; u8 pad31; s16 x32;
    u8 pad34[0x64 - 0x34]; void (*x64)(struct S18C_003D84A0 *); Fx_003D84A0 *x68;
} S18C_003D84A0;

typedef struct {
    u8 pad0[0x30]; u128_003D84A0 x30; u8 pad40[0x70 - 0x40]; V4_003D84A0 x70;
} Path_003D84A0;

typedef struct { u8 pad0[0x70]; f32 x70; u8 pad74[0x80 - 0x74]; } Blk_003D84A0;

typedef struct {
    u8 pad0[0x30]; f32 x30; s16 x34; u8 pad36[2]; u8 x38; u8 x39; u8 x3A; u8 pad3B[3];
    u8 x3E; u8 x3F; s32 x40; u8 x44; u8 pad45[0x58 - 0x45]; u8 x58; u8 x59;
    u8 pad5A[0x64 - 0x5A]; u8 x64; u8 pad65[0x81 - 0x65]; u8 x81; u8 pad82[0xB8 - 0x82];
    u8 xB8; u8 padB9[0xE7 - 0xB9]; u8 xE7; u8 padE8[0x150 - 0xE8];
    s32 x150; u8 pad154[0x15E - 0x154]; u8 x15E; u8 pad15F[0x17C - 0x15F];
    s32 x17C; s32 x180; s32 x184; s32 x188; S18C_003D84A0 *x18C; s32 x190; s32 x194; s32 x198;
    f32 x19C; Blk_003D84A0 x1A0; Blk_003D84A0 x220;
} Obj_003D84A0;

typedef void (*Fn_003D84A0)(Moby_003D84A0 *);

extern Fn_003D84A0 *func_L01_0043B548(s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern Part_003D84A0 *func_003C24B0(s32, s32);
extern s32 func_L01_0043B618(Part_003D84A0 *);
extern void func_L01_0043B750(s32, Part_003D84A0 *);
extern void func_0038D308(void *, void *);
extern void func_003C7C38(Part_003D84A0 *);
extern void func_003C3938(Moby_003D84A0 *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

extern Path_003D84A0 *D_L12_001DFE00;
extern Moby_003D84A0 *D_L12_001DFD1C;
extern s32 D_L12_001DF030[] __attribute__((section(".sdata"))); __asm__(".extern D_L12_001DF030, 4");
extern f32 D_L12_001DF03C; __asm__(".extern D_L12_001DF03C, 4");
extern f32 D_L12_001DF040; __asm__(".extern D_L12_001DF040, 4");
extern f32 D_L12_001DF044; __asm__(".extern D_L12_001DF044, 4");

s32 func_L12_003D84A0(void *arg0, void *arg1) {
    Moby_003D84A0 *a0 = arg0;
    Obj_003D84A0 *a1 = arg1;
    Path_003D84A0 *path;
    V4_003D84A0 rot;
    Part_003D84A0 *m;
    S18C_003D84A0 *s;
    Fx_003D84A0 *fx;
    s32 i;
    s32 t;

    if (a1->x150 > 0) {
        Fn_003D84A0 *f = func_L01_0043B548(0x19E1, 0x6C);
        a1->x150 = -1;
        a1->x15E = 6;
        (*f)(a0);
        return 0;
    }
    a1->xB8 = 0xFF;
    a1->xE7 = 1;
    a1->x81 = 0xFF;
    a1->x38 = 2;
    a1->x3A = 0x20;
    a1->x58 = 8;
    a1->x59 = 1;
    a1->x3E = 3;
    a1->x40 = 0;
    a1->x39 = 0;
    a1->x3F = 0;
    a1->x64 = 0;
    if (a1->x34 == 0) {
        a1->x34 = 500;
    }
    a1->x17C = -1;
    a1->x190 = 0;
    a1->x194 = 0;
    a1->x30 = a1->x34;
    a1->x198 = 0;
    if (a1->x44 != 0) {
        a1->x19C = a1->x44;
    } else {
        a1->x19C = 1.0f;
    }
    func_0038CB78(&a1->x1A0, 0, 0x80);
    func_0038CB78(&a1->x220, 0, 0x80);
    a1->x1A0.x70 = 1.0f;
    a1->x220.x70 = 1.0f;
    path = &D_L12_001DFE00[a1->x180];
    rot = path->x70;
    if (a1->x184 != 0) {
        rot.z = func_0038DAB8(rot.z, 1.5707964f);
    } else {
        rot.z = func_0038DB00(rot.z, 1.5707964f);
    }
    if (a1->x180 != -1) {
        a1->x188 = -1;
        for (i = 0; i < 3; i++) {
            m = func_003C24B0(D_L12_001DF030[i], 0);
            if (i == 0) {
                a1->x188 = func_L01_0043B618(m);
            } else {
                func_L01_0043B750(a1->x188, m);
            }
            m->x10 = path->x30;
            m->xF0 = rot;
            func_0038D308(m->xC0, &m->xF0);
            if (a1->x184 != 0) {
                m->x34 |= 0x8000;
            }
            m->x20 = 1;
            m->x30 = 0xFF;
            m->x34 &= ~1;
            m->x32 = 0xFF;
            m->x31 = 1;
            m->x38 = a0->x38;
            func_003C7C38(m);
            m->x34 |= 0x146;
        }
    }
    s = (S18C_003D84A0 *)func_003C24B0(0x1E6F, 0xA0);
    a1->x18C = s;
    if (s != 0) {
        s->x10 = a0->x10;
        fx = s->x68;
        a1->x18C->x30 = 0xC0;
        a1->x18C->x32 = 0x80;
        func_0038CB78(fx, 0, 0xA0);
        fx->x40 = D_L12_001DF03C;
        fx->x44 = D_L12_001DF040;
        fx->x48 = D_L12_001DF044;
        fx->x50 = -10;
        t = a0 - D_L12_001DFD1C;
        fx->x54 = t;
        fx->x58 = t;
        fx->x61 = 1;
        fx->x62 = 0;
        a1->x18C->x64(a1->x18C);
    }
    func_003C3938(a0, 1, 0);
    func_L01_004450F0(a0, 1, -1);
    return 1;
}
/* localdecomp:end func_L12_003D84A0 */
