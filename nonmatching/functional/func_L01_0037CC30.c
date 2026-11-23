/* functional: high. PAL-specific: callees/consts re-checked against PAL asm; byte diffs are frame size and scheduling only. */
/* localdecomp:start func_L01_0037CC30 */
#include "vu0.h"
typedef int s128 __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s32 i[0xA80]; } Hero;
typedef struct {
    f32 d0, d4, d8, dC;
    f32 e0, e4, e8, eC;
    s128 q20;
    s128 q30;
    u8 p40[0x10];
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80, f84, f88, f8C, f90, f94;
    u8 timer[8];
    u8 *owner;
    u8 *target;
    u8 pA8[8];
} S_Slot;
typedef struct {
    u8 p0[0x50];
    s32 cnt;
    u8 p54[0x3C];
    S_Slot slots[12];
} S_Obj;

extern Hero D_001A4BE0;
extern s32 D_L01_001EEA80[];
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_L01_0037C978(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_00382348();
extern s32 func_0038CAD0(void *);

void func_L01_0037CC30(u8 *a) {
    S_Obj *s5 = *(S_Obj **)(a + 0x68);
    s128 q0;
    s128 tmp;
    S_Slot *p;
    u8 *v;
    s32 n;
    s32 i;
    s32 k;
    func_003C2F58(a, 0, &q0);
    n = func_003D4D00(a + 0x10, 1, 6.0f, a, 0);
    for (i = 0; i < n; i++) {
        func_L01_0037C978(a, D_L01_001EEA80[i], 2500);
    }
    for (k = 0; k < 12; k++) {
        if (s5->slots[k].owner != a) continue;
        if (s5->slots[k].target == 0) continue;
        p = &s5->slots[k];
        p->f50 = func_0038DAB8(p->f50, p->f5C);
        p->f54 = func_0038DAB8(p->f54, p->f60);
        p->f58 = func_0038DAB8(p->f58, p->f64);
        p->f74 = func_0038DAB8(p->f74, p->f80);
        p->f78 = func_0038DAB8(p->f78, p->f84);
        p->f7C = func_0038DAB8(p->f7C, p->f88);
        p->d0 = func_0038D098(p->f50) * p->f68;
        p->d4 = func_0038D0B0(p->f54) * p->f6C;
        p->d8 = -func_0038D0B0(p->f58) * p->f70;
        p->e0 = func_0038D098(p->f74) * p->f8C;
        p->e4 = func_0038D0B0(p->f78) * p->f90;
        p->e8 = -func_0038D0B0(p->f7C) * p->f94;
        p->q20 = q0;
        if (s5->slots[k].target == *(u8 **)(D_001A4BE0.b + 0x25C0)) {
            func_L01_004C7D98(a + 0x10, &tmp);
            func_0038CE20(&tmp, &tmp, 0.8f);
            vec_add_ab(&p->q30, D_001A4BE0.b + 0x80, &tmp);
        } else {
            v = func_00382348();
            if (v != 0) {
                func_L01_004C7D98(a + 0x10, &tmp);
                func_0038CE20(&tmp, &tmp, *(f32 *)(v + 0x10));
                vec_add_ba(&p->q30, s5->slots[k].target + 0x10, &tmp);
            }
        }
        if (func_0038CAD0(p->timer) != 0) {
            p->target = 0;
            p->owner = 0;
            s5->cnt--;
        }
    }
}
/* localdecomp:end func_L01_0037CC30 */
