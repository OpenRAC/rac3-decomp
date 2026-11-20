#include "common.h"
#include "cpu.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern int func_00121760();
/* --- end of declarations from other files --- */

/* declarations of 133BB8.c's earlier functions (tools/port_from_us.py) */
extern s32 func_00124920(void);
extern void func_00124970_00133BB8(void);
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x1C0 - 0x140];
    int f1C0;
    int f1C4;
    u8 pad1C8[0x878 - 0x1C8];
    int f878;
} S_133C58;
void func_00134D68(void *s);
void func_00134D60(void *s);
int func_00132970(void *s, int n);
int func_00132888_00133C58(void *s, int n);
void func_00134C00_00133C58(void *s, int n);
int func_00132428(void *s);
void func_0013A150(void *s, char *fmt, int x);
extern s32 func_0013A0F8();
extern char D_00151DF8[];
extern char D_00151E20[];
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x68 - 0x14];
} Fb_133DF8;
typedef struct {
    u8 pad0[0x10C];
    u32 f10C;
    u32 f110;
    u32 f114;
    s32 f118[3];
    s32 f124;
    u8 pad128[0x134 - 0x128];
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 f140;
    u8 pad144[0x14C - 0x144];
    s32 f14C;
    s32 f150;
    s32 f154;
    u8 pad158[0x184 - 0x158];
    s32 f184;
    s32 f188;
    s32 f18C;
    u8 pad190[0x198 - 0x190];
    s32 f198;
    u8 pad19C[0x1F8 - 0x19C];
    Fb_133DF8 fb[9];
    u8 pad5A0[0x858 - 0x5A0];
    s32 f858;
    u8 pad85C[0x87C - 0x85C];
    s32 f87C;
} S_133DF8;
typedef struct {
    s32 w;
    s32 h;
    u8 pad8[0x40 - 8];
    S_133DF8 *q;
} H_133DF8;
extern void func_00136000();
extern u32 func_00136010();
typedef struct {
    u8 pad0[0x160];
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    u8 pad174[0x1BC - 0x174];
    s32 f1BC;
    u8 pad1C0[0x85C - 0x1C0];
    s32 f85C;
    s32 f860;
    s32 f864;
} S_134460;
extern u32 func_00132888();
extern void func_00134C00();
extern void func_001349F8();
typedef struct {
    u8 pad0[0x134];
    u32 f134;
    u32 f138;
    u8 pad13C[0x144 - 0x13C];
    int f144;
    int f148;
    int f14C;
    int f150;
    u8 pad154[0x858 - 0x154];
    int f858;
} S_1345A8;
extern char D_00151E60[];
extern char D_00151E88[];
int func_00132888_001345A8(void *s, int n);
extern s32 func_0013A0F8();
typedef struct {
    u8 pad0[0x828];
    s32 x828;           
    u32 x82C;           
    u8 pad830[0x850 - 0x830];
    u32 x850;           
    u32 x854;           
} S_1346E8;
extern u32 func_00132888();
extern void func_00134BC8(S_1346E8 *);
extern s32 func_0013A0F8();
extern char D_00151EA8[];
extern char D_00151ED0[];
typedef struct { u8 pad[0x878]; s32 x878; } S_1349F8;
typedef struct { void (*f[11])(S_1349F8 *); } T_1349F8;
extern void func_00134D68_001349F8(S_1349F8 *);
extern void func_00134D60_001349F8(S_1349F8 *);
extern void func_00134C00_001349F8(S_1349F8 *, s32);
extern s32 func_00132970_001349F8(S_1349F8 *, s32);
extern u32 func_00132888_001349F8(S_1349F8 *, s32);
extern u8 D_00151FB8[];
typedef struct {
    u8 pad0[0x160];
    s32 f160;
    u8 pad164[0x838 - 0x164];
    long f838;
    long f840;
    u8 pad848[0x868 - 0x848];
    s32 f868;
    u8 pad86C[0x878 - 0x86C];
    s32 f878;
} S_134C08;
typedef struct {
    s32 type;
    s32 pad4;
    long f8;
    long f10;
} Cb_134C08;
extern void func_00134D68_00134C08();
extern void func_00134C00();
extern s32 func_00132970_00134C08();
extern u32 func_00132888();
extern void func_00134110();
extern void func_001343C0();
extern void func_00134460();
extern s32 func_00135D50(s32, s32 *);
extern u32 func_00132888();
typedef struct {
    u8 pad[0x154];
    s32 f154;
    s32 f158;
    s32 f15C;
} S_134DB8;
typedef struct {
    u8 pad0[0x14C];
    s32 f14C;
    u8 pad150[0x184 - 0x150];
    s32 f184;
    s32 f188;
    u8 pad18C[0x194 - 0x18C];
    s32 f194;
    u8 pad198[0x19C - 0x198];
    s32 hoff[3];
    s32 voff[3];
} S_134EE0;
extern u32 func_00132888();
typedef struct {
    u8 pad0[0x68];
} Fb_1350A8;
typedef struct {
    Fb_1350A8 *a;
    Fb_1350A8 *b;
    s32 pad;
    Fb_1350A8 *c;
} G_1350A8;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[0x18 - 0x10];
    s32 f18;
    u8 pad1C[0x24 - 0x1C];
    s32 (*f24)();
    u8 pad28[0x30 - 0x28];
    s32 (*f30)();
    u8 pad34[0x3C - 0x34];
    s32 f3C;
    u8 pad40[0x48 - 0x40];
    s32 f48;
    u8 pad4C[0x54 - 0x4C];
    s32 f54;
    u8 pad58[0x60 - 0x58];
    s32 f60;
    s32 f64;
    u8 pad68[0x8C - 0x68];
    s32 f8C;
    long f90;
    s32 f98;
    s32 f9C;
    long fA0;
    s32 fA8;
    s32 fAC;
    s32 fB0;
    u8 padB4[0xC0 - 0xB4];
    s32 fC0;
    s32 fC4;
    s32 fC8[14];
    long f100;
    s32 f108;
    s32 f10C;
    s32 f110;
    s32 f114;
    s32 f118[4];
    u8 pad128[0x1C8 - 0x128];
    G_1350A8 g[3];
    Fb_1350A8 fb[9];
    u8 pad5A0[0x85C - 0x5A0];
    s32 f85C;
    s32 f860;
    s32 f864;
    void *f868;
} D_1350A8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 padC[0x10 - 0xC];
    long f10;
    long f18;
    long f20;
    long f28;
    long f30;
    long f38;
    D_1350A8 *f40;
} M_1350A8;
extern char D_00152058[];
extern char D_00152008[];
extern char D_00152030[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_0013A0F8();
extern s32 func_0013A150_001350A8(void *, char *, ...);
extern void func_00135FD8();
extern u32 func_00136010();
extern void func_00134FD8();
extern s32 func_00135C60();
extern s32 func_00135E88();
extern s32 func_00135FF0();
extern s32 func_00136080();
extern s32 func_001360A8();

/* localdecomp:start func_001352E0 */
typedef struct {
    u8 pad0[0x1C0];
    s32 f1C0;
    u8 pad1C4[0x828 - 0x1C4];
    s32 f828;
} Ctx_1352E0;

void func_001352E0(Ctx_1352E0 *p)
{
    extern void func_0013A4B8();
    s32 di;

    p->f828 = 1;
    p->f1C0 = 0;
    di = func_00124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000B400 = 0;
    *(volatile u32 *)0x1000D400 = 0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (di) {
        func_00124970_00133BB8();
    }
    *(volatile u32 *)0x1000B020 = 0;
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000D420 = 0;
    *(volatile u32 *)0x10002010 = 0x40000000;
    func_0013A4B8(0, 0);
}
/* localdecomp:end func_001352E0 */

/* localdecomp:start func_001353A8 */
typedef struct {
    s32 f0;
    u8 pad4[0xA8 - 4];
    s32 fA8;
    s32 fAC;
    s32 fB0;
    s32 fB4;
    s32 fB8;
    s32 fBC;
    u8 padC0[0xE8 - 0xC0];
    s32 fE8;
    u32 fEC;
    u8 padF0[0x184 - 0xF0];
    s32 f184;
    u8 pad188[0x834 - 0x188];
    s32 f834;
    u8 pad838[0x858 - 0x838];
    s32 f858;
    u8 pad85C[0x878 - 0x85C];
    s32 f878;
} C_1353A8;
typedef struct {
    u8 pad0[0x40];
    C_1353A8 *x40;
} O_1353A8;
extern char D_00152080[];
extern char D_001520C0[];
extern char D_00152100[];

s32 func_001353A8(O_1353A8 *o)
{
    extern s32 func_00134C08();
    extern s32 func_00135E40();
    extern s32 func_00136A40();
    C_1353A8 *c;
    s32 ret;
    s32 st;

    ret = 0;
    st = 1;
    c = o->x40;
    c->f0 = 0;
    if (c->fEC & 0x3F) {
        func_0013A150(c, D_00152080, c->fEC);
        return -1;
    }
    if (c->f878) {
        func_00121760(D_001520C0);
        return -1;
    }
    c->f834 = 0;
    do {
        if (ret != -1) {
            do {
                st = func_00134C08(c);
                if (st < 0) {
                    return -1;
                }
                if (st == 0) {
                    break;
                }
                if (c->f184 == c->fE8) {
                    break;
                }
            } while (c->f858 != 0);
        }
        switch (st) {
        case 0:
            func_00136A40(o);
            c->f0 = 1;
            break;
        case 1:
            c->fBC = 0;
            c->fB8 = 0;
            c->fB4 = 0;
            ret = func_00135E40(o, 0, c->fA8);
            c->fB4++;
            break;
        case 2:
            ret = func_00135E40(o, c->fB8, c->fAC);
            c->fB8++;
            break;
        case 3:
        case 4:
            ret = func_00135E40(o, c->fBC, c->fB0);
            c->fBC++;
            break;
        }
        if (c->f878) {
            func_00121760(D_00152100);
            return -1;
        }
        if (c->f834) {
            return 1;
        }
    } while (c->f0 == 0);
    return 1;
}
/* localdecomp:end func_001353A8 */

/* localdecomp:start func_00135560 */
typedef struct Rec_00135560 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ long v18;
    /* 0x20 */ long v20;
    /* 0x28 */ s32 state;
    /* 0x2C */ s32 f2C;
    /* 0x30 */ s32 f30;
    /* 0x34 */ s32 f34;
    /* 0x38 */ s32 f38;
    /* 0x3C */ s32 f3C;
    /* 0x40 */ s32 f40;
    /* 0x44 */ s32 f44;
    /* 0x48 */ s32 f48;
    /* 0x4C */ s32 f4C;
    /* 0x50 */ s32 f50;
    /* 0x54 */ s32 f54;
    /* 0x58 */ s32 f58;
    /* 0x5C */ s32 f5C;
    /* 0x60 */ s32 f60;
} Rec_00135560;

typedef struct Obj_00135560 {
    /* 0x000 */ u8 pad0[0xB4];
    /* 0x0B4 */ s32 cntA;
    /* 0x0B8 */ s32 cntB;
    /* 0x0BC */ u8 pad1[0xFC - 0xBC];
    /* 0x0FC */ s32 flagFC;
    /* 0x100 */ u8 pad2[0x14C - 0x100];
    /* 0x14C */ s32 f14C;
    /* 0x150 */ u8 pad3[0x158 - 0x150];
    /* 0x158 */ s32 f158;
    /* 0x15C */ s32 f15C;
    /* 0x160 */ s32 mode;
    /* 0x164 */ u8 pad4[0x184 - 0x164];
    /* 0x184 */ s32 type;
    /* 0x188 */ s32 f188;
    /* 0x18C */ u8 pad5[0x194 - 0x18C];
    /* 0x194 */ s32 f194;
    /* 0x198 */ s32 f198;
    /* 0x19C */ s32 f19C;
    /* 0x1A0 */ s32 f1A0;
    /* 0x1A4 */ s32 f1A4;
    /* 0x1A8 */ s32 f1A8;
    /* 0x1AC */ s32 f1AC;
    /* 0x1B0 */ s32 f1B0;
    /* 0x1B4 */ s32 flag1B4;
    /* 0x1B8 */ s32 flag1B8;
    /* 0x1BC */ u8 pad6[0x1C8 - 0x1BC];
    /* 0x1C8 */ Rec_00135560 *r1C8;
    /* 0x1CC */ Rec_00135560 *r1CC;
    /* 0x1D0 */ Rec_00135560 *r1D0;
    /* 0x1D4 */ Rec_00135560 *r1D4;
    /* 0x1D8 */ Rec_00135560 *r1D8;
    /* 0x1DC */ Rec_00135560 *r1DC;
    /* 0x1E0 */ Rec_00135560 *r1E0;
    /* 0x1E4 */ Rec_00135560 *r1E4;
    /* 0x1E8 */ Rec_00135560 *r1E8;
    /* 0x1EC */ Rec_00135560 *r1EC;
    /* 0x1F0 */ Rec_00135560 *r1F0;
    /* 0x1F4 */ Rec_00135560 *r1F4;
    /* 0x1F8 */ u8 pad7[0x838 - 0x1F8];
    /* 0x838 */ long v838;
    /* 0x840 */ long v840;
} Obj_00135560;

s32 func_00135560(Obj_00135560 *p, s32 arg1) {
    Rec_00135560 *rec;
    s32 ret;
    s32 n;
    Rec_00135560 *tmp;
    Rec_00135560 *cur;
    s32 type;
    s32 mode;

    rec = 0;
    ret = 0;
    type = p->type;
    mode = p->mode;
    n = (type == 3) ? 2 : 4;
    if (mode == 3) {
        p->r1D0 = p->r1D4;
        p->r1E0 = p->r1E4;
        p->r1F0 = p->r1F4;
        if (p->cntA + p->cntB >= n) {
            p->flagFC = 0;
            p->flag1B8 = 0;
            p->flag1B4 = 0;
        }
        if ((p->flagFC != 0 || p->flag1B8 != 0) && p->flag1B4 == 0) {
            Rec_00135560 *ra = p->r1C8;
            Rec_00135560 *rb = p->r1D8;
            Rec_00135560 *rc;
            ra->state = 0;
            rc = p->r1E8;
            rb->state = 0;
            rc->state = 0;
            type = p->type;
        }
        p->flagFC = 0;
        p->flag1B8 = 0;
        if (type == 3) {
            if (p->r1C8->state == 1 || p->flag1B4 != 0) {
                if (p->r1CC->state == 1) {
                    ret = 1;
                }
            }
        } else {
            if ((p->r1D8->state == 1 && p->r1E8->state == 1) || p->flag1B4 != 0) {
                if (p->r1DC->state == 1) {
                    if (p->r1EC->state == 1) {
                        ret = 1;
                    }
                }
            }
        }
    } else {
        if (arg1 == 0) {
            tmp = p->r1C8;
            p->r1C8 = p->r1CC;
            p->r1CC = tmp;
            tmp = p->r1D8;
            p->r1D8 = p->r1DC;
            p->r1DC = tmp;
            tmp = p->r1E8;
            p->r1E8 = p->r1EC;
            p->r1EC = tmp;
        }
        p->r1D0 = p->r1CC;
        p->r1E0 = p->r1DC;
        p->r1F0 = p->r1EC;
        if (type == 3) {
            if (mode != 2 || p->r1C8->state == 1) {
                ret = 1;
            }
        } else {
            cur = (type == 1) ? p->r1F0 : p->r1E0;
            if (mode != 2 || (arg1 != 0 && cur->state == 1) ||
                (p->r1D8->state == 1 && p->r1E8->state == 1)) {
                ret = 1;
            }
        }
    }
    switch (type) {
    case 3:
        rec = p->r1D0;
        break;
    case 1:
        rec = p->r1E0;
        break;
    case 2:
        rec = p->r1F0;
        break;
    }
    rec->state = 0;
    {
        long la = p->v838;
        s32 sa = p->mode;
        rec->v18 = la;
        rec->f2C = sa;
    }
    {
        long lb = p->v840;
        s32 sb = p->type;
        rec->v20 = lb;
        rec->f30 = sb;
    }
    rec->f34 = p->f14C;
    rec->f38 = p->f198;
    rec->f3C = p->f188;
    rec->f40 = p->f194;
    rec->f44 = p->f19C;
    rec->f48 = p->f1A0;
    rec->f4C = p->f1A4;
    rec->f50 = p->f1A8;
    rec->f54 = p->f1AC;
    rec->f58 = p->f1B0;
    rec->f5C = p->f158;
    rec->f60 = p->f15C;
    return ret;
}
/* localdecomp:end func_00135560 */

/* localdecomp:start func_00135818 */
typedef struct Ctx_135818 {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    u8 padC[0x18 - 0xC];
    s32 (*fn)(void *, s32 *, s32);
    s32 pad1C;
    s32 gp;
    u8 pad24[0xC0 - 0x24];
    s32 fC0;
    u8 padC4[0x128 - 0xC4];
    s32 f128;
    s32 pad12C;
    s32 f130;
    u8 pad134[0x184 - 0x134];
    s32 f184;
    u8 pad188[0x878 - 0x188];
    s32 f878;
} Ctx_135818;
typedef struct S_135818 {
    u8 pad0[8];
    s32 f8;
    u8 padC[0x40 - 0xC];
    Ctx_135818 *ctx;
} S_135818;

s32 func_00135818(S_135818 *s, s32 b, s32 c) {
    extern s32 func_00135F08(Ctx_135818 *);
    extern void func_00136B00(Ctx_135818 *, s32, s32);
    Ctx_135818 *ctx = s->ctx;
    s32 r16 = 0;
    s32 r19;
    s32 loc[8];

    if (c == -1 || b < c) {
        if (ctx->f8 == 0) {
            s->f8 = 0;
            ctx->f8 = 1;
        }
        {
            s32 v;
            s32 t = func_00135560((Obj_00135560 *)ctx, 0);
            v = 0;
            if (t != 0) {
                v = func_00135F08(ctx) != 0;
            }
            r19 = v;
        }
    } else {
        r19 = func_00135560((Obj_00135560 *)ctx, 0);
        loc[0] = 1;
        if (s != 0) {
            Ctx_135818 *t = s->ctx;
            if (t != 0) {
                s32 (*fn)(void *, s32 *, s32) = t->fn;
                if (fn != 0) {
                    s32 old;
                    s32 cur;
                    s32 r;
                    old = (s32)CpuSwapGp((void *)t->gp);
                    r = fn(s, loc, *(s32 *)((u8 *)t + loc[0] * 12 + 0x10));
                    cur = (s32)CpuSwapGp((void *)old);
                }
            }
        }
        r16 = 1;
    }
    if (ctx->f878 != 0) {
        return 0;
    }
    func_00136B00(ctx, ctx->f128, ctx->f4);
    if (ctx->f184 != 3 && r16 == 0) {
        ctx->f130 = ctx->f130 == 0;
    }
    s->f8 = ctx->f128 - ctx->fC0;
    if (ctx->f130 == 0) {
        ctx->f128 += 1;
        ctx->f4 += 1;
    }
    return r19;
}
/* localdecomp:end func_00135818 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135988);

/* localdecomp:start func_00135B50 */
extern s32 func_00124970(void);
extern void func_0013A598(void);
s32 func_00135B50(void) {
    s32 s = func_00124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 &= 0xFFFFFEFF;
    *(volatile u32 *)0x1000B400 &= 0xFFFFFEFF;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (s) {
        func_00124970();
    }
    *(volatile u32 *)0x1000B020 = 0;
    *(volatile u32 *)0x1000B420 = 0;
    func_0013A598();
    return 1;
}
/* localdecomp:end func_00135B50 */

/* localdecomp:start func_00135C00 */
s32 func_00135C00(void) {
    return 1;
}
/* localdecomp:end func_00135C00 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00135C08);
