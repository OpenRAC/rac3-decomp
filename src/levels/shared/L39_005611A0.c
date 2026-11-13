#include "common.h"

/* localdecomp:start func_L39_005611A0 */
#include "vu0.h"
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern f32 D_L39_0024B40C;
__asm__(".extern D_L39_0024B40C, 4");
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L39_0066C828(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4840(f32 *q, void *axis, f32 angle);
extern void func_0038D850(void *out, void *a, void *b);
extern void func_003C48A8(void *, void *);
extern void func_L39_005614B0(u8 *);
extern u8 *func_L39_0061BF38(s32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_00560618(u8 *, u8 *, s32);
extern s32 func_L39_00560330(u8 *, u8 *);

void func_L39_005611A0(u8 *m) {
    vu0_v4 t;
    s32 i;
    u8 *o;

    switch (m[0x20]) {
    case 0:
        func_0038CF68(&t, m + 0xE0, 0.75f);
        vec_add_ab(m + 0x10, m + 0x10, &t);
        func_L39_0066C828(m, -1, 1);
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            *(u16 *)(m + 0x34) &= ~0x41;
        }
        if (*(f32 *)(m + 0xF0) == 0.0f && *(f32 *)(m + 0xF4) == 0.0f) {
            *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.09424779f);
        } else {
            func_003C4840((f32 *)&t, m + 0xE0, 0.09424779f);
            func_0038D850(m + 0xC0, m + 0xC0, &t);
            func_0038D850(m + 0xD0, m + 0xD0, &t);
            func_003C48A8(m + 0xC0, m + 0xF0);
        }
        if (m[0x31] != 0) {
            func_L39_005614B0(m);
        }
        for (i = 0; i < *D_00241120; i++) {
            o = func_L39_0061BF38(i);
            if (o == 0) continue;
            if (func_L01_0040E548(o + 0xA0, m + 0x10) < D_L39_0024B40C) {
                if (func_L39_00560618(o, m, 1) != 0) {
                    *(u16 *)(m + 0x34) |= 0x41;
                    func_L01_004450F0(m, 2, -1);
                    break;
                }
                if (func_L39_00560330(o, m) != 0) {
                    func_L01_004450F0(m, 2, -1);
                    break;
                }
            }
        }
        break;
    case 2:
        *(u16 *)(m + 0x96) += 1;
        if (m[0x31] != 0) {
            func_L39_005614B0(m);
            if (*(f32 *)(m + 0xF0) == 0.0f && *(f32 *)(m + 0xF4) == 0.0f) {
                *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.09424779f);
            } else {
                func_003C4840((f32 *)&t, m + 0xE0, 0.09424779f);
                func_0038D850(m + 0xC0, m + 0xC0, &t);
                func_0038D850(m + 0xD0, m + 0xD0, &t);
                func_003C48A8(m + 0xC0, m + 0xF0);
            }
        }
        if (*(u16 *)(m + 0x96) >= 0x4C) {
            *(u16 *)(m + 0x34) &= ~0x41;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 3:
        if (m[0x31] != 0) {
            func_L39_005614B0(m);
        }
        break;
    }
}
/* localdecomp:end func_L39_005611A0 */

INCLUDE_ASM("asm/levels", func_L39_005614B0);
