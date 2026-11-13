#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00674398);

/* localdecomp:start func_L39_00674E08 */
typedef struct {
    u8 pad0[0x18A0];
    u8 arr[4][0xB50];
} Rooms_00674E08;
typedef struct {
    u8 pad0[0x1FCA8];
    Rooms_00674E08 rooms;
} World_00674E08;
typedef struct {
    u8 pad0[0x2544];
    s32 f2544;
} Obj_00674E08;
typedef struct {
    s32 f0;
    u8 pad4[0x18];
} Ent_00674E08;
__asm__(".extern D_L39_002464D4, 4");
__asm__(".extern D_L39_002464D8, 4");
extern s32 D_L39_00241118;
extern s32 *D_L39_00241120;
extern World_00674E08 *D_L39_00242A50;
extern Ent_00674E08 D_L39_004840A0[];
extern s32 D_L39_002464D4;
extern s32 D_L39_002464D8;
extern Obj_00674E08 *func_L39_0061BF38(s32);
extern void func_L39_00605878(void *);
extern void func_L39_006068A0(void *, s32);
extern u32 func_L01_004D0CB0(void *);
extern void func_L39_006070C0(void *, s32, s32, s32, u32);

s32 func_L39_00674E08(void) {
    Obj_00674E08 *p = func_L39_0061BF38(D_L39_00241118);
    s32 i;
    u32 r;
    Rooms_00674E08 *rooms;
    Rooms_00674E08 *r2;
    if (*D_L39_00241120 >= 2) {
        for (i = 0; i < 4; i++) {
            Rooms_00674E08 *r1 = &D_L39_00242A50->rooms;
            func_L39_00605878(&r1->arr[i]);
        }
    }
    r2 = &D_L39_00242A50->rooms;
    func_L39_006068A0(&r2->arr[D_L39_00241118], D_L39_00241118);
    if (D_L39_004840A0[p->f2544].f0 == 0) {
        if (*D_L39_00241120 == 1) {
            rooms = &D_L39_00242A50->rooms;
            r = func_L01_004D0CB0(&rooms->arr[D_L39_00241118]);
            func_L39_006070C0(rooms, D_L39_00241118, D_L39_002464D4, D_L39_002464D8, r >> 24);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00674E08 */

INCLUDE_ASM("asm/levels", func_L39_00674F50);
