/* Near miss: moby_killed (needs @ps2as on this file plus 'func_L01_004443E8 2' in divs_nops.txt, which is already appended). Complete C from the assembly: prologue and most of the body match, but gcc swaps $s1/$s2 (moby/bolts), merges the odd/even id-nibble paths and the table argument loads that retail duplicates, and orders the hit-flag locals and the D_001E0204 load differently. About 386 differing words, mostly that register swap. */
#include "common.h"
typedef struct {
    u8 pad0[0x10];
    f32 pos[3];
    u8 pad1C[0x24 - 0x1C];
    u8 *cls;
    u8 pad28[0x7F - 0x28];
    u8 hits;
    u8 pad80[0xB0 - 0x80];
    u8 kind;
    u8 flags;
    s16 id;
    s16 b4;
    u16 b6;
} M_4443E8;
typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
    u8 pad90[0x25C4 - 0x90];
    s32 state;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 mode;
    u8 pad25E5[0x25F3 - 0x25E5];
    u8 b25F3;
    u8 pad25F4[0x28C8 - 0x25F4];
    u8 xp_shift;
} H_4443E8;
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x34 - 0xC];
    s32 w34;
    s32 w38;
    s32 w3C;
} S_4443E8;
typedef struct {
    u8 pad0[0x7B];
    u8 b7B;
    u8 pad7C[0xE4 - 0x7C];
    u8 bE4;
} T_4443E8;
typedef struct {
    u8 pad0[0x17];
    u8 b17;
} R_4443E8;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[0xF0 - 2];
} Rec_4443E8;

extern H_4443E8 D_001A4BE0;
extern u8 D_001426BA[];
extern S_4443E8 D_00142660_4443E8;
extern T_4443E8 D_001426E0;
extern u8 D_001BBE90[];
extern u8 D_001BBC40[];
extern s32 D_001A2018[];
extern s32 D_00142DE0[];
extern u8 D_001425C0[];
extern Rec_4443E8 D_L01_002C5600[];
extern s32 D_001D545C;
extern u8 D_L01_001D60C8[];
extern u8 D_L01_001D60D0[];
extern u8 D_L01_001D60D8[];
extern u8 D_L01_001D60E0[];
extern s16 D_L01_001D60E8;
extern s16 D_L01_001D60EA;
extern s32 D_L01_001D7BE0;
extern f32 D_L01_001DAA34;
extern s32 D_L01_001DFF40;
extern u8 D_L01_001DFE80[];
extern s32 D_L01_001E0200[];
extern M_4443E8 *D_L01_001E0204[];
__asm__(".extern D_L01_001D7BE0, 4");
extern s32 D_L01_0021FF38[][0x9C];
extern u8 D_L01_00236B90[];
extern u8 D_L01_00237800[];
extern f32 D_L01_002F1600[];

extern void func_L01_00444288(M_4443E8 *, s32);
extern void func_L01_00444200(void);
extern s32 func_003C4B50(M_4443E8 *);
extern s32 func_L01_00444350(void);
extern s32 func_L01_004006C8(u8 *, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern R_4443E8 *func_00382348(M_4443E8 *);
extern void func_003E4D10(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_0044D360(M_4443E8 *, s32, s32, s32, f32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00415D40(s32, s32, s32, s32);
extern void func_L01_00415C98(s32, s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);

/* moby_killed: called by enemies as they die: the XP for the killing gun, the bolts and the bank's share. */
void func_L01_004443E8(M_4443E8 *moby, s32 hit, s32 killer) {
    s32 mult;
    u16 b6;
    s32 f100;
    s32 f400;
    s32 f1000;
    s32 hero;
    s32 bolts;
    s32 bank;
    s32 bank_cut;
    s32 gun_xp;
    s32 flags;
    f32 xp;
    f32 hero_mult;
    s32 i;
    s32 slot;
    R_4443E8 *rec;

    if (moby->id < 0) {
        return;
    }
    if (moby->flags & 0x80) {
        return;
    }
    moby->hits = moby->hits + 1;
    mult = 1;
    if (moby->cls != 0 && moby->cls[0x46] == 5) {
        mult = (D_001426BA[0] + 1) << D_001A4BE0.xp_shift;
        func_L01_00444288(moby, 0);
        func_L01_00444200();
    } else if (func_003C4B50(moby) != 0) {
        mult = (D_001426BA[0] + 1) << D_001A4BE0.xp_shift;
    }
    hero_mult = (f32)mult;
    b6 = moby->b6;
    f100 = hit & 0x100;
    f400 = hit & 0x400;
    hero = 1;
    f1000 = hit & 0x1000;
    if (moby != D_L01_001E0204[0]) {
        M_4443E8 **p = D_L01_001E0204;
        hero = 0;
        while (hero >= 0) {
            p--;
            if (*p == moby) {
                break;
            }
            hero--;
        }
    }
    gun_xp = 0;
    if (b6 != 0 || D_L01_001D7BE0 != -1) {
        if ((u8)(D_001A4BE0.mode - 1) >= 2) {
            bank = (D_00142660_4443E8.w38 + 0x31) / 0x32;
            if (D_L01_001D7BE0 != -1 && hero < 0 && func_003C4B50(moby) == 0) {
                bolts = func_L01_00444350();
            } else {
                s32 b = D_001BBE90[(moby->id >> 1) + (D_001D545C << 10)];
                u8 *tbl;
                if (moby->id & 1) {
                    if ((b >> 4) & 8) {
                        tbl = D_L01_001D60E0;
                    } else {
                        tbl = D_L01_001D60D8;
                    }
                } else {
                    if (b & 8) {
                        tbl = D_L01_001D60E0;
                    } else {
                        tbl = D_L01_001D60D8;
                    }
                }
                bolts = func_L01_004006C8(tbl, moby->b6, moby->id);
            }
            bolts = bolts << D_001A4BE0.xp_shift;
            if (func_L01_0041A4F0() != 0) {
                f32 fb = (f32)bolts;
                if (D_001D545C == 7 && D_001426E0.b7B != 0) {
                    bolts = (s32)(fb * D_L01_001DAA34);
                } else {
                    bolts = (s32)(fb * D_L01_002F1600[D_001D545C]);
                }
            }
            rec = func_00382348(moby);
            if (rec != 0) {
                if (rec->b17 != 0xFF && (func_L01_0041A4F0() != 0 || D_L01_002C5600[D_001425C0[rec->b17]].b1 != 4)) {
                    if (hero >= 0) {
                        s32 sum = 0;
                        for (i = 0; i < 0x9C; i++) {
                            sum += D_L01_0021FF38[hero][i];
                        }
                        if (sum != 0) {
                            f32 share = (f32)(bolts + bank) * (1.0f / (f32)sum);
                            for (i = 0; i < 0x9C; i++) {
                                f32 v = share * (f32)D_L01_0021FF38[hero][i];
                                if (v > 2147483648.0f) {
                                    v = 2147483648.0f;
                                }
                                D_00142DE0[i] += (s32)v;
                            }
                        }
                        D_L01_001E0200[hero] = 0;
                    } else {
                        D_00142DE0[rec->b17] += bolts + bank;
                    }
                }
            }
            D_00142660_4443E8.w38 -= bank;
            if (func_L01_0041A4F0() != 0 || D_00142660_4443E8.w8 < 100) {
                D_00142660_4443E8.w34 += bolts + bank;
            }
            func_003E4D10(0x258);
        }
    }
    bank_cut = 0;
    if (f1000 == 0) {
        bank_cut = (D_00142660_4443E8.w3C + 0x31) / 0x32;
        D_00142660_4443E8.w3C = D_00142660_4443E8.w3C - bank_cut;
    }
    if (D_L01_001D7BE0 != -1) {
        xp = (f32)func_00382498(D_L01_001D60E8, D_L01_001D60EA);
        if (hero >= 0) {
            xp = xp * 10.0f;
        }
    } else {
        s32 b = D_001BBE90[(moby->id >> 1) + (D_001D545C << 10)];
        u8 *tbl;
        if (moby->id & 1) {
            if ((b >> 4) & 8) {
                tbl = D_L01_001D60D0;
            } else {
                tbl = D_L01_001D60C8;
            }
        } else {
            if (b & 8) {
                tbl = D_L01_001D60D0;
            } else {
                tbl = D_L01_001D60C8;
            }
        }
        xp = (f32)func_L01_004006C8(tbl, moby->b4, moby->id);
    }
    if (moby->id >= 0 && (moby->flags & 0x80) == 0) {
        u8 *p;
        if (D_L01_001D7BE0 != -1 && func_003C4B50(moby) == 0) {
            D_001A2018[D_L01_001D7BE0]++;
        }
        p = &D_001BBE90[(moby->id >> 1) + (D_001D545C << 10)];
        if (moby->id & 1) {
            if (((*p >> 4) & 7) != 7) {
                *p += 0x10;
            }
        } else {
            if ((*p & 7) != 7) {
                *p += 1;
            }
        }
        D_L01_00236B90[moby->id + 0x464] = moby->kind + 2;
        slot = moby->kind;
        if (slot == 0xFF || (!(D_L01_001DFE80[slot] & 0x80) && (D_001BBC40[D_001D545C * 16 + slot] & 0x80))) {
            D_L01_00237800[moby->id + 0x464] = moby->kind + 2;
        }
    }
    xp = xp * hero_mult + (f32)bank_cut;
    flags = 1;
    if (f100) {
        flags = 5;
    }
    if (D_001A4BE0.b25F3 != 0 || (hit & 0x200)) {
        flags |= 2;
    }
    if (D_001A4BE0.state == 0x10) {
        if (func_0038CF00(D_001A4BE0.pos, moby->pos) < 4.0f) {
            flags |= 2;
        }
    }
    if (f400) {
        flags |= 0x10;
    }
    flags |= 8;
    if (!(D_L01_001DFF40 > 99)) {
        flags |= 2;
    }
    if (xp < 0.0f) {
        xp = 0.0f;
    }
    if (0.0f < xp) {
        s32 extra;
        if (xp >= 8.0f) {
            extra = (s32)(xp * 0.25f);
        } else {
            extra = 0;
            if (xp >= 2.0f) {
                extra = 1;
            }
        }
        func_L01_0044D360(moby, (s32)xp - extra, (s32)xp + extra, flags, 0.0f, -1, killer);
    }
    if (D_001426E0.bE4 == 0 && func_L01_0041A4F0() != 0) {
        s32 a = func_00381FF0(0x8DE);
        s32 b = func_00381FF0(0x827);
        func_L01_00415D40(a, 0, b, 1);
        func_L01_00415C98(0x40, 0);
        func_003A0EC0(4, 1, 10, 0, 0);
        D_001426E0.bE4 = 1;
    }
}
