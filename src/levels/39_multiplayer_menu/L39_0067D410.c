#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067A788.c, which this file was cut from */
extern void func_L39_00595628(u8 *, u8 *);

/* localdecomp:start func_L39_0067D410 */
__asm__(".extern D_L39_00247A80, 16");
__asm__(".extern D_L39_00247A84, 16");
__asm__(".extern D_L39_00247A88, 16");
__asm__(".extern D_L39_00247A8C, 16");
extern f32 D_L39_00247A80;
extern f32 D_L39_00247A84;
extern f32 D_L39_00247A88;
extern f32 D_L39_00247A8C;
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005169C8(s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);

void func_L39_0067D410(f32 x, f32 y, f32 w, f32 h, f32 dy, s32 top, s32 bottom) {
    s32 color;
    f32 t;

    func_L01_00516AA0(0x450023, 1, 1);
    func_L01_00516AA0(0x450024, 1, 0);
    func_L01_00516AA0(0x450025, 1, 0);
    func_L01_00516470(0x450023, x, y);
    func_L01_00517538(0x450023, w, h);
    func_L01_00516470(0x450024, x + D_L39_00247A80, (y - dy) + D_L39_00247A84);
    func_L01_00516470(0x450025, x + D_L39_00247A80, (y + dy) + D_L39_00247A84);
    func_L01_00517538(0x450024, 0.5f, 0.5f);
    func_L01_00517538(0x450025, 0.5f, -0.5f);
    t = (w + D_L39_00247A8C) * D_L39_00247A88;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    func_L01_005169C8(0x450024, t);
    func_L01_005169C8(0x450025, t);
    color = func_0038DBD8(0x332299DE, 0x2299DE, 0.5f);
    func_L01_005170B8(0x450024, color);
    func_L01_005170B8(0x450023, 0x332299DE);
    func_L01_005170B8(0x450025, color);
    func_L01_00516C78(0x450023, 3, 3);
    func_L01_00516C78(0x450024, 3, 3);
    func_L01_00516C78(0x450025, 3, 3);
}
/* localdecomp:end func_L39_0067D410 */

/* localdecomp:start func_L39_0067D658 */
void func_L39_006121B0(s32);
void func_L39_00681470();

void func_L39_0067D658(void) {
    func_L39_006121B0(0);
    func_L39_006121B0(1);
    func_L39_00681470();
}
/* localdecomp:end func_L39_0067D658 */

/* localdecomp:start func_L39_0067D688 */
typedef struct { s32 f0; u8 pad[0x84]; s32 f88; } S_0067D688;
extern S_0067D688 *func_00137008(void *, s32);
extern s32 func_L01_00516FD8(s32, s32);
__asm__(".extern D_L39_0024D110, 16");
extern s32 D_L39_0024D110;
extern u8 D_L39_00370D00[];
__asm__(".extern D_001DB1C8_sda, 4");
extern f32 D_001DB1C8_sda;
__asm__(".extern D_L39_002468DC, 16");
extern f32 D_L39_002468DC;

void func_L39_0067D688(void) {
    S_0067D688 *p = func_00137008(D_L39_00370D00, D_L39_0024D110);

    func_L01_00516470(0x450010, D_001DB1C8_sda, D_L39_002468DC);
    func_L01_00516C78(0x450010, 3, 3);
    func_L01_005170B8(0x450010, 0x8066CCFF);
    if (p->f0 >= 0) {
        func_L01_00516FD8(0x450010, (s32)&p->f88);
        func_L01_00516AA0(0x450010, 1, 1);
    } else {
        func_L01_00516FD8(0x450010, 0);
        func_L01_00516AA0(0x450010, 1, 0);
    }
}
/* localdecomp:end func_L39_0067D688 */

/* localdecomp:start func_L39_0067D758 */
typedef struct { s32 f0; s32 f4; u8 f8[0x40]; u8 f48[0x40]; u8 f88[0x40]; } S_0067D758;
__asm__(".extern D_001DB154_sda, 4");
__asm__(".extern D_001DB1F8_sda, 4");
__asm__(".extern D_001DB158_sda, 4");
__asm__(".extern D_001DB15C_sda, 4");
__asm__(".extern D_001DB160_sda, 4");
__asm__(".extern D_001DB164_sda, 4");
__asm__(".extern D_001DB168_sda, 4");
__asm__(".extern D_001DB16C_sda, 4");
__asm__(".extern D_001DB170_sda, 4");
__asm__(".extern D_001DB171_sda, 4");
__asm__(".extern D_001DB1D0_sda, 4");
__asm__(".extern D_001DB1D4_sda, 4");
__asm__(".extern D_001DB1D8_sda, 4");
__asm__(".extern D_001DB1DC_sda, 4");
typedef struct { u8 pad[0x1C4]; s32 f1C4; } Pad_0067D758;
extern s32 D_L39_00242910;
extern f32 D_L39_00247A30;
extern u8 D_L39_00247A34;
extern s32 D_L39_00247A38;
extern s32 D_L39_00241440;
extern Pad_0067D758 *D_L39_00241164;
extern s32 D_L39_0024D110;
extern s32 D_L39_0024D150;
typedef struct { char s[8]; s32 id[11]; } Msg_0067D758;
extern Msg_0067D758 D_L39_00246900_0067D758 __attribute__((section(".sdata")));
typedef struct { u8 buf[0x28]; s32 a; s32 b; s32 c; } Net_0067D758;
extern Net_0067D758 D_L39_0024D118_0067D758 __attribute__((section(".sdata")));
extern f32 D_L39_00245C38;
extern s32 D_L39_0024BB44;
extern u8 D_L39_002468F0[];
extern char D_L39_002468F8[];
extern char D_L39_00246900[];
extern char D_L39_0036FD40[];
extern char D_L39_00370C40[];
extern u8 D_L39_00370D00[];
extern u8 D_L39_00371500[];
extern char D_L39_00372840[];
extern char D_L39_00372940[];
extern s32 D_001A43E8[];
extern s32 D_001DB154_sda;
extern s32 D_001DB1F8_sda;
extern s32 D_001DB158_sda;
extern s32 D_001DB15C_sda;
extern s32 D_001DB160_sda;
extern s32 D_001DB164_sda;
extern s32 D_001DB168_sda;
extern s32 D_001DB16C_sda;
extern u8 D_001DB170_sda;
extern u8 D_001DB171_sda;
extern f32 D_001DB1D0_sda;
extern f32 D_001DB1D4_sda;
extern f32 D_001DB1D8_sda;
extern s32 D_001DB1DC_sda;
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L01_005168F0(s32, f32);
extern s32 func_L01_00518010(s32, s32);
extern void func_L01_00518670(s32, s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern s32 func_L39_005F3548(s32, s32, void *);
extern void func_L39_00611628(s32, char *);
extern f32 func_0038D0B0(f32);
extern void func_0038E150(s32);
extern s32 func_0038E548(char *, s32, f32);
extern void func_L01_00478898(void);
extern void func_L39_0067CE48(char *);
extern void func_L39_0067CED8(void);
extern s32 func_L39_0067CEA0();
extern void func_L39_0067D688(void);
extern void func_L39_0067D410(f32, f32, f32, f32, f32, s32, s32);
extern s32 func_L39_0067EB98(void);
extern int func_L39_0067EBD0(void);
extern s32 func_00120048(char *, char *, ...);
extern void *func_001206F4(void *, void *);
extern s32 func_00120884(char *);
extern void func_00120D28(void *, void *, s32);
extern void func_001264E0(s32);
extern s32 func_00136ED0(void *, s32, void *);
extern s32 func_001370B8(void *, void *, void *);
extern s32 func_00137370(void *);
extern void func_00137490(void);
extern void func_001375B0(void *, void *, s32);
extern char *func_00381FF0(s32);

void func_L39_0067D758(void) {
    char buf[0x100];
    S_0067D758 *e;
    u8 *name;
    s32 now2, mode2, r2, i3, t8, now7, prev7, dt7, a, c, col, pad, found, i, idx, len, t;
    f32 y, ang;
    char *s, *pc;
    s32 id, tid;

    if (D_L39_00242910 == -2) {
        if (D_L39_00247A34 != 0) {
            func_003C4138(&D_L39_00247A30, 0.0f, 0.07792208f);
        } else {
            func_003C4138(&D_L39_00247A30, 1.0f, 0.07792208f);
        }
        col = func_0038DBD8(D_L39_00247A38 & 0xFFFFFF, D_L39_00247A38, D_L39_00247A30);
        func_L01_005170B8(0x450001, col);
        func_L01_005170B8(0x450002, col);
        if (D_L39_00247A34 != 0) {
            if (D_L39_00247A30 == 0.0f) {
                if (D_001DB154_sda == 12) {
                    a = 10;
                    D_L39_00242910 = -2;
                } else {
                    D_L39_00241440 = 0;
                    D_L39_00242910 = -2;
                    a = 12;
                }
                func_L39_005BF798(a, 2, 0, 0, 0);
            }
            return;
        }
    }
    func_L01_00516AA0(0x450026, 1, 0);
    name = D_L39_002468F0;
    D_001DB1DC_sda++;
    switch (D_001DB154_sda) {
    case 1:
        if (D_001DB171_sda != 0) {
            D_001DB171_sda = 0;
            D_001DB154_sda = 3;
        } else {
            D_001DB171_sda = 0;
            D_001DB154_sda = 2;
        }
        break;
    case 2:
        now2 = func_L39_0067CEA0();
        mode2 = D_001A43E8[0];
        if (mode2 != 2) {
            D_001DB164_sda = 0;
            func_00120048(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[1]), 1);
            D_001DB154_sda = 11;
            D_001DB158_sda = 2;
            D_001DB160_sda = 13;
            D_001DB15C_sda = 0;
            break;
        }
        if (D_001DB164_sda == 0 || now2 - D_001DB164_sda > 1000) {
            D_001DB164_sda = now2;
            D_L39_0024D150 = r2 = func_00136ED0(name, 6, D_L39_00370D00);
            if (r2 > 0) {
                D_001DB154_sda = 3;
            } else {
                if (r2 == -15) {
                    func_001206F4(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[2]));
                    D_001DB154_sda = 11;
                    D_001DB158_sda = 2;
                    D_001DB160_sda = 13;
                    D_001DB15C_sda = 0;
                } else if (r2 == 0) {
                    func_001206F4(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[0]));
                    D_001DB154_sda = 11;
                    D_001DB158_sda = 2;
                    D_001DB160_sda = 13;
                    D_001DB15C_sda = 0;
                } else {
                    func_00120048(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[3]), 1);
                    D_001DB154_sda = 11;
                    D_001DB158_sda = 2;
                    D_001DB160_sda = 13;
                    D_001DB15C_sda = 0;
                }
            }
        }
        break;
    case 3:
        if (D_001A43E8[0] == 2) {
            D_L39_0024D110 = -1;
            for (i3 = 1; i3 < 5; i3++) {
                if (func_00137008(D_L39_00370D00, i3)->f0 >= 0) {
                    D_L39_0024D110 = i3;
                    break;
                }
            }
            if (D_L39_0024D110 >= 0) {
                D_001DB154_sda = 4;
            } else {
                func_00120048(D_L39_00372840, func_00381FF0(D_001DB1F8_sda));
                D_001DB154_sda = 11;
                D_001DB15C_sda = 3;
                D_001DB160_sda = 13;
                D_001DB158_sda = 0;
            }
        } else {
            func_00120048(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[8]));
            D_001DB154_sda = 11;
            D_001DB158_sda = 2;
            D_001DB160_sda = 13;
            D_001DB15C_sda = 0;
        }
        break;
    case 4:
        if (D_001A43E8[0] != 2) {
            D_001DB154_sda = 2;
            break;
        }
        func_L39_0067D688();
        pad = D_L39_00241164->f1C4;
        if (pad & 0x4000) {
            func_L39_005F3548(3, 0, 0);
            found = 0;
            for (i = 1; i < 5; i++) {
                idx = D_L39_0024D110 + i;
                if (idx >= 5) {
                    idx -= 4;
                }
                if (func_00137008(D_L39_00370D00, idx)->f0 >= 0) {
                    D_L39_0024D110 = idx;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                func_001206F4(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[0]));
                D_001DB154_sda = 11;
                D_001DB15C_sda = 3;
                D_001DB160_sda = 13;
                D_001DB158_sda = 0;
            }
        } else if (pad & 0x1000) {
            func_L39_005F3548(3, 0, 0);
            found = 0;
            for (i = 1; i < 5; i++) {
                idx = D_L39_0024D110 - i;
                if (idx <= 0) {
                    idx += 4;
                }
                if (func_00137008(D_L39_00370D00, idx)->f0 >= 0) {
                    D_L39_0024D110 = idx;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                func_001206F4(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[0]));
                D_001DB154_sda = 11;
                D_001DB15C_sda = 3;
                D_001DB160_sda = 13;
                D_001DB158_sda = 0;
            }
        } else if (pad & 0x840) {
            D_L39_00372840[0] = 0;
            D_L39_0036FD40[0] = 0;
            func_L39_005F3548(4, 0, 0);
            D_001DB154_sda = 5;
        } else if (pad & 0x10) {
            func_L39_005F3548(0x17, 0, 0);
            D_001DB154_sda = 13;
        } else if (pad & 0x80) {
            func_L39_005F3548(4, 0, 0);
            func_L39_0067CED8();
        }
        break;
    case 5:
        e = (S_0067D758 *)func_00137008(D_L39_00370D00, D_L39_0024D110);
        if (e != 0) {
            func_00120D28(D_L39_00372940, e->f88, 0x31);
            D_L39_00372940[0x32] = 0;
        }
        if (func_001370B8(name, e->f8, D_L39_00371500) < 0) {
            func_001206F4(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[4]));
            D_001DB154_sda = 11;
            D_001DB15C_sda = 5;
            D_001DB160_sda = 13;
            D_001DB158_sda = 0;
        } else {
            D_001DB154_sda = 6;
        }
        break;
    case 6:
        D_001DB154_sda = 7;
        break;
    case 7:
        now7 = func_L39_0067CEA0();
        prev7 = D_001DB168_sda;
        dt7 = prev7 < 0 ? 3000 : now7 - prev7;
        if (dt7 >= 3000) {
            D_001DB16C_sda = now7;
            func_001264E0(0);
            if (func_00137370(D_L39_00371500) == -1) {
                func_00120048(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[5]), D_L39_00372940);
                D_001DB154_sda = 11;
                D_001DB158_sda = 1;
                D_001DB160_sda = 13;
                D_001DB15C_sda = 0;
            } else {
                func_00137490();
                D_001DB154_sda = 8;
            }
        }
        break;
    case 8:
        t8 = func_L39_0067CEA0() - D_001DB16C_sda;
        func_001375B0(&D_L39_0024D118_0067D758, D_L39_00372840, 0x100);
        func_L39_0067CE48(D_L39_00372840);
        if (D_L39_0024D118_0067D758.a == 4) {
            if (D_L39_0024D118_0067D758.b == 0) {
                func_001206F4(D_L39_00372840, func_00381FF0(0x1285));
            } else if (D_L39_0024D118_0067D758.b == -302) {
                func_001206F4(D_L39_00372840, func_00381FF0(0x1281));
            } else {
                func_001206F4(D_L39_00372840, func_00381FF0(0x1281));
            }
        }
        if (D_L39_0024D118_0067D758.c == 3) {
            D_001DB154_sda = 12;
        } else if (D_L39_0024D118_0067D758.c == 5) {
            D_001DB154_sda = 9;
            D_001DB15C_sda = 7;
            D_001DB160_sda = 13;
            D_001DB158_sda = 0;
            D_001DB170_sda = 0;
        } else if (t8 > 30000) {
            func_001206F4(D_L39_00372840, func_00381FF0(D_L39_00246900_0067D758.id[6]));
            D_001DB154_sda = 9;
            D_001DB15C_sda = 7;
            D_001DB160_sda = 13;
            D_001DB170_sda = 1;
            D_001DB158_sda = 0;
        }
        if (D_L39_00241164->f1C4 & 0x10) {
            func_L39_005F3548(0x17, 0, 0);
            D_001DB154_sda = 9;
            D_001DB158_sda = 13;
        }
        break;
    case 9:
        func_L39_0067EB98();
        D_001DB154_sda = 10;
        break;
    case 10:
        func_001375B0(&D_L39_0024D118_0067D758, buf, 0x100);
        if (D_001DB158_sda == 13) {
            D_001DB154_sda = 13;
        } else if (D_L39_0024D118_0067D758.c == 5 || func_L39_0067EBD0() > 30000) {
            D_001DB154_sda = 11;
        }
        break;
    case 11:
        if ((D_001DB158_sda != 0 || D_001DB15C_sda != 0) && (D_L39_00241164->f1C4 & 0x40)) {
            if (D_001DB158_sda != 0) {
                D_001DB154_sda = D_001DB158_sda;
                D_L39_00372840[0] = 0;
                D_001DB158_sda = 0;
                D_001DB15C_sda = 0;
                D_001DB160_sda = 0;
            } else if (D_001DB15C_sda != 0) {
                D_001DB154_sda = D_001DB15C_sda;
                D_L39_00372840[0] = 0;
                D_001DB158_sda = 0;
                D_001DB15C_sda = 0;
                D_001DB160_sda = 0;
            }
        } else if (D_001DB160_sda != 0 && (D_L39_00241164->f1C4 & 0x10)) {
            func_L39_005F3548(0x17, 0, 0);
            D_L39_00372840[0] = 0;
            D_001DB154_sda = D_001DB160_sda;
            D_001DB158_sda = 0;
            D_001DB15C_sda = 0;
            D_001DB160_sda = 0;
        } else if (D_L39_00241164->f1C4 & 0x80) {
            func_L39_0067CED8();
        }
        break;
    case 12:
    case 13:
        break;
    }
    for (id = 0x45000E; id <= 0x45001C; id++) {
        func_L01_00516AA0(id, 1, 0);
        D_L39_0036FD40[(id - 0x45000E) * 0x100] = 0;
    }
    func_L01_00516AA0(0x45001E, 1, 0);
    func_L01_00516C78(0x45000E, 1, 3);
    func_L01_00516AA0(0x45000C, 1, 0);
    switch (D_001DB154_sda) {
    case 1:
        func_00120048(D_L39_0036FD40, D_L39_002468F8, func_00381FF0(0x12C0));
        func_L01_00516AA0(0x45000E, 1, 1);
        func_L01_00516C78(0x45000E, 3, 3);
        func_L01_00516470(0x45000E, 0.5f, 0.2f);
        func_L01_005170B8(0x45000E, 0x8066CCFF);
        func_L01_00516AA0(0x45000A, 1, 0);
        break;
    case 2:
        func_00120048(D_L39_0036FD40, D_L39_002468F8, func_00381FF0(0x1193));
        func_L01_00516AA0(0x45000E, 1, 1);
        func_L01_00516470(0x45000E, 0.1f, 0.2f);
        func_L01_005170B8(0x45000E, 0x8066CCFF);
        func_L01_00516AA0(0x45000A, 1, 0);
        break;
    case 3:
        func_00120048(D_L39_0036FD40, D_L39_002468F8, func_00381FF0(0x1193));
        func_L01_00516AA0(0x45000E, 1, 1);
        func_L01_00516470(0x45000E, 0.15f, 0.2f);
        func_L01_005170B8(0x45000E, 0x8066CCFF);
        func_L01_00516AA0(0x45000A, 1, 0);
        break;
    case 4:
        func_L01_00516AA0(0x450026, 1, 1);
        func_00120048(D_L39_0036FD40, func_00381FF0(0x1194));
        func_L01_00516C78(0x45000E, 3, 3);
        func_L01_00516AA0(0x45000E, 1, 1);
        func_L01_00516AA0(0x45000E, 0x40, 1);
        func_L01_00516470(0x45000E, 0.5f, 0.2f);
        func_L01_005170B8(0x45000E, 0x8066CCFF);
        func_L01_00517538(0x45001F, 0.82f, D_001DB1D8_sda);
        func_L01_00516FD8(0x45000A, (s32)func_00381FF0(0x124));
        func_L01_00516AA0(0x45000A, 1, 1);
        func_L01_00516AA0(0x450010, 1, 1);
        func_0038E150(1);
        for (i = 1; i < 5; i++) {
            y = ((f32)(i - 1) - 1.5f) * (D_001DB1D8_sda - 0.02f) * 0.25f + 0.5f;
            tid = i + 0x450010;
            e = (S_0067D758 *)func_00137008(D_L39_00370D00, i);
            if (e->f0 >= 0) {
                if (i < 4) {
                    func_L01_00516470(i + 0x45001F, 0.5f,
                                      ((f32)(i - 1) + 0.5f - 1.5f) * (D_001DB1D8_sda - 0.02f) * 0.25f + 0.5f);
                }
                if (i == D_L39_0024D110) {
                    func_L39_0067D410(0.5f, y, 0.8f, D_001DB1D0_sda, D_001DB1D4_sda, i >= 2, i < 4);
                    t = D_001DB1DC_sda % 40;
                    c = func_0038DBD8(0x8066CCFF, 0x80FFFFFF, func_0038D0B0((f32)t * 3.1415927f / 20.0f) * 0.5f + 0.5f);
                } else {
                    c = 0x8066CCFF;
                }
                func_L01_005170B8(tid, c);
                func_003E7F20(tid, 1);
                func_L01_00516470(tid, 0.12f, y);
                s = &D_L39_0036FD40[0x200] + (i << 8);
                func_00120048(s, D_L39_00246900, i, e->f48);
                len = func_00120884(s);
                if ((f32)func_0038E548(s, len, 1.0f) * (1.0f / D_L39_00245C38) > 0.76f) {
                    do {
                        s[len - 1] = '.';
                        s[len] = '.';
                        s[len + 1] = '.';
                        s[len + 2] = 0;
                        len--;
                    } while ((f32)func_0038E548(s, func_00120884(s), 1.0f) * (1.0f / D_L39_00245C38) > 0.76f);
                }
                func_L39_00611628(tid, buf);
                func_L01_00516AA0(tid, 1, 1);
            } else {
                if (i < 4) {
                    func_L01_00516470(i + 0x45001F, 0.5f, 2.0f);
                }
                func_L01_005170B8(tid, 0x8066CCFF);
                func_L01_00516470(tid, 0.15f, (f32)(i - 1) * 0.05f + 0.3f);
                func_L01_00516AA0(tid, 1, 0);
                func_00120048(&D_L39_0036FD40[0x200] + (i << 8), func_00381FF0(D_L39_00246900_0067D758.id[10]), i);
            }
        }
        func_L01_005170B8(0x45001C, 0x8066CCFF);
        func_L01_00516C78(0x45001C, 3, 3);
        func_L01_00516470(0x45001C, 0.5f, 0.93f);
        func_L01_00516AA0(0x45001C, 1, 1);
        func_L01_00516AA0(0x45001C, 0x40, 1);
        func_L01_00517538(0x45001C, 0.9f, 0.9f);
        func_00120048(&D_L39_0036FD40[0xE00], func_00381FF0(0x12C1));
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        ang = (f32)(D_L39_0024BB44 % 60) * -6.2831855f / 60.0f + 3.1415927f;
        func_L01_00516AA0(0x45000C, 1, 1);
        func_L01_005168F0(0x45000C, ang);
        func_00120048(D_L39_0036FD40, D_L39_00372840);
        func_L01_00516AA0(0x45000E, 1, 1);
        func_L01_00516470(0x45000E, 0.5f, 0.2f);
        func_L01_00516C78(0x45000E, 3, 3);
        func_L01_005170B8(0x45000E, 0x8066CCFF);
        func_L01_00518010(0x45000E, 1);
        func_003E8898(0x45000E, 0.8f, 0.0f);
        func_L01_00516AA0(0x45000A, 1, 0);
        break;
    case 11:
        func_00120048(D_L39_0036FD40, func_00381FF0(D_L39_00246900_0067D758.id[9]));
        func_L01_00516AA0(0x45000E, 1, 1);
        func_L01_00516470(0x45000E, 0.15f, 0.2f);
        func_L01_005170B8(0x45000E, 0x8066CCFF);
        func_00120048(D_L39_00370C40, D_L39_00372840);
        func_L01_00516AA0(0x45001E, 1, 1);
        func_L01_00516470(0x45001E, 0.5f, 0.3f);
        func_L01_00517538(0x45001E, 0.8f, 0.2f);
        func_L01_00518670(0x45001E, 1, 1);
        func_003E7F20(0x45001E, 1);
        func_L01_005170B8(0x45001E, func_0038DBD8(0x80000000, 0x8066CCFF, 0.75f));
        func_L01_00516FD8(0x45000A, (s32)func_00381FF0(0x125D));
        func_L01_00516AA0(0x45000A, 1, 1);
        func_L01_005170B8(0x45001C, 0x8066CCFF);
        func_L01_00516C78(0x45001C, 3, 3);
        func_L01_00516470(0x45001C, 0.5f, 0.93f);
        func_L01_00516AA0(0x45001C, 1, 1);
        func_L01_00516AA0(0x45001C, 0x40, 1);
        func_L01_00517538(0x45001C, 0.9f, 0.9f);
        func_00120048(&D_L39_0036FD40[0xE00], func_00381FF0(0x12C1));
        break;
    case 12:
    case 13:
        break;
    }
    func_L01_00478898();
    if (D_001DB154_sda == 13) {
        D_L39_00247A34 = 1;
    } else if (D_001DB154_sda == 12) {
        D_L39_00247A34 = 1;
    }
}
/* localdecomp:end func_L39_0067D758 */

/* localdecomp:start func_L39_0067EB98 */
void func_00137520();
s32 func_L39_0067CEA0();
extern s32 D_001A5DF0[];
extern s32 D_001DB168_sda;

s32 func_L39_0067EB98(void) {
    D_001DB168_sda = func_L39_0067CEA0();
    func_00137520();
    D_001A5DF0[0] = 2;
    return 0;
}
/* localdecomp:end func_L39_0067EB98 */

/* localdecomp:start func_L39_0067EBD0 */
int func_L39_0067EBD0(void) { int r = func_L39_0067CEA0(); int g = D_001DB168_sda; return g < 0 ? 3000 : r - g; }
/* localdecomp:end func_L39_0067EBD0 */

/* localdecomp:start func_L39_0067EC00 */
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_001915F0(void);
extern int D_001E1A60_sda;

/* from rac4-decomp's func_L00_00708228 */
void func_L39_0067EC00(void) {
    D_001E1A60_sda = func_001260F0(func_00126150(), 0x3C);
    func_001915F0();
}
/* localdecomp:end func_L39_0067EC00 */

/* localdecomp:start func_L39_0067EC30 */
typedef struct S_0067EC30 {
    u8 pad0[2];
    u16 count;
    u8 pad4[0xAC];
} S_0067EC30;

extern int D_001A5CD0[];
typedef struct S_0067EC30_D { int a; u8 pad[0x14]; } S_0067EC30_D;
__asm__(".extern D_L39_0024D158, 16");
extern int D_L39_0024D158;
extern int D_001E1A48_sda;
extern void *func_0011D534(void *, s32, s32);
extern int func_00191698(int, void *);
extern void func_00190EF0(int, int *);
extern int func_00191010(int, S_0067EC30 *);
extern void func_00191258(int, S_0067EC30 *, int *);
extern void func_00191878(int, void *);
extern int func_001917B8(int);

int func_L39_0067EC30(void) {
    u8 buf[0x20];
    u8 info[0x10];
    S_0067EC30 st;
    int n;

    func_0011D534(&D_L39_0024D158, 0, 0x18);
    if (D_001A5CD0[4] == -1) {
        if (func_00191698(0, info) == 0) {
            func_00190EF0(0, &D_001A5CD0[4]);
        }
    } else if (func_00191010(D_001A5CD0[4], &st) == 0) {
        if (st.count != 0) {
            func_00191258(D_001A5CD0[4], &st, &D_L39_0024D158);
            for (n = 0; n < st.count; n++) {
            }
            func_00191878(D_001A5CD0[4], buf);
        }
    } else {
        func_001917B8(D_001A5CD0[4]);
        D_001A5CD0[4] = -1;
        return D_L39_0024D158;
    }
    return D_001E1A48_sda;
}
/* localdecomp:end func_L39_0067EC30 */

/* localdecomp:start func_L39_0067ED40 */
extern int D_001A5CD0[];
__asm__(".extern D_L39_0024D170, 16");
extern int D_L39_0024D170;
extern int func_001917B8(int);
extern void func_00191640(void);
extern int func_00126150(void);
extern int func_001260F0(int, int);

void func_L39_0067ED40(void) {
    int *p = D_001A5CD0;
    func_001917B8(p[4]);
    p[4] = -1;
    func_00191640();
    func_001260F0(func_00126150(), D_L39_0024D170);
}
/* localdecomp:end func_L39_0067ED40 */

/* localdecomp:start func_L39_0067ED90 */
extern T D_L39_004AE080[];
extern void func_001377D0(int, int, int);
void func_L39_0067ED90(unsigned int i) {
    if (i < 6) func_001377D0(D_L39_004AE080[i].a, D_L39_004AE080[i].b, D_L39_004AE080[i].c);
}
/* localdecomp:end func_L39_0067ED90 */

LINKER_REMNANT("asm/levels", func_L39_0067EDD8);
