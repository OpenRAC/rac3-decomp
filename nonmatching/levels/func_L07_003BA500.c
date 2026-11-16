/* NTSC-U draft (Claude wave C4): C of func_L07_003B8C10, the NTSC-U twin of func_L07_003BA500, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 264 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L07_003B8C10", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH) only with the extra @ps2as; its PAL counterpart file src/levels/07_annihilation_nation/L07_003B9A90.c has no @ps2as (264 diff with its flags). Cause: the retail code has 'lw $v0, sym' macro loads of D_L07_001DF420/001DF41C/001DF458 ...
 */
#include "common.h"

/* localdecomp:start func_L07_003B8C10 */
typedef struct {
    u8 pad_00[0x40];
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    u8 pad_50[0x44];
    s32 f94;
    s32 f98;
    u8 pad_9C[4];
    s16 hA0;
    s16 hA2;
    s16 hA4;
    s16 hA6;
    s16 hA8;
    s16 hAA;
    s16 hAC;
    u8 bAE;
} Sub_3B8C10;

extern u16 *D_L07_0021C020_003B8C10[];
extern u8 *D_L07_001DF41C_003B8C10;
__asm__(".extern D_L07_001DF41C_003B8C10, 16");
extern u8 *D_L07_001DF420;
__asm__(".extern D_L07_001DF420, 16");
extern s32 D_L07_001DF458_003B8C10;
__asm__(".extern D_L07_001DF458_003B8C10, 16");
extern u8 D_00142660[];
extern u8 D_001A4BE0[];

extern void func_L07_003BECE8(u8 *, s32);
extern void func_L07_003B0FB8(u8 *);
extern void func_L07_003A7518(u8 *, s32, u8 *);
extern void func_L07_003B78D8(u8 *, s32, u8 *);
extern void func_L07_003BB3C0(u8 *, s32, u8 *);
extern void func_L07_003C6C48(u8 *, s32, u8 *);
extern void func_L07_003BC958(u8 *, s32, u8 *);
extern void func_L07_003AEC48(u8 *, s32, u8 *);
extern void func_L07_00350400(u8 *, s32, u8 *);
extern void func_L07_003CB328(u8 *, s32, u8 *);
extern void func_L07_003D10A8(u8 *, s32, u8 *);
extern void func_L07_003B8058(u8 *, s32);
extern void func_L07_003E1668(u8 *, s32);
extern s32 func_0037E1D8(s32);
extern void func_L07_003B9E78(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_003B8C10(u8 *obj, u8 flag) {
    Sub_3B8C10 *sub = *(Sub_3B8C10 **)(obj + 0x68);
    u8 *rec;
    u16 *p;
    u16 *q;
    s32 idx;
    s32 idy;
    u8 *hero;
    u8 *ctl;

    sub->bAE = flag;
    for (p = D_L07_0021C020_003B8C10[sub->f40];
         ((idx = sub->f40) & 0xFF) != 0xFF && !(D_L07_001DF458_003B8C10 < idx) && p != 0 &&
         (((s16 *)p)[-1] >= 0 || p == D_L07_0021C020_003B8C10[idx]);
         p++) {
        rec = D_L07_001DF41C_003B8C10 + ((*p & 0x7FFF) << 8);
        if (rec == 0) {
            break;
        }
        func_L07_003BECE8(rec, sub->bAE);
    }
    for (q = D_L07_0021C020_003B8C10[sub->f44];
         ((idy = sub->f44) & 0xFF) != 0xFF && !(D_L07_001DF458_003B8C10 < idy) && q != 0 &&
         (((s16 *)q)[-1] >= 0 || q == D_L07_0021C020_003B8C10[idy]);
         q++) {
        rec = D_L07_001DF41C_003B8C10 + ((*q & 0x7FFF) << 8);
        if (rec == 0) {
            break;
        }
        func_L07_003B0FB8(rec);
    }
    for (rec = D_L07_001DF41C_003B8C10; rec < D_L07_001DF420; rec += 0x100) {
        if (rec[0xB0] == sub->f4C) {
            continue;
        }
        switch (*(s16 *)(rec + 0xAA)) {
        case 0x1982:
            func_L07_003A7518(rec, sub->bAE, obj);
            break;
        case 0x1A4A:
            func_L07_003B78D8(rec, sub->bAE, obj);
            break;
        case 0x1A85:
        case 0x19D2:
        case 0x1D88:
            func_L07_003BB3C0(rec, sub->bAE, obj);
            break;
        case 0x19BD:
        case 0x1ADB:
        case 0x1D8A:
            func_L07_003C6C48(rec, sub->bAE, obj);
            break;
        case 0x19BE:
        case 0x1A9B:
        case 0x1D89:
            func_L07_003BC958(rec, sub->bAE, obj);
            break;
        case 0x19DA:
            func_L07_003AEC48(rec, sub->bAE, obj);
            break;
        case 0x161E:
            func_L07_00350400(rec, sub->bAE, obj);
            break;
        case 0x1769:
        case 0x1B36:
        case 0x1D8B:
            func_L07_003CB328(rec, sub->bAE, obj);
            break;
        case 0x1C34:
            func_L07_003D10A8(rec, sub->bAE, obj);
            break;
        case 0x1A58:
            func_L07_003B8058(rec, sub->bAE);
            break;
        case 0x1E26:
            func_L07_003E1668(rec, sub->bAE);
            break;
        }
    }
    sub->hA0 = 0;
    sub->hA2 = 0;
    sub->hA4 = 0;
    sub->f94 = 0;
    sub->f98 = 0;
    sub->hA6 = 0;
    sub->hAA = 0;
    sub->hA8 = func_0037E1D8(0x3C) + 0x78;
    sub->hAC = 0;
    hero = D_001A4BE0;
    ctl = D_00142660;
    *(s32 *)(hero + 0x2850) = *(s32 *)(ctl + 8);
    func_L07_003B9E78(obj);
    func_L01_00441FB8(obj, 2, -1);
}
/* localdecomp:end func_L07_003B8C10 */
