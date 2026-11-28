/* Wave 13 (r23, 2026-11-28) replaces the earlier draft of this function (Codex wave 11 near miss). */
/* PAL near miss (wave 13, r23): 4 words differ in its file's context with the file's flags (the draft gave 111).
 * Changes against the draft: D_L03_ names in the level 5/7 sibling forms (u8 record addresses on $gp; each
 * record's +4 count read through an 8-byte R_00411220 alias with `.extern ..., 16`, as func_L05_0041DB30
 * does, so it stays lui+lw and is not hoisted into a delay slot), no section(.sdata) externs or _sda names;
 * the case 2 loop written as the matched func_L19_00418E68 writes it (the global flag in the for condition and
 * set in two nested ifs: GCC keeps it in a register and stores it after the loop, which gives retail's
 * move a1,a0 copy and the beql/move a1,t5 form; the field D_L03_001E6800.f34 read in the loop gives the
 * move a2,v1 copy), the $gp tables as scalars through pa/pb; prologue order float, f20, f30 with the zeroes
 * a, c, b, d, e (as func_L05_0041DB30); case 13 as if/else; the d choice as `<=`.
 * Left: the case 2 loop preheader order. Retail sets the constants 6 and 1 before the two table pointers
 * (addiu a0,6; addiu t5,1; addiu t0,gp; addiu a3,gp), ours sets the pointers first. Indexing the scalars
 * directly ((&D_L03_001D6C68)[i], or .sdata arrays) gives retail's preheader order but swaps e and the
 * D_L03_002E5D50 high part (t6/t7, 8 words); pointers in the for-init, pb before pa, a while loop, pointers
 * set before e = 1 or at their declaration change nothing or are worse.
 */
#include "common.h"

/* localdecomp:start func_L03_00411220 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_00411220;
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; } S2_00411220;
typedef struct { u8 p0[4]; s32 f4; } R_00411220;
extern S_00411220 D_L03_002E5CA0;
extern S2_00411220 D_L03_001E6800;
extern f32 D_L03_001D6B64;
extern u8 D_L03_001D6AD0;
extern u8 D_L03_001D6AC5;
extern u8 D_L03_001D6B90;
extern u8 D_L03_001D6BA8;
extern u8 D_L03_001D6BC0;
extern u8 D_L03_001D6BD8;
extern u8 D_L03_001D6BF0;
extern u8 D_L03_001D6C08;
extern u8 D_L03_001D6C20;
extern R_00411220 D_L03_001D6B90_00411220;
__asm__(".extern D_L03_001D6B90_00411220, 16");
extern R_00411220 D_L03_001D6BA8_00411220;
__asm__(".extern D_L03_001D6BA8_00411220, 16");
extern R_00411220 D_L03_001D6BC0_00411220;
__asm__(".extern D_L03_001D6BC0_00411220, 16");
extern R_00411220 D_L03_001D6BD8_00411220;
__asm__(".extern D_L03_001D6BD8_00411220, 16");
extern R_00411220 D_L03_001D6BF0_00411220;
__asm__(".extern D_L03_001D6BF0_00411220, 16");
extern R_00411220 D_L03_001D6C08_00411220;
__asm__(".extern D_L03_001D6C08_00411220, 16");
extern s32 D_L03_001D6C38;
extern u8 D_L03_001D6C50;
extern s32 D_L03_001D6C68;
extern s32 D_L03_001D6C78;
extern s32 D_L03_002E5CF0[];
extern s32 D_L03_002E5D50[];
extern s32 D_L03_002E5DC0[];
extern s32 D_L03_002E5E30[];
extern s32 D_L03_002E5E90[];
extern s32 D_L03_002E5EF0[];
extern s32 D_L03_002E5F50[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
extern void func_L03_004109D8(void *, void *, void *, s32);

void func_L03_00411220(void) {
    void *a;
    void *b;
    void *c;
    void *d;
    s32 e;
    s32 i;
    s32 *pa;
    s32 *pb;
    s32 t;

    D_L03_001D6B64 = 1.0f;
    D_L03_002E5CA0.f20 = &D_L03_001D6AD0;
    D_L03_002E5CA0.f30 = 1;
    a = 0;
    c = 0;
    b = 0;
    d = 0;
    e = 0;
    D_L03_001D6AC5 = 0;
    if (D_001D545C == 3) {
        switch (D_L03_001E6800.f30) {
        case 0:
            t = D_L03_001E6800.f34;
            a = D_L03_002E5CF0;
            if (t < (D_L03_001D6B90_00411220.f4 * 5 + 2) / 6) b = &D_L03_001D6B90;
            else if (t < (D_L03_001D6BA8_00411220.f4 * 5 + 2) / 6) b = &D_L03_001D6BA8;
            else if (t < (D_L03_001D6BC0_00411220.f4 * 5 + 2) / 6) b = &D_L03_001D6BC0;
            else if (t < (D_L03_001D6BD8_00411220.f4 * 5 + 2) / 6) b = &D_L03_001D6BD8;
            else if (t < (D_L03_001D6BF0_00411220.f4 * 5 + 2) / 6) b = &D_L03_001D6BF0;
            else if (t < (D_L03_001D6C08_00411220.f4 * 5 + 2) / 6) b = &D_L03_001D6C08;
            else b = &D_L03_001D6C20;
            break;
        case 2:
            if (D_L03_001E6800.f34 < (D_L03_001D6C38 * 5 + 2) / 6) {
                D_L03_002E5CA0.f30 = 0;
                e = 1;
                pa = &D_L03_001D6C68;
                pb = &D_L03_001D6C78;
                for (i = 0; i < 4 && D_L03_001D6AC5 == 0; i++) {
                    if (D_L03_001E6800.f34 >= (pa[i] * 5 + 2) / 6) {
                        if (D_L03_001E6800.f34 <= (pb[i] * 5 + 2) / 6) {
                            D_L03_001D6AC5 = 1;
                        }
                    }
                }
                c = &D_L03_001D6C50;
            } else {
                b = &D_L03_001D6C38;
            }
            if (D_L03_001E6800.f34 <= (D_L03_002E5D50[21] * 5 + 2) / 6) d = D_L03_002E5D50;
            else d = D_L03_002E5DC0;
            break;
        case 12:
            if (D_L03_001E6800.f34 >= (D_L03_002E5E30[14] * 5 + 2) / 6) a = D_L03_002E5E30;
            break;
        case 13:
            if (D_L03_001E6800.f34 < (D_L03_002E5E90[15] * 5 + 2) / 6) a = D_L03_002E5E90;
            else a = D_L03_002E5EF0;
            break;
        case 17:
            a = D_L03_002E5F50;
            break;
        }
    }
    if (a != 0) {
        func_L01_00423068(a, (s32)b, (s32)c, e, 0, 1, 0);
    } else if (d != 0) {
        func_L03_004109D8(d, b, c, e);
    }
}
/* localdecomp:end func_L03_00411220 */
