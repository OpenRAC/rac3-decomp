#include "common.h"

/* NTSC-U counterpart of func_L39_00548130 (src/levels/shared/L39_00548130.c) */
/* localdecomp:start func_L39_00547818 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00548130;

extern void func_00389158(void *, void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003BF2F8(void *, void *, f32);
extern void func_00389118(void *, void *, void *);
extern f32 func_L39_005B25C8_00547818(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L01_00445C50(u32, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_005C5838(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L39_00547818(u8 *self, V4_00548130 *pos) {
    V4_00548130 q;
    V4_00548130 dir;
    V4_00548130 up = { 0.3f, -1.0f, 0.0f };
    V4_00548130 center;
    V4_00548130 step;
    V4_00548130 p60;
    V4_00548130 drift;
    V4_00548130 off;
    V4_00548130 p90;
    u8 *p;
    f32 ang;
    f32 life;
    f32 scale;
    s32 i;
    s32 j;
    s32 n;
    u8 *e;
    u8 *sub;

    up.w = 1.0f;
    ang = 0.0f;
    p = *(u8 **)(*(u8 **)(self + 0x68) + 0x50);
    if (p == 0) {
        return;
    }
    center = *pos;
    func_00389158(&up, p + 0x380, p + 0x390, 0.34906584f);
    dir = up;
    qzero(&drift);
    if (*(s32 *)(p + 0x2D0) != 0) {
        func_003886E8(&drift, p + 0x140, 1.7f);
    }
    func_003886E8(&off, p + 0x380, 0.4f);
    vec_add_ab(&center, &center, &off);
    for (i = 0; i < 20; i++) {
        ang = func_00389380(ang, func_L39_005B2510(0.0f, 0.62831855f));
        func_003886E8(&step, &dir, func_L39_005B2510(0.20000001788f, 0.2666666806f));
        vec_add_ab(&step, &step, &drift);
        p60.x = center.x + func_L39_005B2568(0.0f, 0.3f);
        p60.y = center.y + func_L39_005B2568(0.0f, 0.3f);
        p60.z = center.z + func_L39_005B2568(0.0f, 0.3f);
        n = func_L39_005B2568(1.0f, 2.0f);
        e = func_L01_004633E8(&p60, 0.0f, 1.0f, 1.01f, func_L39_005B2510(0.2f, 0.75f) * 210000.0f,
                              n, p + 0x140, 0x7F202020, 0);
        if (e != 0) {
            e[3] = 0x44;
            *(s16 *)(e + 0xA) = 60;
            e[9] = 0x44;
            sub = e + 0x20;
            *(f32 *)(sub + 0x1C) = 5.0f;
            *(s32 *)(sub + 0x4) = 3;
            sub[0xA] = 0x30;
            sub[0xB] = e[0xA];
        }
        p60.x = center.x + func_L39_005B2568(0.0f, 0.6f);
        p60.y = center.y + func_L39_005B2568(0.0f, 0.6f);
        p60.z = center.z + func_L39_005B2568(0.0f, 0.6f);
        life = func_L39_005B2510(0.2f, 1.75f);
        vec_sub_ab(&p60, &p60, &step);
        func_L01_00466F98(&p60, &step, 6, 0x7F, 0x404040, n, life * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
        if (fabs_asm(ang) > 1e-5f) {
            func_003BF2F8(&q, p + 0x380, ang);
            func_00389118(&dir, &up, &q);
        }
    }
    func_003886E8(&up, p + 0x380, func_L39_005B2510(8.0f, 12.0f) * 0.0166666675f);
    scale = 0.5f;
    for (j = 0; j < 2; j++) {
        f32 pitch = func_L39_005B2510(0.2617994f, 1.3962634f);
        f32 yaw = func_L39_005B25C8_00547818();
        func_0037E4B8(&p90, scale * (func_L39_005B2510(7.0f, 10.5f) * 0.0166666675f), yaw, pitch);
        vec_add_ab(&p90, &p90, &up);
        p90.z += 0.05000000447f;
        {
            s32 c0 = func_L01_00445C50(0x4F007FFF, 0);
            s32 c1 = func_L01_00445C50(0x1F00007F, 0);
            func_L39_005C5838(pos, &p90, c0, c1, func_L39_005B24C8(60, 120), 1, -1, -1, 0, scale * 40000.0f);
        }
    }
}
/* localdecomp:end func_L39_00547818 */
