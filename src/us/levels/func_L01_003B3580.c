#include "common.h"

/* NTSC-U counterpart of func_L01_003B4D80 (src/levels/shared/L01_003B4D80.c) */
extern void func_L01_003B3580(u8 *, u8 *);
extern s32 D_L01_001DE674_003B3580;

/* localdecomp:start func_L01_003B3580 */
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_L01_00512FE8(s32, char *);
extern s32 func_L01_003B3018(void *a, u8 *b);
extern s32 D_L01_001DFBC0_003B3580;
__asm__(".extern D_L01_001DFBC0_003B3580, 16");
extern char D_L01_001DE760_003B3580[];
extern char D_L01_001DE768_003B3580[];
extern char D_L01_001DE778_003B3580[];
extern char D_L01_001DE780[];
extern char D_L01_001E21B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E21B0, 4");
extern char D_L01_001E21F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E21F0, 4");
extern s32 D_L01_001E00D8;
__asm__(".extern D_L01_001E00D8, 4");
extern s16 *D_L01_0021DEA0[];
extern u8 *D_L01_001E009C_003B3580;
__asm__(".extern D_L01_001E009C_003B3580, 16");

void func_L01_003B3580(u8 *a0, u8 *a1) {
    s32 t;
    s32 rem;
    s32 mins;
    s32 secs;
    s32 diff;
    u8 *n;
    u8 *s;
    s16 *q;

    t = *(s32 *)(a1 + 0x24);
    if (t == 0) {
        return;
    }
    rem = t * 60 - (D_L01_001DFBC0_003B3580 - *(s32 *)(*(u8 **)(*(u8 **)(a1 + 8) + 0x68) + 0x60));
    if (rem < 0) {
        rem = 0;
    }
    secs = rem / 60 % 60;
    mins = rem / 3600;
    if (rem % 60 != 0) {
        secs++;
        if (secs >= 60) {
            mins++;
            secs = 0;
        }
    }
    func_0011B2E8(D_L01_001E21B0, D_L01_001DE768_003B3580, mins < 10 ? D_L01_001DE778_003B3580 : D_L01_001DE760_003B3580, mins,
                  secs < 10 ? D_L01_001DE778_003B3580 : D_L01_001DE760_003B3580, secs);
    func_L01_00512FE8(0x140004, D_L01_001E21B0);
    if (func_L01_003B3018(a0, a1) == 0) {
        return;
    }
    if ((u8 *)D_L01_001DE674_003B3580 != 0) {
        diff = 0;
        for (n = (u8 *)D_L01_001DE674_003B3580; n != 0; n = *(u8 **)(s + 0x58)) {
            s = *(u8 **)(n + 0x68);
            if (*(s32 *)s == 0x1D75) {
                diff = *(s32 *)(s + 0xC0) - *(s32 *)(s + 0xC4);
                break;
            }
        }
        func_0011B2E8(D_L01_001E21F0, D_L01_001DE780, diff);
        func_L01_00512FE8(0x140007, D_L01_001E21F0);
    } else {
        if (*(s32 *)(a1 + 0xC) != -1) {
            diff = 0;
            for (q = D_L01_0021DEA0[*(s32 *)(a1 + 0xC)]; (*(s32 *)(a1 + 0xC) & 0xFF) != 0xFF && *(s32 *)(a1 + 0xC) <= D_L01_001E00D8 && q != 0 && (q[-1] >= 0 || q == D_L01_0021DEA0[*(s32 *)(a1 + 0xC)]); q++) {
                n = D_L01_001E009C_003B3580 + ((*(u16 *)q & 0x7FFF) << 8);
                if (n == 0) break;
                s = *(u8 **)(n + 0x68);
                if (*(s32 *)s == 0x1D75) {
                    diff = *(s32 *)(s + 0xC0) - *(s32 *)(s + 0xC4);
                    break;
                }
            }
            func_0011B2E8(D_L01_001E21F0, D_L01_001DE780, diff);
            func_L01_00512FE8(0x140007, D_L01_001E21F0);
        } else {
            func_L01_00512FE8(0x140007, D_L01_001DE778_003B3580);
        }
    }
}
/* localdecomp:end func_L01_003B3580 */
