/* near miss (level 5): 89 differences with -mvu0-use-vf0-vf2 and @ps2as on its file; every instruction and the stack layout are right, but ours hoists the D_001EA6C0/D_001EA6E0 addresses into saved registers and strength-reduces the D_001E1D70[i] store where retail rebuilds lui/addiu in the loop and keeps i<<4 (frame 0xA0 against retail 0x90) */
#include "common.h"

/* localdecomp:start func_L05_003B1CF8 */
#include "vu0.h"
typedef struct {
    char pad0[0x18];
    u8 *f18;
} S_3B1CF8;
extern S_3B1CF8 D_L05_001EA6C0;
extern vu0_v4 D_L05_001EA6E0;
extern vu0_v4 D_L05_001E1D70[];
extern s32 func_L05_003B1E80(s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00446BC8(f32, void *, s32);

void func_L05_003B1CF8(u8 *o) {
    u8 *p = *(u8 **)(o + 0x68);
    s32 i;
    vu0_v4 m[3];
    vu0_v4 a;
    vu0_v4 b;
    s32 hit;
    for (i = 0; i < 2; i++) {
        if (((p[0x2BB] >> i) & 1) == 0) {
            continue;
        }
        func_003C2EC0(o, func_L05_003B1E80(i, 1), m);
        func_0038CF68(&b, m, 30.0f);
        vec_add_ab(&b, &a, &b);
	lqc2 $vf2, %2
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0" : "=m"(b) : "m"(a), "m"(b));
        func_L01_004CB320();
        hit = func_003D3CB0(&a, &b, 0, o, 0);
        if (hit != 0) {
            u8 *q = D_L05_001EA6C0.f18;
            if (q != 0 && *(s16 *)(q + 0xAA) == 0x186D && q[0x20] != 2 && q[0x20] != 5) {
                q[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            u8 *q;
            b = D_L05_001EA6E0;
            q = D_L05_001EA6C0.f18;
            if (q != 0 && (*(u16 *)(q + 0x34) & 0x4000) != 0) {
                func_L01_00446BC8((f32)p[0x45], o, 0x10001);
            }
        }
        D_L05_001E1D70[i] = b;
    }
}
/* localdecomp:end func_L05_003B1CF8 */
