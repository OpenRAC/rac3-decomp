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
extern s32 func_L01_004A2240(void);
extern s32 func_L01_00517748(s32);
extern s32 *func_003B9BD0(s32);

/* localdecomp:start func_L01_004A2240 */
extern s32 func_L01_004A2240(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0D18;
extern s32 D_L01_001E0D00[2];
extern void func_L01_004A2298();
extern void func_L01_004A2360();
extern void func_L01_004A22C8();
extern void func_L01_004A23D8_004A2240(void);
extern void func_L01_004A23F8();
s32 func_L01_004A2240(void) {
    if (D_L01_001E0D18 == 0) {
        func_003E6FA0(D_L01_001E0D00, (s32)func_L01_004A2298, (s32)func_L01_004A2360, (s32)func_L01_004A22C8, (s32)func_L01_004A23D8_004A2240, (s32)func_L01_004A23F8);
        D_L01_001E0D18 = 1;
    }
    return (s32)D_L01_001E0D00;
}
/* localdecomp:end func_L01_004A2240 */

/* localdecomp:start func_L01_004A2298 */
extern void *func_003BB3A8(s32);
extern s32 D_L01_001D96E8;
extern s32 D_L01_001D96EC;
extern s32 D_L01_001D96F0;

void func_L01_004A2298(void) {
    D_L01_001D96E8 = ((s32 (*)(s32))func_003BB3A8)(1);
    D_L01_001D96EC = ((s32 (*)(s32))func_003BB3A8)(1);
    D_L01_001D96F0 = 0;
}
/* localdecomp:end func_L01_004A2298 */

INCLUDE_ASM("asm/levels", func_L01_004A22C8);

/* localdecomp:start func_L01_004A2360 */
typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad30[0x1C];
} S_004A2360;
extern s32 D_L01_001D96C0;
extern s32 D_L01_001D96C8;
extern s32 D_L01_001D96CC;
extern s32 D_L01_001D96D0;
extern s32 D_L01_001D96E8;
extern s32 D_L01_001D96EC;
extern s32 D_L01_001DFCC0_004A2360[] __attribute__((section(".sdata")));
extern S_004A2360 D_L01_002E5F30_004A2360;
extern s32 func_003BB468(s32);
extern s32 func_L01_00517918(s32);
extern void func_L01_004A2848(void);
extern s32 func_003A2750(s32);

void func_L01_004A2360(void) {
    D_L01_001D96C8 = -1;
    func_003BB468(D_L01_001D96E8);
    func_003BB468(D_L01_001D96EC);
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    if (D_L01_001D96C0 != 0) {
        func_L01_00517918(0x14);
    }
    func_L01_004A2848();
    func_003A2750(1);
    D_L01_001DFCC0_004A2360[0] = D_L01_001D96CC;
    D_L01_002E5F30_004A2360.f2C = D_L01_001D96D0;
}
/* localdecomp:end func_L01_004A2360 */

/* localdecomp:start func_L01_004A23D8 */
extern void func_L01_0047E4B8_004A23D8();

void func_L01_004A23D8(void) {
    func_L01_0047E4B8_004A23D8();
}
/* localdecomp:end func_L01_004A23D8 */
