/* US draft of func_003B54D8 (rac3-uya-decomp func_003AFF20, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003B0A60. */


/* localdecomp:start func_003B54D8 */
typedef struct { u8 p[0x1C0]; u32 f1C0; u32 f1C4; } P_3AFF20;
__asm__(".extern D_001D89E4, 4");
__asm__(".extern D_001D89E8, 4");
__asm__(".extern D_001D89EC, 4");
__asm__(".extern D_001D89B0, 4");
__asm__(".extern D_001D89B4, 4");
__asm__(".extern D_001D89FC, 4");
extern s32 D_001D89E4;
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D89B0;
extern s32 D_001D89B4;
extern s32 D_001D89FC;
__asm__(".extern D_001D5520_003B54D8, 16");
extern s32 D_001D5520_003B54D8;
extern s32 D_001D5520_g_003B54D8;
__asm__(".extern D_001D52FC_003B54D8, 16");
extern P_3AFF20 *D_001D52FC_003B54D8;
extern P_3AFF20 *D_001D52FC_g_003B54D8;
extern u8 D_0037F690[];
extern char D_001D89F0[];
extern s32 func_003B97B0(void);
extern s32 func_003B96D0(void);
extern s32 func_003B9700();
extern void func_003B96D8();
extern void func_003B6438(void);
extern void func_003B9890(void);
extern void func_00391408(s32, s32, s32);
extern void func_003BA4F8(void *, s32);
extern void func_003B5CD8(void);
extern void func_003B5BC0(s32, s32);
extern void func_11B2E8();
void func_003B54D8(s32 a0) {
    switch (D_001D89E4) {
    case 1:
        if (func_003B97B0() != 0) break;
        switch (func_003B96D0()) {
        case 1: {
            u8 *buf; char *fmt;
            s32 x, y, z;
            D_001D89EC = D_001D89B0;
            D_001D89E8 = D_001D89B4;
            buf = D_0037F690;
            fmt = D_001D89F0;
            x = func_00381FF0(0x511);
            y = func_00381FF0(0x512);
            z = func_00381FF0(0x513);
            func_11B2E8(buf, fmt, x, y, D_001D89EC, z);
            {
                s32 w = func_00381FF0(0x8E3);
                func_003B9700(0, w, func_00381FF0(0x8DF), buf, 0);
            }
            func_003B96D8(0x20, 0x10);
            D_001D89E4 = 2;
            break;
        }
        case 2:
            D_001D89E4 = 0;
            break;
        }
        break;
    case 2:
        D_001D5520_g_003B54D8 = D_001D5520_003B54D8 == 0;
        func_003B6438();
        D_001D89E4 = 3;
        break;
    case 3: {
        u8 *buf; char *fmt;
        s32 x, y, z;
        buf = D_0037F690;
        fmt = D_001D89F0;
        x = func_00381FF0(0x511);
        y = func_00381FF0(0x512);
        z = func_00381FF0(0x513);
        func_11B2E8(buf, fmt, x, y, D_001D89EC, z);
        if (func_003B97B0() == 0) {
            switch (func_003B96D0()) {
            case 1:
                D_001D89E4 = 0;
                break;
            case 2:
                D_001D89E4 = 4;
                break;
            }
        } else {
            if (--D_001D89E8 > 0) break;
            if (--D_001D89EC <= 0) {
                ((s32 (*)(void))func_003B9890)();
                D_001D89E4 = 4;
            }
            D_001D89E8 = D_001D89B4;
        }
        break;
    }
    case 4:
        D_001D5520_g_003B54D8 = D_001D5520_003B54D8 == 0;
        func_003B6438();
        D_001D89E4 = 0;
        break;
    case 5: {
        u32 bits;
        if (func_003B97B0() == 0) {
            D_001D89E4 = 0;
            break;
        }
        bits = D_001D52FC_g_003B54D8->f1C0;
        if (bits & 0xF000) {
            s32 dx, dy;
            u32 q;
            if (++D_001D89FC < 3) break;
            D_001D89FC = 0;
            if (bits & 0x8000) dx = -2;
            else dx = (bits & 0x2000) ? 2 : 0;
            q = D_001D52FC_003B54D8->f1C0;
            if (q & 0x1000) dy = -1;
            else if (q & 0x4000) dy = 1;
            else dy = 0;
            func_00391408(dx, dy, 1);
        }
        break;
    }
    case 0: {
        s32 b = D_001D52FC_003B54D8->f1C4;
        func_003BA4F8(func_003B9BD0(0), b);
        func_003B5CD8();
        func_003B5BC0(a0, b);
        func_003B0A60();
        break;
    }
    }
}
/* localdecomp:end func_003B54D8 */
