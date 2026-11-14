#include "common.h"

/* NTSC-U counterpart of func_L40_003F3C60 (src/levels/shared/L40_003F2E88.c): 168 -> 201 */
typedef struct {
    u8 b[16];
} B_003F3C60;
typedef struct {
    u8 pad[0x88];
    s32 tbl[1];
} T_003F3C60;
#include "vu0.h"
extern s32 D_L40_002412AC;
extern f32 func_00388978(f32);

/* localdecomp:start func_L40_003F37A0 */
#include "vu0.h"


extern s32 D_001A5F78[];
extern s32 D_L40_002412AC;
extern T_003F3C60 *D_L40_003575EC __attribute__((section(".data")));
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, s32, s32, s32, u8 *);
extern f32 func_L39_005B25C8_003F37A0(void);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L40_0053B8F8(void *, s32, s32, s32, f32, f32, f32);
extern u8 *func_L40_0053BEB0(s32, void *, s32, s32);

void func_L40_003F37A0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 uid = **(s32 **)(m + 0x90);
    s32 st;
    u8 *p;
    u8 *q;
    s32 tg;
    vu0_v4 buf;

    if (*(s32 *)(v + 0x2A4) == 0) {
        *(s32 *)(v + 0x2A4) = 1;
    }
    st = *(s32 *)(v + 0x2A4);
    switch (st) {
    case 1: {
        if (++*(s32 *)(v + 0x2A8) >= 0xC9) {
            f32 zero = 0.0f;
            f32 ang;
            f32 r;
            *(s32 *)(v + 0x2A8) = 0;
            ang = func_L39_005B25C8_003F37A0();
            r = func_L39_005B2510(zero, 3.0f);
            buf.x = func_00388960(ang) * r;
            buf.y = func_00388978(ang) * r;
            buf.z = zero;
            vec_add_ab(v + 0x220, v + 0x1F0, &buf);
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            q = p + func_L39_00669978(1, uid, D_001A5F78[0] + 0x1F4, 0, p);
            *(B_003F3C60 *)q = *(B_003F3C60 *)(v + 0x220);
            q += 0x10;
            *(s32 *)p = q - p;
        }
        *(s32 *)(v + 0x2C0) = func_L40_0053B8F8(m, D_L40_003575EC->tbl[*(s32 *)(v + 0x2AC)], 0, 0, 28.0f, -1.0f, 3.0f);
        if (*(s32 *)(v + 0x2C0) == -1) {
            return;
        }
        p = func_L39_006699B0();
        if (p == 0) {
            return;
        }
        q = p + func_L39_00669978(1, uid, D_001A5F78[0] + 0x1F4, 1, p);
        *(s32 *)q = *(s32 *)(v + 0x2C0);
        q += 4;
        *(s32 *)p = q - p;
        *(s32 *)(v + 0x2A4) = 4;
        break;
    }
    case 4:
        if (func_L40_0053BEB0(*(s32 *)(v + 0x2C0), &buf, -1, 0) == 0 &&
            (D_L40_002412AC & 0x3F) == (((s32)m >> 8) & 0x3F)) {
            tg = func_L40_0053B8F8(m, D_L40_003575EC->tbl[*(s32 *)(v + 0x2AC)], 0, 0, 28.0f, -1.0f, 3.0f);
            *(s32 *)(v + 0x2C0) = tg;
            if (tg != -1) {
                p = func_L39_006699B0();
                if (p == 0) {
                    return;
                }
                q = p + func_L39_00669978(1, uid, D_001A5F78[0] + 0x1F4, 1, p);
                *(s32 *)q = *(s32 *)(v + 0x2C0);
                q += 4;
                *(s32 *)p = q - p;
                *(s32 *)(v + 0x2A4) = st;
            } else {
                p = func_L39_006699B0();
                if (p == 0) {
                    return;
                }
                *(s32 *)p = func_L39_00669978(1, uid, D_001A5F78[0] + 0x1F4, 2, p);
                *(s32 *)(v + 0x2A4) = 1;
            }
            return;
        }
        if (m[0x20] == 4 && func_L01_0044AF40(m, 14.0f) != 0) {
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            *(s32 *)p = func_L39_00669978(1, uid, D_001A5F78[0] + 0x1F4, 2, p);
            *(s32 *)(v + 0x2A4) = 10;
            return;
        }
        if (func_00388800(&buf, v + 0x1F0) > 35.0f) {
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            tg = func_L39_00669978(1, uid, D_001A5F78[0] + 0x1F4, 2, p);
            *(s32 *)(v + 0x2A4) = 10;
            *(s32 *)p = tg;
        }
        break;
    case 10:
        if (*(s32 *)(v + 0x2C4) >= 0xC9) {
            *(s32 *)(v + 0x2C4) = 0;
            *(s32 *)(v + 0x2A4) = 1;
        } else {
            *(s32 *)(v + 0x2C4) = *(s32 *)(v + 0x2C4) + 1;
        }
        break;
    }
}
/* localdecomp:end func_L40_003F37A0 */
