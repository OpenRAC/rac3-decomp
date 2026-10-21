#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00133C58();
extern void func_00133BB8();
/* --- end of declarations from other files --- */

/* localdecomp:start func_00133BB8 */
/* libmpeg/libipu: IPU command word from the sync value; 2.9-ee-991111 */
extern s32 func_00124920(void);
extern void func_00124970_00133BB8(void);
void func_00133BB8(s32 a, s32 b) {
    u32 x;
    s32 ei;

    x = a;
    ei = func_00124920();
    if ((x >> 28) == 7) {
        x &= 0xFFFFFFF;
        x |= 0x80000000;
    } else {
        x &= 0xFFFFFFF;
    }
    *(volatile u32 *)0x1000B010 = x;
    *(volatile s32 *)0x1000B020 = b >> 4;
    *(volatile u32 *)0x1000B000 = 0x100;
    if (ei) {
        func_00124970_00133BB8();
    }
}
/* localdecomp:end func_00133BB8 */

/* localdecomp:start func_00133C58 */
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

int func_00133C58(S_133C58 *s, int a1, int *mbaddr, int *first, int *pred)
{
    int code;
    int v;

    s->f12C = 0;
    func_00134D68(s);
    while (func_00132970(s, 0x18) != 1 && s->f878 == 0) {
        func_00134C00_00133C58(s, 8);
    }
    code = func_00132970(s, 0x20);
    if ((u32)(code - 0x101) >= 0xAF) {
        func_0013A150(s, D_00151DF8, code);
        return 2;
    }
    func_00134D60(s);
    s->f1C4 = func_00132888_00133C58(s, 5);
    if (func_00132888_00133C58(s, 1)) {
        func_00132888_00133C58(s, 1);
        func_00134C00_00133C58(s, 7);
        while (func_00132888_00133C58(s, 1)) {
            func_00134C00_00133C58(s, 8);
        }
    }
    v = func_00132428(s);
    *first = v;
    if (s->f12C) {
        func_0013A0F8(s, D_00151E20);
        return 1;
    }
    *mbaddr = ((code & 0xFF) - 1) * s->f13C + v - 1;
    *first = 1;
    s->f1C0 = 1;
    pred[5] = 0;
    pred[4] = 0;
    pred[1] = 0;
    pred[0] = 0;
    pred[7] = 0;
    pred[6] = 0;
    pred[3] = 0;
    pred[2] = 0;
    return 0;
}
/* localdecomp:end func_00133C58 */

/* localdecomp:start func_00133DF8 */
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

static __inline__ void setfb_133DF8(Fb_133DF8 *f, s32 w, s32 h)
{
    f->f4 = w;
    f->f8 = h;
    f->fC = w >> 4;
    f->f10 = h >> 4;
}

void func_00133DF8(H_133DF8 *hd)
{
    S_133DF8 *q;
    s32 mode;
    s32 w;
    s32 h;
    u32 sz;
    u32 a;
    u32 b;
    u32 c;
    s32 k;
    s32 v;

    q = hd->q;
    mode = q->f858;
    if (mode == 0) {
        q->f184 = 3;
        q->f14C = 1;
        q->f150 = 1;
        q->f198 = 1;
        q->f18C = 1;
        q->f154 = 5;
    }
    q->f13C = (q->f134 + 15) >> 4;
    if (mode != 0 && q->f14C == 0) {
        v = ((q->f138 + 31) >> 5) << 1;
    } else {
        v = (q->f138 + 15) >> 4;
    }
    q->f140 = v;
    h = v << 4;
    w = q->f13C << 4;
    if (w == hd->w && h == hd->h) {
        return;
    }
    k = 0x180;
    hd->w = w;
    hd->h = h;
    sz = (u32)(w * (h * k)) >> 8;
    func_00136000(q->f118);
    q->f10C = func_00136010(q, q->f118, sz, 0x40);
    q->f110 = func_00136010(q, q->f118, sz, 0x40);
    q->f114 = func_00136010(q, q->f118, sz, 0x40);
    if (q->f87C == 0) {
        s32 n;
        a = (q->f10C & 0x0FFFFFFF) | 0x20000000;
        b = (q->f110 & 0x0FFFFFFF) | 0x20000000;
        c = (q->f114 & 0x0FFFFFFF) | 0x20000000;
        n = hd->w * hd->h / 512 * k;
        q->fb[0].f0 = a;
        q->fb[1].f0 = b;
        q->fb[2].f0 = c;
        q->fb[3].f0 = a;
        q->fb[4].f0 = b;
        q->fb[5].f0 = c;
        q->fb[6].f0 = a + n;
        q->fb[7].f0 = b + n;
        q->fb[8].f0 = c + n;
    } else if (q->f87C == 1) {
        s32 n;
        n = hd->w * hd->h / 512 * k;
        q->fb[0].f0 = q->f10C;
        q->fb[1].f0 = q->f110;
        q->fb[2].f0 = q->f114;
        q->fb[3].f0 = q->f10C;
        q->fb[4].f0 = q->f110;
        q->fb[5].f0 = q->f114;
        q->fb[6].f0 = q->f10C + n;
        q->fb[7].f0 = q->f110 + n;
        q->fb[8].f0 = q->f114 + n;
    }
    setfb_133DF8(&q->fb[0], w, h);
    setfb_133DF8(&q->fb[1], w, h);
    setfb_133DF8(&q->fb[2], w, h);
    setfb_133DF8(&q->fb[3], w, h / 2);
    setfb_133DF8(&q->fb[4], w, h / 2);
    setfb_133DF8(&q->fb[5], w, h / 2);
    setfb_133DF8(&q->fb[6], w, h / 2);
    setfb_133DF8(&q->fb[7], w, h / 2);
    setfb_133DF8(&q->fb[8], w, h / 2);
}
/* localdecomp:end func_00133DF8 */
