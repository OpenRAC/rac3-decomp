/* NTSC-U draft (Claude wave K): C of func_L01_00497D48, the NTSC-U twin of func_L01_0049B5A8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 13 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L01_00497D48", whose code is not the PAL one).
 * Worker's note: 13 aligned diffs (was 31); needs @ps2as (retail builds 1.2f with lui/ori/mtc1; the PAL line lacks it, so the final answer is a flags result). What moved it: (1) func_L01_00498098's argument is a SEPARATE symbol (extern u8 D_L01_002EBF88[]; retail addiu ...
 */
#include "common.h"

/* NTSC-U counterpart of the L01 menu init */
/* localdecomp:start func_L01_00497D48 */
typedef struct { s32 f0; s32 p4; s32 f8; s32 pC; s32 p10; u8 flag; u8 pad[3]; } E_497D48;
extern E_497D48 D_L01_002EBF28[];
extern u8 D_L01_002EBF88[];
extern s32 D_001D943C_sda;
__asm__(".extern D_001D943C_sda, 4");
extern s32 D_001D9438_sda;
__asm__(".extern D_001D9438_sda, 4");
extern s32 D_001D9434_sda;
__asm__(".extern D_001D9434_sda, 4");
extern void func_L01_00498868(void);
extern void func_00389920(s32);
extern void func_L01_004962E0(s32, f32 *, f32 *);
extern s32 func_0037DF98(s32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00512828(s32, f32);
extern void func_L01_00498098(void *);
extern void func_003E2DE0(s32, s32);
extern s32 func_003E29B8(s32, s32);
extern s32 *func_003AED40(s32);
extern void func_003E31A8(s32, s32 *);
extern void func_L01_005131A0(s32, s32);
extern void func_L01_00512D70(s32, s32);
extern void func_003E3250(s32, s32, s32);
extern void func_L01_00498378(void);
extern void func_L01_00498AD8(void);
extern void func_L01_00498978(void);

void func_L01_00497D48(void) {
    f32 a;
    f32 b;
    s32 i;
    s32 n;
    E_497D48 *p;

    i = 0;
    b = 0.0f;
    a = 1.2f;
    func_L01_00498868();
    func_00389920(0);
    func_L01_004962E0(0x1C2, &a, &b);
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_0037DF98(0x1C2), 0xD0006, 0x124, 0xD0007, 0xCD5, b);
    func_L01_00512828(0xD0005, a);
    func_L01_00498098(D_L01_002EBF88);
    func_003E2DE0(0x11, 0x4E0000);
    func_003E29B8(0x4E0005, 1);
    func_003E29B8(0x4E0006, 1);
    func_003E31A8(0x4E0009, func_003AED40(0));
    func_L01_005131A0(0x4E0009, 0);
    func_L01_00512D70(0x4E0009, 0);
    func_003E3250(0x4E0009, 1, 0xA);
    func_L01_00498378();
    func_L01_00498AD8();
    D_001D943C_sda = -1;
    if (D_L01_002EBF28[0].f0 != 0) {
        n = -1;
        p = D_L01_002EBF28;
        do {
            if (p->flag) n = i;
            p++;
            i++;
        } while (p->f0 != 0 && n < 0);
        D_001D943C_sda = n;
    }
    if (D_001D943C_sda < 0) {
        if (D_001D9438_sda != 0) D_001D943C_sda = 0;
    }
    if (D_001D943C_sda >= 0) {
        func_L01_005131A0(0x4E0009, D_L01_002EBF28[D_001D943C_sda].f8 + 1);
        func_L01_00512D70(0x4E0009, 1);
    }
    func_L01_00512D70(0x4E0009, 0);
    D_001D9434_sda = -1;
    func_L01_00498978();
}
/* localdecomp:end func_L01_00497D48 */
