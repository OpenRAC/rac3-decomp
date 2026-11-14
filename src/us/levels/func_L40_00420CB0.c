#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_00420CB0 */
typedef struct {
    f32 x, y, z;
} V_00420CB0;

typedef struct {
    u8 pad[0x88];
    s32 a[1];
} S_00420CB0;

extern s32 D_001A5F78[];
extern s32 D_L40_002412AC;
extern s32 *D_L40_0028FF00[];
extern void *D_L40_003575EC[];
extern f32 D_001DBFE0_sda;
extern f32 D_001DBFE4_sda;
extern f32 D_001DBFE8_sda;
__asm__(".extern D_001DBFE0_sda, 4");
__asm__(".extern D_001DBFE4_sda, 4");
__asm__(".extern D_001DBFE8_sda, 4");

extern s32 func_L40_004202B0(void *);
extern f32 func_00388800(void *, void *);
extern s32 func_L39_005B2498(s32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_L40_0053B8F8(void *, s32, s32, s32, f32, f32, f32);
extern u8 *func_L40_0053BEB0(s32, void *, s32, s32);
extern s32 func_L40_003F4050(void *, void *);
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, void *, s32, void *, void *);
extern s32 func_L39_006698E8(s32);

void func_L40_00420CB0(u8 *a0) {
    u8 *v;
    s32 uid;
    s32 *tbl;
    s32 target;
    u8 *p;
    u8 *q;
    f32 r1;
    f32 ang;
    V_00420CB0 out;

    v = *(u8 **)(a0 + 0x68);
    uid = **(s32 **)(a0 + 0x90);
    switch (*(s32 *)(v + 0x2A4)) {
    case 0:
        *(s32 *)(v + 0x2A4) = 1;
        break;
    case 1:
        target = -1;
        *(s32 *)(v + 0x45C) = func_L40_004202B0(a0);
        if (*(s32 *)(v + 0x454) != -1) {
            tbl = D_L40_0028FF00[*(s32 *)(v + 0x454)];
            if ((D_L40_002412AC & 0x3F) == (((s32)a0 >> 8) & 0x3F)) {
                if (func_00388800(a0 + 0x10, (u8 *)tbl + ((*(s32 *)(v + 0x2C4) << 4) + 0x10)) < 1.0f) {
                    if (func_L39_005B2498(1) == 0) {
                        if (*(s32 *)(v + 0x340) == 0) {
                            *(s32 *)(v + 0x340) = 1;
                        }
                        *(s32 *)(v + 0x2C4) += *(s32 *)(v + 0x340);
                        if (*(s32 *)(v + 0x2C4) < 0) {
                            *(s32 *)(v + 0x2C4) = 1;
                            *(s32 *)(v + 0x340) = 1;
                        } else if (*(s32 *)(v + 0x2C4) >= *tbl) {
                            *(s32 *)(v + 0x340) = -1;
                            *(s32 *)(v + 0x2C4) -= 2;
                        }
                        p = func_L39_006699B0();
                        if (p == 0) {
                            return;
                        }
                        q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)1, p);
                        *(s32 *)q = *(s32 *)(v + 0x2C4);
                        q += 4;
                        *(s32 *)p = q - p;
                    }
                }
            }
        }
        if (*(s32 *)(v + 0x45C) != -1) {
            target = func_L40_0053B8F8(a0, ((S_00420CB0 *)D_L40_003575EC[0])->a[*(s32 *)(v + 0x290)], 0, 0,
                                       *(f32 *)(v + 0x2B8), -1.0f, 10.0f);
        }
        if (target == -1) {
            return;
        }
        if (func_L40_0053BEB0(target, &out, -1, 0) == 0) {
            return;
        }
        *(s32 *)(v + 0x29C) = -1;
        *(s32 *)(v + 0x2E8) = 0;
        r1 = func_L39_005B2510(3.5f, 5.0f);
        ang = func_00389380(*(f32 *)(a0 + 0xF8), func_L39_005B2510(D_001DBFE4_sda, D_001DBFE8_sda) * 0.017453292f);
        *(f32 *)(v + 0x2E0) = func_00388960(ang) * r1;
        *(f32 *)(v + 0x2E4) = func_00388978(ang) * r1;
        *(s32 *)(v + 0x2E8) = 0;
        func_00388830(v + 0x2E0, v + 0x2E0, r1);
        vec_add_ba(v + 0x2E0, v + 0x2E0, a0 + 0x10);
        *(f32 *)(v + 0x2E8) = *(f32 *)(v + 0x2E8) + D_001DBFE0_sda;
        *(f32 *)(v + 0x2E8) = func_003BE7F0(v + 0x2E0, 0, 0, 0.5f);
        *(s32 *)(v + 0x2A8) = 0;
        *(s32 *)(v + 0x2A4) = 2;
        p = func_L39_006699B0();
        if (p == 0) {
            return;
        }
        q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, 0, p);
        *(V_00420CB0 *)q = *(V_00420CB0 *)(v + 0x2E0);
        q += 12;
        *(s32 *)p = q - p;
        break;
    case 2:
        if (++*(s32 *)(v + 0x2A8) >= 0x33) {
            if (*(s32 *)(v + 0x29C) == -1) {
                *(s32 *)(v + 0x29C) = func_L40_003F4050((void *)(*(s32 *)(v + (*(s32 *)(v + 0x45C) << 2) + 0x310)), v + 0x2E0);
            }
        }
        if (*(s32 *)(v + 0x2A8) > *(s32 *)(v + 0x44C)) {
            *(s32 *)(v + 0x2A4) = 1;
            *(s32 *)(v + (*(s32 *)(v + 0x45C) << 2) + 0x328) = func_L39_006698E8(*(s32 *)(v + 0x29C));
        }
        break;
    }
}
/* localdecomp:end func_L40_00420CB0 */
