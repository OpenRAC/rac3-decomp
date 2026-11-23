#include "common.h"

/* NTSC-U counterpart of func_L39_005FB960 (src/levels/shared/L39_005FB708.c) */
typedef struct { s32 sector; s32 size; } TocFile_005FB708;
typedef struct {
    s32 header;
    s32 base;
    TocFile_005FB708 files[1];
} Toc_005FB708;
extern Toc_005FB708 D_L39_001F0B80;
extern s32 D_L39_0025F600[];
extern s32 D_L39_0024CBB4;
extern s32 func_003A3220(s32);
extern s32  D_L39_0024CBB0;
extern s32  D_L39_0024CBB4;
extern s32  D_L39_0024CBB8;
extern s32  D_L39_0024CBBC;
extern s32 D_L39_0024CBC0 __attribute__((section(".sdata")));
extern void func_001264E0(s32 a);
extern void func_L39_005BFDC8(void);
extern void func_L39_005F1248(void);
extern s32 D_L39_002405E8_005F91C8;
extern u8 D_1FE020[];
extern void func_003A3BB8(void);

/* localdecomp:start func_L39_005F91C8 */
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

extern u8 D_001A5990[];
extern s32 D_L39_0025F600[];
extern s32 D_L39_0025F780_005F91C8[];
extern s32 D_L39_00240474;
extern s32 D_001D4BE0_sda_005F91C8;
__asm__(".extern D_001D4BE0_sda_005F91C8, 4");
extern S_005FB960_Sav D_001A4560;
extern S_005FB960_Slot D_L39_0025CFC0;
extern s32 D_L39_0024CBD8_005F91C8;
extern u8 D_L39_00241264;
extern s32 D_L39_002405E8_005F91C8;
extern long D_L39_0025DEC0[];
extern u8 D_00194F40[];

extern void func_0038E410(u8 *);
extern void func_003A3DA0(s32);
extern void func_L01_00478CA8_005F91C8(void);
extern void func_L39_005FA660(void);
extern void func_001264E0(s32);
extern void func_L39_005F1248(void);
extern void func_L39_005BFDC8(void);
extern s32 func_00194B28(s32);
extern void func_L39_005A43D8(void);
extern s32 func_00194A60(s32, s32, s32, u8 *);
extern void func_003A3288(s32, s32, s32, s32);
extern s32 func_003A32E0(s32, s32);
extern s32 func_003AA2E8(s32, s32, s32 (*)(s32, s32), s32, s32);
extern s32 func_003A3220(s32);
extern void func_0038E248(u8 *, s32 *, s32 *);
extern void func_0013A9D8(u8 *);
extern void func_001331A0(s32, s32);
extern void func_L39_005F3D60(void);
extern void func_003A3BB8(void);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_005BD880(s32, s32);

void func_L39_005F91C8(void) {
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

    if (D_L39_0024CBB4 == 0) {
        func_0038E410((u8 *)D_L39_0025F600);
        func_L39_005BD880(0, 0);
        return;
    }
    spA = D_L39_0025F780_005F91C8[3];
    spB = D_L39_0025F780_005F91C8[5];
    end = spB + 0xF8000;
    func_003A3DA0(1);
    D_001D4BE0_sda_005F91C8 = D_L39_00240474;
    func_L01_00478CA8_005F91C8();
    func_L39_005FA660();
    func_003A3DA0(1);
    func_001264E0(0);
    func_L39_005F1248();
    func_L39_005BFDC8();
    func_00194B28(0);
    while (D_001A4560.a15C >= 3 || D_001A4560.a164 >= 0) {
        func_L39_005A43D8();
    }
    sp14 = -1;
    done = sp10 = 0;
    do {
        if (D_L39_0024CBB8 != 0 && *(s32 *)D_L39_0024CBB8 != 0) {
            buf[0] = 100;
            buf[2] = 0;
            buf[1] = D_L39_00241264;
            func_00194B28(0);
            func_00194A60(*(s32 *)D_L39_0024CBB8 + D_L39_001F0B80.base, 0x10, end, buf);
            func_00194B28(0);
            D_L39_0025CFC0.w4C = end;
        } else {
            D_L39_0025CFC0.w4C = 0;
        }
        D_L39_0025CFC0.w34 = 0;
        func_003A3288(spA, D_L39_0024CBD8_005F91C8 << 1, spB, 0xF8000);
        r = func_003AA2E8(D_L39_0024CBB0, D_L39_0024CBB4, func_003A32E0, D_L39_0024CBBC, D_L39_0024CBC0);
        p = D_L39_0025F600;
        if ((r ^ 1) == 0) {
            ((u8 *)p)[0x64] = 1;
        }
        if (r != 0) {
            if (!(D_L39_002405E8_005F91C8 & 0x40)) {
                ((u8 *)p)[0x64] = 1;
                func_0038E410((u8 *)p);
            }
        }
        if (D_L39_0025F600[0] != 0) {
            D_L39_0025F600[0] = D_L39_0025F600[0] + 1;
            if (D_L39_0025F600[0] + D_001A5990[0xAD] >= 4) {
                D_L39_0025F600[0] = 1;
            }
            if (D_L39_0025F600[0] == 2) {
                D_L39_002405E8_005F91C8 = 0;
                if (D_001A5990[0xAD] != 0) {
                    D_L39_0024CBC0 = 0;
                    idx = func_003A3220(0x1D);
                } else {
                    D_L39_0024CBC0 = 1;
                    idx = func_003A3220(0x1F);
                }
            } else if (D_L39_0025F600[0] == 3) {
                D_L39_0024CBC0 = 1;
                D_L39_002405E8_005F91C8 = 0;
                idx = func_003A3220(0x1E);
            } else {
                D_L39_0024CBC0 = 0;
                D_L39_002405E8_005F91C8 = 1;
                idx = func_003A3220(0);
            }
            D_L39_0024CBB8 = (s32)&D_L39_001F0B80.files[idx * 2];
            D_L39_0024CBB0 = D_L39_001F0B80.files[idx * 2 + 1].sector + D_L39_001F0B80.base;
            D_L39_0024CBB4 = D_L39_001F0B80.files[idx * 2 + 1].size;
        } else if (D_L39_0025F600[0x18] == 0) {
            done = 1;
        } else {
            func_0038E248((u8 *)D_L39_0025F600, &sp10, &sp14);
            if (sp14 == 0) {
                D_L39_0024CBC0 = sp10 == 0x1F;
                idx = func_003A3220(sp10);
                D_L39_0024CBB8 = (s32)&D_L39_001F0B80.files[idx * 2];
                D_L39_0024CBB0 = D_L39_001F0B80.files[idx * 2 + 1].sector + D_L39_001F0B80.base;
                D_L39_0024CBB4 = D_L39_001F0B80.files[idx * 2 + 1].size;
            } else if (sp14 == 1) {
                done = 1;
            }
        }
    } while (!done);
    func_00194B28(0);
    func_0013A9D8(D_00194F40);
    func_001331A0(0, 0);
    func_L39_005F3D60();
    D_L39_0025DEC0[4] = 0;
    func_003A3BB8();
    if (r == 0 && sp14 == 1) {
        func_L39_005BD7D8(2, 2, sp10, 0, 0);
    } else {
        func_L39_005BD880(0, 0);
    }
}
/* localdecomp:end func_L39_005F91C8 */
