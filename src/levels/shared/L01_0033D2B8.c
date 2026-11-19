#include "common.h"

/* localdecomp:start func_L01_0033D2B8 */
extern f32 D_L01_001DCFD8;
extern f32 func_00382538(void);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D750(u8 *, s32, f32);
extern void func_L01_0043A430(u8 *, s32, u8 *);

void func_L01_0033D2B8(u8 *a) {
    u8 *s = *(u8 **)(a + 0x68);
    f32 f;

    switch (a[0x20]) {
    case 0:
        a[0x20] = 1;
        a[0x63] = 0x20;
        *(f32 *)(s + 0x40) = func_00382538();
        func_L01_0043A430(a, 1, s);
        break;
    case 1:
        f = D_L01_001DCFD8 * 0.01745329238474369f * 0.020000001415610313f;
        *(f32 *)(a + 0xF8) = func_0038DAB8(*(f32 *)(a + 0xF8), f);
        *(f32 *)(s + 0x40) = func_0038DAB8(*(f32 *)(s + 0x40), f * -2.0f);
        func_0038D750(s + 0x10, 2, *(f32 *)(s + 0x40));
        break;
    }
}
/* localdecomp:end func_L01_0033D2B8 */

/* localdecomp:start func_L01_0033D390 */
void func_L01_0033D390(void) {

}
/* localdecomp:end func_L01_0033D390 */

INCLUDE_ASM("asm/levels", func_L01_0033D398);

/* localdecomp:start func_L01_0033D780 */
extern f32 D_L01_001DD010;
__asm__(".extern D_L01_001DD010, 4");
extern u8 D_L01_001E18B0;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L01_0033DED0(void *);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_0033D780(void *a0) {
    f32 t;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    s32 c0;
    s32 c1;
    s32 c2;

    D_L01_001DD010 = func_0038DAB8(D_L01_001DD010, 0.15f);
    t = func_0038D098(D_L01_001DD010);
    f20 = (t + 1.0f) * 0.5f;
    f23 = f20 * 0.0625f + 0.0625f;
    f22 = f20 * 0.19999999f + 0.15f;
    f21 = f20 * 0.125f + 0.125f;
    c0 = func_0038DBD8(f20, 0x2F007F00, 0x3F007F00);
    c1 = func_0038DBD8(f20, 0x2F7F7F7F, 0x5F7F7F7F);
    c2 = func_0038DBD8(f20, 0x10003F00, 0x10003F00);
    func_L01_0033DED0(a0);
    func_003D9508(&D_L01_001E18B0, 0x31, c0, 1, f21, 0.125f, 0.0f);
    func_003D9508(&D_L01_001E18B0, 0x31, c1, 1, f23, 0.124f, 0.0f);
    func_003D9508(&D_L01_001E18B0, 0xB, c2, 1, f22, 0.123f, 0.0f);
}
/* localdecomp:end func_L01_0033D780 */

INCLUDE_ASM("asm/levels", func_L01_0033D940);

INCLUDE_ASM("asm/levels", func_L01_0033DBE8);

/* localdecomp:start func_L01_0033DED0 */
typedef struct {
    u8 pad0[0x30];
    u8 obj[0x5C];
    void *key;
    u8 pad8[4];
    s32 flag;
    u8 pad9[8];
} Ent_0033DED0;

extern Ent_0033DED0 D_L01_00278BC0[];
extern void func_L01_0033E0C8(void *a, Ent_0033DED0 *b);
extern void func_003D9508(void *o, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14);
extern f32 func_003824E0(f32 a, f32 b);

void func_L01_0033DED0(void *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        Ent_0033DED0 *e = &D_L01_00278BC0[i];

        if (e->key == arg0) {
            func_L01_0033E0C8(arg0, e);
            if (e->flag == 0) {
                func_003D9508(e->obj, 0x31, 0x3F007F00, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, 0.0f);
                func_003D9508(e->obj, 0x31, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, 0.0f);
                func_003D9508(e->obj, 0xB, 0x10003F00, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
            }
        }
    }
}
/* localdecomp:end func_L01_0033DED0 */
