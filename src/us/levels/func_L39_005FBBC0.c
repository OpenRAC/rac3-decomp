#include "common.h"

/* NTSC-U counterpart of func_L39_005FE358 (src/levels/shared/L39_005FE2E0.c) */
/* localdecomp:start func_L39_005FBBC0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 v[4][4];
    s32 col[4];
    f32 q[8];
    long z70;
    long r78;
    long c80;
    long c88;
} S_005FE358;

extern s32 D_L39_002412A8;
__asm__(".extern D_L39_002412A8, 16");
extern s32 D_L39_002412AC;
__asm__(".extern D_L39_002412AC, 16");
extern s32 D_001D9928_sda_005FBBC0[2];
__asm__(".extern D_001D9928_sda_005FBBC0, 8");
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389410(f32);
extern void func_00388BF0(void *, void *);
extern void func_00388F08(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003CD830(void *, void *, s32);
extern long func_L39_00588720(s32);

void func_L39_005FBBC0(u8 *a0, u8 *a1, void *a2, s32 a3, f32 scale) {
    S_005FE358 s;
    u128_t m1[4];
    u128_t m2[4];
    f32 e1[4];
    f32 e2[4];
    s32 i;
    s32 j;
    u8 b;
    f32 len;
    f32 r;

    if (D_L39_002412A8 == 2) {
        return;
    }
    for (i = 0; i < 2; i++) {
        len = sqrt_asm(((f32 *)a1)[0] * ((f32 *)a1)[0] + ((f32 *)a1)[2] * ((f32 *)a1)[2]);
        e1[0] = func_00389380(-func_00388A28(len, ((f32 *)a1)[1]), 1.5707964f);
        e1[1] = func_00388A28(((f32 *)a1)[2], ((f32 *)a1)[0]);
        e1[2] = 0.0f;
        e1[3] = 0.0f;
        r = (f32)(D_L39_002412AC % 180) * 6.2831855f / 180.0f;
        e2[0] = 0.0f;
        r = func_00389410(r);
        b = i & 1;
        if (b) {
            r = -r;
        }
        e2[1] = r;
        e2[2] = 0.0f;
        e2[3] = 0.0f;
        func_00388BF0(m2, e2);
        func_00388BF0(m1, e1);
        func_00388F08(m1, m1, m2);
        m1[3] = *(u128_t *)a0;
        if (a2 == 0) {
            for (j = 0; j < 4; j++) {
                s.col[j] = D_001D9928_sda_005FBBC0[i];
            }
        } else {
            for (j = 0; j < 4; j++) {
                s.col[j] = ((s32 *)a2)[i];
            }
        }
        if (a3) {
            s.r78 = func_L39_00588720((i & 1) ? 0x57 : 0x58);
        } else {
            s.r78 = func_L39_00588720((i & 1) ? 0x12 : 0x11);
        }
        s.c80 = 0xFF9000000260L;
        s.c88 = 0x8000000044L;
        s.z70 = 0;
        s.v[0][0] = -1.0f; s.v[0][1] = 0.0f; s.v[0][2] = 1.0f; s.v[0][3] = 1.0f;
        s.v[1][0] = 1.0f; s.v[1][1] = 0.0f; s.v[1][2] = 1.0f; s.v[1][3] = 1.0f;
        s.v[2][0] = -1.0f; s.v[2][1] = 0.0f; s.v[2][2] = -1.0f; s.v[2][3] = 1.0f;
        s.v[3][0] = 1.0f; s.v[3][1] = 0.0f; s.v[3][2] = -1.0f; s.v[3][3] = 1.0f;
        func_003886E8(s.v[0], s.v[0], scale);
        func_003886E8(s.v[1], s.v[1], scale);
        func_003886E8(s.v[2], s.v[2], scale);
        func_003886E8(s.v[3], s.v[3], scale);
        s.q[0] = 0.0f; s.q[1] = 1.0f; s.q[2] = 1.0f; s.q[3] = 1.0f;
        s.q[4] = 0.0f; s.q[5] = 0.0f; s.q[6] = 1.0f; s.q[7] = 0.0f;
        func_003CD830(&s, m1, 1);
    }
}
/* localdecomp:end func_L39_005FBBC0 */
