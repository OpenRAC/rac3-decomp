#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct V_003A8330 {
    f32 x, z, y, w;
} __attribute__((aligned(16))) V_003A8330;

/* localdecomp:start func_L08_003A9B08 */
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

extern void func_L08_003AA300(M_003A9B08 *);
extern void func_L08_003AA1F8(M_003A9B08 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_00382538(void);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 D_L01_001D66B0[8];
extern u8 *D_L08_0021ECBC[];
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004739D8(void *, void *, s32, s32, s16, u8, f32);
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

extern f32 D_L08_001DE2AC;
__asm__(".extern D_L08_001DE2AC, 4");
extern s32 D_L08_001DE2B4;
__asm__(".extern D_L08_001DE2B4, 4");
extern s32 D_L08_001DE2B8;
__asm__(".extern D_L08_001DE2B8, 4");
extern f32 D_L08_001DE2BC;
__asm__(".extern D_L08_001DE2BC, 4");
extern f32 D_L08_001DE2C0;
__asm__(".extern D_L08_001DE2C0, 4");
extern f32 D_L08_001DE2C4;
__asm__(".extern D_L08_001DE2C4, 4");
extern f32 D_L08_001DE2C8;
__asm__(".extern D_L08_001DE2C8, 4");
extern f32 D_L08_001DE2CC;
__asm__(".extern D_L08_001DE2CC, 4");
extern f32 D_L08_001DE2D0;
__asm__(".extern D_L08_001DE2D0, 4");
extern f32 D_L08_001DE2D4;
__asm__(".extern D_L08_001DE2D4, 4");
extern f32 D_L08_001DE2D8;
__asm__(".extern D_L08_001DE2D8, 4");
extern f32 D_L08_001DE2DC;
__asm__(".extern D_L08_001DE2DC, 4");
extern f32 D_L08_001DE2E0;
__asm__(".extern D_L08_001DE2E0, 4");
extern s32 D_L08_001DE2E4;
__asm__(".extern D_L08_001DE2E4, 4");
extern s32 D_L08_001DE2E8;
__asm__(".extern D_L08_001DE2E8, 4");
extern s32 D_L08_001DE2EC;
__asm__(".extern D_L08_001DE2EC, 4");
extern s32 D_L08_001DE2F0;
__asm__(".extern D_L08_001DE2F0, 4");
extern s32 D_L08_001DE2F4;
__asm__(".extern D_L08_001DE2F4, 4");
extern s32 D_L08_001DE2F8;
__asm__(".extern D_L08_001DE2F8, 4");
extern s32 D_L08_001DE2FC;
__asm__(".extern D_L08_001DE2FC, 4");
extern s32 D_L08_001DE300;
__asm__(".extern D_L08_001DE300, 4");
extern f32 D_L08_001DE304;
__asm__(".extern D_L08_001DE304, 4");

void func_L08_003A9B08(M_003A9B08 *m) {
    V_003A9B08 pos;
    V_003A9B08 vel;
    V_003A9B08 end;
    f32 *vars = m->vars;
    s32 i, j, c1, c2;

    switch (m->state) {
    case 0: {
        u8 *p;
        f32 speed;

        func_L08_003AA300(m);
        m->rot0 = func_0038DAB8(m->rot0, 0.25132743f);
        m->rot1 = func_0038DAB8(m->rot1, 0.2967059910297394f);
        func_L08_003AA1F8(m);
        func_0038CE20(&pos, vars, -0.75f);
        p = func_L01_0046A610(&m->pos, D_L01_001D66B0, 5, 0x2F, 0xFF90, (s32)func_00382538(), 157500.0f, -1000.0f, 0.95f, 0.0f, 0.0f);
        if (p != 0) {
            p[2] = D_L08_0021ECBC[0][0];
        }
        p = func_L01_0046A610(&m->pos, D_L01_001D66B0, 5, 0x2F, 0x10A182, (s32)func_00382538(), 126000.0078125f, -1000.0f, 0.95f, 0.0f, 0.0f);
        if (p != 0) {
            p[2] = D_L08_0021ECBC[0][0];
        }
        if (func_00382468(3) == 0) {
            vu0_q q;
            __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
            __asm__("sqc2 %1, %0" : "=m"(vel) : "j"(q));
            func_0038CF68(&vel, &vel, -func_003824E0(0.1f, 0.2f));
            speed = func_003824E0(0.75f, 0.8f) * 210000.0f;
            func_L01_004739D8(&m->pos, &vel, 0x6412A182, 0x12A178, (func_00382498(120, 240) * 5 + 2) / 6, 0, speed);
        }
        break;
    }
    case 1: {
        u8 *p;
        f32 angle, speed, z, r, len;

        if (vars[8] > 0.0f) {
            func_L01_00446780(m, &m->pos, 1, 0, 1, 0, D_L08_001DE2AC, vars[8], 1.0f);
        }
        for (i = 0; i < D_L08_001DE2B4; i++) {
            *(u128_t *)&pos = m->pos;
            func_003C4C18(&pos, D_L08_001DE2BC);
            angle = func_00382538();
            speed = func_003824E0(D_L08_001DE2C8, D_L08_001DE2CC);
            z = func_003824E0(D_L08_001DE2D0, D_L08_001DE2D4);
            speed *= 0.020000001415610313f;
            len = func_003824E0(0.0f, D_L08_001DE304) * 0.020000001415610313f;
            func_0038CE20(&vel, D_L01_001D66B0, len);
            vel.x += func_0038D098(angle) * speed;
            vel.y += func_0038D0B0(angle) * speed;
            vel.z += z * 0.020000001415610313f;
            end = vel;
            end.z -= D_L08_001DE2D8 * 0.0004000000189989805f * (f32)((D_L08_001DE2F8 * 5 + 2) / 6);
            for (j = 0; j < D_L08_001DE2B8; j++) {
                r = func_003824E0(0.5f, 1.5f);
                vel.w = r * D_L08_001DE2DC;
                end.w = r * D_L08_001DE2E0;
                func_003C4C18(&pos, D_L08_001DE2C0);
                func_003C4C18(&end, D_L08_001DE2C4 * 0.020000001415610313f);
                c1 = func_0038DBD8(D_L08_001DE2E4, D_L08_001DE2EC, func_003824E0(0.0f, 1.0f));
                c2 = func_0038DBD8(D_L08_001DE2E8, D_L08_001DE2F0, func_003824E0(0.0f, 1.0f));
                p = func_L01_00463378(&pos, &vel, &end, c1, c2, (D_L08_001DE2F4 * 5 + 2) / 6, (D_L08_001DE2F8 * 5 + 2) / 6,
                                      (s32)((func_003824E0((f32)D_L08_001DE2FC, (f32)D_L08_001DE300) * 5 + 2) / 6), -1);
                if (p != 0 && func_00382468(2) != 0) {
                    p[3] = 0x48;
                }
            }
        }
        func_003C2880(m);
        break;
    }
    }
}
/* localdecomp:end func_L08_003A9B08 */
