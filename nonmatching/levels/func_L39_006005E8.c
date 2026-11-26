/* func_L39_006005E8 (1352 B, 15 places): k4 Sonnet first pass, NEAR MISS (rough draft): 325 diff of ~338 rows with the file's flags + `--as ps2as`
 * (checked at level 39 only). The structure is right (all control flow, calls, constants, field offsets); almost every row differs by register numbers,
 * because the draft's register allocation is off (retail keeps the -1 constant in $s5, the &D_L39_0025D9C0 + 8 base in $s3, six $s regs, frame 0xA0; draft: 0x90).
 * What it is: GS sprite/texture-upload packet builder for a level-39 menu object `o` (Obj: f2 = entry count, f6 = texture count, f8 flag, f10 id, f14 = u32 list,
 * f18 = Ent[16 B] array, f1C = base, f24/f28 selector). Part 1 loops over o->f18 entries building the 64-bit GS tag word in e->f0 (D_L39_002402F0 is the
 * running VRAM page counter) and a slot record in D_L39_0025D9C0 (16 B slots, counter D_L39_0024B9FC < 0x40). Part 2: func_L39_00600190() is a K&R-style call that
 * relies on leftover $a0..$a3 (retail has only `jal; nop`), then scales mat[10] and mat[0] when the sda byte is set, func_L39_00590508(mat+12, mat+12, 166.66666f),
 * builds the view matrix m[16] on the stack via func_L39_00591050(m, &D_001D99C0_sda, mat) and adds the screen offsets D310/D314 plus 16*x / 16*y to m[12] / m[13],
 * func_L39_00590C70(0x70001FC0), optionally func_L39_005FFFD0(sc, o, 0x70002000), func_L39_005A9828 / 005A9968, then Part 3 walks o->f14 emitting DMA/GIF
 * packets (0x10000008 tag via *D_001E13C0_sda, a 128-bit copy from D_001D9970_sda, t3/t4 GIF words, and 4 x 24-byte copies from scratchpad 0x70000000 + (byte << 5)).
 * Needs `@ps2as` (float constants are built inline with lui/ori/mtc1; with it the constants and 5 hunks equal) and `long` (not `long long`) for 64-bit values:
 * `s64` is rejected by SN gcc here ("unsupported wide integer operation"). Declarations: D_L39_002402F0/300/304/310/314, D_L39_0024B9FC, D_L39_002450F4,
 * D_L39_0024CAD0 need `__asm__(".extern X, 16")` (size > 8 keeps them out of $gp); gp slots D_001D99B4_sda (-0x2EFC, u8), D_001D99B0_sda (-0x2F00),
 * D_001D99C0_sda (-0x2EF0), D_001D9970_sda (-0x2F40, u128), D_001E13C0_sda (0x4B10, u32 *).
 * Prototypes: confident for callees' arg counts; float/int split inferred (f12/f13/f14 = x, y, sc in this order; the draft's x,y order compiled to swapped $f20/$f21).
 * Still wrong / next steps: (1) allocation: retail has t5 = 1, t6 = D_L39_0025D9C0, s3 = t6+8 (second base for the f8 pointer field: try a second array or `(u8 *)D + 8`),
 * s5 = -1 in the loop; (2) the sll/addu order of the slot index; (3) part 3's 4 copies and the order of the stores to the *D_L39_0024CAD0 header (retail reloads the global each
 * time) not yet compared row by row; (4) the `lq/sq` copy needs the exact u128_t copy form from docs/wiki/Matching-Patterns.md. Permuter is unlikely to help before (1).
 */
#include "common.h"
/* localdecomp:start func_L39_006005E8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    long f0;
    u16 f8;
    u16 fA;
    s16 fC;
    s16 fE;
} Ent_6005E8;
typedef struct {
    s16 f0;
    s16 f2;
    u8 pad4[2];
    s16 f6;
    s16 f8;
    u8 padA[6];
    s32 f10;
    s32 *f14;
    Ent_6005E8 *f18;
    u8 *f1C;
    s32 f20;
    s32 f24;
    s32 f28;
} Obj_6005E8;
typedef struct { u8 pad[0xB0]; f32 fB0; f32 fB4; } Cam_6005E8;
typedef struct { u8 pad[0xAD]; u8 fAD; } Glob_6005E8;
typedef struct { u8 *f0; s16 f4; s16 f6; u8 *f8; u8 fC; u8 fD; s16 fE; } Slot_6005E8;
extern s32 D_L39_002402F0;
__asm__(".extern D_L39_002402F0, 16");
extern s32 D_L39_00240300;
__asm__(".extern D_L39_00240300, 16");
extern s32 D_L39_00240304;
__asm__(".extern D_L39_00240304, 16");
extern s32 D_L39_00240310;
__asm__(".extern D_L39_00240310, 16");
extern s32 D_L39_00240314;
__asm__(".extern D_L39_00240314, 16");
extern s32 D_L39_0024B9FC;
__asm__(".extern D_L39_0024B9FC, 16");
extern u32 *D_L39_0024CAD0;
__asm__(".extern D_L39_0024CAD0, 16");
extern f32 D_L39_002450F4;
__asm__(".extern D_L39_002450F4, 16");
extern Slot_6005E8 D_L39_0025D9C0[];
extern Cam_6005E8 D_L39_0025D6C0;
extern Glob_6005E8 D_001A5810;
extern u8 D_001D99B4_sda;
__asm__(".extern D_001D99B4_sda, 1");
extern f32 D_001D99B0_sda;
__asm__(".extern D_001D99B0_sda, 4");
extern f32 D_001D99C0_sda;
__asm__(".extern D_001D99C0_sda, 4");
extern u128_t D_001D9970_sda;
__asm__(".extern D_001D9970_sda, 16");
extern u32 *D_001E13C0_sda;
__asm__(".extern D_001E13C0_sda, 4");
extern void func_L39_00590508(f32 *, void *, f32);
extern void func_L39_00590C70(void *);
extern void func_L39_00591050(f32 *, void *, f32 *);
extern void func_L39_005A9828(s32, f32 *, s32, s32);
extern void func_L39_005A9968(s32, f32 *, s32, s32, s32);
extern void func_L39_005FFFD0(f32, Obj_6005E8 *, s32);
extern void func_L39_00600190();

void func_L39_006005E8(Obj_6005E8 *o, s32 col, f32 *mat, f32 x, f32 y, f32 sc) {
    f32 m[16];
    s32 i;
    s32 j;
    s32 cur;
    s32 nxt;
    s32 sh;
    Ent_6005E8 *e;
    Slot_6005E8 *sl;
    s32 *p;
    long t3;
    s32 t4;
    f32 yy;
    long *d;
    long *src;

    if ((col >> 24) != 0) {
        for (i = 0; i < o->f6; i++) {
            e = &o->f18[i];
            cur = D_L39_002402F0;
            nxt = cur + 0x400;
            sh = e->fC - 6;
            if (sh < 0) { sh = 0; }
            D_L39_002402F0 = nxt + (1 << (e->fC + e->fE));
            e->f0 = (nxt >> 8) | ((long)(1 << sh) << 14) | ((((long)(u16)e->fC << 48) >> 22) | 0x1300000)
                    | (((long)(u16)e->fE << 48) >> 18) | (((long)(cur >> 8) << 37) | (0x8000 << 19)) | ((long)-1 << 63);
            if (D_L39_0024B9FC < 0x40) {
                sl = &D_L39_0025D9C0[D_L39_0024B9FC];
                sl->f6 = cur >> 8;
                sl->f4 = 0;
                sl->f0 = o->f1C + e->fA * 16;
                sl->f8 = o->f1C + e->f8 * 16;
                sl->fC = e->fC;
                sl->fE = nxt >> 8;
                sl->fD = e->fE;
                D_L39_0024B9FC++;
            }
        }
        func_L39_00600190();
        if (D_001D99B4_sda != 0) {
            mat[10] = mat[10] * (D_001D99B0_sda * 1.126f);
            mat[0] = mat[0] * 1.18f;
        }
        func_L39_00590508(mat + 12, mat + 12, 166.66666f);
        yy = -((f32)(D_L39_00240304 >> 1) / D_L39_0025D6C0.fB4);
        D_001D99C0_sda = (f32)(D_L39_00240300 >> 1) / D_L39_0025D6C0.fB0;
        D_L39_002450F4 = yy;
        if (D_001A5810.fAD != 0) {
            D_L39_002450F4 = yy * 0.75000006f;
        }
        func_L39_00591050(m, &D_001D99C0_sda, mat);
        m[13] += (f32)D_L39_00240314 + y * 16.0f;
        m[12] += (f32)D_L39_00240310 + x * 16.0f;
        func_L39_00590C70((void *)0x70001FC0);
        if (o->f8 != 0) {
            func_L39_005FFFD0(sc, o, 0x70002000);
        }
        if (o->f24 == 0) {
            func_L39_005A9828(o->f10, m, o->f0, col);
        } else {
            func_L39_005A9968(o->f10, m, o->f0, o->f28, col);
        }
        t3 = ((((long)0x8000 << 29) | 0x9980) << 19) | 0x7FFB;
        if (o->f6 != 0) {
            p = o->f14;
            t4 = 0x5C;
        } else {
            t4 = 0x4C;
            p = o->f14 + 1;
        }
        for (j = 0; j < o->f2; j++, p++) {
            if (o->f6 != 0 && (*p >> 8) == -1) {
                if ((u8)*p < o->f6) {
                    t3 = o->f18[(u8)*p].f0;
                } else {
                    t3 = ((((long)0x8000 << 29) | 0x9980) << 19) | 0x7FFB;
                }
                j--;
            } else {
                *D_001E13C0_sda = 0x10000008;
                D_L39_0024CAD0[1] = 0;
                D_L39_0024CAD0[2] = 0;
                D_L39_0024CAD0[3] = 0x50000008;
                *(u128_t *)(D_L39_0024CAD0 + 4) = D_001D9970_sda;
                D_L39_0024CAD0 += 4;
                d = (long *)D_L39_0024CAD0;
                D_L39_0024CAD0 += 4;
                d[2] = t3;
                ((long *)D_L39_0024CAD0)[1] = t4;
                src = (long *)(0x70000000 + (((u8 *)p)[0] << 5));
                d = (long *)D_L39_0024CAD0;
                d[2] = src[0]; d[3] = src[1]; d[4] = src[2];
                src = (long *)(0x70000000 + (((u8 *)p)[1] << 5));
                d[5] = src[0]; d[6] = src[1]; d[7] = src[2];
                src = (long *)(0x70000000 + (((u8 *)p)[3] << 5));
                d[8] = src[0]; d[9] = src[1]; d[10] = src[2];
                src = (long *)(0x70000000 + (((u8 *)p)[2] << 5));
                d[11] = src[0]; d[12] = src[1]; d[13] = src[2];
                D_L39_0024CAD0 += 28;
            }
        }
    }
}
/* localdecomp:end func_L39_006005E8 */
