/* NTSC-U draft (Claude wave K): C of func_L39_006A1D00, the NTSC-U twin of func_L39_006A4510, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 486 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_006A1D00", whose code is not the PAL one).
 * Worker's note: 486 diff on a complete first draft (all control flow decoded, not tuned): menu-slot panel builder: poll loop until D_L39_0024D860->w78 ready, parse object func_L39_006C9630/9A08/9860(q, id) with ids 0xC,0x10,... filling s2 fields 0x2B8-0x338, vtable calls ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006A4510 (src/levels/39_multiplayer_menu/L39_006A4510.c) */
extern u8 *D_L39_0024D860_006A1D00;
extern u8 D_L39_002488E0[];
extern u8 D_L39_002487E8[];
extern u8 D_L39_002488E8[];
extern u8 D_L39_002488F8[];
extern u8 D_L39_00248900[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern u8 *func_L39_006D1BF8(void *, s32);
extern void func_L39_006C9630(void *);
extern void func_L39_006C9A08(void *, void *);
extern s32 func_L39_006C9860(void *, s32);
extern void func_L39_006D4888(void *);
extern void func_00195500(void);
extern void func_L39_006D6030(void *);
extern s32 func_00120884(void *);
extern void func_L39_00594648(void *, void *, s32);
extern u8 *func_0037DF98(s32);
extern s32 func_00120048(void *, void *, ...);
extern u8 *func_L39_006A2DA0(void *, s32);
extern void func_L39_006C9668(void *, s32);
extern u8 *func_L39_006D2140(void *, s32, void *);

/* localdecomp:start func_L39_006A1D00 */
typedef void (*Vf_006A1D00)(void *, void *);

void func_L39_006A1D00(u8 *s2, s32 a1) {
    u8 *s5;
    u8 *s0;
    u8 *s3;
    u8 *e;
    u8 *r;
    u8 *v;
    u8 buf[0x12];
    u8 line[8][15];
    u8 *ptrs[8];
    u8 *names[3];
    u8 *tbl[3];
    u8 q[0x60];
    s32 i;
    s32 n;
    s32 cnt;
    s32 sel;
    s32 st;
    s32 idx;
    s32 *p6;

    if (a1 == 0) {
        if (!(*(s32 *)(s2 + 0x2CC) + 0x1388 < (s32)func_00130760(func_0012DCB0(), 0x24000))) {
            return;
        }
    }
    p6 = (s32 *)(s2 + 0x2BC);
    cnt = 0;
    *(s32 *)(s2 + 0x2CC) = (s32)func_00130760(func_0012DCB0(), 0x24000);
    s5 = *(u8 **)(D_L39_0024D860_006A1D00 + 0x3C);
    *(u8 **)(s2 + 0x2B8) = func_L39_006D1BF8(s5, *(s32 *)(s2 + 0x2A8));
    if (*(u8 **)(s2 + 0x2B8) != 0) {
        func_L39_006C9630(q);
        func_L39_006C9A08(q, *(u8 **)(s2 + 0x2B8));
        if (func_L39_006C9860(q, 0xC) == 0) {
            s0 = *(u8 **)(D_L39_0024D860_006A1D00 + 0x78);
            r = 0;
            if (s0[0xD] != 0) {
                r = s0 + 0x14;
            }
            if (r == 0) {
                s3 = s0 + 0x14;
                do {
                    func_L39_006D4888(s0);
                    if (s0[0] != 0) {
                        do {
                            func_00195500();
                            if (D_L39_0024D860_006A1D00 != 0) {
                                func_L39_006D6030(D_L39_0024D860_006A1D00);
                            }
                        } while (s0[0] != 0);
                    }
                    r = 0;
                    if (s0[0xD] != 0) {
                        r = s3;
                    }
                } while (r == 0);
            }
        }
        st = func_L39_006C9860(q, 0x10);
        *(s32 *)(s2 + 0x2C8) = st + 0x27;
        (*(u8 **)(s2 + 0x2B8))[0x146] = 0;
        s0 = *(u8 **)(s2 + 0x2B8) + 0x134;
        func_L39_00594648(buf, s0, func_00120884(s0));
        i = 0x11;
        if (buf[0x11] == 0x20) {
            i = 0x10;
            while (buf[i] == 0x20) {
                i--;
            }
        }
        buf[i + 1] = 0;
        (*(Vf_006A1D00 *)(*(u8 **)(*(u8 **)(s2 + 0x144) + 0x60) + 0xB8))(*(u8 **)(s2 + 0x144), buf);
        switch (*(s32 *)(s2 + 0x2C8) - 0x28) {
        case 0: v = func_0037DF98(0xBB1); break;
        case 1: v = func_0037DF98(0xBB2); break;
        case 2: v = func_0037DF98(0xDA); break;
        case 3: v = func_0037DF98(0xBB4); break;
        case 4: v = func_0037DF98(0xD8); break;
        case 5: v = func_0037DF98(0xD4); break;
        case 6: v = func_0037DF98(0x18C4); break;
        case 7: v = func_0037DF98(0x18C5); break;
        case 8: v = func_0037DF98(0x18C6); break;
        case 9: v = func_0037DF98(0x18C7); break;
        default: v = 0; break;
        }
        func_00120048(line, v);
        (*(Vf_006A1D00 *)(*(u8 **)(*(u8 **)(s2 + 0x148) + 0x60) + 0xB8))(*(u8 **)(s2 + 0x148), line);
        v = func_L39_006A2DA0(s2, func_L39_006C9860(q, 2));
        if (v != 0) {
            (*(Vf_006A1D00 *)(*(u8 **)(*(u8 **)(s2 + 0x150) + 0x60) + 0xB8))(*(u8 **)(s2 + 0x150), v);
        } else {
            (*(Vf_006A1D00 *)(*(u8 **)(*(u8 **)(s2 + 0x150) + 0x60) + 0xB8))(*(u8 **)(s2 + 0x150), D_L39_002487E8);
        }
        s2[0x330] = func_L39_006C9860(q, 0x13) == 0;
        s2[0x331] = func_L39_006C9860(q, 0x12) == 0;
        n = func_L39_006C9860(q, 0xF);
        *(s32 *)(s2 + 0x324) = n * 5;
        n = func_L39_006C9860(q, 0x15);
        *(s32 *)(s2 + 0x328) = n * 5;
        *(s32 *)(s2 + 0x32C) = func_L39_006C9860(q, 0x17);
        *(s32 *)(s2 + 0x334) = func_L39_006C9860(q, 0x18);
        s2[0x33E] = func_L39_006C9860(q, 0x19) == 1;
        s2[0x33C] = func_L39_006C9860(q, 0x1A) == 1;
        s2[0x33D] = func_L39_006C9860(q, 0x1B) == 1;
        s2[0x33F] = func_L39_006C9860(q, 0x1C) == 1;
        *(s32 *)(s2 + 0x338) = func_L39_006C9860(q, 0x14);
        tbl[0] = func_0037DF98(0x1024);
        tbl[1] = func_0037DF98(0x10E2);
        tbl[2] = func_0037DF98(0x1026);
        names[0] = tbl[0];
        names[1] = tbl[1];
        names[2] = tbl[2];
        *(s32 *)(s2 + 0x320) = func_L39_006C9860(q, 0x11);
        if (*(s32 *)(s2 + 0x338) != 0 && *(s32 *)(s2 + 0x320) == 2) {
            (*(Vf_006A1D00 *)(*(u8 **)(*(u8 **)(s2 + 0x14C) + 0x60) + 0xB8))(*(u8 **)(s2 + 0x14C), func_0037DF98(0x162A));
        } else {
            (*(Vf_006A1D00 *)(*(u8 **)(*(u8 **)(s2 + 0x14C) + 0x60) + 0xB8))(*(u8 **)(s2 + 0x14C), names[*(s32 *)(s2 + 0x320)]);
        }
        *(s32 *)(s2 + 0x2C0) = func_L39_006C9860(q, 1);
        n = func_L39_006C9860(q, 3);
        *(s32 *)(s2 + 0x310) = n;
        if (n >= 9) {
            *(s32 *)(s2 + 0x310) = n - 8;
        }
        s2[0x318] = func_L39_006C9860(q, 4) == 0;
        s2[0x319] = func_L39_006C9860(q, 5) == 0;
        s2[0x31A] = func_L39_006C9860(q, 6) == 0;
        s2[0x31B] = func_L39_006C9860(q, 7) == 0;
        s2[0x31C] = func_L39_006C9860(q, 8) == 0;
        s2[0x31D] = func_L39_006C9860(q, 9) == 0;
        s2[0x31E] = func_L39_006C9860(q, 0xA) == 0;
        s2[0x31F] = func_L39_006C9860(q, 0xB) == 0;
        func_L39_006C9668(q, 2);
    }
    *(u8 **)(s2 + 0x2C4) = func_L39_006D2140(s5, *(s32 *)(s2 + 0x2A8), p6);
    if (*(u8 **)(s2 + 0x2C4) != 0) {
        if (*(s32 *)(s2 + 0x2BC) >= 9) {
            *(s32 *)(s2 + 0x2BC) = 8;
        }
        for (i = 0; i < 8; i++) {
            ptrs[i] = line[i];
        }
        idx = (*(s32 (**)(void *))(*(u8 **)(*(u8 **)(s2 + 0x164) + 0x60) + 0x8C))(*(u8 **)(s2 + 0x164));
        sel = -1;
        if (idx != -1) {
            sel = *(s32 *)(s2 + 0x2D0 + idx * 4);
        }
        n = 0;
        for (i = 0; i < *(s32 *)(s2 + 0x2BC); i++) {
            e = *(u8 **)(s2 + 0x2C4) + i * 0x124;
            if (e[0x46] != 0) {
                func_00120048(line[i], D_L39_002488E8, i + 1);
                cnt++;
            } else {
                func_00120048(line[i], D_L39_002488F8, i + 1);
            }
            *(s32 *)(s2 + 0x2D0 + i * 4) = *(s32 *)(e + 0x20);
            if (*(s32 *)(e + 0x20) == sel) {
                n = i;
            }
        }
        (*(void (**)(void *, s32, void *))(*(u8 **)(*(u8 **)(s2 + 0x164) + 0x60) + 0x6C))(*(u8 **)(s2 + 0x164), *(s32 *)(s2 + 0x2BC), ptrs);
        (*(void (**)(void *, s32))(*(u8 **)(*(u8 **)(s2 + 0x164) + 0x60) + 0x88))(*(u8 **)(s2 + 0x164), n);
    }
    s0 = *(u8 **)(s2 + 0x160) + 0x14;
    func_00120048(s0, D_L39_00248900, func_0037DF98(0x1005), cnt, *(s32 *)(s2 + 0x2C0));
}
/* localdecomp:end func_L39_006A1D00 */
