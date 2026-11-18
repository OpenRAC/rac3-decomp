#include "common.h"

/* localdecomp:start func_L01_00451388 */
extern void func_003C5278_00451388(void *);

void func_L01_00451388(void *p) {
    func_003C5278_00451388((u8 *)p + 0x10);
}
/* localdecomp:end func_L01_00451388 */

/* localdecomp:start func_L01_004513A8 */
typedef int Q_004513A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004513A8;
extern s32 D_L01_001D673C_004513A8;
extern s32 D_L01_001D6740_004513A8;
extern u8 D_L01_001DFC50_004513A8;
extern V_004513A8 D_L01_001EAA20_004513A8;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_003C5278(void *, void *, void *, f32);
extern f32 func_0038CF00(void *, void *);

f32 func_L01_004513A8(V_004513A8 *p, void *a1, V_004513A8 *out) {
    V_004513A8 a;
    V_004513A8 b;
    f32 d;
    f32 e;
    if (D_L01_001D673C_004513A8 == 0) {
        *(Q_004513A8 *)&b = *(Q_004513A8 *)p;
        *(Q_004513A8 *)&a = *(Q_004513A8 *)p;
        b.z += 0.5f;
        a.z = 0.01f;
        if (func_003D3CB0(&b, &a, 2, a1, 0) != 0) {
            if (out != 0) {
                *(Q_004513A8 *)out = *(Q_004513A8 *)&D_L01_001EAA20_004513A8;
            }
            return p->z - ((f32 *)&D_L01_001EAA20_004513A8)[2];
        }
        if (out != 0) {
            *(Q_004513A8 *)out = *(Q_004513A8 *)p;
        }
        return p->z;
    }
    *(Q_004513A8 *)&a = *(Q_004513A8 *)&D_L01_001DFC50_004513A8;
    if (D_L01_001D6740_004513A8 != 0) {
        *(Q_004513A8 *)&a = *(Q_004513A8 *)p;
        func_003C5278(&a, &a, &a, -10.0f);
    }
    func_003C5278(p, &b, p, -0.5f);
    d = func_0038CF00(p, &a);
    if (func_003D3CB0(&b, &a, 2, a1, 0) != 0) {
        if (out != 0) {
            *(Q_004513A8 *)out = *(Q_004513A8 *)&D_L01_001EAA20_004513A8;
        }
        e = func_0038CF00(p, &D_L01_001EAA20_004513A8);
        if (d < func_0038CF00(&D_L01_001EAA20_004513A8, &a)) {
            e = -e;
        }
        return e;
    }
    if (out != 0) {
        *(Q_004513A8 *)out = *(Q_004513A8 *)p;
    }
    return d;
}
/* localdecomp:end func_L01_004513A8 */

LINKER_REMNANT("asm/levels", func_L01_00451578);
