#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

INCLUDE_ASM("asm/levels", func_L07_003C0710);

INCLUDE_ASM("asm/levels", func_L07_003C0BE8);

/* localdecomp:start func_L07_003C0D00 */
void func_L01_003EB5E0(s32, s32);
void func_L01_004450F0(s32, s32, s32);
void func_L01_005003D0(s32, s32);

void func_L07_003C0D00(s32 arg0) {
    func_L01_005003D0(0, 1);
    func_L01_003EB5E0(0, 2);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003C0D00 */

/* localdecomp:start func_L07_003C0D48 */
extern u8 *D_001DE550_sda;
__asm__(".extern D_001DE550_sda, 4");
extern u8 D_L07_001E1710_003C0D48 __asm__("D_L07_001E1710");
__asm__(".extern D_L07_001E1710, 16");
extern u8 D_L07_001E1708_003C0D48 __asm__("D_L07_001E1708");
__asm__(".extern D_L07_001E1708, 16");
extern void func_L01_00516FD8(s32, void *);
extern s32 func_00381FF0(s32);
extern void func_L07_003C0FC8(void *, void *, void *, void *);
extern void func_L07_003C17C0(void *);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);

void func_L07_003C0D48(void) {
    u8 *obj = D_001DE550_sda;
    u8 *d = *(u8 **)(obj + 0x68);

    func_L01_00516FD8(0x47001E, &D_L07_001E1710_003C0D48);
    func_L01_00516FD8(0x470019, (void *)func_00381FF0(0xC45));
    func_L01_00516FD8(0x47001A, &D_L07_001E1708_003C0D48);
    func_L01_00516FD8(0x470007, (void *)func_00381FF0(0xC44));
    func_L07_003C0FC8(d + 0x20, d + 0x24, d + 0x39, d + 0x3A);
    func_L07_003C17C0(obj);
    func_L01_005003D0(0x74, 1);
    func_L01_004450F0((s32)obj, 4, -1);
}
/* localdecomp:end func_L07_003C0D48 */

/* localdecomp:start func_L07_003C0E08 */
extern char *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");

extern void func_L07_00330748(s32 a);
void func_L01_004450F0(s32, s32, s32);
void func_L07_003C0E08(O_B *a0) {
    func_L07_00330748((s32)(D_L07_001DF41C + (a0->p68->idx << 8)));
    func_L01_004450F0((s32)a0, 6, -1);
}
/* localdecomp:end func_L07_003C0E08 */

/* localdecomp:start func_L07_003C0E58 */
extern char *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern void func_L01_004F50C8(void *a, void *b, s32 c, s32 d);
extern void func_L07_003BA500(void *p, s32 flag);

void func_L07_003C0E58(char *obj, s32 flag) {
    char *p = D_L07_001DF41C + (**(s32 **)(obj + 0x68) << 8);
    func_L01_004F50C8(p + 0x10, p + 0xF0, 0x74, 1);
    func_L07_003BA500(p, flag & 0xFF);
    func_L01_004450F0(obj, 5, -1);
}
/* localdecomp:end func_L07_003C0E58 */

/* localdecomp:start func_L07_003C0ED8 */
typedef struct { u8 pad0[4]; s16 h4; u8 pad6[0x1E]; } E_003C0ED8;
extern E_003C0ED8 D_L07_002BC920[];
extern void func_L07_003C0F40(u8 *);
void func_L07_003C0ED8(u8 *arg0, s32 i) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    E_003C0ED8 *e = &D_L07_002BC920[i];
    if (e->h4 == -1) {
        func_L01_004450F0(arg0, 8, -1);
    } else {
        p[0x38] = e->h4;
        func_L07_003C0F40(arg0);
    }
}
/* localdecomp:end func_L07_003C0ED8 */

INCLUDE_ASM("asm/levels", func_L07_003C0F40);

INCLUDE_ASM("asm/levels", func_L07_003C0FC8);

/* localdecomp:start func_L07_003C1120 */
extern u8 D_0014275B[];
s32 func_L07_003C1120(s32 arg0) {
    if (arg0 == 0) {
        return D_0014275B[0];
    }
    return 1;
}
/* localdecomp:end func_L07_003C1120 */

INCLUDE_ASM("asm/levels", func_L07_003C1138);

INCLUDE_ASM("asm/levels", func_L07_003C12A8);

INCLUDE_ASM("asm/levels", func_L07_003C1360);

/* localdecomp:start func_L07_003C1430 */
extern u8 D_001D5551[];

u8 func_L07_003C1430(s32 arg0) {
    u8 var_v0;

    var_v0 = 1;
    if (arg0 == 0) {
        var_v0 = D_001D5551[0];
    }
    return var_v0;
}
/* localdecomp:end func_L07_003C1430 */

INCLUDE_ASM("asm/levels", func_L07_003C1448);

INCLUDE_ASM("asm/levels", func_L07_003C1528);

INCLUDE_ASM("asm/levels", func_L07_003C17C0);

INCLUDE_ASM("asm/levels", func_L07_003C19C8);

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

INCLUDE_ASM("asm/levels", func_L07_003C1C88);

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

INCLUDE_ASM("asm/levels", func_L07_003C1EB8);
