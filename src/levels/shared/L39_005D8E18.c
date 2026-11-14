#include "common.h"

/* localdecomp:start func_L39_005D8E18 */
extern s32 D_001D7F18_sda;
__asm__(".extern D_001D7F18_sda, 4");
extern f32 D_001D7F20_sda;
__asm__(".extern D_001D7F20_sda, 4");
extern s32 D_001D7F24_sda;
__asm__(".extern D_001D7F24_sda, 4");
extern s32 *D_001D5A10_sda;
__asm__(".extern D_001D5A10_sda, 4");
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern u8 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern f32 D_L39_0024C2A8;
extern f32 D_L39_0024C2AC;
extern f32 D_L39_0024C2B0;
extern f32 D_L39_0024C2B4;
extern char D_L39_0024C2B8[8];
extern char D_L39_0024C2C0[8];
extern char D_L39_00243638[];
extern char D_L39_00243640[];

typedef struct {
    u8 pad0[8];
    s32 f8;
    s32 fC;
} T_005D8E18;

typedef struct {
    u8 pad0[0x1F8];
    f32 f1F8[2];
    u8 pad200[0x10];
    T_005D8E18 *f210;
} S_005D8E18;
extern S_005D8E18 D_L39_00352940;

extern s32 func_L01_005169C8(s32, f32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_005D7C18(s32 *mode, f32 *a, f32 *b, f32 *c, s32 *n0, s32 *n1);
extern void func_L39_005D7D80(void);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00120048(char *, char *, ...);

/* sets the two score strings and their size */
static __inline__ void setScore_005D8E18(char *fmt, f32 w, f32 h) {
    func_00120048(D_L39_0024C2C0, fmt, D_L39_00352940.f210->f8);
    func_00120048(D_L39_0024C2B8, fmt, D_L39_00352940.f210->fC);
    func_L01_00517538(0x70018, w, h);
    func_L01_00517538(0x70019, w, h);
}

void func_L39_005D8E18(void) {
    s32 mode;
    f32 y;
    f32 h;
    f32 step;
    s32 n0;
    s32 n1;
    u8 *s;
    s32 i;
    s32 col;
    s32 team;
    f32 f;
    f32 w;
    f32 yofs;
    s32 n;

    if (D_001D7F18_sda != 0) {
        func_L01_005169C8(0x70002, D_001D7F20_sda);
        func_L01_005169C8(0x70003, D_001D7F20_sda);
        func_L01_005169C8(0x70014, 0.4f);
        func_L01_005169C8(0x70013, 0.4f);
        func_L01_00516470(0x70002, 0.92f, 0.25f);
        func_L01_00516470(0x70003, 0.92f, 0.25f);
        func_L01_00516470(0x70008, 0.934f, 0.315f);
        func_L01_00516470(0x70005, 0.95f, 0.256f);
        func_L01_00516470(0x70004, 0.923000038f, 0.256f);
        func_L01_00516470(0x70007, 0.95f, 0.256f);
        func_L01_00516470(0x70006, 0.92f, 0.256f);
        func_L01_00517538(0x70008, 0.044f, 0.044f);
        func_L01_00517538(0x70005, 0.016f, 0.184f);
        func_L01_00517538(0x70004, 0.016f, 0.184f);
        func_L01_00517538(0x70007, 0.022f, 0.184f);
        func_L01_00517538(0x70006, 0.022f, 0.184f);
        func_L01_00516470(0x70009, 0.935f, 0.36f);
        func_L01_00516470(0x7000A, 0.935f, 0.36f);
        func_L01_00516470(0x70013, 0.93f, 0.2f);
        func_L01_00516470(0x70014, 0.93f, 0.2f);
        func_L01_00516470(0x70015, 0.933f, 0.265f);
        func_L01_00516470(0x70016, 0.93f, 0.13f);
        func_L01_00516470(0x70017, 0.932f, 0.210000008f);
        func_L01_00517538(0x70013, 1.0f, 1.0f);
        func_L01_00517538(0x70014, 1.0f, 1.0f);
        func_L01_00517538(0x70015, 0.044f, 0.044f);
        func_L01_00517538(0x70016, 0.05f, 0.075f);
        func_L01_00517538(0x70017, 0.05f, 0.075f);

        if (D_L39_00241640 != 0) {
            if (*(s32 *)(D_L39_00241640 + 0x180) != 1) {
                func_L01_00516AA0(0x70001, 1, 1);
                func_L01_00516AA0(0x70012, 1, 0);
                func_L01_00517190(0x70015, 0xED33);
                n = *D_001D5A10_sda;
            } else {
                func_L01_00516AA0(0x70012, 1, 1);
                func_L01_00516AA0(0x70001, 1, 0);
                func_L01_00517190(0x70015, 0xED5B);
                n = *D_L39_00241120;
            }
            if (n >= 3) {
                func_L01_00516AA0(0x70001, 1, 0);
                func_L01_00516AA0(0x70012, 1, 0);
                func_L01_00516AA0(0x7001A, 1, 1);
            }
        }

        s = func_L39_0061BF38(0);
        func_L39_005D7C18(&mode, &y, &h, &step, &n0, &n1);
        yofs = 0.25f;
        for (i = 0; i < 7; i++) {
            if (i < mode) {
                func_L01_00516AA0(i + 0x7000B, 1, 1);
                func_L01_00516470(i + 0x7000B, 0.887f, y + yofs);
                func_L01_00517538(i + 0x7000B, 0.02f, h);
                if ((*(s32 *)(s + 0x2548) == 0 && i < n0) || (*(s32 *)(s + 0x2548) == 1 && mode - i <= n0)) {
                    col = 0x40FF0000;
                } else if ((*(s32 *)(s + 0x2548) == 1 && i < n1) || (*(s32 *)(s + 0x2548) == 0 && mode - i <= n1)) {
                    col = 0x400000FF;
                } else {
                    col = D_001D7F24_sda;
                }
                func_L01_005170B8(i + 0x7000B, col);
                y += step;
            } else {
                func_L01_00516AA0(i + 0x7000B, 1, 0);
            }
        }

        team = *(s32 *)(s + 0x2548);
        col = 0x40FF0000;
        if (team != 0) {
            col = 0x400000FF;
        }
        f = D_L39_00352940.f1F8[team];
        if (f > 1.0f) {
            f = 1.0f;
        }
        if (f < 0.001f) {
            f = 0.001f;
        }
        func_L01_00517538(0x7000A, 0.048f, f * 0.086f);
        func_L01_005170B8(0x7000A, col);
        if (D_L39_00241640 != 0 && *(s8 *)(D_L39_00241640 + 0x196) != 0) {
            func_L01_00516AA0(0x7000A, 1, 1);
        } else {
            func_L01_00516AA0(0x7000A, 1, 0);
        }

        col = func_0038DBD8(0x40FF0000, 0x80F9C908, D_L39_0024C2B0);
        f = D_L39_0024C2A8;
        if (f > 1.0f) {
            f = 1.0f;
        }
        if (f < 0.001f) {
            f = 0.001f;
        }
        func_L01_005170B8(0x70004, col);
        func_L01_00517538(0x70004, 0.016f, f * 0.184f);

        col = func_0038DBD8(0x400000FF, 0x8003C5FD, D_L39_0024C2B4);
        f = D_L39_0024C2AC;
        if (f > 1.0f) {
            f = 1.0f;
        }
        if (f < 0.001f) {
            f = 0.001f;
        }
        func_L01_005170B8(0x70005, col);
        func_L01_00517538(0x70005, 0.016f, f * 0.184f);

        if (D_L39_00352940.f210->f8 >= 100 || D_L39_00352940.f210->fC >= 100) {
            w = 0.646f;
            setScore_005D8E18(D_L39_00243638, w, 0.68f);
        } else {
            w = 0.95f;
            setScore_005D8E18(D_L39_00243640, w, 1.0f);
        }
        func_L39_005D7D80();
        D_001D7F18_sda--;
    } else {
        func_L01_00516AA0(0x70000, 1, 0);
    }
}
/* localdecomp:end func_L39_005D8E18 */
