#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* localdecomp:start func_L39_00686138 */
typedef struct {
    u8 pad0[0x1C0];
    u32 f1C0;
    u32 f1C4;
    u8 pad1C8[0x5C0 - 0x1C8];
} Pad_00686138;

extern Pad_00686138 D_00225780[];
extern s32 D_001DC210_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DC210_sda, 8");
extern s32 D_001DC230_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DC230_sda, 8");
extern s32 D_001DC250_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DC250_sda, 8");
extern s32 D_001DC270_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DC270_sda, 8");

s32 func_L39_00686138(u8 *self, Pad_00686138 *pad) {
    s32 r = 0;
    s32 i = pad - D_00225780;

    if (*(s32 *)(self + 0x270) >= 0 || *(s32 *)(self + 0x274) >= 0) {
        if (pad->f1C4 & 0x40) {
            r = 7;
        } else if (pad->f1C4 & 0x10) {
            r = 5;
        } else if (pad->f1C0 & 0x1000) {
            r = 1;
        } else if (pad->f1C0 & 0x4000) {
            r = 2;
        } else if (pad->f1C0 & 0x8000) {
            r = 3;
        } else if (pad->f1C0 & 0x2000) {
            r = 4;
        } else if (pad->f1C4 & 0x80) {
            r = 8;
        } else if (pad->f1C4 & 0x20) {
            r = 6;
        } else if (pad->f1C4 & 0x100) {
            r = 9;
        } else if (pad->f1C4 & 0x800) {
            r = 10;
        } else if (pad->f1C4 & 0x4) {
            r = 11;
        } else if (pad->f1C4 & 0x1) {
            r = 12;
        } else if (pad->f1C4 & 0x200) {
            r = 13;
        } else if (pad->f1C4 & 0x8) {
            r = 14;
        } else if (pad->f1C4 & 0x2) {
            r = 15;
        } else if (pad->f1C4 & 0x400) {
            r = 16;
        }
        if (r == D_001DC210_sda[i]) {
            if (D_001DC230_sda[i] <= 0 || --D_001DC230_sda[i] <= 0) {
                if (D_001DC250_sda[i] < 6) {
                    D_001DC250_sda[i]++;
                }
                D_001DC230_sda[i] = D_001DC270_sda[D_001DC250_sda[i]];
            } else {
                r = 0;
            }
        } else {
            D_001DC210_sda[i] = r;
            D_001DC250_sda[i] = 0;
            D_001DC230_sda[i] = D_001DC270_sda[0];
        }
    }
    return r;
}
/* localdecomp:end func_L39_00686138 */

INCLUDE_ASM("asm/levels", func_L39_006862D0);
