#include "common.h"

/* declared by functions of L39_0060B428.c, which this file was cut from */
extern void func_003861F0(void);
extern s32 D_L39_0024BB58;

/* localdecomp:start func_L39_0060B560 */
extern void func_L39_005872D8(void);
extern void func_003861F0(void);
extern void func_L39_0060B6F8(void);
extern void func_L39_00589538(s32);
extern void func_L01_00404858(void);
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32, unsigned long);
extern void func_001264E0(s32);
extern void func_003CD3D8(void);
extern void func_003A8F90(void *);
extern void func_00389370(void);
extern void func_L01_00404A60(void);
extern void func_003864C0(s32);
extern void func_003D85C0(s32);
extern void func_003D8640(void);
extern void func_003D9260(s32);
typedef struct { u8 p0[8]; s32 w8; } Cfg_0060B560;
extern Cfg_0060B560 D_001FC450;
extern u8 D_00100AE0[];
extern s32 D_001DA124_sda;
extern s32 D_001DA4BC_sda;
extern s32 D_L39_00245BB0;
extern s32 D_L39_00245BCC;
extern s32 D_L39_0024BA08;
extern s32 D_L39_0024BA0C;
extern s32 D_L39_0024BB58;
__asm__(".extern D_L39_00245BB0, 16");
__asm__(".extern D_L39_00245BCC, 16");
__asm__(".extern D_L39_0024BA08, 16");
__asm__(".extern D_L39_0024BA0C, 16");
__asm__(".extern D_L39_0024BB58, 16");

void func_L39_0060B560(void) {
    s32 v;
    D_L39_00245BB0 = 0;
    func_L39_005872D8();
    func_003861F0();
    if (D_001DA124_sda & 1) {
        func_L39_0060B6F8();
    }
    func_L39_00589538(1);
    if (D_L39_0024BA08 != 0) {
        func_L01_00404858();
    }
    func_L01_004C5E28();
    func_003A9440(8, 5);
    func_003A9440(0x47, 0x53001);
    func_001264E0(0);
    func_003CD3D8();
    D_L39_0024BB58 = 9;
    func_003A9440(0x47, 0x5360B);
    func_003A8F90(D_00100AE0);
    func_001264E0(0);
    func_00389370();
    if (D_L39_0024BA0C != 0) {
        func_L39_00589538(1);
        func_003A9440(0x4E, ((long)(D_001FC450.w8 >> 13) | 0x31000000) | (1L << 32));
        func_L01_004C5E28();
        func_L01_00404A60();
        func_003A9440(0x4E, 0x31000000 | (D_001FC450.w8 >> 13));
        func_00389370();
    }
    func_003864C0(0);
    if (D_L39_00245BB0 != 0) {
        func_003D85C0(0);
        func_003D8640();
        v = D_L39_00245BCC;
    } else {
        v = D_001DA4BC_sda;
    }
    if (v != 0) {
        func_003D9260(0);
        D_L39_00245BCC = 0;
    }
}
/* localdecomp:end func_L39_0060B560 */

/* localdecomp:start func_L39_0060B6F8 */
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);
extern s32 D_001FC458[];

void func_L39_0060B6F8(void)
{
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, 0x1000000 | (D_001FC458[0] >> 13));
}
/* localdecomp:end func_L39_0060B6F8 */

/* localdecomp:start func_L39_0060B750 */
typedef struct S_0060B750 {
    u8 pad0[0x18];
    s16 h18;
    u8 pad1A[0x15C - 0x1A];
    s32 f15C;
    u8 pad160[0x164 - 0x160];
    s32 f164;
    u8 pad168[0x17C - 0x168];
    s32 f17C;
} S_0060B750;

typedef struct T_0060B750 {
    u8 pad0[7];
    u8 b7;
} T_0060B750;

extern void func_0038CB78(void *, s32, s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_005BF490(void);
extern void func_001264E0(s32);
extern void func_00194BC8(s32, s32, s32, s32, s32);
extern void func_00194670(void);
extern s32 func_00193590(void);
extern void func_L39_005F3948(void);
extern void func_L39_005C1E10(void);
extern void func_00193B80(s32);
extern void func_00193B50(void);
extern void func_L39_005A61D8(void);
extern void func_L39_005A5010(void);
extern s32 func_00194B88(s32);
extern void func_L39_005C2B10(s32);
extern void func_001959F8(void);
extern void func_L39_0058A5D0(s32);
extern void func_L39_005A3D98(void);
extern void func_00194A38(s32);
extern void func_L39_005FD6F8(void);

extern u8 D_L39_0025F580[];
extern s32 D_L39_0025F740[];
extern u8 D_00225660[];
extern s32 D_001FE020[];
extern S_0060B750 D_001A43E0;
extern s32 D_L39_0024BB6C;
__asm__(".extern D_L39_0024BB6C, 16");
extern s32 D_L39_0024BB40;
__asm__(".extern D_L39_0024BB40, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern s32 D_001D4CEC_sda;
extern s32 D_001D5BCC_sda;

void func_L39_0060B750(void) {
    s32 i;
    s32 *p;

    func_0038CB78(D_L39_0025F580, -1, 0x80);
    func_L39_005BF798(6, 2, 0, 0, 0);
    func_L39_005BF490();
    D_L39_0025F740[4] |= 0x80000000;
    func_001264E0(0);
    func_00194BC8(2, 0, 0, 0, 0);
    func_00194670();
    func_00193590();
    func_L39_005F3948();
    func_L39_005C1E10();
    D_00225660[7] = 1;
    for (i = 0; i < 6; i++) {
        if (D_001FE020[36 + i] != 0) {
            func_00193B80(D_001FE020[36 + i]);
            func_00193B50();
            D_L39_0024BB6C = 0;
            D_001FE020[36 + i] = 0;
        }
    }
    while (D_001A43E0.f15C >= 3 || D_001A43E0.f164 >= 0) {
        func_L39_005A61D8();
        func_L39_005A5010();
    }
    if (D_001A43E0.f17C != 0) {
        D_001A43E0.f17C = 0;
    }
    if (D_001A43E0.h18 >= 0) {
        D_001A43E0.h18 = -1;
    }
    D_001D4CEC_sda = D_L39_002403FC & ~0x200;
    func_00194B88(0);
    D_00225660[7] = 0;
    func_L39_005C2B10(1);
    while (func_00193590() != 0) {
        func_001959F8();
    }
    D_00225660[7] = 1;
    func_L39_0058A5D0(5);
    D_001D5BCC_sda = D_L39_0024BB40;
    func_L39_005A3D98();
    func_00194A38(0);
    D_00225660[7] = 0;
    func_L39_005FD6F8();
}
/* localdecomp:end func_L39_0060B750 */
