#include "common.h"

/* declared by functions of L35_003A5780.c, which this file was cut from */
extern f32 func_0038D098(f32);
void func_L35_003A5978(void *);

/* localdecomp:start func_L35_003A5978 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A5978;
typedef struct {
    u8 pad00[0x10];
    V_003A5978 pos;
    u8 pad20[0xE0];
} M_003A5978;
typedef struct {
    u8 pad00[0x10];
    V_003A5978 pts[1];
} P_003A5978;
typedef struct {
    u8 pad00[0x48];
    f32 f48;
    u8 pad4C[4];
    f32 f50;
    u8 pad54[4];
    f32 f58;
    u8 pad5C[4];
    V_003A5978 *f60;
    u8 pad64[4];
    P_003A5978 *f68;
    u8 pad6C[4];
    s32 f70;
    s32 f74;
} S_003A5978;
extern u8 D_001A4BE0[];
__asm__(".extern D_L35_001DF89C, 16");
extern M_003A5978 *D_L35_001DF89C;
extern V_003A5978 D_L35_001E2500;
__asm__(".extern D_L35_001DEAB0, 4");
extern s32 D_L35_001DEAB0;
__asm__(".extern D_L35_001DEAB4, 4");
extern s32 D_L35_001DEAB4;
__asm__(".extern D_L35_001DEAB8, 4");
extern s32 D_L35_001DEAB8;
__asm__(".extern D_L35_001DEABC, 4");
extern f32 D_L35_001DEABC;
__asm__(".extern D_L35_001DEAC0, 4");
extern f32 D_L35_001DEAC0;
__asm__(".extern D_L35_001DEAC4, 4");
extern f32 D_L35_001DEAC4;
__asm__(".extern D_L35_001DEAC8, 4");
extern f32 D_L35_001DEAC8;
__asm__(".extern D_L35_001DEACC, 4");
extern f32 D_L35_001DEACC;
__asm__(".extern D_L35_001DEAD0, 4");
extern f32 D_L35_001DEAD0;
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern void func_L35_003A5878(void *, f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_003C4088(f32, f32, f32);

static __inline__ void vcopy_003A5978(V_003A5978 *d, V_003A5978 *s) { *(vu0_q *)d = *(vu0_q *)s; }
void func_L35_003A5978(void *arg0) {
    S_003A5978 *s = *(S_003A5978 **)((u8 *)arg0 + 0x68);
    u8 *hero;
    f32 v[4];
    f32 mid;
    s32 i;
    s32 k;
    M_003A5978 *p;
    M_003A5978 *q;

    func_L30_0034CDC0(&v[0], &v[1], &v[2], &v[3], 1.0f);
    hero = D_001A4BE0;
    mid = (v[0] + v[1]) * 0.5f;
    qzero(&s->f60[0]);
    s->f60[0].x = fabs_asm(v[1] - mid);
    qzero(&s->f60[1]);
    s->f60[1].y = fabs_asm(D_L35_001DEAC4) * 0.5f;
    qzero(&s->f60[2]);
    s->f60[2].z = D_L35_001DEACC * 0.5f;
    s->f60[3].x = mid;
    s->f60[3].y = *(f32 *)(hero + 0x84) + D_L35_001DEABC + D_L35_001DEAC4 * 0.5f;
    s->f60[3].z = s->f48;
    s->f60[3].w = 1.0f;
    qzero(&s->f60[4]);
    s->f60[4].x = 1.0f / s->f60[0].x;
    qzero(&s->f60[5]);
    s->f60[5].y = 1.0f / s->f60[1].y;
    qzero(&s->f60[6]);
    s->f60[6].z = 1.0f / s->f60[2].z;
    qzero(&s->f60[7]);

    p = &D_L35_001DF89C[s->f74];
    *(vu0_q *)&p->pos = *(vu0_q *)&D_L35_001E2500;
    p->pos.z -= 1.0f;
    q = &D_L35_001DF89C[s->f70];
    *(vu0_q *)&q->pos = *(vu0_q *)&D_L35_001E2500;
    q->pos.z -= 1.0f;
    func_L35_003A5878(q, s->f58, s->f50);

    for (k = 0; k < D_L35_001DEAB8; k += 2) {
        u8 *h = D_001A4BE0;
        s->f68->pts[k].x = v[0] - 5.0f;
        s->f68->pts[k].y = *(f32 *)(h + 0x84) + 8.0f + D_L35_001DEAC8 * ((f32)k / (f32)D_L35_001DEAB4);
        s->f68->pts[k].z = s->f48;
        vcopy_003A5978(&s->f68->pts[k + 1], &s->f68->pts[k]);
        s->f68->pts[k + 1].x = v[1] + 5.0f;
    }
    for (i = 0; i < D_L35_001DEAB0; i += 2) {
        u8 *h = D_001A4BE0;
        k = D_L35_001DEAB8 + i;
        s->f68->pts[k].x = v[0];
        s->f68->pts[k].y = *(f32 *)(h + 0x84) + D_L35_001DEABC + D_L35_001DEAC8
            + (D_L35_001DEAC0 - D_L35_001DEAC8) * (f32)i / (f32)D_L35_001DEAB0;
        s->f68->pts[k].z = s->f48 + (D_L35_001DEAC0 - D_L35_001DEAC8)
            * (1.0f - func_0038D098(func_0038DB48((f32)i * 1.5707964f / (f32)D_L35_001DEAB0)));
        vcopy_003A5978(&s->f68->pts[k + 1], &s->f68->pts[k]);
        s->f68->pts[k + 1].x = v[1];
    }
    for (i = 0; i < D_L35_001DEAB4; i += 2) {
        u8 *h = D_001A4BE0;
        k = D_L35_001DEAB8 + D_L35_001DEAB0 + i;
        s->f68->pts[k].x = v[0];
        s->f68->pts[k].y = *(f32 *)(h + 0x84) + D_L35_001DEABC + D_L35_001DEAC0;
        s->f68->pts[k].z = func_003C4088(s->f48 + D_L35_001DEAC0 - D_L35_001DEAC8,
                               v[2] - D_L35_001DEAD0, (f32)i / (f32)(D_L35_001DEAB4 - 2));
        vcopy_003A5978(&s->f68->pts[k + 1], &s->f68->pts[k]);
        s->f68->pts[k + 1].x = v[1];
    }
}
/* localdecomp:end func_L35_003A5978 */
