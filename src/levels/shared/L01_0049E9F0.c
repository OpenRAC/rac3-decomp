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

/* localdecomp:start func_L01_0049E9F0 */
extern s32 func_L01_0041A4F0(void);

s32 func_L01_0049E9F0(s32 a0) {
    s32 r = 0;
    if (func_L01_0041A4F0() == 0 || a0 != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_0049E9F0 */

INCLUDE_ASM("asm/levels", func_L01_0049EA38);

INCLUDE_ASM("asm/levels", func_L01_0049EE28);

LINKER_REMNANT("asm/levels", func_L01_0049F150);

/* localdecomp:start func_L01_0049F168 */
extern void func_L01_0049F2C8(void);
extern void func_L01_0049F868_0049F168(void);
extern void func_L01_0049F798(void);
extern void func_L01_0049F8A8_0049F168(void);
extern void func_L01_0049F8C8_0049F168(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0C58;
extern s32 D_L01_001E0C78;
extern s32 D_L01_001E0C98;
extern s32 D_L01_001E0CB8;
extern s32 D_L01_001E0C40[2];
extern s32 D_L01_001E0C60[2];
extern s32 D_L01_001E0C80[2];
extern s32 D_L01_001E0CA0[2];
extern V16_48DCD8 D_L01_001D9628[];
s32 func_L01_0049F168(s32 idx) {
    V16_48DCD8 v;
    if (D_L01_001E0C58 == 0) {
        func_003E6FA0(D_L01_001E0C40, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C58 = 1;
    }
    if (D_L01_001E0C78 == 0) {
        func_003E6FA0(D_L01_001E0C60, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C78 = 1;
    }
    if (D_L01_001E0C98 == 0) {
        func_003E6FA0(D_L01_001E0C80, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C98 = 1;
    }
    if (D_L01_001E0CB8 == 0) {
        func_003E6FA0(D_L01_001E0CA0, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0CB8 = 1;
    }
    v = D_L01_001D9628[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_0049F168 */

INCLUDE_ASM("asm/levels", func_L01_0049F2C8);

INCLUDE_ASM("asm/levels", func_L01_0049F798);

/* localdecomp:start func_L01_0049F868 */
extern void func_L01_00517918(s32);
extern void func_L01_004A03A8_0049F868(void);
extern void func_003A2750(s32);

void func_L01_0049F868(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_004A03A8_0049F868();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0049F868 */

/* localdecomp:start func_L01_0049F8A8 */
extern void func_L01_0047E4B8_0049F8A8();

void func_L01_0049F8A8(void) {
    func_L01_0047E4B8_0049F8A8();
}
/* localdecomp:end func_L01_0049F8A8 */

/* localdecomp:start func_L01_0049F8C8 */
extern void func_L01_0047E520_0049F8C8();

void func_L01_0049F8C8(void) {
    func_L01_0047E520_0049F8C8();
}
/* localdecomp:end func_L01_0049F8C8 */
