#include "common.h"

typedef struct Obj_003A88E8 {
    u8 pad0[0x94C];
    s16 f94C;
    u8 pad94E[0x0E];
    s32 f95C;
    u8 pad960[0x20];
    s32 f980;
    s32 f984;
} Obj_003A88E8;


typedef struct {
    u8 pad0[0x954];
    s32 f0;
    f32 f4;
} S_3A8998;

INCLUDE_ASM("asm/levels", func_L24_003A8668);

INCLUDE_ASM("asm/levels", func_L24_003A8898);

/* localdecomp:start func_L24_003A88E8 */
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00404808(void (*)(void), void *);
extern void func_L24_003A7F58(void);

void func_L24_003A88E8(u8 *a0) {
    Obj_003A88E8 *obj;
    s32 c;

    obj = *(Obj_003A88E8 **)(a0 + 0x68);
    if (obj->f980 != 0) {
        obj->f984++;
        if (obj->f984 >= 0x1F5) {
            obj->f984 = 0;
            obj->f980 = 0;
        }
    }
    if (obj->f94C > 0) {
        obj->f94C--;
        c = obj->f95C;
        if (c >= 2) {
            if (obj->f94C == 0) {
                c--;
                obj->f95C = c;
                obj->f94C = 10;
            }
        }
    }
    func_003C2F58(a0, 2, *(u8 **)(a0 + 0x68) + 0x960);
    func_L01_00404808(func_L24_003A7F58, a0);
}
/* localdecomp:end func_L24_003A88E8 */

/* localdecomp:start func_L24_003A8998 */
extern u8 D_001A4C60[];
extern u8 *D_001D52FC;
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L24_003A8998(u8 *a0) {
    S_3A8998 *p = *(S_3A8998 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        p->f0 = 0;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_0038CF38(D_001A4C60, a0 + 0x10) <= p->f4) {
            func_L01_00452560(0, 1, 0x16BE, 1, 0, 0, 0);
            if (*(u32 *)(D_001D52FC + 0x1A4) & 0x10) {
                p->f0++;
                if (p->f0 >= *(u8 *)(*(u8 **)(a0 + 0x24) + 0xC)) {
                    p->f0 = 0;
                }
                func_L01_004450F0(a0, 2, -1);
            }
        }
        break;
    case 2:
        if (a0[0x43] != p->f0) {
            func_003C3A10(a0, p->f0, 0, 10);
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L24_003A8998 */
