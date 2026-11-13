#include "common.h"

typedef struct { char pad[0xF0]; void (*fn)(void *); } VT;
typedef struct { char pad[0x60]; VT *vt; } Obj;

/* declared by functions of L39_0068B768.c, which this file was cut from */
extern s32 D_001DC3F4_sda;

/* localdecomp:start func_L39_0068B8B0 */
extern s32 D_L39_002403F8;
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern s32 D_001DC3F4_sda;
__asm__(".extern D_001DC3F4_sda, 4");
extern void func_L39_00611FC0(s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_00689A70(void);

s32 func_L39_0068B8B0(Obj *a)
{
    VT *v;
    if (D_L39_002403F8 == 0xB) {
        func_L39_00611FC0(0xA);
        func_L39_005BF798(0x12, 1, 4, 0, 0);
        v = a->vt;
        D_00241440 = 1;
        v->fn(a);
        func_L39_00689A70();
        return 1;
    }
    if (D_L39_002403F8 == 0x12) {
        func_L39_00611FC0(0xA);
        D_001DC3F4_sda = 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_0068B8B0 */
