#include "common.h"

/* localdecomp:start func_L39_0056F368 */
#include "vu0.h"

typedef struct {
    vu0_q pos;
    u8 pad10[0x30];
    vu0_q pos2;
    u8 pad50[0x20];
    u8 *unk70;
    u8 pad74[0x20];
    s32 idx;
    f32 unk98;
} Moby_0056F368;

typedef struct {
    u8 pad0[0x1C0];
    vu0_v4 unk1C0;
    u8 pad1D0[0x410 - 0x1D0];
    vu0_v4 unk410;
    u8 pad420[0x460 - 0x420];
} Cam_0056F368;

typedef struct {
    u8 pad0[0xA4];
    u8 unkA4[1];
} G_0056F368;

extern G_0056F368 D_001A5810;
extern s32 D_001A5990[][8];
extern f32 D_L39_00242398_0056F368[] __attribute__((section(".sdata")));
extern Cam_0056F368 D_L39_0024DE80_0056F368[];
extern s32 D_L39_002429BC_0056F368;
__asm__(".extern D_L39_002429BC_0056F368, 16");
extern s32 D_L39_0024B680_0056F368;
__asm__(".extern D_L39_0024B680_0056F368, 4");
extern f32 D_L39_0024B684_0056F368;
__asm__(".extern D_L39_0024B684_0056F368, 4");
extern f32 D_L39_0024B6EC_0056F368;
__asm__(".extern D_L39_0024B6EC_0056F368, 4");

extern void func_L39_005B8170_0056F368(void *, Moby_0056F368 *);
extern u8 *func_L39_0061BF38_0056F368(s32);
extern f32 func_L39_005914C8_0056F368(f32, f32);
extern void func_L39_00569510_0056F368(Moby_0056F368 *, void *);
extern void func_L39_0056B080_0056F368(Moby_0056F368 *);
extern void func_L39_0056A7B8_0056F368(Moby_0056F368 *);
extern void func_L39_0056F300_0056F368(Moby_0056F368 *);
extern void func_L39_0056ADB0_0056F368(Moby_0056F368 *);
extern void func_L39_005910D8_0056F368(void *, void *, void *, f32);
extern void func_L39_00591240_0056F368(void *, void *);
extern void func_L39_00590F60_0056F368(Moby_0056F368 *, void *);

void func_L39_0056F368(Moby_0056F368 *m)
{
    vu0_v4 q0;
    vu0_v4 q1;
    vu0_v4 q2;
    vu0_v4 v;
    vu0_v4 pos;
    vu0_v4 *src;
    f32 mat[16];
    u8 *p;
    s32 i;
    f32 d;
    f32 f;

    p = m->unk70 + 0x60;
    func_L39_005B8170_0056F368(&q0, m);
    i = *(s32 *)(func_L39_0061BF38_0056F368(m->idx) + 0x2544);
    D_L39_00242398_0056F368[m->idx] =
        ((f32)D_001A5990[D_001A5810.unkA4[i]][i] / 100.0f) * 0.0567232035f + 0.021816615f;
    src = &D_L39_0024DE80_0056F368[m->idx].unk1C0;
    pos = *src;
    d = pos.z - m->unk98;
    if (d > 0.0f) {
        if (d > D_L39_0024B6EC_0056F368 * 0.0200000014f) {
            d = D_L39_0024B6EC_0056F368 * 0.0200000014f;
        }
    } else if (d < 0.0f) {
        if (d < -(D_L39_0024B6EC_0056F368 * 0.0200000014f)) {
            d = -(D_L39_0024B6EC_0056F368 * 0.0200000014f);
        }
    }
    m->unk98 = m->unk98 + d;
    if (pos.z == 0.0f) {
        if (fabsf(m->unk98) <= D_L39_0024B6EC_0056F368 * 0.0200000014f) {
            m->unk98 = 0.0f;
        }
    }
    pos.z = m->unk98;
    vec_add_ab(&v, &pos, &D_L39_0024DE80_0056F368[m->idx].unk410);
    f = D_L39_0024DE80_0056F368[m->idx].unk1C0.w;
    if (D_L39_002429BC_0056F368 != 0) {
        f = 0.0f;
    }
    v.w = func_L39_005914C8_0056F368(f, D_L39_0024DE80_0056F368[m->idx].unk410.w);
    func_L39_00569510_0056F368(m, &v);
    func_L39_0056B080_0056F368(m);
    func_L39_0056A7B8_0056F368(m);
    func_L39_0056F300_0056F368(m);
    func_L39_0056ADB0_0056F368(m);
    if ((s8)p[0x10F] > 0) {
        p[0x10F]--;
        func_L39_005B8170_0056F368(&q2, m);
        func_L39_005910D8_0056F368(&q1, &q0, &q2,
            D_L39_0024B684_0056F368 + (1.0f - D_L39_0024B684_0056F368) * (1.0f - (f32)(s8)p[0x10F] / (f32)D_L39_0024B680_0056F368));
        func_L39_00591240_0056F368(&q1, mat);
        func_L39_00590F60_0056F368(m, mat);
        m->pos2 = m->pos;
    } else {
        p[0x10E] = 0;
    }
}
/* localdecomp:end func_L39_0056F368 */
