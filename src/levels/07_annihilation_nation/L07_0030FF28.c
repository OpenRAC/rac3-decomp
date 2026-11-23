#include "common.h"

/* localdecomp:start func_L07_0030FF28 */
s32 func_0038CAD0(void *);
void func_003C2880(void *);
void func_L01_00404808(void *, void *);
void func_L01_004AA760(s32, void *);
void func_L07_00310160(void *, void *);
extern u8 D_L07_00310558[];

void func_L07_0030FF28(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    *(f32 *)((u8 *)temp_s0 + 0x78) = (f32) ((*(f32 *)((u8 *)temp_s0 + 0x78)) + 1.0f);
    if (((*(s32 *)((u8 *)temp_s0 + 0x74)) != 0) && (func_0038CAD0(temp_s0 + 0x74) != 0)) {
        func_L01_004AA760(0x10, arg0);
        func_003C2880(arg0);
        return;
    }
    if (((*(f32 *)((u8 *)temp_s0 + 0x78)) > 120.0f) && ((*(s32 *)((u8 *)temp_s0 + 0x74)) == 0)) {
        *(s32 *)((u8 *)temp_s0 + 0x74) = 0xC;
    } else {
        func_L07_00310160(arg0, temp_s0);
    }
    func_L01_00404808(D_L07_00310558, arg0);
}
/* localdecomp:end func_L07_0030FF28 */

/* localdecomp:start func_L07_0030FFE8 */
#include "vu0.h"

extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004AAC98(s32, s32, void *, s32);

u8 *func_L07_0030FFE8(u8 *parent, vu0_q *pos, u8 b, f32 x) {
    vu0_v4 tmp;
    u8 *m;
    u8 *v;
    f32 *p;
    s32 i;

    *(vu0_q *)&tmp = *pos;
    m = func_003C24B0(0xABE, 0x80);
    if (m != 0) {
        m[0x30] = 0x7F;
        *(s16 *)(m + 0x32) = 0x7F;
        m[0x31] = 1;
        *(long *)(m + 0x38) = *(long *)(parent + 0x38);
        v = *(u8 **)(m + 0x68);
        *(vu0_q *)(m + 0x10) = *(vu0_q *)&tmp;
        qzero(m + 0xF0);
        *(f32 *)(m + 0xF8) = x;
        *(f32 *)(m + 0x18) += 0.5f;
        *(f32 *)(v + 0x70) = 0.6f;
        *(u8 **)(m + 0xB8) = parent;
        v[0x7C] = b;
        *(s32 *)(v + 0x74) = 0;
        *(s32 *)(v + 0x78) = 0;
        p = (f32 *)v;
        for (i = 0; i < 28; i++) {
            p[i] = func_003824E0(-4.0f, 4.0f) * 0.4f / 100.0f;
            if (i == 0 || i == 27) {
                p[i] = 0.0f;
            }
        }
        func_L01_004AAC98(0x10, 4, m, 0x1A1F);
        func_L07_00310160(m, v);
    }
    return m;
}
/* localdecomp:end func_L07_0030FFE8 */

INCLUDE_ASM("asm/levels", func_L07_00310160);

INCLUDE_ASM("asm/levels", func_L07_00310558);
