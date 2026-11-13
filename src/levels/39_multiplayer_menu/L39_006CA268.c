#include "common.h"

/* declared by functions of L39_006C99F0.c, which this file was cut from */
s32 func_L39_00688340(s32, s32, s32);
extern s32 *D_L39_0024D760;
extern u8 *D_L39_00247914;

/* localdecomp:start func_L39_006CA268 */
/* pattern from L39_0068DDC8.c: scalar pointer with .extern size hint */
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern void func_L39_006D0078(void *);

s32 func_L39_006CA268(u8 *arg0)
{
    func_L39_006D0078((void *)D_L39_0024D760[0x38 / 4]);
    arg0[0x2A8] = 1;
    return 1;
}
/* localdecomp:end func_L39_006CA268 */

LINKER_REMNANT("asm/levels", func_L39_006CA2A8);

INCLUDE_ASM("asm/levels", func_L39_006CA2C0);

LINKER_REMNANT("asm/levels", func_L39_006CA6C0);

/* localdecomp:start func_L39_006CA6C8 */
extern u8 D_L39_0047EDC0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006CA6C8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EDC0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006CA6C8 */

/* localdecomp:start func_L39_006CA6F0 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots 0x196C..0x197C. */
extern f32 D_001DE21C_sda;
extern f32 D_001DE220_sda;
extern f32 D_001DE224_sda;
extern f32 D_001DE228_sda;
extern f32 D_001DE22C_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_006CA6F0(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DE21C_sda, D_001DE220_sda, D_001DE224_sda, D_001DE228_sda, D_001DE22C_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_006CA6F0 */

/* localdecomp:start func_L39_006CA730 */
extern f32 D_001DE230_sda;
extern f32 D_001DE234_sda;
extern f32 D_001DE238_sda;
extern f32 D_001DE23C_sda;
extern f32 D_001DE240_sda;
extern f32 D_001DE244_sda;
extern f32 D_001DE248_sda;
extern f32 D_001DE24C_sda;
extern f32 D_001DE250_sda;
void func_L39_0067F100(s32);
void func_L39_0068AAB8(void *);
void func_L39_0068A4A8(void *, s32, s32, s32, f32, f32, f32, f32);
void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
void func_L39_006CAAE8(void *, s32);

typedef struct V_006CA730 {
    u8 pad[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x40 - 0x24];
    void (*f40)(void *, s32);
    void (*f44)(void *, s32, void *, f32, f32);
    void (*f48)(void *, s32, s32);
    void (*f4C)(void *, s32, s32);
} V_006CA730;

typedef struct O_006CA730 {
    u8 pad[0x60];
    V_006CA730 *vt;
} O_006CA730;

typedef struct S_006CA730 {
    u8 pad[0x110];
    O_006CA730 *items[7];
    u8 pad12C[0x6B0 - 0x12C];
    s32 sel;
    u8 flag;
} S_006CA730;

void func_L39_006CA730(S_006CA730 *arg0)
{
    O_006CA730 **p;
    f32 b;
    s32 i;

    func_L39_0067F100(0x2E0000);
    func_L39_0068AAB8(arg0);
    b = D_001DE234_sda + ((D_001DE23C_sda - D_001DE240_sda) * -2.5f) / 7.0f;
    func_L39_0068A4A8(arg0, 0, 6, 0x332299DE, D_001DE230_sda, b + D_001DE244_sda,
                      (D_001DE234_sda + ((D_001DE23C_sda - D_001DE240_sda) * -1.5f) / 7.0f) - b, D_001DE238_sda - D_001DE240_sda);
    func_L39_00689F00(arg0, 0, 3, 3, 1.5f, 1.5f, D_001DE238_sda - D_001DE240_sda, D_001DE248_sda, D_001DE24C_sda, D_001DE250_sda);
    arg0->items[0]->vt->f4C(arg0->items[0], 0x40, 1);
    arg0->items[0]->vt->f20(arg0->items[0], 1, 0);
    arg0->items[0]->vt->f44(arg0->items[0], 1, arg0->items[0], D_001DE238_sda - D_001DE240_sda, 0.0f);
    p = &arg0->items[1];
    for (i = 5; i >= 0; i--) {
        (*p)->vt->f40(*p, 1);
        (*p)->vt->f48(*p, 1, 3);
        p++;
    }
    arg0->flag = 0;
    func_L39_006CAAE8(arg0, arg0->sel);
}
/* localdecomp:end func_L39_006CA730 */

/* localdecomp:start func_L39_006CA8C8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006CA8C8(void *);

extern void func_L39_0067F168();
void func_L39_006CA8C8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006CA8C8 */

/* localdecomp:start func_L39_006CA8F8 */
__asm__(".extern D_L39_00247914, 16");
extern u8 *D_L39_00247914;
extern f32 D_001DE254_sda;
extern f32 D_001DE230_sda;
void func_L39_006B7E90(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_L39_00688340(s32, s32, s32);
void func_L39_006CAD88(void *);
void func_L39_006CAC48(void *);
s32 func_L39_0068AEF8(void *, s32);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

typedef struct { u8 pad[0x110]; u8 *items[0x60]; s32 cur; } S_006CA8F8;

s32 func_L39_006CA8F8(u8 *arg0, s32 arg1)
{
    f32 pos[2];
    u8 *obj;
    s32 flags;

    func_L39_006B7E90(1, 0, 0x190, 0, 0x82);
    if (arg1 == 1) {
        func_L39_00688340(3, 0, 0);
        func_L39_006CAD88(arg0);
        return 1;
    }
    if (arg1 == 2) {
        func_L39_00688340(3, 0, 0);
        func_L39_006CAC48(arg0);
        return 1;
    }
    if (arg1 == 7) {
        func_L39_00688340(4, 0, 0);
        *(s32 *)(D_L39_00247914 + 0x284) = 0x2C;
        return 1;
    }
    if (arg1 == 5) {
        arg0[0x6B4] = 1;
    }
    if (func_L39_0068AEF8(arg0, arg1)) {
        return 1;
    }
    obj = ((S_006CA8F8 *)arg0)->items[((S_006CA8F8 *)arg0)->cur];
    (*(void (**)(void *, void *, void *))(*(u8 **)(obj + 0x60) + 0x30))(obj, &pos[0], &pos[1]);
    flags = 0;
    if (*(s32 *)(arg0 + 0x6B0) > 0) {
        flags |= 1;
    }
    if (*(s32 *)(arg0 + 0x6B0) < *(s32 *)(arg0 + 0x6A8) - 1) {
        flags |= 2;
    }
    func_L39_0068A2D0(arg0, flags, 3, 3, D_001DE230_sda, pos[1] + D_001DE254_sda);
    return 0;
}
/* localdecomp:end func_L39_006CA8F8 */
