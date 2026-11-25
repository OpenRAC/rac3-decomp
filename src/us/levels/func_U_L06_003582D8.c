#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x18]; u8 *target; } G_00358630;
extern G_00358630 D_L06_001E8440;

/* localdecomp:start func_U_L06_003582D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00358FF0;
typedef struct {
    V_00358FF0 dir;
    u8 pad10[8];
    u8 b18;
    u8 pad19;
    u16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[0x30 - 0x24];
} D_00358FF0;
extern s32 func_00388398(s32 *a0);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_L01_003F9498(void *, f32, s32, u8 *);
extern s32 func_003CF790(void *, f32, s32, void *, void *);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L01_00441FB8(u8 *m, s32 a, s32 b);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_0039FBD8(u8 *, s32, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, u8 *);
extern f32 func_00389380(f32, f32);
extern void func_00388BD0(u8 *a, u8 *b);
extern f32 func_00388A28(f32 a, f32 b);
extern f32 func_003887A0(f32 *v);
extern int func_L01_00452EC8(u8 *);
extern s32 func_L06_00358A88(u8 *a0, u8 *a1);
extern void func_L06_00358D70(u8 *a0, u8 *a1);
struct Moby_00359CD0;
extern void func_L06_00358FB8(struct Moby_00359CD0 *);
extern s16 D_L06_001DD418;
extern s16 D_L06_001DD41A;

void func_U_L06_003582D8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    V_00358FF0 pos;
    D_00358FF0 d;
    u8 *owner;
    u8 *m;
    s32 hit;
    f32 f;
    f32 r;

    switch (a0[0x20]) {
    case 1:
        f = (f32)*(s32 *)v / 100.0f;
        *(f32 *)(a0 + 0x2C) = (*(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) + *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24)) * f;
        *(s16 *)(v + 0x38) = (f32)D_L06_001DD418 * f;
        *(s16 *)(v + 0x3A) = (f32)D_L06_001DD41A * f;
        vec_add_ba(&pos, a0 + 0x10, v + 0x10);
        *(f32 *)(a0 + 0xF0) = func_00389380(*(f32 *)(a0 + 0xF0), 0.09308423f);
        func_00388BD0(a0 + 0xC0, a0 + 0xF0);
        *(vu0_q *)(a0 + 0x10) = *(vu0_q *)&pos;
        func_L06_00358D70(a0, v);
        if (func_00388398((s32 *)v)) {
            func_L01_00441FB8(a0, 2, -1);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(a0, 1);
            *(s32 *)v = 10;
        }
        break;
    case 2:
        if (func_00388398((s32 *)v)) {
            func_L01_00441FB8(a0, 3, -1);
            if (func_L06_00358A88(a0, v) == 0) {
                func_003BD360(a0);
            } else {
                *(s32 *)v = 60;
                func_0039FBD8(*(u8 **)(*(u8 **)(a0 + 0x24) + 0x28) + 0x20, 0, 0, (s32)(v + 0x20), 0x400);
            }
        }
        break;
    case 3:
        func_L01_00402498(func_L06_00358FB8, a0);
        if (func_00388398((s32 *)v)) {
            func_L01_00441FB8(a0, 4, -1);
            *(s32 *)v = 5;
        }
        break;
    case 4:
        func_L01_00402498(func_L06_00358FB8, a0);
        if (func_00388398((s32 *)v)) {
            f32 *dir;
            func_L01_00441FB8(a0, 5, -1);
            dir = (f32 *)(v + 0x10);
            *(u16 *)(a0 + 0x34) &= 0xFFBE;
            *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            qzero(dir);
            *(f32 *)(v + 0x18) = -*(f32 *)(v + 8);
            *(f32 *)(a0 + 0xF8) = func_00388A28(*(f32 *)(v + 0x10), *(f32 *)(v + 0x14));
            *(f32 *)(a0 + 0xF4) = -func_00388A28(func_003887A0(dir), *(f32 *)(v + 0x18));
            func_00388BD0(a0 + 0xC0, a0 + 0xF0);
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(v + 0x20);
            *(f32 *)(a0 + 0x18) += 24.0f;
            *(s32 *)v = 240;
        }
        break;
    case 5:
        func_L01_00402498(func_L06_00358FB8, a0);
        r = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        f = *(f32 *)(a0 + 0x2C) / r + 0.06f;
        if (2.0f < f)
            f = 2.0f;
        *(f32 *)(a0 + 0x2C) = r * f;
        f = f * 0.5f;
        *(s16 *)(v + 0x38) = (f32)D_L06_001DD418 * f;
        *(s16 *)(v + 0x3A) = (f32)D_L06_001DD41A * f;
        vec_add_ba(&pos, a0 + 0x10, v + 0x10);
        func_L01_00443628(&d, *(void **)(a0 + 0xB8), 0x10001, v + 0x10, *(f32 *)(v + 4));
        d.h1A = *(u16 *)(a0 + 0xAA);
        vec_sub_ab(&d.dir, a0 + 0x10, *(u8 **)(a0 + 0xB8) + 0x10);
        d.dir.z = 0.0f;
        func_00388830(&d.dir, &d.dir, 1.6666667f);
        d.b18 = 3;
        d.dir.w = 5627.925f;
        d.flags |= 1;
        owner = *(u8 **)(a0 + 0xB8);
        func_L01_004C76B8();
        hit = func_003CE740(a0 + 0x10, &pos, 0, owner, &d);
        if (hit) {
            m = D_L06_001E8440.target;
            if (m != 0 && *(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
                m[0x20] = 4;
            }
        }
        func_L01_004C76F0();
        if (hit || func_003CE740(a0 + 0x10, &pos, 0, *(u8 **)(a0 + 0xB8), &d) ||
            func_L01_003F9498(a0 + 0x10, 0.2f, 1, *(u8 **)(a0 + 0xB8)) || func_00388398((s32 *)v)) {
            func_003CF790(a0 + 0x10, 1.5f, 0, *(u8 **)(a0 + 0xB8), &d);
            func_0039FE80(0, 0, a0);
            func_L01_0032FE90(a0 + 0x10, 1, 0xF, 0xA, 0xA, 0xA, 0x19, 1, 0.75f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(a0, 1);
            func_L01_00441FB8(a0, 6, -1);
        } else {
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)&pos;
            func_L06_00358D70(a0, v);
        }
        break;
    case 6:
        if (func_L01_00452EC8(a0))
            *(s32 *)v = 60;
        if (func_00388398((s32 *)v))
            func_003BD360(a0);
        break;
    }
}
/* localdecomp:end func_U_L06_003582D8 */
