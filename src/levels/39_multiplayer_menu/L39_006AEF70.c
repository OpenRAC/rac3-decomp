#include "common.h"

typedef struct {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x4C - 0x24];
    void (*f4C)(void *, s32, s32);
} VT_006AEF20;
typedef struct {
    u8 pad0[0x60];
    VT_006AEF20 *vt;
} OBJ_006AEF20;

/* declared by functions of L39_006AE3D8.c, which this file was cut from */
extern s32 *D_L39_00241120;
extern u8 *func_00381FF0(s32);

/* localdecomp:start func_L39_006AEF70 */
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern s32 *D_001DC204_sda;
extern s32 *D_L39_00241120;
extern u8 D_L39_00248B90[];
extern s32 func_L39_006872E8(s32 *, u8 *, u8 *, s32, s32, f32);
extern void func_00196038(void);
extern void func_00199050(void);
extern s32 func_L39_005C1A60(s32, s32, s32);
s32 func_L39_006AEF70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 != 0) {
        s32 *m = D_L39_00247914;
        u8 *b = D_L39_00248B90;
        u8 *t = func_00381FF0(0x1643);

        if (func_L39_006872E8(m, b, t, 3, 0, 0.6f) != 1) {
            return 0;
        }
    }
    func_00196038();
    func_00199050();
    *D_L39_00241120 = 1;
    if (arg3 >= 0) {
        s32 *m = D_001DC204_sda;
        u8 *b = D_L39_00248B90;
        u8 *t = func_00381FF0(arg3);

        func_L39_006872E8(m, b, t, 4, 0, 0.6f);
    }
    D_L39_00247914[0x284 / 4] = 0x15;
    func_L39_005C1A60(0, 0, 0x400);
    return 1;
}
/* localdecomp:end func_L39_006AEF70 */
