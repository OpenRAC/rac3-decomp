#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_003A8B10(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


typedef struct { u8 p0[0x34]; s32 f34; u8 p38[0x14]; s32 f4C; } S_225780_3A21C0;
extern void func_003A8B10(void);
extern void func_11F0A0(s32);
extern void func_003A91D0();
extern void func_0039C410();
extern void func_003A92F0();
extern S_225780_3A21C0 D_00225700_003A7A18;
extern u8 D_001D52E0;
extern u8 D_13D208[];
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern void func_003A1C28(void);
extern s32 func_003A8770(s32);
extern void func_003912E8(void);
extern void func_003A5430(void);
extern long func_13CDF0_003A7A18(s32);
extern s32 func_13CD28(s32, s32, s32, void *);
extern void func_003A87D8(s32, s32, s32, s32);
extern u32 func_003A8830(s32, u32);
extern s32 func_003AF890(s32, s32, s32 (*)(s32, s32), s32, s32);
extern s32 func_12A9F0(s32, s32);
extern void func_12D4D8(u8 *);
extern void func_003A9108(void);
extern s32 D_001DA034;
extern s32 D_00227400[];
extern s32 D_001DA030;
extern s32 D_001DA03C;
extern s32 D_001DA040;
extern s32 D_001D4D40;
/* localdecomp:start func_003A8B10 */
typedef struct { s32 f0; u8 pad4[0x5C]; s32 active; u8 flag64; u8 pad65[3]; } Object_0038E440_003A8EC8;
typedef struct { s32 off; s32 size; } P_003A8EC8;
typedef struct { s32 f0; s32 base; P_003A8EC8 e[1]; } T_003A8EC8;
extern T_003A8EC8 D_00160C40;
extern Object_0038E440_003A8EC8 D_00227400_003A8B10;
extern s32 D_00227580[];
extern s32 D_00142430[];
extern s32 D_001DA058;
extern u8 D_00143950[];
typedef struct { unsigned long v; u16 h8; u16 hA; u8 bC; u8 bD; s16 hE; } T_003A8EC8b;
extern T_003A8EC8b D_00226000[];
extern P_003A8EC8 *D_001DA038;
extern void func_00392C48(s32 *);
extern void func_003A0F98(s32, s32);
extern void func_00392A80(void *, s32 *, s32 *);
extern void func_003D9DA8(void);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
void func_003A8B10(void)
{
    u8 message[16];
    s32 choice, done;
    s32 source, destination, output;
    s32 result, exit_loop;
    s32 r;
    u8 *opt;

    if (D_001DA034 == 0) {
        func_00392C48(D_00227400);
        func_003A0F98(0, 0);
        return;
    }
    source = D_00227580[3];
    destination = D_00227580[5];
    output = destination + 0xF8000;
    func_003A92F0(1);
    D_001D4BB0 = D_001D4BB4;
    func_003912E8();
    func_003A91D0();
    func_003A92F0(1);
    func_11F0A0(0);
    func_003A5430();
    func_003A1C28();
    func_13CDF0_003A7A18(0);
    while (D_00142430[0x15C / 4] >= 3 || D_00142430[0x164 / 4] >= 0)
        func_0039C410();
    done = -1;
    choice = 0;
    exit_loop = 0;
    do {
        if (D_001DA038 && D_001DA038->off) {
            message[0] = 100;
            message[1] = D_001D52E0;
            message[2] = 0;
            func_13CDF0_003A7A18(0);
            func_13CD28(D_001DA038->off + D_00160C40.base, 16, output, message);
            func_13CDF0_003A7A18(0);
            D_00225700_003A7A18.f4C = output;
        } else {
            D_00225700_003A7A18.f4C = 0;
        }
        D_00225700_003A7A18.f34 = 0;
        func_003A87D8(source, D_001DA058 << 1, destination, 0xF8000);
        result = func_003AF890(D_001DA030, D_001DA034, (s32 (*)(s32, s32))func_003A8830, D_001DA03C, D_001DA040);
        {
            Object_0038E440_003A8EC8 *menu = &D_00227400_003A8B10;
            s32 cancelled = result == 1;
            if (cancelled)
                menu->flag64 = 1;
            if (result && !(D_001D4D40 & 0x40)) {
                menu->flag64 = 1;
                func_00392C48((s32 *)menu);
            }
        }
        if (D_00227400_003A8B10.f0) {
            opt = D_00143950;
            if (++D_00227400_003A8B10.f0 + opt[0xAD] >= 4)
                D_00227400_003A8B10.f0 = 1;
            if (D_00227400_003A8B10.f0 == 2) {
                D_001D4D40 = 0;
                if (opt[0xAD]) {
                    D_001DA040 = 0;
                    r = func_003A8770(0x1D);
                } else {
                    D_001DA040 = 1;
                    r = func_003A8770(0x1F);
                }
            } else if (D_00227400_003A8B10.f0 == 3) {
                D_001DA040 = 1;
                D_001D4D40 = 0;
                r = func_003A8770(0x1E);
            } else {
                D_001DA040 = 0;
                D_001D4D40 = 1;
                r = func_003A8770(0);
            }
            D_001DA038 = &D_00160C40.e[r * 2];
            D_001DA030 = D_00160C40.e[r * 2 + 1].off + D_00160C40.base;
            D_001DA034 = D_00160C40.e[r * 2 + 1].size;
        } else if (D_00227400_003A8B10.active == 0) {
            exit_loop = 1;
        } else {
            func_00392A80(&D_00227400_003A8B10, &choice, &done);
            if (done == 0) {
                D_001DA040 = choice == 0x1F;
                r = func_003A8770(choice);
                D_001DA038 = &D_00160C40.e[r * 2];
                D_001DA030 = D_00160C40.e[r * 2 + 1].off + D_00160C40.base;
                D_001DA034 = D_00160C40.e[r * 2 + 1].size;
            } else if (done == 1) {
                exit_loop = 1;
            }
        }
    } while (!exit_loop);
    func_13CDF0_003A7A18(0);
    func_12D4D8(D_13D208);
    func_12A9F0(0, 0);
    func_003D9DA8();
    D_00226000[2].v = 0;
    func_003A9108();
    if (result == 0 && done == 1)
        func_003A0EC0(2, 2, choice, 0, 0);
    else
        func_003A0F98(0, 0);
}
/* localdecomp:end func_003A8B10 */

/* localdecomp:start func_003A8F50 */
extern s32 D_001425AC[];
extern s16 D_0016C5A8[];
extern s32 D_001D4D40;
extern void func_00392DF0(s32, s32);
void func_003A8F50(void) {
    D_001D4D40 = 1;
    D_0016C5A8[0] = 1;
    D_001425AC[0] = 1;
    func_00392DF0(1, 1);
}
/* localdecomp:end func_003A8F50 */
TEXT_PADDING(2);

/* localdecomp:start func_003A8F90 */
extern void func_0038CB50();
void func_003A8F90(u32 a) {
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_0038CB50(0x10);
    }
    *(volatile u32 *)0x10008020 = 0;
    *(volatile u32 *)0x10008030 = a & 0xFFFFFFF;
    *(volatile u32 *)0x10008000 = 0x145;
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_0038CB50(0x10);
    }
}
/* localdecomp:end func_003A8F90 */
