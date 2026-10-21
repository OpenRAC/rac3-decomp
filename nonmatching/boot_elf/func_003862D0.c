/* US draft of func_003862D0 (rac3-uya-decomp func_003862A8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003862D0 */
/* func_003862D0: blend the fog colour / depth of a camera region (0x80-byte entries of D_002FE200) by the
 * weight func_003CD1D8 returns. Flags: @ps2as (localdecomp_flags.txt already has it; text_parts needs a
 * single-function override). Needs the alias func_003CD1D8_003862D0 = 0x3C78B0.
 * Store order: the third colour byte (D_001D9C46) is computed and stored first, then the first two.
 * Same shape as the rac1-decomp port in scratch/agent_results/2026-10-12-rac1-port (written independently here
 * from the retail asm).
 */
typedef struct {
    u8 p0[0x50];
    s32 f50;
    s32 c0;
    s32 c1;
    f32 f5C, f60, f64, f68;
    f32 f6C, f70, f74, f78;
    u8 p7C[4];
} R_381C18;
extern R_381C18 D_002FE200[];
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern s32 func_003CD1D8_003862D0(void *, f32 *, s32 *);

void func_003862D0(void *pos) {
    f32 t;
    s32 idx;
    R_381C18 *r;
    u32 w1, w0;
    s32 c0, c1;
    f32 u;
    u32 a, b;
    u32 r1, r0, g1, g0, b1, b0;

    if (func_003CD1D8_003862D0(pos, &t, &idx) == 0) {
        return;
    }
    r = &D_002FE200[idx];
    if (!(r->f50 & 2)) {
        return;
    }
    w1 = (s32)(t * 255.0f);
    w0 = 255 - w1;
    u = 1.0f - t;
    c1 = r->c1;
    c0 = r->c0;
    r1 = (c1 & 0xFF) * w1;
    g1 = ((c1 >> 8) & 0xFF) * w1;
    b1 = (c1 >> 16) & 0xFF;
    r0 = (c0 & 0xFF) * w0;
    g0 = ((c0 >> 8) & 0xFF) * w0;
    b0 = (c0 >> 16) & 0xFF;
    a = (s32)(r1 + r0) >> 8;
    b = (s32)(g1 + g0) >> 8;
    D_001D9C46 = (s32)(b1 * w1 + b0 * w0) >> 8;
    D_001D9C44 = a;
    D_001D9C45 = b;
    D_001D9C48 = (r->f6C * t + r->f5C * u) * 1024.0f;
    D_001D9C4C = (r->f74 * t + r->f64 * u) * 1024.0f;
    D_001D9C50 = 255.0f - (r->f70 * t + r->f60 * u) * 255.0f;
    D_001D9C54 = 255.0f - (r->f78 * t + r->f68 * u) * 255.0f;
}
/* localdecomp:end func_003862D0 */
