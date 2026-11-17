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

INCLUDE_ASM("asm/levels", func_L12_003D84A0);
