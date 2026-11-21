#include "common.h"

/* declared by functions of L01_0047F220.c, which this file was cut from */
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00492870(void);

/* localdecomp:start func_L01_00480800 */
typedef struct {
    u8 pad0[4];
    s32 type;
    u8 pad8[4];
    u8 enabled;
    u8 on;
    u8 padE[6];
    s32 w14;
} S_00480800;

extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, s32);
extern s32 func_003B9C58(s32);
extern s32 func_L01_00517190(s32, s32);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00498948(s32, s32, s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_00480800(void *);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern s32 func_L01_0047EBE0(void);
extern u8 *D_001D52FC;
extern S_00480800 D_L01_002EA230[];
extern u8 D_001D5468[] __attribute__((section(".sdata")));
extern u8 D_001D5470[] __attribute__((section(".sdata")));
extern u8 D_001D5471[] __attribute__((section(".sdata")));
extern u8 D_L01_001D672C;
__asm__(".extern D_L01_001D672C, 16");

void func_L01_00480800(void *menu) {
    s32 i;
    S_00480800 *e;
    s32 v;

    func_003BA4F8(func_003B9BD0(0), *(s32 *)(D_001D52FC + 0x1C4));
    i = func_003B9C58(func_003B9BD0(0));
    if (D_L01_002EA230[i].enabled) {
        func_L01_00517190(0x520003, D_L01_002EA230[i].w14);
    } else {
        func_L01_00517190(0x520003, 1);
    }
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
        i = func_003B9C58(func_003B9BD0(0));
        e = &D_L01_002EA230[i];
        if (e->enabled) {
            v = e->on ^ 1;
            e->on = v;
            D_001D5468[D_L01_002EA230[i].type] = v;
            if (D_L01_002EA230[i].type == 10) {
                D_001D5470[0] = v;
            }
            if (D_L01_002EA230[i].type == 11) {
                D_001D5471[0] = e->on;
            }
            func_003A5348(4, 0, 0);
            func_L01_00498948(func_003B9BD0(0), i, e->on ? 3 : 0);
        }
    } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x10) {
        func_L01_00517748(func_L01_00492870());
        func_L01_00516090_00480800(menu);
        func_003A5348(4, 0, 0);
    }
    if (func_L01_0047DAB0()) {
        func_L01_0047DAC8();
        func_L01_00516090_00480800(menu);
        if (D_L01_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_00480800 */
