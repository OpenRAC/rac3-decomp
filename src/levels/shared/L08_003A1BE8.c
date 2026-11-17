#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x30];
    u8 v30[0x0E];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x160 - 0x60];
    u8 v160[0x304 - 0x160];
    s32 i304;
    f32 f308;
} S_Vars3A1638;
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; S_Vars3A1638 *vars;
} S_Moby3A1638;
typedef struct {
    u8 pad0[16];
    u8 pos[33];
    u8 b49;
    u8 pad32[61];
    u8 b111;
    u8 pad70[38];
    u16 h150;
} Moby_3A1DD8;

/* localdecomp:start func_L08_003A1BE8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A1BE8;
extern V4_003A1BE8 D_001A4C60;
extern u8 D_L08_001D66B0[8];
extern f32 D_L08_001DE240;
__asm__(".extern D_L08_001DE240, 4");
extern s32 D_L08_001DE260;
__asm__(".extern D_L08_001DE260, 4");
extern s32 D_L08_001DE264;
__asm__(".extern D_L08_001DE264, 4");
extern s32 D_L08_001DE268;
__asm__(".extern D_L08_001DE268, 4");
extern s32 D_L08_001DE26C;
__asm__(".extern D_L08_001DE26C, 4");
extern s32 D_L08_001DE270;
__asm__(".extern D_L08_001DE270, 4");
extern s32 D_L08_001DE274;
__asm__(".extern D_L08_001DE274, 4");
extern s32 D_L08_001DE278;
__asm__(".extern D_L08_001DE278, 4");
extern s32 D_L08_001DE27C;
__asm__(".extern D_L08_001DE27C, 4");
extern s32 D_L08_001DE280;
__asm__(".extern D_L08_001DE280, 4");
extern f32 D_L08_001DE284;
__asm__(".extern D_L08_001DE284, 4");
extern f32 D_L08_001DE288;
__asm__(".extern D_L08_001DE288, 4");
extern f32 D_L08_001DE28C;
__asm__(".extern D_L08_001DE28C, 4");
extern f32 D_L08_001DE290;
__asm__(".extern D_L08_001DE290, 4");

extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004739D8(void *, void *, s32, s32, s16, u8, f32);
extern void func_L08_003AA088(void *, void *, void *, f32, f32);
extern void func_L08_003A17C0(void *, void *, void *);

void func_L08_003A1BE8(u8 *m, u8 *t) {
    V4_003A1BE8 d;
    V4_003A1BE8 x;
    V4_003A1BE8 rot;
    V4_003A1BE8 unused; /* never used: retail's frame has a dead 16-byte slot at 0x40 */
    V4_003A1BE8 pos;
    V4_003A1BE8 tmp;
    s32 i;
    s32 c1, c2;
    f32 g, f;

    vec_sub_ab(&d, &D_001A4C60, m + 0x10);
    func_0038CF68(&d, &d, 1.0f);
    rot = *(V4_003A1BE8 *)(m + 0xE0);
    func_0038CE90(&x, &rot, &d);
    for (i = 0; i < 10; i++) {
        func_0038CE20(&tmp, &rot, func_L01_00443A18(0.0f, 0.5f));
        vec_add_ab(&pos, &tmp, &d);
        func_0038CE20(&tmp, &x, func_L01_00443A18(0.0f, 0.5f));
        vec_add_ab(&pos, &tmp, &pos);
        func_0038CE20(&pos, &pos, func_003824E0(D_L08_001DE290 * 0.4f, D_L08_001DE290) * 0.020000001f);
        c1 = func_0038DBD8(D_L08_001DE260, D_L08_001DE268, func_003824E0(0.0f, 1.0f));
        c2 = func_0038DBD8(D_L08_001DE264, D_L08_001DE26C, func_003824E0(0.0f, 1.0f));
        g = func_003824E0((f32)D_L08_001DE278 * 0.5f, (f32)D_L08_001DE278 * 2.5f);
        func_L01_00463378(t, &pos, D_L08_001D66B0, c1, c2, (D_L08_001DE270 * 5 + 2) / 6, (D_L08_001DE274 * 5 + 2) / 6,
            (s32)((g * 5.0f + 2.0f) / 6.0f), -1);
        func_0038CE20(&pos, &pos, func_003824E0(1.5f, 2.5f));
        f = func_003824E0(D_L08_001DE284, D_L08_001DE288) * 210000.0f;
        func_L01_004739D8(t, &pos, D_L08_001DE27C, D_L08_001DE280, (func_00382498(0x78, 0xF0) * 5 + 2) / 6, 0, f);
    }
    func_0038CE20(&tmp, &rot, func_L01_00443A18(0.0f, 0.75f));
    vec_add_ab(&pos, &tmp, &d);
    func_0038CE20(&tmp, &x, func_L01_00443A18(0.0f, 0.5f));
    vec_add_ab(&pos, &tmp, &pos);
    func_0038CE20(&pos, &pos, func_003824E0(D_L08_001DE28C * 0.7f, D_L08_001DE28C) * 0.020000001f);
    func_L08_003AA088(t, &pos, m, 0.0f, D_L08_001DE240);
    func_L08_003A17C0(m, t, &d);
}
/* localdecomp:end func_L08_003A1BE8 */

INCLUDE_ASM("asm/levels", func_L08_003A1FA0);
