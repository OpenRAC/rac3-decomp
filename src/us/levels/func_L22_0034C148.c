#include "common.h"

/* NTSC-U counterpart of func_L22_0034CBD8 (src/levels/22_mylon/L22_0034CAD8.c) */
#include "vu0.h"
extern s32 D_L22_001DF8C0_0034C148;
extern void func_L22_0034C148(char *);

/* localdecomp:start func_L22_0034C148 */
typedef struct {
    vu0_v4 r[4];
} M4_34CBD8;

typedef struct {
    vu0_v4 r[3];
} M3_34CBD8;

typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    u8 pad50[0x90 - 0x50];
} R_34CBD8;

__asm__(".extern D_L22_001DD240_0034C148, 4");
__asm__(".extern D_L22_001DD270, 4");
__asm__(".extern D_L22_001DD250, 4");
__asm__(".extern D_L22_001DD280_0034C148, 4");
__asm__(".extern D_L22_001DD2C0, 4");
extern s32 D_L22_001DD240_0034C148;
extern s32 D_L22_001DD244;
extern s32 D_L22_001DD270;
extern s32 D_L22_001DD278;
extern s32 D_L22_001DD250;
extern s32 D_L22_001DD280_0034C148;
extern s32 D_L22_001DD2C0;
extern void func_00388BF0(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_003894E8(void *, f32);
extern void func_00388F08(void *, void *, void *);
extern void func_003D3EE0(void *, s32, s32, void *, void *, s32);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern void func_003888C8(void *, void *, void *);
extern void func_003CD830(void *, void *, s32);

void func_L22_0034C148(char *p) {
    M4_34CBD8 m0;
    M4_34CBD8 m1;
    M4_34CBD8 m2;
    R_34CBD8 recs[2];
    vu0_v4 ang;
    vu0_v4 pt;
    M3_34CBD8 m3;
    s32 *pv;
    s32 i;
    s32 j;
    s32 k;
    s32 s;

    pv = *(s32 **)(p + 0x68);
    *(vu0_q *)&pt = 0;
    *(vu0_q *)&m2.r[3] = 0;
    m2.r[3].x = 30.0f;
    m2.r[3].w = 1.0f;
    pt.x = (f32)(D_L22_001DF8C0_0034C148 % 600) / 600.0f;
    pt.x = (pt.x + pt.x) * 3.1415927f - 3.1415927f;
    ang = pt;
    func_00388BF0(&m1, &ang);
    func_00388BF0(&m0, p + 0xF0);
    m0.r[3] = *(vu0_v4 *)(p + 0x10);
    m0.r[3].w = 1.0f;
    func_003888F0(&pt, &m2.r[3], &m0);
    pt.w = 30.0f;
    if (func_003894E8(&pt, 512.0f) != -1) {
        func_00388F08(&m0, &m0, &m1);
    }
    func_003D3EE0(&recs[0], D_L22_001DD240_0034C148, D_L22_001DD270, &D_L22_001DD250, &D_L22_001DD280_0034C148, 1);
    func_003D3EE0(&recs[1], D_L22_001DD244, D_L22_001DD278, &D_L22_001DD250, &D_L22_001DD2C0, 1);
    for (k = 0; k < 4; k++) {
        recs[0].c[k] += *pv;
        recs[1].c[k] += *pv;
    }
    qzero(&ang);
    ang.x = 0.1308997f;
    func_00388BD0(&m2, &ang);
    func_00388EB8(&m3, &m2, &m2);
    for (i = 0; i < 0x30; i++) {
        s = (i & 1) ? 2 : 0;
        for (j = 0; j < 2; j++) {
            func_003888C8(&recs[j].v[s], &recs[j].v[s], &m3);
            func_003888C8(&recs[j].v[s + 1], &recs[j].v[s + 1], &m3);
            func_003CD830(&recs[j], &m0, 1);
        }
    }
}
/* localdecomp:end func_L22_0034C148 */
