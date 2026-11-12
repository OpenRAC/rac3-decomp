#include "common.h"

/* localdecomp:start func_L05_003B2668 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L05_003B27F8(u8 *, f32, f32, f32, s32);

void func_L05_003B2668(u8 *p) {
    u8 *s = *(u8 **)(p + 0x68);
    f32 f;
    f32 sn;
    f32 cs;
    f32 a;
    f32 b;
    u8 idx;

    f = *(f32 *)(s + 0x29C);
    *(f32 *)(s + 0x29C) = f + (f > 0.8f ? 0.02f : 0.08f);
    if (*(f32 *)(s + 0x29C) > 0.95f) {
        *(f32 *)(s + 0x29C) = 0.95f;
    }
    sn = func_0038D0B0(*(f32 *)(s + 0x29C) * 3.1415927f * 0.5f);
    cs = func_0038D098(*(f32 *)(s + 0x29C) * 3.1415927f * 0.5f);
    cs = 1.0f - cs;
    idx = (s32)((1.0f - cs) * 128.0f);
    b = sn * 0.6f + -0.3f + 1.0f;
    a = sn * 10.0f + 5.0f;
    func_L05_003B27F8(p, a, 0.0f, -0.2617994f, idx);
    func_L05_003B27F8(p, a * b, 0.61086524f, -0.2617994f, idx);
}
/* localdecomp:end func_L05_003B2668 */

INCLUDE_ASM("asm/levels", func_L05_003B27F8);

INCLUDE_ASM("asm/levels", func_L05_003B29D0);

/* localdecomp:start func_L05_003B2E40 */
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);

void func_L05_003B2E40(u8 *p) {
    s32 r;
    s32 a;

    a = 0;
    if (*(u8 *)(*(u8 **)(p + 0x68) + 0x2B8) < 3) {
        a = 3 - *(u8 *)(*(u8 **)(p + 0x68) + 0x2B8);
    }
    r = func_00382498(a, 2);
    switch (r) {
    case 0:
        func_L01_004450F0((s32) p, 9, -1);
        return;
    case 1:
        func_L01_004450F0((s32) p, 0xC, -1);
        return;
    case 2:
        func_L01_004450F0((s32) p, 0xF, -1);
        return;
    }
}
/* localdecomp:end func_L05_003B2E40 */

/* localdecomp:start func_L05_003B2EF0 */
__asm__(".extern D_001D545C, 4");
typedef struct { u8 pad[0x18]; u8 *f18; } S_3B2EF0;
extern u8 D_001BBC40[];
__asm__(".extern D_001D5570, 16");
extern u8 D_001D5570[8];
extern u8 D_001A4BE0[];
extern S_3B2EF0 D_L05_001EA6C0;
extern s32 D_001D545C;
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern u8 *func_L01_0045B958(u8 *);
s32 func_L05_003B2EF0(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    u8 *h1; u8 *h2; S_3B2EF0 *g1; S_3B2EF0 *g2;
    u8 *p;
    s32 id;
    if (*(s32 *)(st + 0x20) != 0) {
        if (D_001BBC40[self[0xB0] + (D_001D545C << 4)] & 0x80) return 1;
    }
    if (*(s32 *)(st + 0x30) != 0) {
        if (D_001D5570[*(s32 *)(st + 0x30)] != 0) return 1;
    }
    h1 = D_001A4BE0;
    if (*(u8 **)(h1 + 0x35C) == self) {
        if (*(s32 *)(h1 + 0x360) >= 2) return 1;
    }
    if (func_L01_003FB640(self + 0x10, 1, self, *(f32 *)(self + 0x2C) * 1.1f / *(f32 *)(*(u8 **)(self + 0x24) + 0x24)) != 0) {
        g1 = &D_L05_001EA6C0;
        if (g1->f18 != 0) {
            h2 = D_001A4BE0;
            if (g1->f18 == *(u8 **)(h2 + 0x25C0) && *(u8 **)(h2 + 0x35C) == self) {
                if (*(s32 *)(st + 0x20) != 0) {
                    func_L01_0043B510(self[0xB0]);
                    func_L01_004A3610(h2 + 0x80, h2 + 0x90);
                }
                return 1;
            }
            g2 = &D_L05_001EA6C0;
            if (*(u16 *)(g2->f18 + 0x34) & 0x20) {
                p = func_L01_0045B958(g2->f18);
                if (p != 0 && (*(u8 **)(p + 0x88) == self || *(u8 **)(p + 0x84) == self)) {
                    id = *(s16 *)(g2->f18 + 0xAA);
                    if (id == 0x1A4E || id == 0x1AA0 || id == 0x1BD3 || id == 0x16BE || id == 0x1BA0) return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L05_003B2EF0 */
