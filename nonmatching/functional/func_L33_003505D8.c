/* functional: high. Written from PAL asm, every block read against it; sibling of the matched func_L33_00350470. Needs file flag -mvu0-use-vf0-vf2; not byte-identical (141 diffs, frame size differs). Uses the file's D_L33_001E9600 struct (.pos/.moby) and D_L33_001E1830_00350470 alias. */
#include "common.h"
#include "vu0.h"

extern f32 func_0038DB48(f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern u8 D_001A30B0[];
extern u8 *D_001A71A0[];
extern f32 D_L33_001DD84C;
extern f32 D_L33_001DD850;

void func_L33_003505D8(u8 *a) {
    u8 *st;
    u8 *e;
    u8 *hit;
    s32 h;
    f32 len;
    f32 base[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 v2[4] __attribute__((aligned(16)));
    f32 v3[4] __attribute__((aligned(16)));
    f32 v4[4] __attribute__((aligned(16)));

    st = *(u8 **)(a + 0x68);
    base[0] = 0.0f;
    base[1] = 0.0f;
    base[2] = D_L33_001DD84C;
    base[3] = 0.0f;
    func_L30_0034C8A8(D_L33_001E1830_00350470.obj, a);
    vec_add_ba(a + 0x10, a + 0x10, st);
    *(f32 *)(a + 0xF4) = func_0038DAB8(*(f32 *)(a + 0xF4), func_0038DB48(*(f32 *)st / *(f32 *)(st + 0x20)));
    h = *(s32 *)(st + 0x24);
    if (h == -1 || (e = D_001A30B0 + h * 128, *(u8 **)(e + 0xDC) != a) || e[0xD0] == 0) {
        *(s32 *)(st + 0x24) = func_003A52A0(1, 4, a);
    }
    if (func_L01_003FB640(a + 0x10, 0, *(f32 *)(st + 0x20), a) == 0) {
        vec_add_ab(st, st, base);
        return;
    }
    vec_sub_ba(d, &D_L33_001E9600.pos, a + 0x10);
    d[1] = 0.0f;
    hit = D_L33_001E9600.moby;
    if (hit != 0) {
        if (*(s16 *)(hit + 0xAA) != *(s16 *)(D_001A71A0[0] + 0xAA)) {
            return;
        }
    } else if (!(D_L33_001DD850 * fabs_asm(d[2]) < fabs_asm(d[0]))) {
        func_L02_003BA9F8(st, d, v3, v2);
        *(vu0_q *)st = *(vu0_q *)v2;
        len = func_0038CEA8(d);
        if (len < *(f32 *)(st + 0x20)) {
            len = func_0038CEA8(d);
            func_0038CF68(v4, d, len - *(f32 *)(st + 0x20));
            vec_add_ab(a + 0x10, a + 0x10, v4);
        }
        return;
    }
    h = *(s32 *)(st + 0x24);
    if (h != -1 && (e = D_001A30B0 + h * 128, *(u8 **)(e + 0xDC) == a) && e[0xD0] != 0) {
        func_003A4F28(h);
    }
    *(s32 *)(st + 0x24) = -1;
    func_L33_00350188(a, &D_L33_001E9600.pos);
    func_L01_004450F0(a, 0, -1);
}
