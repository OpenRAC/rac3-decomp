#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
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

/* localdecomp:start func_001343C0 */
void func_001343C0(u8 *p) {
    *(s32 *)(p + 0xFC) = 0;
    *(s32 *)(p + 0x864) = 1;
    *(s32 *)(p + 0x85C) = *(s32 *)(p + 0x860) + 1;
    func_00132888(p, 1);
    func_00132888(p, 5);
    func_00132888(p, 6);
    func_00132888(p, 1);
    func_00132888(p, 6);
    func_00132888(p, 6);
    *(s32 *)(p + 0x1B4) = func_00132888(p, 1);
    *(s32 *)(p + 0x1B8) = func_00132888(p, 1);
    func_001349F8(p);
}
/* localdecomp:end func_001343C0 */

/* localdecomp:start func_00134460 */
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

void func_00134460(S_134460 *p)
{
    s32 tr;
    s32 flag;
    s32 prev;

    tr = func_00132888(p, 10);
    p->f160 = func_00132888(p, 3);
    func_00132888(p, 16);
    if (p->f160 == 2 || p->f160 == 3) {
        p->f164 = func_00132888(p, 1);
        p->f168 = func_00132888(p, 3);
    }
    if (p->f160 == 3) {
        p->f16C = func_00132888(p, 1);
        p->f170 = func_00132888(p, 3);
    }
    while (func_00132888(p, 1) != 0) {
        func_00134C00(p, 8);
    }
    func_001349F8(p);
    flag = 0;
    prev = 0;
    if (p->f160 != 3 && tr != 0) {
        if (tr < 0) {
            flag = p->f864 == 0;
        }
        p->f864 = 0;
        prev = tr;
    }
    p->f1BC = p->f85C + tr;
    if (flag && prev >= tr) {
        p->f1BC += 0x400;
    }
    p->f860 = (p->f860 < p->f1BC) ? p->f1BC : p->f860;
}
/* localdecomp:end func_00134460 */

/* localdecomp:start func_001345A8 */
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

void func_001345A8(S_1345A8 *s)
{
    u32 v;
    u32 plid;
    u32 hext;
    u32 vext;
    u32 brext;
    u32 vbvext;

    s->f858 = 1;
    *(u32 *)0x10002010 &= ~0x800000;
    v = (u32)func_00132888_001345A8(s, 0x1C);
    brext = (v >> 1) & 0xFFF;
    s->f150 = (v >> 17) & 3;
    vext = (v >> 13) & 3;
    hext = (v >> 15) & 3;
    if (s->f150 != 1) {
        func_0013A0F8(s, D_00151E60);
    }
    s->f14C = (v >> 19) & 1;
    plid = v >> 20;
    vbvext = (u32)func_00132888_001345A8(s, 0x10) >> 8;
    if (plid != 0x48 && plid != 0x58 && plid != 0x44) {
        func_0013A0F8(s, D_00151E88);
    }
    s->f134 = (hext << 12) | (s->f134 & 0xFFF);
    s->f138 = (vext << 12) | (s->f138 & 0xFFF);
    s->f144 += brext << 18;
    s->f148 += vbvext << 10;
}
/* localdecomp:end func_001345A8 */

/* localdecomp:start func_001346E8 */
/* libmpeg: sequence extension flags (two IPU setup commands, two checks); 2.9-ee-991111 */
typedef struct {
    u8 pad0[0x828];
    s32 x828;           /* 0x828 */
    u32 x82C;           /* 0x82C */
    u8 pad830[0x850 - 0x830];
    u32 x850;           /* 0x850 */
    u32 x854;           /* 0x854 */
} S_1346E8;

extern u32 func_00132888();
extern void func_00134BC8(S_1346E8 *);
extern s32 func_0013A0F8();
extern char D_00151EA8[];
extern char D_00151ED0[];

static __inline__ void cmd_1346E8(S_1346E8 *p, u32 cmd) {
    *(volatile u32 *)0x10002000 = cmd;
    p->x82C = cmd & 0xF0000000;
    if (p->x82C == 0x20000000 || p->x82C == 0x30000000 || p->x82C == 0x40000000) {
        p->x828 = 0;
    } else {
        p->x828 = 1;
    }
}

void func_001346E8(S_1346E8 *p) {
    if ((p->x850 = func_00132888(p, 1)) != 0) {
        func_00134BC8(p);
        cmd_1346E8(p, 0x50000000);
        func_00134BC8(p);
    }
    if ((p->x854 = func_00132888(p, 1)) != 0) {
        func_00134BC8(p);
        cmd_1346E8(p, 0x58000000);
        func_00134BC8(p);
    }
    if (func_00132888(p, 1) != 0) {
        func_0013A0F8(p, D_00151EA8);
    }
    if (func_00132888(p, 1) != 0) {
        func_0013A0F8(p, D_00151ED0);
    }
}
/* localdecomp:end func_001346E8 */
