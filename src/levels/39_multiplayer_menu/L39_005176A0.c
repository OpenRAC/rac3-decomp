#include "common.h"

/* localdecomp:start func_L39_005176A0 */
typedef struct E_005176A0 {
    s32 f0;
    s32 f4;
    void *f8;
    u8 padC[0xA];
    u8 f16;
    u8 pad17[0x11];
} E_005176A0;
typedef struct S_005176A0 {
    s32 f0;
    u32 count;
    E_005176A0 *items;
    s32 flags;
} S_005176A0;
extern void func_L39_004BEF28(void *);

void func_L39_005176A0(S_005176A0 *a) {
    u32 i;

    for (i = 0; i < a->count; i++) {
        if (a->items[i].f8 != 0 && (a->items[i].f16 & 1)) {
            func_L39_004BEF28(a->items[i].f8);
            a->items[i].f8 = 0;
        }
    }
    if ((a->flags & 2) && a->items != 0) {
        func_L39_004BEF28(a->items);
        a->items = 0;
    }
    a->f0 = 0;
    if (a->flags & 1) {
        func_L39_004BEF28(a);
    }
}
/* localdecomp:end func_L39_005176A0 */
