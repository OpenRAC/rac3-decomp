#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;

/* localdecomp:start func_L07_003BAC00 */
s32 func_L07_003BAC00(u8 *self, s32 key) {
    u8 *s = *(u8 **)(self + 0x68);
    s32 i;

    if (self[0x20] != 3) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (*(s32 *)(s + 0x20 + i * 4) == key) {
            return (s[0xAF] >> i) & 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003BAC00 */

/* localdecomp:start func_L07_003BAC58 */
extern s32 func_L07_003BCDC0(void *);
extern s32 func_L07_003C97D0(void *);
extern s32 func_L07_003BEAB0(void *);
extern s32 func_L07_003B05A0(void *);
extern s32 func_L07_00351230(void *);
extern s32 func_L07_003CCE58(void *);

/* localdecomp:start func_L07_003BAC58 */
s32 func_L07_003BAC58(u8 *arg0) {
    switch (*(s16 *)(arg0 + 0xAA)) {
    case 0x1A85:
    case 0x19D2:
    case 0x1D88:
        return func_L07_003BCDC0(arg0);
    case 0x19BD:
    case 0x1ADB:
    case 0x1D8A:
        return func_L07_003C97D0(arg0);
    case 0x19BE:
    case 0x1A9B:
    case 0x1D89:
        return func_L07_003BEAB0(arg0);
    case 0x19DA:
        return func_L07_003B05A0(arg0);
    case 0x161E:
        return func_L07_00351230(arg0);
    case 0x1769:
    case 0x1B36:
    case 0x1D8B:
        return func_L07_003CCE58(arg0);
    }
    return 1;
}
/* localdecomp:end func_L07_003BAC58 */
/* localdecomp:end func_L07_003BAC58 */

/* localdecomp:start func_L07_003BADA8 */
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458;
__asm__(".extern D_L07_001DF458, 16");
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");

s32 func_L07_003BAC58(u8 *e);

s32 func_L07_003BADA8(s32 id) {
    u16 *p;
    u8 *e;

    p = D_L07_0021C020[id];
    if ((id & 0xFF) != 0xFF && id <= D_L07_001DF458 && p != 0) {
        do {
            e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
            if (e == 0) {
                break;
            }
            if (func_L07_003BAC58(e) == 0) {
                return 0;
            }
            p++;
            if ((id & 0xFF) == 0xFF || id > D_L07_001DF458 || p == 0) {
                break;
            }
        } while ((s16)p[-1] >= 0 || p == D_L07_0021C020[id]);
    }
    return 1;
}
/* localdecomp:end func_L07_003BADA8 */

/* localdecomp:start func_L07_003BAEA0 */
u8 *func_L07_003BAEA0(u8 *a0) {
    u8 *s;

    switch (*(s16 *)(a0 + 0xAA)) {
    case 0x1A85:
    case 0x19D2:
    case 0x1D88:
        s = *(u8 **)(a0 + 0x68);
        return s + 0x240;
    case 0x19BD:
    case 0x1ADB:
    case 0x1D8A:
        s = *(u8 **)(a0 + 0x68);
        return s + 0x440;
    default:
        return 0;
    }
}
/* localdecomp:end func_L07_003BAEA0 */

/* localdecomp:start func_L07_003BAF28 */
extern u16 *D_L07_0021C020[];
extern s32 D_001DF458_sda;
__asm__(".extern D_001DF458_sda, 4");
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");

u8 *func_L07_003BAEA0(u8 *a0);

s32 func_L07_003BAF28(u8 *a0) {
    s16 best;
    u16 *p;
    u8 *e;
    u8 *v;
    s16 h;

    h = *(s16 *)(func_L07_003BAEA0(a0) + 0x20);
    if (h != -1) {
        return h;
    }
    best = 0;
    p = D_L07_0021C020[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_001DF458_sda && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L07_0021C020[a0[0x21]])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        if (e != a0) {
            v = func_L07_003BAEA0(e);
            if (*(s16 *)(v + 0x20) >= best) {
                best = *(u16 *)(v + 0x20) + 1;
            }
        }
        p++;
    }
    return best;
}
/* localdecomp:end func_L07_003BAF28 */

/* localdecomp:start func_L07_003BB038 */
extern u8 *func_L07_003BAEA0(u8 *);
extern u16 *D_L07_0021C020[];
extern s32 D_001DF458_sda;
__asm__(".extern D_001DF458_sda, 4");
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");

void func_L07_003BB038(u8 *self) {
    u8 *s;
    u16 *p;
    u8 *e;
    u8 *q;

    s = func_L07_003BAEA0(self);
    if (*(s16 *)(s + 0x20) == -1) {
        return;
    }
    p = D_L07_0021C020[self[0x21]];
    while (self[0x21] != 0xFF && self[0x21] <= D_001DF458_sda && p != 0) {
        if ((s16)p[-1] < 0 && p != D_L07_0021C020[self[0x21]]) {
            break;
        }
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        if (e != self) {
            q = func_L07_003BAEA0(e);
            if (*(s16 *)(q + 0x20) >= *(s16 *)(s + 0x20)) {
                *(u16 *)(q + 0x20) = *(u16 *)(q + 0x20) - 1;
            }
        }
        p++;
    }
    *(s16 *)(s + 0x20) = -1;
}
/* localdecomp:end func_L07_003BB038 */

/* localdecomp:start func_L07_003BB148 */
void func_003A4F28(u32);
int func_L01_004AA710(int, int);

void func_L07_003BB148(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_L01_004AA710(arg0, var_s0) != 0) {
            func_003A4F28(var_s0);
        }
        var_s0 += 1;
    } while (var_s0 < 0x34);
}
/* localdecomp:end func_L07_003BB148 */

/* localdecomp:start func_L07_003BB1A8 */
extern P_003BB1F0 *func_00382348(u8 *);

void func_L07_003BB1A8(u8 *arg0) {
    u8 *p = (u8 *)func_00382348(arg0);
    u16 h;

    p[0xE] = 1;
    p[0x30] = 0;
    p[0x2F] = 0;
    p[0x2E] = 0;
    h = *(u16 *)(arg0 + 0x34);
    h &= 0xFFF9;
    *(u16 *)(arg0 + 0x34) = h;
}
/* localdecomp:end func_L07_003BB1A8 */

/* localdecomp:start func_L07_003BB1F0 */
extern P_003BB1F0 *func_00382348(u8 *);
extern u8 *func_L01_00448FF0(u8 *);
extern u8 *func_L01_00449020(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_L07_003BB148(s32);
extern u8 *D_001DE508;

void func_L07_003BB1F0(u8 *arg0) {
    P_003BB1F0 *q;
    u8 *r;
    u8 *s;
    u8 *p;
    u8 *g;
    u16 h;

    q = func_00382348(arg0);
    q->f0 = (f32)q->h4;
    r = func_L01_00448FF0(arg0);
    if (r != 0) {
        *(s16 *)(r + 0x38) = 0;
        *(u8 *)(r + 7) = 0;
        *(u8 *)(r + 9) = 0;
        *(u8 *)(r + 8) = 0;
    }
    s = func_L01_00449020(arg0);
    *(s16 *)(s + 0x14) = 0;
    func_L07_003BB148((s32)arg0);
    h = *(u16 *)(arg0 + 0x34);
    *(u8 *)(arg0 + 0x7F) = 0;
    *(u8 *)(arg0 + 0xA8) = 0xFF;
    *(s32 *)(arg0 + 0x98) = 0;
    *(u16 *)(arg0 + 0x34) = (h | 0x41) & 0xEFFF;
    func_L01_004AA7E8(arg0, 1);
    h = *(u16 *)(arg0 + 0x34) | 6;
    g = D_001DE508;
    *(u16 *)(arg0 + 0x34) = h;
    p = *(u8 **)(g + 0x68);
    *(u16 *)(p + 0xAC) += 1;
}
/* localdecomp:end func_L07_003BB1F0 */
