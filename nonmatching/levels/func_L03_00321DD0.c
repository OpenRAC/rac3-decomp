/* near miss (level 3, Starship Phoenix): 163 differences, codegen detail (all five cases of the jump-table switch are written in table order): the jump-table setup differs (the C puts sll before the lui and uses $v1 where retail uses $a0), retail keeps the D_00142CA0 base in $a0 (lui+addiu, so +0x22 and +0x1E are offsets from a held pointer) and puts the D_001426E0 lui in the beqz delay slot while the C folds the offset into the address and leaves a nop; globals as plain arrays, locals at the top (189), locals inside case 0 (163-177) and struct-typed globals (174) tried */
#include "common.h"

/* localdecomp:start func_L03_00321DD0 */
typedef struct S_00321DD0 {
    s32 f0;
    s32 f4;
    u8 pad8[4];
    s32 fC;
    u8 pad10[0x14];
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    u8 pad44[0x26];
    s16 f6A;
    u8 f6C;
} S_00321DD0;

typedef struct A_00321DD0 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x47];
    S_00321DD0 *f68;
} A_00321DD0;

extern u8 D_00142CA0[];
__asm__(".extern D_00142CA0, 16");
extern u8 D_001426E0[];
__asm__(".extern D_001426E0, 16");
extern u8 D_001426E8;
__asm__(".extern D_001426E8, 16");
extern s32 D_00142C10[];
__asm__(".extern D_00142C10, 16");
extern u32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u32 D_001A8114[];
__asm__(".extern D_001A8114, 16");
extern u32 D_001A8318[];
__asm__(".extern D_001A8318, 16");
extern u8 D_001A4C60[];
extern char *D_L03_001DF99C_00321DD0;
__asm__(".extern D_L03_001DF99C_00321DD0, 16");
extern void func_L03_003220D8_00321DD0();
extern void func_L03_00322160_00321DD0();
extern void func_L03_00322548_00321DD0();
extern void func_L01_004BAF50(void);
extern s32 func_L01_004BA800(void);
extern void func_0039EF28(void);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_00382380(u8 *, s32, s32);
extern s32 func_0038CB00(s16 *);
extern void func_L01_004450F0(A_00321DD0 *, s32, s32);
extern void func_L01_00456230(char *, s32);

void func_L03_00321DD0(A_00321DD0 *a) {
    S_00321DD0 *p = a->f68;
    s32 r;
    u8 *c;
    u8 *e;

    func_L03_003220D8_00321DD0();
    func_L03_00322160_00321DD0(a);
    switch (a->f20) {
    case 0:
        func_L01_004BAF50();
        c = D_00142CA0;
        if (c[0x22] != 0) {
            r = p->f40;
        } else {
        e = D_001426E0;
        if (e[0x28] != 0) {
            r = p->f3C;
        } else if (e[0x20] != 0) {
            r = p->f38;
        } else if (e[0x3D] != 0) {
            r = p->f34;
        } else if (e[0x74] != 0) {
            r = p->f30;
        } else if (c[0x1E] != 0) {
            if (e[0xC] == 0) {
                e[0xC] = 1;
                func_0039EF28();
                e[0x16] = 1;
                func_0039EF28();
            }
            r = p->f28;
        } else {
            func_L03_00322548_00321DD0(a, p->f24);
            p->f6C = 0xFF;
            func_L01_004450F0(a, 1, -1);
            return;
        }
        }
        func_L03_00322548_00321DD0(a, r);
        return;
    case 1:
        if (D_001426E8 != 0) {
            func_L01_004450F0(a, 2, -1);
            return;
        }
        if (func_L01_004BA800() == 0) {
            if ((D_001A8114[0] & (1 << D_001D545C)) == 0) {
                func_L01_0041A5B0(0xB9C, 0x3F);
            }
        }
        if (p->f6C == 0xFF) {
            if (func_00382380(D_001A4C60, p->fC, 0) != 0) {
                p->f6C = 0;
                p->f6A = 0xBB8;
                func_L01_0041A5B0(0xA1C, 9);
            }
            return;
        }
        if (func_0038CB00(&p->f6A) == 0) {
            return;
        }
        p->f6A = 0xBB8;
        if (func_00382380(D_001A4C60, p->f0, 0) == 0) {
            return;
        }
        p->f6C = (p->f6C + 1) % 3;
        func_L01_0041A5B0(0xA1C + p->f6C, 9 + p->f6C);
        return;
    case 2:
        if (D_001426E0[9] != 0) {
            func_L01_004450F0(a, 4, -1);
            return;
        }
        if (func_00382380(D_001A4C60, p->f4, 0) == 0) {
            return;
        }
        D_001426E0[9] = 1;
        func_0039EF28();
        func_L01_00456230(D_L03_001DF99C_00321DD0 + (p->f2C << 8), 1);
        func_L01_004450F0(a, 3, -1);
        return;
    case 3:
        if (func_L01_004BA800() != 0) {
            return;
        }
        if ((D_00142C10[0] & 0x20000) == 0) {
            return;
        }
        if ((D_001A8318[0] & (1 << D_001D545C)) == 0) {
            func_L01_0041A5B0(0xCB8, 0x6A);
        }
        func_L01_004450F0(a, 4, -1);
        return;
    case 4:
        return;
    }
}
/* localdecomp:end func_L03_00321DD0 */
