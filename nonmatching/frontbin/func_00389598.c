/* US draft of func_00389598 (rac3-uya-decomp func_00384EC0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00389598 */
typedef struct { unsigned long v; u16 h8; u16 hA; u8 bC; u8 bD; s16 hE; } T_384EC0;
typedef struct { s32 w0; s16 h4; s16 h6; s32 w8; u8 bC; u8 bD; s16 hE; } C_384EC0;
extern T_384EC0 D_00226000[];
extern C_384EC0 D_00225C00[];
extern s32 D_001A1ED0[];
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern s32 D_001D9C04;
__asm__(".extern D_001D58E0, 8");
__asm__(".extern D_001D58E8, 8");
__asm__(".extern D_001D58F0, 4");
extern unsigned long D_001D58E0;
extern unsigned long D_001D58E8;
extern s32 D_001D58F0;
/* the packet pointer, reloaded after every store */
extern u32 *D_001DA050_00389598[1];
extern u8 D_141AD0[];
extern u8 D_141DC0[];
long func_00389598(s32 i) {
    if (i < 0) {
        if (i == -5) {
            return ((unsigned long)(D_001A1ED0[2] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0x30) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -8) {
            return ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0x1B) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(D_001D58F0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(1) << 61));
        } else if (i == -7) {
            return ((unsigned long)(D_001A1ED0[0] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -6) {
            return ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -2 || i == -1) {
            s32 a;
            unsigned long t;
            if (D_001D58E0 != 0) return D_001D58E0;
            a = (D_001D4BB0 + 0x1FFF) & ~0x1FFF;
            D_001D4BB0 = a + 0x20000;
            D_001DA050_00389598[0][0] = 0x10000003;
            D_001DA050_00389598[0][1] = 0;
            D_001DA050_00389598[0][2] = 0;
            D_001DA050_00389598[0][3] = 0x50000003;
            D_001DA050_00389598[0][4] = 0x8001;
            D_001DA050_00389598[0][5] = 0x20000000;
            D_001DA050_00389598[0][6] = 0xEE;
            D_001DA050_00389598[0][7] = 0;
            *(unsigned long *)&D_001DA050_00389598[0][8] = (long)(a >> 13) | 0x2040000;
            D_001DA050_00389598[0][10] = 0x4D;
            D_001DA050_00389598[0][11] = 0;
            *(unsigned long *)&D_001DA050_00389598[0][12] = ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001DA050_00389598[0][14] = 7;
            D_001DA050_00389598[0][15] = 0;
            D_001DA050_00389598[0][16] = 0x3000002F;
            D_001DA050_00389598[0][17] = (u32)D_141AD0;
            D_001DA050_00389598[0][18] = 0;
            D_001DA050_00389598[0][19] = 0x5000002F;
            t = ((unsigned long)(a >> 8) | ((unsigned long)(4) << 14) | ((unsigned long)(2) << 20) | ((unsigned long)(8) << 26) |
                ((unsigned long)(8) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001D58E0 = t;
            D_001DA050_00389598[0] += 0x14;
            return t;
        } else if (i == -4 || i == -3) {
            s32 a;
            unsigned long t;
            if (D_001D58E8 != 0) return D_001D58E8;
            a = (D_001D4BB0 + 0x1FFF) & ~0x1FFF;
            D_001D4BB0 = a + 0x2000;
            D_001DA050_00389598[0][0] = 0x10000003;
            D_001DA050_00389598[0][1] = 0;
            D_001DA050_00389598[0][2] = 0;
            D_001DA050_00389598[0][3] = 0x50000003;
            D_001DA050_00389598[0][4] = 0x8002;
            D_001DA050_00389598[0][5] = 0x10000000;
            D_001DA050_00389598[0][6] = 0xEE;
            D_001DA050_00389598[0][7] = 0;
            *(unsigned long *)&D_001DA050_00389598[0][8] = (long)(a >> 13) | 0x2010000;
            D_001DA050_00389598[0][10] = 0x4D;
            D_001DA050_00389598[0][11] = 0;
            *(unsigned long *)&D_001DA050_00389598[0][12] = ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001DA050_00389598[0][14] = 7;
            D_001DA050_00389598[0][15] = 0;
            D_001DA050_00389598[0][16] = 0x3000002F;
            D_001DA050_00389598[0][17] = (u32)D_141DC0;
            D_001DA050_00389598[0][18] = 0;
            D_001DA050_00389598[0][19] = 0x5000002F;
            t = ((unsigned long)(a >> 8) | ((unsigned long)(1) << 14) | ((unsigned long)(2) << 20) | ((unsigned long)(6) << 26) |
                ((unsigned long)(6) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001D58E8 = t;
            D_001DA050_00389598[0] += 0x14;
            return t;
        }
    } else {
        T_384EC0 *e = &D_00226000[i];
        if (e->v == 0) {
            s32 base = D_001D4BB0;
            s32 w;
            s32 b0, b1, n;
            unsigned long t;
            w = e->bC;
            w -= 6;
            if (w < 0) w = 0;
            b0 = base >> 8;
            base += 0x400;
            b1 = base >> 8;
            t = ((unsigned long)(b1) | ((unsigned long)(1 << w) << 14) | ((unsigned long)(e->hE) << 20) | ((unsigned long)(e->bC) << 26) |
                ((unsigned long)(e->bD) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(b0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(4) << 61));
            D_001D4BB0 = base + (1 << (e->bC + e->bD));
            e->v = t;
            if (0x3FF000 - D_001D934C < D_001D4BB0) return t;
            n = D_001D9BFC;
            if (n < 0x40) {
                C_384EC0 *c = &D_00225C00[n];
                c->w0 = D_001D9C04 + (e->hA << 6);
                c->h4 = 0;
                c->h6 = b0;
                D_00225C00[n].w8 = D_001D9C04 + (e->h8 << 6);
                c->bC = e->bC;
                c->bD = e->bD;
                c->hE = b1;
                D_001D9BFC = n + 1;
            }
        }
    }
    return D_00226000[i].v;
}
/* localdecomp:end func_00389598 */
