/* functional: medium. Same stores/calls/loop conditions as retail (the list walk is the matched loop of func_L30_003586A8); not byte-identical (retail loop is laid out differently). */
#include "vu0.h"
__asm__(".extern D_L30_001DF758, 4");
extern s32 D_L30_001DF758;
__asm__(".extern D_L30_001DDAD0, 4");
extern s32 D_L30_001DDAD0;
__asm__(".extern D_L30_001E1414, 4");
extern s32 D_L30_001E1414;
typedef struct {
    u8 p0[0xD4]; s32 fD4;
    u8 pD8[0xE4 - 0xD8]; s32 fE4;
    u8 pE8[0xEC - 0xE8]; u8 *fEC;
    u8 pF0[0xF4 - 0xF0]; u8 *fF4; u8 *fF8; s32 fFC;
    u8 p100[0x120 - 0x100]; s32 f120; s32 f124; s32 f128; s32 f12C; f32 f130; f32 f134;
    u8 p138[0x13C - 0x138]; s32 f13C;
} V_358380;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_358380;
extern s16 *D_L30_0021C420[];
extern u8 *D_L30_001DF71C;
__asm__(".extern D_L30_001DF71C, 16");
extern u8 *D_L30_001DF728;
__asm__(".extern D_L30_001DF728, 16");
extern u8 D_L30_001DF800[];
extern s32 D_L30_001E1410;
extern u8 D_L30_001E1430[];
extern s16 D_001CD018;
extern u8 D_001D546F;
extern u8 D_001A4BE0[];
extern s32 func_L30_0034CA78(void);
extern void func_L30_00357F90(void *);
extern void func_L30_004E71F0(s32);
extern void func_003A1C28(void);
extern void func_003A1930(s32, s32, s32);

void func_L30_00358380(u8 *self) {
    V_358380 *v;
    s16 *q;
    u8 *o;
    u8 *g = (u8 *)&D_00142660;

    qzero(D_L30_001E1430);
    self[0x30] = 0xFF;
    g[0x77] &= 0xEF;
    g[0xD2] = 0;
    D_L30_001E1410 = 0;
    D_L30_001E1414 = 0;
    *(s32 *)(D_001A4BE0 + 0x2850) = func_L30_0034CA78() * 20 + 100;
    if (D_001CD018 != 0) {
        func_003A1C28();
        func_003A1930(0, 1, 0x400);
    }
    func_L30_00357F90(self);
    v = *(V_358380 **)(self + 0x68);
    v->fD4 = 0;
    *(s32 *)(D_001A4BE0 + 0x1B08) = 0;
    *(s32 *)(D_001A4BE0 + 0x1B04) = 0;
    q = D_L30_0021C420[v->fFC];
    {
        s32 n = 1;
        while ((v->fFC & 0xFF) != 0xFF && v->fFC <= D_L30_001DF758 && q != 0
               && (q[-1] >= 0 || q == D_L30_0021C420[v->fFC])) {
            u8 *m = D_L30_001DF71C + ((*(u16 *)q & 0x7FFF) << 8);
            V_358380 *r;
            if (m == 0) break;
            r = *(V_358380 **)(m + 0x68);
            *(s32 *)r = n;
            *(s32 *)((u8 *)r + 4) = 0;
            n++;
            if (g[0x77] & 0x80) {
                func_L30_004E71F0(1);
                D_001D546F = 1;
            }
            q++;
            if (g[0x75] == *(s32 *)r) {
                *(s32 *)((u8 *)r + 4) = 1;
                *(s32 *)(D_001A4BE0 + 0x1B04) = g[0x76];
                *(s32 *)(D_001A4BE0 + 0x1B08) = g[0x74];
                *(s32 *)(D_001A4BE0 + 0x1B38) = g[0x77];
                *(Q_358380 *)(D_001A4BE0 + 0x80) = *(Q_358380 *)(D_L30_001DF800 + (*(s32 *)((u8 *)r + 8) << 7) + 0x30);
            }
        }
    }
    *(u16 *)(g + 0x72) = *(u16 *)(g + 0x70);
    for (o = D_L30_001DF728; o != 0; o = *(u8 **)(o + 0x28)) {
        s16 cls = *(s16 *)(o + 0xAA);
        if (cls == 0x1363) v->fF8 = o;
        if (cls == 0x1AB2) v->fEC = o;
        if (cls == 0x1F5D) v->fF4 = o;
    }
    v->f124 = -100;
    v->f120 = v->fE4;
    v->f128 = g[0x74];
    v->f13C = D_L30_001DDAD0;
    v->f12C = -100;
    v->f134 = 1.0f;
    v->f130 = 1.0f;
}
