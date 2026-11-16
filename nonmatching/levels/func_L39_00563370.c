/* NTSC-U draft (Claude wave K): C of func_L39_00562850, the NTSC-U twin of func_L39_00563370, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 97 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00562850", whose code is not the PAL one).
 * Worker's note: best 97 diff (138 first draft). Needs -mvu0-use-vf0-vf2 (vec_add_ba; PAL flags lack it) so cannot land anyway. Blocker: saved-reg allocation - retail has 8 s-regs (s0 p0 then g, s1 arg0 then g+0x3C0, s2 moby, s3 sub, s4/s5 = m+0xD0/0xE0, s6/s7 = ...
 */
#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"

/* localdecomp:start func_L39_00562850 */
extern f32 D_001DFD98_sda;
__asm__(".extern D_001DFD98_sda, 4");
extern f32 D_001E1F84_sda;
__asm__(".extern D_001E1F84_sda, 4");
extern u8 D_L39_003CD080[];
extern u128_t D_L39_0024D740;
extern u128_t D_L39_0024D750;
extern u128_t D_L39_0024D760;
extern u8 D_L39_0024D770[];
extern s32 D_L39_0024D780[];
extern s32 D_L39_0024D790[];
extern s16 D_L39_0024D7D0[];
extern u8 *func_003BCFB0(s32, s32);
extern void func_00388BD0(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_L01_004C5830(s32);
extern f32 func_L01_004C5828(void);
extern void func_L39_005F0CE0(s32, s32, void *);

u8 *func_L39_00562850(u8 *arg0) {
    u8 *m;
    u8 *d;
    u8 *g;
    u8 *v;
    u8 *p0;
    u8 *p1;
    u8 *p2;
    s16 *h;
    s32 *w;
    s32 i;

    m = func_003BCFB0(0x1B37, 0x80);
    if (m != 0) {
        d = *(u8 **)(m + 0x68);
        p0 = m + 0xC0;
        *(u8 **)(d + 0x40) = arg0;
        m[0x30] = 0xFF;
        m[0x20] = 1;
        *(u16 *)(m + 0x34) |= 0x41;
        p2 = m + 0xE0;
        p1 = m + 0xD0;
        func_00388BD0(p0, m + 0xF0);
        for (i = 3; i >= 0; i--) {
            D_L39_0024D780[i] = 0;
        }
        g = D_L39_003CD080;
        v = g + 0x3C0;
        h = (s16 *)(d + 0x18);
        w = (s32 *)(d + 0x20);
        func_00388830(g, p0, D_001DFD98_sda);
        D_L39_0024D740 = *(u128_t *)(m + 0xE0);
        func_00388830(g + 0x140, p1, D_001DFD98_sda);
        D_L39_0024D750 = *(u128_t *)(m + 0xC0);
        func_00388830(g + 0x280, p2, D_001DFD98_sda);
        D_L39_0024D760 = *(u128_t *)(m + 0xD0);
        vec_add_ba(v, p0, p2);
        func_00388830(v, v, D_001DFD98_sda);
        func_00388758(D_L39_0024D770, v, p1);
        for (i = 7; i >= 0; i--) {
            D_L39_0024D790[i] = 0;
        }
        for (i = 4; i >= 0; i--) {
            D_L39_0024D7D0[i] = 0;
        }
        D_001E1F84_sda = 1.0f;
        func_L01_004C5830(0);
        *(f32 *)d = func_L01_004C5828();
        *(u128_t *)(m + 0x10) = *(u128_t *)(*(u8 **)(d + 0x40) + 0xA0);
        *(s32 *)(d + 0x14) = 0x1E;
        *(s32 *)(d + 0xC) = -1;
        *(s32 *)(d + 0x10) = 0;
        for (i = 3; i >= 0; i--) {
            h[i] = 0;
        }
        for (i = 3; i >= 0; i--) {
            w[i] = 0;
        }
        func_L39_005F0CE0(1, 0, m);
    }
    return m;
}
/* localdecomp:end func_L39_00562850 */
