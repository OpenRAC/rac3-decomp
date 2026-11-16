/* NTSC-U draft (Claude wave K): C of func_L01_0033F150, the NTSC-U twin of func_L01_0033F920, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details) (NTSC-U twin "func_L01_0033F150", whose code is not the PAL one).
 * Worker's note: NEEDS FLAGS: the file line lacks -mvu0-use-vf0-vf2 and @ps2as, but this function has real VU0 (lqc2/vsub.xyz/sqc2): vec_sub_ba's j operands fail without the first (vf17 spilled), ee-as rejects lqc2 without the second. Best draft ~240 of 581 insns align ...
 */
#include "common.h"
#include "vu0.h"

/* func_L01_0033F150 (NTSC-U counterpart of func_L01_0033F920): best draft of worker k05, level high.
   Needs the flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as"
   (the file's own line lacks -mvu0-use-vf0-vf2 and @ps2as: vec_sub_ba's "j" operands need the first, ee-as
   rejects lqc2 without the second). Not a match: ~240 of 581 instructions align.
   What is known (see the report note): eight explicit-pointer loops, up-counting `slti` counter
   (n = i + 1; i = n keeps it from being reversed), tmp/pts/xy bases as named pointers. */

/* localdecomp:start func_L01_0033F150 */
typedef struct { f32 x, y, z; } V3;
extern f32 D_001DD15C_sda;
extern f32 D_001DD160_sda;
extern s32 D_001DD158_sda;
extern f32 D_001DD164_sda;
extern u32 D_001DD168_sda;
extern s32 D_001DD138_sda;
extern s32 D_001DD150_sda;
__asm__(".extern D_001DD15C_sda, 4");
__asm__(".extern D_001DD160_sda, 4");
__asm__(".extern D_001DD158_sda, 4");
__asm__(".extern D_001DD164_sda, 4");
__asm__(".extern D_001DD168_sda, 4");
__asm__(".extern D_001DD138_sda, 4");
__asm__(".extern D_001DD150_sda, 4");
extern s32 D_L01_001DD13C[];
extern s32 D_L01_001DD154[];
extern s8 D_L01_001DD16F[];
extern u8 D_001A4EC0[];
extern u8 D_L01_001E2A40[];
extern V3 D_L01_002B15F0[];
extern f32 D_L01_002B1FB0[];
extern u32 D_L01_002B2630[];
extern V3 D_L01_002B1CE0[];
extern f32 D_L01_002B2450[];
extern u32 D_L01_002B2880[];

extern long func_00384EC0(s32);
extern void func_003A3EF0(s32, long);
extern void func_00388018(void);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003888F0(void *, void *, void *);
extern void func_003CE4B4(s32, void *, s32, void *, s32);

void func_L01_0033F150(u8 *obj, f32 alpha) {
    f32 m[16];
    V3 pts[148];
    f32 xy[296];
    f32 tmp[4];
    V3 *src;
    V3 *dst;
    f32 *A;
    f32 *B;
    f32 *c;
    f32 *d;
    u32 *col;
    s32 i;
    s32 n;
    V3 *pv;
    f32 *pa;
    f32 *pb;
    f32 *pt;

    D_001DD15C_sda = D_001DD15C_sda + D_001DD160_sda;
    if (D_001DD15C_sda >= 7.0f) {
        D_001DD15C_sda -= 7.0f;
    }
    func_003A3EF0(6, func_00384EC0(D_001DD158_sda));
    func_003A3EF0(0x42, 0x8000000048L);
    func_003A3EF0(8, 0);
    func_003A3EF0(0x14, 0xFF9000000260L);
    func_00388018();
    vec_sub_ba(m, D_L01_001E2A40, obj + 0x10);
    func_00388830(m, m, 1.0f);
    func_00388758(m + 4, m, D_001A4EC0);
    func_00388830(m + 4, m + 4, -1.0f);
    func_00388758(m + 8, m + 4, m);
    pv = pts;
    pa = xy;
    pb = xy + 1;
    pt = tmp;
    *(vu0_q *)(m + 12) = *(vu0_q *)(obj + 0x10);

    src = D_L01_002B15F0;
    dst = pv;
    A = pa;
    B = pb;
    c = D_L01_002B1FB0;
    d = D_L01_002B1FB0 + 1;
    col = D_L01_002B2630;
    for (i = 0; i < 148; i = n) {
        n = i + 1;
        tmp[0] = 0.0f;
        tmp[3] = 1.0f;
        tmp[1] = src->y * D_001DD164_sda;
        tmp[2] = src->x * D_001DD164_sda;
        src++;
        func_003888F0(pt, pt, m);
        *A = *d + D_001DD15C_sda;
        *B = *c;
        dst->x = tmp[0];
        dst->y = tmp[1];
        dst->z = tmp[2];
        dst++;
        if (*col & 0xFF000000) {
            s32 a = (s32)((f32)D_L01_001DD16F[0] * alpha);
            if (a <= 0) {
                a = 1;
            }
            *col = (a << 24) | D_001DD168_sda;
        } else {
            *col = D_001DD168_sda;
        }
        col++;
        A += 2; B += 2; c += 2; d += 2;
    }
    func_003CE4B4(D_001DD138_sda, pv, D_001DD150_sda, pa, 1);

    src = D_L01_002B1CE0;
    dst = pv;
    A = pa;
    B = pb;
    c = D_L01_002B2450;
    d = D_L01_002B2450 + 1;
    col = D_L01_002B2880;
    for (i = 0; i < 60; i = n) {
        n = i + 1;
        tmp[0] = 0.0f;
        tmp[3] = 1.0f;
        tmp[1] = src->y * D_001DD164_sda;
        tmp[2] = src->x * D_001DD164_sda;
        src++;
        func_003888F0(pt, pt, m);
        *A = *d + D_001DD15C_sda;
        *B = *c;
        dst->x = tmp[0];
        dst->y = tmp[1];
        dst->z = tmp[2];
        dst++;
        if (*col & 0xFF000000) {
            s32 a = (s32)((f32)D_L01_001DD16F[0] * alpha);
            if (a <= 0) {
                a = 1;
            }
            *col = (a << 24) | D_001DD168_sda;
        } else {
            *col = D_001DD168_sda;
        }
        col++;
        A += 2; B += 2; c += 2; d += 2;
    }
    func_003CE4B4(D_L01_001DD13C[0], pv, D_L01_001DD154[0], pa, 1);

    src = D_L01_002B15F0;
    dst = pv;
    A = pa;
    B = pb;
    c = D_L01_002B1FB0;
    d = D_L01_002B1FB0 + 1;
    for (i = 0; i < 148; i = n) {
        n = i + 1;
        tmp[0] = 0.0f;
        tmp[3] = 1.0f;
        tmp[1] = -src->y * D_001DD164_sda;
        tmp[2] = src->x * D_001DD164_sda;
        src++;
        func_003888F0(pt, pt, m);
        *A = *d + D_001DD15C_sda;
        *B = *c;
        dst->x = tmp[0];
        dst->y = tmp[1];
        dst->z = tmp[2];
        dst++;
        A += 2; B += 2; c += 2; d += 2;
    }
    func_003CE4B4(D_001DD138_sda, pv, D_001DD150_sda, pa, 1);

    src = D_L01_002B1CE0;
    dst = pv;
    A = pa;
    B = pb;
    c = D_L01_002B2450;
    d = D_L01_002B2450 + 1;
    for (i = 0; i < 60; i = n) {
        n = i + 1;
        tmp[0] = 0.0f;
        tmp[3] = 1.0f;
        tmp[1] = -src->y * D_001DD164_sda;
        tmp[2] = src->x * D_001DD164_sda;
        src++;
        func_003888F0(pt, pt, m);
        *A = *d + D_001DD15C_sda;
        *B = *c;
        dst->x = tmp[0];
        dst->y = tmp[1];
        dst->z = tmp[2];
        dst++;
        A += 2; B += 2; c += 2; d += 2;
    }
    func_003CE4B4(D_L01_001DD13C[0], pv, D_L01_001DD154[0], pa, 1);

    src = D_L01_002B15F0;
    dst = pv;
    A = pa;
    B = pb;
    c = D_L01_002B1FB0;
    d = D_L01_002B1FB0 + 1;
    for (i = 0; i < 148; i = n) {
        n = i + 1;
        tmp[0] = 0.0f;
        tmp[3] = 1.0f;
        tmp[1] = src->y * D_001DD164_sda;
        tmp[2] = -src->x * D_001DD164_sda;
        src++;
        func_003888F0(pt, pt, m);
        *A = *d + D_001DD15C_sda;
        *B = *c;
        dst->x = tmp[0];
        dst->y = tmp[1];
        dst->z = tmp[2];
        dst++;
        A += 2; B += 2; c += 2; d += 2;
    }
    func_003CE4B4(D_001DD138_sda, pv, D_001DD150_sda, pa, 1);

    src = D_L01_002B1CE0;
    dst = pv;
    A = pa;
    B = pb;
    c = D_L01_002B2450;
    d = D_L01_002B2450 + 1;
    for (i = 0; i < 60; i = n) {
        n = i + 1;
        tmp[0] = 0.0f;
        tmp[3] = 1.0f;
        tmp[1] = src->y * D_001DD164_sda;
        tmp[2] = -src->x * D_001DD164_sda;
        src++;
        func_003888F0(pt, pt, m);
        *A = *d + D_001DD15C_sda;
        *B = *c;
        dst->x = tmp[0];
        dst->y = tmp[1];
        dst->z = tmp[2];
        dst++;
        A += 2; B += 2; c += 2; d += 2;
    }
    func_003CE4B4(D_L01_001DD13C[0], pv, D_L01_001DD154[0], pa, 1);

    src = D_L01_002B15F0;
    dst = pv;
    A = pa;
    B = pb;
    c = D_L01_002B1FB0;
    d = D_L01_002B1FB0 + 1;
    for (i = 0; i < 148; i = n) {
        n = i + 1;
        tmp[0] = 0.0f;
        tmp[3] = 1.0f;
        tmp[1] = -src->y * D_001DD164_sda;
        tmp[2] = -src->x * D_001DD164_sda;
        src++;
        func_003888F0(pt, pt, m);
        *A = *d + D_001DD15C_sda;
        *B = *c;
        dst->x = tmp[0];
        dst->y = tmp[1];
        dst->z = tmp[2];
        dst++;
        A += 2; B += 2; c += 2; d += 2;
    }
    func_003CE4B4(D_001DD138_sda, pv, D_001DD150_sda, pa, 1);

    src = D_L01_002B1CE0;
    dst = pv;
    A = pa;
    B = pb;
    c = D_L01_002B2450;
    d = D_L01_002B2450 + 1;
    for (i = 0; i < 60; i = n) {
        n = i + 1;
        tmp[0] = 0.0f;
        tmp[3] = 1.0f;
        tmp[1] = -src->y * D_001DD164_sda;
        tmp[2] = -src->x * D_001DD164_sda;
        src++;
        func_003888F0(pt, pt, m);
        *A = *d + D_001DD15C_sda;
        *B = *c;
        dst->x = tmp[0];
        dst->y = tmp[1];
        dst->z = tmp[2];
        dst++;
        A += 2; B += 2; c += 2; d += 2;
    }
    func_003CE4B4(D_L01_001DD13C[0], pv, D_L01_001DD154[0], pa, 1);
}
/* localdecomp:end func_L01_0033F150 */
