#include "common.h"

typedef struct { char pad[0xF0]; void (*fn)(void *); } VT;
typedef struct { char pad[0x60]; VT *vt; } Obj;

/* localdecomp:start func_L39_0068B768 */
extern s32 D_001A43E0[];
extern s32 D_001D4CE8_sda;
extern s32 D_001DC3F4_sda;
__asm__(".extern D_L39_00241440, 16");
extern s32 D_L39_00241440;
extern s32 func_L01_00517918(s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_00689A70(void);

typedef void (*Fn_0068B768)(void *);
typedef struct {
    u8 pad0[0x60];
    Fn_0068B768 *vt;
} Obj_0068B768;

void func_L39_0068B768(Obj_0068B768 *a) {
    s32 mode = D_001A43E0[2];
    s32 x;

    if (mode == 2) {
        if (D_001A43E0[4] != 0 || (x = D_001D4CE8_sda) == 0x12) {
            func_L01_00517918(10);
            D_001DC3F4_sda = 1;
            return;
        }
        if (x == 1) {
            func_L39_005BF798(0x12, 1, 3, 0, 0);
            D_L39_00241440 = x;
            a->vt[60](a);
            func_L39_00689A70();
            D_001DC3F4_sda = mode;
            return;
        }
    }
    D_001DC3F4_sda = 3;
}
/* localdecomp:end func_L39_0068B768 */

INCLUDE_ASM("asm/levels", func_L39_0068B828);

/* localdecomp:start func_L39_0068B8A0 */
extern s32 D_001DC3F4_sda;

void func_L39_0068B8A0(void) {
    D_001DC3F4_sda = 3;
}
/* localdecomp:end func_L39_0068B8A0 */
