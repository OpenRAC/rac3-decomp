/* functional: high. Ported from the matched frontbin twin func_00394620 (src/frontbin/394620.c), callees renamed to boot_elf addresses; assembly identical modulo addresses. MATCHes boot_elf.elf with @ps2as flags (check.py --retail baserom/boot_elf.elf --no-context), but 392DF8.c flags (-mno-split-addresses) give 509 diffs: the boot_elf text_parts boundary for this function may be wrong. */
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8_00394A00;
extern s32 D_001D5CAC;
extern u8 D_001425C0[];
extern s32 func_00393A00(S_38EDE8_00394A00 *p, s32 *x, s32 *y);
extern void func_0039AA38(s32);
extern void func_00381CA8(s32);
extern void func_00381D70(s32);
extern s32 func_003934B8(s32);
#define ROW_38F3F8 ((E_38F3F8 *)((s32 *)D_001D9EF0_00394A00)[D_001D5CAC])
typedef struct {
    u8 pad0[0x50];
    s32 x;
    s32 y;
    s32 f58;
    u8 pad5C[0x70 - 0x5C];
    u8 st[2];
    u8 pad72[2];
    s32 sel;
} P_00394A00;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 id;
} E_00394A00;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[0x44 - 2];
    s16 msg;
    u8 pad46[0x68 - 0x46];
    s32 f68;
    u8 pad6C[0x84 - 0x6C];
    u16 f84;
    u8 pad86[0xF0 - 0x86];
} __attribute__((aligned(16))) T_00394A00;
extern s32 D_001D9EE8[];
extern s32 D_001D9EE8_00394A00;
extern E_00394A00 **D_001D9EF0_00394A00;
extern s32 D_001D5CAC;
extern s32 D_001D5C78;
extern s32 D_001D55E8;
extern s32 D_0031D050[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s32 D_00142DE0[];
extern T_00394A00 D_001DAA40_00394A00[];
extern char D_001D5D60[];
extern s32 D_001D5D68;
extern s32 D_001D5D6C;
extern s32 D_001D5D70;
extern s32 D_001D5D74;
extern s32 D_001D5D78;
extern f32 D_001D5D7C;
extern s32 D_001D5D80;
__asm__(".extern D_001D5CAC, 4");
__asm__(".extern D_001D5C78, 4");
__asm__(".extern D_001D55E8, 4");
__asm__(".extern D_001D5D68, 4");
__asm__(".extern D_001D5D78, 4");
__asm__(".extern D_001D5D7C, 4");
__asm__(".extern D_001D5D80, 4");
extern void func_003AEFF8(u8 *, s32, f32);
extern s32 func_00398088(void);
extern void func_0011B2E8(void *, char *, s32);
extern s32 func_0038DFB8(s32, s32, f32);
extern s32 func_00391198_00394A00(s32, s32, unsigned long, void *, s32);
extern s32 func_00381C90_00394A00(s32, s32);
extern void func_0038B310(s32, s32, s32, s32, unsigned long);
extern s32 func_003823D0(s32);
extern s32 func_0011B868(u8 *);
extern void func_0038E530(s32);
extern void func_003916E8_00394A00(u8 *, s32, s32, f32);
extern void func_003910A8(void);
extern void func_00391088(void);
extern void func_00391620_00394A00(s32, s32, unsigned long, u8 *, s32, s32, f32);

s32 func_00394A00(P_00394A00 *p) {
    s32 col;
    char buf[0x50];
    u8 *st;
    T_00394A00 t;
    s32 x;
    s32 y;
    f32 a;
    f32 b;
    f32 ab;
    s32 w;
    s32 i;
    s32 sel;
    s32 id;
    s32 saved;
    s32 n;
    s32 cnt;
    s32 has;
    f32 fcnt;
    f32 fcur;
    f32 frac;
    s32 base;
    u32 alpha;
    u8 *str;
    u8 *q;
    s32 j;
    s32 len;
    s32 split;
    s32 yy;
    s32 msg;

    st = p->st;
    a = st[0] * 0.125f;
    if (a > 1.0f) {
        a = 1.0f;
    } else if (a < 0.0f) {
        a = 0.0f;
    }
    b = st[1] * 0.125f;
    if (b > 1.0f) {
        b = 1.0f;
    } else if (b < 0.0f) {
        b = 0.0f;
    }
    x = p->x;
    y = p->y;
    w = a * 128.0f;
    func_00393A00((S_38EDE8_00394A00 *)p, &x, &y);
    for (i = 0; i < D_001D9EE8_00394A00; i++) {
        if (p->sel == i && D_001D9EF0_00394A00[D_001D5CAC][i].f0 != 0 && D_001D5C78 != 0) {
            f32 f = i;
            if (f > 7.0f) {
                f -= 8.0f;
            }
            {
                u8 *h = (u8 *)(D_001D5C78 + 0x1FCA8);
                func_003AEFF8(h + 0x18A0, 1, f);
            }
        }
        if (D_001D9EF0_00394A00[D_001D5CAC][i].f0 != 0 && D_001D5C78 != 0) {
            *(s32 *)(D_001D5C78 + 0x24DD4) = func_00398088() ? (s32)(w * 0.5f) : 0;
        }
    }
    sel = p->sel;
    if (sel >= 0 && D_001D9EF0_00394A00[D_001D5CAC][sel].f0 != 0 && D_0031D050[0] == 0) {
        id = D_001D9EF0_00394A00[0][sel].id;
        ab = a * b;
        if (D_001DAA40_00394A00[D_001425C0[id]].b0 != 0) {
            if (D_001DAA40_00394A00[D_001425C0[id]].f84 != 0) {
                n = D_001427F0[id];
                func_0011B2E8(buf, D_001D5D60, n);
                {
                    s32 c;
                    u32 al;
                    if (n != 0) {
                        c = func_0038DFB8(0x8066CCFF, 0x8066CCFF, ab);
                    } else {
                        c = func_0038DFB8(0x004040FF, 0x804040FF, ab);
                    }
                    al = c & 0xFF000000;
                    if (al > 0x80000000) {
                        al = 0x80000000;
                    }
                    func_00391198_00394A00(x + 0x6B, y + 0x79, al, buf, -1);
                    func_00391198_00394A00(x + 0x69, y + 0x77, c, buf, -1);
                }
            }
            n = D_001DAA40_00394A00[D_001425C0[id]].b1;
            cnt = D_001DAA40_00394A00[D_001425C0[id]].f68;
            has = n != 0;
            if (cnt != 0 || has) {
                fcnt = cnt;
                fcur = D_00142DE0[id] >> 5;
                frac = 0.0f;
                if (cnt > 0) {
                    if (fcnt != 0.0f) {
                        base = 0;
                        if (n != 0) {
                            func_00381C90_00394A00(id, n - 1);
                            base = D_001DAA40_00394A00[D_001425C0[id]].f68;
                            func_00381C90_00394A00(id, n);
                        }
                        frac = (fcur - base) / (fcnt - base);
                    }
                } else {
                    frac = 1.0f;
                }
                {
                    s32 r0 = D_001D5D6C + 0x86;
                    s32 r1 = D_001D5D74 + 0x86;
                    s32 r2 = D_001D5D68 + 0x69;
                    s32 r3 = D_001D5D70 + 0x69;
                    func_0038B310(y + r0, y + r1, x + r2, x + r3 + (s32)(frac * 92.0f), 0x706EC8FF);
                }
            }
        }
        split = 0;
        col = func_0038DFB8(0x8066CCFF, 0x8066CCFF, ab);
        t = D_001DAA40_00394A00[D_001425C0[D_001D9EF0_00394A00[D_001D5CAC][sel].id]];
        str = (u8 *)func_003823D0(t.msg);
        len = func_0011B868(str);
        if (str != 0 && len != 0) {
            q = str;
            for (j = 0; j < len; j++) {
                q++;
                if (*q == '-') {
                    q++;
                    split = j + 2;
                    break;
                }
            }
            if (split == 0) {
                q = str;
                for (j = 0; j < len; j++) {
                    q++;
                    if (*q == ' ') {
                        q++;
                        split = j + 1;
                        break;
                    }
                }
            }
            alpha = col & 0xFF000000;
            if (alpha > 0x80000000) {
                alpha = 0x80000000;
            }
            yy = y + 0x50;
            if (split != 0) {
                yy = y + 0x40;
            }
            saved = D_001D55E8;
            func_0038E530(1);
            msg = -1;
            if (t.b0 != 0) {
                switch (t.b1) {
                case 0: msg = 0x18B8; break;
                case 1: msg = 0x18B9; break;
                case 2: msg = 0x18BA; break;
                case 3: msg = 0x18BB; break;
                case 4: msg = 0x18BC; break;
                case 5: msg = 0x18BD; break;
                case 6: msg = 0x18BE; break;
                case 7: msg = 0x18BF; break;
                }
            }
            if (msg != -1) {
                func_0038E530(0);
                func_00391198_00394A00(x + 0x6B, D_001D5D80 + yy - 0xE, alpha, (void *)func_003823D0(msg), -1);
                {
                    s32 o = D_001D5D80 - 0x10;
                    func_00391198_00394A00(x + 0x69, yy + o, col, (void *)func_003823D0(msg), -1);
                }
                func_0038E530(1);
            }
            if (split != 0) {
                func_003916E8_00394A00(str, split, 0x50, 0.8f);
                func_003910A8();
                func_00391620_00394A00(x + 0x6B, yy + D_001D5D80 + 2, alpha, str, split, D_001D5D78, D_001D5D7C);
                func_00391088();
                func_00391620_00394A00(x + 0x69, yy + D_001D5D80, col, str, split, D_001D5D78, D_001D5D7C);
                yy += 0x10;
                func_003916E8_00394A00(q, -1, 0x50, 0.8f);
                func_003910A8();
                func_00391620_00394A00(x + 0x6B, yy + D_001D5D80 + 2, alpha, q, -1, D_001D5D78, D_001D5D7C);
                func_00391088();
                func_00391620_00394A00(x + 0x69, yy + D_001D5D80, col, q, -1, D_001D5D78, D_001D5D7C);
            } else {
                func_003910A8();
                func_00391620_00394A00(x + 0x6B, yy + D_001D5D80 + 2, alpha, str, -1, D_001D5D78, D_001D5D7C);
                func_00391088();
                func_00391620_00394A00(x + 0x69, yy + D_001D5D80, col, str, -1, D_001D5D78, D_001D5D7C);
            }
            func_0038E530(saved);
        }
    }
    return p->f58;
}
