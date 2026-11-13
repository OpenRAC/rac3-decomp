#include "common.h"

/* localdecomp:start func_L39_006C5B30 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006C5B30(void *);

extern void func_L39_0067F168();
void func_L39_006C5B30(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006C5B30 */

/* localdecomp:start func_L39_006C5B60 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 pad[2];
} S_006C5B60;

typedef struct {
    u8 pad[0xB8];
    void (*fn)(void *, void *);
} VT_006C5B60;

typedef struct {
    u8 pad[0x60];
    VT_006C5B60 *vt;
} O_006C5B60;

extern S_006C5B60 D_L39_004B1768[][25];
extern u8 D_L39_00249780[];
extern u8 D_L39_00249788[];
extern u8 D_L39_00249758[];
extern char D_L39_0024D3E0[256] __attribute__((section(".sdata")));
extern void *func_00381FF0(s32);
extern s32 func_00120048(char *, char *, ...);

void func_L39_006C5B60(u8 *obj) {
    *(u8 *)(obj + 0xBB0) = *(s32 *)(obj + 0xD4C) == 1;
    (*(O_006C5B60 **)(obj + 0x130))->vt->fn(*(O_006C5B60 **)(obj + 0x130), func_00381FF0(D_L39_004B1768[*(s32 *)(obj + 0xD4C)][*(s32 *)(obj + 0xB64)].f4));
    if (*(s32 *)(obj + 0xBA8) == 1) {
        func_00120048(D_L39_0024D3E0, (char *)D_L39_00249780, func_00381FF0(0x190A));
    } else {
        func_00120048(D_L39_0024D3E0, (char *)D_L39_00249788, func_00381FF0(0x190B),
                      *(s32 *)(obj + 0xBA8), *(s32 *)(obj + 0xBA8) + *(s32 *)(obj + 0x2B8) - 1);
    }
    (*(O_006C5B60 **)(obj + 0x140))->vt->fn(*(O_006C5B60 **)(obj + 0x140), D_L39_0024D3E0);
    (*(O_006C5B60 **)(obj + 0x148))->vt->fn(*(O_006C5B60 **)(obj + 0x148), D_L39_00249758);
    (*(O_006C5B60 **)(obj + 0x144))->vt->fn(*(O_006C5B60 **)(obj + 0x144), D_L39_00249758);
    *(s32 *)(obj + 0xBA4) = D_L39_004B1768[*(s32 *)(obj + 0xD4C)][*(s32 *)(obj + 0xB64)].f0;
}
/* localdecomp:end func_L39_006C5B60 */

INCLUDE_ASM("asm/levels", func_L39_006C5CC8);
