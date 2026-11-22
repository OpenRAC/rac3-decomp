#include "common.h"

typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
typedef void (*Fn_6600D8)(void *, void *);
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;

/* localdecomp:start func_L39_00666E48 */
typedef struct { u8 pad0[0x1A14]; u8 b1A14; u8 pad1[0x2524 - 0x1A15]; s32 x2524; u8 pad2[0x2558 - 0x2528]; s32 x2558; } P_00666E48;
extern P_00666E48 *D_L39_0024CE20_00666E48[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20_00666E48, 32");
extern u8 D_001A5CD0[];
extern s32 func_00197548(void);
extern void func_L39_006703B0_00666E48(s32);
extern void func_L39_00640698_00666E48(void *);
extern void func_L39_0061C258_00666E48(s32);
extern void func_003C2880(s32);
extern void func_L39_006683F8_00666E48(void *, s32);
extern void func_L39_0066C5B0_00666E48(void);
extern void func_L39_0066D3A8_00666E48(s32, s32);

void func_L39_00666E48(s32 *a0) {
    s32 i;
    P_00666E48 *p;
    for (i = 0; i < 8; i++) {
        if (D_L39_0024CE20_00666E48[i] == 0) continue;
        if (D_L39_0024CE20_00666E48[i]->x2558 == 0) continue;
        if (D_L39_0024CE20_00666E48[i]->x2558 != (s32)a0) continue;
        if (D_L39_0024CE20_00666E48[i]->b1A14 != 0 && func_00197548() != 0) continue;
        p = D_L39_0024CE20_00666E48[i];
        if (D_001A5CD0[0x7D5 + i] != 2) {
            D_001A5CD0[0x7D5 + i] = 2;
            func_L39_006703B0_00666E48((s32)a0 + 0x1B0);
        }
        func_L39_00640698_00666E48(p);
        func_L39_0061C258_00666E48(p->x2524);
        func_003C2880(p->x2524);
        p->x2524 = 0;
        p->x2558 = 0;
        D_L39_0024CE20_00666E48[i] = 0;
        func_L39_006683F8_00666E48(p, *a0);
        func_L39_0066C5B0_00666E48();
        func_L39_0066D3A8_00666E48(i, *a0);
        return;
    }
}
/* localdecomp:end func_L39_00666E48 */

LINKER_REMNANT("asm/levels", func_L39_00666F58);

/* localdecomp:start func_L39_00666F68 */
s32 func_L39_00666F68(void) {
    return 0;
}
/* localdecomp:end func_L39_00666F68 */

/* localdecomp:start func_L39_00666F70 */
s32 func_L39_00666F70(u8 *a0, s32 a1) {
    return *(s32 *)(a0 + 0x32C) == a1;
}
/* localdecomp:end func_L39_00666F70 */
