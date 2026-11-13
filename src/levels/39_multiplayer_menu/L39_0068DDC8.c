#include "common.h"

/* localdecomp:start func_L39_0068DDC8 */
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern u8 D_L39_00247C30[];
extern u8 D_L39_00247C38[];
extern u8 D_L39_00247C40[];
extern s32 func_L39_006DD860(u8 *, s32);
extern s32 func_L39_006CEA18(u8 *, s32);
extern void func_L39_006D0DD0(u8 *);
extern s32 func_00120B70(u8 *, u8 *, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern u8 *func_00381FF0(s32);

typedef struct {
    s32 pad0;
    s32 count;
    u8 **items;
} S_0068DDC8;

typedef struct {
    u8 pad0[0x2F94];
    s32 sel;
    u8 pad2F98[4];
    S_0068DDC8 list[1];
} SS_0068DDC8;

typedef struct {
    u8 pad0[0x3F0];
    s32 sel;
    u8 pad3F4[0x10];
    S_0068DDC8 list[1];
} SD_0068DDC8;

void func_L39_0068DDC8(u8 *self) {
    void *args[140];
    u8 buf[0x50];
    u8 *s = (u8 *)D_L39_0024D760[0x54 / 4];
    S_0068DDC8 *p1 = 0;
    u8 *d;
    S_0068DDC8 *p0;
    s32 n;
    s32 i;
    s32 m;
    s32 neg;
    s32 cnt;
    u8 *sep = D_L39_00247C30;

    if (*(s32 *)(s + 0x2F94) >= 0) {
        p1 = &((SS_0068DDC8 *)s)->list[((SS_0068DDC8 *)s)->sel];
    }
    d = (u8 *)D_L39_0024D760[0x38 / 4];
    p0 = 0;
    if (d[0x3EC] != 0 && *(s32 *)(d + 0x3F0) >= 0) {
        p0 = &((SD_0068DDC8 *)d)->list[((SD_0068DDC8 *)d)->sel];
    }
    if (self[0x2A8] != 0 && s[0x2F89] == 0 && d[0x3F4] == 0) {
        func_L39_006DD860(s, 1);
        self[0x2A8] = 0;
    }
    if (self[0x2B8] != 0 && d[0x3F4] == 0 && s[0x2F89] == 0) {
        func_L39_006CEA18(d, 0);
        if (*(s32 *)d >= 0) {
            func_L39_006D0DD0(d);
        }
        self[0x2B8] = 0;
    }
    neg = 0;
    if (*(s32 *)d < 0) {
        neg = 1;
    }
    if ((neg || d[0x3F4] == 0) && s[0x2F89] == 0) {
        s32 c = *(s32 *)(s + 0x2F90);
        s32 ch0 = *(s32 *)(self + 0x2AC) != c;
        s32 ch1 = 0;
        if (!neg) {
            s32 gen = *(s32 *)(d + 0x3FC);
            ch1 = *(s32 *)(self + 0x2B4) != gen;
        }
        ch0 |= ch1;
        if (ch0) {
            n = 0;
            if (p1 != 0) {
                *(s32 *)(self + 0x2AC) = c;
                cnt = p1->count;
                *(s32 *)(self + 0x2B0) = cnt;
                if (cnt > 0x40) {
                    *(s32 *)(self + 0x2B0) = 0x40;
                }
                m = 0;
                for (i = 0; i < *(s32 *)(self + 0x2B0); i++) {
                    u8 *name = p1->items[i >> 1] + 0x20;
                    if (func_00120B70(name, D_L39_00247C38, 5) != 0) {
                        args[n++] = name;
                        args[n++] = sep;
                        m++;
                    }
                }
                *(s32 *)(self + 0x2B0) = m;
            }
            if (*(s32 *)d >= 0 && p0 != 0) {
                *(s32 *)(self + 0x2B4) = *(s32 *)(d + 0x3FC);
                cnt = p0->count;
                *(s32 *)(self + 0x2BC) = cnt;
                if (cnt > 6) {
                    *(s32 *)(self + 0x2BC) = 6;
                }
                if (*(s32 *)(self + 0x2BC) > 0) {
                    u8 *name;
                    args[n++] = func_00381FF0(0x1608);
                    name = d + 4;
                    args[n++] = sep;
                    if (name != 0) {
                        func_00120048(buf, D_L39_00247C40, name);
                    }
                    args[n++] = buf;
                    args[n++] = p0->items[0];
                }
            }
            {
                u8 *o = *(u8 **)(self + 0x114);
                (*(void (**)(void *, s32, void **))(*(u8 **)(o + 0x60) + 0x6C))(o, n, args);
            }
            {
                u8 *o = *(u8 **)(self + 0x114);
                (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x20))(o, 2, 0);
            }
        }
    }
}
/* localdecomp:end func_L39_0068DDC8 */

/* localdecomp:start func_L39_0068E0E8 */
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern void func_L39_006DCAD0(s32, s32);

/* from rac4-decomp's func_L00_00708980 */
void func_L39_0068E0E8(void) {
    func_L39_006DCAD0(D_L39_0024D760[0x50 / 4], 0);
}
/* localdecomp:end func_L39_0068E0E8 */

/* localdecomp:start func_L39_0068E110 */
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern s32 func_L39_006DE180(s32);
extern s32 func_L01_003A4720(s32);

void func_L39_0068E110(void) {
    func_L39_006DE180(D_L39_0024D760[0x54 / 4]);
    func_L01_003A4720(D_L39_0024D760[0x30 / 4]);
}
/* localdecomp:end func_L39_0068E110 */

LINKER_REMNANT("asm/levels", func_L39_0068E148);

INCLUDE_ASM("asm/levels", func_L39_0068E160);

LINKER_REMNANT("asm/levels", func_L39_0068E9E8);

/* localdecomp:start func_L39_0068E9F0 */
extern u8 D_L39_0047C720[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0068E9F0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C720;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0068E9F0 */

INCLUDE_ASM("asm/levels", func_L39_0068EA18);
