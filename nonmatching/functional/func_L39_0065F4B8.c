/* functional: medium. Per-frame update of one multiplayer-menu player (self): snaps a teleported position back, runs the player's vtable tick and the fixed chain of per-frame subsystems, decides from the protected command byte (g+0x19E4/0x19E6) which of them run, builds and sends the 64-bit input packet (func_L39_0066EE90 buffer, func_0014AD08), refreshes the 16 button-state bits from the keyed 16-bit table at g+0x1A40.., steps the slot state at g+0x254C and saves the position. Control flow, call order and memory accesses follow retail; the keyed-table decodes are the two helpers below (retail inlines them). Medium: long function transcribed by hand, no coverage evidence for the packet bit layout (bits 56-63 and the three s16 positions) or the unscramble helper variants. */
#include "vu0.h"

extern u8 D_001A5CD0[];
extern s32 D_L39_00352944;
extern u8 D_L39_004840A0[];
extern u8 D_L39_002FB000[];
extern s32 D_L39_0024112C;
extern s32 D_L39_002461DC;
extern s32 *D_L39_00241120;
extern s32 D_L39_002405CC;
extern u8 D_L39_004997E0[];
extern u8 D_L39_00483A00[];
extern f32 func_L01_0040E548(void *, void *);
extern void func_L39_006613D0(void *);
extern void func_L39_00661488(void *);
extern void func_L39_00622450(void *);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L39_00622990(void *);
extern void func_L39_00622C28(void *);
extern void func_L39_006233A8(void *, void *, void *, void *);
extern void func_L39_006617C8(void *);
extern void func_L39_00629FE0(void *, s32);
extern void func_L39_00656F28(void *);
extern void func_L39_0063EE68(void *);
extern void func_L39_0063A230(void *);
extern void func_L39_006390D0(void *);
extern s32 func_L39_00639D90(void *);
extern void func_L39_006217C0(void *);
extern void func_L39_0063C468(void *);
extern void func_L39_0063C840(void *);
extern void func_L39_0063EE70(void *);
extern void func_L39_0063EC20(void *);
extern void func_L35_003A53C0(void *);
extern void func_L39_0063AE10(void *);
extern void func_L39_0062B838(void *, s32);
extern void func_L39_0063EE78(void *);
extern void func_L39_0063FC90(void *);
extern void func_L39_00621388(void *);
extern void func_L39_00621600(void *);
extern void func_L39_00631E90(void *);
extern void func_L39_0063A540(void *);
extern void func_L39_00644D08(void *);
extern void func_L01_004436F4(void *);
extern void func_L39_0063F0C0(void *);
extern void func_L39_0063F0C8(void *);
extern void func_L39_0063B0A8(void *);
extern s32 func_L39_005C42E8(s32, s32);
extern s32 func_L39_0066EE90(void *, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_005BA3A0(void *, void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_L39_00677348(s32, s32);
extern void func_L39_006772F8(s32, s32);
extern void func_L39_00661988(void *);
extern void func_L39_00674190(void *);

/* protected 32-bit value: 8 bytes keyed by the address of the key byte (step 5, stride 255) */
static u32 p5_dec(u8 *key) {
    u32 b[2];
    u32 c = key[0];
    u32 base;
    s32 k;
    if (c == 0) return 0;
    base = ((u32)key - c) & 7;
    for (k = 0; k < 8; k++) {
        ((u8 *)b)[k] = D_L39_004997E0[c + 1 + ((base + k * 5) & 7) * 255];
    }
    b[0] ^= (u32)key;
    b[1] ^= b[0];
    return b[1];
}

/* protected 16-bit value: 8 bytes, step 3, stride `stride` of table `tbl`, then the xor/divide unmask */
static u32 p16_dec(u8 *key, u8 *tbl, s32 stride) {
    u32 b[2];
    u32 c = key[0];
    u32 base, v, hi;
    s32 k;
    if (c == 0) return 0;
    base = ((u32)key - c) & 7;
    for (k = 0; k < 8; k++) {
        ((u8 *)b)[k] = tbl[c + 1 + ((base + k * 3) & 7) * stride];
    }
    b[0] ^= (u32)key;
    v = b[1] ^ b[0];
    hi = v >> 16;
    b[1] = hi / (((v ^ hi) << 16) + 1);
    return b[1] & 0xFFFF;
}

void func_L39_0065F4B8(u8 *g) {
    f32 pos[4];
    unsigned long pktbuf[0x15];  /* retail sp+0x20..: 16-byte block, 8-byte header (pk), payload from +0x18 */
    u8 *pkt = (u8 *)pktbuf;
    u8 tmp[4];
    unsigned long pk;
    u8 *p;
    u8 *o;
    s32 idx;
    s32 ctr;
    s32 r17;
    s32 r10;
    s32 i;
    s32 k;
    s32 cnt8;
    s32 st;
    u32 w;
    u32 res;
    u8 flag17;
    u8 flag9;
    f32 d;
    f32 f2;
    f32 f2a;
    f32 f3;
    f32 f4;
    s32 count;
    s32 v;

    pos[0] = *(f32 *)(g + 0x2538);
    pos[1] = *(f32 *)(g + 0x253C);
    pos[2] = *(f32 *)(g + 0x2540);
    d = func_L01_0040E548(pos, g + 0xA0);
    if (100.0f < d) *(vu0_q *)(g + 0xA0) = *(vu0_q *)pos;
    func_L39_006613D0(g);
    func_L39_00661488(g);
    *(s16 *)(g + 0x19E2) = 0;
    *(s16 *)(g + 0x19E0) = 0;
    func_L39_00622450(g);

    if (*(s32 *)(D_001A5CD0 + 0x170) == 0 && *(s32 *)(D_001A5CD0 + 0x12C) >= 2) {
        s32 t = *(s32 *)(D_001A5CD0 + 0x128);
        if (*(s32 *)(D_001A5CD0 + 0x7D0) < t - 0xBB8 && D_L39_00352944 > 0 && D_L39_00352944 + 0x61A8 < t) {
            *(s32 *)(*(u8 **)(g + 0x2534) + 0x1CC) = 1;
            *(s16 *)(g + 0x320) = 2;
            *(s32 *)(D_L39_004840A0 + *(s32 *)(g + 0x2544) * 0x1C) = 5;
            *(s32 *)(D_L39_004840A0 + *(s32 *)(g + 0x2544) * 0x1C + 8) = 2;
            func_L01_00451F60(0x18D2, 2, 0);
        }
    }
    (*(void (**)(void *))(*(u8 **)(g + 0x14) + 0x28))(g);
    func_L39_00622990(g);
    func_L39_00622C28(g);
    func_L39_006233A8(g, g + 0xA0, g + 0xB0, g + 0x1540);
    func_L39_006617C8(g);

    f2 = 2.5f;
    if (*(s16 *)(g + 0x370) == -1) f2 = 10.0f;
    flag17 = 0;
    if (*(f32 *)(g + 0x2A8) == 0.0f || f2 < *(f32 *)(g + 0x2AC)) flag17 = 1;

    if ((p5_dec(g + 0x19E6) ^ 0x14) != 0 && (p5_dec(g + 0x19E4) ^ 0x83) != 0) {
        if (*(s32 *)(g + 0x478) == 0xB || flag17 != 0) {
            func_L39_00629FE0(g, flag17);
            if (*(s32 *)(g + 0x478) != 0xB && flag17 != 0) {
                if (g[0x1A0E] != 0) {
                    if (*(s32 *)(g + 0x251C) == 0) goto L5800;
                }
                if (g[0x1A0B] == 0 && g[0x15EE] != 0) g[0x1A13] = 1;
            }
        }
    }
L5800:
    func_L39_00656F28(g);
    func_L39_0063EE68(g);
    func_L39_0063A230(g);
    func_L39_006390D0(g);
    if (g[0x1A08] == 0 && func_L39_00639D90(g) == 0
        && (p5_dec(g + 0x19E4) ^ 1) != 0 && (p5_dec(g + 0x19E4) ^ 0x1D) != 0
        && *(s32 *)(g + 0x2544) != (D_L39_0024112C & 7)) {
        /* skip func_L39_006217C0 */
    } else {
        func_L39_006217C0(g);
    }
    func_L39_0063C468(g);
    func_L39_0063C840(g);
    func_L39_0063EE70(g);
    func_L39_0063EC20(g);
    func_L35_003A53C0(g);
    func_L39_0063AE10(g);
    func_L39_0062B838(g, 0);
    func_L39_0063EE78(g);
    func_L39_0063FC90(g);
    r10 = func_L39_00639D90(g);

    if (g[0x1A0A] != 0) goto L5C30;
    if (r10 == 2 && (p5_dec(g + 0x19E6) ^ 0x14) != 0) goto L5C30;
    if (r10 == 1) {
        flag9 = 0;
        if ((p5_dec(g + 0x19E4) ^ 1) == 0) {
            flag9 = 1;
        } else if ((p5_dec(g + 0x19E4) ^ 0x1D) == 0) {
            flag9 = 1;
        } else if (g[0x24FE] != 0) {
            flag9 = 1;
        } else if (g[0x2500] != 0) {
            flag9 = 1;
        }
        if (flag9) goto L5C30;
    }
    if (g[0x314] == 0) {
        res = 0;
    } else {
        res = p16_dec(g + 0x314, D_L39_004997E0, 255);
    }
    if ((res & 0xFFFF) == 0) {
        func_L39_00621600(g);
        goto L5C48;
    }
L5C30:
    func_L39_00621388(g);
L5C48:
    func_L39_00631E90(g);
    func_L39_0063A540(g);
    func_L39_00644D08(g);
    func_L01_004436F4(*(void **)(g + 0x2524));
    func_L39_0063F0C0(g);
    func_L39_0063F0C8(g);
    if (func_L39_00639D90(g) != 0) {
        st = *(s32 *)(g + 0x2450);
        if (st != 4 && st != 0x51) {
            *(s32 *)(g + 0x2450) = 0x20;
            goto L5CB4;
        }
    } else {
        st = *(s32 *)(g + 0x2450);
    }
    if (st == 0x20) *(s32 *)(g + 0x2450) = 0;
L5CB4:
    func_L39_0063B0A8(g);

    if (*(s32 *)(g + 0x2544) == 0) {
        if (g[0x44EC] < 5) {
            s32 r = func_L39_005C42E8(0x40, 0);
            if ((*(s32 *)(*(u8 **)(g + 0x2534) + 0x1A0) & r) != 0 && g[0x44EC] == 0) goto L6194;
            g[0x44EC] = g[0x44EC] + 1;
            goto L6190;
        }
    }
    ctr = D_L39_002461DC;
    D_L39_002461DC = ctr + 1;
    if (!(ctr < 0x259)) D_L39_002461DC = 0;
    r17 = func_L39_0066EE90(g + 0x430C, pkt + 0x18);
    if (r17 == 0) {
        g[0x44EE] = g[0x44EE] + 1;
        goto L6190;
    }
    pk = *(unsigned long *)(pkt + 0x10);
    pk = (pk & 0xFDFFFFFFFFFFFFFFUL) | ((unsigned long)(g[0x24C9] & 1) << 57);
    pk &= 0xF3FFFFFFFFFFFFFFUL;
    *(unsigned long *)(pkt + 0x10) = pk;
    flag9 = 0;
    if ((p5_dec(g + 0x19E4) ^ 0x31) == 0) {
        if (*(u8 **)(g + 0x2530) != 0 && (*(u8 **)(g + 0x2530))[0x27B] != 0) {
            if ((p5_dec(g + 0x19E4) ^ 0x31) == 0) flag9 = 1;
        }
        if (!flag9) {
            pk = *(unsigned long *)(pkt + 0x10);
            pk = (pk & 0xF3FFFFFFFFFFFFFFUL) | (1UL << 58);
            *(unsigned long *)(pkt + 0x10) = pk;
            func_0038CC88(pkt, g + 0x431C, 8);
            goto L5F94;
        }
    }
    for (i = 0; i < 4; i++) {
        s32 x = *(s32 *)(g + 0x2398) - 4 + i + 8;
        s32 rem = x % 8;
        if (*(s32 *)(g + 0x239C) - 1 < rem) rem = 0;
        ((s32 *)pkt)[i] = *(s32 *)(g + 0x2378 + rem * 4);
    }
L5F94:
    f2a = *(f32 *)(g + 0xA0) * 64.0f + 0.5f;
    f3 = *(f32 *)(g + 0xA4) * 64.0f + 0.5f;
    f4 = *(f32 *)(g + 0xA8) * 64.0f + 0.5f;
    g[0x44EF] = g[0x44EF] - 1;
    cnt8 = g[0x44EF];
    *(s16 *)(pkt + 0x10) = (s16)(s32)f2a;
    *(s16 *)(pkt + 0x12) = (s16)(s32)f3;
    *(s16 *)(pkt + 0x14) = (s16)(s32)f4;
    pk = *(unsigned long *)(pkt + 0x10);
    if (cnt8 != 0) {
        pk &= 0xFEFFFFFFFFFFFFFFUL;
    } else {
        g[0x44EF] = 5;
        func_L39_005BA3A0(g + 0xB0, tmp);
        func_0038CC88(pkt + 0x18 + r17, tmp, 4);
        r17 += 4;
        pkt[0x18 + r17] = (u8)p5_dec(g + 0x19E4);
        r17 += 1;
        func_0038CC88(pkt + 0x18 + r17, g + 0xA0, 0xC);
        r17 += 0xC;
        pk = *(unsigned long *)(pkt + 0x10);
        pk |= 1UL << 56;
    }
    *(unsigned long *)(pkt + 0x10) = pk;
    pkt[0x16] = g[0x44ED];
    g[0x44ED] = g[0x44ED] + 1;
    g[0x44EE] = 0;
    pk = *(unsigned long *)(pkt + 0x10);
    pk = (pk & 0x0FFFFFFFFFFFFFFFUL) | ((unsigned long)(*(u32 *)(g + 0x4324) & 0xFF) << 60);
    *(unsigned long *)(pkt + 0x10) = pk;
    if (*(s32 *)(D_001A5CD0 + 0x170) == 0) {
        func_0014AD08(D_001A5CD0[0x7D4] | 0x80, *(s32 *)(D_001A5CD0 + 4), -1, D_L39_002405CC, r17 + 0x18, pkt);
    }
    goto L6194;
L6190:
L6194:
    p = *(u8 **)(g + 0x2558);
    v = *(s32 *)(p + 0x16C);
    if (v >= 0 && !(*(s32 *)(D_001A5CD0 + 0x128) < v)) {
        *(vu0_q *)(p + 0x190) = *(vu0_q *)(p + 0x180);
        p = *(u8 **)(g + 0x2558);
        *(s32 *)(p + 0x160) = *(s32 *)(p + 0x164);
        p = *(u8 **)(g + 0x2558);
        *(vu0_q *)(p + 0x180) = *(vu0_q *)(p + 0x170);
        p = *(u8 **)(g + 0x2558);
        *(s32 *)(p + 0x164) = *(s32 *)(p + 0x16C) - 0xF5;
        p = *(u8 **)(g + 0x2558);
        *(s32 *)(p + 0x16C) = -1;
    }
    count = *D_L39_00241120;
    i = 0;
    if (count > 0 && g != D_L39_002FB000) {
        u8 *q = D_L39_002FB000;
        i = 1;
        while (i < count) {
            q += 0x4500;
            if (q == g) break;
            i++;
        }
    }
    if ((p5_dec(g + 0x19E6) ^ 0x14) == 0 && g[0x19E6] != 0) {
        func_L39_00677348(i, 1);
        func_L39_006772F8(i, 1);
    } else {
        func_L39_00677348(i, 0);
        func_L39_006772F8(i, 0);
    }
    if (*(u8 **)(g + 0x2558) != 0) {
        func_L39_00661988(g);
        *(s32 *)(*(u8 **)(*(u8 **)(g + 0x2558) + 4) + 0x48) = *(s32 *)(g + 0x478);
        func_L39_00674190(g);
        *(u16 *)(*(u8 **)(*(u8 **)(g + 0x2558) + 4) + 0x84) = 0;
        for (k = 0; k < 16; k++) {
            u8 *key = g + 0x1A52 + k;
            res = (key[0] == 0) ? 0 : p16_dec(key, D_L39_00483A00, 0xD1);
            if ((res & 0xFFFF) != 0 || k == 0xB || k == 0xE || k == 0xF) {
                o = *(u8 **)(*(u8 **)(g + 0x2558) + 4);
                *(u16 *)(o + 0x84) = *(u16 *)(o + 0x84) | (1 << k);
            }
        }
        res = (g[0x1A40] == 0) ? 0 : p16_dec(g + 0x1A40, D_L39_00483A00, 0xD1);
        *(u16 *)(*(u8 **)(*(u8 **)(g + 0x2558) + 4) + 0x80) = (u16)res;
        res = (g[0x1A41] == 0) ? 0 : p16_dec(g + 0x1A41, D_L39_00483A00, 0xD1);
        *(u16 *)(*(u8 **)(*(u8 **)(g + 0x2558) + 4) + 0x82) = (u16)res;
    }
    if (g[0x1A0A] == 0 && D_001A5810.bA4[*(s32 *)(g + 0x2544)] == 2
        && (p5_dec(g + 0x19E4) ^ 0x90) != 0) {
        o = *(u8 **)(g + 0x424);
        *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(g + 0x424) + 0x24) + 0x10);
    }
    *(s32 *)(g + 0x2550) = *(s32 *)(g + 0x2550) + 1;
    if (*(s32 *)(g + 0x2550) >= 0x65) {
        st = *(s32 *)(g + 0x254C);
        if (st == 1 || st == 2) {
            *(s32 *)(g + 0x254C) = 0;
        } else if (st == 3) {
            *(s32 *)(g + 0x254C) = 5;
        } else if (st == 4) {
            *(s32 *)(g + 0x254C) = 6;
        }
    }
    *(f32 *)(g + 0x2538) = *(f32 *)(g + 0xA0);
    *(f32 *)(g + 0x2540) = *(f32 *)(g + 0xA8);
    *(f32 *)(g + 0x253C) = *(f32 *)(g + 0xA4);
}
