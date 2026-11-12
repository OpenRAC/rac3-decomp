#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003D26C0);

INCLUDE_ASM("asm/levels", func_L19_003D2788);

/* localdecomp:start func_L19_003D2A40 */
typedef struct { u8 p0[0x18]; u8 *f18; } S_3D2A40g;
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446A70(s32, s32, s32, s32, s32, f32);
extern void func_L19_003D2DD8(void *, s32, s32, s32, void *);
extern u8 *D_L19_001E8E58[];
extern S_3D2A40g D_L19_001E8E40;
__asm__(".extern D_L19_001DEBCC, 4");
extern f32 D_L19_001DEBCC;
__asm__(".extern D_L19_001DEBD0, 4");
extern f32 D_L19_001DEBD0;
__asm__(".extern D_L19_001DEBD4, 4");
extern f32 D_L19_001DEBD4;

void func_L19_003D2A40(u8 *a, void *b) {
    u8 *s;
    u8 *pos;
    s32 r;
    u8 *o;
    u8 *q;
    f32 v[4];
    pos = a + 0x10;
    s = *(u8 **)(a + 0x68);
    func_L01_004CB320();
    r = func_003D3CB0(b, pos, 0, a, 0);
    if (r != 0) {
        o = D_L19_001E8E58[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (r == 0) {
        if (func_L01_003FB640(a + 0x10, 0, a, D_L19_001DEBD4) == 0) {
            return;
        }
    }
    q = D_L19_001E8E40.f18;
    if (q != 0) {
        o = *(u8 **)(s + 0x20);
        if (q != o && (*(u16 *)(q + 0x34) & 0x4000) && *(s16 *)(q + 0xAA) != *(s16 *)(o + 0xAA)) {
            f32 f = D_L19_001DEBCC;
            if (*(s32 *)(s + 0x24) == 0) {
                f = f * 0.5f;
            }
            func_0038CF68(v, s, f);
            v[2] = D_L19_001DEBD0;
            v[3] = 5627.9248f;
            func_L01_00446A70((s32)D_L19_001E8E40.f18, (s32)a, 0x10001, (s32)(a + 0x10), (s32)v, *(f32 *)(s + 0x1C));
            func_L19_003D2DD8(a + 0x10, 0xA, 2, 1, a);
        }
        if (D_L19_001E8E40.f18 != 0) {
            a[0x20] = 2;
            return;
        }
    }
    func_L19_003D2DD8(a + 0x10, 0xF, 5, 0, a);
    a[0x20] = 2;
}
/* localdecomp:end func_L19_003D2A40 */

INCLUDE_ASM("asm/levels", func_L19_003D2BF8);

INCLUDE_ASM("asm/levels", func_L19_003D2DD8);
