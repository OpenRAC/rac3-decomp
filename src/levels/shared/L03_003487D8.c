#include "common.h"

/* localdecomp:start func_L03_003487D8 */
extern s32 D_L03_001DF6B8;
extern u16 D_001A4DC0[];
extern u8 D_L03_001E13C8[];
extern s32 *D_L03_00281DA0[];
extern s32 D_L03_00281FA0[][2];
extern u8 *D_001D52FC;
extern void func_003C2880(u8 *);
extern void func_L01_00448248(s32 *, s32, s32);
extern void func_L01_00404808(void (*)(void), u8 *);
extern void func_L03_00348C90();

void func_L03_003487D8(u8 *obj) {
    s32 *st = *(s32 **)(obj + 0x68);
    s32 step = 0;
    D_L03_001DF6B8 = 1;
    D_001A4DC0[0] = 5;
    if (*(unsigned long *)(D_001D52FC + 0x1A0) & 0x9000000000UL) {
        func_003C2880(obj);
        return;
    }
    if (*(s32 *)(D_001D52FC + 0x1A4) & 0x4000) {
        func_L01_00448248(st, st[1] - 1, 1);
        if (st[2] < st[0] - 15) st[2]++;
    } else if (*(s32 *)(D_001D52FC + 0x1A4) & 0x1000) {
        func_L01_00448248(st, 0, 1);
        if (st[0] < st[2]) st[2]--;
    } else if (*(s32 *)(D_001D52FC + 0x1A0) & 0x2000) {
        step = (*(s32 *)(D_001D52FC + 0x1A0) & 15) ? 5 : 1;
    } else if (*(s32 *)(D_001D52FC + 0x1A0) & 0x8000) {
        step = (*(s32 *)(D_001D52FC + 0x1A0) & 15) ? -5 : -1;
    }
    if (step && *(u16 *)(obj + 0x96) >= 5) {
        *(u16 *)(obj + 0x96) = 0;
        switch (D_L03_001E13C8[st[0]]) {
        case 0: {
            s32 value = *D_L03_00281DA0[st[0]];
            value += step;
            if (value > D_L03_00281FA0[st[0]][1]) value = D_L03_00281FA0[st[0]][1];
            else if (value < D_L03_00281FA0[st[0]][0]) value = D_L03_00281FA0[st[0]][0];
            *D_L03_00281DA0[st[0]] = value;
            break;
        }
        case 1: {
            f32 value = *(f32 *)D_L03_00281DA0[st[0]] + step * 0.01f;
            if (value > D_L03_00281FA0[st[0]][1]) value = D_L03_00281FA0[st[0]][1];
            else if (value < D_L03_00281FA0[st[0]][0]) value = D_L03_00281FA0[st[0]][0];
            *(f32 *)D_L03_00281DA0[st[0]] = value;
            break;
        }
        case 2: {
            u8 value = *(u8 *)D_L03_00281DA0[st[0]];
            value += step;
            if (value > D_L03_00281FA0[st[0]][1]) value = D_L03_00281FA0[st[0]][1];
            else if (value < D_L03_00281FA0[st[0]][0]) value = D_L03_00281FA0[st[0]][0];
            *(u8 *)D_L03_00281DA0[st[0]] = value;
            break;
        }
        case 3: {
            s16 value = *(s16 *)D_L03_00281DA0[st[0]];
            value += step;
            if (value > D_L03_00281FA0[st[0]][1]) value = D_L03_00281FA0[st[0]][1];
            else if (value < D_L03_00281FA0[st[0]][0]) value = D_L03_00281FA0[st[0]][0];
            *(s16 *)D_L03_00281DA0[st[0]] = value;
            break;
        }
        }
    }
    func_L01_00404808(func_L03_00348C90, obj);
    (*(u16 *)(obj + 0x96))++;
}
/* localdecomp:end func_L03_003487D8 */

INCLUDE_ASM("asm/levels", func_L03_00348B88);

INCLUDE_ASM("asm/levels", func_L03_00348C18);

/* localdecomp:start func_L03_00348C90 */
extern void func_003A9440(s32, long);
extern s32 func_00381FF0(s32);
extern void func_L01_00421738(s32, s32, s32, s32, s32, s32);
extern void func_L03_00400000(s32, s32, unsigned long, s32, s32);
extern void func_11B2E8(char *, char *, ...);
extern long func_129A18(f32);

__asm__(".extern D_L03_001DD568, 4");
__asm__(".extern D_L03_001DD578, 4");
__asm__(".extern D_L03_001DD57C, 4");
__asm__(".extern D_L03_001DD580, 4");
__asm__(".extern D_L03_001DD584, 4");
__asm__(".extern D_L03_001DD594, 4");
extern s32 D_L03_001DD568;
extern s32 D_L03_001DD56C;
extern s32 D_L03_001DD570;
extern s32 D_L03_001DD578;
extern s32 D_L03_001DD57C;
extern s32 D_L03_001DD580;
extern s32 D_L03_001DD584;
extern s32 D_L03_001DD58C;
extern s32 D_L03_001DD594;
extern char D_L03_001DD598[];
extern char D_L03_001DD5A0[];
extern char D_L03_001DD5A8[];
extern char D_L03_001DD5B0[];
extern s32 *D_L03_00281DA0[];
extern s32 D_L03_00281EA0[];
extern u8 D_L03_001E13C8[];

void func_L03_00348C90(char *obj) {
    char text[256];
    s32 i = 0, count = 0;
    s32 *st = *(s32 **)(obj + 0x68);
    func_003A9440(0x42, 0x8000000044LL);
    func_L01_00421738(D_L03_001DD568, D_L03_001DD56C, D_L03_001DD570, D_L03_001DD56C + D_L03_001DD578 * (st[1] < 17 ? st[1] : 16), D_L03_001DD594, 0);
    func_L03_00400000(2, 8, D_L03_001DD58C, func_00381FF0(0x1EBE), -1);
    for (; i < 64 - st[2] && count < st[1] && count < 16; i++) {
        if (!D_L03_00281DA0[i + st[2]]) continue;
        count++;
        if (D_L03_00281EA0[i]) {
            func_11B2E8(text, D_L03_001DD598, D_L03_00281EA0[i + st[2]]);
            func_L03_00400000(D_L03_001DD580, D_L03_001DD584 + i * D_L03_001DD578, D_L03_001DD58C, (s32)text, -1);
        }
        if (st[0] == i + st[2]) {
            func_11B2E8(text, D_L03_001DD5A0);
            func_L03_00400000(D_L03_001DD580 - 16, D_L03_001DD584 + i * D_L03_001DD578, 0x80008000UL, (s32)text, -1);
        }
        switch (D_L03_001E13C8[i + st[2]]) {
        case 0:
            func_11B2E8(text, D_L03_001DD5A8, *D_L03_00281DA0[i + st[2]]);
            func_L03_00400000(D_L03_001DD57C, D_L03_001DD584 + i * D_L03_001DD578, 0x80008080UL, (s32)text, -1);
            break;
        case 1:
            func_11B2E8(text, D_L03_001DD5B0, func_129A18(*(f32 *)D_L03_00281DA0[i + st[2]]));
            func_L03_00400000(D_L03_001DD57C, D_L03_001DD584 + i * D_L03_001DD578, 0x80008080UL, (s32)text, -1);
            break;
        case 2:
            func_11B2E8(text, D_L03_001DD5A8, *(u8 *)D_L03_00281DA0[i + st[2]]);
            func_L03_00400000(D_L03_001DD57C, D_L03_001DD584 + i * D_L03_001DD578, 0x80008080UL, (s32)text, -1);
            break;
        case 3:
            func_11B2E8(text, D_L03_001DD5A8, *(s16 *)D_L03_00281DA0[i + st[2]]);
            func_L03_00400000(D_L03_001DD57C, D_L03_001DD584 + i * D_L03_001DD578, 0x80008080UL, (s32)text, -1);
            break;
        case 4:
            break;
        }
    }
}
/* localdecomp:end func_L03_00348C90 */
