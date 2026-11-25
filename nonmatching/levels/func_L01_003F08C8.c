/* PAL near miss (round 27 W31, from W27's draft): 14 aligned rows (difflib over the tools/check.py columns; W27's draft = 30 with the same scorer, 33 on W27's own), using the owning file's flags
 * (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2, S mode). Check: python tools/check.py nonmatching/levels/func_L01_003F08C8.c func_L01_003F08C8 --no-context
 * Earlier (W4, W8b, W21, W27): case order, inner switch, scalar externs for one-macro loads, plain D_001D54D0, masked halfword written twice, while-loop guard, s32 callees (func_0012C908, func_L01_0045FDF0).
 * New this round (30 -> 14): (1) the byte tables are 8-BYTE OBJECTS as every other file declares them (`extern u8 D_001D5570[8]`, `u8 D_001D5470[8]`): D_001D5573 is D_001D5570[3] and
 * D_001D5475 is D_001D5470[5]. D_001D5570[8] gives retail's `la` (adjacent lui/addiu, length 8 so it is never a delay-slot filler; address kept whole in $s2); D_001D5470[5] / D_001D5570[3]
 * give retail's `beq; nop` / `bne; nop` (no beql, no gp-form load copied into the slot). The `tab` pointer local is gone.
 * (2) D_00142724 is an UNSIZED array (`D_00142724[0] = ...`): retail's `lui $v0,0x14; sb $v1,0x2724($v0)` is the split form (hi half in a register), not `lui $at`.
 * Still differs (all in the loop's end block and allocation, 14 rows): (a) a/b/old in $s0-$s2 (retail b=$s0 a=$s1 old=$s2; here a=$s0 b=$s2 old=$s1: regalloc.py priorities a .050 (8 refs / live 484),
 * old .033 (4 / 239), b .025 (6 / 488)); (b) retail's end of loop is `xori $v0,$v0,2; addiu $s1,$zero,1; move $s0,$s1; movz $s0,$zero,$v0` (a = 1; b = a; if (c == 2) b = 0): jump.c merges `b = a` into
 * the conditional move and cse folds a to the constant 1 in every spelling (`b = a; if`, if/else, `c == 2 ? z : a`, u8/u32 a,b, `b = a = 1`: `xori; sltu`; a ternary: `move b,0; movn b,a,t`, `(a, 0)` as the
 * then-arm the same); `a = (c != 0); b = a; if (c == 2) b = 0;` gives the `move; movz` shape with `sltu` for a; `a = (c >> 8) == 0;` (or `(c >> 8) + 1`, `| 1`: unknown to cse1, folded by combine) gives
 * retail's `xori; li; move; movz` shape (15 aligned) BUT with the roles reversed (`li` in b's register, `move a,b`, `movz b`): cse2 rewrites `b = a` after the insn that set a into `b = <that insn>; a = b`.
 * Retail needs `li a,1`, `move b,a`, `movz b`: a constant that cse1 does not fold into `b = a` and a `b = a` that is not right after a's setter (a statement between does not help: the cmove then merges, movn). (c) the switch head: retail loads D_001D6694 into $v1 and adds 2 in place ($v1), here $a0 (x shared with the call arguments; a separate local or no local: 17).
 * Tried and not better: `a = 0; b = 0` order (15), declaration order b/a/old (14), old before a/b (14), do { b = a; } while (0) around the copy (13 but contrived and still sltu), two guards for a / b (14-20).
 * Check the jump table if this lands (the 0x2c/-0x47d0 words in check.py are the table relocation). */
#include "common.h"
/* localdecomp:start func_L01_003F08C8 */
typedef struct { u8 b0; u8 pad1[0xF]; s32 w10; u8 pad14[0xF0 - 0x14]; } Row_3F08C8;
typedef struct { u8 pad0[0x14]; s32 w14; u8 pad18[0x40 - 0x18]; s16 h40; } Obj142660_3F08C8;
typedef struct { u8 pad0[0x18]; s32 w18; u8 pad1C[0x26 - 0x1C]; s16 h26; s16 h28; s16 h2A; s16 h2C; u8 pad2E[2]; s32 w30; } Obj16C580_3F08C8;
typedef struct { u8 pad0[0x1228]; s32 w1228; u8 pad122C[0x25F2 - 0x122C]; u8 b25F2; } Obj1A4BE0_3F08C8;
extern s32 D_001D4B60;
extern s32 D_001D4B90;
extern s32 D_001D4BA0;
extern s32 D_001D4C40;
extern u8 D_001D5470[8];
extern u16 D_001D54D2;
extern s32 D_001D54D0;
extern s32 D_001D4CF0_sda;
__asm__(".extern D_001D4CF0_sda, 4");
extern s32 D_001D545C;
extern u8 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 1");
extern u8 D_001D5570[8];
extern Obj1A4BE0_3F08C8 D_001A4BE0;
extern Obj16C580_3F08C8 D_0016C580;
extern Obj142660_3F08C8 D_00142660;
extern u8 D_001425C0[];
extern Row_3F08C8 D_002C5600[];
extern s32 D_00143950[];
extern u8 D_001A9318[];
extern u8 D_00142724[];
extern unsigned long D_001D4AC0;
extern s32 D_001D6694;
extern s32 D_001D6694_sda;
__asm__(".extern D_001D6694_sda, 4");
extern s32 D_001D6690;
extern s32 D_001D668C;
extern s32 D_001D6698;
extern s32 D_001DFB44;
extern f32 D_001DFB4C;
extern s32 D_001DFB54;
extern s32 D_001DFB54_sda;
__asm__(".extern D_001DFB54_sda, 4");
extern s32 D_001DFB48;
extern s32 D_001D6674;
extern s32 D_001DF948;
extern s32 D_001DF948_sda;
__asm__(".extern D_001DF948_sda, 4");
extern u8 D_001D672E_sda;
__asm__(".extern D_001D672E_sda, 1");
extern s32 D_001D56C0_sda;
__asm__(".extern D_001D56C0_sda, 4");
extern s32 D_001D56C4_sda;
__asm__(".extern D_001D56C4_sda, 4");
extern s32 D_001D52E8_sda;
__asm__(".extern D_001D52E8_sda, 4");
extern s32 D_001D52F0_sda;
__asm__(".extern D_001D52F0_sda, 4");
extern s32 D_001D52F4_sda;
__asm__(".extern D_001D52F4_sda, 4");
extern s32 func_0012C908();
extern void func_0013B620();
extern void func_0013CA20();
extern void func_L01_003F1188_003F08C8();
extern void func_L01_003F1218_003F08C8();
extern void func_L01_003F1478_003F08C8();
extern void func_L01_003F1600_003F08C8();
extern void func_L01_003F1680_003F08C8();
extern void func_L01_003F19B8_003F08C8();
extern void func_L01_003F1E68_003F08C8();
extern void func_L01_003F2000_003F08C8();
extern void func_L01_003F26E0_003F08C8();
extern void func_L01_003F5808_003F08C8();
extern void func_L01_004027B0_003F08C8();
extern void func_L01_00403B68_003F08C8();
extern void func_L01_00403B90_003F08C8();
extern void func_L01_00403BB8_003F08C8();
extern void func_L01_00403BE8_003F08C8();
extern void func_L01_00403C48_003F08C8();
extern void func_L01_00403C88_003F08C8();
extern void func_L01_00404D80_003F08C8();
extern void func_L01_004054F0_003F08C8();
extern void func_L01_00407950_003F08C8();
extern void func_L01_004152F8_003F08C8();
extern void func_L01_00415410_003F08C8();
extern void func_L01_00415788_003F08C8();
extern void func_L01_00416DC8_003F08C8();
extern s32 func_L01_00419F70_003F08C8();
extern void func_L01_0041BFE8_003F08C8();
extern void func_L01_00422548_003F08C8();
extern void func_L01_00423020_003F08C8();
extern void func_L01_00423040_003F08C8();
extern void func_L01_004255E0_003F08C8();
extern void func_L01_00425B18_003F08C8(s32);
extern void func_L01_00425D48_003F08C8();
extern void func_L01_00425E10_003F08C8();
extern void func_L01_00425FE0_003F08C8();
extern void func_L01_0042B4F8_003F08C8();
extern void func_L01_0042CBC0_003F08C8();
extern void func_L01_0042DB70_003F08C8();
extern void func_L01_004309D0_003F08C8();
extern void func_L01_00431E88_003F08C8();
extern void func_L01_004334D0_003F08C8();
extern void func_L01_004361E0_003F08C8();
extern void func_L01_00436740_003F08C8();
extern void func_L01_00437560_003F08C8();
extern void func_L01_0044CD60_003F08C8();
extern void func_L01_00451F60_003F08C8();
extern void func_L01_00459F60_003F08C8();
extern void func_L01_0045A550_003F08C8();
extern void func_L01_0045A590_003F08C8();
extern void func_L01_0045EEF0_003F08C8();
extern void func_L01_0045F328_003F08C8();
extern void func_L01_0045F360_003F08C8();
extern s32 func_L01_0045FDF0_003F08C8();
extern void func_L01_00461818_003F08C8();
extern void func_L01_004781D0_003F08C8();
extern void func_L01_00478608_003F08C8();
extern void func_L01_0047D148_003F08C8();
extern void func_L01_0047E738_003F08C8();
extern void func_L01_004AD9A0_003F08C8();
extern void func_L01_004AF178_003F08C8();
extern void func_L01_004B0298_003F08C8();
extern void func_L01_004B1020_003F08C8();
extern void func_L01_004B88B0_003F08C8();
extern void func_L01_004B8DC0_003F08C8();
extern void func_L01_004B8ED0_003F08C8();
extern void func_L01_004B96E8_003F08C8();
extern void func_L01_004BA278_003F08C8();
extern void func_L01_004BDF78_003F08C8();
extern void func_L01_004C0888_003F08C8();
extern void func_L01_004C5810_003F08C8();
extern void func_L01_004C5858_003F08C8();
extern void func_L01_004C58D8_003F08C8();
extern void func_L01_004C59F8_003F08C8();
extern void func_L01_004CA8C8_003F08C8();
extern void func_L01_004CA928_003F08C8();
void func_L01_003F08C8(void) {
    s32 a;
    s32 b;
    s32 old;
    s32 x;
    s32 flag;
    func_L01_003F1188_003F08C8();
    func_L01_004B1020_003F08C8();
    D_001D6694 = 0;
    D_001D6690 = -2;
    D_001D668C = 0;
    D_001DFB48 = 0;
    func_L01_00422548_003F08C8();
    if (D_001D4B60 != D_00142660.h40) {
        func_L01_004255E0_003F08C8(D_00142660.h40);
    }
    {
        s32 status = func_L01_00419F70_003F08C8();
        if (D_001D4B90 != status) {
            func_L01_00425B18_003F08C8(status);
        }
    }
    if (D_001D4BA0 != D_001D5470[5]) {
        func_L01_00425FE0_003F08C8(D_001D5470[5]);
    }
    if (D_0016C580.w30 != (D_001D54D2 & 0x1F)) {
        func_L01_00425E10_003F08C8(D_001D54D2 & 0x1F);
    }
    x = D_001D54D0 & 3;
    if (D_0016C580.w18 != x) {
        func_L01_00425D48_003F08C8(x);
    }
    if (D_002C5600[D_001425C0[D_001A4BE0.w1228]].b0 == 0) {
        func_L01_0044CD60_003F08C8(9);
    }
    func_L01_0042B4F8_003F08C8(1, 0);
    func_L01_0042DB70_003F08C8();
    func_L01_0041BFE8_003F08C8();
    func_L01_00436740_003F08C8();
    func_L01_00478608_003F08C8();
    func_L01_003F2000_003F08C8();
    if (D_0016C580.h2C != 0) {
        func_L01_00404D80_003F08C8(8);
        D_0016C580.h2C = 0;
    }
    func_L01_003F1E68_003F08C8();
    D_0016C580.h2A = 1;
    if (D_0016C580.h28 != 0) {
        D_0016C580.h28 = 0;
    }
    x = D_001D545C;
    flag = 1;
    if (x == 1 || x >= 0x17 || x == 0xC || x == 0x12 || x == 0x14) {
        flag = 0;
    }
    if (D_001D5570[x] == 0) {
        if (x == 9 || x == 0xD) {
            flag = 0;
        }
    }
    if (x == 3) {
        if (D_001D5570[3] == 0 || (u32)(D_001D4CF0_sda - 0x1F) < 5) {
            flag = 0;
        }
    }
    if (flag != 0) {
        func_L01_0045A590_003F08C8(6, 1, 6, 0, 0);
    }
    D_0016C580.h26 = 0;
    D_001D52E8_sda = 0;
    if (D_001D545C < 0x25) {
        if (D_001D5570[D_001D545C] == 0) {
            D_001D5570[D_001D545C] = 1;
            func_L01_00437560_003F08C8();
        }
    }
    func_L01_00404D80_003F08C8(4);
    D_001DF948_sda = 0;
    func_L01_0045EEF0_003F08C8(0, 1, 0x400);
    func_L01_0045F328_003F08C8(0);
    func_0013CA20();
    func_L01_0045FDF0_003F08C8(1);
    {
        Row_3F08C8 *r = &D_002C5600[D_001425C0[D_001D4C40]];
        func_L01_0042CBC0_003F08C8(r->w10);
    }
    func_L01_0045FDF0_003F08C8(1);
    {
        Row_3F08C8 *r = &D_002C5600[D_001425C0[D_00142660.w14]];
        func_L01_0042CBC0_003F08C8(r->w10);
    }
    func_L01_0045FDF0_003F08C8(1);
    func_L01_00459F60_003F08C8();
    if (D_001D6694 == 0) {
        func_L01_0045F360_003F08C8();
    }
    while (D_001D6674 == 0) {
        D_001D4AC0 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        D_001DFB54 = 0;
        b = 0;
        a = 0;
        old = D_001D6694_sda;
        func_L01_00407950_003F08C8();
        func_L01_004C58D8_003F08C8();
        func_L01_004C5858_003F08C8();
        func_L01_00415410_003F08C8();
        if (D_001D6694 == 0 || D_001D6694 == 2) {
            func_L01_00415788_003F08C8(1);
        } else {
            func_L01_00415788_003F08C8(1);
        }
        func_L01_004152F8_003F08C8();
        func_0013B620();
        x = D_001D6694;
        switch (x) {
        case -1:
        case 0:
            switch (D_001D6698) {
            case 0:
                D_001D52F4_sda = 0;
                D_001D52F0_sda = 0;
                func_L01_00461818_003F08C8();
                func_L01_004B8ED0_003F08C8();
                if (D_001D56C0_sda == 1) {
                    D_001D4AC0 += *(volatile u32 *)0x10000800;
                    *(volatile u32 *)0x10000800 = 0;
                    func_L01_00461818_003F08C8();
                    func_L01_004B8ED0_003F08C8();
                }
                func_L01_00403B68_003F08C8();
                break;
            case 1:
            case 2:
            case 3:
                func_L01_003F19B8_003F08C8();
                break;
            }
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 8:
            func_L01_00461818_003F08C8();
            func_L01_004CA928_003F08C8();
            func_L01_004CA8C8_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 14:
            func_L01_00461818_003F08C8();
            func_L01_004B8ED0_003F08C8();
            func_L01_00403B90_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 18:
            func_L01_0047D148_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 10:
        case 11:
        case 12:
        case 16:
            func_L01_00461818_003F08C8();
            func_L01_0045A590_003F08C8(0, 2, 0, 0, 0);
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 7:
            func_L01_00461818_003F08C8();
            func_L01_004B96E8_003F08C8();
            func_L01_00403C48_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 17:
            if (D_001DFB48 >= 0x1A2) {
                func_L01_00451F60_003F08C8(0x1DB2, 2, 0);
            }
            func_L01_004361E0_003F08C8();
            func_L01_004B8DC0_003F08C8();
            func_L01_003F5808_003F08C8();
            func_L01_00403B68_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 1:
            func_L01_004B88B0_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 2:
            func_L01_00461818_003F08C8();
            func_L01_004BA278_003F08C8();
            func_L01_00403BB8_003F08C8();
            func_L01_004054F0_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 3:
            func_L01_00461818_003F08C8();
            func_L01_0047E738_003F08C8();
            func_L01_00403C88_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 4:
            func_L01_00461818_003F08C8();
            func_L01_00416DC8_003F08C8();
            func_L01_00403BE8_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 5:
            func_L01_00461818_003F08C8();
            func_L01_004BDF78_003F08C8();
            func_L01_004C0888_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 6:
            func_L01_00461818_003F08C8();
            func_L01_004AD9A0_003F08C8();
            func_L01_004AF178_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case 9:
            func_L01_00461818_003F08C8();
            func_L01_00423020_003F08C8();
            func_L01_00423040_003F08C8();
            D_001DFB48 = D_001DFB48 + 1;
            break;
        case -2:
        case 13:
        case 15:
        case 19:
            D_001DFB48 = D_001DFB48 + 1;
            break;
        default:
            D_001DFB48 = D_001DFB48 + 1;
            break;
        }
        func_L01_0045A550_003F08C8();
        if (D_001D6694 == 0) {
            func_L01_003F26E0_003F08C8();
        }
        func_L01_004334D0_003F08C8();
        func_L01_00431E88_003F08C8();
        func_L01_003F1218_003F08C8();
        func_L01_004C59F8_003F08C8(1);
        D_001DFB4C = (f32)*(volatile u32 *)0x10000800 / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
        if (D_001A4BE0.b25F2 == 0 && D_001DFB54_sda == 0) {
            if (D_001D6694_sda == 0) {
                func_L01_003F1478_003F08C8();
                func_L01_004781D0_003F08C8();
            } else if (D_001D6694_sda == 2) {
                func_L01_003F1600_003F08C8();
                func_L01_004781D0_003F08C8();
            } else {
                func_0012C908(0);
                D_001D56C0_sda = 0;
                D_001D56C4_sda = 0;
                D_001DF948_sda = D_001DF948 + 1;
                func_L01_004781D0_003F08C8();
            }
            if (D_001D6694 != 3) {
                D_001D672E_sda = 0;
            }
        }
        func_L01_004027B0_003F08C8();
        if (D_001D6694 == 0 && D_001A4BE0.b25F2 != 0) {
            a = 1;
            b = D_001A4BE0.b25F2 != 2 ? a : 0;
        }
        if (a != 0) {
            func_L01_003F1680_003F08C8(b);
        } else {
            func_L01_00459F60_003F08C8();
            if (D_001D6694 != old) {
                D_001DFB48 = 0;
            }
            if (D_001DFB54 != 0) {
                func_L01_004C5810_003F08C8();
            }
        }
    }
    func_L01_004309D0_003F08C8(D_001A9318 + (D_001D545C << 11));
    if (D_001DFB44 != D_001D545C) {
        D_00142724[0] = D_001D545C_sda;
    }
    func_L01_004B0298_003F08C8();
}
/* localdecomp:end func_L01_003F08C8 */
