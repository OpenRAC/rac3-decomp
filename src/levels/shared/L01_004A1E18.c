#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* declared by functions of L01_004A1910.c, which this file was cut from */
extern E_49E5B8 D_L01_002ED850[];
extern s32 D_L01_001D9660;

/* localdecomp:start func_L01_004A1E18 */
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 D_L01_001D9660;
extern s32 D_L01_001D9658;
extern s32 D_L01_001D96AC;
extern E_49E5B8 D_L01_002ED850[];
extern char D_L01_001D96B0[];

void func_L01_004A1E18(void) {
    D_L01_001D9660 = func_003B9C58(func_003B9BD0(0));
    if (D_L01_001D9660 < 0) {
        return;
    }
    if (D_L01_001D9658 != D_L01_001D9660) {
        if (D_L01_002ED850[D_L01_001D9660].x14) {
            func_L01_00516FD8(0x570005, func_00381FF0(D_L01_002ED850[D_L01_001D9660].x0));
            func_L01_00516FD8(0x570006, func_00381FF0(D_L01_002ED850[D_L01_001D9660].x4));
        } else {
            func_L01_00516FD8(0x570005, func_00381FF0(456));
            func_L01_00516FD8(0x570006, (s32)D_L01_001D96B0);
        }
        D_L01_001D96AC = 30;
    }
    if (D_L01_001D96AC != 0) {
        if (--D_L01_001D96AC == 0) {
            if (D_L01_002ED850[D_L01_001D9660].x14) {
                ((s32 (*)(s32, s32))func_L01_00517190)(0x570009, D_L01_002ED850[D_L01_001D9660].x8 + 1);
                ((s32 (*)(s32, s32))func_L01_00516D60)(0x570009, 1);
            } else {
                ((s32 (*)(s32, s32))func_L01_00516D60)(0x570009, 0);
            }
        }
    }
    D_L01_001D9658 = D_L01_001D9660;
}
/* localdecomp:end func_L01_004A1E18 */
