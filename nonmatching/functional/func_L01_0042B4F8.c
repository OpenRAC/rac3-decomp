/* functional: medium. Written from the PAL asm (no prior draft), section by section; every offset, width, call argument and branch was traced, bytes differ entirely (823 of ~830 words, register allocation/ordering). plzcw is a bit-count helper. Unnamed level globals use D_L01_ names by address; the lead should confirm names/types in the gate. */
typedef struct { s32 w[4]; } Q_0042B4F8;
/* level file header: word fields named by their hex offset */
typedef struct {
    s32 w00, w04, w08, w0C, w10, w14, w18, w1C, w20, w24, w28, w2C, w30, w34, w38, w3C;
    s32 w40, w44, w48, w4C, w50, w54, w58, w5C, w60, w64, w68, w6C, w70, w74, w78, w7C;
    s32 w80, w84, w88, w8C, w90, w94, w98, w9C, wA0, wA4, wA8, wAC, wB0, wB4, wB8;
} Hdr_0042B4F8;
/* loader state at D_L01_001EA940 */
typedef struct {
    s32 w00, w04, w08, w0C, w10, w14, w18, w1C, w20, w24, w28, w2C, w30, w34, w38, w3C;
    s32 w40, w44, w48, w4C, w50, w54, w58, w5C, w60, w64, w68, w6C, w70, w74, w78;
} Ld_0042B4F8;
typedef struct {
    u8 *p0;
    u8 pad4[2];
    u8 b6, b7;
    u8 pad8[4];
    u8 bC, bD;
    u8 padE[0x1A];
    u8 *p28;
    u8 pad2C[0x1C];
    s32 w48[1];
} Obj_0042B4F8;
typedef struct {
    Q_0042B4F8 q;
    s16 f10, f12, f14;
} P_0042B4F8;

extern Ld_0042B4F8 D_L01_001EA940;
extern s32 D_001D4B50;
extern s32 D_L01_001F3F40[];
extern u8 D_L01_001DFE80[];
extern u8 D_001BBC40[];
extern unsigned long D_L01_001DFE90[];
extern unsigned long D_L01_001DFEA8[];
extern s32 D_001A1ED0[];
extern s32 D_001D545C;
extern s32 D_L01_001E0E98;
extern s32 D_L01_001E000C;
extern s32 D_L01_001E0F10;
extern s32 D_L01_001E0DDC;
extern s32 D_L01_0023B700[];
extern s32 D_L01_001FFE70[];
extern s32 D_L01_00243000[];
extern s32 D_L01_002395F0[];
extern P_0042B4F8 D_0016C690;
extern s32 D_0016C580[];
extern unsigned long D_001D4BA8;
extern u8 D_001D6D10_sda[];
extern unsigned long D_L01_001F3DC0[];
extern s32 D_L01_001E0000;
extern s32 D_L01_00200670[];
extern Obj_0042B4F8 *D_L01_001FD180[];
extern u8 D_L01_001FDBD0[];
extern s16 D_L01_001FD9F0[];
extern u8 D_00142660[];
extern s32 D_L01_0021F5E0;
extern s32 D_001D4B60;
extern s32 D_001D4B90;
extern s32 D_001D4B94;
extern s32 D_L01_0023C500;
extern s32 D_L01_00238470;
extern s32 D_L01_001DF984;
extern Q_0042B4F8 D_L01_001DFEC0, D_L01_001DFED0, D_L01_001DFEE0, D_L01_001DFEF0;
extern s32 D_L01_001DFF00;
extern s32 D_L01_001DFB80, D_L01_001DFB84, D_L01_001DFB88, D_L01_001DFB8C;
extern s32 D_L01_001D66A0, D_L01_001DFC8C;
extern s32 D_L01_001E0E94;
extern s32 D_L01_001DFB6C, D_L01_001DFB68;
extern s32 D_L01_001DFC20;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0020;
extern s32 D_L01_001E1078;
extern s32 D_L01_001E0DF0;

extern void func_00398E50(void);
extern void func_L01_004B32E8(void);
extern void func_0038CD28(void *, void *, s32);
extern void func_0038CC88(void *, void *, s32);
extern void func_003995A0(u8 *, s32, s32, s32 *);
extern void func_0011F0A0(s32);
extern s32 func_003A0760(s32, s32);
extern void func_00399E80(s32, s32);
extern void func_00398668(s32);
extern void func_L01_00427E58(s32);
extern void func_00399D68(s32, s32, s32, s32);
extern void func_L01_00427F18(s32 *, s32, s32 *);
extern void func_00398A88(s32);
extern void func_00399A08(s32, s32);
extern s32 func_L01_00419F70(void);
extern void func_L01_00425CD0(s32);
extern void func_L01_00426B60(Obj_0042B4F8 *, s32);
extern void func_L01_00427220(s32, s32, s32, s32);
extern void func_L01_00428090(void);
extern void func_L01_004275F8(s32, s32, s32, s32, s32);
extern void func_003985B8(s32, s32);
extern void func_L01_00425218(s32);
extern void func_00398498(s32, s32, s32, s32);
extern s32 func_L01_00428098(s32);
extern void func_L01_0042AE30(void);
extern void func_L01_0042AF50(s32);
extern void func_L01_004A3848(void);
extern void func_L01_004A35C0(void);
extern void func_L01_004004F8(u8 *);
extern void func_L01_003F1E98(s32);

/* base + offset + (index of the highest set bit of w) << 28; plzcw in retail */
static s32 TexAddr_0042B4F8(s32 base, s32 off, u32 w) {
    s32 e = -1;
    while (w != 0) { e++; w >>= 1; }
    return base + off + (e << 28);
}

s32 func_L01_0042B4F8(s32 flag, s32 arg2) {
    Ld_0042B4F8 *L = &D_L01_001EA940;
    Hdr_0042B4F8 *h = (Hdr_0042B4F8 *)L->w0C;
    u8 *hb = (u8 *)h;
    s32 *boot = (s32 *)D_001D4B50;
    s32 base = L->w18;
    s32 cur, tabEnd, size, i, j, k, n, slot;
    s32 *e;
    u8 *eb;
    if (flag != 0) func_00398E50();
    if (flag != 0) {
        func_L01_004B32E8();
        D_L01_001F3F40[0] = 0;
        func_0038CD28(h, (u8 *)boot + boot[2], boot[3]);
        func_0038CC88(D_L01_001DFE80, D_001BBC40 + D_001D545C * 16, 16);
        func_003995A0((u8 *)boot + boot[4], h->w00, h->w84, (s32 *)(hb + h->w04));
        func_0011F0A0(0);
        size = func_003A0760((s32)((u8 *)boot + boot[0x12]), base);
        cur = base + h->w60;
        L->w2C = cur;
        D_L01_001DFE90[0] = ((long)(s32)((D_001A1ED0[13] + h->w90 * 4) >> 8) | 0x1DB08000LL)
            | (((long)(s32)((D_001A1ED0[8] + h->w94) >> 8) << 37) | 0x5C0000000LL) | 0x8000000000000000ULL;
        D_L01_001DFE90[2] = 0x0040000400004000ULL;
        D_L01_001DFE90[1] = 0xFFA0000000E0ULL;
        D_L01_001DFEA8[2] = 0x0040000400004000ULL;
        D_L01_001DFEA8[1] = 0xFFA0000000E0ULL;
        D_L01_001DFEA8[0] = (((long)(s32)((D_001A1ED0[13] + h->w98 * 4) >> 8) | 0x19B04000LL)
            | (((long)(s32)((D_001A1ED0[8] + h->w9C) >> 8) << 37) | 0x580000000LL)) | 0x8000000000000000ULL;
        D_L01_001E0E98 = h->w30;
        eb = hb + h->w34;
        for (k = 0; k < h->w30; k++, eb += 16)
            D_L01_0023B700[k] = TexAddr_0042B4F8(cur, *(s32 *)eb, *(u16 *)(eb + 4));
        tabEnd = base + size;
        D_L01_001E000C = h->w38;
        eb = hb + h->w3C;
        for (k = 0; k < h->w38; k++, eb += 16)
            D_L01_001FFE70[k] = TexAddr_0042B4F8(L->w2C, *(s32 *)eb, *(u16 *)(eb + 4));
        *(Q_0042B4F8 *)&D_0016C690 = ((Q_0042B4F8 *)(hb + h->w3C))[h->w80];
        D_0016C690.f10 = (u16)h->w80;
        D_L01_001E0F10 = h->w40;
        eb = hb + h->w44;
        for (k = 0; k < h->w40; k++, eb += 16)
            D_L01_00243000[k] = TexAddr_0042B4F8(L->w2C, *(s32 *)eb, *(u16 *)(eb + 4));
        D_L01_001E0DDC = h->w48;
        eb = hb + h->w4C;
        for (k = 0; k < h->w48; k++, eb += 16)
            D_L01_002395F0[k] = TexAddr_0042B4F8(L->w2C, *(s32 *)eb, *(u16 *)(eb + 4));
        L->w1C = base + h->w08;
        func_00399E80(L->w1C, (s32)(hb + h->w34));
        D_L01_001F3F40[2] = L->w1C;
        if (h->w0C != 0) {
            L->w20 = base + h->w0C;
            D_L01_001DFB80 = L->w20;
        } else {
            L->w20 = 0;
            D_L01_001DFB80 = 0;
        }
        if (h->w10 != 0) {
            L->w24 = base + h->w10;
            func_00398668(L->w24);
        } else {
            D_L01_001E0DF0 = 0;
            L->w24 = 0;
        }
        L->w28 = base + h->w14;
        func_L01_00427E58(L->w28);
        D_L01_001F3F40[1] = L->w28;
        eb = hb + h->w1C;
        for (i = 0; i < h->w18; i++, eb += 0x20) {
            e = (s32 *)eb;
            n = 0;
            if (e[0] != 0) n = base + e[0];
            if (e[2] != 0) {
                D_L01_001F3DC0[0] = (e[2] == 1) ? *(unsigned long *)((u8 *)D_0016C580 + 0x38) : D_001D4BA8;
                D_L01_001F3DC0[1] = 0xFFA0000000E0ULL;
                D_L01_001F3DC0[2] = 0x0040000400004000ULL;
                func_00399D68(n, 0, (s32)D_001D6D10_sda, e[1]);
                D_L01_00200670[D_L01_001E0000 - 1] = 0xFFFC0000;
            } else {
                func_00399D68(n, (s32)(hb + h->w3C), (s32)(eb + 0x10), e[1]);
            }
        }
        L->w38 = (s32)D_L01_001FD180[0];
        func_L01_00427F18((s32 *)(hb + h->w1C), h->w18, (s32 *)(hb + h->w24));
        k = D_L01_001E0000;
        D_0016C580[7] = k;
        j = D_0016C580[7];
        slot = (u8)j;
        D_L01_001FD9F0[j] = 0xD54;
        D_L01_001FD180[j] = (Obj_0042B4F8 *)L->w70;
        D_L01_00200670[j] = 0xFFFC0000;
        D_L01_001FDBD0[0xD54] = slot;
        D_0016C690.f12 = k + 1;
        D_L01_001E0000 = k + 2;
        D_L01_0021F5E0 = 0;
        if (D_001D4B60 != *(s16 *)(D_00142660 + 0x40)) {
            func_00398A88(*(s16 *)(D_00142660 + 0x40));
            D_001D4B60 = *(s16 *)(D_00142660 + 0x40);
        }
        func_00399A08((s32)D_L01_001FD180[0], L->w78);
        D_L01_00200670[0] = 0xFFFC0000;
        if (D_L01_001FDBD0[0xD54] != 0xFF) {
            Obj_0042B4F8 *o = D_L01_001FD180[D_L01_001FDBD0[0xD54]];
            if (o->b6 != 0) {
                s32 *t = (s32 *)(o->p0 + o->b7 * 16);
                u8 *end = (u8 *)t[0] + t[1] * 16;
                *(unsigned long *)(end - 0x20) = D_L01_001DFEA8[0];
                *(unsigned long *)(end - 0x10) = D_L01_001DFEA8[2];
            }
        }
        j = func_L01_00419F70();
        if (D_001D4B90 != j) func_L01_00425CD0(j);
        D_001D4B94 = D_L01_001FDBD0[0x47];
        if (D_L01_001FDBD0[0x47] != 0xFF) {
            func_00399A08((s32)D_L01_001FD180[D_L01_001FDBD0[0x47]], L->w74);
            D_L01_00200670[D_001D4B94] = 0xFFFC0000;
        }
        {
            s16 *sp = (s16 *)(hb + h->wAC);
            while (*sp >= 0) {
                if (D_L01_001FDBD0[*sp] != 0xFF) D_L01_00200670[D_L01_001FDBD0[*sp]] = 0xFFF00000;
                sp++;
            }
        }
        e = (s32 *)(hb + h->w78);
        for (k = 0; k < D_L01_001FD180[0]->bC; k++, e++) {
            if (*e != 0) {
                D_L01_001FD180[0]->w48[k] = base + *e;
                func_L01_00426B60(D_L01_001FD180[0], k);
            }
        }
        L->w44 = D_L01_001FD180[0]->w48[0];
        eb = hb + h->w24;
        for (i = 0; i < h->w20; i++, eb += 0x20)
            func_L01_00427220(base + *(s32 *)eb, (s32)(hb + h->w44), (s32)(eb + 0x10), *(s32 *)(eb + 4));
        if (D_L01_0023C500 != 0) L->w3C = D_L01_0023C500;
        func_L01_00428090();
        eb = hb + h->w2C;
        for (i = 0; i < h->w28; i++, eb += 0x30)
            func_L01_004275F8(base + *(s32 *)eb, (s32)(hb + h->w4C), (s32)(eb + 0x10), (s32)(eb + 0x20), *(s32 *)(eb + 4));
        if (D_L01_00238470 != 0) L->w40 = D_L01_00238470;
        L->w34 = base + h->w68;
        D_L01_001DF984 = L->w34;
        func_003985B8((s32)(hb + h->w5C), h->w58);
        if (h->wA4 != 0) {
            func_L01_00425218(base + h->wA4);
        } else {
            D_L01_001DFF00 = 0;
            D_L01_001DFEC0.w[0] = D_L01_001DFEC0.w[1] = D_L01_001DFEC0.w[2] = D_L01_001DFEC0.w[3] = 0;
            D_L01_001DFED0.w[0] = D_L01_001DFED0.w[1] = D_L01_001DFED0.w[2] = D_L01_001DFED0.w[3] = 0;
            D_L01_001DFEE0.w[0] = D_L01_001DFEE0.w[1] = D_L01_001DFEE0.w[2] = D_L01_001DFEE0.w[3] = 0;
            D_L01_001DFEF0.w[0] = D_L01_001DFEF0.w[1] = D_L01_001DFEF0.w[2] = D_L01_001DFEF0.w[3] = 0;
        }
        D_L01_001DFB84 = h->wA8 != 0 ? base + h->wA8 : 0;
        D_L01_001DFB88 = h->wB0 != 0 ? base + h->wB0 : 0;
        D_L01_001DFB8C = h->wB8 != 0 ? base + h->wB8 : 0;
        if (h->wB4 != 0) {
            s32 *p = (s32 *)(base + h->wB4);
            s32 *q;
            D_L01_001D66A0 = p[0];
            q = p + 2;
            D_L01_001DFC8C = (s32)q;
            for (k = p[0]; k > 0; k--, q += 4) q[1] += (s32)p + p[1];
        } else {
            D_L01_001DFC8C = 0;
        }
        L->w30 = base + h->w64;
        func_00398498((s32)(hb + h->w6C), L->w30, (s32)(hb + h->w54), h->w50);
        cur = (base + size + 0x3F) & ~0x3F;
        if (D_L01_001E0E94 != D_L01_001F3F40[6]) {
            D_L01_001F3F40[4] = cur;
            n = h->w30 << 4;
            func_0038CD28((void *)cur, hb + h->w34, n);
            cur += n;
            D_L01_001F3F40[5] = cur;
            cur = (cur + D_L01_001F3F40[6] * 2 + 0x7F) & ~0x3F;
        }
        {
            s16 *p70 = (s16 *)(hb + h->w70);
            s16 *pp;
            u8 *r;
            n = p70[1] << 5;
            D_L01_001DFB6C = cur;
            D_L01_001DFB68 = p70[1];
            func_0038CC88((void *)cur, (u8 *)p70 + p70[0], n);
            pp = p70 + 2;
            cur += n;
            r = (u8 *)D_L01_001DFB6C;
            for (k = D_L01_001DFB68; k > 0; k--, r += 0x20) {
                if (*(s16 *)(r + 0x1A) < pp[1]) *(u16 *)(r + 0x1A) = *(u16 *)((u8 *)p70 + pp[0] + *(s16 *)(r + 0x1A) * 4);
                else *(s16 *)(r + 0x1A) = -1;
                *(s32 *)(r + 0x1C) = 0;
            }
            eb = hb + h->w1C;
            pp += 2;
            for (i = 0; i < h->w18; i++, eb += 0x20, pp += 2) {
                s32 key = *(s32 *)(eb + 4);
                Obj_0042B4F8 *o;
                u8 *q;
                slot = D_L01_001FDBD0[key];
                if (D_L01_001FD9F0[slot] != key) continue;
                o = D_L01_001FD180[slot];
                q = (u8 *)p70 + pp[0];
                if (o->bD == 0) continue;
                n = *(s32 *)q;
                q += 4;
                for (j = 0; j < D_L01_001FD180[slot]->bD; j++, q += 4) {
                    *(u16 *)(D_L01_001FD180[slot]->p28 + j * 0x20 + 0x1A) = *(u16 *)q;
                    *(s32 *)(D_L01_001FD180[slot]->p28 + j * 0x20 + 0x1C) = n + 1;
                }
            }
        }
        L->w48 = (cur + 0x3F) & ~0x3F;
    }
    L->w68 = func_L01_00428098(flag);
    if (flag != 0) D_0016C690.f14 = -1;
    if (D_L01_001F3F40[3] != 0) {
        if (flag != 0) func_L01_0042AE30();
        func_L01_0042AF50(D_L01_001F3F40[0]);
    }
    if (arg2 != 0) func_L01_004A3848();
    else func_L01_004A35C0();
    D_L01_001DFC20 = 0;
    if (D_00142660[0x32] != 0) {
        u8 *p = D_L01_001E001C;
        if (p != D_L01_001E0020) {
            do {
                func_L01_004004F8(p);
                p += 0x100;
            } while (p != D_L01_001E0020);
        }
    }
    D_L01_001E1078 = 0;
    func_L01_003F1E98(1);
    return 0;
}
