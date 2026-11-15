#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L08_00310D78 */
#include "vu0.h"

extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0044C870(u8 *, s32, u8 *, void *);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_L01_0044C638(u8 *, s32, u8 *, u8 *, u8 *, u8 *);
extern s32 func_L01_0044C790(u8 *, s32, u8 *, u8 *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_0044AF78(void *, void *, void *, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L08_003115B0(u8 *);
extern u8 *D_L08_001E8A98[];
extern s32 D_001DC570_sda;
__asm__(".extern D_001DC570_sda, 4");
extern u8 D_L08_001D66B0[8];
extern u8 D_001A30B0[];

void func_L08_00310D78(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *pos;
    s32 hit;
    u8 *g;
    u8 *g2;
    s32 idx;
    u8 *e;
    vu0_v4 v90;
    vu0_v4 vA0;
    u8 vB0[0x30] __attribute__((aligned(16)));
    u128_t vE0[2] __attribute__((aligned(16)));
    vu0_v4 v100;

    switch (a0[0x20]) {
    case 0:
        *(f32 *)(st + 0x18) = func_0038DAB8(*(f32 *)(st + 0x18), *(f32 *)(st + 0x1C));
        qzero(&v90);
        v90.y = *(f32 *)(st + 0x18) * 0.25f;
        v90.x = *(f32 *)(st + 0x18) * 0.5f;
        v90.z = *(f32 *)(st + 0x18);
        func_0038D308(a0 + 0xC0, &v90);
        vec_add_ba(&vA0, a0 + 0x10, st);
        func_L01_00446760(vB0, *(void **)(st + 0x10), 1, st, *(f32 *)(st + 0x14));
        *(u16 *)(vB0 + 0x1A) = *(u16 *)(a0 + 0xAA);
        func_L01_004CB320();
        hit = func_003D3CB0(a0 + 0x10, &vA0, 0, a0, vB0);
        if (hit != 0) {
            g = D_L08_001E8A98[0];
            if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
                g[0x20] = 4;
            }
        }
        func_L01_004CB358();
        pos = a0 + 0x10;
        if (hit != 0 || func_L01_003FB640(pos, 0, a0, 0.3f) != 0) {
            g2 = D_L08_001E8A98[0];
            if (g2 != 0) {
                if (g2 != *(u8 **)(st + 0x10)) {
                    func_L01_00446780(*(u8 **)(st + 0x10), pos, 0x10001, 0, 1, 0, 0.3f, *(f32 *)(st + 0x14), 0.0f);
                    func_L01_004450F0(a0, 1, -1);
                    return;
                }
            } else {
                func_L01_00446780(*(u8 **)(st + 0x10), pos, 0x10001, 0, 1, 0, 0.3f, *(f32 *)(st + 0x14), 0.0f);
                func_L01_004450F0(a0, 1, -1);
                return;
            }
        }
        *(vu0_v4 *)(a0 + 0x10) = vA0;
        func_0038CE20(vE0, st, -0.5f);
        qzero(&vE0[1]);
        if (*(s32 *)(st + 0x24) != 0) {
            func_L01_0044C870(a0, *(s32 *)(st + 0x24), pos, &v100);
            vec_add_ab(vE0, vE0, &v100);
        }
        func_L01_0046FB40(pos, vE0, 5, D_001DC570_sda, 3, 0x4F, 0,
                          func_003824E0(1.0f, 1.5f) * 210000.0f * *(f32 *)(st + 0x20),
                          func_003824E0(0.2f, 0.4f) * 210000.0f * *(f32 *)(st + 0x20), 0.0f, 0);
        v100 = *(vu0_v4 *)(a0 + 0x10);
        v100.x += func_L01_00443A18(0.0f, 0.15f);
        v100.y += func_L01_00443A18(0.0f, 0.15f);
        v100.z += func_L01_00443A18(0.0f, 0.15f);
        func_L01_0046FB40(&v100, vE0, 5, D_001DC570_sda, 7, 0x5F, 0,
                          func_003824E0(1.0f, 1.5f) * 210000.0f * *(f32 *)(st + 0x20),
                          func_003824E0(0.1f, 0.3f) * 210000.0f * *(f32 *)(st + 0x20), 0.0f, 0);
        v100.x += func_L01_00443A18(0.0f, 0.15f);
        v100.y += func_L01_00443A18(0.0f, 0.15f);
        v100.z += func_L01_00443A18(0.0f, 0.15f);
        func_L01_0046FB40(&v100, vE0, 5, D_001DC570_sda, 0xC, 0x7F, 0,
                          func_003824E0(1.0f, 1.5f) * 210000.0f * *(f32 *)(st + 0x20),
                          func_003824E0(0.2f, 0.4f) * 210000.0f * *(f32 *)(st + 0x20), 0.0f, 0);
        if (*(s32 *)(st + 0x24) != 0) {
            func_L01_0044C638(a0, *(s32 *)(st + 0x24), pos, a0 + 0xF0, pos, a0 + 0xF0);
            func_L01_0044C790(a0, *(s32 *)(st + 0x24), st, st);
        }
        break;
    case 1:
        idx = *(s32 *)(st + 0x28);
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(st + 0x28) = -1;
        func_003A52A0(1, 0, a0);
        func_L01_0044AF78(a0, D_L08_001D66B0, a0 + 0x10, 0.0f, 0.0f, 0, 0, 6, -1, 0, 1, -1, 0, 0x1010001, 0.0f, 0.0f, 9.0f, 1.0f, 0.0f);
        func_L01_003303B8(a0 + 0x10, 0, 2, 2, 2, 2, 2, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C2880(a0);
        return;
    }
    if (*(f32 *)(st + 0x20) < 1.0f) {
        *(f32 *)(st + 0x20) += 0.025f;
    }
    *(f32 *)(a0 + 0x2C) = func_003824E0(0.01f, 0.0125f) * *(f32 *)(st + 0x20);
    func_L01_00404A10(func_L08_003115B0, a0);
}
/* localdecomp:end func_L08_00310D78 */
