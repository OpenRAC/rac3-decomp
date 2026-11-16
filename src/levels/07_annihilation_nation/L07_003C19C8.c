#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* declared by functions of L07_003C0710.c, which this file was cut from */
extern char *D_L07_001DF41C;
extern u8 D_001426E0[];
extern void func_L01_00456230(char *, s32);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L07_003C1E48(char *);
extern void func_L07_003C1E80(char *);
void func_L01_004450F0(s32, s32, s32);
extern void func_L01_00516FD8(s32, void *);
extern s32 func_00381FF0(s32);
typedef struct { u8 pad0[4]; s16 h4; u8 pad6[0x1E]; } E_003C0ED8;
extern E_003C0ED8 D_L07_002BC920[];
extern u8 D_0014275B[];
extern u8 D_L07_001DE554;
extern u8 D_L07_001DE555;

/* localdecomp:start func_L07_003C19C8 */
typedef struct {
    u8 pad0[0x68];
    u8 *p68;
} W_003C19C8;

typedef struct {
    u8 pad0[0x14];
    s32 f14;
    u8 pad18[0xC];
} E_003C19C8;

extern E_003C0ED8 D_L07_002BC920[];
typedef struct { u8 pad0[0x14]; s32 f14; u8 pad18[0xC]; } E_003C19C8b;

extern u8 D_L07_001DE554;
extern u8 D_L07_001DE555;

extern s32 func_L07_003C1B88(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516FD8(s32, void *);
extern void func_L01_005170B8(s32, s32);

void func_L07_003C19C8(W_003C19C8 *arg0, s32 mask, s32 *counter, s32 arg3) {
    u8 *p = arg0->p68;
    s32 i;

    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            u32 t = (u32)(*counter - D_L07_001DE555);
            if (t < 5) {
                s32 id = func_L07_003C1B88(i);
                if (id == -1) {
                    func_L01_00516FD8(t + 0x470024,
                                      (void *)func_00381FF0(((E_003C19C8b *)D_L07_002BC920)[i].f14));
                } else {
                    func_L01_00516FD8(t + 0x470024, (void *)func_00381FF0(id));
                }
                func_L01_005170B8(t + 0x470024, arg3);
                if (*counter == D_L07_001DE554) {
                    p[0x38] = i;
                }
            }
            *counter += 1;
        }
    }
}
/* localdecomp:end func_L07_003C19C8 */

/* localdecomp:start func_L07_003C1AF8 */
extern s32 func_L01_0041A4F0(void);
extern u8 D_0014275B[];
s32 func_L07_003C1AF8(void) {
    if (func_L01_0041A4F0() == 0) {
        return D_0014275B[0] != 0;
    }
    return D_0014275B[0] == 0 ? 2 : 3;
}
/* localdecomp:end func_L07_003C1AF8 */

/* localdecomp:start func_L07_003C1B40 */
f32 func_L07_003C1B40(u8 x) {
    switch (x) {
    case 1: case 3: return 2.0f;
    case 0: case 2: default: return 1.0f;
    }
}
/* localdecomp:end func_L07_003C1B40 */

/* localdecomp:start func_L07_003C1B88 */
extern u8 D_001426E0[];

s32 func_L07_003C1B88(s32 a0) {
    if (D_001426E0[a0 + 0x8E] == 0) {
        switch (a0) {
        case 0: return 0x1505;
        case 1: return 0xC32;
        case 2: return 0x1298;
        case 3: return 0x1299;
        }
    }
    return -1;
}
/* localdecomp:end func_L07_003C1B88 */

/* localdecomp:start func_L07_003C1C08 */
extern u8 D_001426E0[];

s32 func_L07_003C1C08(s32 arg0) {
    if (D_001426E0[arg0 + 0x8E] == 0) {
        switch (arg0) {
        case 0:
            return 0x1504;
        case 1:
            return 0xC3B;
        case 2:
            return 0x129A;
        case 3:
            return 0x129B;
        }
    }
    return -1;
}
/* localdecomp:end func_L07_003C1C08 */

/* localdecomp:start func_L07_003C1C88 */
typedef struct {
    u8 pad0[0x68];
    u8 *p68;
} W_003C1C88;

extern W_003C1C88 *D_L07_001DE550;

extern s32 func_L07_00334A70(s32);

s32 func_L07_003C1C88(void) {
    typedef struct { u8 pad0[2]; s16 h2; u8 pad4[0x20]; } E_003C1C88b;
    E_003C1C88b *e = (E_003C1C88b *)D_L07_002BC920;

    switch (func_L07_00334A70(e[D_L07_001DE550->p68[0x38]].h2)) {
    case 0x7F:
        return 0x129C;
    case 0x47:
        return 0x129D;
    case 0x87:
        return 0x129E;
    case 0x4F:
        return 0x129F;
    case 0x5F:
        return 0x12A1;
    case 0x8F:
        return 0x12A0;
    default:
        return -1;
    }
}
/* localdecomp:end func_L07_003C1C88 */

/* localdecomp:start func_L07_003C1D58 */
extern u8 D_001A4BE0[];
extern f32 func_L01_0040E570(u8 *, u8 *);

s32 func_L07_003C1D58(u8 *a0) {
    s32 r = 0;

    if (D_001A4BE0[0x25E4] == 0) {
        if (*(s16 *)&D_001A4BE0[0x288C] == 0) {
            if (func_L01_0040E570(D_001A4BE0 + 0x80, a0 + 0x10) < 25.0f) {
                r = 1;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L07_003C1D58 */

/* localdecomp:start func_L07_003C1DC8 */
void func_L01_00479200(s32);
void func_L01_0047B3D8(void);
void func_L01_0047B948(void);
void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
void func_L01_003EB350(s32, void *);
void func_L01_003EB3C0(s32, void *);

extern u8 D_L07_001E1EC0[];
extern s32 D_001DE560;
extern s32 D_001DE570;

void func_L07_003C1DC8(s32 arg0) {
    func_L01_00479200(arg0);
    func_L01_0047B3D8();
    func_L01_0047B948();
    func_L01_003EB438(0, D_L07_001E1EC0, D_L07_001E1EC0 + 0x10, 2, 0xA7, 0);
    func_L01_003EB350(0, &D_001DE560);
    func_L01_003EB3C0(0, &D_001DE570);
    func_L01_004450F0(arg0, 3, -1);
}
/* localdecomp:end func_L07_003C1DC8 */

/* localdecomp:start func_L07_003C1E48 */
__asm__(".extern D_L07_001DF41C, 16");
extern char *D_L07_001DF41C;
extern void func_L01_00456230(char *, int);

void func_L07_003C1E48(char *obj) {
    func_L01_00456230(D_L07_001DF41C + (*(int *)(*(char **)(obj + 0x68) + 0xC) << 8), 1);
}
/* localdecomp:end func_L07_003C1E48 */

/* localdecomp:start func_L07_003C1E80 */
__asm__(".extern D_L07_001DF41C, 16");
extern char *D_L07_001DF41C;
extern void func_L01_00456230(char *, int);

void func_L07_003C1E80(char *a)
{
    func_L01_00456230(D_L07_001DF41C + (*(int *)(*(int *)(a + 0x68) + 0x10) << 8), 1);
}
/* localdecomp:end func_L07_003C1E80 */
