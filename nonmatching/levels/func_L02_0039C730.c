/* func_L02_0039C730 (Claude wave 14 r74, 2026-11-28). First draft kept here. */
/* r74 wave 14 (2026-11-28), first draft (fresh entry), from the functional C. 167 diff / 52 aligned rows at level 02 under
 * the file's line (377 retail instructions, 375 here). Forms that retail's code fixes: a switch on self[0x20] (beqz to case 0,
 * beq to case 1, b to the end), one function-scope collision struct whose first two vectors are case 1's velocity and
 * end point (stack 0x20/0x30, retail reuses them), dir at 0x50 and the second struct at 0x60, one counter i for both the
 * collision result of case 0 and the 45-pass loop (s0), the loop as next = i + 1 / i = next, a pointer local for the
 * first func_003C4C18 of each pass (retail keeps it in the 0x90 stack slot), D_L02_001D66B0 in .sdata (one la per call),
 * D_L02_0021E27C and D_L02_001E8058 as arrays (not $gp), 0.010000001f, the .w stores in vel-then-end order.
 * Left: st and self+0x10 in s4/s3 (retail s3/s4), the case-0 scale choice (retail threads g == 0 straight to the 3.0f
 * arm; here g is tested again), the three float temporaries of each pass in f21/f22/f20 (retail f22/f20/f21, with
 * mov.s + in-place mul.s for the 1..8 random value). */
#include "common.h"

/* localdecomp:start func_L02_0039C730 */
#include "vu0.h"
typedef int u128_0039C730 __attribute__((mode(TI)));
typedef struct { vu0_v4 a; vu0_v4 b; vu0_v4 c; } Hit_0039C730;
extern u8 D_L02_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L02_0021E27C[];
extern u8 *D_L02_001E8058[];
void func_L02_0039C730(u8 *self) {
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
    extern void func_L01_004CB320(void);
    extern void func_L01_004CB358(void);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_003D4D00(void *, s32, void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C2880(void *);
    extern void func_003C4C18(void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
    u8 *st = *(u8 **)(self + 0x68);
    vu0_v4 pos;
    Hit_0039C730 hit;
    vu0_v4 dir;
    Hit_0039C730 info;
    u8 *r;
    vu0_v4 *pp;
    u8 *g;
    s32 i, j, next;
    f32 a, b, c;
    s32 m1, m2;

    *(s32 *)(st + 0x24) += 1;
    if (*(s32 *)(st + 0x24) > 0xF0) {
        func_L01_00446780(self, self + 0x10, 0x10001, 0.6f, *(f32 *)(st + 0x14), 0.0f, 0, 1, 0);
        func_L01_004450F0(self, 1, -1);
    }
    switch (self[0x20]) {
    case 0:
        r = func_L01_0046A610(self + 0x10, D_L02_001D66B0, 5, 0x4F, 0xFF90, (s32)func_00382538(), 472500.0f, -1000.0f, 0.95f, 0.0f, 0.0f);
        if (r != 0) {
            r[2] = *D_L02_0021E27C[0];
        }
        r = func_L01_0046A610(self + 0x10, D_L02_001D66B0, 5, 0x4F, 0x10A182, (s32)func_00382538(), 168000.0f, -1000.0f, 0.95f, 0.0f, 0.0f);
        if (r != 0) {
            r[2] = *D_L02_0021E27C[0];
        }
        vec_add_ba(&pos, self + 0x10, st);
        func_L01_00446760(&hit, self, 1, st, *(f32 *)(st + 0x14));
        *(u16 *)((u8 *)&hit + 0x1A) = *(u16 *)(self + 0xAA);
        func_L01_004CB320();
        i = func_003D3CB0(self + 0x10, &pos, 0, self, &hit);
        if (i != 0) {
            g = D_L02_001E8058[0];
            if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
                g[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (i != 0) {
            g = D_L02_001E8058[0];
            if (g == 0 || g != *(u8 **)(st + 0x10)) {
                f32 scale = g == 0 ? 3.0f : 1.5f;
                *(u128_0039C730 *)&dir = *(u128_0039C730 *)st;
                func_0038CE20(&dir, &dir, scale);
                dir.z = 1.0f;
                dir.w = 5627.925f;
                func_L01_00446760(&info, self, 0x10001, &dir, *(f32 *)(st + 0x14));
                *((u8 *)&info + 0x19) = 1;
                *(u16 *)((u8 *)&info + 0x1A) = *(u16 *)(self + 0xAA);
                *((u8 *)&info + 0x18) = 0;
                func_003D4D00(self + 0x10, 0, *(u8 **)(st + 0x10), &info, 0.6f);
                func_L01_004450F0(self, 1, -1);
                return;
            }
        }
        *(u128_0039C730 *)(self + 0x10) = *(u128_0039C730 *)&pos;
        func_0038CE20(&dir, st, -0.5f);
        break;
    case 1:
        pp = &pos;
        i = 0;
        do {
            next = i + 1;
            pos = *(vu0_v4 *)(self + 0x10);
            func_003C4C18(pp, 0.25f);
            pos.z += 0.25f;
            a = func_00382538();
            b = func_003824E0(1.0f, 8.0f);
            b *= 0.020000001f;
            c = func_003824E0(2.0f, 6.0f);
            func_0038CE20(&hit.a, st, func_003824E0(0.0f, 0.0f) * 0.020000001f);
            hit.a.x += func_0038D098(a) * b;
            hit.a.y += func_0038D0B0(a) * b;
            hit.a.z += c * 0.020000001f;
            *(u128_0039C730 *)&hit.b = *(u128_0039C730 *)&hit.a;
            hit.b.z -= 0.2f;
            for (j = 14; j >= 0; j--) {
                f32 s = func_003824E0(0.5f, 1.5f);
                hit.a.w = s * 0.125f;
                hit.b.w = s * 0.065f;
                func_003C4C18(&pos, 0.125f);
                func_003C4C18(&hit.b, 0.010000001f);
                m1 = func_0038DBD8(0x8000EEEE, 0x8000FF90, func_003824E0(0.0f, 1.0f));
                m2 = func_0038DBD8(0xFFEE, 0xFFEE, func_003824E0(0.0f, 1.0f));
                func_L01_00463378(&pos, &hit.a, &hit.b, m1, m2, 8, 0x19, (s32)((func_003824E0(5.0f, 25.0f) * 5.0f + 2.0f) / 6.0f), -1);
            }
            i = next;
        } while (i < 45);
        func_003C2880(self);
        break;
    }
}
/* localdecomp:end func_L02_0039C730 */
