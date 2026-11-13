#include "common.h"

/* declared by functions of L30_00358618.c, which this file was cut from */
extern u8 D_001426E0[];

/* localdecomp:start func_L30_003586A8 */
typedef struct { f32 x, y, z, w; } V_003586A8 __attribute__((aligned(16)));
typedef struct {
    u8 p0[0xE0];
    s32 fE0;
    s32 fE4;
    s32 fE8;
    u8 *fEC;
    u8 pF0[4];
    u8 *fF4;
    u8 pF8[4];
    s32 fFC;
} P_003586A8;
typedef struct { u8 b0; u8 p1[3]; s32 f4; u8 p8[4]; s32 fC; } R_003586A8;
extern s16 *D_L30_0021C420[];
extern u8 *D_L30_001DF71C;
__asm__(".extern D_L30_001DF71C, 16");
extern s32 D_L30_001DF758;
extern f32 D_L30_001DDAAC;
__asm__(".extern D_L30_001DDAAC, 4");
extern V_003586A8 D_001A4C60;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBB18[][8];
extern u8 D_001426E0[];
extern u8 D_00142660[];
extern u8 D_001A4BE0[];
extern s32 D_001A7430[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_L30_003580F8(void *, void *);
extern void func_L30_00357DD8(void *, void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern void func_L30_003582E0(s32, s32);
extern s32 func_L30_0034CA78(void);
extern s32 func_00382380(void *, s32, s32);
extern s16 func_L30_00358360(void *);

void func_L30_003586A8(u8 *a0) {
    P_003586A8 *p = *(P_003586A8 **)(a0 + 0x68);
    V_003586A8 pos;
    s16 *q;
    s16 *q2;

    pos = D_001A4C60;
    pos.z += 1.7f;
    q = D_L30_0021C420[p->fE0];
    while ((p->fE0 & 0xFF) != 0xFF && p->fE0 <= D_L30_001DF758 && q != 0 && (q[-1] >= 0 || q == D_L30_0021C420[p->fE0])) {
        u8 *m = D_L30_001DF71C + ((*(u16 *)q & 0x7FFF) << 8);
        if (m == 0) break;
        if (func_0038CF00(m + 0x10, &pos) < D_L30_001DDAAC) {
            if (func_L30_003580F8(a0, m) == 0) {
                func_L30_00357DD8(a0, m);
            }
        }
        q++;
    }
    if (p->fE4 == p->fE8 && D_001BBB18[D_001D545C][0] == 0 && p->fF4 != 0) {
        if (func_L01_00456250(p->fF4) == 0) {
            func_L01_00456230(p->fF4, 1);
        }
    }
    if ((((D_001426E0[0x51] >> (D_001D545C - 30)) ^ 1) & 1) && p->fEC != 0) {
        if (func_0038CF00(&pos, p->fEC + 0x10) < D_L30_001DDAAC) {
            func_L30_003582E0(0xC68, 0x53);
            D_001426E0[0x51] |= 1 << (D_001D545C - 30);
            D_001A7430[0] = func_L30_0034CA78() * 20.0f + 100.0f;
        }
    }
    if ((D_001426E0[0x51] >> (D_001D545C - 30)) & 1) {
        func_L01_00456230(p->fEC, 1);
    }
    q2 = D_L30_0021C420[p->fFC];
    while ((p->fFC & 0xFF) != 0xFF && p->fFC <= D_L30_001DF758 && q2 != 0 && (q2[-1] >= 0 || q2 == D_L30_0021C420[p->fFC])) {
        u8 *m = D_L30_001DF71C + ((*(u16 *)q2 & 0x7FFF) << 8);
        R_003586A8 *r;
        if (m == 0) break;
        r = *(R_003586A8 **)(m + 0x68);
        if (r->f4 == 0 && func_00382380(&pos, r->fC, 0) != 0) {
            r->f4 = 1;
            D_00142660[0x74] = D_001A4BE0[0x1B08];
            D_00142660[0x76] = D_001A4BE0[0x1B04];
            D_00142660[0x75] = r->b0;
            *(s16 *)(D_00142660 + 0x72) = func_L30_00358360(a0);
            D_00142660[0x77] = D_001A4BE0[0x1B38];
        }
        q2++;
    }
}
/* localdecomp:end func_L30_003586A8 */

/* localdecomp:start func_L30_00358A18 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x78];
    long f78;
    u8 pad80[0x8];
    long f88;
} Q_00358A18;

extern u8 D_001A4BE0[];
extern f32 D_L30_001E2240[];
extern f32 D_L30_001E1440[] __attribute__((section(".sdata")));
extern Q_00358A18 D_L30_00283E80;
__asm__(".extern D_L30_001DDABC, 4");
__asm__(".extern D_L30_001DDAC4, 4");
__asm__(".extern D_L30_001DDB00, 4");
__asm__(".extern D_L30_001DDAC8, 4");
__asm__(".extern D_L30_001DDACC, 4");
extern f32 D_L30_001DDABC;
extern f32 D_L30_001DDAC4;
extern f32 D_L30_001DDB00;
extern s32 D_L30_001DDAC8;
extern s32 D_L30_001DDACC;
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern void func_L24_00358F70(f32 *m, s32 a1, f32 a, f32 b, f32 c, f32 d, f32 e);
extern void func_L30_0034C460(void *, s32, s32, s32, s32);
extern void func_L30_0034C428(void *);
extern long func_00389598(s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_003A9440(s32, unsigned long);

void func_L30_00358A18(u8 *a0) {
    Q_00358A18 q;
    f32 v[4];
    f32 w;
    f32 d;
    f32 s;
    f32 x0, x1, x2, x3;
    u8 *p = *(u8 **)(a0 + 0x68);

    w = D_L30_001DDAC4 * (fabs_asm(*(f32 *)(D_001A4BE0 + 0x84) - D_L30_001E2240[1]) - D_L30_001DDABC);
    func_L30_0034CDC0(&v[0], &v[1], &v[2], &v[3], 1.0f);
    d = v[1] - v[0];
    v[0] -= d;
    v[1] += d;
    v[2] = (v[2] + v[3]) * 0.5f - D_L30_001DDB00 * (d * 1.5f);
    v[3] = (v[2] + v[3]) * 0.5f + D_L30_001DDB00 * (d * 1.5f);
    s = *(f32 *)(p + 0xD0);
    func_L24_00358F70((f32 *)&D_L30_00283E80, 1, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    func_L30_0034C460(&D_L30_00283E80, ((s32)(s * s * 128.0f) << 24) | 0x808080, -1, -1, -1);
    func_L30_0034C428(&D_L30_00283E80);
    D_L30_00283E80.f88 = (0x8000L << 24) | 0x44;
    D_L30_00283E80.f78 = func_00389598(D_L30_001DDAC8);
    x0 = func_003C4088(v[0], D_L30_001E1440[0] - w, s);
    x1 = func_003C4088(v[1], D_L30_001E1440[0] + w, s);
    x2 = func_003C4088(v[2], D_L30_001E1440[2] - D_L30_001DDB00 * w, s);
    x3 = func_003C4088(v[3], D_L30_001E1440[2] + D_L30_001DDB00 * w, s);
    func_L24_00358F70((f32 *)&D_L30_00283E80, 0, x0, x1, x3, x2, D_L30_001E1440[1] - D_L30_001DDABC);
    func_003D2DA0(&D_L30_00283E80, 0, 0);
    func_L24_00358F70((f32 *)&q, 1, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    func_L30_0034C460(&q, 0x80808080, -1, -1, -1);
    func_L30_0034C428(&q);
    q.f88 = (0x8000L << 24) | 0x4A;
    q.f78 = func_00389598(0x16);
    func_003A9440(0x47, 0x31001);
    func_L24_00358F70((f32 *)&q, 0, v[0], v[1], v[3], v[2], D_L30_001E1440[1] - D_L30_001DDABC);
    func_003D2DA0(&q, 0, 0);
    func_L30_0034C460(&D_L30_00283E80, 0x80808080, -1, -1, -1);
    D_L30_00283E80.f78 = func_00389598(D_L30_001DDACC);
    func_003D2DA0(&D_L30_00283E80, 0, 0);
    func_L30_0034C460(&q, 0x80000000, -1, -1, -1);
    q.f88 = (0x8000L << 24) | 0x54;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L30_00358A18 */

INCLUDE_ASM("asm/levels", func_L30_00358DA8);
