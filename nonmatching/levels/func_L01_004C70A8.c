/* Draft (178 differing words, nearly all one 8-byte shift; open-rac-engine: landing_marker_draw).
 * Uses sqrt_asm (include/vu0.h) for its one bare `sqrt.s`; this file has no other C sqrt site.
 * Everything follows retail but one spot: retail computes `odd = i & 1` after the spin's
 * func_0038DB48 call (`andi $v0,$s0,1; move $s1,$v0; andi $v0,$v0,0xff; bnel`), where this C
 * gets it hoisted to the loop head (not by sched1, gcse or the asm: tried -fno-schedule-insns,
 * -fno-gcse and no sqrt_asm), so i/odd swap $s0/$s1, two words go and the first colour loop
 * loses its 8-alignment nop. Tried: odd as u8/s32, `(u8)odd`, the assignment inside the test.
 * The two colour loops differ in retail: the table one fills colour[3..0] backwards, the
 * argument one walks a pointer forwards. func_0038CE20 is called through an alias (a later block
 * declares it with its own vector type); check.py shows `jal 0` for it until a level build has
 * derived the alias. */
#include "vu0.h"
typedef int u128_4C70A8 __attribute__((mode(TI)));
typedef struct {
    f32 verts[4][4];       /* 0x00 */
    u32 colour[4];         /* 0x40 */
    f32 uv[8];             /* 0x50 */
    unsigned long f70;     /* 0x70 */
    unsigned long tex;     /* 0x78 */
    unsigned long reg80;   /* 0x80 */
    unsigned long prim;    /* 0x88 */
} Quad_4C70A8;
typedef struct {
    u8 pad0[0x25C4];
    s32 state;             /* 0x25C4 */
} Hero_4C70A8;

__asm__(".extern D_L01_001DAFF8, 8");
extern u32 D_L01_001DAFF8[2];      /* the two rings' colours */
extern S_4C4A18 D_001A4BE0;
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;         /* the frame count */
extern s32 func_L01_00511A98(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_0038D328(f32 *mat, f32 *rot);
extern void func_0038D640(f32 *out, f32 *a, f32 *b);
extern unsigned long func_00389598(int tex);
/* a later block of this file declares it with its own vector type */
extern void func_0038CE20_004C70A8(f32 *out, f32 *in, f32 s);
extern void func_003D2DA0(Quad_4C70A8 *quad, f32 *mat, int a);

/* landing_marker_draw: two rings turning opposite ways at pos, facing along dir */
void func_L01_004C70A8(u128_4C70A8 *pos, f32 *dir, u32 *colours, s32 big, f32 scale)
{
    Quad_4C70A8 quad;
    f32 mat[16];
    f32 spin_mat[16];
    f32 angles[4];
    f32 spin[4];
    s32 i;
    s32 k;
    s32 odd;
    u32 colour;
    u32 *c;
    f32 turn;
    s32 state = ((Hero_4C70A8 *)&D_001A4BE0)->state;

    if (state == 23 || state == 24 || state == 27 || state == 25 || state == 26 || state == 116) {
        return;
    }
    if (func_L01_00511A98() != 0 || D_L01_001D6694 == 2) {
        return;
    }
    i = 0;
    do {
        angles[0] = func_0038DAB8(-func_0038D160(sqrt_asm(dir[0] * dir[0] + dir[2] * dir[2]), dir[1]), 1.5707964f);
        angles[1] = func_0038D160(dir[2], dir[0]);
        angles[2] = 0.0f;
        angles[3] = 0.0f;
        spin[0] = 0.0f;
        turn = func_0038DB48((f32)(D_L01_001DFB40 % 150) * 6.2831855f / 150.33333f);
        if ((u8)(odd = i & 1)) {
            turn = -turn;
        }
        spin[1] = turn;
        spin[2] = 0.0f;
        spin[3] = 0.0f;
        func_0038D328(spin_mat, spin);
        func_0038D328(mat, angles);
        func_0038D640(mat, mat, spin_mat);
        *(u128_4C70A8 *)&mat[12] = *pos;
        if (colours == 0) {
            colour = D_L01_001DAFF8[i++];
            for (k = 3; k >= 0; k--) {
                quad.colour[k] = colour;
            }
        } else {
            colour = colours[i++];
            c = quad.colour;
            for (k = 3; k >= 0; k--) {
                *c++ = colour;
            }
        }
        if (big) {
            quad.tex = func_00389598(odd ? 0x57 : 0x58);
        } else {
            quad.tex = func_00389598(odd ? 0x12 : 0x11);
        }
        quad.reg80 = 0xFF9000000260;
        quad.prim = 0x8000000044;
        quad.f70 = 0;
        quad.verts[0][0] = -1.0f; quad.verts[0][1] = 0.0f; quad.verts[0][2] = 1.0f; quad.verts[0][3] = 1.0f;
        quad.verts[1][0] = 1.0f;  quad.verts[1][1] = 0.0f; quad.verts[1][2] = 1.0f; quad.verts[1][3] = 1.0f;
        quad.verts[2][0] = -1.0f; quad.verts[2][1] = 0.0f; quad.verts[2][2] = -1.0f; quad.verts[2][3] = 1.0f;
        quad.verts[3][0] = 1.0f;  quad.verts[3][1] = 0.0f; quad.verts[3][2] = -1.0f; quad.verts[3][3] = 1.0f;
        func_0038CE20_004C70A8(quad.verts[0], quad.verts[0], scale);
        func_0038CE20_004C70A8(quad.verts[1], quad.verts[1], scale);
        func_0038CE20_004C70A8(quad.verts[2], quad.verts[2], scale);
        func_0038CE20_004C70A8(quad.verts[3], quad.verts[3], scale);
        quad.uv[0] = 0.0f; quad.uv[1] = 1.0f; quad.uv[2] = 1.0f; quad.uv[3] = 1.0f;
        quad.uv[4] = 0.0f; quad.uv[5] = 0.0f; quad.uv[6] = 1.0f; quad.uv[7] = 0.0f;
        func_003D2DA0(&quad, mat, 1);
    } while (i < 2);
}
