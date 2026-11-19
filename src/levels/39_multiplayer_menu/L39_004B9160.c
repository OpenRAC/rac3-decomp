#include "common.h"

/* localdecomp:start func_L39_004B9160 */
extern s32 func_L39_004C3D20(void *, u8 *, s32);
extern s32 *func_L01_003E4008(void);
extern s32 func_L39_004B95C0(s32);

s32 func_L39_004B9160(void *arg0, u8 *arg1, s32 arg2) {
    s32 n;
    s32 r;

    for (n = arg2; n > 0; n -= r, arg1 += r) {
        r = func_L39_004C3D20(arg0, arg1, n);
        if (r < 0) {
            if (*func_L01_003E4008() == 0x71) {
                return func_L39_004B95C0(*func_L01_003E4008());
            }
            return -0x262;
        }
        if (r == 0) {
            break;
        }
    }
    return arg2 - n;
}
/* localdecomp:end func_L39_004B9160 */

/* localdecomp:start func_L39_004B9218 */
extern s64 func_L01_00412E50(s32, void *, s32, s32);

s32 func_L39_004B9218(s32 fd, u8 *buf, s32 len) {
    s32 n;
    s32 r;

    for (n = len; n > 0; n -= r, buf += r) {
        r = func_L01_00412E50(fd, buf, n, 0);
        if (r < 0) {
            return func_L39_004B95C0(*func_L01_003E4008());
        }
        if (r == 0) {
            break;
        }
    }
    return len - n;
}
/* localdecomp:end func_L39_004B9218 */

/* localdecomp:start func_L39_004B92B8 */
extern s32 func_L39_004B80D8(void);
extern s32 func_L39_004B8150(void);
extern s32 func_L39_004B9218(s32, u8 *, s32);
extern s32 D_L39_00464788;
extern void *D_L39_00464790;
extern s32 D_L39_00464774;

s32 func_L39_004B92B8(u8 *buf, s32 len) {
    s32 lock;
    s32 r;

    lock = func_L39_004B80D8();
    if (D_L39_00464788 != 0) {
        r = func_L39_004B9160(D_L39_00464790, buf, len);
    } else {
        r = func_L39_004B9218(D_L39_00464774, buf, len);
    }
    if (lock >= 0) {
        func_L39_004B8150();
    }
    return r;
}
/* localdecomp:end func_L39_004B92B8 */

/* localdecomp:start func_L39_004B9350 */
extern s32 func_L39_004C3DC0(void *);
extern void func_L39_004C39F8(void *);
extern s32 func_L01_00422FE0(s32, s32);
extern s32 D_L39_00464778;

s32 func_L39_004B9350(void) {
    s32 lock;

    lock = func_L39_004B80D8();
    if (D_L39_00464788 != 0) {
        if (D_L39_00464790 != 0) {
            func_L39_004C3DC0(D_L39_00464790);
            func_L39_004C39F8(D_L39_00464790);
            D_L39_00464790 = 0;
        }
    }
    if (D_L39_00464774 >= 0) {
        func_L01_00422FE0(D_L39_00464774, 0);
        D_L39_00464774 = -1;
    }
    D_L39_00464778 = 0;
    if (lock >= 0) {
        func_L39_004B8150();
    }
    return 0;
}
/* localdecomp:end func_L39_004B9350 */

/* localdecomp:start func_L39_004B93F8 */
typedef struct S_004B93F8 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ void *f10;
} S_004B93F8;

extern s32 D_L39_00464788;
extern S_004B93F8 D_L39_004646F8[];
extern void *D_L39_0046478C;
extern s32 D_L39_0046477C;
extern s32 D_L39_00464780;
extern char D_L39_00442C50[];
extern void func_L39_004BBE28(void *);
extern void func_L39_004C46A8(void *);
extern void func_L39_004C33C8(void);
extern void func_L01_004126A8(s32);
extern void func_00126270(s32);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004B93F8(void) {
    u32 i;
    u32 j;
    char *p;

    if (D_L39_00464788 != 0) {
        for (i = 0; i < 6; i++) {
            if (D_L39_004646F8[i].f10 != 0) {
                func_L39_004BBE28(D_L39_004646F8[i].f10);
                D_L39_004646F8[i].f10 = 0;
            }
        }
        if (D_L39_0046478C != 0) {
            func_L39_004C46A8(D_L39_0046478C);
            D_L39_0046478C = 0;
        }
        func_L39_004C33C8();
    }
    func_L01_004126A8(D_L39_0046477C);
    D_L39_0046477C = -1;
    func_00126270(D_L39_00464780);
    D_L39_00464780 = -1;
    p = D_L39_00442C50;
    for (j = 0; j < 0x200; j++) {
        p[j] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_004B93F8 */

/* localdecomp:start func_L39_004B9570 */
extern s32 D_L39_00464774;
extern s32 D_L39_0046477C;
extern s32 D_L39_00464780;
extern s32 func_001262B0(s32);
extern void func_L01_0033D298(void *);
extern s32 func_L39_00518830(void);

s32 func_L39_004B9570(void) {
    s32 ret;

    if (func_001262B0(D_L39_00464780) < 0) {
        ret = ((s32 (*)(s32))func_L01_0033D298)(D_L39_00464774);
    } else {
        ret = ((s32 (*)(s32))func_L39_00518830)(D_L39_0046477C);
    }
    return ret;
}
/* localdecomp:end func_L39_004B9570 */

/* localdecomp:start func_L39_004B95C0 */
s32 func_L39_004B95C0(s32 id) {
    switch (id) {
    case 116: return -0x269;
    case 4:
    case 113: return -0x259;
    case 12: return -0x26D;
    case 22:
    case 125: return -0x270;
    case 127: return -0x268;
    case 110:
    case 128: return -0x26C;
    case 111: return -0x26A;
    case 104: return -0x272;
    case 118: return -0x26B;
    case 16:
    case 115: return -0x271;
    }
    return -0x271;
}
/* localdecomp:end func_L39_004B95C0 */

/* localdecomp:start func_L39_004B9640 */
extern s32 *func_L01_003E4008(void);
extern s32 func_L39_004B95C0(s32);

s32 func_L39_004B9640(s32 err) {
    s32 ret;

    switch (err) {
    case -1:
        ret = func_L39_004B95C0(*func_L01_003E4008());
        if (ret == -0x271) {
            ret = -0x267;
        }
        break;
    case 1:
        ret = -0x263;
        break;
    case 2:
        ret = -0x264;
        break;
    case 3:
        ret = -0x265;
        break;
    case 4:
        ret = -0x266;
        break;
    default:
        ret = -0x267;
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_004B9640 */

/* localdecomp:start func_L39_004B96D0 */
extern s32 D_L39_00464770;
extern char D_L39_00442C50[];
extern u16 D_L39_00442E50;
extern void *func_001206F4(void *, void *);

s32 func_L39_004B96D0(char *name, u16 port) {
    D_L39_00464770 = 1;
    func_001206F4(D_L39_00442C50, name);
    D_L39_00442E50 = port;
    return 0;
}
/* localdecomp:end func_L39_004B96D0 */

INCLUDE_ASM("asm/levels", func_L39_004B9720);

/* localdecomp:start func_L39_004B9C78 */
extern s32 D_L39_00464788;
s32 func_L39_004B9C78(s32 arg0) {
    D_L39_00464788 = arg0;
    return 0;
}
/* localdecomp:end func_L39_004B9C78 */

/* localdecomp:start func_L39_004B9C88 */
/* pointer p for the clear loops and D == state -> 2 diff; func_L39_004BB368 called as void (its definition never returns a value) -> MATCH (@ee296 file line). */
extern char *func_L39_004C4C58(void *);
extern s32 func_001205B0(char *, char *);
extern s32 func_L39_004C4EE0(void *);
extern void func_L01_0032ADE8(s32);
extern s32 func_L39_004BB368(void);
extern char D_L39_00474D58[];
extern char D_L39_00474D60[];
extern char D_L39_00474D68[];
extern s32 D_L39_00443074;
extern s32 D_L39_004647A0;
extern s32 D_L39_004647A4;
extern s32 D_L39_004647A8;
extern s32 D_L39_00443278;
extern s32 D_L39_00464794[];
extern s32 D_L39_00464798[];
extern u8 D_L39_00443280[];
extern u8 D_L39_00443078[];
extern u8 D_L39_00443178[];
extern u8 D_L39_004432B8[];

void func_L39_004B9C88(void *ssl) {
    s32 state;
    u32 i;
    u8 *p;

    if (func_001205B0(func_L39_004C4C58(ssl), D_L39_00474D58) == 0) {
        D_L39_00443074 = 2;
    } else if (func_001205B0(func_L39_004C4C58(ssl), D_L39_00474D60) == 0) {
        D_L39_00443074 = 3;
    } else if (func_001205B0(func_L39_004C4C58(ssl), D_L39_00474D68) == 0) {
        D_L39_00443074 = 1;
    } else {
        D_L39_00443074 = -1;
    }
    if (D_L39_004647A0 > 0 && D_L39_004647A8 == 3) {
        ((void (*)(void))func_L39_004BB368)();
        p = D_L39_00443280;
        for (i = 0; i < 50; i++) {
            p[i] = 0;
        }
        D_L39_004647A0 = 0;
    }
    state = func_L39_004C4EE0(ssl);
    if (D_L39_00443278 == state) {
        if (D_L39_00464794[0] != 0) {
            p = D_L39_00443078;
            for (i = 0; i < 0x100; i++) {
                p[i] = 0;
            }
            D_L39_00464794[0] = 0;
        }
        return;
    }
    D_L39_00443278 = state;
    switch (state) {
    case 0x1110:
    case 0x1111:
    case 0x1210:
    case 0x1211:
        func_L01_0032ADE8(0x20);
        break;
    case 0x1120:
    case 0x1121:
        func_L01_0032ADE8(0x21);
        break;
    case 0x1130:
    case 0x1131:
        func_L01_0032ADE8(0x22);
        break;
    case 0x1140:
    case 0x1141:
        func_L01_0032ADE8(0x25);
        break;
    case 0x1150:
    case 0x1151:
        func_L01_0032ADE8(0x23);
        break;
    case 0x1160:
    case 0x1161:
        func_L01_0032ADE8(0x24);
        break;
    case 0x1170:
    case 0x1171:
    case 0x1172:
        break;
    case 0x1180:
    case 0x1181:
        func_L01_0032ADE8(0x26);
        break;
    case 0x1190:
    case 0x1191:
        func_L01_0032ADE8(0x27);
        break;
    case 0x11A0:
    case 0x11A1:
        func_L01_0032ADE8(0x10);
        break;
    case 0x11B0:
    case 0x11B1:
        func_L01_0032ADE8(0x28);
        break;
    case 0x11C0:
    case 0x11C1:
        func_L01_0032ADE8(0x11);
        break;
    case 0x11D0:
    case 0x11D1:
        func_L01_0032ADE8(0x29);
        break;
    case 0x1010:
    case 0x1011:
        func_L01_0032ADE8(0x30);
        break;
    case 0x1020:
    case 0x1021:
        func_L01_0032ADE8(0x31);
        break;
    case 0x1030:
    case 0x1031:
        func_L01_0032ADE8(0x32);
        break;
    case 0x1040:
    case 0x1041:
        func_L01_0032ADE8(0x33);
        break;
    case 0x1050:
    case 0x1051:
    case 0x1052:
    case 0x1053:
        break;
    case 0x1060:
    case 0x1061:
        func_L01_0032ADE8(0x34);
        break;
    case 0x1091:
        func_L01_0032ADE8(0x36);
        break;
    case 0x1070:
    case 0x1071:
        func_L01_0032ADE8(0x35);
        break;
    case 0x1090:
        break;
    }
    if (D_L39_00464794[0] > 0) {
        if (D_L39_004647A8 == 3) {
            ((void (*)(void))func_L39_004BB368)();
        }
        if (D_L39_00464794[0] != 0) {
            p = D_L39_004432B8;
            for (i = 0; i < 0x100; i++) {
                p[i] = 0;
            }
            D_L39_004647A4 = 0;
            p = D_L39_00443078;
            for (i = 0; i < 0x100; i++) {
                p[i] = 0;
            }
            D_L39_00464794[0] = 0;
        }
    }
    if (D_L39_00464798[0] > 0) {
        if (D_L39_004647A8 == 3) {
            ((void (*)(void))func_L39_004BB368)();
        }
        if (D_L39_00464798[0] != 0) {
            p = D_L39_00443178;
            for (i = 0; i < 0x100; i++) {
                p[i] = 0;
            }
            D_L39_00464798[0] = 0;
        }
    }
}
/* localdecomp:end func_L39_004B9C88 */

INCLUDE_ASM("asm/levels", func_L39_004BA208);

/* localdecomp:start func_L39_004BA760 */
#include "dnas.h"

extern void *func_L39_004CC800(void);
extern void func_L39_004CC810(void *, void *, s32);
extern s32 func_L39_004BBF08(void *);
extern void *func_L39_004BBF50(void *, s32);
extern s32 func_L39_004BBF98(void *, s32, s32 *, s64 *, s32 *, char **, s32 *);
extern char *func_L39_004BC4F8(s32, s64, s32);
extern void func_L39_004BD350(s32, s32, s32, u32);
extern s32 func_001205B0(char *, char *);
extern void func_00120D28(void *, void *, s32);
extern char D_L39_004750A8[];
extern char D_L39_004750B8[];

static __inline__ void fill_random_004BA760(u8 *p, u32 size) {
    u32 i;

    for (i = 0; i < size; i++) {
        p[i] = func_L39_004D0C78() / 2147483647.0f * 256.0f;
    }
}

s32 func_L39_004BA760(void) {
    u8 buf[0x2000];
    u8 host[0x100];
    s32 a;
    s64 b;
    s32 c;
    char *d;
    s32 e;
    void *ctx;
    s32 n;
    s32 i;
    s32 ret;
    char *name;

    ctx = func_L39_004CC800();
    func_L39_004CC810(ctx, buf, 0x2000);
    n = func_L39_004BBF08(ctx);
    for (i = 0; i < n; i++) {
        if (func_L39_004BBF98(func_L39_004BBF50(ctx, i), 0, &a, &b, &c, &d, &e)) {
            name = func_L39_004BC4F8(a, b, 0);
            if (func_001205B0(name ? name : D_L39_004750A8, D_L39_004750B8) == 0) {
                break;
            }
        }
    }
    if (i == n) {
        ret = -1;
    } else {
        DNAS_BEGIN(func_L39_004BA760, 0, func_L39_004BD350);
        func_00120D28(host, DNAS_STRING("gate1.eu.dnas.playstation.org"), 0x100);
        DNAS_END(func_L39_004BA760, 0, func_L39_004BD350);
        ret = 0;
        if (func_001205B0(d, (char *)host) != 0) {
            ret = -1;
        }
    }
    fill_random_004BA760(buf, 0x2000);
    fill_random_004BA760(host, 0x100);
    return ret;
}
/* localdecomp:end func_L39_004BA760 */

INCLUDE_ASM("asm/levels", func_L39_004BAA78);

/* localdecomp:start func_L39_004BB1E8 */
extern s32 D_L39_00464794[];
extern s32 D_L39_00464798[];
extern u8 D_L39_00443078[];
extern u8 D_L39_00443178[];

long func_L39_004BB1E8(void *bio, s32 oper, u8 *buf, s32 len, long argl, long ret) {
    s32 n;
    s32 i;

    if (ret < 0) {
        return ret;
    }
    if (oper == 0x82) {
        n = D_L39_00464794[0];
        if (n < 0xFF) {
            if (n + len < 0xFF) {
                u8 *p = D_L39_00443078 + n;
                for (i = 0; i < len; i++) {
                    p[i] = buf[i];
                }
                D_L39_00464794[0] += len;
            } else {
                u8 *q = D_L39_00443078 + n;
                for (i = 0; i < 0xFF - n; i++) {
                    q[i] = buf[i];
                }
                D_L39_00464794[0] = 0xFF;
            }
        }
    } else if (oper == 0x83) {
        n = D_L39_00464798[0];
        if (n < 0xFF) {
            if (n + len < 0xFF) {
                u8 *p = D_L39_00443178 + n;
                for (i = 0; i < len; i++) {
                    p[i] = buf[i];
                }
                D_L39_00464798[0] += len;
            } else {
                u8 *q = D_L39_00443178 + n;
                for (i = 0; i < 0xFF - n; i++) {
                    q[i] = buf[i];
                }
                D_L39_00464798[0] = 0xFF;
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004BB1E8 */

/* localdecomp:start func_L39_004BB368 */
extern s32 D_L39_00464798[];
extern s32 D_L39_00464794[];

s32 func_L39_004BB368(void) {
    s32 i;
    s32 n;

    n = D_L39_00464798[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
    n = D_L39_00464794[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
}
/* localdecomp:end func_L39_004BB368 */
