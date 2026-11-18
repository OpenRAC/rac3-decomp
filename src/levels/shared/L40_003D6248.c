#include "common.h"

/* declared by functions of L40_003D61D8.c, which this file was cut from */
typedef struct { s32 id; s32 pad[5]; } Ent_003D6040;

/* localdecomp:start func_L40_003D6248 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1C[4];
    vu0_v4 f20;
} S_003D6248;
extern S_003D6248 D_L40_0025B980;
__asm__(".extern D_L40_00241120, 16");
extern s32 *D_L40_00241120;
__asm__(".extern D_L40_00246984, 4");
extern f32 D_L40_00246984;
extern s32 func_L40_003D5710(u8 *);
extern void func_003C2880(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_0066C828(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4840(f32 *out, u8 *axis, f32 angle);
extern void func_0038D850(void *out, void *a, void *b);
extern void func_003C48A8(void *, void *);
extern u8 *func_L39_0061BF38(s32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L40_003D5840(u8 *, u8 *);
extern void func_L40_003D65A8(u8 *);

void func_L40_003D6248(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    Ent_003D6040 *e;
    s32 i;
    u8 *p;

    switch (*(u8 *)(m + 0x20)) {
    case 0:
        if (func_L40_003D5710(m) == 0) {
            func_003C2880(m);
            break;
        }
        func_0038CF68(&a, m + 0xE0, 0.5f);
        vec_add_ba(&a, &a, m + 0x10);
        func_0038CF68(&b, m + 0xE0, -20.0f);
        vec_add_ab(&b, &b, m + 0x10);
        if (func_003D3CB0(&a, &b, 2, 0, 0) != 0 && D_L40_0025B980.f18 == 0) {
            func_0038CF68(m + 0x10, m + 0xE0, 0.75f);
            vec_add_ba(m + 0x10, m + 0x10, &D_L40_0025B980.f20);
        }
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.5f;
        *(s32 *)(v + 0x18) = 0;
        *(s32 *)(v + 0x14) *= 1000;
        e = func_L40_003D61D8(*(s16 *)(m + 0xAA));
        *(s32 *)(v + 0x10) = e->pad[0];
        *(s32 *)(v + 0x20) = e->pad[1];
        *(s32 *)(v + 0x24) = e->pad[2];
        *(s32 *)(v + 0x28) = e->pad[3];
        *(s32 *)(v + 0x2C) = e->pad[4];
        func_L39_0066C828(m, -1, 1);
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            *(u16 *)(m + 0x34) &= ~0x41;
        }
        if (*(f32 *)(m + 0xF0) == 0.0f && *(f32 *)(m + 0xF4) == 0.0f) {
            *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.0942477882f);
        } else {
            func_003C4840((f32 *)&a, m + 0xE0, 0.0942477882f);
            func_0038D850(m + 0xC0, m + 0xC0, &a);
            func_0038D850(m + 0xD0, m + 0xD0, &a);
            func_003C48A8(m + 0xC0, m + 0xF0);
        }
        if (*(u8 *)(m + 0x31) != 0) {
            func_L40_003D65A8(m);
        }
        for (i = 0; i < *D_L40_00241120; i++) {
            p = func_L39_0061BF38(i);
            if (p == 0) {
                continue;
            }
            if (func_L01_0040E548(p + 0xA0, m + 0x10) < D_L40_00246984 && func_L40_003D5840(p, m) != 0) {
                *(u16 *)(m + 0x34) |= 0x41;
                func_L01_004450F0(m, 2, -1);
                break;
            }
        }
        break;
    case 2:
        if (++*(u16 *)(m + 0x96) >= 0x4C) {
            *(u16 *)(m + 0x34) &= ~0x41;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            *(u16 *)(m + 0x34) |= 0x41;
        }
        break;
    }
}
/* localdecomp:end func_L40_003D6248 */

/* localdecomp:start func_L40_003D65A8 */
/* The code of func_L39_005614B0 with the two colours read from the moby's vars (+0x28, +0x2C)
 * instead of constants. As there: fabs_asm keeps abs.s out of the jal delay slot, the callee
 * returns s32 (unused), and the $gp floats carry .extern size hints. */
#include "vu0.h"
extern u32 D_L40_0024112C;
extern f32 D_L40_00246988;
__asm__(".extern D_L40_00246988, 4");
extern f32 D_L40_0024698C;
__asm__(".extern D_L40_0024698C, 4");
extern s32 D_L40_00246990;
__asm__(".extern D_L40_00246990, 4");
extern s32 D_L40_00246994;
__asm__(".extern D_L40_00246994, 4");
extern void func_0038CE20(f32 *, f32 *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L39_005CDCF0(f32 *, s32, u8, s32, s32, s32, s32, s32, f32);

void func_L40_003D65A8(u8 *a0) {
    f32 v[4];
    s32 i;
    s32 t;
    s32 c;
    s32 b;
    u8 *st = *(u8 **)(a0 + 0x68);

    func_0038CE20(v, (f32 *)a0, 0.0009765625f);
    for (i = 0; i < 4; i++) {
        t = ((s32)((D_L40_0024112C + i * 20) & 0xFF) * 5 + 2) / 6;
        c = func_0038DBD8(*(s32 *)(st + 0x28), *(s32 *)(st + 0x2C), fabs_asm(0.5f - (f32)(212 - t) / 212.0f));
        b = *(u8 *)&D_L40_0024112C;
        if (i & 2) {
            b = b * 2;
        }
        if (i & 1) {
            b = 255 - b;
        }
        func_L39_005CDCF0(v, c, b, D_L40_00246994, D_L40_00246990, 2, 0, 0,
                          (D_L40_00246988 + (f32)i * D_L40_0024698C) * (*(f32 *)(a0 + 0x2C) / ((f32 *)*(u8 **)(a0 + 0x24))[9]));
    }
}
/* localdecomp:end func_L40_003D65A8 */
