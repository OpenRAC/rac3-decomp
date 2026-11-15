#include "common.h"

typedef struct { char pad[0xF0]; void (*fn)(void *); } VT;
typedef struct { char pad[0x60]; VT *vt; } Obj;

/* declared by functions of L39_0068B768.c, which this file was cut from */
extern s32 D_001DC3F4_sda;

/* declared by functions of L39_0068B950.c, which this file was cut from */
extern s32 D_001DC3F4_sda;
extern int D_001DC3F4_sda;

/* localdecomp:start func_L39_0068C0E0 */
typedef struct { char pad[0x284]; s32 f284; } W_0068C0E0;

extern u8 D_00247A34;
__asm__(".extern D_00247A34, 16");
extern f32 D_00247A30;
__asm__(".extern D_00247A30, 16");
extern W_0068C0E0 *D_001DC204_sda;

extern void func_L39_0068B768(Obj *);
extern void func_L39_0068B828(Obj *);
extern s32 func_L39_0068BAD8(Obj *, s32 *);
extern void func_L39_0068B8A0(void);
extern void func_L39_0068BA10(void);
extern s32 func_L39_0068BAB0(void);

s32 func_L39_0068C0E0(Obj *a, s32 state) {
    s32 ret;

    if (D_00247A34) {
        if (D_00247A30 <= 0.0f) {
            D_001DC204_sda->f284 = 0x18;
        }
        return 1;
    }
    ret = 0;
    switch (D_001DC3F4_sda) {
    case 0:
        func_L39_0068B768(a);
        break;
    case 1:
        func_L39_0068B828(a);
        break;
    case 2:
        ((void (*)(Obj *))func_L39_0068B8A0)(a);
        break;
    case 3:
        ret = func_L39_0068BAD8(a, &state);
        break;
    case 4:
        func_L39_0068B950(a);
        break;
    case 5:
        ((void (*)(Obj *))func_L39_0068BA10)(a);
        break;
    case 6:
        func_L39_0068BA40(a);
        break;
    case 7:
        ret = ((s32 (*)(Obj *))func_L39_0068BAB0)(a);
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_0068C0E0 */
