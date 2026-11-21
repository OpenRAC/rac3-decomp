#include "common.h"

/* localdecomp:start func_L01_00443EA0 */
extern u8 D_L01_001FDBD0[];
extern u8 *D_L01_001FD180[];

void func_L01_00443EA0(s32 a0, s32 a1) {
    u8 *src;
    u8 *dst;
    s32 i;

    if (a0 == a1) {
        return;
    }
    src = D_L01_001FD180[D_L01_001FDBD0[a1]];
    dst = D_L01_001FD180[D_L01_001FDBD0[a0]];
    dst[0xC] = src[0xC];
    dst[0xA] = src[0xA];
    dst[0xD] = src[0xD];
    *(s32 *)(dst + 0x18) = *(s32 *)(src + 0x18);
    *(s32 *)(dst + 0x1C) = *(s32 *)(src + 0x1C);
    *(s32 *)(dst + 0x28) = *(s32 *)(src + 0x28);
    i = 0;
    if (src[0xC] != 0) {
        s32 *d;
        s32 *s;

        d = (s32 *)(dst + 0x48);
        s = (s32 *)(src + 0x48);
        do {
            *d = *s;
            i++;
            s++;
            d++;
        } while (i < src[0xC]);
    }
}
/* localdecomp:end func_L01_00443EA0 */

/* localdecomp:start func_L01_00443F50 */
s32 func_L01_00443F50(s32 a0) {
    s32 r = 0;
    if (a0 != 22 && a0 != 167 && a0 != 192 && a0 != 193 && a0 != 194 && a0 != 195 && a0 != 196 && a0 != 111 && a0 != 87) {
        r = a0 != 151;
    }
    return r;
}
/* localdecomp:end func_L01_00443F50 */

/* localdecomp:start func_L01_00443FB0 */
typedef struct Entry_00443FB0 {
    u8 pad[0x8A];
    u16 count;
    u8 tail[0x64];
} Entry_00443FB0;
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern u8 D_00142CA0[];
extern u8 D_L01_002C5600[];
s32 func_L01_00443FB0(s32 unused, s32 *out) {
    extern s32 func_L01_00443F50(s32 a0);
    extern s32 func_00382468(s32 limit);
    s32 i;
    s32 count;
    s32 improved;
    s32 result = 1;
    count = improved = 0;
    for (i = 0; i < 156; i++) {
        if (D_00142CA0[i] && ((Entry_00443FB0 *)(D_L01_002C5600 + D_001425C0[i] * 240))->count && func_L01_00443F50(i)) {
            if (D_001427F0[i] < ((Entry_00443FB0 *)(D_L01_002C5600 + D_001425C0[i] * 240))->count) improved++;
            count++;
        }
    }
    if (!count) return 0;
    if (improved) {
        s32 pick = func_00382468(improved);
        for (i = 0; i < 156; i++) {
            if (D_00142CA0[i] && ((Entry_00443FB0 *)(D_L01_002C5600 + D_001425C0[i] * 240))->count &&
                D_001427F0[i] < ((Entry_00443FB0 *)(D_L01_002C5600 + D_001425C0[i] * 240))->count && func_L01_00443F50(i)) {
                if (pick == 0) {
                    *out = i;
                    goto selected;
                }
                pick--;
            }
        }
    } else {
        s32 pick = func_00382468(count);
        s32 j;
        for (j = 0; j < 156; j++) {
            if (D_00142CA0[j] && ((Entry_00443FB0 *)(D_L01_002C5600 + D_001425C0[j] * 240))->count && func_L01_00443F50(j)) {
                if (pick == 0) {
                    *out = j;
                    goto selected;
                }
                pick--;
            }
        }
    }
selected:
    if (!func_00382468(5)) result = 2;
    return result;
}
/* localdecomp:end func_L01_00443FB0 */

/* localdecomp:start func_L01_00444200 */
extern s32 func_L01_0041A4F0(void);
extern void func_003E54E0(s32 a);
extern u8 D_00142660[];

void func_L01_00444200(void)
{
    u8 *q;

    if (func_L01_0041A4F0() != 0) {
        q = D_00142660;
        if (q[0x5A] + 1 < 0x14) {
            q[0x5B] = q[0x5B] + 1;
            if (((q[0x5B] & 0xFF) << 1) >= q[0x5A] + 1) {
                func_003E54E0(0x96);
                q[0x5B] = 0;
                q[0x5A] = q[0x5A] + 1;
            }
        }
    }
}
/* localdecomp:end func_L01_00444200 */

/* localdecomp:start func_L01_00444288 */
typedef struct { s16 classes[4]; u8 pad[16]; } Row_00444288;
extern Row_00444288 D_L01_001DA5A8[];
extern u16 D_001A1F18[][2];
void func_L01_00444288(u8 *obj,s32 mode) {
    s32 found=-1;
    s32 i,j;
    s32 kind=*(s16 *)(obj+0xaa);
    for(i=0;i<64;i++) {
        for(j=0;j<4;j++) {
            if(kind==D_L01_001DA5A8[i].classes[j]) {
                found=i;
                break;
            }
        }
        if(found!=-1) break;
    }
    if(found!=-1) {
        u16 *counter;
        if(mode==0) counter=&D_001A1F18[found][0];
        else if(mode==1) counter=&D_001A1F18[found][mode];
        else return;
        if(*counter<9999) ++*counter;
    }
}
/* localdecomp:end func_L01_00444288 */

/* localdecomp:start func_L01_00444350 */
__asm__(".extern D_L01_001D7BE0, 4");
extern s32 D_L01_001D7BE0;
extern s32 D_001A2018[];
extern s16 D_L01_002C4F60[];
extern s16 D_L01_002C4FE8[];

s32 func_L01_00444350(void) {
    s32 i = D_L01_001D7BE0;
    s32 n = D_001A2018[i] / D_L01_002C4F60[i];

    if (n >= 10) {
        n = 9;
    }
    return (1.0f - n * 0.1f) * D_L01_002C4FE8[i];
}
/* localdecomp:end func_L01_00444350 */

/* localdecomp:start func_L01_004443E8 */
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
} M_004443E8;
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
} H_004443E8;
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x34 - 0xC];
    s32 w34;
    s32 w38;
    s32 w3C;
} S_004443E8;
typedef struct {
    u8 pad0[0x7B];
    u8 b7B;
    u8 pad7C[0xE4 - 0x7C];
    u8 bE4;
} T_004443E8;
typedef struct {
    u8 pad0[0x17];
    u8 b17;
} R_004443E8;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[0xF0 - 2];
} Rec_004443E8;

extern H_004443E8 D_001A4BE0;
extern u8 D_001426BA[];
extern T_004443E8 D_001426E0;
extern u8 D_001BBE90[];
extern u8 D_001BBC40[];
extern s32 D_00142DE0[];
extern s32 D_001D545C;
extern u8 D_L01_001D60C8[] __attribute__((section(".sdata")));
extern u8 D_L01_001D60D0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D60D8[] __attribute__((section(".sdata")));
extern u8 D_L01_001D60E0[] __attribute__((section(".sdata")));
extern s16 D_L01_001D60E8;
extern s16 D_L01_001D60EA;
extern f32 D_L01_001DAA34;
__asm__(".extern D_L01_001D7BE0, 4");
extern s32 D_L01_001DFF40;
extern u8 D_L01_001DFE80[] __attribute__((section(".sdata")));
extern M_004443E8 *D_L01_001E0200[2];
extern s32 D_L01_0021FF38[][0x9C];
typedef struct {
    u8 p0[0x464];
    u8 x464[1];
} K_004443E8;
extern K_004443E8 D_L01_00236B90;
extern K_004443E8 D_L01_00237800;
extern f32 D_L01_002F1600[];

extern s32 func_003C4B50(M_004443E8 *);
extern R_004443E8 *func_00382348(M_004443E8 *);
extern void func_003E4D10(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_0044D360(M_004443E8 *, s32, s32, s32, f32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00415D40(s32, s32, s32, s32);
extern void func_L01_00415C98(s32, s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);

/* from rac2-decomp's func_002A6C58 */
void func_L01_004443E8(M_004443E8 *moby, s32 hit, s32 killer) {
    S_004443E8 *bank_p;
    s32 mult;
    u16 b6;
    s32 f400;
    s32 f100;
    s32 f1000;
    s32 hero;
    s32 bolts;
    s32 bank;
    s32 bank_cut;
    s32 flags;
    f32 xp;
    f32 hero_mult;
    s32 i;
    R_004443E8 *rec;

    if (moby->id < 0) {
        return;
    }
    if (moby->flags & 0x80) {
        return;
    }
    moby->hits++;
    mult = 1;
    if (moby->cls != 0 && moby->cls[0x46] == 5) {
        mult = (D_001426BA[0] + 1) << D_001A4BE0.xp_shift;
        func_L01_00444288((u8 *)moby, 0);
        func_L01_00444200();
    } else if (func_003C4B50(moby) != 0) {
        mult = (D_001426BA[0] + 1) << D_001A4BE0.xp_shift;
    }
    b6 = moby->b6;
    f100 = hit & 0x100;
    hero_mult = mult;
    hero = 1;
    f1000 = hit & 0x1000;
    f400 = hit & 0x400;
    while (hero >= 0 && moby != D_L01_001E0200[hero]) {
        hero--;
    }
    if (b6 != 0 || D_L01_001D7BE0 != -1) {
        if (D_001A4BE0.mode != 1 && D_001A4BE0.mode != 2) {
            bank = (((S_004443E8 *)D_00142660)->w38 + 0x31) / 0x32;
            if (D_L01_001D7BE0 != -1 && hero < 0 && func_003C4B50(moby) == 0) {
                bolts = func_L01_00444350();
            } else {
                s32 b = D_001BBE90[(moby->id >> 1) + (D_001D545C << 10)];
                if ((moby->id & 1) ? (b >> 4) & 8 : b & 8) {
                    bolts = func_L01_004006C8(D_L01_001D60E0, moby->b6, moby->id);
                } else {
                    bolts = func_L01_004006C8(D_L01_001D60D8, moby->b6, moby->id);
                }
            }
            bolts <<= D_001A4BE0.xp_shift;
            if (func_L01_0041A4F0() != 0) {
                f32 fb = bolts;
                s32 v;
                if (D_001D545C != 7 || D_001426E0.b7B == 0) {
                    v = fb * D_L01_002F1600[D_001D545C];
                } else {
                    v = fb * D_L01_001DAA34;
                }
                bolts = v;
            }
            rec = func_00382348(moby);
            if (rec != 0 && rec->b17 != 0xFF &&
                (func_L01_0041A4F0() != 0 || ((Rec_004443E8 *)D_L01_002C5600)[D_001425C0[rec->b17]].b1 != 4)) {
                if (hero >= 0) {
                    s32 sum = 0;
                    for (i = 0; i < 0x9C; i++) {
                        sum += D_L01_0021FF38[hero][i];
                    }
                    if (sum != 0) {
                        f32 share = (f32)(bolts + bank) * (1.0f / (f32)sum);
                        s32 j;
                        for (j = 0; j < 0x9C; j++) {
                            f32 v = share * (f32)D_L01_0021FF38[hero][j];
                            if (v > 2147483648.0f) {
                                v = 2147483648.0f;
                            }
                            D_00142DE0[j] += (s32)v;
                        }
                    }
                    D_L01_001E0200[hero] = 0;
                } else {
                    D_00142DE0[rec->b17] += bolts + bank;
                }
            }
            bank_p = (S_004443E8 *)D_00142660;
            bank_p->w38 -= bank;
            if (func_L01_0041A4F0() != 0 || bank_p->w8 < 100) {
                bank_p->w34 += bolts + bank;
            }
            func_003E4D10(0x258);
        }
    }
    bank_cut = 0;
    if (f1000 == 0) {
        bank_cut = (((S_004443E8 *)D_00142660)->w3C + 0x31) / 0x32;
        ((S_004443E8 *)D_00142660)->w3C -= bank_cut;
    }
    if (D_L01_001D7BE0 != -1) {
        xp = func_00382498(D_L01_001D60E8, D_L01_001D60EA);
        if (hero >= 0) {
            xp *= 10.0f;
        }
    } else {
        s32 b = D_001BBE90[(moby->id >> 1) + (D_001D545C << 10)];
        if ((moby->id & 1) ? (b >> 4) & 8 : b & 8) {
            xp = func_L01_004006C8(D_L01_001D60D0, moby->b4, moby->id);
        } else {
            xp = func_L01_004006C8(D_L01_001D60C8, moby->b4, moby->id);
        }
    }
    if (moby->id >= 0 && !(moby->flags & 0x80)) {
        s32 kind;
        if (D_L01_001D7BE0 != -1 && func_003C4B50(moby) == 0) {
            D_001A2018[D_L01_001D7BE0]++;
        }
        if (moby->id & 1) {
            u8 *p = &D_001BBE90[(moby->id >> 1) + (D_001D545C << 10)];
            if (((*p >> 4) & 7) != 7) {
                *p += 0x10;
            }
        } else {
            u8 *p = &D_001BBE90[(moby->id >> 1) + (D_001D545C << 10)];
            if ((*p & 7) != 7) {
                *p += 1;
            }
        }
        D_L01_00236B90.x464[moby->id] = moby->kind + 2;
        kind = moby->kind;
        if (kind == 0xFF || (!(D_L01_001DFE80[(u8)kind] & 0x80) && (D_001BBC40[(u8)kind + D_001D545C * 16] & 0x80))) {
            D_L01_00237800.x464[moby->id] = kind + 2;
        }
    }
    xp *= hero_mult;
    xp += bank_cut;
    flags = 1;
    if (f100) {
        flags = 5;
    }
    if (D_001A4BE0.b25F3 != 0 || (hit & 0x200)) {
        flags |= 2;
    }
    if (D_001A4BE0.state == 0x10 && func_0038CF00(D_001A4BE0.pos, moby->pos) < 4.0f) {
        flags |= 2;
    }
    if (f400) {
        flags |= 0x10;
    }
    flags |= 8;
    if (D_L01_001DFF40 < 100) {
        flags |= 2;
    }
    if (xp < 0.0f) {
        xp = 0.0f;
    }
    if (xp > 0.0f) {
        s32 spread = 0;
        if (xp >= 8.0f) {
            spread = xp * 0.25f;
        } else if (xp >= 2.0f) {
            spread = 1;
        }
        func_L01_0044D360(moby, (s32)xp - spread, (s32)xp + spread, flags, 0.0f, -1, killer);
    }
    if (D_001426E0.bE4 == 0 && func_L01_0041A4F0() != 0) {
        s32 a = func_00381FF0(0x8DE);
        func_L01_00415D40(a, 0, func_00381FF0(0x827), 1);
        func_L01_00415C98(0x40, 0);
        func_003A0EC0(4, 1, 10, 0, 0);
        D_001426E0.bE4 = 1;
    }
}
/* localdecomp:end func_L01_004443E8 */
