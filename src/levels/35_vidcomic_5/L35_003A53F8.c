#include "common.h"

/* localdecomp:start func_L35_003A53F8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A53F8;
typedef struct {
    u8 pad00[0x18];
    u8 *f18;
} G_003A53F8;
typedef struct {
    u8 pad00[0xF0];
    f32 fF0;
    f32 fF4;
} O_003A53F8;
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L35_003BC828(void *, V_003A53F8 *, s32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L30_0034CC28(void *, void *, void *, s32, s32, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L30_0034CB68(void *, void *, s32, s32, void *, s32, f32, f32);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L35_003A53C0(s32);
extern u8 D_001A30B0[];
extern u8 D_001A4BE0[];
extern u8 D_L35_001D66B0[] __attribute__((section(".sdata")));
extern G_003A53F8 D_L35_001E92C0;
extern u8 D_L35_001E92E0[];
__asm__(".extern D_L35_001DEA78, 4");
extern f32 D_L35_001DEA78;
__asm__(".extern D_L35_001DEA7C, 4");
extern f32 D_L35_001DEA7C;
__asm__(".extern D_L35_001DEA80_003A53F8, 4");
extern f32 D_L35_001DEA80_003A53F8;
__asm__(".extern D_L35_001DEA88, 4");
extern f32 D_L35_001DEA88;
__asm__(".extern D_L35_001DEA8C_003A53F8, 4");
extern f32 D_L35_001DEA8C_003A53F8;
__asm__(".extern D_L35_001DEA90, 4");
extern f32 D_L35_001DEA90;
__asm__(".extern D_L35_001DEA94, 4");
extern f32 D_L35_001DEA94;

void func_L35_003A53F8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 state = a0[0x20];
    s32 ok;
    u8 *t;
    V_003A53F8 tmp;
    u8 buf[0x30];

    if (state != 0) {
        if (state == 1) {
            if (*(s32 *)(s + 0x28) != -1) {
                t = D_001A30B0 + *(s32 *)(s + 0x28) * 0x80;
                if (*(void **)(t + 0xDC) == a0 && t[0xD0] != 0) {
                    func_003A4F28(*(s32 *)(s + 0x28));
                }
            }
            *(s32 *)(s + 0x28) = -1;
            func_003A52A0(1, 0, a0);
            func_003C2880(a0);
        }
    } else {
        ((O_003A53F8 *)a0)->fF4 = -*(f32 *)(s + 0x20);
        ((O_003A53F8 *)a0)->fF0 = func_0038DAB8(((O_003A53F8 *)a0)->fF0, D_L35_001DEA90);
        if (func_0038CEA8(s + 0x10) < D_L35_001DEA94) {
            vec_add_ab(s + 0x10, s + 0x10, s);
        }
        vec_add_ab(a0 + 0x10, a0 + 0x10, s + 0x10);
        ok = func_L01_003FB640(a0 + 0x10, 0, 0, D_L35_001DEA80_003A53F8) != 0;
        if (*(s32 *)(s + 0x28) == -1
            || (t = D_001A30B0 + (*(s32 *)(s + 0x28) << 7), *(void **)(t + 0xDC) != a0) || t[0xD0] == 0) {
            *(s32 *)(s + 0x28) = func_003A52A0(0, 4, a0);
        }
        func_L35_003A53C0((s32)a0);
        if (ok && D_L35_001E92C0.f18 == 0 && 0.0f < *(f32 *)(s + 0x18)) {
            qzero(&tmp);
            tmp.z += D_L35_001DEA88;
            func_L35_003BC828(a0 + 0x10, &tmp, 1, 1.0f, D_L35_001DEA8C_003A53F8);
            func_L01_004450F0(a0, 1, -1);
            return;
        }
        if (ok) {
            u8 *m = D_L35_001E92C0.f18;
            if (m != 0) {
                if (*(s16 *)(m + 0xAA) == 0x19FB || *(s16 *)(m + 0xAA) == 0x19EC) {
                    goto far;
                }
                if (*(u16 *)(m + 0xAA) == 0x1D67 || *(u16 *)(m + 0xAA) == 0x1D68) {
                    func_L30_0034CC28(buf, a0, D_L35_001D66B0, 0, 0, D_L35_001DEA78);
                    func_L01_00446978(D_L35_001E92C0.f18, buf);
                }
            }
            func_L30_0034CB68(a0, s + 0x10, 1, -1, D_L35_001E92E0, 1, D_L35_001DEA7C, D_L35_001DEA80_003A53F8);
            func_L30_0034CB68(a0, s + 0x10, 0, -1, D_L35_001E92E0, 0, D_L35_001DEA78, D_L35_001DEA80_003A53F8);
            func_L04_00325460(a0 + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, D_L35_001DEA80_003A53F8, 20.0f, 1, 0, 0, 0);
            func_003C2880(a0);
        } else {
            u8 *h;

        far:
            h = D_001A4BE0;

            if (fabs_asm(*(f32 *)(a0 + 0x18) - *(f32 *)(h + 0x88)) > 64.0f
                || fabs_asm(*(f32 *)(a0 + 0x10) - *(f32 *)(h + 0x80)) > 64.0f) {
                func_003C2880(a0);
            }
        }
        if (func_0038CAD0(s + 0x24) != 0) {
            func_003C2880(a0);
        }
    }
}
/* localdecomp:end func_L35_003A53F8 */
