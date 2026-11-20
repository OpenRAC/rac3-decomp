#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067C408 */
typedef struct G_0067C408 {
    u8 _p0[0x11];
    u8 name[0x83];
    s32 f94;
    u8 b98;
    u8 _p1[4];
    u8 b9D;
} G_0067C408;
typedef struct P_0067C408 {
    u8 _p0[0x70];
    s32 w70;
    u8 _p1[4];
    s32 w78;
    u8 _p2[0xF4];
    s32 w170;
    s32 w174;
    u8 _p3[8];
    u8 b180;
    u8 _p4;
    u8 name[0x142];
    s32 w2C4;
    u8 _p5[0x1C];
    u8 b2E4;
    u8 b2E5;
} P_0067C408;
typedef struct R_0067C408 {
    u8 _p0[0x30];
    u8 *f30;
    u8 _p1[8];
    s32 f3C;
    u8 _p2[0xC];
    s32 *f4C;
    G_0067C408 *f50;
} R_0067C408;
typedef struct Q_0067C408 {
    u8 _p0[0x284];
    s32 f284;
} Q_0067C408;

extern s32 D_L39_0024027C;
__asm__(".extern D_L39_0024027C, 16");
extern s32 D_L39_00240280;
__asm__(".extern D_L39_00240280, 16");
extern s32 D_L39_00241440;
__asm__(".extern D_L39_00241440, 16");
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern void *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern u8 D_L39_002359E0[];
extern Q_0067C408 *D_L39_00247914;
extern R_0067C408 *D_L39_0024D760;
__asm__(".extern D_L39_0024D760, 16");
extern P_0067C408 D_001A5CD0;
extern R_0067C408 *D_001E2050_sda;
void func_L39_0067EC00(void);
void func_00392260(s32, s32, s32);
void func_L39_006D78B8(s32, s32);
void func_L39_006813F8(void);
void func_L39_00685E30(s32, s32);
void func_L01_00480B10(s32);
void func_L39_0067CCB0(void);
void func_L39_0067CA48(void);
void func_L39_0067CAC0(void);
void func_001953B8(void *);
s32 func_001953D0(void *);
void func_L39_006D8D80(R_0067C408 *);
s32 func_L39_0067CE40(G_0067C408 *);
void func_L39_006DCC80(G_0067C408 *);
void func_L39_005DA820(s32);
void func_L39_005E0450(s32);
void func_L39_005D7360(s32);
void func_L39_006774C8(void);
void func_L39_005D8DB8(void);
void func_L39_00686048(void);
void func_L39_006A7928(void);
void func_00199050(void);
void func_L39_006D40B0(s32);
void *func_001206F4(void *, void *);

void func_L39_0067C408(void) {
    s32 mode;
    s32 t;
    s32 c1;
    s32 c7;
    s32 c8;
    s32 w1;
    s32 w2;
    s32 size;
    s32 base;
    s32 i;
    P_0067C408 *p;
    P_0067C408 *p1;
    P_0067C408 *p7;
    P_0067C408 *p8;
    G_0067C408 *g;
    R_0067C408 *r;
    u8 ta;
    u8 ta1;

    size = 0xC8000;
    func_L39_0067EC00();
    func_00392260(0, 0, 0);
    base = D_L39_0024027C;
    t = D_L39_00240280 - base;
    t -= size;
    mode = D_L39_00241440;
    D_L39_00241440 = -1;
    func_L39_006D78B8(base, 0xC8000);
    func_L39_006813F8();
    func_L39_00685E30(D_L39_0024027C + size, t);
    func_L01_00480B10(10);
    switch (mode) {
    case 0:
        D_L39_00247914->f284 = 0x18;
        func_001953B8(func_L39_0067CCB0);
        func_001953D0(func_L39_0067CCB0);
        break;
    case 1:
        D_L39_00247914->f284 = 0;
        func_001953B8(func_L39_0067CA48);
        func_001953D0(func_L39_0067CA48);
        p1 = &D_001A5CD0;
        if (p1->w174 == 0) {
            if (p1->b2E4 == 0) {
                func_L39_006D8D80(D_001E2050_sda);
            }
            if (p1->b2E5 != 0) {
                g = D_001E2050_sda->f50;
                ta1 = p1->b180;
                c1 = p1->w2C4;
                g->b9D = p1->b2E5;
                g->b98 = ta1;
                func_001206F4(g->name, (char *)p1->name);
                g->f94 = c1;
                if (func_L39_0067CE40(g)) {
                    func_L39_006DCC80(g);
                }
            }
            func_001953B8(func_L39_0067CAC0);
            func_001953D0(func_L39_0067CAC0);
        } else {
            func_001953B8(func_L39_0067CCB0);
            func_001953D0(func_L39_0067CCB0);
        }
        break;
    case 2:
        D_L39_00247914->f284 = 0;
        func_001953B8(func_L39_0067CAC0);
        func_001953D0(func_L39_0067CAC0);
        break;
    case 4:
    case 6:
    case 9:
        if (D_L39_002412DC != 0x27) {
            for (i = 0; i < *D_L39_00241120; i++) {
                func_L39_005DA820(i);
                func_L39_005E0450(i);
                func_L39_005D7360(i);
            }
            func_L39_006774C8();
            func_L39_005D8DB8();
        }
        if (mode == 4) {
            D_L39_00247914->f284 = 0x12;
        }
        if (mode == 9) {
            D_L39_00247914->f284 = 0x19;
        }
        p = &D_001A5CD0;
        func_001953B8(func_L39_0067CA48);
        func_001953D0(func_L39_0067CA48);
        func_L39_00686048();
        p->w170 = 0;
        if (D_L39_00241640 == D_L39_002359E0) {
            D_L39_00241640 = 0;
        }
        func_001953B8(func_L39_0067CAC0);
        func_001953D0(func_L39_0067CAC0);
        if (mode == 6) {
            r = D_001E2050_sda;
            w1 = p->w78;
            *r->f4C = w1;
            p->w78 = w1;
            w2 = p->w70;
            *(s32 *)(r->f30 + 0x28) = w2;
            p->w70 = w2;
            func_L39_006A7928();
            return;
        }
        if (mode == 4) {
            return;
        }
        func_00199050();
        if (p->w174 != 0) {
            D_L39_00247914->f284 = 0x15;
        } else {
            func_L39_006D40B0(D_L39_0024D760->f3C);
        }
        return;
    case 3:
    case 5:
        if (D_L39_002412DC != 0x27) {
            for (i = 0; i < *D_L39_00241120; i++) {
                func_L39_005DA820(i);
                func_L39_005E0450(i);
                func_L39_005D7360(i);
            }
            func_L39_006774C8();
            func_L39_005D8DB8();
        }
        if (mode == 5) {
            func_L39_006A7928();
        } else {
            D_L39_00247914->f284 = 0x12;
        }
        func_001953B8(func_L39_0067CCB0);
        func_001953D0(func_L39_0067CCB0);
        break;
    case 8:
        p8 = &D_001A5CD0;
        g = D_L39_0024D760->f50;
        ta = p8->b180;
        c8 = p8->w2C4;
        g->b9D = p8->b2E5;
        g->b98 = ta;
        func_001206F4(g->name, (char *)p8->name);
        g->f94 = c8;
        if (func_L39_0067CE40(g)) {
            func_L39_006DCC80(g);
        }
        D_L39_00247914->f284 = 0x1D;
        func_001953B8(func_L39_0067CAC0);
        func_001953D0(func_L39_0067CAC0);
        break;
    case 7:
        p7 = &D_001A5CD0;
        g = D_L39_0024D760->f50;
        ta = p7->b180;
        c7 = p7->w2C4;
        g->b9D = p7->b2E5;
        g->b98 = ta;
        func_001206F4(g->name, (char *)p7->name);
        g->f94 = c7;
        if (func_L39_0067CE40(g)) {
            func_L39_006DCC80(g);
        }
        D_L39_00247914->f284 = 0x1D;
        func_001953B8(func_L39_0067CCB0);
        func_001953D0(func_L39_0067CCB0);
        return;
    default:
        return;
    }
}
/* localdecomp:end func_L39_0067C408 */
