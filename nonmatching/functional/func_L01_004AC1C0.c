/* functional: medium. Hand-decoded from the asm: every branch of the h0xC state machine, the 0xD54 target checks (merged into a helper valid_4AC1C0, which has no side effects), the colour pulse and the 0x16C5A6/0x16C650 camera-target writes follow retail order. Unnamed globals: D_001D6694_sda/D_001D6706_sda are the $gp-relative slots (gp 0x1DC8B0), D_0016C650/D_0016C5A6 core data. vadd.xyz written as three float adds (w kept). func_003C3D30 is called with (vec,0,0,0.5f). Not byte-compared beyond compiling (264 diff = scheduling). */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 D_001D6694_sda;
extern s16 D_001D6706_sda;
extern u32 D_001D545C;
extern u8 D_001D5533;
extern u8 *D_001D52FC;
extern s32 D_001D673C;
extern u8 D_0016C650[];
extern s16 D_0016C5A6;
extern s32 D_L01_001DFC28;
extern u8 *D_L01_0023AC70[];
extern u8 D_L01_001E29C0[];
__asm__(".extern D_001D6694_sda, 4");
__asm__(".extern D_001D6706_sda, 2");
extern s32 func_L01_0044C108(void *);
extern void func_003A58C0(void *, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_003A7AF8(void);
extern void func_L01_004AC618(void);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D098(f32);
extern s32 func_L01_00511A98(void);
extern s32 func_L01_004BA800(void);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003C48A8(void *, void *);
extern void func_L01_00452658(s32, s32);

static s32 valid_4AC1C0(u8 *o) {
    return o != 0 && *(s16 *)(o + 0xAA) == 0xD54 && o[0x20] != 0xFE && o[0x20] != 0xFD;
}

void func_L01_004AC1C0(u8 *self) {
    u8 *pos = self + 0x10;
    u8 *p;
    u8 *g;
    u8 **q;
    u8 *m;
    s32 n;
    s32 flag;
    f32 f;
    vu0_v4 v;
    vu0_v4 w;

    if (func_L01_0044C108(pos) == 0) {
        return;
    }
    p = *(u8 **)(self + 0x68);
    if (D_001D6694_sda == 0) {
        func_003A58C0(self, 0);
    }
    if (self[0x31] != 0) {
        p[0xE] = p[0xE] + 2;
        for (q = D_L01_0023AC70; *q != 0; q++) {
            if (*(s16 *)(*q + 0xAA) == D_001D6706_sda) {
                break;
            }
        }
        if (*q != 0) {
            f = func_0038D098((f32)(p[0xE] - 0x80) * 0.024543693f);
            n = (s32)(f * 50.0f) + 0x8C;
            *(s32 *)(*q + 0x78) = n | (n << 8) | (n << 16);
            *(u16 *)(*q + 0x34) |= 0x10;
        }
        func_L01_00404A10((void *)func_003A7AF8, self);
        f = func_0038CF38(pos, D_L01_001E29C0);
        if (f < 32.0f) {
            func_L01_00404808((void *)func_L01_004AC618, self);
        }
    }
    g = D_001A4BE0;
    if (*(s16 *)(p + 0xC) != 0) {
        f = func_0038CF00(pos, D_001A4C60);
        if (6.1f < f) {
            m = *(u8 **)(D_001A4C60 + 0x2DC);
            if (m == 0 || *(s16 *)(m + 0xAA) != 0xD54) {
                *(s16 *)(p + 0xC) = 0;
            } else if (m[0x20] == 0xFE || m[0x20] == 0xFD) {
                *(s16 *)(p + 0xC) = 0;
            }
        }
    } else if (D_001D545C != 1 && func_L01_00511A98() == 0) {
        n = *(s32 *)(g + 0x25C4);
        if (n != 0x74 && n != 0x31) {
            f = func_0038CF38(pos, g + 0x80);
            m = *(u8 **)(g + 0x35C);
            if (f < 8.0f || valid_4AC1C0(m)) {
                f = func_0038CF00(pos, g + 0x80);
                if (f < 6.0f || valid_4AC1C0(*(u8 **)(g + 0x35C))) {
                    *(s16 *)(p + 0xC) = 1;
                }
            }
        }
    }
    if (*(u16 *)(self + 0x34) & 1) {
        *(s16 *)(p + 0xC) = 0;
    } else if (*(s32 *)(g + 0x25C4) == 0x31) {
        *(s16 *)(p + 0xC) = 0;
    }
    if (*(s16 *)(p + 0xC) == 0) {
        return;
    }
    if (func_L01_004BA800() != 0) {
        return;
    }
    flag = 0;
    if (D_001D5533 != 0) {
        flag = (u32)func_L01_00452560(0, 2, 0x855, 1, 0, 0, 0) != 0;
    }
    if (func_L01_00456250(self) == 0) {
        if (!(*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) {
            return;
        }
        if (flag == 0) {
            return;
        }
    }
    func_L01_00456230(self, 0);
    if (D_001D673C == 0) {
        w.x = 1.48f;
        w.y = 2.66f;
        w.z = 0.0f;
        w.w = 0.0f;
        func_0038D000(&v, &w, D_0016C650);
        v.x = v.x + *(f32 *)(self + 0x10);
        v.y = v.y + *(f32 *)(self + 0x14);
        v.z = v.z + *(f32 *)(self + 0x18);
        v.z = func_003C3D30(&v, 0, 0, 0.5f);
        *(vu0_v4 *)(D_0016C650 - 0x60) = v;
        *(vu0_v4 *)(D_0016C650 - 0x50) = *(vu0_v4 *)(self + 0xF0);
    } else {
        func_003C48A8(D_0016C650, self + 0xF0);
    }
    func_L01_00452658(0, 2);
    D_L01_001DFC28 = 1;
    D_0016C5A6 = 0;
}
