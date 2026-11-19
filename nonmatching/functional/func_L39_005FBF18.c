/* functional: medium. Compiles; not byte-exact (extra callee-saved reg, gp-alias vs lui reads of D_L39_00241128/00241120/00241640 are plain names). Read block by block against the asm; coverage by reading only. */
/* localdecomp:start func_L39_005FBF18 */
#include "vu0.h"
typedef struct { u8 b[0x90]; } E_005FBF18;
extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern u8 D_L39_002429AD;
__asm__(".extern D_L39_002429AD, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern s32 D_L39_0024BB44;
__asm__(".extern D_L39_0024BB44, 16");
extern s32 D_L39_0024BC28;
__asm__(".extern D_L39_0024BC28, 16");
extern u8 D_L39_002434B0[];
extern s32 D_L39_00242A04;
extern s32 D_L39_00242914;
extern s32 D_L39_00242A00;
extern E_005FBF18 D_L39_002357A0[];
extern u8 D_L39_002359E0[];
extern u8 *D_L39_00241640;
extern s32 D_L39_00241644;
extern u8 D_001A5CD0[];
extern u8 D_001A5815;

extern u8 func_L01_00422440(void);
extern s32 func_L01_00432F68(void);
extern s32 func_L02_004E49E8(void);
extern s32 func_L39_005BF798(s32, s32, s32, s32, s32);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_00677190(s32);
extern s32 func_L01_0040E020(void *);
extern s32 func_L39_005E45D8(s32);
extern void func_L39_005BD300(void);
extern s32 func_L01_003257E8(void);
extern void func_L01_0045A570(s32);
extern void func_L39_005FBDD8(void);
extern s32 func_001959F8(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_00197528(s32);
extern void func_00196038(void);
extern void func_00197538(void);
extern void func_L01_0047EDB8(void);
extern void func_L01_00438EA0(void);
extern void func_003CD058(void);
extern void func_L39_005F3828(void);
extern void func_L01_00487E70(void);
extern void func_003CD350(void);
extern void func_L39_0057B1C0(void);
extern void func_L39_005F26E8(void);
extern void func_L39_005F1718(void);
extern void func_003D0B20(void);
extern void func_L39_005ABA28(void);
extern s32 func_L39_0059C5F0(s32);
extern void func_L39_005A8ED8(void);
extern void func_L01_00478898(void);
extern void func_003B3088(s32);
extern void func_L39_0059AC60(void);
extern void func_L39_005FBE08(void);

void func_L39_005FBF18(void) {
    s32 i;
    u8 *e;
    u8 *q;

    if (D_L39_00241128 == 0 && D_L39_002429AD == 0 && (D_L39_002403FC & 1) != 0) {
        func_L39_005BF798(4, 1, 1, 0, 0);
        return;
    }
    if (func_L01_00422440() != 0 && D_L39_00241128 == 0 && (D_L39_002403FC & 0x600) != 0) {
        if (func_L39_005BF798(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_L01_00432F68() != 0 && D_L39_00241128 == 0 && func_L01_00422440() != 0) {
        if (func_L39_005BF798(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_L02_004E49E8() != 0) {
        return;
    }
    for (i = 0; i < *D_L39_00241120; i++) {
        e = func_L39_0061BF38(i);
        if (D_L39_0024BB44 >= 8 && (*(s32 *)(*(u8 **)(e + 0x2534) + 0x1A4) & 0x800) != 0 && D_L39_00241128 == 0) {
            func_L39_0061C0E0(i, 1);
            e[0x2519] = 0xF;
        }
        func_L39_00677190(i);
        if (e[0x2518] != 0 && func_L01_0040E020(e + 0x2519) == 2) {
            func_L39_005E45D8(i);
        }
    }
    func_L39_005BD300();
    if (D_L39_0024BC28 != 0 && func_L39_005BF798(6, 1, 0, 0, 0) == 0) {
        func_L01_0045A570(func_L01_003257E8() != 0);
        D_L39_0024BC28 = 0;
        return;
    }
    func_L39_005FBDD8();
    func_001959F8();
    if ((f32)*(s32 *)(D_001A5CD0 + 0x2E0) > 1250.0f && *(s32 *)(D_001A5CD0 + 0x170) == 0 &&
        *(s32 *)(D_001A5CD0 + 0x2DC) != 0) {
        D_L39_00242A04 = 1;
        D_001A5815 = 0;
        for (i = 0; i < *D_L39_00241120; i++) {
            e = func_L39_0061BF38(i);
            if (e != 0) {
                q = *(u8 **)(e + 0x2558);
                if (q != 0 && *(s32 *)(q + 4) != 0) {
                    func_0038CC88(&D_L39_002357A0[i], *(void **)(q + 4), 0x90);
                }
            }
        }
        func_0038CC88(D_L39_002359E0, D_L39_00241640, 0x1A4);
        D_L39_00241640 = D_L39_002359E0;
        func_00197528(*(s32 *)(D_001A5CD0 + 8));
        func_00196038();
        func_00197538();
        D_001A5CD0[0x168] = 1;
        *(s32 *)(D_001A5CD0 + 0x170) = 1;
        for (i = 0; i < *D_L39_00241120; i++) {
            e = func_L39_0061BF38(i);
            if (e != 0) {
                q = *(u8 **)(e + 0x2558);
                if (q != 0) {
                    *(s32 *)(q + 4) = (s32)&D_L39_002357A0[i];
                    D_L39_00241644 = D_L39_00241644 - 1;
                    *(s16 *)(*(u8 **)(e + 0x2558) + 0x1A4) = 0;
                }
            }
        }
    }
    func_L01_0047EDB8();
    func_L01_00438EA0();
    func_003CD058();
    func_L39_005F3828();
    func_L01_00487E70();
    func_003CD350();
    qzero(D_L39_002434B0);
    if (*D_L39_00241120 == 1) {
        func_L39_0057B1C0();
    }
    if (D_L39_00242914 != 0) {
        if (D_L39_00242A00 != 0) {
            func_L39_005F26E8();
        }
    } else {
        func_L39_005F1718();
    }
    func_003D0B20();
    func_L39_005ABA28();
    if (D_L39_00242A00 != 0) {
        func_L39_0059C5F0(1);
        func_L39_005A8ED8();
        func_L01_00478898();
        for (i = 0; *D_L39_00241120 > 0 && i < *D_L39_00241120; ) {
            func_003B3088(i);
            i++;
        }
        if (*D_L39_00241120 >= 2) {
            func_003B3088(4);
        }
    }
    func_L39_0059AC60();
    func_L39_005FBE08();
}
/* localdecomp:end func_L39_005FBF18 */
