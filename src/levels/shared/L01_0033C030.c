#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0033C030 */
typedef struct {
    u8 p0[0x230];
    s32 w230;
    u8 p234[0x28C8 - 0x234];
    u8 b28C8;
} Hero_0033C030;

typedef struct {
    u8 p0[0xF6];
    s16 hF6;
    u8 pF8[3];
    u8 bFB;
    u8 pFC[0x30];
    u8 *w12C;
} T_0033C030;

extern s32 D_L01_001DCFB0;
__asm__(".extern D_L01_001DCFB0, 4");
extern u8 D_001A7E18[];
extern Hero_0033C030 D_001A4BE0;
extern u8 *D_L01_00221098[];
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u16 D_001A8A9C[];

extern s32 func_00382468(s32);
extern void func_L01_004443E8(void *, s32, s32);
extern s32 func_L01_0041A5B0(s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);
extern s32 func_L01_00443FB0(void *, s32 *);
extern void func_L01_0030F288(void *, s32, s32, s32);

void func_L01_0033C030(u8 *self) {
    T_0033C030 *t;
    s32 lv;
    s32 k;
    s32 n;
    s32 cnt;
    s32 x;
    s32 sel;
    u8 *sv;
    u8 *p;
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    f32 big;

    t = *(T_0033C030 **)(self + 0x68);
    x = t->hF6 == 0;
    if (*(s16 *)(self + 0xAA) == 0x1F5 || *(s16 *)(self + 0xAA) == 0x200 ||
        *(s16 *)(self + 0xAA) == 0x1F7 || *(s16 *)(self + 0xAA) == 0x1FA) {
        x = 0;
    }
    if (x != 0) {
        lv = D_L01_001DCFB0;
        if (lv >= 21) {
            k = 0;
        } else if (lv >= 11) {
            k = 1;
        } else {
            k = 2;
        }
        func_L01_004443E8(self, 0x100, func_00382468(2) + k);
        return;
    }
    if (*(s16 *)(self + 0xAA) == 0x1F5 || *(s16 *)(self + 0xAA) == 0x200) {
        goto tail;
    }
    if (*(s16 *)(self + 0xAA) == 0x1F7) {
        sv = D_001A7E18;
        if (*(u16 *)(sv + 0xF048) == 0) {
            func_L01_0041A5B0(0x1406, 0x108);
            if (*(u16 *)(sv + 0xF048) == 0) {
                *(u16 *)(sv + 0xF048) = 1;
            }
        }
        D_001A4BE0.b28C8 = D_001A4BE0.b28C8 + 1;
        big = 157500.0f;
        D_001A4BE0.w230 = D_001A4BE0.w230 + 1500;
        func_L01_00451E78(self, 1, 0.0f);
        k = 1;
        *(vu0_q *)&v0 = *(vu0_q *)(self + 0x10);
        v0.z = v0.z + 0.5f;
        do {
            p = func_L01_0046A610(&v0, D_L01_001D66B0, 50, 6, 0x904020, (s32)func_L01_00443A18(1.0f, -1.0f),
                                  big * 6.0f, 1000.0f, 0.0f, 0.0f, 0.0f);
            if (p != 0) {
                p[2] = D_L01_00221098[0x170 / 4][1];
            }
            k--;
        } while (k >= 0);
        k = 1;
        do {
            p = func_L01_0046A610(&v0, D_L01_001D66B0, 50, 0x7F, 0x804020, (s32)func_L01_00443A18(1.0f, -1.0f),
                                  big * 5.0f, 1000.0f, 0.0f, 0.0f, 0.0f);
            if (p != 0) {
                p[2] = D_L01_00221098[0x170 / 4][0];
            }
            k--;
        } while (k >= 0);
        n = 0x1D;
        do {
            func_00382580(&v1, 1.5f, 2.0f);
            vec_add_ab(&v1, &v1, &v0);
            vec_sub_ab(&v2, &v0, &v1);
            func_0038CF68(&v2, &v2, 0.40000004f);
            func_L01_004735F0(&v1, &v2, 0x25, 5.0f);
            n--;
        } while (n >= 0);
        goto tail;
    }
    if (*(s16 *)(self + 0xAA) == 0x1FA) {
        t->w12C[0xBC] = 1;
        *(s32 *)(t->w12C + 0xB8) = 0;
        if (D_001A8A9C[0] == 0) {
            func_L01_0041A5B0(0x1409, 0x10B);
        }
        goto tail;
    }
    switch (t->bFB) {
    case 1: sel = 0x27; break;
    case 2: sel = 0x2F; break;
    case 3: sel = 0x47; break;
    case 4: sel = 0x37; break;
    case 5: sel = 0x6F; break;
    case 6: sel = 0x3F; break;
    case 7: sel = 0x5F; break;
    case 8: sel = 0x11; break;
    case 9: sel = 0x7F; break;
    case 10: sel = 0x77; break;
    case 11: sel = 0x57; break;
    case 12: sel = 0x4F; break;
    case 13: sel = 0x67; break;
    case 14: sel = 0x97; break;
    case 15: sel = 0x13; break;
    case 16: sel = 0x16; break;
    case 0:
    default: sel = -1; break;
    }
    x = sel;
    cnt = func_L01_00443FB0(self, &x);
    for (k = 0; k < cnt; k++) {
        func_L01_0030F288(self + 0x10, x, -1, 0);
    }
tail:
    if (*(s16 *)(self + 0xB4) != 0) {
        *(s16 *)(self + 0xB4) = 0;
    }
    func_L01_004443E8(self, 0x100, 0);
}
/* localdecomp:end func_L01_0033C030 */
