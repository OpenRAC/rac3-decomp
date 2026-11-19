/* PAL port of the NTSC-U draft (round 8): PAL port of the NTSC-U draft (round 8; the file needs #include "vu0.h" before the block, and D_L11_ names with the _0033CFB0 suffix because the next block declares D_L11_001DCFDC as s32): 14 differences with the file's flags (already -mvu0-use-vf0-vf2 and @ps2as). All of it matches except the init loop (4 iterations, two func_003824E0 calls): retail evaluates the second (lui/lwc1 f13) argument first, and the `lwc1 $f12,gp` load of the first sits in the jal delay slot after `lwc1 $f13`; gcc loads $f12 first. Temps for the two arguments in both orders, unsized-array element reads, and swapping the two statements (19) did not change it. Data PAL addresses used: sda slots D_001DCFA8/B0/B8/C0_sda, D_L11_001DCFAC/B4/BC, D_L11_001DBBA8, D_L11_0033D510 */
#include "common.h"
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L11_0033CFB0 */
typedef struct {
    f32 f00;
    f32 f04;
    u8 pad08[8];
    f32 f10[4];
    f32 f20[4];
    f32 f30[4];
} Priv_33CFB0;

extern u8 D_L11_001E84E0_0033CFB0[];
extern f32 D_L11_001DCFAC_0033CFB0;
extern f32 D_L11_001DCFB4_0033CFB0;
extern f32 D_L11_001DBBA8_0033CFB0;
extern s32 D_L11_001DCFBC_0033CFB0;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 D_001DCFA8_sda;
__asm__(".extern D_001DCFA8_sda, 4");
extern f32 D_001DCFB0_sda;
__asm__(".extern D_001DCFB0_sda, 4");
extern s32 D_001DCFB8_sda;
__asm__(".extern D_001DCFB8_sda, 4");
extern f32 D_001DCFC0_sda;
__asm__(".extern D_001DCFC0_sda, 4");
extern u8 D_001A4C60[];
extern u8 D_001A4EC0[];
extern u8 D_L11_0033D510_0033CFB0[];
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L11_0033D310(void *);
extern void func_L01_00404808(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L11_0033CFB0(u8 *obj)
{
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 u20;
    vu0_v4 u30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 u80;
    vu0_v4 u90;
    Priv_33CFB0 *p;
    s32 i;
    f32 c;
    f32 t;
    u8 *hero;
    u8 state;

    state = obj[0x20];
    p = *(Priv_33CFB0 **)(obj + 0x68);
    switch (state) {
    case 0:
        *(u16 *)(obj + 0x34) |= 0x100;
        func_003C5180(obj + 0x10, &v0, 0);
        func_L01_004515D8(obj + 0xC0, &v0, &v1);
        func_0038CF68(&v40, obj + 0xE0, 0.5f);
        func_0038CF68(&v50, obj + 0xE0, -4.0f);
        vec_add_ba(&v40, &v40, obj + 0x10);
        vec_add_ba(&v50, &v50, obj + 0x10);
        if (func_003D3CB0(&v40, &v50, 2, obj, 0) != 0) {
            *(vu0_q *)(obj + 0x10) = *(vu0_q *)D_L11_001E84E0_0033CFB0;
            func_0038CF68(&v50, obj + 0xE0, -0.1f);
            vec_add_ba(obj + 0x10, &v50, obj + 0x10);
            func_003C5180(obj + 0x10, &v60, 0);
            func_L01_004515D8(obj + 0xC0, &v60, &v70);
        }
        func_L01_004450F0(obj, 1, -1);
        *(s16 *)(obj + 0x32) = 0xFF;
        for (i = 0; i < 4; i++) {
            p->f20[i] = (f32)i * 0.25f;
            p->f30[i] = func_003824E0(D_001DCFA8_sda, D_L11_001DCFAC_0033CFB0) * 0.020000001f;
            p->f10[i] = func_003824E0(D_001DCFB0_sda, D_L11_001DCFB4_0033CFB0);
        }
        break;
    case 1:
        if (D_001D545C_sda == 0xB) {
            func_003C5180(obj + 0x10, &v0, 0);
            func_L01_004515D8(obj + 0xC0, &v0, &v1);
        }
        t = func_0038CF00(D_001A4C60, obj + 0x10);
        if (t < 3.0f) {
            D_L11_001DBBA8_0033CFB0 = p->f00;
        }
        hero = D_001A4C60 - 0x80;
        if (*(s32 *)(hero + 0x25C4) == 0x86) {
            if (*(s32 *)(hero + 0x1B8) == state) {
                func_003A52A0(0, 0, obj);
            }
        }
        if (func_0038CE68(obj + 0xE0, D_001A4EC0) < -0.6f) {
            func_L11_0033D310(obj);
            func_L01_00404808(D_L11_0033D510_0033CFB0, obj);
        }
        break;
    }
    if (obj[0x31] != 0) {
        c = func_0038DAB8(p->f04, D_001DCFC0_sda * 0.017453292f * 0.020000001f);
        p->f04 = c;
        c = func_0038D0B0(c);
        c = c * c;
        c = c * c;
        *(s32 *)(obj + 0x78) = func_0038DBD8(D_001DCFB8_sda, D_L11_001DCFBC_0033CFB0, c * c);
    }
}
/* localdecomp:end func_L11_0033CFB0 */
