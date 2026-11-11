#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C69C0 */
typedef struct { s32 a, b, c, type; } S_006C69C0;
extern S_006C69C0 D_L39_004B1768_006C69C0[][25];
extern char D_002497D0[];
extern f32 D_001DDFFC_sda;
extern f32 D_001DE000_sda;
extern f32 D_001DDF60_sda;
extern f32 D_001DDF58_sda;
extern f32 D_001DDF10_sda;
extern s32 func_00381FF0();
__asm__(".extern D_001DDFFC_sda, 4");
__asm__(".extern D_001DE000_sda, 4");
__asm__(".extern D_001DDF60_sda, 4");
__asm__(".extern D_001DDF58_sda, 4");
__asm__(".extern D_001DDF10_sda, 4");

void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
typedef struct O_006C69C0 O_006C69C0;
typedef struct {
    u8 pad[0x6C];
    void (*f6C)(O_006C69C0 *, s32, char **);
    u8 pad2[0x94 - 0x70];
    void (*f94)(O_006C69C0 *, f32);
} Vt_006C69C0;
struct O_006C69C0 { u8 pad[0x60]; Vt_006C69C0 *vt; };

void func_L39_006C69C0(u8 *arg0, s32 idx) {
    char *names[25];
    s32 count;
    s32 i;
    s32 n;

    if (idx == -1) {
        idx = *(s32 *)(arg0 + 0xD4C);
    }
    count = 0;
    for (i = 0; i < 25 && D_L39_004B1768_006C69C0[idx][i].a != 0; i++) {
        if (D_L39_004B1768_006C69C0[idx][i].b != 0) {
            names[i] = (char *)func_00381FF0(D_L39_004B1768_006C69C0[idx][i].b);
        } else {
            names[i] = D_002497D0;
        }
        count++;
    }
    (*(O_006C69C0 **)(arg0 + 0x12C))->vt->f6C(*(O_006C69C0 **)(arg0 + 0x12C), count, names);
    if (idx == 6) {
        (*(O_006C69C0 **)(arg0 + 0x12C))->vt->f94(*(O_006C69C0 **)(arg0 + 0x12C), D_001DDFFC_sda);
    } else {
        (*(O_006C69C0 **)(arg0 + 0x12C))->vt->f94(*(O_006C69C0 **)(arg0 + 0x12C), D_001DE000_sda);
    }
    n = count - 1;
    if (n >= 13) {
        n = 12;
    }
    func_L39_0068A4A8(arg0, 0, n, 0x332299DE, D_001DDF58_sda, 0.265f, D_001DDF10_sda, D_001DDF60_sda - 0.035f);
}
/* localdecomp:end func_L39_006C69C0 */

INCLUDE_ASM("asm/levels", func_L39_006C6B30);

INCLUDE_ASM("asm/levels", func_L39_006C7128);

INCLUDE_ASM("asm/levels", func_L39_006C7800);

/* localdecomp:start func_L39_006C7B40 */
typedef struct { s32 a, b, c, type; } S_006C7B40;
extern S_006C7B40 D_L39_004B1768[][25];
extern f32 D_001A6A24 __attribute__((section(".data")));
extern char D_002497E8[];
extern char D_002497F0[];
extern char D_002497F8[];
s32 func_001321C8(f32);
s32 func_00120048(char *, const char *, ...);

void func_L39_006C7B40(u8 *arg0, char *buf, s32 value, s32 arg3) {
    s32 type = D_L39_004B1768[*(s32 *)(arg0 + 0xD4C)][*(s32 *)(arg0 + 0xB64)].type;

    if (type == 1) {
        func_00120048(buf, D_002497F0, func_001321C8(value / D_001A6A24));
    } else if (type == 2) {
        func_00120048(buf, D_002497E8, arg3);
    } else if (value > 99999) {
        value = (value + 500) / 1000;
        func_00120048(buf, D_002497F8, value);
    } else {
        func_00120048(buf, D_002497E8, value);
    }
}
/* localdecomp:end func_L39_006C7B40 */
