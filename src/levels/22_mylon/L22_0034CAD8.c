#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L22_0034CAD8 */
extern s32 D_L22_001F2D80[];
extern s32 D_L22_001E17C8;
__asm__(".extern D_L22_001E17C8, 16");
extern s32 D_L22_001DF8C0;
__asm__(".extern D_L22_001DF8C0, 16");
extern void func_L22_0044A390(void *, s32, s32);
extern void func_L22_0040A500(void *, void *);
extern void func_L22_0034CBD8(char *);

/* from rac2-decomp's func_L11_0045B5C8 */
void func_L22_0034CAD8(char *p) {
    char *q = *(char **)(p + 0x68);
    u16 c;
    s32 v;
    s32 old;
    s32 current;
    if (D_L22_001F2D80[0] != 0) {
        return;
    }
    switch (*(u8 *)(p + 0x20)) {
    case 0:
        *(u8 *)(p + 0x30) = 0xFF;
        func_L22_0044A390(p, 1, -1);
        *(s32 *)(q + 0x0) = 0x1000000;
        *(s32 *)(q + 0x8) = 1;
        *(s32 *)(q + 0x4) = 1;
        break;
    case 1:
        if (*(u16 *)(p + 0x96) >= 0x2D) {
            *(u16 *)(p + 0x96) = 0;
            *(s32 *)(q + 0x4) = -*(s32 *)(q + 0x4);
        }
        v = *(s32 *)(q + 0x8) + *(s32 *)(q + 0x4);
        old = D_L22_001E17C8;
        current = D_L22_001DF8C0;
        *(s32 *)(q + 0x0) = v << 24;
        *(s32 *)(q + 0x8) = v;
        if (old != current) {
            D_L22_001E17C8 = current;
            func_L22_0040A500(func_L22_0034CBD8, p);
        }
        break;
    }
    c = *(u16 *)(p + 0x96);
    if (c <= 0xFFFE) {
        *(u16 *)(p + 0x96) = c + 1;
    }
}
/* localdecomp:end func_L22_0034CAD8 */

/* localdecomp:start func_L22_0034CBD8 */
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

__asm__(".extern D_L22_001DD200, 4");
__asm__(".extern D_L22_001DD230, 4");
__asm__(".extern D_L22_001DD210, 4");
__asm__(".extern D_L22_001DD240, 4");
__asm__(".extern D_L22_001DD280, 4");
extern s32 D_L22_001DD200;
extern s32 D_L22_001DD204;
extern s32 D_L22_001DD230;
extern s32 D_L22_001DD238;
extern s32 D_L22_001DD210;
extern s32 D_L22_001DD240;
extern s32 D_L22_001DD280;
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_0038DC20(void *, f32);
extern void func_0038D640(void *, void *, void *);
extern void func_003D9450(void *, s32, s32, void *, void *, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L22_0034CBD8(char *p) {
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
    pt.x = (f32)(D_L22_001DF8C0 % 500) / 600.0f;
    pt.x = (pt.x + pt.x) * 3.1415927f - 3.1415927f;
    ang = pt;
    func_0038D328(&m1, &ang);
    func_0038D328(&m0, p + 0xF0);
    m0.r[3] = *(vu0_v4 *)(p + 0x10);
    m0.r[3].w = 1.0f;
    func_0038D028(&pt, &m2.r[3], &m0);
    pt.w = 30.0f;
    if (func_0038DC20(&pt, 512.0f) != -1) {
        func_0038D640(&m0, &m0, &m1);
    }
    func_003D9450(&recs[0], D_L22_001DD200, D_L22_001DD230, &D_L22_001DD210, &D_L22_001DD240, 1);
    func_003D9450(&recs[1], D_L22_001DD204, D_L22_001DD238, &D_L22_001DD210, &D_L22_001DD280, 1);
    for (k = 0; k < 4; k++) {
        recs[0].c[k] += *pv;
        recs[1].c[k] += *pv;
    }
    qzero(&ang);
    ang.x = 0.1308997f;
    func_0038D308(&m2, &ang);
    func_0038D5F0(&m3, &m2, &m2);
    for (i = 0; i < 0x30; i++) {
        s = (i & 1) ? 2 : 0;
        for (j = 0; j < 2; j++) {
            func_0038D000(&recs[j].v[s], &recs[j].v[s], &m3);
            func_0038D000(&recs[j].v[s + 1], &recs[j].v[s + 1], &m3);
            func_003D2DA0(&recs[j], &m0, 1);
        }
    }
}
/* localdecomp:end func_L22_0034CBD8 */
