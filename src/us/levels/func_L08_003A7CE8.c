#include "common.h"

/* NTSC-U counterpart of func_L08_003A9B08 (src/levels/shared/L08_003A9B08.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L08_003A7CE8 */
#include "vu0.h"

typedef struct V_003A9B08 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A9B08;

typedef struct M_003A9B08 {
    u8 pad0[0x10];
    u128_t pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    f32 *vars;
    u8 pad6C[0xF0 - 0x6C];
    f32 rot0;
    f32 rot1;
} M_003A9B08;

extern void func_L08_003A8420(M_003A9B08 *);
extern void func_L08_003A8330(M_003A9B08 *);
extern f32 func_00389380(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_0037E2A8(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 D_L08_001D66B0_003A7CE8[8];
extern u8 *D_L08_0021ECBC_003A7CE8[];
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00470258(void *, void *, f32, s32, s32, s16, s32);
extern void func_L01_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern u8 *func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);

extern f32 D_L08_001DE2EC_003A7CE8;
__asm__(".extern D_L08_001DE2EC_003A7CE8, 4");
extern s32 D_L08_001DE2F4_003A7CE8;
__asm__(".extern D_L08_001DE2F4_003A7CE8, 4");
extern s32 D_L08_001DE2F8_003A7CE8;
__asm__(".extern D_L08_001DE2F8_003A7CE8, 4");
extern f32 D_L08_001DE2FC_003A7CE8;
__asm__(".extern D_L08_001DE2FC_003A7CE8, 4");
extern f32 D_L08_001DE300_003A7CE8;
__asm__(".extern D_L08_001DE300_003A7CE8, 4");
extern f32 D_L08_001DE304_003A7CE8;
__asm__(".extern D_L08_001DE304_003A7CE8, 4");
extern f32 D_L08_001DE308;
__asm__(".extern D_L08_001DE308, 4");
extern f32 D_L08_001DE30C;
__asm__(".extern D_L08_001DE30C, 4");
extern f32 D_L08_001DE310;
__asm__(".extern D_L08_001DE310, 4");
extern f32 D_L08_001DE314;
__asm__(".extern D_L08_001DE314, 4");
extern f32 D_L08_001DE318;
__asm__(".extern D_L08_001DE318, 4");
extern f32 D_L08_001DE31C;
__asm__(".extern D_L08_001DE31C, 4");
extern f32 D_L08_001DE320;
__asm__(".extern D_L08_001DE320, 4");
extern s32 D_L08_001DE324;
__asm__(".extern D_L08_001DE324, 4");
extern s32 D_L08_001DE328;
__asm__(".extern D_L08_001DE328, 4");
extern s32 D_L08_001DE32C;
__asm__(".extern D_L08_001DE32C, 4");
extern s32 D_L08_001DE330;
__asm__(".extern D_L08_001DE330, 4");
extern s32 D_L08_001DE334;
__asm__(".extern D_L08_001DE334, 4");
extern s32 D_L08_001DE338;
__asm__(".extern D_L08_001DE338, 4");
extern s32 D_L08_001DE33C;
__asm__(".extern D_L08_001DE33C, 4");
extern s32 D_L08_001DE340;
__asm__(".extern D_L08_001DE340, 4");
extern f32 D_L08_001DE344;
__asm__(".extern D_L08_001DE344, 4");

void func_L08_003A7CE8(M_003A9B08 *m) {
    V_003A9B08 pos;
    V_003A9B08 vel;
    V_003A9B08 end;
    f32 *vars = m->vars;
    s32 i, j, c1, c2;

    switch (m->state) {
    case 0: {
        u8 *p;
        f32 speed;

        func_L08_003A8420(m);
        m->rot0 = func_00389380(m->rot0, 0.20943953f);
        m->rot1 = func_00389380(m->rot1, 0.24725498f);
        func_L08_003A8330(m);
        func_003886E8(&pos, vars, -0.75f);
        p = func_L01_00466F98(&m->pos, D_L08_001D66B0_003A7CE8, 6, 0x2F, 0xFF90, (s32)func_0037E2A8(), 157500.0f, -1000.0f, 0.95f, 0.0f, 0.0f);
        if (p != 0) {
            p[2] = D_L08_0021ECBC_003A7CE8[0][0];
        }
        p = func_L01_00466F98(&m->pos, D_L08_001D66B0_003A7CE8, 6, 0x2F, 0x10A182, (s32)func_0037E2A8(), 126000.0078125f, -1000.0f, 0.95f, 0.0f, 0.0f);
        if (p != 0) {
            p[2] = D_L08_0021ECBC_003A7CE8[0][0];
        }
        if (func_0037E1D8(3) == 0) {
            vu0_q q;
            __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
            __asm__("sqc2 %1, %0" : "=m"(vel) : "j"(q));
            func_00388830(&vel, &vel, -func_0037E250(0.1f, 0.2f));
            speed = func_0037E250(0.75f, 0.8f) * 210000.0f;
            func_L01_00470258(&m->pos, &vel, speed, 0x6412A182, 0x12A178, func_0037E208(120, 240), 0);
        }
        break;
    }
    case 1: {
        u8 *p;
        f32 angle, speed, z, r, len;

        if (vars[8] > 0.0f) {
            func_L01_00443648(m, &m->pos, 1, 0, 1, 0, D_L08_001DE2EC_003A7CE8, vars[8], 1.0f);
        }
        for (i = 0; i < D_L08_001DE2F4_003A7CE8; i++) {
            *(u128_t *)&pos = m->pos;
            func_003BF6A8(&pos, D_L08_001DE2FC_003A7CE8);
            angle = func_0037E2A8();
            speed = func_0037E250(D_L08_001DE308, D_L08_001DE30C);
            z = func_0037E250(D_L08_001DE310, D_L08_001DE314);
            speed *= 0.016666668f;
            len = func_0037E250(0.0f, D_L08_001DE344) * 0.016666668f;
            func_003886E8(&vel, D_L08_001D66B0_003A7CE8, len);
            vel.x += func_00388960(angle) * speed;
            vel.y += func_00388978(angle) * speed;
            vel.z += z * 0.016666668f;
            end = vel;
            end.z -= D_L08_001DE318 * 0.00027777778f * (f32)D_L08_001DE338;
            for (j = 0; j < D_L08_001DE2F8_003A7CE8; j++) {
                r = func_0037E250(0.5f, 1.5f);
                vel.w = r * D_L08_001DE31C;
                end.w = r * D_L08_001DE320;
                func_003BF6A8(&pos, D_L08_001DE300_003A7CE8);
                func_003BF6A8(&end, D_L08_001DE304_003A7CE8 * 0.016666668f);
                c1 = func_003894A0(D_L08_001DE324, D_L08_001DE32C, func_0037E250(0.0f, 1.0f));
                c2 = func_003894A0(D_L08_001DE328, D_L08_001DE330, func_0037E250(0.0f, 1.0f));
                p = func_L01_0045FEC8(&pos, &vel, &end, c1, c2, D_L08_001DE334, D_L08_001DE338,
                                      (s32)func_0037E250((f32)D_L08_001DE33C, (f32)D_L08_001DE340), -1);
                if (p != 0 && func_0037E1D8(2) != 0) {
                    p[3] = 0x48;
                }
            }
        }
        func_003BD360(m);
        break;
    }
    }
}
/* localdecomp:end func_L08_003A7CE8 */
