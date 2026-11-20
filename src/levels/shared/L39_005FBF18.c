#include "common.h"

/* localdecomp:start func_L39_005FBF18 */
#include "vu0.h"
typedef struct {
    u8 pad0[4];
    void *p4;
    u8 pad8[0x1A4 - 8];
    s16 h1A4;
} S2558_005FBF18;
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[0x168 - 0xC];
    u8 b168;
    u8 pad169[0x170 - 0x169];
    s32 w170;
    u8 pad174[0x2DC - 0x174];
    s32 w2DC;
    s32 w2E0;
} G_005FBF18;
extern s32 D_L39_00241128;
extern s32 *D_L39_00241120;
extern u32 D_L39_002403FC;
extern u8 D_L39_002429AD;
extern s32 D_L39_0024BB44;
extern s32 D_L39_0024BC28;
extern s32 D_L39_00242A04;
extern s32 D_L39_00242914;
extern s32 D_L39_00242A00;
extern void *D_L39_00241640;
extern s32 D_L39_00241644;
extern vu0_q D_L39_002434B0 __attribute__((section(".sdata")));
extern u8 D_L39_002357A0[];
extern u8 D_L39_002359E0[];
extern G_005FBF18 D_001A5CD0;
extern u8 D_001A5815[];
extern s32 func_L39_005BF798(s32, s32, s32, s32, s32);
extern u8 func_L01_00422440(void);
extern s32 func_L01_00432F68(void);
extern s32 func_L02_004E49E8_005FBF18(void);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_00677190(s32);
extern s32 func_L01_0040E020(void *);
extern void func_L39_005E45D8(s32);
extern void func_L39_005BD300(void);
extern s32 func_L01_003257E8(void);
extern void func_L01_0045A570(s32);
extern void func_L39_005FBDD8(void);
extern void func_0038CC88(void *, void *, s32);
extern s32 func_001959F8(void);
extern void func_00197528(s32);
extern void func_00196038(void);
extern void func_00197538(void);
extern void func_L01_0047EDB8_005FBF18(void);
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
extern void func_L39_0059C5F0(s32);
extern void func_L39_005A8ED8(void);
extern void func_L01_00478898(void);
extern void func_003B3088(s32);
extern void func_L39_0059AC60(void);
extern void func_L39_005FBE08(void);

void func_L39_005FBF18(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    if (D_L39_00241128 == 0 && D_L39_002429AD == 0 && (D_L39_002403FC & 1)) {
        func_L39_005BF798(4, 1, 1, 0, 0);
        return;
    }
    if (func_L01_00422440() != 0 && D_L39_00241128 == 0 && (D_L39_002403FC & 0x600)) {
        if (func_L39_005BF798(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_L01_00432F68() != 0 && D_L39_00241128 == 0 && func_L01_00422440() != 0) {
        if (func_L39_005BF798(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_L02_004E49E8_005FBF18() != 0) {
        return;
    }
    for (i = 0; i < *D_L39_00241120; i++) {
        u8 *o = func_L39_0061BF38(i);
        if (D_L39_0024BB44 >= 8 && (*(s32 *)(*(u8 **)(o + 0x2534) + 0x1A4) & 0x800) && D_L39_00241128 == 0) {
            func_L39_0061C0E0(i, 1);
            o[0x2519] = 15;
        }
        func_L39_00677190(i);
        if (o[0x2518] != 0 && func_L01_0040E020(o + 0x2519) == 2) {
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
    if ((f32)D_001A5CD0.w2E0 > 1250.0f && D_001A5CD0.w170 == 0) {
        switch (D_001A5CD0.w2DC) {
        case 0:
            break;
        case 2:
        case 5:
        default:
            D_L39_00242A04 = 1;
            D_001A5815[0] = 0;
            for (j = 0; j < *D_L39_00241120; j++) {
                u8 *o = func_L39_0061BF38(j);
                S2558_005FBF18 *p;
                if (o != 0 && (p = *(S2558_005FBF18 **)(o + 0x2558)) != 0 && p->p4 != 0) {
                    func_0038CC88(D_L39_002357A0 + j * 0x90, p->p4, 0x90);
                }
            }
            func_0038CC88(D_L39_002359E0, D_L39_00241640, 0x1A4);
            D_L39_00241640 = D_L39_002359E0;
            func_00197528(D_001A5CD0.w8);
            func_00196038();
            func_00197538();
            D_001A5CD0.w170 = 1;
            D_001A5CD0.b168 = 1;
            for (k = 0; k < *D_L39_00241120; k++) {
                u8 *o = func_L39_0061BF38(k);
                S2558_005FBF18 *p;
                if (o != 0 && (p = *(S2558_005FBF18 **)(o + 0x2558)) != 0) {
                    p->p4 = D_L39_002357A0 + k * 0x90;
                    (*(S2558_005FBF18 **)(o + 0x2558))->h1A4 = 0;
                    D_L39_00241644--;
                }
            }
            break;
        }
    }
    func_L01_0047EDB8_005FBF18();
    func_L01_00438EA0();
    func_003CD058();
    func_L39_005F3828();
    func_L01_00487E70();
    func_003CD350();
    qzero(&D_L39_002434B0);
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
        for (m = 0; m < *D_L39_00241120; m++) {
            func_003B3088(m);
        }
        if (*D_L39_00241120 >= 2) {
            func_003B3088(4);
        }
    }
    func_L39_0059AC60();
    func_L39_005FBE08();
}
/* localdecomp:end func_L39_005FBF18 */
