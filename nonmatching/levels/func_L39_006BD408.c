/* NTSC-U draft (Claude wave K): C of func_L39_006BA8F0, the NTSC-U twin of func_L39_006BD408, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 132 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_006BA8F0", whose code is not the PAL one).
 * Worker's note: FLAGS+132 diff: needs @ps2as (PAL line has none) for retail's lui form of D_001A612C/D_L39_0024D860 plus $gp form of the same address in delay slots (Ps2EeAs); with it the whole function aligns structurally: sscanf-like func_001200E0 arms set st (=1/4/2/6, ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006BD408 (src/levels/39_multiplayer_menu/L39_006BBB38.c) */
extern s32 D_001A612C[];
extern u8 *D_L39_0024D860_006BA8F0;
extern u8 D_L39_00249500[];
extern u8 D_L39_00249508[];
extern u8 D_L39_00249630[];
extern u8 *func_L39_006D8BF8(void *);
extern s32 func_001200E0(void *, void *, ...);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_L39_006D4888(void *);
extern void func_00195500(void);
extern void func_L39_006D6030(void *);
extern void func_00120D28(void *, void *, s32);
extern s32 func_L39_006CC290(void *, s32);
extern s32 func_L39_006D0790(void *, void *, void *);
extern u8 *func_L39_006D0A30(void *, s32, s32);
extern s32 func_00120884(void *);
extern void func_L39_00594648(void *, void *, s32);
extern s32 func_0011FFA8(void *, s32, ...);
extern s32 func_0037DF98(s32);

/* localdecomp:start func_L39_006BA8F0 */
void func_L39_006BA8F0(u8 *s2, s32 a1) {
    u8 *a0;
    u8 *s0;
    u8 *s1;
    u8 *e;
    s32 st;
    s32 s5;
    s32 s3;
    s32 i;
    s32 n;
    s32 v40;
    s32 v44;
    u8 buf[0x40];
    s32 *pa;
    s32 *pb;
    u8 *nm;

    *(s32 *)(s2 + 0x2A8) = a1;
    if (D_001A612C[0] != 0) {
        return;
    }
    a0 = func_L39_006D8BF8(*(void **)(D_L39_0024D860_006BA8F0 + 0x4C));
    s2[0x2AC] = 0;
    *(s32 *)(s2 + 0x2F0) = 0;
    if (a0 == 0) {
        return;
    }
    pa = &v40;
    pb = &v44;
    nm = a0 + 0x1C;
    st = 8;
    if (a0[0x1C] == 0x43) {
        if (nm[1] == 0x59) {
            st = 1;
            func_001200E0(a0 + 0x1E, D_L39_00249500, pa, pb);
        } else if (nm[1] == 0x52) {
            st = 4;
            func_001200E0(a0 + 0x1E, D_L39_00249500, pa, pb);
        } else if (nm[1] == 0x43) {
            st = 2;
            func_001200E0(a0 + 0x1E, D_L39_00249508, pa, pb);
        }
    } else if (a0[0x1C] == 0x48) {
        st = 6;
        func_001200E0(a0 + 0x1E, D_L39_00249500, pa, pb);
    }
    switch (st) {
    case 1:
        s1 = *(u8 **)(D_L39_0024D860_006BA8F0 + 0x78);
        s5 = v40 + 0x28;
        s0 = 0;
        if (s1[0xD] != 0) {
            s0 = s1 + 0x14;
        }
        s3 = (s32)func_00130760(func_0012DCB0(), 0x24000);
        while (s0 == 0) {
            func_L39_006D4888(s1);
            if (s1[0] != 0) {
                do {
                    func_00195500();
                    if ((s32)func_00130760(func_0012DCB0(), 0x24000) - s3 >= 0x3A99) {
                        return;
                    }
                    if (D_L39_0024D860_006BA8F0 != 0) {
                        func_L39_006D6030(D_L39_0024D860_006BA8F0);
                    }
                } while (s1[0] != 0);
            }
            s0 = 0;
            if (s1[0xD] != 0) {
                s0 = s1 + 0x14;
            }
        }
        n = *(s32 *)(s0 + 4);
        for (i = 0; i < n; i++) {
            e = *(u8 **)(*(u8 **)(s0 + 8) + i * 4);
            if (*(s32 *)(e + 0x18) == s5) {
                func_00120D28(s2 + 0x2AC, e + 0x1C, 0x40);
                *(s32 *)(s2 + 0x2F4) = s5;
                *(s32 *)(s2 + 0x2F0) = 1;
                s2[0x2EB] = 0;
                return;
            }
        }
        return;
    case 2:
        s1 = *(u8 **)(D_L39_0024D860_006BA8F0 + 0x38);
        if (func_L39_006CC290(s1, 0) == 0) {
            return;
        }
        *(s32 *)(s2 + 0x304) = *(s32 *)s1;
        if (func_L39_006D0790(s1, s2 + 0x308, s2 + 0x30C) != 0) {
            e = func_L39_006D0A30(s1, *(s32 *)(s2 + 0x30C), *(s32 *)(s2 + 0x308));
            if (e != 0) {
                s0 = e + 0x20;
                func_L39_00594648(buf, s0, func_00120884(s0));
                func_0011FFA8(s2 + 0x2AC, 0x40, D_L39_00249630, s1 + 4, buf);
            } else {
                func_0011FFA8(s2 + 0x2AC, 0x40, s1 + 4);
            }
        } else {
            func_0011FFA8(s2 + 0x2AC, 0x40, s1 + 4);
        }
        s2[0x2EB] = 0;
        *(s32 *)(s2 + 0x2F0) = 3;
        return;
    case 4:
        s1 = *(u8 **)(D_L39_0024D860_006BA8F0 + 0x38);
        if (func_L39_006CC290(s1, 0) == 0) {
            return;
        }
        if (*(s32 *)s1 == -1) {
            return;
        }
        s0 = s2 + 0x2AC;
        func_0011FFA8(s0, 0x40, func_0037DF98(0x14A0), s1 + 4);
        *(s32 *)(s2 + 0x2F0) = 2;
        s2[0x2EB] = 0;
        return;
    default:
        return;
    }
}
/* localdecomp:end func_L39_006BA8F0 */
