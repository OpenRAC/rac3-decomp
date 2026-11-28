#include "common.h"

/* declared by functions of L39_004B9160.c, which this file was cut from */
extern s32 func_L39_004D0C78(void);

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

/* localdecomp:start func_L39_004BA208 */
extern void func_L39_004BB3E8(s32);
extern s32 D_L39_00443074;
extern s32 D_L39_00464794[];
extern s32 D_L39_00464798[];
extern s32 D_L39_0046479C[];
extern s32 D_L39_004647A0;
extern s32 D_L39_004647A8;
extern u8 D_L39_00443078[];
extern u8 D_L39_00443178[];
extern u8 D_L39_00443280[];

void func_L39_004BA208(void *ssl, s32 where, s32 ret) {
    u32 i;
    u8 *p;

    if (where & 0x4000) {
        if (where & 8) {
            switch (ret & 0xFF) {
            case 0x0:
                func_L39_004BB3E8(0x40);
                break;
            case 0xA:
                func_L39_004BB3E8(0x41);
                break;
            case 0x14:
                func_L39_004BB3E8(0x42);
                break;
            case 0x1E:
                func_L39_004BB3E8(0x43);
                break;
            case 0x28:
                func_L39_004BB3E8(0x44);
                break;
            case 0x29:
                func_L39_004BB3E8(0x45);
                D_L39_0046479C[0] = 1;
                break;
            case 0x2A:
                func_L39_004BB3E8(0x46);
                break;
            case 0x2B:
                func_L39_004BB3E8(0x47);
                break;
            case 0x2C:
                func_L39_004BB3E8(0x48);
                break;
            case 0x2D:
                func_L39_004BB3E8(0x49);
                break;
            case 0x2E:
                func_L39_004BB3E8(0x4A);
                break;
            case 0x2F:
                func_L39_004BB3E8(0x4B);
                break;
            case 0x15:
                func_L39_004BB3E8(0x80);
                break;
            case 0x16:
                func_L39_004BB3E8(0x81);
                break;
            case 0x30:
                func_L39_004BB3E8(0x82);
                break;
            case 0x31:
                func_L39_004BB3E8(0x83);
                break;
            case 0x32:
                func_L39_004BB3E8(0x84);
                break;
            case 0x33:
                func_L39_004BB3E8(0x85);
                break;
            case 0x3C:
                func_L39_004BB3E8(0x86);
                break;
            case 0x46:
                func_L39_004BB3E8(0x87);
                break;
            case 0x47:
                func_L39_004BB3E8(0x88);
                break;
            case 0x50:
                func_L39_004BB3E8(0x89);
                break;
            case 0x5A:
                func_L39_004BB3E8(0x8A);
                break;
            case 0x64:
                func_L39_004BB3E8(0x8B);
                break;
            case 0x1:
                func_L39_004BB3E8(0x60);
                break;
            case 0x2:
                func_L39_004BB3E8(0x61);
                D_L39_0046479C[0] = 1;
                break;
            case 0x4:
                func_L39_004BB3E8(0x62);
                break;
            case 0x6:
                func_L39_004BB3E8(0x63);
                break;
            }
        }
        if (where & 4) {
            switch (ret & 0xFF) {
            case 0x0:
                func_L39_004BB3E8(0x50);
                break;
            case 0xA:
                func_L39_004BB3E8(0x51);
                break;
            case 0x14:
                func_L39_004BB3E8(0x52);
                break;
            case 0x1E:
                func_L39_004BB3E8(0x53);
                break;
            case 0x28:
                func_L39_004BB3E8(0x54);
                break;
            case 0x29:
                func_L39_004BB3E8(0x55);
                break;
            case 0x2A:
                func_L39_004BB3E8(0x56);
                break;
            case 0x2B:
                func_L39_004BB3E8(0x57);
                break;
            case 0x2C:
                func_L39_004BB3E8(0x58);
                break;
            case 0x2D:
                func_L39_004BB3E8(0x59);
                break;
            case 0x2E:
                func_L39_004BB3E8(0x5A);
                break;
            case 0x2F:
                func_L39_004BB3E8(0x5B);
                break;
            case 0x15:
                func_L39_004BB3E8(0x90);
                break;
            case 0x16:
                func_L39_004BB3E8(0x91);
                break;
            case 0x30:
                func_L39_004BB3E8(0x92);
                break;
            case 0x31:
                func_L39_004BB3E8(0x93);
                break;
            case 0x32:
                func_L39_004BB3E8(0x94);
                break;
            case 0x33:
                func_L39_004BB3E8(0x95);
                break;
            case 0x3C:
                func_L39_004BB3E8(0x96);
                break;
            case 0x46:
                func_L39_004BB3E8(0x97);
                break;
            case 0x47:
                func_L39_004BB3E8(0x98);
                break;
            case 0x50:
                func_L39_004BB3E8(0x99);
                break;
            case 0x5A:
                func_L39_004BB3E8(0x9A);
                break;
            case 0x64:
                func_L39_004BB3E8(0x9B);
                break;
            case 0x1:
                func_L39_004BB3E8(0x70);
                break;
            case 0x2:
                func_L39_004BB3E8(0x71);
                break;
            case 0x4:
                func_L39_004BB3E8(0x72);
                break;
            case 0x6:
                func_L39_004BB3E8(0x73);
                break;
            }
        }
        if (D_L39_00443074 == 2) {
            if (D_L39_004647A0 > 0) {
                if (D_L39_004647A8 == 3) {
                    ((void (*)(void))func_L39_004BB368)();
                }
                p = D_L39_00443280;
                for (i = 0; i < 0x32; i++) {
                    p[i] = 0;
                }
                D_L39_004647A0 = 0;
            }
        } else if (D_L39_00464794[0] > 0 && (where & 4)) {
            if (D_L39_004647A8 == 3) {
                ((void (*)(void))func_L39_004BB368)();
            }
            p = D_L39_00443078;
            for (i = 0; i < 0x100; i++) {
                p[i] = 0;
            }
            D_L39_00464794[0] = 0;
        } else if (D_L39_00464798[0] > 0 && (where & 8)) {
            if (D_L39_004647A8 == 3) {
                ((void (*)(void))func_L39_004BB368)();
            }
            p = D_L39_00443178;
            for (i = 0; i < 0x100; i++) {
                p[i] = 0;
            }
            D_L39_00464798[0] = 0;
        }
    }
}
/* localdecomp:end func_L39_004BA208 */

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
