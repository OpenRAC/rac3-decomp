#include "common.h"

/* localdecomp:start func_L39_005FB708 */
typedef struct { s32 sector; s32 size; } TocFile_005FB708;
typedef struct {
    s32 header;
    s32 base;
    TocFile_005FB708 files[1];
} Toc_005FB708;
extern Toc_005FB708 D_001F0A00;
extern u32 D_001A4B50[];
extern u8 D_001A58C7[];
extern s32 D_L39_0025F500[];
extern s32 D_L39_0024CAB4;
extern s32 func_003A8770(s32);
extern void func_L39_0059A400(void *);
extern void func_L39_005FB7D0(s32, s32, s32, s32, s32);

/* from rac2-decomp's func_002F5D40 */
void func_L39_005FB708(s32 n)
{
    s32 index;
    s32 flag;
    s32 i2;
    u8 v;
    s32 a0;

    if (n < 0) {
        D_L39_0024CAB4 = 0;
        return;
    }
    index = func_003A8770(n);
    D_001A4B50[(u32)n >> 2] |= 1 << (n & 0x1F);
    func_L39_0059A400(D_L39_0025F500);
    flag = index == 0x1F;
    a0 = D_001F0A00.files[index * 2 + 1].sector + D_001F0A00.base;
    v = D_001A58C7[0];
    if (D_L39_0025F500[0] != 0) {
        v = 0;
    }
    i2 = index * 2;
    func_L39_005FB7D0(a0, D_001F0A00.files[i2 + 1].size, (s32)&D_001F0A00.files[i2], v, flag);
}
/* localdecomp:end func_L39_005FB708 */

/* localdecomp:start func_L39_005FB7D0 */
extern s32  D_L39_0024CAB0;
extern s32  D_L39_0024CAC4;
extern s32  D_L39_0024CAB4;
extern s32  D_L39_0024CAB8;
extern s32  D_L39_0024CABC;
extern s32 D_L39_0024CAC0 __attribute__((section(".sdata")));
extern u8 D_001FE020[];
extern s16 D_002256A8[];
extern void func_001264E0(s32 a);
extern void func_00194BC8(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_L39_0058A5D0(s32 a);
extern void func_L01_0041A6E0(void);
extern void func_L39_005C1E10(void);
extern void func_L39_005F3948(void);

/* from rac2-decomp's func_002F5E20 */
void func_L39_005FB7D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *p;
    p = D_001FE020;
    p[0x43] = p[0x43] | 8;
    func_00194BC8(2, 0, 0, 0, 0);
    func_001264E0(0);
    func_L39_005F3948();
    func_L39_005C1E10();
    D_L39_0024CAB0 = arg0;
    D_L39_0024CAC4 = (s32) D_002256A8[0];
    D_L39_0024CAB4 = arg1;
    D_L39_0024CAB8 = arg2;
    D_L39_0024CABC = arg3;
    D_L39_0024CAC0 = arg4;
    func_L39_0058A5D0(4);
    func_L01_0041A6E0();
}
/* localdecomp:end func_L39_005FB7D0 */

/* localdecomp:start func_L39_005FB8A8 */
extern s32 D_L39_00240468;
extern s32 D_L39_0024CAC4;
extern s32 D_L39_0025F560[];
extern s32 D_L39_00242910;
extern s32 D_L39_002429A8;
extern void (*D_L39_002429A4)(s32);
extern s32 D_001D7298_sda;
extern u8 D_1FE020[];
extern void func_L39_0058A5D0(s32 a0);
extern void func_L39_005C1AC0(s32 a0, s32 a1, s32 a2);
extern void func_003A1D00(void);
extern void func_003A9108(void);

void func_L39_005FB8A8(void) {
    u8 *p;

    if (D_L39_00240468 == 0) {
        D_L39_00240468 = 1;
    }
    func_L39_0058A5D0(4);
    func_L39_005C1AC0(D_L39_0024CAC4, 1, 0x400);
    func_003A1D00();
    p = D_1FE020;
    p[0x43] |= 0x10;
    func_003A9108();
    if (D_L39_002429A4 != 0) {
        if (D_L39_0025F560[0] == 0) {
            if (D_L39_00242910 == 2)
                goto done;
            if (D_L39_00242910 == 1)
                goto done;
            D_L39_002429A4(D_001D7298_sda);
            D_L39_002429A4 = 0;
            D_L39_002429A8 = 0;
        }
    }
done:
    ;
}
/* localdecomp:end func_L39_005FB8A8 */

/* localdecomp:start func_L39_005FB960 */
typedef struct S_005FB960_Slot {
    u8 pad00[0x34];
    s32 w34;
    u8 pad38[0x14];
    s32 w4C;
} S_005FB960_Slot;

typedef struct S_005FB960_Sav {
    u8 pad00[0x15C];
    s32 a15C;
    u8 pad160[4];
    s32 a164;
} S_005FB960_Sav;

extern u8 D_001A5810[];
extern s32 D_L39_0025F500[];
extern s32 D_L39_0025F680[];
extern s32 D_L39_002402F4;
extern s32 D_001D4BE0_sda;
__asm__(".extern D_001D4BE0_sda, 4");
extern S_005FB960_Sav D_001A43E0;
extern S_005FB960_Slot D_L39_0025CEC0;
extern s32 D_L39_0024CAD8;
extern u8 D_L39_002410E4;
extern s32 D_L39_00240468;
extern long D_L39_0025DDC0[];
extern u8 D_00194E50[];

extern void func_00392C48(u8 *);
extern void func_003A92F0(s32);
extern void func_L01_0047C4F8_005FB960(void);
extern void func_L39_005FCDF8(void);
extern void func_001264E0(s32);
extern void func_L39_005F3948(void);
extern void func_L39_005C1E10(void);
extern s32 func_00194A38(s32);
extern void func_L39_005A61D8(void);
extern s32 func_00194970(s32, s32, s32, u8 *);
extern void func_003A87D8(s32, s32, s32, s32);
extern s32 func_003A8830(s32, s32);
extern s32 func_003AF890(s32, s32, s32 (*)(s32, s32), s32, s32);
extern s32 func_003A8770(s32);
extern void func_00392A80(u8 *, s32 *, s32 *);
extern void func_0013A9D8(u8 *);
extern void func_001331A0(s32, s32);
extern void func_L39_005F64F8(void);
extern void func_003A9108(void);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_005BF840(s32, s32);

void func_L39_005FB960(void) {
    u8 buf[16];
    s32 sp10;
    s32 sp14;
    s32 spA;
    s32 spB;
    s32 r;
    s32 done;
    s32 idx;
    s32 end;
    s32 *p;

    if (D_L39_0024CAB4 == 0) {
        func_00392C48((u8 *)D_L39_0025F500);
        func_L39_005BF840(0, 0);
        return;
    }
    spA = D_L39_0025F680[3];
    spB = D_L39_0025F680[5];
    end = spB + 0xF8000;
    func_003A92F0(1);
    D_001D4BE0_sda = D_L39_002402F4;
    func_L01_0047C4F8_005FB960();
    func_L39_005FCDF8();
    func_003A92F0(1);
    func_001264E0(0);
    func_L39_005F3948();
    func_L39_005C1E10();
    func_00194A38(0);
    while (D_001A43E0.a15C >= 3 || D_001A43E0.a164 >= 0) {
        func_L39_005A61D8();
    }
    sp14 = -1;
    done = sp10 = 0;
    do {
        if (D_L39_0024CAB8 != 0 && *(s32 *)D_L39_0024CAB8 != 0) {
            buf[0] = 100;
            buf[2] = 0;
            buf[1] = D_L39_002410E4;
            func_00194A38(0);
            func_00194970(*(s32 *)D_L39_0024CAB8 + D_001F0A00.base, 0x10, end, buf);
            func_00194A38(0);
            D_L39_0025CEC0.w4C = end;
        } else {
            D_L39_0025CEC0.w4C = 0;
        }
        D_L39_0025CEC0.w34 = 0;
        func_003A87D8(spA, D_L39_0024CAD8 << 1, spB, 0xF8000);
        r = func_003AF890(D_L39_0024CAB0, D_L39_0024CAB4, func_003A8830, D_L39_0024CABC, D_L39_0024CAC0);
        p = D_L39_0025F500;
        if ((r ^ 1) == 0) {
            ((u8 *)p)[0x64] = 1;
        }
        if (r != 0) {
            if (!(D_L39_00240468 & 0x40)) {
                ((u8 *)p)[0x64] = 1;
                func_00392C48((u8 *)p);
            }
        }
        if (D_L39_0025F500[0] != 0) {
            D_L39_0025F500[0] = D_L39_0025F500[0] + 1;
            if (D_L39_0025F500[0] + D_001A5810[0xAD] >= 4) {
                D_L39_0025F500[0] = 1;
            }
            if (D_L39_0025F500[0] == 2) {
                D_L39_00240468 = 0;
                if (D_001A5810[0xAD] != 0) {
                    D_L39_0024CAC0 = 0;
                    idx = func_003A8770(0x1D);
                } else {
                    D_L39_0024CAC0 = 1;
                    idx = func_003A8770(0x1F);
                }
            } else if (D_L39_0025F500[0] == 3) {
                D_L39_0024CAC0 = 1;
                D_L39_00240468 = 0;
                idx = func_003A8770(0x1E);
            } else {
                D_L39_0024CAC0 = 0;
                D_L39_00240468 = 1;
                idx = func_003A8770(0);
            }
            D_L39_0024CAB8 = (s32)&D_001F0A00.files[idx * 2];
            D_L39_0024CAB0 = D_001F0A00.files[idx * 2 + 1].sector + D_001F0A00.base;
            D_L39_0024CAB4 = D_001F0A00.files[idx * 2 + 1].size;
        } else if (D_L39_0025F500[0x18] == 0) {
            done = 1;
        } else {
            func_00392A80((u8 *)D_L39_0025F500, &sp10, &sp14);
            if (sp14 == 0) {
                D_L39_0024CAC0 = sp10 == 0x1F;
                idx = func_003A8770(sp10);
                D_L39_0024CAB8 = (s32)&D_001F0A00.files[idx * 2];
                D_L39_0024CAB0 = D_001F0A00.files[idx * 2 + 1].sector + D_001F0A00.base;
                D_L39_0024CAB4 = D_001F0A00.files[idx * 2 + 1].size;
            } else if (sp14 == 1) {
                done = 1;
            }
        }
    } while (!done);
    func_00194A38(0);
    func_0013A9D8(D_00194E50);
    func_001331A0(0, 0);
    func_L39_005F64F8();
    D_L39_0025DDC0[4] = 0;
    func_003A9108();
    if (r == 0 && sp14 == 1) {
        func_L39_005BF798(2, 2, sp10, 0, 0);
    } else {
        func_L39_005BF840(0, 0);
    }
}
/* localdecomp:end func_L39_005FB960 */

/* localdecomp:start func_L39_005FBDA0 */
void func_L39_0059A578(s32, s32);
extern s32 D_001A455C[];
extern s16 D_001FC368[];
extern s32 D_001D4D58_sda;

/* from rac4-decomp's func_004E5550 */
void func_L39_005FBDA0(void) {
    D_001FC368[0] = (D_001A455C[0] = 1);
    D_001D4D58_sda = 1;
    func_L39_0059A578(1, 1);
}
/* localdecomp:end func_L39_005FBDA0 */

/* localdecomp:start func_L39_005FBDD8 */
extern s32 D_L39_0024BA08;
extern s32 D_L39_0024BA10;
extern s32 D_L39_0024BA14;
extern s32 D_L39_0024BA0C;
extern s32 D_L39_0024BA38;
extern s32 D_L39_0024BA60;
void func_L39_005FBDD8(void) {
    D_L39_0024BA08 = 0;
    D_L39_0024BA10 = 0;
    D_L39_0024BA14 = 0;
    D_L39_0024BA0C = 0;
    D_L39_0024BA38 = 0;
    D_L39_0024BA60 = 0;
}
/* localdecomp:end func_L39_005FBDD8 */

/* localdecomp:start func_L39_005FBE08 */
typedef struct S_005FBE08 {
    u8 pad00[0x100];
    f32 f100;
    f32 f104;
    f32 f108;
    f32 f10C;
    u8 pad110[0x90];
    s32 i1A0;
} S_005FBE08;

extern S_005FBE08 *D_L39_00241164;
extern s32 D_001D9718_sda;
__asm__(".extern D_001D9718_sda, 4");
extern s32 D_L39_0024112C;
extern s32 D_L39_00240388;
extern s32 D_001D4C78_sda;
__asm__(".extern D_001D4C78_sda, 4");
extern s32 D_L39_00242994;
extern s32 D_001D5BCC_sda;
__asm__(".extern D_001D5BCC_sda, 4");
extern s32 D_00201878[];
extern s32 D_L39_0024C018;
extern s32 D_L39_00243260;

void func_L39_005FBE08(void) {
    S_005FBE08 *p = D_L39_00241164;

    if (p->i1A0 != 0 || p->f108 != 0.0f || p->f10C != 0.0f || p->f100 != 0.0f || p->f104 != 0.0f) {
        D_001D9718_sda = 0;
    } else {
        D_001D9718_sda = D_001D9718_sda + 1;
    }
    D_L39_0024112C = D_L39_0024112C + 1;
    D_001D4C78_sda = D_L39_00240388 + 1;
    if (D_L39_00242994 != 0 && D_001D9718_sda < 0x2EE) {
        D_00201878[D_001D5BCC_sda]++;
    }
    if (D_L39_0024C018 != D_L39_00240388 - 1) {
        D_L39_00243260 = -1;
    }
}
/* localdecomp:end func_L39_005FBE08 */
