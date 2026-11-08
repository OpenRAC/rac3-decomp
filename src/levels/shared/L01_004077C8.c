#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004077C8);

/* localdecomp:start func_L01_004077D0 */
extern char D_L01_001E6F60[];
extern int D_L01_001DF9FC;
extern void func_0038CB78(void *, int, int);
void func_L01_004077D0(void) {
    func_0038CB78(D_L01_001E6F60, 0, 1536);
    D_L01_001DF9FC = 0;
}
/* localdecomp:end func_L01_004077D0 */

LINKER_REMNANT("asm/levels", func_L01_00407800);

/* localdecomp:start func_L01_00407808 */
extern char D_L01_001E6F60[];
typedef struct {
    u8 pad0[16];
    s32 w16;
    s32 w20;
    u8 pad1[4];
    s32 w28;
    u16 h32;
    u16 h34;
    u16 h36;
    u16 h38;
    u8 pad2[8];
} S405438;

extern s32 D_L01_001DF9FC;

s32 func_L01_00407808(s32 idx, u16 a, u16 b, u16 c, u16 d, s32 e, s32 f) {
    S405438 *s;
    s32 i;

    if (idx < 0) {
        for (i = 0; i < 32; i++) {
            if (!(((S405438 *)&D_L01_001E6F60)[i].w28 & 5)) {
                idx = i;
            }
        }
        if (idx < 0) {
            return -1;
        }
    }
    D_L01_001DF9FC++;
    s = &((S405438 *)&D_L01_001E6F60)[idx];
    s->h32 = a;
    s->h34 = b;
    s->h36 = c;
    s->h38 = d;
    s->w20 = e;
    s->w28 = 5;
    s->w16 = f;
    return idx;
}
/* localdecomp:end func_L01_00407808 */

LINKER_REMNANT("asm/levels", func_L01_004078A8);

/* localdecomp:start func_L01_004078B0 */
extern char D_L01_001E6F60[];
typedef struct {
    u8 pad0[16];
    f32 *w16;
    u32 w20;
    u8 pad1[4];
    s32 w28;
    s16 h32;
    s16 h34;
    s16 h36;
    s16 h38;
    u8 pad2[8];
} S4054E0;


void func_L01_004078B0(u32 *buf, s32 idx) {
    S4054E0 *s = &((S4054E0 *)&D_L01_001E6F60)[idx];
    s32 n = s->h36 * s->h38;
    s32 count = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (s->w20 < (buf[i] & 0xFFFFFF)) {
            count++;
        }
    }
    *(&((S4054E0 *)&D_L01_001E6F60)[idx])->w16 = (f32)(n - count) / (f32)n;
}
/* localdecomp:end func_L01_004078B0 */

/* localdecomp:start func_L01_00407950 */
typedef struct {
    u8 pad0[0x1C];
    s32 flags;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u8 pad28[8];
} S_407950;

extern u8 *D_L01_001E1060[];
extern s32 D_L01_001E1074;
extern void func_L01_00415C18(s32, s32, s32, s32, u8 *);
extern void func_0012A9F0(s32, s32);

/* from rac2-decomp's func_00280710 */
void func_L01_00407950(void) {
    u8 *buffers[2];
    s32 current;
    s32 next;
    s32 i;
    s32 index;
    if (D_L01_001DF9FC == 0) {
        return;
    }
    buffers[0] = D_L01_001E1060[1 - D_L01_001E1074];
    buffers[1] = buffers[0] + 0x40000;
    current = 0;
    next = -1;
    for (i = 31; i >= 0; i--) {
        if (((S_407950 *)D_L01_001E6F60)[i].flags & 4) {
            next = i;
            func_L01_00415C18(((S_407950 *)D_L01_001E6F60)[i].x, ((S_407950 *)D_L01_001E6F60)[i].y, ((S_407950 *)D_L01_001E6F60)[i].w, ((S_407950 *)D_L01_001E6F60)[i].h, buffers[current]);
            func_0012A9F0(0, 0);
        }
    }
    if (next == -1) {
        return;
    }
    index = next;
    while (index >= 0) {
        current = 1 - current;
        next = -1;
        for (i = index - 1; i >= 0; i--) {
            if (((S_407950 *)D_L01_001E6F60)[i].flags & 4) {
                next = i;
                func_L01_00415C18(((S_407950 *)D_L01_001E6F60)[i].x, ((S_407950 *)D_L01_001E6F60)[i].y, ((S_407950 *)D_L01_001E6F60)[i].w, ((S_407950 *)D_L01_001E6F60)[i].h, buffers[current]);
            }
        }
        func_L01_004078B0(buffers[1 - current], index);
        if (((S_407950 *)D_L01_001E6F60 + index)->flags & 1) {
            ((S_407950 *)D_L01_001E6F60 + index)->flags &= ~5;
            D_L01_001DF9FC--;
        }
        if (next >= 0) {
            func_0012A9F0(0, 0);
        }
        index = next;
    }
}
/* localdecomp:end func_L01_00407950 */

/* localdecomp:start func_L01_00407B38 */
extern void func_003A9440(s32, unsigned long);
extern void func_L01_00407B38();

extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern s32 D_001A1ED8[];
void func_L01_00407B38(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_L01_00407B38 */
