#include "common.h"

/* localdecomp:start func_L39_006023D8 */
extern void func_11D534(void *, s32, s32);
extern s32 func_L39_00602190(void *);
extern void *func_L01_00521C90(s32, s32);
extern void func_003AB250();
extern void func_003AB428(void *, s32, s32);
extern void func_003AB458(void *, f32);
extern void func_003AAF00(void *, s32);
extern s32 *func_L39_006010E0(void *);
extern u8 D_L39_002453D0[];
extern u8 D_L39_002453E0[];
extern s32 D_L39_00242A50;

void func_L39_006023D8(char *obj, void *pool) {
    char *top;
    char *bracket;

    obj[0x88] = 0;
    *(s32 *)(obj + 0x18C) = 0;
    *(s32 *)(obj + 0x188) = 0;
    *(s32 *)(obj + 0x1A8) = 0;
    *(s32 *)(obj + 0x1AC) = 0;
    *(s32 *)(obj + 0x1B4) = 0x28;
    *(s32 *)(obj + 0x1A4) = 1;
    *(s32 *)(obj + 0x190) = 1;
    func_11D534(obj + 0x1B8, 0, 0x78);
    if (pool != 0) {
        f32 *xy;
        f32 *colour;
        s32 *cell4;
        s32 *cellC;

        xy = func_L01_00521C90(0x10, func_L39_00602190(pool));
        xy[0] = 255.0f;
        xy[1] = 108.0f;
        ((s32 *)xy)[2] = 0;
        ((s32 *)xy)[3] = 0;
        *(f32 **)(obj + 0) = xy;
        colour = func_L01_00521C90(0x10, func_L39_00602190(pool));
        colour[0] = 0.0f;
        colour[1] = 0.0f;
        *(s32 *)colour = 0x600E5092;
        ((s32 *)colour)[2] = 0;
        ((s32 *)colour)[3] = 0;
        *(f32 **)(obj + 8) = colour;
        cell4 = func_L01_00521C90(0x10, func_L39_00602190(pool));
        *(s32 **)(obj + 4) = cell4;
        cell4[1] = 0;
        cell4[2] = 0;
        cell4[3] = 0;
        cell4[0] = 0;
        cellC = func_L01_00521C90(0x10, func_L39_00602190(pool));
        *(s32 **)(obj + 12) = cellC;
        cellC[1] = 0;
        cellC[2] = 0;
        cellC[3] = 0;
        cellC[0] = 0;
    }
    bracket = obj + 0x10;
    top = obj + 0x4C;
    func_003AB250(bracket, D_L39_002453D0, pool);
    func_003AB428(bracket, D_L39_00242A50 + 0x7090, 0xC);
    func_003AB458(bracket, 0.02f);
    func_003AAF00(bracket, 1);
    *func_L39_006010E0(bracket) = 0x332299DE;
    func_003AB250(top, D_L39_002453E0, pool);
    func_003AB428(top, D_L39_00242A50 + 0x7090, 0xD);
    func_003AAF00(top, 1);
    *func_L39_006010E0(top) = 0x332299DE;
    **(s32 **)(obj + 12) = 0x8066CCFF;
    *(s32 *)(obj + 0x198) = 0;
    **(s32 **)(obj + 4) = 0;
}
/* localdecomp:end func_L39_006023D8 */
