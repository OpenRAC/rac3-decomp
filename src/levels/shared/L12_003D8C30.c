#include "common.h"

typedef struct { u8 pad[0x60]; u8 x60; } V_3D6A28;
typedef struct { u8 pad[0x68]; V_3D6A28 *x68; } M_3D6A28;
typedef struct { u8 pad[0x70]; u8 x70[0x100]; s32 x170; u8 pad174[0x18C - 0x174]; M_3D6A28 *x18C; } B_3D6A28;
typedef struct { u8 pad[0xA8]; u8 xA8; } O_3D6A28;

typedef struct { s32 x0; f32 x4; s32 x8; f32 xC; u8 pad10[0x20 - 0x10]; s32 x20; s32 x24; u8 pad28[0x3C - 0x28]; s32 x3C; u8 pad40[0x54 - 0x40]; s32 x54; } Src_003D9000;
typedef struct { u8 pad[0x68]; Src_003D9000 *x68; } Req_003D9000;
typedef struct { u8 pad[0x160]; f32 x160; s32 x164; f32 x168; s32 x16C; s32 x170; s32 x174; u8 pad178[0x180 - 0x178]; s32 x180; s32 x184; } Dst_003D9000;
typedef struct { u8 pad[0x68]; Dst_003D9000 *x68; } Obj_003D9000;

/* localdecomp:start func_L12_003D8C30 */
#include "vu0.h"
typedef int u128_003D8C30 __attribute__((mode(TI)));
typedef struct V_003D8C30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003D8C30;

typedef struct G_003D8C30 {
    u8 pad0[0x19E0];
    s32 x19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    u8 *x25C0;
} G_003D8C30;
extern G_003D8C30 D_001A4BE0;
extern f32 D_L12_001DF024;
__asm__(".extern D_L12_001DF024, 4");
extern f32 D_L12_001DF028;
__asm__(".extern D_L12_001DF028, 4");
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L12_003D8C30(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    V_003D8C30 a;
    V_003D8C30 b;
    f32 d;

    if (*(s16 *)(s + 0x14C) != 0) {
        func_003C2F58(o, 0, &b);
        if (*(u8 **)(s + 0x140) != 0) {
            if (*(u8 **)(s + 0x140) == D_001A4BE0.x25C0 && D_001A4BE0.x19E0 != 0) {
                *(u128_003D8C30 *)&a = *(u128_003D8C30 *)(s + 0x130);
            } else {
                *(u128_003D8C30 *)&a = *(u128_003D8C30 *)(*(u8 **)(s + 0x140) + 0x10);
                a.z += 0.1f;
            }
        } else {
            *(u128_003D8C30 *)&a = *(u128_003D8C30 *)(s + 0x130);
        }
        d = func_0038CF38(&a, &b);
        *(f32 *)(s + 0x200) = -func_0038D160(d, b.z - a.z);
        *(f32 *)(s + 0x208) = func_0038DAB8(func_0038D160(b.x - a.x, b.y - a.y), -(*(f32 *)(o + 0xF8) - 1.5707964f));
        if (*(f32 *)(s + 0x200) > 0.5235988f) {
            *(f32 *)(s + 0x200) = 0.5235988f;
        }
        if (*(f32 *)(s + 0x200) < -0.5235988f) {
            *(f32 *)(s + 0x200) = -0.5235988f;
        }
    } else {
        qzero(s + 0x200);
        *(f32 *)(s + 0x208) = -1.5707964f;
    }
    func_L01_0044E850(o, s + 0x1A0, 0, D_L12_001DF024, D_L12_001DF028);
}
/* localdecomp:end func_L12_003D8C30 */

INCLUDE_ASM("asm/levels", func_L12_003D8DB8);
