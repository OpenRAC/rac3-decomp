#include "common.h"

typedef struct S_0067EF00 {
    s32 f0;
    s32 f4;
    s32 f8;
} S_0067EF00;

/* localdecomp:start func_L39_0067EF00 */
s32 func_L39_0067EF00(S_0067EF00 *p, s32 v) {
    s32 t = p->f4;

    if (t == 2) {
        if (v == 3) {
            p->f8 = 1;
        }
    } else if (t == 3) {
        if (v == 4) {
            p->f8 = 2;
        } else if (v == 2) {
            p->f8 = 6;
        }
    } else if (t == 4) {
        if (v == 3) {
            p->f8 = 5;
        } else if (v == 5) {
            p->f8 = 3;
        }
    } else if (t == 5) {
        if (v == 4) {
            p->f8 = v;
        }
    }
    p->f4 = v;
    return t;
}
/* localdecomp:end func_L39_0067EF00 */

/* localdecomp:start func_L39_0067EFA0 */
typedef struct V_0067EFA0 {
    u8 pad0[0x1c];
    void (*f1c)(void *, s32);
} V_0067EFA0;

typedef struct S_0067EFA0 {
    s32 f0;
    s32 f4;
    u8 pad8[0x58];
    V_0067EFA0 *f60;
} S_0067EFA0;

s32 func_L39_0067EFA0(S_0067EFA0 *p, s32 v) {
    s32 t = p->f4;

    if ((t >= 3 && v < 3) || (t < 3 && v >= 3) || v == 0 || t <= 0 || t >= 6) {
        p->f60->f1c(p, v);
    }
    return t;
}
/* localdecomp:end func_L39_0067EFA0 */

/* localdecomp:start func_L39_0067F010 */
/* from rac2-decomp's func_00343028, renamed, constants adapted */
void func_L39_0067F010(u8 *a0, f32 a1, f32 a2) { *(f32 *)(a0 + 0x50) = a1; *(f32 *)(a0 + 0x54) = a2; }
/* localdecomp:end func_L39_0067F010 */

/* localdecomp:start func_L39_0067F020 */
/* from rac2-decomp's func_00343028, renamed, constants adapted */
void func_L39_0067F020(u8 *a0, f32 a1, f32 a2) { *(f32 *)(a0 + 0x58) = a1; *(f32 *)(a0 + 0x5c) = a2; }
/* localdecomp:end func_L39_0067F020 */

/* localdecomp:start func_L39_0067F030 */
extern void *D_001DBC4C_sda;
void func_003E82F8(void *);

/* from rac4-decomp's func_L01_00446AC0 */
void func_L39_0067F030(void *object) {
    D_001DBC4C_sda = object;
    func_003E82F8(object);
}
/* localdecomp:end func_L39_0067F030 */

/* localdecomp:start func_L39_0067F050 */
extern s32 D_001DBC50_sda;
extern s32 D_001DBC58_sda;

void func_L39_0067F050(s32 arg0) {
    D_001DBC50_sda = arg0;
    D_001DBC58_sda = -1;
}
/* localdecomp:end func_L39_0067F050 */

/* localdecomp:start func_L39_0067F060 */
/* from rac2-decomp style; NOTE: callee func_003E8348 declared s32 return (needed for $v1 choice) */
extern s32 D_001DBC64_sda;
extern s32 D_001DBC68_sda;
extern s32 D_001DBC6C_sda;
extern s32 D_001DBC70_sda;

void func_L01_00484A80(s32);
s32 func_003E8348(s32, s32);

void func_L39_0067F060(s32 arg0, s32 arg1) {
    D_001DBC64_sda = arg0;
    D_001DBC68_sda = arg1;
    D_001DBC70_sda = arg1;
    func_L01_00484A80(arg1);
    func_003E8348(D_001DBC64_sda, D_001DBC70_sda);
    D_001DBC6C_sda = D_001DBC70_sda;
}
/* localdecomp:end func_L39_0067F060 */

/* localdecomp:start func_L39_0067F0A0 */
extern s32 D_001DBC68_sda;
extern s32 D_001DBC6C_sda;
extern s32 D_001DBC70_sda;

void func_L01_00484A80(s32);
void func_003E8630(s32, s32);

s32 func_L39_0067F0A0(void) {
    if ((D_001DBC70_sda - D_001DBC68_sda) % 17 == 0) {
        D_001DBC70_sda = D_001DBC70_sda + 1;
        D_001DBC6C_sda = D_001DBC70_sda;
        func_L01_00484A80(D_001DBC70_sda);
        func_003E8630(D_001DBC68_sda, D_001DBC6C_sda);
    }
    D_001DBC70_sda = D_001DBC70_sda + 1;
    return D_001DBC70_sda;
}
/* localdecomp:end func_L39_0067F0A0 */

/* localdecomp:start func_L39_0067F100 */
extern s32 D_001DBC50_sda;
extern s32 D_001DBC54_sda;
extern s32 D_001DBC58_sda;
extern s32 D_001DBC5C_sda;
extern s32 D_001DBC60_sda;

void func_L01_00484A80(s32);
s32 func_003E8348(s32, s32);

s32 func_L39_0067F100(s32 arg0) {
    if (D_001DBC58_sda == -1) {
        D_001DBC58_sda = D_001DBC50_sda;
    } else if (D_001DBC58_sda == 4) {
        D_001DBC58_sda = 13;
    } else {
        D_001DBC58_sda++;
    }
    D_001DBC54_sda = arg0;
    D_001DBC60_sda = arg0;
    func_L01_00484A80(arg0);
    func_003E8348(D_001DBC58_sda, D_001DBC60_sda);
    D_001DBC5C_sda = D_001DBC60_sda;
    return D_001DBC58_sda;
}
/* localdecomp:end func_L39_0067F100 */

/* localdecomp:start func_L39_0067F168 */
extern s32 D_001DBC58_sda;

void func_L39_006121B0(s32);

s32 func_L39_0067F168(void) {
    s32 v;

    v = D_001DBC58_sda;
    func_L39_006121B0(v);
    if (D_001DBC58_sda == 13) {
        D_001DBC58_sda = 4;
    } else {
        D_001DBC58_sda = D_001DBC58_sda - 1;
    }
    return v;
}
/* localdecomp:end func_L39_0067F168 */

/* localdecomp:start func_L39_0067F1B0 */
extern s32 D_001DBC54_sda;
extern s32 D_001DBC5C_sda;
extern s32 D_001DBC60_sda;

void func_L01_00484A80(s32);
void func_003E8630(s32, s32);

s32 func_L39_0067F1B0(void) {
    if ((D_001DBC60_sda - D_001DBC54_sda) % 17 == 0) {
        D_001DBC60_sda = D_001DBC60_sda + 1;
        D_001DBC5C_sda = D_001DBC60_sda;
        func_L01_00484A80(D_001DBC60_sda);
        func_003E8630(D_001DBC54_sda, D_001DBC5C_sda);
    }
    D_001DBC60_sda = D_001DBC60_sda + 1;
    return D_001DBC60_sda;
}
/* localdecomp:end func_L39_0067F1B0 */

/* localdecomp:start func_L39_0067F210 */
typedef struct {
    u8 pad0[0x470];
    s32 f470;
    s32 f474;
    s32 f478;
    s32 f47C;
    s32 f480;
    u8 pad484[0x490 - 0x484];
    u8 f490;
} P_0067F210;
typedef struct {
    u8 pad0[0xAC];
    P_0067F210 *fAC;
} G_0067F210;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    char f1C[0x20];
    s32 f3C;
    char f40[1];
} S_0067F210;

__asm__(".extern D_L39_00247914, 16");
extern G_0067F210 *D_L39_00247914;
extern u8 D_L39_003729C0[];
extern char D_L39_00247308[];
extern char D_L39_00247390[];
extern char D_L39_00247398[];
__asm__(".extern D_L39_0024D764, 16");
extern u8 D_L39_0024D764;
__asm__(".extern D_L39_0024D765, 16");
extern u8 D_L39_0024D765;
extern s32 func_00120884(char *);
extern void func_L39_005958F8(u8 *, char *, s32);
extern void func_0011D534(void *, s32, s32);
extern s32 func_00120048(void *, char *, ...);
extern s32 func_001200E0(void *, char *, ...);
extern char *func_001206F4(void *, void *);
extern void func_L39_0067F3B8(s32, char *);
extern void func_L39_0067F648(s32, char *);

void func_L39_0067F210(S_0067F210 *this) {
    char buf[0x70];
    s32 a;
    s32 b;
    s32 c;

    func_L39_005958F8(D_L39_003729C0, this->f40, func_00120884(this->f40));
    if (this->f3C == 0 && D_L39_0024D764 != 0) {
        func_0011D534(buf, 0, 0x70);
        func_00120048(buf, D_L39_00247390, this->f1C, D_L39_003729C0);
        func_L39_0067F3B8(this->f18, buf);
    } else if (this->f3C == 1 && D_L39_0024D765 != 0) {
        if (D_L39_003729C0[0] == 'V' || D_L39_003729C0[0] == 'C') {
            func_001206F4(buf, D_L39_003729C0);
        } else if (D_L39_003729C0[0] == 'N') {
            P_0067F210 *p;
            s32 x;
            s32 y;
            func_001200E0(D_L39_003729C0 + 1, D_L39_00247308, &a);
            func_001200E0(D_L39_003729C0 + 9, D_L39_00247308, &b);
            x = a;
            y = b;
            p = D_L39_00247914->fAC;
            p->f478 = x;
            p->f480 = y;
            return;
        } else if (D_L39_003729C0[0] == 'R') {
            P_0067F210 *p = D_L39_00247914->fAC;
            func_001200E0(D_L39_003729C0 + 1, D_L39_00247308, &c);
            p->f470 = c;
            p->f490 = 1;
            return;
        } else {
            func_00120048(buf, D_L39_00247398, 'M', this->f1C, D_L39_003729C0 + 1);
        }
        func_L39_0067F648(this->f18, buf);
    }
}
/* localdecomp:end func_L39_0067F210 */
