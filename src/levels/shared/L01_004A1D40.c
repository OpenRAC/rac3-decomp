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
extern s32 D_L01_001D9660;
extern s32 func_L01_00517748(s32);
extern void func_L01_00516090_004A1AC8(s32);

/* localdecomp:start func_L01_004A1D40 */
extern u8 *D_001D52FC;
__asm__(".extern D_L01_001D9660, 4");
extern s32 func_L01_0047FE28(void);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_004914D0(s32);
extern s32 func_L01_00492870(void);

void func_L01_004A1D40(s32 arg0) {
    u32 flags;

    if (D_L01_001D9660 >= 0 && (*(s32 *)(D_001D52FC + 0x1C4) & 0x40)) {
        func_L01_004A1AC8(arg0);
    }
    flags = *(s32 *)(D_001D52FC + 0x1C4);
    if (flags & 0x910) {
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_004A1AC8(arg0);
    } else if (flags & 1) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_004914D0(0));
        func_L01_00516090_004A1AC8(arg0);
    } else if (flags & 2) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_00492870());
        func_L01_00516090_004A1AC8(arg0);
    }
}
/* localdecomp:end func_L01_004A1D40 */
