#include "common.h"

/* declared by functions of L39_006C99F0.c, which this file was cut from */
s32 func_L39_00688340(s32, s32, s32);
extern s32 *D_L39_0024D760;
extern u8 *D_L39_00247914;

/* localdecomp:start func_L39_006CA2C0 */
typedef struct Item_006CA2C0 {
    s32 type;
    u8 name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    s32 flags;
    s32 count;
} Item_006CA2C0;

typedef struct Group_006CA2C0 {
    Item_006CA2C0 hdr;
    Item_006CA2C0 *children[0x60];
} Group_006CA2C0;

__asm__(".extern D_001DE230_sda, 4");
__asm__(".extern D_001DE234_sda, 4");
__asm__(".extern D_001DE238_sda, 4");
__asm__(".extern D_001DE23C_sda, 4");
__asm__(".extern D_001DE240_sda, 4");
extern f32 D_001DE230_sda;
extern f32 D_001DE234_sda;
extern f32 D_001DE238_sda;
extern f32 D_001DE23C_sda;
extern f32 D_001DE240_sda;
extern u8 D_L39_00249968[];
extern u8 D_L39_0047EDC0[];
void func_L39_00688388(void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_L39_00689670(void *, void *);

static __inline__ void base_init_006CA2C0(Item_006CA2C0 *it, s32 name, f32 x, f32 y, f32 w, f32 h)
{
    it->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
}

static __inline__ void item_init_006CA2C0(Item_006CA2C0 *it, s32 name, f32 x, f32 y, f32 w, f32 h)
{
    base_init_006CA2C0(it, name, x, y, w, h);
    it->type = 1;
}

static __inline__ void group_init_006CA2C0(Group_006CA2C0 *g)
{
    base_init_006CA2C0(&g->hdr, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    g->hdr.flags = 0x2E;
    g->hdr.count = 0;
    g->hdr.x = 0.0f;
    g->hdr.y = 0.0f;
    g->hdr.w = 1.0f;
    g->hdr.h = 1.0f;
}

u8 *func_L39_006CA2C0(u8 *self)
{
    Item_006CA2C0 items[7];
    Group_006CA2C0 group;
    f32 x, y, w;

    func_L39_00688388(self);
    x = D_001DE230_sda;
    y = D_001DE234_sda + (D_001DE23C_sda - D_001DE240_sda) * -3.0f / 7.0f;
    w = D_001DE238_sda - (D_001DE240_sda + D_001DE240_sda);
    *(u8 **)(self + 0x60) = D_L39_0047EDC0;
    *(u8 **)(self + 0x2A4) = self + 0x6B8;
    *(s32 *)(self + 0x6A8) = 0;
    *(s32 *)(self + 0x6AC) = 0;
    *(s32 *)(self + 0x6B0) = 0;

    item_init_006CA2C0(&items[0], (s32)D_L39_00249968, x, y, w, 0.05f);
    item_init_006CA2C0(&items[1], (s32)D_L39_00249968, D_001DE230_sda - D_001DE238_sda * 0.5f + D_001DE240_sda,
                       D_001DE234_sda + (D_001DE23C_sda - D_001DE240_sda) * -2.0f / 7.0f,
                       D_001DE238_sda - (D_001DE240_sda + D_001DE240_sda), 0.05f);
    item_init_006CA2C0(&items[2], (s32)D_L39_00249968, D_001DE230_sda - D_001DE238_sda * 0.5f + D_001DE240_sda,
                       D_001DE234_sda + (D_001DE23C_sda - D_001DE240_sda) * -1.0f / 7.0f,
                       D_001DE238_sda - (D_001DE240_sda + D_001DE240_sda), 0.05f);
    item_init_006CA2C0(&items[3], (s32)D_L39_00249968, D_001DE230_sda - D_001DE238_sda * 0.5f + D_001DE240_sda,
                       D_001DE234_sda + (D_001DE23C_sda - D_001DE240_sda) * 0.0f / 7.0f,
                       D_001DE238_sda - (D_001DE240_sda + D_001DE240_sda), 0.05f);
    item_init_006CA2C0(&items[4], (s32)D_L39_00249968, D_001DE230_sda - D_001DE238_sda * 0.5f + D_001DE240_sda,
                       D_001DE234_sda + (D_001DE23C_sda - D_001DE240_sda) * 1.0f / 7.0f,
                       D_001DE238_sda - (D_001DE240_sda + D_001DE240_sda), 0.05f);
    item_init_006CA2C0(&items[5], (s32)D_L39_00249968, D_001DE230_sda - D_001DE238_sda * 0.5f + D_001DE240_sda,
                       D_001DE234_sda + (D_001DE23C_sda - D_001DE240_sda) * 2.0f / 7.0f,
                       D_001DE238_sda - (D_001DE240_sda + D_001DE240_sda), 0.05f);
    item_init_006CA2C0(&items[6], (s32)D_L39_00249968, D_001DE230_sda - D_001DE238_sda * 0.5f + D_001DE240_sda,
                       D_001DE234_sda + (D_001DE23C_sda - D_001DE240_sda) * 3.0f / 7.0f,
                       D_001DE238_sda - (D_001DE240_sda + D_001DE240_sda), 0.05f);
    group_init_006CA2C0(&group);
    group.children[0] = &items[0];
    group.children[1] = &items[1];
    group.children[2] = &items[2];
    group.children[3] = &items[3];
    group.children[4] = &items[4];
    group.children[5] = &items[5];
    group.children[6] = &items[6];
    group.hdr.count = 7;
    func_L39_00689670(self, &group);
    return self;
}
/* localdecomp:end func_L39_006CA2C0 */

LINKER_REMNANT("asm/levels", func_L39_006CA6C0);
