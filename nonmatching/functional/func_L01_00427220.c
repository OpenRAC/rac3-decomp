/* functional: medium. not byte close (245 diff, register allocation); transcribed from asm incl. all shifts/psm constants; data globals declared without gp .extern so gp-vs-lui differs; no gate coverage */
typedef int s128 __attribute__((mode(TI)));
typedef struct { u8 p0[4]; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; s16 fE; } TexEnt_00427220;
extern s32 D_L01_001E0ED0;
extern u8 D_L01_0023C800[];
extern u16 D_L01_0023C700[];
extern u8 *D_L01_0023C500[];
extern s32 D_L01_00243800[];
extern u8 D_L01_00243C00[];
extern u8 D_L01_001F3DC0[];
extern s32 D_001A1ED0[];
#include "vu0.h"

/* register an instance of a loaded model chunk: relocate its internal pointers, then build the
   GS texture-register packets (4 quadwords per part) from the texture table a1 (or the default
   table D_L01_001F3DC0 when a1 is null) */
void func_L01_00427220(u8 *o, TexEnt_00427220 *tex, void *src, s32 id) {
    s32 n;
    s32 i;
    s32 j;
    u8 *q;
    u8 *slot;
    u8 *e;
    u8 *pkt;

    n = D_L01_001E0ED0;
    D_L01_0023C800[id] = (u8)n;
    D_L01_0023C700[n] = (u16)id;
    D_L01_0023C500[n] = o;
    D_L01_00243800[n] = (s32)(*(f32 *)(o + 0x48) * 1024.0f);
    *(u16 *)(o + 0x46) = (u16)n;
    D_L01_001E0ED0 = n + 1;
    *(s32 *)(o + 0x20) = -1;
    *(s16 *)(o + 0x3E) = 0;

    for (i = 0; i < 3; i++) {
        slot = o + i * 4;
        if (*(s32 *)slot != 0) {
            *(s32 *)slot = *(s32 *)slot + (s32)o;
            if (o[0xC + i] != 0) {
                j = 0;
                q = *(u8 **)slot;
                do {
                    s32 *w = (s32 *)(q + (j << 4));
                    j++;
                    *w = *w + (s32)q;
                    q = *(u8 **)slot;
                } while (j < o[0xC + i]);
            }
        }
    }
    if (o[0xD] == 0) {
        *(u32 *)(o + 0x14) = 0x45FFF000;
    }
    if (o[0xE] == 0) {
        *(u32 *)(o + 0x18) = 0x46000000;
    }
    *(s32 *)(o + 0x30) = 0;
    *(s32 *)(o + 0x34) = *(s32 *)(o + 0x34) + (s32)o;
    *(s32 *)(o + 0x1C) = *(s32 *)(o + 0x1C) + (s32)o;

    e = D_L01_00243C00 + ((s32)D_L01_0023C800[id] << 4);
    *(s128 *)e = *(s128 *)src;
    pkt = *(u8 **)(o + 0x1C);
    for (j = 0; j < o[0xF]; j++, pkt += 0x50) {
        s32 t = e[j];
        s32 w10 = *(s32 *)(pkt + 0x10);
        s32 w14 = *(s32 *)(pkt + 0x14);
        s32 w30 = *(s32 *)(pkt + 0x30);
        s32 w34 = *(s32 *)(pkt + 0x34);
        long a, b, c, d;

        if (tex != 0) {
            TexEnt_00427220 *te = &tex[t];
            s32 base = D_001A1ED0[8] >> 8;
            s32 x = te->f4;
            s32 ta = x >> 6;
            s32 tb = x >> 7;
            s32 lz1 = 30 - plzcw_asm(x);
            s32 lz2 = 30 - plzcw_asm(te->f6);
            if (ta <= 0) ta = 1;
            if (tb <= 0) tb = 1;
            a = ((long)lz1 << 26) | 0x1300000;
            a |= (long)ta << 14;
            a |= (long)lz2 << 30;
            a |= (long)(te->fA + base) << 37;
            a |= 0x400000000L;
            a |= 0x8000000000000000L;
            b = ((long)(te->f8 - 1) << 2) | ((long)w14 << 6) | 0x20;
            b |= (long)w10 << 32;
            c = ((long)tb << 14) | ((long)(te->fC + base) << 20);
            c |= (long)(te->fE + base) << 40;
            c |= 0x400000000L;
            c |= 0x40000000000000L;
            d = (long)w30 | ((long)w34 << 2);
            d |= (long)t << 24;
        } else {
            u8 *dt = D_L01_001F3DC0 + t * 0x18;
            a = *(long *)dt;
            b = (*(long *)(dt + 8) & 0x1C) | ((long)w14 << 6) | 0x20 | ((long)w10 << 32);
            c = *(long *)(dt + 0x10);
            d = (long)w30 | ((long)w34 << 2) | ((long)t << 24);
        }
        *(long *)(pkt + 0x00) = a;
        *(long *)(pkt + 0x10) = b;
        *(long *)(pkt + 0x20) = c;
        *(long *)(pkt + 0x30) = d;
    }
}
