#include "common.h"

/* NTSC-U counterpart of func_L39_006DA090 (src/levels/39_multiplayer_menu/L39_006D8E90.c) */
typedef struct Loc_006DA090 {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 f30[0x40];
} Loc_006DA090;
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;
extern Obj_006DA090 *D_L39_0024D860;
extern Obj_006DA090 *D_L39_0024D860;
s32 func_001206F4(void *, s32);
void func_001962D8(void *);
s32 func_001962E8(void);
s32 func_001206F4(void *, s32);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_L39_005945F0(void *, void *, s32);
s32 func_001206F4(void *, s32);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_L39_005945F0(void *, void *, s32);

/* localdecomp:start func_L39_006D7538 */
s32 func_L39_006DAAA8(s32, void *, s32);
s32 func_001206F4(void *, s32);
void func_L39_005945F0(void *, void *, s32);
void *func_0017ED28(void *);
void func_001962D8(void *);
s32 func_001962E8(void);
__asm__(".extern D_L39_0024D860, 16");
extern u16 D_L39_0024A050[];

s32 func_L39_006D7538(s32 a0, void *a1) {
    Loc_006DA090 loc;
    Obj_006DA090 *p;
    s32 r;
    s32 x;

    p = D_L39_0024D860;
    x = p->f50;
    r = func_L39_006DAAA8(p->f54, a1, 0);
    if (r != 0) {
        loc.f00 = D_L39_0024A050[0];
        func_001206F4((u8 *)&loc + 0x15, x);
        loc.f28 = 0;
        loc.f2C = -1;
        func_L39_005945F0(loc.f30, a1, 0x40);
        func_001962D8(func_0017ED28(&loc));
        if (func_001962E8() != 0) {
            p->f10 = 0x49;
            if (p->f14 == 0) {
                p->f14 = 0x49;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D7538 */
