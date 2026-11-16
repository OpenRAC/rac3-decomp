/* NTSC-U draft (Claude wave C4): C of func_L18_00352128, the NTSC-U twin of func_L18_00352D30, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L18_00352128", whose code is not the PAL one).
 * Worker's note: flags: MATCH with '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (248/248 words, check_native.py MATCH, name_conflicts clean); the PAL file's flag line has no @ps2as (16 lui/ori/mtc1 float constants), so it cannot land as is. Levers: hero global ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L18_00352128 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u32 flag;
    u8 pad[0x1C];
} E_52128;
typedef struct {
    u8 p0[0x2260];
    f32 f2260;
    f32 f2264;
    u8 p2268[0x35C];
    s32 f25C4;
} H_52128;
extern H_52128 D_001A4BE0;
extern u8 *D_001D52FC_sda;
__asm__(".extern D_001D52FC_sda, 4");
extern u8 D_001439F4[];
extern E_52128 D_00143A70[];
extern void func_003BEBF8(void *, f32, f32);
extern void func_L18_00351EF0(void *);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_00389018(void *, s32, f32);
extern void func_L01_004455F0(void *, f32, f32, f32, void *, f32, s32);
extern void func_003BEA80(void *, void *);

void func_L18_00352128(u8 *o) {
    u8 *p;
    u8 *cam;
    f32 a;
    f32 b;
    f32 c;
    f32 x;
    f32 ax;
    f32 z1;
    f32 z2;
    f32 z3;
    f32 z4;
    f32 t3;
    f32 t4;
    f32 s;
    f32 t;
    s32 sel;

    p = *(u8 **)(o + 0x68);
    a = 0.0f;
    b = 0.0f;
    c = 0.0f;
    cam = D_001D52FC_sda;
    if (D_001A4BE0.f25C4 != 0x31) {
        func_003BEBF8(p + 0x390, 0.043633234f, 0.0024240685f);
    } else {
        x = D_001A4BE0.f2260;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            b = ax * -0.6f;
        } else if (x < 0.0f) {
            a = ax * -0.6f;
        }
        c = x * 0.3f;
        x = D_001A4BE0.f2264;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            z1 = ax * 0.5f;
            b += z1;
            a += z1;
        } else if (x < 0.0f) {
            z2 = ax * -0.6f;
            b += z2;
            a += z2;
        }
        sel = D_001439F4[0];
        s = 1.0f;
        if (D_00143A70[sel].flag != 0) s = -1.0f;
        if (sel == 0) s = 1.0f;
        x = *(f32 *)(cam + 0x100) * s;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            t3 = ax * -0.6f;
            z3 = ax * 0.5f;
            b += t3;
            a += z3;
        } else if (x < 0.0f) {
            t4 = ax * 0.5f;
            z4 = ax * -0.6f;
            b += t4;
            a += z4;
        }
        if (b > 0.5f) b = 0.5f;
        if (b < -0.6f) b = -0.6f;
        if (a > 0.5f) a = 0.5f;
        if (a < -0.6f) a = -0.6f;
        c += x * 0.3f;
        if (c > 0.3f) c = 0.3f;
        if (c < -0.3f) c = -0.3f;
        if (*(s32 *)(p + 0x3BC) == 0) {
            t = b;
            b = a;
            a = t;
        }
    }
    func_L18_00351EF0(o);
    *(f32 *)(p + 0x388) = func_003893C8(*(f32 *)(p + 0x388), *(f32 *)(p + 0x390));
    *(f32 *)(p + 0x38C) = func_00389380(*(f32 *)(p + 0x38C), *(f32 *)(p + 0x390));
    func_00389018(p + 0xA0, 2, *(f32 *)(p + 0x388));
    func_00389018(p + 0xE0, 2, *(f32 *)(p + 0x38C));
    func_003BEBF8(p + 0x394, b, 0.029088823f);
    func_003BEBF8(p + 0x39C, a, 0.029088823f);
    func_00389018(p + 0x120, 1, *(f32 *)(p + 0x394));
    func_00389018(p + 0x160, 1, *(f32 *)(p + 0x39C));
    t = func_00389380(*(f32 *)(p + 0x350), *(f32 *)(p + 0x2B4));
    func_L01_004455F0(p + 0x2C4, -t, 0.02f, 0.15f, p + 0x3A4, 0.029088823f, 0);
    func_L01_004455F0(p + 0x2C8, *(s32 *)(p + 0x3BC) != 0 ? -c : c, 0.008f, 0.2f, p + 0x3A8, 0.029088823f, 0);
    func_003BEA80(p + 0x1A0, p + 0x2C0);
    *(u128_t *)(p + 0x1E0) = *(u128_t *)(p + 0x1A0);
}
/* localdecomp:end func_L18_00352128 */
