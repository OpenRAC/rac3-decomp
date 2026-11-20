#include "common.h"

/* localdecomp:start func_L39_00620AF8 */
typedef struct { u8 pad0[0x1A14]; u8 f1A14; } O_00620AF8;
extern s32 func_L39_006626C8_00620AF8(void *, s32);
extern s32 func_L39_006625A8(void *, s32, s32, s32);
extern void func_L39_00662AA0(s32, void *, s32);

void func_L39_00620AF8(O_00620AF8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 buf;
    s32 h;
    if (arg0->f1A14 != 0) {
        if (arg2 != 0) {
            if (func_L39_006626C8_00620AF8(arg0, 8) == 0) {
                h = func_L39_006625A8(arg0, 8, 0, 0);
                buf = arg1;
                func_L39_00662AA0(h, &buf, 1);
                buf = arg3;
                func_L39_00662AA0(h, &buf, 1);
            }
        } else {
            if (func_L39_006626C8_00620AF8(arg0, 6) == 0) {
                h = func_L39_006625A8(arg0, 6, 0, 0);
                buf = arg1;
                func_L39_00662AA0(h, &buf, 1);
                buf = arg3;
                func_L39_00662AA0(h, &buf, 1);
            }
        }
    }
}
/* localdecomp:end func_L39_00620AF8 */

/* localdecomp:start func_L39_00620BE8 */
void func_L01_00443EA0(s32, s32);

void func_L39_00620BE8(void) {
    func_L01_00443EA0(0x18CB, 0x171C);
    func_L01_00443EA0(0x18CC, 0x171C);
    func_L01_00443EA0(0x18CF, 0x171C);
    func_L01_00443EA0(0x18CD, 0x171C);
    func_L01_00443EA0(0x1ADC, 0x171C);
    func_L01_00443EA0(0x16DB, 0x171C);
    func_L01_00443EA0(0x1CFC, 0x171C);
    func_L01_00443EA0(0x1E68, 0x171C);
    func_L01_00443EA0(0x1E07, 0x171C);
    func_L01_00443EA0(0x1CFB, 0x171C);
    func_L01_00443EA0(0x1E77, 0x171C);
    func_L01_00443EA0(0x1E78, 0x171C);
    func_L01_00443EA0(0x1CFD, 0x171C);
    func_L01_00443EA0(0x1CFE, 0x171C);
    func_L01_00443EA0(0x1E4C, 0x171C);
    func_L01_00443EA0(0x1E65, 0x171C);
    func_L01_00443EA0(0x1E4D, 0x171C);
    func_L01_00443EA0(0x1E69, 0x171C);
    func_L01_00443EA0(0x1E59, 0x171C);
    func_L01_00443EA0(0x1E7A, 0x171C);
    func_L01_00443EA0(0x1E83, 0x171C);
}
/* localdecomp:end func_L39_00620BE8 */

/* localdecomp:start func_L39_00620CF8 */
typedef struct {
    u8 pad0[30];
    s16 h30;
    u8 pad32[33 - 32];
    s8 b33;
    u8 pad34[128 - 34];
} Ent_00620CF8;
typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00620CF8;
extern Ent_00620CF8 D_L39_0049C890[];
extern u8 D_L39_00483A00[];
extern s32 func_L39_00648AE0(u8 *, s32);

s16 func_L39_00620CF8(u8 *p, s32 i) {
    Ent_00620CF8 *e;
    Buf_00620CF8 buf;
    u8 *t;
    u8 *q;
    u8 *d;
    u16 r;
    u32 a;
    u32 b;
    s32 n, k, m, j;

    if (i == -1) {
        i = *(s32 *)(p + 0x478);
    }
    if (func_L39_00648AE0(p, i)) {
        e = &D_L39_0049C890[D_L39_0049C890[i].b33];
    } else {
        e = &D_L39_0049C890[i];
    }
    if (e->h30 == 0) {
        return 1;
    }
    t = (u8 *)(i + (u32)p);
    t += 0x1A52;
    q = t;
    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (j = 0; j < 24; j += 3) {
            *d++ = D_L39_00483A00[((k + j) & 7) * 209 + m];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
        r = buf.h[2];
    }
    return r;
}
/* localdecomp:end func_L39_00620CF8 */
