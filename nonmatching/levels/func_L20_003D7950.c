/* PAL near miss (Codex wave 6): held at landing (efcb5824): the C matches PAL at every place, but its NTSC-U counterpart (same code) did not build from it everywhere in the NTSC-U build.
 */
#include "common.h"
/* localdecomp:start func_L20_003D7950 */
#include "vu0.h"
extern s32 D_L20_001E2640[] __attribute__((section(".sdata")));
extern vu0_v4 D_L20_001E2600[] __attribute__((section(".sdata")));
extern vu0_v4 D_L20_002A2940[][20];
extern f32 D_L20_001DEBF8;
extern s32 D_L20_001DEBFC;
extern s32 D_L20_001DEC00;
extern s32 D_L20_001DEC04;
extern f32 D_L20_001DEC08;
extern f32 D_L20_001DEC0C;
typedef struct { u8 pad[0xF8]; u8 *texture; } Tex_003D7950;
extern Tex_003D7950 D_L20_00220258;
typedef struct { u8 pad[2]; u8 b2; u8 b3; s32 color; s32 pad8; f32 scale; } Particle_003D7950;
__asm__(".extern D_L20_001DEBF8, 4");
__asm__(".extern D_L20_001DEBFC, 4");
__asm__(".extern D_L20_001DEC00, 4");
__asm__(".extern D_L20_001DEC04, 4");
__asm__(".extern D_L20_001DEC08, 4");
__asm__(".extern D_L20_001DEC0C, 4");
void func_L20_003D7950(u8 *obj)
{
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_003C4C18(void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern Particle_003D7950 *func_L01_0046CA28(void *, s32, s32, s32);
    extern void func_L20_003D7CE0(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32, s32);
    vu0_v4 points[20];
    vu0_v4 pos;
    vu0_v4 delta;
    s32 i, j, k;
    s32 *count;
    vu0_v4 *out;
    vu0_v4 *last;
    f32 speed = 6.0f;
    f32 len, lim;
    Particle_003D7950 *p;
    pos = *(vu0_v4 *)(obj + 0x10);
    pos.z += 2.0f;
    for (i = 0; i < 4; i++) {
        count = &D_L20_001E2640[i];
        (*count)++;
        if (*count >= 20) *count = 20;
        j = *count - 1;
        k = j;
        if (j > 0) {
        out = points;
        for (; k > 0; k--) {
            *(vu0_q *)&D_L20_002A2940[i][k] = *(vu0_q *)&D_L20_002A2940[i][k-1];
            vec_add_ab(out, &pos, &D_L20_002A2940[i][k]);
            out->w = 0.05f;
            out++;
        }
        }
        func_003C4840(&delta, &D_L20_001E2600[i], speed * 0.017453292f);
        func_0038D850(&D_L20_002A2940[i][0], &D_L20_002A2940[i][0], &delta);
        func_003C4C18(&D_L20_002A2940[i][0], 0.025f);
        len = func_0038CEA8(&D_L20_002A2940[i][0]);
        lim = D_L20_001DEBF8 * 1.1f;
        if (len > lim) {
            func_0038CE20(&D_L20_002A2940[i][0], &D_L20_002A2940[i][0], lim / len);
        } else {
            lim = D_L20_001DEBF8 * 0.9f;
            if (len < lim) func_0038CE20(&D_L20_002A2940[i][0], &D_L20_002A2940[i][0], lim / len);
        }
        vec_add_ab(&points[j], &pos, &D_L20_002A2940[i][0]);
        points[j].w = 0.05f;
        last = (vu0_v4 *)((u8 *)points + ((D_L20_001E2640[i]-1) << 4));
        p = func_L01_0046CA28(last, 2, 0, 1);
        if (p) {
            p->color = D_L20_001DEBFC | 0xA06565;
            p->scale = D_L20_001DEC08 * 210000.0f;
            p->b2 = D_L20_00220258.texture[1];
        }
        p = func_L01_0046CA28(last, 2, 0, 1);
        if (p) {
            p->color = 0x407F7F7F;
            p->scale = D_L20_001DEC08 * 0.15f * 210000.0f;
        }
        func_L20_003D7CE0(points, 20, 15, 15, D_L20_001DEC00,
            D_L20_001DEC00 & 0xFFFFFF, D_L20_001DEC04 | 0xA06565,
            D_L20_001DEC04, 0.02f, 0.07f, D_L20_001DEC0C, 0,
            D_L20_001E2640[i]-1, D_L20_001E2640[i]);
    }
}
/* localdecomp:end func_L20_003D7950 */
