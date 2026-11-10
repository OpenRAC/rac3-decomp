#include "common.h"

/* localdecomp:start func_L39_004F3390 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} S_004F3390;
extern S_004F3390 *func_L39_004BEED8(s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004FA480(s32);
extern s32 func_L39_005065C8(void);
extern s32 func_L39_004FAAB0(void);
extern s32 func_L39_004F4390(void);
extern s32 func_L39_004F3BC0(void);

S_004F3390 *func_L39_004F3390(void) {
    S_004F3390 *o = func_L39_004BEED8(0x28);
    if (o == 0) {
        s32 err[12];
        err[11] = 0x76;
        func_L39_004BC6C8(13, 204, 33, 0, 0);
        return 0;
    }
    o->f0 = 0;
    if (!(o->f4 = func_L39_004FA480(2))) return 0;
    if (!(o->f8 = func_L39_005065C8())) return 0;
    if (!(o->fC = func_L39_004FAAB0())) return 0;
    if (!(o->f10 = func_L39_004F4390())) return 0;
    if (!(o->f14 = func_L39_004FAAB0())) return 0;
    if (!(o->f18 = func_L39_004F3BC0())) return 0;
    o->f1C = 0;
    o->f20 = 0;
    o->f24 = 0;
    return o;
}
/* localdecomp:end func_L39_004F3390 */

INCLUDE_ASM("asm/levels", func_L39_004F3458);

INCLUDE_ASM("asm/levels", func_L39_004F3830);

INCLUDE_ASM("asm/levels", func_L39_004F38C0);

INCLUDE_ASM("asm/levels", func_L39_004F3928);

INCLUDE_ASM("asm/levels", func_L39_004F39F0);

INCLUDE_ASM("asm/levels", func_L39_004F3BC0);

INCLUDE_ASM("asm/levels", func_L39_004F3C40);

INCLUDE_ASM("asm/levels", func_L39_004F3CA8);

/* localdecomp:start func_L39_004F3DC8 */
typedef struct { s32 *f0; s32 *f4; } S_004F3DC8;
extern s32 func_L39_00506300(s32 *, s32 *);
extern s32 func_L39_004FAC48(s32 *, s32 *);
extern void *func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(s32 *, s32, s32, s32, s32);

void *func_L39_004F3DC8(S_004F3DC8 *arg0, s32 *arg1) {
    void *result;
    s32 size;
    s32 tmp;

    if (arg0 == 0) {
        return 0;
    }
    size = func_L39_00506300(arg0->f0, 0);
    size += func_L39_004FAC48(arg0->f4, 0);
    result = func_L39_004FA1A0(1, size, 16);
    if (arg1 == 0) {
        return result;
    }
    tmp = *arg1;
    func_L39_004F9FF8(&tmp, 1, size, 16, 0);
    func_L39_00506300(arg0->f0, &tmp);
    func_L39_004FAC48(arg0->f4, &tmp);
    *arg1 = tmp;
    return result;
}
/* localdecomp:end func_L39_004F3DC8 */

INCLUDE_ASM("asm/levels", func_L39_004F3E90);

INCLUDE_ASM("asm/levels", func_L39_004F4048);

INCLUDE_ASM("asm/levels", func_L39_004F40C8);

/* localdecomp:start func_L39_004F4110 */
typedef struct { s32 *f0; s32 *f4; } S_004F4110;
extern s32 func_L39_004F9B38(s32 *, s32 *);
extern void *func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(s32 *, s32, s32, s32, s32);

void *func_L39_004F4110(S_004F4110 *arg0, s32 *arg1) {
    void *result;
    s32 size;
    s32 tmp;

    if (arg0 == 0) {
        return 0;
    }
    size = func_L39_004F9B38(arg0->f0, 0);
    size += func_L39_004F9B38(arg0->f4, 0);
    result = func_L39_004FA1A0(1, size, 16);
    if (arg1 == 0) {
        return result;
    }
    tmp = *arg1;
    func_L39_004F9FF8(&tmp, 1, size, 16, 0);
    func_L39_004F9B38(arg0->f0, &tmp);
    func_L39_004F9B38(arg0->f4, &tmp);
    *arg1 = tmp;
    return result;
}
/* localdecomp:end func_L39_004F4110 */

INCLUDE_ASM("asm/levels", func_L39_004F41D8);

INCLUDE_ASM("asm/levels", func_L39_004F4390);

INCLUDE_ASM("asm/levels", func_L39_004F4410);

INCLUDE_ASM("asm/levels", func_L39_004F4760);

INCLUDE_ASM("asm/levels", func_L39_004F4818);
