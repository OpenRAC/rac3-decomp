/* functional: medium. 356 diff, frame size equal; transcribed from asm incl. shifts, default-table scan and packet slot order (differs from 00427220); no gate coverage */
typedef int s128 __attribute__((mode(TI)));
#include "vu0.h"
typedef struct { u8 p0[4]; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; s16 fE; } TexEnt_004275F8;
extern s32 D_L01_001E0DC0;
extern u8 D_L01_002385F0[];
extern u16 D_L01_00238570[];
extern u8 *D_L01_00238470[];
extern s32 D_L01_00239DF0[];
extern u8 D_L01_0023A3F0[];
extern u8 D_L01_001F3DC0[];
extern s32 D_001A1ED0[];

/* register an instance of a loaded model (second kind): bump the instance counter and fill the
   lookup tables, relocate its pointers, optionally patch the first packet group from the
   tint table ti, then build the GS tex-register packets (4 quads each, stride 0x40) for every
   part from the texture table tex or the default table D_L01_001F3DC0 */
void func_L01_004275F8(u8 *o, TexEnt_004275F8 *tex, void *src, s16 *ti, s32 id) {
    s32 n;
    s32 i;
    s32 j;
    s32 cnt;
    s32 w;
    s32 buf[4];
    u8 *e;
    u8 *sub;
    u8 *pkt;
    u8 *g;

    n = D_L01_001E0DC0;
    D_L01_002385F0[id] = (u8)n;
    D_L01_00238570[n] = (u16)id;
    D_L01_00238470[n] = o;
    D_L01_00239DF0[n] = (s32)(*(f32 *)(o + 0x10) * 1024.0f);
    *(u16 *)(o + 0x26) = (u16)n;
    D_L01_001E0DC0 = n + 1;
    *(s32 *)(o + 0x18) = 0;
    *(s16 *)(o + 0x16) = 0;
    if (*(s32 *)(o + 0x2C) != 0) {
        *(s32 *)(o + 0x2C) = *(s32 *)(o + 0x2C) + (s32)o;
    }
    if (*(s16 *)(o + 0x28) > 0) {
        i = 0;
        g = o + 0x40;
        do {
            i++;
            *(s32 *)g = *(s32 *)g + (s32)o;
            g += 8;
        } while (i < *(s16 *)(o + 0x28));
    }
    w = *(s32 *)(o + 0x1C);
    if (w != 0) {
        pkt = (u8 *)(w + (s32)o);
        *(s32 *)(o + 0x1C) = (s32)pkt;
        if (ti != 0) {
            long a, b, c, d;
            s32 base;
            for (i = 0; i < 4; i++) {
                s32 v = ti[0] >> (i + 6);
                buf[i] = v;
                if (v <= 0) {
                    buf[i] = 1;
                }
            }
            b = ((long)(ti[2] - 1) << 2) | ((long)*(s32 *)(pkt + 0x14) << 6) | 0x20;
            b |= (long)*(s32 *)(pkt + 0x10) << 32;
            base = D_001A1ED0[8] >> 8;
            *(long *)(pkt + 0x10) = b;
            a = ((long)(30 - plzcw_asm(ti[0])) << 26) | 0x1300000;
            a |= ((long)(ti[4] + base)) | ((long)buf[0] << 14);
            a |= (long)(30 - plzcw_asm(ti[1])) << 30;
            a |= ((long)(ti[3] + base) << 37) | 0x400000000L;
            a |= 0x8000000000000000L;
            *(long *)(pkt + 0x20) = a;
            c = (long)(ti[5] + base) | ((long)buf[1] << 14);
            c |= (long)(ti[6] + base) << 20;
            c |= (long)buf[2] << 34;
            c |= (long)(ti[7] + base) << 40;
            c |= (long)buf[3] << 54;
            *(long *)(pkt + 0x30) = c;
        } else {
            u8 *t = D_L01_001F3DC0;
            long b;
            i = 0;
            if (*(long *)(t + 0x18) != 0) {
                u8 *p = t + 0x18;
                long v;
                do {
                    p += 0x18;
                    v = *(long *)p;
                    i++;
                } while (v != 0);
            }
            t = D_L01_001F3DC0 + i * 0x18;
            b = (*(long *)(t + 8) & 0x1C) | ((long)*(s32 *)(pkt + 0x14) << 6) | 0x20 | ((long)*(s32 *)(pkt + 0x10) << 32);
            *(long *)(pkt + 0x20) = *(long *)t;
            *(long *)(pkt + 0x30) = *(long *)(t + 0x10);
            *(long *)(pkt + 0x10) = b;
        }
    }

    e = D_L01_0023A3F0 + ((s32)D_L01_002385F0[id] << 4);
    *(s128 *)e = *(s128 *)src;
    if (*(s16 *)(o + 0x28) > 0) {
        i = 0;
        do {
            s32 cur = i;
            i++;
            sub = *(u8 **)(o + 0x40 + cur * 8);
            g = sub + 0x10;
            pkt = g + (*(s32 *)(g + 4) << 4) + 0x10;
            j = 0;
            if (*(s32 *)(sub + 0x10) > 0) {
                do {
                    s32 w0 = *(s32 *)(pkt + 0x00);
                    s32 w4 = *(s32 *)(pkt + 0x04);
                    s32 w10 = *(s32 *)(pkt + 0x10);
                    s32 w14 = *(s32 *)(pkt + 0x14);
                    s32 t = e[*(s32 *)(pkt + 0x20)];
                    long a, b, c, d;

                    if (tex != 0) {
                        TexEnt_004275F8 *te = &tex[t];
                        s32 base = D_001A1ED0[8] >> 8;
                        s32 x = te->f4;
                        s32 ta = x >> 6;
                        s32 tb = x >> 7;
                        if (ta <= 0) ta = 1;
                        if (tb <= 0) tb = 1;
                        a = ((long)(30 - plzcw_asm(x)) << 26) | 0x1300000;
                        a |= (long)ta << 14;
                        a |= (long)(30 - plzcw_asm(te->f6)) << 30;
                        a |= ((long)(te->fA + base) << 37) | 0x400000000L;
                        a |= 0x8000000000000000L;
                        b = ((long)(te->f8 - 1) << 2) | ((long)w4 << 6) | 0x20;
                        b |= (long)w0 << 32;
                        d = (long)w10 | ((long)w14 << 2) | ((long)t << 24);
                        c = ((long)tb << 14) | ((long)(te->fC + base) << 20);
                        c |= ((long)(te->fE + base) << 40) | 0x400000000L;
                        c |= 0x40000000000000L;
                        *(long *)(pkt + 0x00) = b;
                        *(long *)(pkt + 0x10) = d;
                        *(long *)(pkt + 0x20) = c;
                        *(long *)(pkt + 0x30) = a;
                    } else {
                        u8 *dt = D_L01_001F3DC0 + t * 0x18;
                        b = (*(long *)(dt + 8) & 0x1C) | ((long)w4 << 6) | 0x20 | ((long)w0 << 32);
                        d = (long)w10 | ((long)w14 << 2) | ((long)t << 24);
                        *(long *)(pkt + 0x00) = b;
                        *(long *)(pkt + 0x10) = d;
                        *(long *)(pkt + 0x20) = *(long *)(dt + 0x10);
                        *(long *)(pkt + 0x30) = *(long *)dt;
                    }
                    j++;
                    pkt += 0x40;
                } while (j < *(s32 *)g);
            }
        } while (i < *(s16 *)(o + 0x28));
    }
}
