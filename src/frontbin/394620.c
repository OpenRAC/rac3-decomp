#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392F68.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
extern s32 D_001D5CAC;
extern u8 D_001425C0[];
extern s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y);

typedef struct {
    u8 pad0[0x64];
    s32 f64;
    u8 pad68[4];
    s32 f6C;
    u8 st[4];
    s32 f74;
    s32 f78;
    s32 f7C;
} O_38F3F8;
typedef struct {
    u8 pad0[0x148];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1C0 - 0x150];
    s32 f1C0;
    volatile s32 f1C4;
    u8 pad1C8[4];
    s32 f1CC;
    u8 pad1D0[8];
    s32 f1D8;
} PAD_38F3F8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} E_38F3F8;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x84 - 0x14];
    u16 f84;
    u8 pad86[4];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_38F3F8;
typedef struct { u8 pad[0xB6]; u8 b; } B6_38F3F8;
typedef struct { u8 pad0[0x1228]; s32 f1228; u8 pad122C[0x25F8 - 0x122C]; s32 f25F8; } W_38F3F8;
typedef struct { u8 pad0[0xF0]; u16 fF0; u8 padF2[2]; u32 fF4; s32 fF8; } X_38F3F8;
extern s32 D_0031D050[];
extern u8 D_00143950_b[];
extern s32 D_001D5C98;
extern s32 D_001D5D5C;
extern u8 D_001D5D58;
extern f32 D_001D5D54;
extern s32 D_001D5CAC;
extern PAD_38F3F8 *D_001D52FC;
extern u8 D_1A745E[];
extern s32 D_001D9EE8_0038F3F8;
extern s32 D_001D9EF0_0038F3F8;
extern volatile s32 D_001D5D00;
extern volatile s32 D_001D5D04;
extern volatile s32 D_001D5D08;
extern volatile s32 D_001D5D0C;
extern u8 D_1425C0[];
extern T_38F3F8 D_001DAA40_0038F3F8[];
extern s16 D_001CCFD4[];
extern u8 D_1A4BE0[];
extern u8 D_1A7C10[];
extern s32 D_1427F0[];
extern u32 D_001D4C38;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern s32 D_001D9F28;
extern s32 D_001D9BC8_0038F3F8;
extern s32 func_003E3DF0(void);
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
extern void func_003AEB48(void *, s32);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003A2558(void);
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_00381CA8(s32);
extern void func_00381D70(s32);
extern s32 func_003934B8(s32);
#define ROW_38F3F8 ((E_38F3F8 *)((s32 *)D_001D9EF0_0038F3F8)[D_001D5CAC])
/* localdecomp:start func_00394620 */
typedef struct {
    u8 pad0[0x50];
    s32 x;
    s32 y;
    s32 f58;
    u8 pad5C[0x70 - 0x5C];
    u8 st[2];
    u8 pad72[2];
    s32 sel;
} P_00394620;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 id;
} E_00394620;
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
} __attribute__((aligned(16))) T_00394620;
extern s32 D_001D9EE8[];
extern s32 D_001D9EE8_00394620;
extern E_00394620 **D_001D9EF0_00394620;
extern s32 D_001D5CAC;
extern s32 D_001D5C78;
extern s32 D_001D55E8;
extern s32 D_0031D050[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s32 D_00142DE0[];
extern T_00394620 D_001DAA40_00394620[];
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
extern void func_003AEC40(u8 *, s32, f32);
extern s32 func_00397CA8(void);
extern void func_11B2E8(void *, char *, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00390DB8_00394620(s32, s32, unsigned long, void *, s32);
extern s32 func_00381D80_00394620(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s32 func_00381FF0(s32);
extern s32 func_11B868(u8 *);
extern void func_0038E150(s32);
extern void func_00391308_00394620(u8 *, s32, s32, f32);
extern void func_00390CC8(void);
extern void func_00390CA8(void);
extern void func_00391240_00394620(s32, s32, unsigned long, u8 *, s32, s32, f32);

s32 func_00394620(P_00394620 *p) {
    s32 col;
    char buf[0x50];
    u8 *st;
    T_00394620 t;
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
    func_00393620((S_38EDE8 *)p, &x, &y);
    for (i = 0; i < D_001D9EE8_00394620; i++) {
        if (p->sel == i && D_001D9EF0_00394620[D_001D5CAC][i].f0 != 0 && D_001D5C78 != 0) {
            f32 f = i;
            if (f > 7.0f) {
                f -= 8.0f;
            }
            {
                u8 *h = (u8 *)(D_001D5C78 + 0x1FCA8);
                func_003AEC40(h + 0x18A0, 1, f);
            }
        }
        if (D_001D9EF0_00394620[D_001D5CAC][i].f0 != 0 && D_001D5C78 != 0) {
            *(s32 *)(D_001D5C78 + 0x24DD4) = func_00397CA8() ? (s32)(w * 0.5f) : 0;
        }
    }
    sel = p->sel;
    if (sel >= 0 && D_001D9EF0_00394620[D_001D5CAC][sel].f0 != 0 && D_0031D050[0] == 0) {
        id = D_001D9EF0_00394620[0][sel].id;
        ab = a * b;
        if (D_001DAA40_00394620[D_001425C0[id]].b0 != 0) {
            if (D_001DAA40_00394620[D_001425C0[id]].f84 != 0) {
                n = D_001427F0[id];
                func_11B2E8(buf, D_001D5D60, n);
                {
                    s32 c;
                    u32 al;
                    if (n != 0) {
                        c = func_0038DBD8(0x8066CCFF, 0x8066CCFF, ab);
                    } else {
                        c = func_0038DBD8(0x004040FF, 0x804040FF, ab);
                    }
                    al = c & 0xFF000000;
                    if (al > 0x80000000) {
                        al = 0x80000000;
                    }
                    func_00390DB8_00394620(x + 0x6B, y + 0x79, al, buf, -1);
                    func_00390DB8_00394620(x + 0x69, y + 0x77, c, buf, -1);
                }
            }
            n = D_001DAA40_00394620[D_001425C0[id]].b1;
            cnt = D_001DAA40_00394620[D_001425C0[id]].f68;
            has = n != 0;
            if (cnt != 0 || has) {
                fcnt = cnt;
                fcur = D_00142DE0[id] >> 5;
                frac = 0.0f;
                if (cnt > 0) {
                    if (fcnt != 0.0f) {
                        base = 0;
                        if (n != 0) {
                            func_00381D80_00394620(id, n - 1);
                            base = D_001DAA40_00394620[D_001425C0[id]].f68;
                            func_00381D80_00394620(id, n);
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
                    func_0038AF30(y + r0, y + r1, x + r2, x + r3 + (s32)(frac * 92.0f), 0x706EC8FF);
                }
            }
        }
        split = 0;
        col = func_0038DBD8(0x8066CCFF, 0x8066CCFF, ab);
        t = D_001DAA40_00394620[D_001425C0[D_001D9EF0_00394620[D_001D5CAC][sel].id]];
        str = (u8 *)func_00381FF0(t.msg);
        len = func_11B868(str);
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
            func_0038E150(1);
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
                func_0038E150(0);
                func_00390DB8_00394620(x + 0x6B, D_001D5D80 + yy - 0xE, alpha, (void *)func_00381FF0(msg), -1);
                {
                    s32 o = D_001D5D80 - 0x10;
                    func_00390DB8_00394620(x + 0x69, yy + o, col, (void *)func_00381FF0(msg), -1);
                }
                func_0038E150(1);
            }
            if (split != 0) {
                func_00391308_00394620(str, split, 0x50, 0.8f);
                func_00390CC8();
                func_00391240_00394620(x + 0x6B, yy + D_001D5D80 + 2, alpha, str, split, D_001D5D78, D_001D5D7C);
                func_00390CA8();
                func_00391240_00394620(x + 0x69, yy + D_001D5D80, col, str, split, D_001D5D78, D_001D5D7C);
                yy += 0x10;
                func_00391308_00394620(q, -1, 0x50, 0.8f);
                func_00390CC8();
                func_00391240_00394620(x + 0x6B, yy + D_001D5D80 + 2, alpha, q, -1, D_001D5D78, D_001D5D7C);
                func_00390CA8();
                func_00391240_00394620(x + 0x69, yy + D_001D5D80, col, q, -1, D_001D5D78, D_001D5D7C);
            } else {
                func_00390CC8();
                func_00391240_00394620(x + 0x6B, yy + D_001D5D80 + 2, alpha, str, -1, D_001D5D78, D_001D5D7C);
                func_00390CA8();
                func_00391240_00394620(x + 0x69, yy + D_001D5D80, col, str, -1, D_001D5D78, D_001D5D7C);
            }
            func_0038E150(saved);
        }
    }
    return p->f58;
}
/* localdecomp:end func_00394620 */
