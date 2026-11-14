#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00350470 */
extern f32 func_0038DAB8(f32, f32);
extern void func_L30_0034C8A8(void *, void *);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00446BC8(void *, void *, s32, void *, f32);
extern void func_L33_00350188(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);

typedef struct {
    u8 obj[0x10];
    s32 val;
} E_00350470;

typedef struct {
    u8 pad0[0x18];
    u8 *moby;
    u8 pad1C[4];
    vu0_v4 pos;
} T_00350470;

typedef struct {
    u8 pad[0x25C0];
    u8 *moby;
} H_00350470;

extern E_00350470 D_L33_001E1830_00350470 __attribute__((section(".sdata")));
extern T_00350470 D_L33_001E9600;
extern H_00350470 D_001A4BE0;

void func_L33_00350470(u8 *m) {
    u8 *v;
    u8 *t;
    vu0_v4 d;

    v = *(u8 **)(m + 0x68);
    *(f32 *)(v + 0x8) += *(f32 *)(v + 0x14);
    vec_add_ba(m + 0x10, m + 0x10, v);
    *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), *(f32 *)(v + 0x28));
    func_L30_0034C8A8(D_L33_001E1830_00350470.obj, m);
    if (func_L01_003FB640(m + 0x10, 0x10, *(f32 *)(v + 0x20), *(void **)(v + 0x1C)) == 0) {
        return;
    }
    vec_sub_ba(&d, &D_L33_001E9600.pos, m + 0x10);
    if (!(0.0f < func_0038CE68(&d, v))) {
        return;
    }
    t = D_L33_001E9600.moby;
    if (t != 0) {
        if (t == *(void **)(v + 0x1C)) {
            return;
        }
        if (*(s16 *)(t + 0xAA) == 0x1761) {
            return;
        }
        if (*(s16 *)(t + 0xAA) == 0x1760) {
            return;
        }
        if (*(s16 *)(t + 0xAA) == 0x175F) {
            return;
        }
        if (t != 0 && t == D_001A4BE0.moby) {
            func_L01_00446BC8(t, m, 0x30001, &D_L33_001E9600.pos, 20.0f);
        }
    }
    func_L33_00350188(m, &D_L33_001E9600.pos);
    *(vu0_q *)(m + 0x10) = *(vu0_q *)&D_L33_001E9600.pos;
    func_L01_004450F0(m, 0, -1);
}
/* localdecomp:end func_L33_00350470 */

INCLUDE_ASM("asm/levels", func_L33_003505D8);
