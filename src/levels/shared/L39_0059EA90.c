#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    char pad0[0xC];
    void *buf;
    int used;
    char pad14[0x30 - 0x14];
} Slot_59EBC8;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 v10[4];
} Info_59EBC8;

/* localdecomp:start func_L39_0059EA90 */
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern Slot_59EBC8 D_L39_002668C0[];
extern Info_59EBC8 D_L39_002667C0[];
extern char D_L39_00266A40[][0x400];
extern void func_0038CBA0(void *, s32);

s32 func_L39_0059EA90(void *pos, s32 color, f32 a, f32 b)
{
    s32 i;
    Info_59EBC8 *in;
    Slot_59EBC8 *s;

    if (*D_00241120 >= 2)
        return -1;
    for (i = 0; i < 8; i++) {
        if (D_L39_002668C0[i].used == 0)
            break;
    }
    if (i == 8)
        return -1;
    s = &D_L39_002668C0[i];
    in = &D_L39_002667C0[i];
    *(u128_t *)in->v10 = *(u128_t *)pos;
    in->v10[3] = a;
    in->f0 = (f32)(color & 0xFF) / 128.0f;
    in->f4 = (f32)((color >> 8) & 0xFF) / 128.0f;
    in->f8 = (f32)((color >> 16) & 0xFF) / 128.0f;
    in->fC = b;
    func_0038CBA0(s, 0x30);
    s->used = 1;
    s->buf = D_L39_00266A40[i];
    return i;
}
/* localdecomp:end func_L39_0059EA90 */

/* localdecomp:start func_L39_0059EBC8 */
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern Slot_59EBC8 D_L39_002668C0[];
extern Info_59EBC8 D_L39_002667C0[];
extern char D_L39_00266A40[][0x400];
extern void func_0038CBA0(void *, s32);

s32 func_L39_0059EBC8(void *pos, f32 a, f32 b, f32 c, f32 d, f32 e)
{
    s32 i;
    Info_59EBC8 *in;
    Slot_59EBC8 *s;

    if (*D_00241120 >= 2)
        return -1;
    for (i = 0; i < 8; i++) {
        if (D_L39_002668C0[i].used == 0)
            break;
    }
    if (i == 8)
        return -1;
    s = &D_L39_002668C0[i];
    in = &D_L39_002667C0[i];
    *(u128_t *)in->v10 = *(u128_t *)pos;
    in->v10[3] = a;
    in->f0 = c;
    in->f4 = d;
    in->f8 = e;
    in->fC = b;
    func_0038CBA0(s, 0x30);
    s->used = 1;
    s->buf = D_L39_00266A40[i];
    return i;
}
/* localdecomp:end func_L39_0059EBC8 */
