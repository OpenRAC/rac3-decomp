#include "common.h"

typedef struct Obj_003A2C98 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0xC];
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x20];
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    f32 f60[1];
} Obj_003A2C98;

/* localdecomp:start func_L02_003A28A8 */
/* log: first wording, after L04_00356318's func_L04_00356318 */
#include "vu0.h"
typedef int u128_003A28A8 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 *D_L02_001E8058 __attribute__((section(".data")));
extern s32 func_L01_0044C108(void *);
extern void func_L02_003A29D0(u8 *, void *);
extern void func_L02_003A2C98(s32, Obj_003A2C98 *);
extern s32 func_L02_003A3878(u8 *);
extern void func_L02_003A2EC8(void);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L02_004D36C0(s32, s32);

void func_L02_003A28A8(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    u8 *h;

    if (func_L01_0044C108(a0 + 0x10) == 0) {
        return;
    }
    if (a0[0x20] == 0) {
        func_L02_003A29D0(a0, q);
    }
    func_L02_003A2C98((s32)a0, (Obj_003A2C98 *)q);
    if (func_L02_003A3878(q) != 0) {
        func_L01_004048D0(func_L02_003A2EC8, a0);
    } else {
        func_L01_00404808(func_L02_003A2EC8, a0);
    }
    if (*(s32 *)(q + 0x98) != -1) {
        *(u128_003A28A8 *)&a = *(u128_003A28A8 *)(D_001A4BE0 + 0x80);
        h = D_001A4BE0;
        func_0038CF68(&b, *(u8 **)(h + 0x25C0) + 0xE0, 0.75f);
        vec_add_ab(&a, &b, &a);
        if (func_L01_003FB640(&a, 0, *(u8 **)(h + 0x25C0), 0.5f) != 0 && D_L02_001E8058 != 0 &&
            *(s16 *)(D_L02_001E8058 + 0xAA) == 0x1C7A && *(s32 *)(h + 0x25C4) != 0x7D) {
            func_L02_004D36C0(0x7D, 1);
        }
    }
}
/* localdecomp:end func_L02_003A28A8 */
