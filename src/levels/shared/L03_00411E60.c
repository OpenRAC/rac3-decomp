#include "common.h"

/* localdecomp:start func_L03_00411E60 */
extern s32 D_L03_001E6834[];
extern void func_0038CF68(void *, void *, f32);

void func_L03_00411E60(u8 *m, s32 a, s32 b) {
    s32 lo = (a * 5 + 2) / 6;
    s32 d = D_L03_001E6834[0];
    s32 hi;
    f32 t;
    s32 i;
    u8 *p;
    u8 *q;
    if (d < lo) {
        return;
    }
    hi = (b * 5 + 2) / 6;
    if (hi < d) {
        return;
    }
    t = (f32)(hi - d) / (f32)(hi - lo);
    if (m == 0) {
        return;
    }
    q = m + 0xE0;
    p = m + 0xC0;
    for (i = 0; i < 2; i++) {
        func_0038CF68(p, p, t);
        p += 0x10;
    }
    func_0038CF68(q, q, 1.0f - t + 1.0f);
}
/* localdecomp:end func_L03_00411E60 */

/* localdecomp:start func_L03_00411F50 */
typedef int u128_00411F50 __attribute__((mode(TI)));
typedef struct { f32 a; f32 b; } F2_00411F50;
extern s16 D_L03_001D6C90;
__asm__(".extern D_L03_001D6C90, 2");
extern s16 D_L03_001D6C92;
__asm__(".extern D_L03_001D6C92, 16");
extern f32 D_L03_001D6C94;
__asm__(".extern D_L03_001D6C94, 16");
extern f32 D_L03_001D6C98;
__asm__(".extern D_L03_001D6C98, 16");
extern F2_00411F50 D_L03_001D6C98_00411F50;
__asm__(".extern D_L03_001D6C98_00411F50, 16");
extern F2_00411F50 D_L03_001D6C9C_00411F50;
__asm__(".extern D_L03_001D6C9C_00411F50, 16");
extern s32 D_L03_001D6CA4;
__asm__(".extern D_L03_001D6CA4, 16");
extern s32 D_L03_001D6CA8;
__asm__(".extern D_L03_001D6CA8, 16");
extern s16 D_L03_001D6CB0;
__asm__(".extern D_L03_001D6CB0, 2");
extern s16 D_L03_001D6CB2;
__asm__(".extern D_L03_001D6CB2, 16");
extern f32 D_L03_001D6CB4;
__asm__(".extern D_L03_001D6CB4, 16");
extern f32 D_L03_001D6CB8;
__asm__(".extern D_L03_001D6CB8, 16");
extern F2_00411F50 D_L03_001D6CB8_00411F50;
__asm__(".extern D_L03_001D6CB8_00411F50, 16");
extern F2_00411F50 D_L03_001D6CBC_00411F50;
__asm__(".extern D_L03_001D6CBC_00411F50, 16");
extern s32 D_L03_001D6CC4;
__asm__(".extern D_L03_001D6CC4, 16");
extern s32 D_L03_001D6CC8;
__asm__(".extern D_L03_001D6CC8, 16");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_00411F50(u8 *m, s32 a1) {
    f32 mat[4][4];
    f32 pos[4];
    f32 v[4];
    u8 *p;
    if (*(s16 *)(m + 0xAA) != 0x1C86) {
        return;
    }
    *(u128_00411F50 *)v = 0;
    v[2] = -1.0f;
    func_003C2EC0(m, a1, mat);
    *(u128_00411F50 *)pos = *(u128_00411F50 *)mat[3];
    func_0038D028(v, v, mat);
    func_0038CF68(v, v, func_003824E0(D_L03_001D6CBC_00411F50.b, D_L03_001D6CB8_00411F50.b));
    p = func_L01_004637C8(pos, v, D_L03_001D6CC4, D_L03_001D6CC8, D_L03_001D6CB0 + func_00382468(D_L03_001D6CB2),
                          (s32)D_L03_001D6CB8, (s32)D_L03_001D6CB4 + func_00382468(2), 0);
    if (p != 0) {
        p[9] = 0x40;
    }
    func_0038CF68(v, v, func_003824E0(D_L03_001D6C9C_00411F50.b, D_L03_001D6C98_00411F50.b));
    p = func_L01_00475C60(pos, v, func_00382498(D_L03_001D6C92, D_L03_001D6C90), 0, D_L03_001D6CA4, D_L03_001D6CA8,
                          (f32)(s32)(D_L03_001D6C94 * 210000.0f), (f32)(s32)(D_L03_001D6C98 * 210000.0f), 0.0f, 1);
    if (p != 0) {
        p[9] = 0x40;
    }
}
/* localdecomp:end func_L03_00411F50 */
