#include "common.h"

/* declared by functions of L30_00357DD8.c, which this file was cut from */
extern s16 *D_L30_0021C420[];
extern u8 *D_L30_001DF71C;
extern s32 D_L30_001DF758;

/* localdecomp:start func_L30_00358380 */
#include "vu0.h"

typedef struct {
    u8 pad0[0xD4];
    s32 xD4;
    u8 pad1[0xE4 - 0xD8];
    s32 xE4;
    u8 pad2[0xEC - 0xE8];
    void *xEC;
    u8 pad3[0xF4 - 0xF0];
    void *xF4;
    void *xF8;
    s32 xFC;
    u8 pad4[0x120 - 0x100];
    s32 x120;
    s32 x124;
    s32 x128;
    s32 x12C;
    f32 x130;
    f32 x134;
    u8 pad5[0x13C - 0x138];
    s32 x13C;
} V_00358380;

typedef struct {
    u8 pad0[0x70];
    u16 x70;
    u16 x72;
    u8 x74;
    u8 x75;
    u8 x76;
    u8 x77;
} S_142660_00358380;

typedef struct {
    u8 pad0[0x80];
    vu0_q x80;
    u8 pad1[0x1B04 - 0x90];
    s32 x1B04;
    s32 x1B08;
    u8 pad2[0x1B38 - 0x1B0C];
    s32 x1B38;
    u8 pad3[0x2850 - 0x1B3C];
    s32 x2850;
} S_1A4BE0_00358380;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} Q_00358380;

typedef struct E_00358380 {
    u8 pad0[0x28];
    struct E_00358380 *x28;
    u8 pad1[0xAA - 0x2C];
    s16 xAA;
} E_00358380;

__asm__(".extern D_L30_001DDAD0, 4");
extern s32 D_L30_001DDAD0;
extern vu0_q D_L30_001E1430 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001E1430, 16");
extern s32 D_L30_001E1410;
extern s32 D_L30_001E1414;
extern u8 D_00142732[];
/* the file declares D_00142660 as S_00357DD8 (only x60): a per-function alias for the 0x70-0x77 fields */
extern S_142660_00358380 D_00142660_00358380;
extern S_1A4BE0_00358380 D_001A4BE0;
extern s16 D_001CD018[];
extern s16 *D_L30_0021C420[];
extern u8 *D_L30_001DF71C;
extern u8 *D_L30_001DF800;
extern E_00358380 *D_L30_001DF728;
extern s32 D_L30_001DF758;
extern u8 D_001D546F;

extern s32 func_L30_0034CA78(void);
extern void func_003A1C28(void);
extern void func_003A1930(s32, s32, s32);
extern void func_L30_00357F90(u8 *);
extern void func_L30_004E71F0(s32);

void func_L30_00358380(u8 *a0) {
    V_00358380 *v = *(V_00358380 **)(a0 + 0x68);
    s16 *p;
    s32 n = 1;
    E_00358380 *e;
    u8 *o;
    Q_00358380 *q;

    qzero(&D_L30_001E1430);
    a0[0x30] = 0xFF;
    D_00142732[0] = 0;
    D_00142660_00358380.x77 &= 0xEF;
    D_L30_001E1410 = 0;
    D_L30_001E1414 = 0;
    D_001A4BE0.x2850 = func_L30_0034CA78() * 20 + 100;
    if (D_001CD018[0] != 0) {
        func_003A1C28();
        func_003A1930(0, 1, 0x400);
    }
    func_L30_00357F90(a0);
    v->xD4 = 0;
    D_001A4BE0.x1B04 = 0;
    D_001A4BE0.x1B08 = 0;
    for (p = D_L30_0021C420[v->xFC];
         (v->xFC & 0xFF) != 0xFF && v->xFC <= D_L30_001DF758 && p != 0
         && (p[-1] >= 0 || p == D_L30_0021C420[v->xFC]); p++) {
        o = D_L30_001DF71C + ((*p & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        q = *(Q_00358380 **)(o + 0x68);
        q->x0 = n;
        q->x4 = 0;
        n++;
        if (D_00142660_00358380.x77 & 0x80) {
            func_L30_004E71F0(1);
            D_001D546F = 1;
        }
        if (D_00142660_00358380.x75 == q->x0) {
            q->x4 = 1;
            D_001A4BE0.x1B04 = D_00142660_00358380.x76;
            D_001A4BE0.x1B08 = D_00142660_00358380.x74;
            D_001A4BE0.x1B38 = D_00142660_00358380.x77;
            D_001A4BE0.x80 = *(vu0_q *)(D_L30_001DF800 + q->x8 * 128 + 0x30);
        }
    }
    D_00142660_00358380.x72 = D_00142660_00358380.x70;
    for (e = D_L30_001DF728; e != 0; e = e->x28) {
        if (e->xAA == 0x1363) {
            v->xF8 = e;
        }
        if (e->xAA == 0x1AB2) {
            v->xEC = e;
        }
        if (e->xAA == 0x1F5D) {
            v->xF4 = e;
        }
    }
    v->x124 = -100;
    v->x120 = v->xE4;
    v->x128 = D_00142660_00358380.x74;
    v->x130 = 1.0f;
    v->x12C = -100;
    v->x134 = 1.0f;
    v->x13C = D_L30_001DDAD0;
}
/* localdecomp:end func_L30_00358380 */
