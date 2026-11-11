#include "common.h"

typedef struct List_003AE1B0 {
    u8 pad0[0x44];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u32 *entries[1];
} List_003AE1B0;

/* localdecomp:start func_L11_003AE1B0 */
extern s32 D_L11_001D6694;
extern u8 D_001D5471;
extern List_003AE1B0 D_L11_001E5AC0;
extern u8 D_L11_001E02A0;
extern u8 D_L11_001E02A1;
extern f32 D_L11_001E02C0;
extern f32 D_L11_001E02C4;
extern f32 D_L11_001E02C8;
extern void func_L01_0043A430(u32 *, s32, u8 *);

void func_L11_003AE1B0(u8 *arg) {
    u32 *elem;
    s32 i;

    if (D_L11_001D6694 == 2) {
        if (D_001D5471 != 0) {
            for (i = 0; i < D_L11_001E5AC0.count; i++) {
                elem = D_L11_001E5AC0.entries[i];
                if (*(s16 *)((u8 *)elem + 0xAA) == *(s16 *)(arg + 0xAA)) {
                    if (D_L11_001E02A1 == 0) {
                        func_L01_0043A430(elem, 0, &D_L11_001E02A0);
                        D_L11_001E02C0 = 2.75f;
                        D_L11_001E02C4 = 2.75f;
                        D_L11_001E02C8 = 2.75f;
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L11_003AE1B0 */

INCLUDE_ASM("asm/levels", func_L11_003AE290);

/* localdecomp:start func_L11_003AE938 */
typedef int q_3AE938 __attribute__((mode(TI)));
__asm__(".extern D_L11_001DE138, 4");
__asm__(".extern D_L11_001DE13C, 4");
__asm__(".extern D_L11_001DE140, 4");
__asm__(".extern D_L11_001DE144, 4");
__asm__(".extern D_L11_001DE148, 4");
__asm__(".extern D_L11_001DE14C, 4");
__asm__(".extern D_L11_001DE150, 4");
extern s32 D_L11_001DE138;
extern s32 D_L11_001DE13C;
extern f32 D_L11_001DE140;
extern f32 D_L11_001DE144;
extern f32 D_L11_001DE148;
extern f32 D_L11_001DE14C;
extern f32 D_L11_001DE150;
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, f32, s32, s32);

void func_L11_003AE938(u8 *a0)
{
    q_3AE938 m[4];
    q_3AE938 p;
    u8 *v;
    f32 t;

    p = *(q_3AE938 *)(a0 + 0x10);
    m[0] = *(q_3AE938 *)(a0 + 0xC0);
    m[1] = *(q_3AE938 *)(a0 + 0xD0);
    m[2] = *(q_3AE938 *)(a0 + 0xE0);
    m[3] = p;
    v = *(u8 **)(a0 + 0x68);
    func_0038CE20(&m[0], &m[0], D_L11_001DE140);
    func_0038CE20(&m[1], &m[1], D_L11_001DE144);
    func_0038CE20(&m[2], &m[2], D_L11_001DE148);
    t = D_L11_001DE14C + D_L11_001DE150 * 1.2f;
    D_L11_001DE14C = t;
    if (1.0f < t) {
        D_L11_001DE14C = t - 1.0f;
    }
    func_003D9740(m, D_L11_001DE138, (*(s32 *)(v + 0xC) << 24) | 0x20AF20, D_L11_001DE14C, D_L11_001DE13C, 1);
}
/* localdecomp:end func_L11_003AE938 */

/* localdecomp:start func_L11_003AEA18 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3AEA18;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001A30B0[];
extern u8 D_001426E0[];
extern u8 *D_L11_001DEE1C;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern s32 func_L01_00456250(void *);
extern void func_0039EF28(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_004048D0(void (*)(u8 *), void *);
extern void func_L11_003AE938(u8 *);

void func_L11_003AEA18(u8 *a0)
{
    s32 *v = *(s32 **)(a0 + 0x68);
    V4_3AEA18 m[4];
    s32 idx;
    u8 *e;

    if (a0[0x20] == 0) {
        *(u16 *)(a0 + 0x34) |= 0x141;
        func_003C5180(a0 + 0x10, m, 0);
        func_L01_004515D8(a0 + 0xC0, &m[0], &m[1]);
        a0[0x20] = 1;
        if (D_001BBC40[a0[0xB0] + D_001D545C * 16] & 0x80) {
            goto kill;
        }
        if (v[2] == -1) {
            goto spawn;
        }
        e = D_001A30B0 + (v[2] << 7);
        if (*(u8 **)(e + 0xDC) != a0 || e[0xD0] == 0) {
spawn:
            v[2] = func_003A52A0(0, 4, a0);
        }
        v[3] = 0xFF;
    }
    if (a0[0x20] == 1) {
        if (func_L01_00456250(D_L11_001DEE1C + (v[1] << 8)) != 0) {
            idx = v[2];
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            v[2] = -1;
            func_003A52A0(1, 0, a0);
            if (D_001426E0[0x21] == 0) {
                D_001426E0[0x21] = 1;
                func_0039EF28(a0);
            }
            func_L01_004450F0(a0, 2, -1);
        }
    }
    if (a0[0x20] == 2) {
        v[3] -= 2;
        if (v[3] < 0) {
kill:
            func_003C2880(a0);
            return;
        }
    }
    func_L01_004048D0(func_L11_003AE938, a0);
}
/* localdecomp:end func_L11_003AEA18 */

INCLUDE_ASM("asm/levels", func_L11_003AEBE8);

INCLUDE_ASM("asm/levels", func_L11_003AEDE8);

INCLUDE_ASM("asm/levels", func_L11_003AF058);

INCLUDE_ASM("asm/levels", func_L11_003AF6B8);

INCLUDE_ASM("asm/levels", func_L11_003AFD48);

INCLUDE_ASM("asm/levels", func_L11_003AFF60);
