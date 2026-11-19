/* functional: medium. Written from the PAL assembly (640 words; layout differs throughout, 637 words differ). Register passthrough fixed: retail uses v0 of func_003A0B60 (declared void in the file) and of func_003C2D00; both called with a returning type. 30 - plzcw(v) is written as floor(log2 v) (-1 for 0), same value. gp-relative globals named by address: D_001D8CD4 (header flags), D_001DA668, D_001DA48C, D_001D8CD8, D_001D8CE0 have no symbol_addrs rows yet. Medium: very wide function, callee prototypes inferred from register use; every offset taken from the assembly. */
/* globals as retail names them (lui/%lo); gp-relative ones by address (gp 0x1DC8B0) */
extern u8 D_1A4BE0[];
extern f32 D_1D9BD0[];
extern s32 D_1D9BD8[];
extern u8 D_1A1ED0[];
extern s32 D_1D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001DA058;
extern u8 D_1D9D80[];
extern u8 D_2DB190[];
extern s16 D_2DAFB0[];
extern s32 D_2DA740[];
extern s32 D_2DDC30[];
extern u8 D_2DE3B0[];
extern s32 D_2DD430[];
extern s32 D_2FD200[];
extern u8 D_1CCFD0[];
extern u8 D_16C580[];
extern u16 D_001D54D2;
extern s32 D_001D54D0;
extern s32 D_1D4B60;
extern u8 D_00142660[];
extern u8 D_160C40[];
extern u8 D_227580[];
extern s32 D_001D8CD4;   /* gp-0x3BDC: world header flags */
extern s32 D_001DA668;   /* gp-0x2248 */
extern s32 D_001DA48C;   /* gp-0x2424 */
extern s32 D_001DA480;   /* gp-0x2430, also lui */
extern s32 D_001D9C04;   /* gp-0x2CAC */
extern u8 *D_001DA4A0;   /* gp-0x2410, also lui */
extern u8 *D_001DA4B0;   /* gp-0x2400 */
extern s32 D_001D8CD8;   /* gp-0x3BD8 */
extern s32 D_001D8CE0;   /* gp-0x3BD0 */
extern unsigned long D_22CAD0[];
extern unsigned long D_1D9F60[];
extern u8 D_001D5F30[];
extern u8 D_2FF600[], D_2FF700[], D_2FF200[], D_2FC640[];
extern u8 D_001D6EA0[];
extern u8 *D_1DA49C;
extern u8 *D_1DA4A4;
extern s32 D_1DA4B4;
extern u8 *D_1D9BCC;
extern s32 D_1DA5C0, D_1DA5C4, D_1DA5C8, D_1DA5CC, D_1DA5D0, D_1DA4D0;
extern f32 D_1DA690;
extern u8 D_225900[];
extern u8 D_1D9C44, D_1D9C45, D_1D9C46;
extern f32 D_1D9C48, D_1D9C4C, D_1D9C50, D_1D9C54;
extern s32 D_2228D0;
extern void func_00398288(void);
extern void func_00387648(void);
extern void func_003877A0(void);
extern void func_003A94C0(void);
extern void func_00399060(void);
extern void func_00398F98(void);
extern void func_00398BE8(void);
extern void func_003A2A80(s32, s32, s32);
extern void func_0038A618(s32);
extern void func_0013CDF0(s32);
extern void func_00399980(void *, s32, s32, void *);
extern void func_00398A48(void *);
extern void func_0039A148(void *, void *, void *, s32);
extern void func_0039A260(void *, void *);
extern void func_00398878(void *, void *, void *, s32);
extern void func_00398998(void *, s32);
extern void func_0038CF80(void *, s32);
extern void func_0038D108(void *, void *, s32);
extern void func_003C2990(void *, s32);
extern void func_0038D708(void *, void *);
extern void func_0038D970(void *, void *);
extern void func_003C7348(void *, s32, s32, s32, s32);
extern u32 func_003C2D00(s32, s32);
extern void func_00398E68(void);
extern void func_00399DE8(s32, s32);
extern void func_00392640(void);
extern void func_003868A0(s32);
extern void func_003882D0(void);

/* floor(log2(v)), -1 for 0: what retail's 30 - plzcw(v) gives for a 16-bit value */
static s32 log2_3BBDC0(u32 v) {
    s32 n = -1;
    while (v != 0) {
        n++;
        v >>= 1;
    }
    return n;
}

void func_003BBDC0(s32 reload) {
    u8 *h, *data, *tex, *tbl, *e, *m, *src, *q, *s;
    u8 *end;
    s32 r, n, k, save, a0, idx, id;
    u8 b8;
    f32 mtx[16] __attribute__((aligned(16)));
    u8 *grp;

    *(f32 *)(D_1A4BE0 + 0x2E8) = -1.0f;
    *(s32 *)(D_1A4BE0 + 0x25C0) = 0;
    *(s32 *)(D_1A4BE0 + 0x2E0) = 0;
    *(s32 *)(D_1A4BE0 + 0x2E4) = 0;
    D_1D9BD0[0] = 1.0f;
    D_1D9BD8[0] = 0;
    D_001DA058 = 0x100000;
    func_00398288();
    D_1D4BB4 = *(s32 *)(D_1A1ED0 + 0x20);
    D_001D4BB0 = *(s32 *)(D_1A1ED0 + 0x20);
    func_0038CF58(D_1D9D80, 0x87654321, 0x10);
    func_0038CF58(D_2DB190, -1, 0x2000);
    func_0038CF58(D_2DE3B0, -1, 0xF00);
    func_0038CF58(D_2DDC30, 0, 0xF0);
    func_00387648();
    func_003877A0();
    func_003A94C0();
    save = D_1CCFD0[7];
    D_1CCFD0[7] = 0;
    if (reload != 0) {
        if (*(s32 *)(D_16C580 + 0x30) != (D_001D54D2 & 0x1F)) func_00399060();
        if (*(s32 *)(D_16C580 + 0x18) != (D_001D54D0 & 3)) func_00398F98();
    }
    if (D_1D4B60 != *(s16 *)(D_00142660 + 0x40)) func_00398BE8();
    idx = *(s16 *)(D_16C580 + 0x2E);
    D_1CCFD0[7] = save;
    func_003A2A80(*(s32 *)(D_227580 + 0x18) + 0x400000,
                  *(s32 *)(D_160C40 + 0x12B8 + idx * 8) + *(s32 *)(D_160C40 + 0x1284),
                  *(s32 *)(D_160C40 + 0x12BC + idx * 8));
    func_0038A618(5);
    func_0013CDF0(0);
    func_11F0A0(0);
    r = ((s32 (*)(u8 *, u32))func_003A0B60)((u8 *)(*(s32 *)(D_227580 + 0x18) + 0x400000),
                                           *(s32 *)(D_227580 + 0x18));
    func_11F0A0(0);

    /* world header at D_227580+0x18: offsets relative to the header (h) or to its data block */
    h = (u8 *)*(s32 *)(D_227580 + 0x18);
    end = h + r;
    data = h + *(s32 *)(h + 0x8);
    tex = data + *(s32 *)(h + 0x5C);
    *(u8 **)(D_227580 + 0x48) = end;
    D_001D8CD4 = *(s32 *)(h + 0x0);
    func_00399980(h + *(s32 *)(h + 0x4), *(s32 *)(h + 0x10), 0, h + *(s32 *)(h + 0x14));
    if (D_001D8CD4 & 2) {
        tbl = h + *(s32 *)(h + 0x20);
        n = *(s32 *)(h + 0x1C);
        D_001DA668 = n;
        for (k = 0; k < n; k++, tbl += 0x10)
            D_2FD200[k] = (s32)(tex + *(s32 *)tbl) + (log2_3BBDC0(*(u16 *)(tbl + 4)) << 28);
    }
    if (D_001D8CD4 & 4) {
        tbl = h + *(s32 *)(h + 0x3C);
        n = *(s32 *)(h + 0x38);
        D_001DA48C = n;
        for (k = 0; k < n; k++, tbl += 0x10)
            D_2DD430[k] = (s32)(tex + *(s32 *)tbl) + (log2_3BBDC0(*(u16 *)(tbl + 4)) << 28);
    }
    if (D_001D8CD4 & 1) func_00398A48(data + *(s32 *)(h + 0x24));
    if (D_001D8CD4 & 4) {
        e = h + *(s32 *)(h + 0x30);
        D_001DA480 = 0;
        for (k = 0; k < *(s32 *)(h + 0x28); k++, e += 0x20) {
            q = *(s32 *)e != 0 ? data + *(s32 *)e : 0;
            id = *(s32 *)(e + 4);
            if (id == 0xD54) continue;
            if (*(s32 *)(e + 8) != 0) {
                D_22CAD0[1] = 0xFFA0000000E0UL;
                D_22CAD0[0] = *(unsigned long *)(D_16C580 + 0x38);
                D_22CAD0[2] = 0x40000400004000UL;
                func_0039A148(q, 0, D_001D5F30, *(s32 *)(e + 4));
                D_2DDC30[D_001DA480 - 1] = 0xFFFC0000;
            } else {
                func_0039A148(q, h + *(s32 *)(h + 0x3C), e + 0x10, id);
            }
        }
    }
    if (D_001D8CD4 & 2) {
        *(u8 **)(D_227580 + 0x1C) = data + *(s32 *)(h + 0x18);
        func_0039A260(data + *(s32 *)(h + 0x18), h + *(s32 *)(h + 0x20));
    }
    if (D_001D8CD4 & 0x10)
        func_00398878(h + *(s32 *)(h + 0x40), data + *(s32 *)(h + 0x60), h + *(s32 *)(h + 0x48), *(s32 *)(h + 0x44));
    D_001D9C04 = (s32)(data + *(s32 *)(h + 0x64));
    func_00398998(h + *(s32 *)(h + 0x50), *(s32 *)(h + 0x4C));

    /* TEX0 for the shared sky/env texture */
    D_1D9F60[2] = 0x40000400004000UL;
    D_1D9F60[0] = (((unsigned long)((u32)(*(s32 *)(D_1A1ED0 + 0x34) + (*(s32 *)(h + 0x54) << 2)) >> 8)) | 0x1DB08000)
                | ((unsigned long)((u32)(*(s32 *)(D_1A1ED0 + 0x20) + *(s32 *)(h + 0x58)) >> 8) << 37)
                | 0x5C0000000UL | 0x8000000000000000UL;
    D_1D9F60[1] = 0xFFA0000000E0UL;
    func_0038CF80(D_2FF600, 0x100);
    func_0038CF80(D_2FF700, 0x180);
    func_0038CF80(D_2FF200, 0x400);
    func_0038D108(D_2FF200, D_001D6EA0, 0x40);

    if (D_001D8CD4 & 0xC) {
        /* moby instances: 0x100 bytes each, then 0x41 spare slots */
        n = *(s32 *)(h + 0x2C);
        D_1DA49C = end;
        func_0038CF58(end, 0, (n + 0x41) << 8);
        end += (n + 0x41) << 8;
        src = h + *(s32 *)(h + 0x34);
        m = D_1DA49C;
        for (k = n; k > 0; k--) {
            func_003C2990(m, *(s32 *)src);
            *(u16 *)(m + 0x32) = 0xFF;
            m[0x30] = 0xFF;
            q = *(u8 **)(m + 0x24);
            *(f32 *)(m + 0x10) = *(f32 *)(src + 0x4);
            *(f32 *)(m + 0x14) = *(f32 *)(src + 0x8);
            *(f32 *)(m + 0x18) = *(f32 *)(src + 0xC);
            *(f32 *)(m + 0xF0) = *(f32 *)(src + 0x10);
            *(f32 *)(m + 0xF4) = *(f32 *)(src + 0x14);
            *(f32 *)(m + 0xF8) = *(f32 *)(src + 0x18);
            if (q != 0)
                *(f32 *)(m + 0x2C) = *(f32 *)(src + 0x1C) * *(f32 *)(q + 0x24);
            else
                *(f32 *)(m + 0x2C) = *(f32 *)(src + 0x1C);
            func_0038D708(mtx, m + 0xF0);
            src += 0x28;
            func_0038D970(m + 0xC0, mtx);
            func_003C7348(m, 0x303030, 0, 0, 0);
            *(s32 *)(m + 0x38) = 0;
            m[0x7E] &= 0xFE;
            m += 0x100;
        }
        D_001DA4A0 = D_1DA49C + n * 0x100;
        if (D_001D8CD4 & 8) D_001DA4A0 = D_001DA4A0 + 0x100;
        D_1DA4A4 = D_001DA4A0 + 0x41 * 0x100;
        D_001DA4A0[0x20] = 0xFF;
        D_1DA4B4 = 0x82;
        D_001DA4B0 = end;
        end = (u8 *)func_003C2D00(0x41, (s32)(end + 0x41 * 0x80));
        for (k = 0x40, m = D_001DA4A0 + 0x100; k >= 0; k--, m += 0x100) m[0x20] = 0xFE;

        /* the front-end's own moby class 0xD54 */
        k = D_001DA480;
        *(s32 *)(D_16C580 + 0x1C) = k;
        b8 = D_16C580[0x1C];
        grp = *(u8 **)(D_227580 + 0x70);
        D_2DAFB0[k] = 0xD54;
        D_2DB190[0xD54] = b8;
        D_001DA480 = k + 1;
        D_2DDC30[k] = 0xFFFC0000;
        D_2DA740[k] = (s32)grp;
        if (grp[6] != 0) {
            s = (u8 *)*(s32 *)grp + grp[7] * 16;
            s = (u8 *)*(s32 *)s + *(s32 *)(s + 4) * 16;
            *(unsigned long *)(s - 0x20) = D_1D9F60[0];
            *(unsigned long *)(s - 0x10) = D_1D9F60[2];
        }
        if (D_2DB190[0] != 0xFF) {
            if (D_1D4B60 != *(s16 *)(D_00142660 + 0x40)) {
                func_00398E68();
                D_1D4B60 = *(s16 *)(D_00142660 + 0x40);
            }
            func_00399DE8(D_2DA740[0], *(s32 *)(D_227580 + 0x78));
            D_2DDC30[0] = 0xFFFC0000;
        }
        if (D_001D8CD4 & 8) {
            D_1D9BCC = D_001DA4A0 - 0x100;
            (D_001DA4A0 - 0x100)[0x20] = 0xFD;
            if (D_001D8CD4 & 8) {
                D_001DA058 = D_001DA058 - 0x60000;
                D_001D8CD8 = *(s32 *)(h + 0x68);
            }
        }
    }
    end += 0x400;
    *(u8 **)(D_227580 + 0x64) = end;
    D_1DA5C0 = (s32)end;
    D_1DA5C8 = -1;
    end += 0x20000;
    D_1DA5C4 = 0;
    D_1DA5CC = 0;
    func_0038CF80(D_2FC640, 0x200);
    D_001D8CE0 = *(s32 *)(h + 0x98);
    if (*(s32 *)(h + 0x94) != 0) {
        s = h + *(s32 *)(h + 0x94);
        *(s32 *)(D_225900 + 0x25C) = *(s32 *)(s + 0x0);
        *(s32 *)(D_225900 + 0x260) = *(s32 *)(s + 0x4);
        *(s32 *)(D_225900 + 0x264) = *(s32 *)(s + 0x8);
        *(s32 *)(D_225900 + 0x250) = *(s32 *)(s + 0xC);
        *(s32 *)(D_225900 + 0x254) = *(s32 *)(s + 0x10);
        *(s32 *)(D_225900 + 0x258) = *(s32 *)(s + 0x14);
        *(f32 *)(D_225900 + 0x228) = *(f32 *)(s + 0x18);
        *(f32 *)(D_225900 + 0x22C) = *(f32 *)(s + 0x1C);
        *(f32 *)(D_225900 + 0x238) = *(f32 *)(s + 0x20);
        D_1D9C46 = D_225900[0x258];
        D_1D9C44 = D_225900[0x250];
        D_1D9C45 = D_225900[0x254];
        D_1D9C48 = *(f32 *)(s + 0x18);
        D_1D9C4C = *(f32 *)(s + 0x1C);
        D_1D9C50 = *(f32 *)(s + 0x20);
        D_1D9C54 = *(f32 *)(s + 0x24);
        *(f32 *)(D_225900 + 0x23C) = *(f32 *)(s + 0x24);
        func_00392640();
        D_2228D0 = 0;
        func_003868A0(0);
    }
    func_003882D0();
    *(u8 **)(D_227580 + 0x68) = end;
    D_1DA690 = 983040.0f;
    D_1DA4D0 = 0x3C0;
    D_1DA5D0 = 0x7D0000;
}
