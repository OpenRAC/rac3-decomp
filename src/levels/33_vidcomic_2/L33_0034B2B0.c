#include "common.h"

/* localdecomp:start func_L33_0034B2B0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0034B2B0;
typedef struct {
    s16 id;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    u8 pad20[8];
    s32 f28;
    s32 f2C;
} E_0034B2B0;
typedef struct {
    E_0034B2B0 ent[1];
} P_0034B2B0;
extern u8 *D_L33_001DFB1C;
extern f32 D_L33_001DD788;
extern f32 D_L33_001DD78C;
extern f32 D_L33_001DD794;
__asm__(".extern D_L33_001DD788, 16");
__asm__(".extern D_L33_001DD78C, 16");
__asm__(".extern D_L33_001DD794, 16");
extern void func_L01_00456230(u8 *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L33_0034FEE8(void *, V_0034B2B0 *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L33_00353800(void *, V_0034B2B0 *, s32, s32, s32, s32, s32);

void func_L33_0034B2B0(u8 *a0, s32 i, void *a2) {
    P_0034B2B0 *e = *(P_0034B2B0 **)(a0 + 0x68);
    V_0034B2B0 v;
    s32 n;

    switch (e->ent[i].id) {
    case 0x174A:
        if (e->ent[i].f8 != -1) {
            func_L01_00456230(D_L33_001DFB1C + (e->ent[i].f8 << 8), 1);
        }
        break;
    case 0x174B:
        qzero(&v);
        v.x = e->ent[i].f10;
        v.z = e->ent[i].f14;
        func_L33_0034FEE8(a2, &v, 0, 1, 0, 1.0f, 0.0f, D_L33_001DD788, D_L33_001DD794, D_L33_001DD78C);
        break;
    case 0x175F:
    case 0x1760:
    case 0x1761:
        if (e->ent[i].id == 0x175F) {
            n = 2;
        } else if (e->ent[i].id == 0x1760) {
            n = 1;
        } else if (e->ent[i].id == 0x1761) {
            n = 0;
        }
        qzero(&v);
        v.x = func_003824E0(e->ent[i].f10, e->ent[i].f14);
        v.z = func_003824E0(e->ent[i].f18, e->ent[i].f1C);
        func_L33_00353800(a2, &v, n, e->ent[i].f28, e->ent[i].f2C, e->ent[i].f8, 0);
        break;
    }
}
/* localdecomp:end func_L33_0034B2B0 */
