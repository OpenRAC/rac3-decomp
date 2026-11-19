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

INCLUDE_ASM("asm/levels", func_L01_0049FBC8);

INCLUDE_ASM("asm/levels", func_L01_0049FDF0);

/* localdecomp:start func_L01_004A02B8 */
extern S_func_0049A930 D_00160C40[];
extern s32 D_L01_001D9590;
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);

void func_L01_004A02B8(void) {
    D_L01_001D9590 = (s32)func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), D_L01_001D9590, 0, D_00160C40->f4954, (s32)D_00160C40->f4B90);
}
/* localdecomp:end func_L01_004A02B8 */

INCLUDE_ASM("asm/levels", func_L01_004A0300);

INCLUDE_ASM("asm/levels", func_L01_004A03A8);

INCLUDE_ASM("asm/levels", func_L01_004A0430);

INCLUDE_ASM("asm/levels", func_L01_004A04B8);

/* localdecomp:start func_L01_004A0608 */

extern s32 D_L01_002ED730[];
extern S_236B80 D_L01_00236B00;

extern s32 func_L01_00516FD8(s32 id, s32 v);

void func_L01_004A0608(void) {
    func_L01_00516FD8(0x54000A, D_L01_00236B00.v[0][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54000E, D_L01_00236B00.v[1][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540012, D_L01_00236B00.v[2][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540016, D_L01_00236B00.v[3][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54001A, D_L01_00236B00.v[4][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54001E, D_L01_00236B00.v[5][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540022, D_L01_00236B00.v[10][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540026, D_L01_00236B00.v[11][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54002A, D_L01_00236B00.v[8][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54002E, D_L01_00236B00.v[7][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540032, D_L01_00236B00.v[6][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540036, D_L01_00236B00.v[9][D_L01_002ED730[0]]);
}
/* localdecomp:end func_L01_004A0608 */

INCLUDE_ASM("asm/levels", func_L01_004A0788);

/* localdecomp:start func_L01_004A0A78 */
void func_L01_004A0A78(void) {

}
/* localdecomp:end func_L01_004A0A78 */

/* localdecomp:start func_L01_004A0A80 */
extern void func_L01_004A0AF8(s32);

void func_L01_004A0A80(void) {
    func_L01_004A0AF8(0);
    func_L01_004A0AF8(1);
    func_L01_004A0AF8(2);
    func_L01_004A0AF8(3);
    func_L01_004A0AF8(4);
    func_L01_004A0AF8(5);
    func_L01_004A0AF8(6);
    func_L01_004A0AF8(7);
    func_L01_004A0AF8(8);
    func_L01_004A0AF8(9);
    func_L01_004A0AF8(10);
    func_L01_004A0AF8(11);
}
/* localdecomp:end func_L01_004A0A80 */

INCLUDE_ASM("asm/levels", func_L01_004A0AF8);

INCLUDE_ASM("asm/levels", func_L01_004A0F28);

INCLUDE_ASM("asm/levels", func_L01_004A1050);

LINKER_REMNANT("asm/levels", func_L01_004A1120);

/* localdecomp:start func_L01_004A1128 */
extern s32 func_L01_004A1128(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0CF8;
extern s32 D_L01_001E0CE0[2];
extern void func_L01_004A1180();
extern void func_L01_004A15B0();
extern void func_L01_004A1520();
extern void func_L01_004A15F0_004A1128(void);
extern void func_L01_004A1610_004A1128();
s32 func_L01_004A1128(void) {
    if (D_L01_001E0CF8 == 0) {
        func_003E6FA0(D_L01_001E0CE0, (s32)func_L01_004A1180, (s32)func_L01_004A15B0, (s32)func_L01_004A1520, (s32)func_L01_004A15F0_004A1128, (s32)func_L01_004A1610_004A1128);
        D_L01_001E0CF8 = 1;
    }
    return (s32)D_L01_001E0CE0;
}
/* localdecomp:end func_L01_004A1128 */

INCLUDE_ASM("asm/levels", func_L01_004A1180);

INCLUDE_ASM("asm/levels", func_L01_004A1520);

/* localdecomp:start func_L01_004A15B0 */
extern void func_L01_00517918(s32);
extern void func_L01_004A1D00(void);
extern void func_003A2750(s32);

void func_L01_004A15B0(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_004A1D00();
    func_003A2750(1);
}
/* localdecomp:end func_L01_004A15B0 */

/* localdecomp:start func_L01_004A15F0 */
extern void func_L01_0047E4B8_004A15F0();

void func_L01_004A15F0(void) {
    func_L01_0047E4B8_004A15F0();
}
/* localdecomp:end func_L01_004A15F0 */

/* localdecomp:start func_L01_004A1610 */
extern void func_L01_0047E520_004A1610();

void func_L01_004A1610(void) {
    func_L01_0047E520_004A1610();
}
/* localdecomp:end func_L01_004A1610 */
