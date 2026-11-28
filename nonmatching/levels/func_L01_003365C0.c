/* func_L01_003365C0 (Claude wave 14 r65, 2026-11-28). First draft kept here. */
/* func_L01_003365C0 (1996 B, 34 places, src/levels/shared/L01_003355B8.c, its own line
   '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as'): first byte-oriented draft, wr65
   (wave 14, 2026-11-28), from retail and the functional C. 441 diff (p10 check.py, level 01), about 243 rows
   aligned with registers masked (ours 496 words, retail 500). Same frame (0x210) and layout as retail: pkt at 0,
   c[4] 0x90, up 0xD0, mat 0xE0, sq[4] 0x110 (a nested block with an array initializer gives retail's four
   zeroed 16-byte temporaries at 0x150..0x180 and the lq/sq copies), 8 reload slots 0x190..0x1AC.
   What made it close: u8 *cam for D_L01_001E2880 (la + 0x158(reg) as retail, reloaded after calls), the four
   0038D000 calls written out (retail has no loop there), the 0038CE20 loops as for loops (dbra counts down),
   
 = i + 1 / i = n for the outer loop (retail keeps i in s4 and i + 1 in s5 and reuses s4 for the inner
   counter), the colour index as k = q; if (p94 == 2) k = q + 9; (xori + movn as retail; the ternary keeps
   branches and a hoisted 2 in a saved register), func_0038CE20 declared in the body (the file declares it only
   later), D_L01_001DCF38 as a 4-byte small-data object (gp for the first column).
   Still differs: (1) the table columns: retail addresses D_L01_001DCF38 + 4/8/12 as absolute symbol+offset
   constants (Ps2EeAs la; extern s32 D[][4] __attribute__((section(".sdata"))) reproduces those exactly but
   allocates worse, 467) where this [1] form computes (i * 4 + j) << 2; (2) the movn selects the scaled index
   in retail (q * 4 + 0x24 vs q * 4, then + D_L01_002AF598) and the unscaled one here, and the if form
   splits the block, so D_L01_001DCF78 is reloaded per vertex; (3) register allocation of the hoisted
   addresses (retail: s7 = D_L01_002AF550, fp = mat, D_L01_002AF598/D_L01_002AF4C0 rematerialized) and the
   order of the 8 reload slots (retail &sq[1..3], &c[0..3], &sq[0]). */
#include "common.h"

/* localdecomp:start func_L01_003365C0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003365C0;

typedef struct {
    V4_003365C0 pos[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long w70, w78, w80, w88;
} __attribute__((aligned(16))) Pkt_003365C0;

extern u8 D_L01_001E2880[];
extern V4_003365C0 D_L01_002AF4C0[];
extern f32 D_L01_002AF550[][2];
extern u32 D_L01_002AF598[];
extern s32 D_L01_001DCF38[1];
__asm__(".extern D_L01_001DCF38, 4");
extern f32 D_L01_001DCF78;
__asm__(".extern D_L01_001DCF78, 4");
extern f32 D_L01_001DCF7C;
__asm__(".extern D_L01_001DCF7C, 4");

void func_L01_003365C0(u8 *m) {
    extern void func_0038D308(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(void *, void *, s32);
    Pkt_003365C0 pkt;
    V4_003365C0 c[4];
    V4_003365C0 up;
    V4_003365C0 mat[3];
    u8 *p = *(u8 **)(m + 0x68);
    u8 *cam = D_L01_001E2880;
    f32 t;
    f32 ns;
    f32 ps;
    f32 z1;
    f32 z2;
    s32 i;
    s32 j;
    s32 q;
    s32 k;
    s32 n;
    u32 color;

    up.x = 0.0f;
    up.y = 0.0f;
    up.z = *(f32 *)(cam + 0x158);
    func_0038D308(mat, &up);
    D_L01_001DCF78 += 0.01f;
    if (1.0f < D_L01_001DCF78) {
        D_L01_001DCF78 -= 1.0f;
    }
    pkt.w70 = 0;
    pkt.w80 = 1;
    pkt.w88 = 0x4000000044UL;
    pkt.w78 = func_00389598(0x18);
    for (i = 0; i < 4; i = n) {
        n = i + 1;
        func_0038D000(&c[0], &D_L01_002AF4C0[D_L01_001DCF38[i * 4 + 0]], mat);
        func_0038D000(&c[1], &D_L01_002AF4C0[D_L01_001DCF38[i * 4 + 1]], mat);
        func_0038D000(&c[2], &D_L01_002AF4C0[D_L01_001DCF38[i * 4 + 2]], mat);
        func_0038D000(&c[3], &D_L01_002AF4C0[D_L01_001DCF38[i * 4 + 3]], mat);
        for (j = 0; j < 4; j++) {
            func_0038CE20(&c[j], &c[j], 0.5f);
        }
        pkt.pos[0].x = *(f32 *)(m + 0x10) + c[0].x * *(f32 *)(p + 0x90);
        pkt.pos[0].y = *(f32 *)(m + 0x14) + c[0].y * *(f32 *)(p + 0x90);
        pkt.pos[0].z = *(f32 *)(m + 0x18) + c[0].z - 1.0f + 1.45f;
        pkt.pos[1].x = *(f32 *)(m + 0x10) + c[1].x * *(f32 *)(p + 0x90);
        pkt.pos[1].y = *(f32 *)(m + 0x14) + c[1].y * *(f32 *)(p + 0x90);
        pkt.pos[1].z = *(f32 *)(m + 0x18) + c[1].z - 1.0f + 1.45f;
        pkt.pos[2].x = *(f32 *)(m + 0x10) + c[2].x * *(f32 *)(p + 0x90);
        pkt.pos[2].y = *(f32 *)(m + 0x14) + c[2].y * *(f32 *)(p + 0x90);
        pkt.pos[2].z = *(f32 *)(m + 0x18) + c[2].z - 1.0f + 1.45f;
        pkt.pos[3].x = *(f32 *)(m + 0x10) + c[3].x * *(f32 *)(p + 0x90);
        pkt.pos[3].y = *(f32 *)(m + 0x14) + c[3].y * *(f32 *)(p + 0x90);
        pkt.pos[3].z = *(f32 *)(m + 0x18) + c[3].z - 1.0f + 1.45f;
        q = D_L01_001DCF38[i * 4 + 0];
        k = q;
        if (*(s32 *)(p + 0x94) == 2) {
            k = q + 9;
        }
        pkt.color[0] = D_L01_002AF598[k];
        pkt.uv[0][0] = D_L01_002AF550[q][0];
        pkt.uv[0][1] = D_L01_002AF550[q][1] + D_L01_001DCF78;
        q = D_L01_001DCF38[i * 4 + 1];
        k = q;
        if (*(s32 *)(p + 0x94) == 2) {
            k = q + 9;
        }
        pkt.color[1] = D_L01_002AF598[k];
        pkt.uv[1][0] = D_L01_002AF550[q][0];
        pkt.uv[1][1] = D_L01_002AF550[q][1] + D_L01_001DCF78;
        q = D_L01_001DCF38[i * 4 + 2];
        k = q;
        if (*(s32 *)(p + 0x94) == 2) {
            k = q + 9;
        }
        pkt.color[2] = D_L01_002AF598[k];
        pkt.uv[2][0] = D_L01_002AF550[q][0];
        pkt.uv[2][1] = D_L01_002AF550[q][1] + D_L01_001DCF78;
        q = D_L01_001DCF38[i * 4 + 3];
        k = q;
        if (*(s32 *)(p + 0x94) == 2) {
            k = q + 9;
        }
        pkt.color[3] = D_L01_002AF598[k];
        pkt.uv[3][0] = D_L01_002AF550[q][0];
        pkt.uv[3][1] = D_L01_002AF550[q][1] + D_L01_001DCF78;
        func_003D2DA0(&pkt, 0, 1);
    }

    pkt.w78 = func_00389598(0x1B);
    D_L01_001DCF7C += 0.01f;
    if (1.0f < D_L01_001DCF7C) {
        D_L01_001DCF7C = 0.0f;
    }
    t = D_L01_001DCF7C;
    ns = -t * 1.2f;
    ps = t * 1.2f;
    z1 = t * 1.4f + 1.1f;
    z2 = z1 - 0.2f;
    {
    V4_003365C0 sq[4] = {
        { ns * *(f32 *)(p + 0x90), ns * *(f32 *)(p + 0x90), z1 },
        { ps * *(f32 *)(p + 0x90), ns * *(f32 *)(p + 0x90), z2 },
        { ns * *(f32 *)(p + 0x90), ps * *(f32 *)(p + 0x90), z1 },
        { ps * *(f32 *)(p + 0x90), ps * *(f32 *)(p + 0x90), z2 },
    };
    up.x = 0.0f;
    up.y = 0.0f;
    up.z = *(f32 *)(cam + 0x158);
    func_0038D308(mat, &up);
    func_0038D000(&c[0], &sq[0], mat);
    func_0038D000(&c[1], &sq[1], mat);
    func_0038D000(&c[2], &sq[2], mat);
    func_0038D000(&c[3], &sq[3], mat);
    }
    for (j = 0; j < 4; j++) {
        func_0038CE20(&c[j], &c[j], 0.5f);
    }
    color = ((s32)((1.0f - D_L01_001DCF7C) * 128.0f) << 24) | 0x808080;
    pkt.pos[0].x = *(f32 *)(m + 0x10) + c[0].x;
    pkt.pos[0].y = *(f32 *)(m + 0x14) + c[0].y;
    pkt.pos[0].z = *(f32 *)(m + 0x18) + c[0].z - 1.0f + 1.45f;
    pkt.pos[1].x = *(f32 *)(m + 0x10) + c[1].x;
    pkt.pos[1].y = *(f32 *)(m + 0x14) + c[1].y;
    pkt.pos[1].z = *(f32 *)(m + 0x18) + c[1].z - 1.0f + 1.45f;
    pkt.pos[2].x = *(f32 *)(m + 0x10) + c[2].x;
    pkt.pos[2].y = *(f32 *)(m + 0x14) + c[2].y;
    pkt.pos[2].z = *(f32 *)(m + 0x18) + c[2].z - 1.0f + 1.45f;
    pkt.pos[3].x = *(f32 *)(m + 0x10) + c[3].x;
    pkt.pos[3].y = *(f32 *)(m + 0x14) + c[3].y;
    pkt.pos[3].z = *(f32 *)(m + 0x18) + c[3].z - 1.0f + 1.45f;
    pkt.color[0] = color;
    pkt.color[1] = color;
    pkt.color[2] = color;
    pkt.color[3] = color;
    pkt.uv[0][0] = 0.0f;
    pkt.uv[0][1] = 0.0f;
    pkt.uv[1][0] = 1.0f;
    pkt.uv[1][1] = 0.0f;
    pkt.uv[2][0] = 0.0f;
    pkt.uv[2][1] = 1.0f;
    pkt.uv[3][0] = 1.0f;
    pkt.uv[3][1] = 1.0f;
    func_003D2DA0(&pkt, 0, 1);
}
/* localdecomp:end func_L01_003365C0 */
