#include "common.h"

/* localdecomp:start func_L39_00588CE0 */
typedef struct { u8 pad[4]; s16 h4; } S0_00588CE0;
typedef struct { u8 pad[0x450]; s32 f450; u8 pad2[0xC]; } S1_00588CE0;
extern S0_00588CE0 *D_L39_0024C920;
__asm__(".extern D_L39_0024C920, 16");
extern s32 D_L39_0024B9C4;
__asm__(".extern D_L39_0024B9C4, 16");
extern s32 D_L39_0024BB58;
__asm__(".extern D_L39_0024BB58, 16");
extern s32 D_L39_00245BB0;
__asm__(".extern D_L39_00245BB0, 16");
extern s32 D_L39_00245BB4;
__asm__(".extern D_L39_00245BB4, 16");
extern s32 D_L39_0024BA10;
__asm__(".extern D_L39_0024BA10, 16");
extern s32 D_L39_0024BA14;
__asm__(".extern D_L39_0024BA14, 16");
extern u8 D_L39_00242520;
__asm__(".extern D_L39_00242520, 4");
extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern s32 D_L39_0024BA08;
__asm__(".extern D_L39_0024BA08, 16");
extern s32 D_L39_0024BA0C;
__asm__(".extern D_L39_0024BA0C, 16");
extern s32 D_L39_0024BA38;
__asm__(".extern D_L39_0024BA38, 16");
extern s32 D_L39_00245BCC;
__asm__(".extern D_L39_00245BCC, 16");
extern s32 D_L39_00245BD0;
__asm__(".extern D_L39_00245BD0, 16");
typedef struct { void *f0; void *f4; void *f8; u8 padC[0xC]; s32 f18; } S2_00588CE0;
extern S2_00588CE0 D_L39_0024BD00 __attribute__((section(".sdata")));
extern s32 D_L39_00241118;
__asm__(".extern D_L39_00241118, 16");
extern S1_00588CE0 D_L39_0024DE80[];
extern u8 D_L39_00244EC0;
__asm__(".extern D_L39_00244EC0, 16");
extern u8 D_L39_00244EC1;
__asm__(".extern D_L39_00244EC1, 16");
extern u8 D_L39_00244EC2;
__asm__(".extern D_L39_00244EC2, 16");
extern u8 D_L39_00244EC3;
__asm__(".extern D_L39_00244EC3, 16");
extern f32 D_L39_0024B9D0;
__asm__(".extern D_L39_0024B9D0, 16");
extern f32 D_L39_0024B9D8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B9D8, 16");
extern s32 D_L39_00242914;
__asm__(".extern D_L39_00242914, 4");
extern u8 D_L39_002424A4;
__asm__(".extern D_L39_002424A4, 4");
extern s32 D_L39_00242508;
__asm__(".extern D_L39_00242508, 4");
extern u8 D_00100AE0[];
extern s32 D_001A5810[];
extern f32 D_L39_0024BB4C;
__asm__(".extern D_L39_0024BB4C, 16");
extern int D_L39_002BA040[];
extern char D_L39_002B85A0[];
extern u64 D_L39_0025D860[];
extern u64 D_L39_0049A860[];
extern s32 D_L39_0024BB90;
__asm__(".extern D_L39_0024BB90, 16");

extern void func_00392350(s32);
extern void func_003861F0(void);
extern void func_003C2DC0(void);
extern void func_00387218(void);
extern void func_L39_00587E80(void);
extern void func_L39_0058CE50(void);
extern void func_L39_005F4690(void);
extern void func_003A9C70(s32);
extern void func_L39_005F61A0(void);
extern void func_L01_004C5E28(void);
extern void func_L39_00589538(s32);
extern void func_L01_00404920(void);
extern void func_00389370(void);
extern void func_L01_004C5DC8(void);
extern void func_L39_005EDE28(void);
extern void func_L39_0058B0D8(u8 *);
extern void func_L01_00404998(void);
extern void func_L39_005885C8(void);
extern void func_003C3860(void);
extern void func_L01_00404858(void);
extern void func_003A9440(s32, unsigned long);
extern void func_00385020(void);
extern void func_0038A058(void);
extern void func_001264E0(s32);
extern void func_003CD3D8(void);
extern void func_L01_00404A60(void);
extern void func_003D85C0(s32);
extern void func_003D8640(void);
extern void func_003D9260(s32);
extern void func_00389FE0(void);
extern void func_L39_0057C4D8(s32);
extern void func_L01_00415728(void);
extern s32 func_003A0EA8(s32);
extern void func_L39_0058ACE0(void);
extern void func_L01_00430110(s32);
extern void func_L39_005A9068(void);
extern void func_00396838(void);
extern void func_L39_0061D0B8(void);
extern void func_L01_00478AA0(void);
extern void func_003B3158(s32);
extern void func_L01_00478AD8(void);
extern void func_L39_0059B428(void);
extern void func_L39_0058A8B0(void);
extern void func_L39_0058B1B8(s32, s32, s32, s32);
extern void func_0038ABC0(void);
extern void func_003A8F90(void *);
extern void func_003A92F0(s32);
extern void func_003D0180(void *);
extern void func_003CF050(void);
extern void func_003DD768(void);
extern void func_003D9C30(void);
extern void func_003E0B10(void *);
extern void func_003DEE20(void);
extern void func_003C31B0(void);
extern void func_003864C0(s32);

/* true when bit 0 of a flags byte is clear */
static __inline__ s32 flagOff_00588CE0(u8 flags) { return !(flags & 1); }
void func_L39_00588CE0(s32 a0) {
    s32 t;
    f32 d;

    if (D_L39_0024C920 == 0 || D_L39_0024C920->h4 != 0 || flagOff_00588CE0(D_L39_0024B9C4)) {
        func_00392350(0);
    }
    func_003861F0();
    func_003C2DC0();
    func_00387218();
    func_L39_00587E80();
    D_L39_0024BB58 = -1;
    D_L39_00245BB0 = 0;
    D_L39_00245BB4 = 0;
    if (D_L39_0024C920 != 0 && (D_L39_0024B9C4 & 1)) {
        func_L39_0058CE50();
    }
    if ((D_L39_0024B9C4 & 2)) {
        func_L39_005F4690();
    }
    func_003A9C70(0x2010000);
    if ((D_L39_0024B9C4 & 4)) {
        func_L39_005F61A0();
    }
    func_003A9C70(0x2020000);
    if ((D_L39_0024B9C4 & 0x20) && D_L39_0024BA10) {
        func_L01_004C5E28();
        func_L39_00589538(1);
        func_L01_00404920();
        func_00389370();
        func_L01_004C5DC8();
    }
    if ((D_L39_0024B9C4 & 8)) {
        func_L39_005EDE28();
    }
    func_003A9C70(0x2040000);
    if (D_L39_00242520) {
        func_L39_0058B0D8(&D_L39_00242520);
    }
    if ((D_L39_0024B9C4 & 0x20) && D_L39_0024BA14) {
        func_L01_004C5E28();
        func_L39_00589538(1);
        func_L01_00404998();
        func_00389370();
        func_L01_004C5DC8();
    }
    if ((D_L39_0024B9C4 & 0x10)) {
        if (D_L39_00241128 == 2) {
            func_L39_005885C8();
        } else {
            func_003C3860();
        }
    }
    func_003A9C70(0x2080000);
    func_L39_00589538(0);
    if ((D_L39_0024B9C4 & 0x20)) {
        func_L01_004C5E28();
        if (D_L39_0024BA08) {
            func_L01_00404858();
        }
        func_003A9440(0x42, 0x8000000048UL);
        func_00385020();
        func_L01_004C5E28();
        func_0038A058();
        func_003A9440(8, 5);
        func_L01_004C5E28();
        func_003A9440(0x47, 0x53001);
        func_001264E0(0);
        func_003CD3D8();
        D_L39_0024BB58 = 9;
        func_003A9440(0x47, 0x5360B);
        if (D_L39_0024BA0C) {
            func_L01_004C5E28();
            func_L01_00404A60();
        }
        func_00389370();
        if (D_L39_00245BB0) {
            func_003D85C0(0);
            if (D_L39_00245BB0) {
                func_003D8640();
            }
        }
        if (D_L39_00245BCC) {
            func_003D9260(0);
        }
        D_L39_00245BD0 = D_L39_00245BCC;
        D_L39_00245BCC = 0;
        func_L39_00589538(0);
        if (D_L39_0024BA38) {
            func_L01_004C5E28();
            func_00389FE0();
        }
        func_003A9440(0x42, 0x8000000044UL);
        func_L39_0057C4D8(a0);
        func_00389370();
    }
    func_L01_00415728();
    func_L39_00589538(0);
    func_L01_004C5E28();
    if ((D_L39_0024B9C4 & 0x180) && func_003A0EA8(3) == 0) {
        func_003A9440(0x47, 0x33001);
        func_L39_0058ACE0();
        if ((D_L39_0024B9C4 & 0x80)) {
            func_L01_00430110(0);
            func_L39_005A9068();
            t = D_L39_0024BD00.f18;
            func_00396838();
            D_L39_0024BD00.f18 = t;
            func_L39_0061D0B8();
            func_L01_00478AA0();
            func_003B3158(D_L39_00241118);
            func_L01_00478AD8();
            func_L39_0059B428();
        }
    }
    if (D_L39_00241128 == 2) {
        func_L39_0058A8B0();
    }
    func_00389370();
    if ((D_L39_0024B9C4 & 0x40)) {
        func_003A9440(0x42, 0x8000000044UL);
        if ((D_L39_0024DE80 + a0)->f450) {
            func_L39_0058B1B8(D_L39_00244EC0, D_L39_00244EC1, D_L39_00244EC2, D_L39_00244EC3);
        }
        if (D_L39_0024B9D0 > 0.0f && D_L39_00242914 == 0) {
            if (D_L39_0024B9D0 > 1.0f) {
                D_L39_0024B9D0 = 1.0f;
            }
            func_L39_0058B1B8(0, 0, 0, D_L39_0024B9D0 * 128.0f);
        }
        if (D_L39_0024B9D8[0] > 0.0f && D_L39_00242914 == 0) {
            if (D_L39_0024B9D8[0] > 1.0f) {
                D_L39_0024B9D8[0] = 1.0f;
            }
            func_L39_0058B1B8(0xFF, 0xFF, 0xFF, D_L39_0024B9D8[a0] * 128.0f);
        }
        if (D_L39_002424A4 && D_L39_00242508) {
            func_0038ABC0();
        }
    }
    func_003A8F90(D_00100AE0);
    func_001264E0(0);
    d = (f32)*(volatile u32 *)0x10000800;
    D_L39_0024BB4C = d / (D_001A5810[0] ? 11520.0f : 9600.0f);
    func_003A92F0(2);
    if ((D_L39_0024B9C4 & 2)) {
        func_003D0180(D_L39_002BA040);
        func_003CF050();
    }
    func_003A92F0(4);
    if ((D_L39_0024B9C4 & 4)) {
        D_L39_0049A860[0] = D_L39_0025D860[0];
        D_L39_0049A860[1] = D_L39_0025D860[-1];
        D_L39_0049A860[2] = D_L39_0025D860[2];
        func_003DD768();
        func_003D9C30();
    }
    func_003A92F0(8);
    if ((D_L39_0024B9C4 & 8)) {
        func_003E0B10(D_L39_002B85A0);
        func_003DEE20();
    }
    func_003A92F0(0x10);
    if ((D_L39_0024B9C4 & 0x10)) {
        func_003C31B0();
    }
    func_003864C0(a0);
    D_L39_0024BB90 = 0;
}
/* localdecomp:end func_L39_00588CE0 */
