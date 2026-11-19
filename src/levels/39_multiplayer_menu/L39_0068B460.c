#include "common.h"

/* localdecomp:start func_L39_0068B460 */
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern u8 D_001DC3F8_sda __attribute__((section(".sdata")));

void func_L39_0068B460(void) {
    D_00241440 = 7;
    D_001DC3F8_sda = 1;
}
/* localdecomp:end func_L39_0068B460 */

/* localdecomp:start func_L39_0068B478 */
extern void func_L39_00595628(u8 *, u8 *);

void func_L39_0068B478(u8 *s)
{
    u8 buf[0x200];
    u8 *d = buf;
    u8 *p = s;
    while (*p) {
        *d++ = 0;
        *d++ = *p++;
    }
    d[0] = 0;
    d[1] = 0;
    func_L39_00595628(buf, s);
}
/* localdecomp:end func_L39_0068B478 */

/* localdecomp:start func_L39_0068B4D0 */
typedef struct {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_0068B4D0;
typedef struct {
    H_0068B4D0 b;
    u8 f48;
    s32 f4C;
} Sld_0068B4D0;
typedef struct {
    H_0068B4D0 b;
    s32 f48;
    s32 count;
    void *items[0x60];
} List_0068B4D0;

extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);
extern u8 D_L39_0047C420[];
extern f32 D_L39_004AE308[];
extern u8 D_L39_00247B10[];
extern s32 D_001DC3F4_sda;

static __inline__ void lab_0068B4D0(H_0068B4D0 *l, s32 text, f32 x, f32 y, f32 w, f32 h) {
    l->type = 0;
    func_L39_0068CD28((u8 *)l, text, x, y, w, h);
    l->type = 1;
}
static __inline__ void sld_0068B4D0(Sld_0068B4D0 *s, s32 text, f32 x, f32 y, f32 w, f32 h, s32 max) {
    s->b.type = 0;
    func_L39_0068CD28((u8 *)s, text, x, y, w, h);
    s->b.type = 4;
    s->f4C = max;
    s->f48 = 0;
}
static __inline__ void list_0068B4D0(List_0068B4D0 *l) {
    l->b.type = 0;
    func_L39_0068CD28((u8 *)l, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    l->f48 = 0x2E;
    l->count = 0;
    l->b.x = 0.0f;
    l->b.y = 0.0f;
    l->b.w = 1.0f;
    l->b.h = 1.0f;
}

void *func_L39_0068B4D0(void *arg0)
{
    List_0068B4D0 list;
    Sld_0068B4D0 sld;
    H_0068B4D0 items[6];
    H_0068B4D0 *it;
    s32 i;
    s32 j;

    func_L39_00688388(arg0);
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047C420;
    *(void **)((u8 *)arg0 + 0x2A4) = (u8 *)arg0 + 0x33C;
    *(s32 *)((u8 *)arg0 + 0x338) = 0;
    list_0068B4D0(&list);
    list.count = 7;
    sld_0068B4D0(&sld, (s32)D_L39_00247B10, D_L39_004AE308[0], D_L39_004AE308[1], D_L39_004AE308[2], D_L39_004AE308[3], 0x22);
    list.items[0] = &sld;
    it = items;
    for (i = 5; i != -1; i--) {
        lab_0068B4D0(it, 0, 1.0f, 1.0f, 1.0f, 1.0f);
        it++;
    }
    for (j = 5; j >= 0; j--) {
        list.items[j + 1] = &items[j];
    }
    func_L39_00689670(arg0, &list);
    *(s32 *)((u8 *)arg0 + 0x290) = 1;
    *((u8 *)arg0 + 0x2B8) = 0;
    *((u8 *)arg0 + 0x2B9) = 0;
    *((u8 *)arg0 + 0x2BA) = 0;
    *((u8 *)arg0 + 0x2BB) = 0;
    if (D_001DC3F8_sda) {
        D_001DC3F8_sda = 0;
        D_001DC3F4_sda = 4;
    }
    return arg0;
}
/* localdecomp:end func_L39_0068B4D0 */

LINKER_REMNANT("asm/levels", func_L39_0068B688);

/* localdecomp:start func_L39_0068B690 */
extern u8 D_L39_0047C420[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0068B690(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C420;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0068B690 */

/* localdecomp:start func_L39_0068B6B8 */
s32 func_00381FF0(s32);
void func_L39_0067F100(s32);
void func_L39_00689BD8(void *, s32);
void func_L39_00689D28(void *, s32);
void func_L39_00689DB8(void *, s32);
void func_L39_0068A9B8(s32);
void func_L39_0068AAB8(void *);
void func_L39_0068C718(void *);

void func_L39_0068B6B8(void *arg0) {
    func_L39_0067F100(0x210000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(arg0, func_00381FF0(0x10C7));
    func_L39_00689D28(arg0, func_00381FF0(0x124));
    func_L39_00689DB8(arg0, func_00381FF0(0xCD5));
    func_L39_0068AAB8(arg0);
    *(s32 *)((u8 *)arg0 + 0x338) = 0;
    func_L39_0068C718(arg0);
}
/* localdecomp:end func_L39_0068B6B8 */
