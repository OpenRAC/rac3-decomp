/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00469EF8, the NTSC-U twin of func_L01_0046D5A8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0046A938.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0046D5A8 (src/levels/shared/L01_0046A938.c) */
/* localdecomp:start func_L01_00469EF8 */
typedef int u128_t_469EF8 __attribute__((mode(TI)));
typedef struct {
    f32 f0, f4, f8;
    u8 *tgt;
    f32 f10, f14;
    s16 h18, h1A, h1C;
} St_469EF8;
extern s32 func_L01_00442D70(void *, s32);
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L01_00469D90(void *, void *, s32, f32, f32, s32, s32, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388BF0(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern void func_003888C8(void *, void *, void *);
extern f32 func_00389380(f32, f32);

void func_L01_00469EF8(u8 *obj) {
    St_469EF8 *st;
    u8 *r;
    vu0_v4 A;
    vu0_v4 B;
    vu0_v4 C;
    f32 M[16] __attribute__((aligned(16)));

    st = (St_469EF8 *)(obj + 0x20);
    if (st->h1C == 0) {
        if (func_L01_00442D70(obj + 4, st->h1A) != 0) {
            func_003C7CE0(obj);
            return;
        }
        if (st->tgt == 0) {
            return;
        }
        A.x = st->f0;
        A.y = st->f4;
        A.z = st->f8;
        func_003886E8(&A, &A, (f32)st->h18);
        vec_add_ba(obj + 0x10, st->tgt + 0x10, &A);
        return;
    }
    if (func_003883C8(obj + 0xA) != 0 || (*(s16 *)(obj + 0xA) < 10 && func_L01_00442D70(obj + 4, 0x10) != 0)) {
        func_003C7CE0(obj);
        return;
    }
    if (st->h1C == 1) {
        func_L01_00469D90(0, obj + 0x10, 0xA, 0.0f, 0.0f, 0, *(s8 *)(obj + 7), 0);
    } else {
        A.x = st->f0;
        A.y = st->f4;
        A.z = st->f8;
        r = func_L01_00469D90(st->tgt, obj + 0x10, 0xA, 0.0f, 0.0f, 0, *(s8 *)(obj + 7), &A);
        if (r != 0) {
            *(u16 *)(r + 0x38) = st->h18;
        }
    }
    if (st->h1C == 1) {
        *(u128_t_469EF8 *)(obj + 0x10) = *(u128_t_469EF8 *)(st->tgt + 0x10);
        A.x = func_00388960(st->f10) * 2.25f;
        A.y = func_00388978(st->f10) * 2.25f;
        A.z = A.x;
        A.x = 0.0f;
        B.x = func_00388960(st->f14) * 0.28f;
        B.y = func_00388978(st->f14) * 0.28f;
        B.z = B.x;
        B.x = 0.0f;
        qzero(&C);
        C.y = st->f10;
        func_00388BF0(M, &C);
        func_003888F0(&B, &B, M);
        vec_add_ba(&A, &A, &B);
        func_003888C8(&A, &A, st->tgt + 0xC0);
        vec_add_ba(obj + 0x10, obj + 0x10, &A);
        st->f10 = func_00389380(st->f10, 0.015998852f);
        st->f14 = func_00389380(st->f14, 0.072722055f);
    }
}
/* localdecomp:end func_L01_00469EF8 */
