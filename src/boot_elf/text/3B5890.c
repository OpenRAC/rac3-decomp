#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003823D0(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003823D0();
extern void func_003B5B80(void);
extern void func_003B5890();
extern void func_003B5BC8(void);
extern void func_003B5BE8(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B5890 */
typedef struct { u8 p[0x1C0]; u32 f1C0; u32 f1C4; } P_3AFF20;
extern s32 D_001D89E4;
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D89B0;
extern s32 D_001D89B4;
extern s32 D_001D89FC;
extern s32 D_001D5520_003B5890;
extern s32 D_001D5520_g_003AFF20;
extern P_3AFF20 *D_001D52FC_003B5890;
extern P_3AFF20 *D_001D52FC_g_003AFF20;
extern u8 D_0037F690[];
extern char D_001D89F0[];
extern s32 func_003B9B68(void);
extern s32 func_003B9A88(void);
extern s32 func_003B9AB8();
extern void func_003B9A90();
extern void func_003B67F0(void);
extern void func_003B9C48(void);
extern void func_003917E8(s32, s32, s32);
extern void func_003BA8B0(void *, s32);
extern void func_11B2E8();
extern s32 D_001D89E4;
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D89B0;
extern s32 D_001D89B4;
extern s32 D_001D89FC;
extern s32 D_001D5520_003B5890 __attribute__((section(".data")));
extern s32 D_001D5520_g_003B5890;
extern P_3AFF20 *D_001D52FC_003B5890 __attribute__((section(".data")));
extern P_3AFF20 *D_001D52FC_g_003B5890;
extern u8 D_0037F690[];
extern char D_001D89F0[];
extern s32 func_003B9B68(void);
extern s32 func_003B9A88(void);
extern s32 func_003B9AB8();
extern void func_003B9A90();
extern void func_003B67F0(void);
extern void func_003B9C48(void);
extern void func_003917E8(s32, s32, s32);
extern void func_003BA8B0(void *, s32);
extern void func_003B6090(void);
extern void func_003B5F78(s32, s32);
extern void func_11B2E8();
extern s32 *func_003B9F88(s32);
extern void func_003B63D0(void);
void func_003B5890(s32 a0) {
    switch (D_001D89E4) {
    case 1:
        if (func_003B9B68() != 0) break;
        switch (func_003B9A88()) {
        case 1: {
            u8 *buf; char *fmt;
            s32 x, y, z;
            D_001D89EC = D_001D89B0;
            D_001D89E8 = D_001D89B4;
            buf = D_0037F690;
            fmt = D_001D89F0;
            x = func_003823D0(0x511);
            y = func_003823D0(0x512);
            z = func_003823D0(0x513);
            func_11B2E8(buf, fmt, x, y, D_001D89EC, z);
            {
                s32 w = func_003823D0(0x8E3);
                func_003B9AB8(0, w, func_003823D0(0x8DF), buf, 0);
            }
            func_003B9A90(0x20, 0x10);
            D_001D89E4 = 2;
            break;
        }
        case 2:
            D_001D89E4 = 0;
            break;
        }
        break;
    case 2:
        D_001D5520_g_003B5890 = D_001D5520_003B5890 == 0;
        func_003B67F0();
        D_001D89E4 = 3;
        break;
    case 3: {
        u8 *buf; char *fmt;
        s32 x, y, z;
        buf = D_0037F690;
        fmt = D_001D89F0;
        x = func_003823D0(0x511);
        y = func_003823D0(0x512);
        z = func_003823D0(0x513);
        func_11B2E8(buf, fmt, x, y, D_001D89EC, z);
        if (func_003B9B68() == 0) {
            switch (func_003B9A88()) {
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
                ((s32 (*)(void))func_003B9C48)();
                D_001D89E4 = 4;
            }
            D_001D89E8 = D_001D89B4;
        }
        break;
    }
    case 4:
        D_001D5520_g_003B5890 = D_001D5520_003B5890 == 0;
        func_003B67F0();
        D_001D89E4 = 0;
        break;
    case 5: {
        u32 bits;
        if (func_003B9B68() == 0) {
            D_001D89E4 = 0;
            break;
        }
        bits = D_001D52FC_g_003B5890->f1C0;
        if (bits & 0xF000) {
            s32 dx, dy;
            u32 q;
            if (++D_001D89FC < 3) break;
            D_001D89FC = 0;
            if (bits & 0x8000) dx = -2;
            else dx = (bits & 0x2000) ? 2 : 0;
            q = D_001D52FC_003B5890->f1C0;
            if (q & 0x1000) dy = -1;
            else if (q & 0x4000) dy = 1;
            else dy = 0;
            func_003917E8(dx, dy, 1);
        }
        break;
    }
    case 0: {
        s32 b = D_001D52FC_003B5890->f1C4;
        func_003BA8B0(func_003B9F88(0), b);
        func_003B6090();
        func_003B5F78(a0, b);
        func_003B63D0();
        break;
    }
    }
}
/* localdecomp:end func_003B5890 */

/* localdecomp:start func_003B5B80 */
extern s32 func_003E8960();
extern void func_003B5F48(void);
extern s32 func_003A2B50(s32);
extern void func_003B9C48(void);
void func_003B5B80(void) {
    func_003E8960(0x10);
    func_003E8960(0x11);
    func_003E8960(0x14);
    func_003B5F48();
    func_003A2B50(1);
    func_003B9C48();
}
/* localdecomp:end func_003B5B80 */

/* localdecomp:start func_003B5BC8 */
void func_003B5BC8(void) {
    func_00381C48();
}
/* localdecomp:end func_003B5BC8 */

/* localdecomp:start func_003B5BE8 */
extern s32 func_00381C50(void);
extern void func_003B9C58();
 
void func_003B5BE8(void) {
    func_00381C50();
    func_003B9C58();
}
/* localdecomp:end func_003B5BE8 */
