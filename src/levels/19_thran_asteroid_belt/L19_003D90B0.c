#include "common.h"

/* localdecomp:start func_L19_003D90B0 */
typedef struct { u8 p0[0x24]; s32 x24; u8 p1[0x48 - 0x28]; s16 x48; u8 p2[0x4E - 0x4A]; s16 x4E; u8 p3[0x6C - 0x50]; s32 x6C; u8 p4[0x76 - 0x70]; s16 x76; u8 p5[0x94 - 0x78]; s32 x94; s16 x98; u8 p6[0x9E - 0x9A]; s16 x9E; } S_3D90B0a;
typedef struct { u8 p0[0x7D4]; u16 x7D4; u8 p1[2]; u32 x7D8; u32 x7DC; } S_3D90B0b;
typedef struct { u8 p0[0x1F]; u8 x1F; u8 p1[0x10]; } S_3D90B0c;
extern S_3D90B0a D_001CCFD0;
extern S_3D90B0b D_001A7E18;
extern S_3D90B0c D_00142CA0;
extern u8 D_001A4C60[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern s32 D_001D4C38;
extern s32 D_L19_001D66D0;
extern s32 D_L19_001D66D4;
__asm__(".extern D_L19_001DED24, 4");
extern s32 D_L19_001DED24;
extern s32 D_L19_001DF758;
extern s32 D_L19_00235640[];
extern s32 D_L19_001F2380[];
extern u8 *D_L19_001DF800;
extern u8 *D_L19_001DF71C;
extern u16 *D_L19_0021C260[];
extern void func_L01_0042B068(s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_004B0EE0(void);
extern s32 func_L01_004BA800(void);
extern void func_003A1930(s32, s32, s32);
extern void func_003A2B68(s32, s32);
extern s32 func_003A1798(void);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_0041A5B0(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0043B510(s32);

void func_L19_003D90B0(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u16 *q;
    S_3D90B0b *w;
    s32 v;
    s32 n;
    u32 m;

    if (obj[0x20] == 0) {
        obj[0x20] = 1;
        obj[0x30] = 0xFF;
        obj[0x95] = 0;
        D_L19_001DED24 = 0;
        *(s16 *)(obj + 0x96) = 0x1770;
        if ((D_001BBC40[*(s32 *)(p + 0x24) + D_001D545C * 16] & 0x80) &&
            !(D_001BBC40[*(s32 *)(p + 0x28) + D_001D545C * 16] & 0x80) && D_L19_00235640[0] == 0) {
            func_L01_0042B068(1, 0);
            func_L01_004F50C8(D_L19_001DF800 + *(s32 *)(p + 0x2C) * 0x80 + 0x30, D_L19_001DF800 + *(s32 *)(p + 0x2C) * 0x80 + 0x70, 0, 1);
        }
    }
    if ((D_001BBC40[*(s32 *)(p + 0x24) + D_001D545C * 16] & 0x80) &&
        !(D_001BBC40[*(s32 *)(p + 0x28) + D_001D545C * 16] & 0x80) &&
        (D_L19_001D66D4 == 6 || D_L19_001D66D0 == 6))
        func_L01_004B0EE0();
    if (func_L01_004BA800() == 0 && D_L19_001D66D4 != 6) {
        if (D_L19_001F2380[0] == 0) {
            if (D_001CCFD0.x48 != 0) {
                D_001CCFD0.x4E = 5;
                func_003A1930(0, 0, 0x400);
            }
        } else if (D_L19_001F2380[0] == 1) {
            s32 id = *(s32 *)(p + 0x20);
            D_L19_001DED24 = 0;
            if (D_001CCFD0.x48 != id) {
                D_001CCFD0.x4E = 5;
                func_003A1930(*(s32 *)(p + 0x20), 0, 0x400);
            }
        }
    }
    if (obj[0x95] == 0 && D_001CCFD0.x6C == 0 && D_001CCFD0.x24 == -1 && D_001CCFD0.x94 == 0) {
        if (!(D_001BBC40[*(s32 *)(p + 0x8) + D_001D545C * 16] & 0x80) && *(s32 *)(p + 0x0) != -1) {
            q = D_L19_0021C260[*(s32 *)(p + 0x0)];
            while ((*(s32 *)(p + 0x0) & 0xFF) != 0xFF && *(s32 *)(p + 0x0) <= D_L19_001DF758 && q != 0 &&
                   ((s16)q[-1] >= 0 || q == D_L19_0021C260[*(s32 *)(p + 0x0)])) {
                u8 *e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (e[0x20] != 0xFE)
                    if (e[0x20] != 0xFD)
                        if (*(s16 *)(e + 0xAA) == 0x1C13 && (e[0x20] == 3 || e[0x95] == 5 || e[0x95] == 6)) {
                            func_003A2B68((*(s32 *)(p + 0x10) & 0x3FFF) + 0x7D0, 0);
                            obj[0x95] = 1;
                            *(s32 *)(p + 0x0) = -1;
                        }
                q++;
            }
        }
        if (!(D_001BBC40[*(s32 *)(p + 0xC) + D_001D545C * 16] & 0x80) && *(s32 *)(p + 0x4) != -1) {
            q = D_L19_0021C260[*(s32 *)(p + 0x4)];
            while ((*(s32 *)(p + 0x4) & 0xFF) != 0xFF && *(s32 *)(p + 0x4) <= D_L19_001DF758 && q != 0 &&
                   ((s16)q[-1] >= 0 || q == D_L19_0021C260[*(s32 *)(p + 0x4)])) {
                u8 *e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (e[0x20] != 0xFE)
                    if (e[0x20] != 0xFD)
                        if (*(s16 *)(e + 0xAA) == 0x1C13 && (e[0x20] == 3 || e[0x95] == 5 || e[0x95] == 6)) {
                            func_003A2B68((*(s32 *)(p + 0x10) & 0x3FFF) + 0x7D0, 0);
                            obj[0x95] = 1;
                            *(s32 *)(p + 0x4) = -1;
                        }
                q++;
            }
        }
    } else if (obj[0x95] == 1 && D_001CCFD0.x76 == 0 && D_001CCFD0.x9E == 3 && D_001CCFD0.x98 < 0x1B58) {
        func_003A1798();
        obj[0x95] = 0;
    }
    if (D_L19_001DED24 != 0 && D_001CCFD0.x76 == 0 && D_001CCFD0.x9E == 3 && D_001CCFD0.x98 < 0x1B58) {
        if (func_003A1798() != 0)
            D_L19_001DED24 = 0;
    }
    if (func_00382380(D_001A4C60, *(s32 *)(p + 0x14), 0)) {
        w = &D_001A7E18;
        if (w->x7D4 != 0) {
            n = (D_001D4C38 * 5 + 2) / 6;
            m = w->x7D8;
            if ((u32)(n - m) >= 0x385 || m == 0)
                func_L01_0041A5B0(0xD00, 0xA7);
            else if (m < n)
                w->x7D8 = n;
        } else {
            w->x7D4 = w->x7D4 + 1;
            n = (D_001D4C38 * 5 + 2) / 6;
            if (w->x7D8 < n)
                w->x7D8 = n;
            w->x7DC = w->x7DC | (1 << D_001D545C) | 0x80000000;
        }
    }
    if (D_00142CA0.x1F != 0 && !(D_001BBC40[obj[0xB0] + D_001D545C * 16] & 0x80)) {
        if (func_00382380(D_001A4C60, *(s32 *)(p + 0x18), 0)) {
            v = *(u16 *)(obj + 0x96);
            if (func_0038CAD0(&v) && func_L01_0041A5B0(0x186D, 0x15D))
                v = 0x8CA;
            *(u16 *)(obj + 0x96) = v;
        }
        if (func_00382380(D_001A4C60, *(s32 *)(p + 0x1C), 0))
            func_L01_0043B510(obj[0xB0]);
    }
}
/* localdecomp:end func_L19_003D90B0 */
