#include "common.h"

/* localdecomp:start func_L39_006A29D0 */
typedef struct S_006A29D0_Item { u8 pad[0x18]; s32 id; u8 data[1]; } S_006A29D0_Item;
typedef struct S_006A29D0_List { s32 pad0; s32 count; S_006A29D0_Item **items; } S_006A29D0_List;
typedef struct S_006A29D0_Obj { u8 pad[0xD]; u8 has_list; u8 pad2[6]; S_006A29D0_List list; } S_006A29D0_Obj;
typedef struct S_006A29D0_Root { u8 pad[0x78]; S_006A29D0_Obj *obj; } S_006A29D0_Root;
__asm__(".extern D_L39_0024D760, 16");
extern S_006A29D0_Root *D_L39_0024D760;
extern u8 D_L39_00248628[];
extern void *func_00381FF0(s32);

void *func_L39_006A29D0(s32 unused, s32 id) {
    S_006A29D0_List *list = D_L39_0024D760->obj->has_list ? &D_L39_0024D760->obj->list : 0;
    s32 i;
    s32 n;

    if (id == 0) {
        return func_00381FF0(0xFBF);
    }
    if (list) {
        n = list->count;
        for (i = 0; i < n; i++) {
            if (list->items[i]->id == id) {
                return list->items[i]->data;
            }
        }
    }
    return D_L39_00248628;
}
/* localdecomp:end func_L39_006A29D0 */

INCLUDE_ASM("asm/levels", func_L39_006A2A58);

LINKER_REMNANT("asm/levels", func_L39_006A2F38);

INCLUDE_ASM("asm/levels", func_L39_006A2F50);

LINKER_REMNANT("asm/levels", func_L39_006A3660);

/* localdecomp:start func_L39_006A3668 */
extern u8 D_L39_0047D858[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006A3668(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D858;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006A3668 */

INCLUDE_ASM("asm/levels", func_L39_006A3690);

/* localdecomp:start func_L39_006A3A80 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006A3A80(void *);

extern void func_L39_0067F168();
void func_L39_006A3A80(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006A3A80 */

INCLUDE_ASM("asm/levels", func_L39_006A3AB0);
