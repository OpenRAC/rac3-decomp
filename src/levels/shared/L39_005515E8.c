#include "common.h"

/* localdecomp:start func_L39_005515E8 */
void func_L39_00551660(void *);
extern s32 func_L39_00551918(u8 *);
extern s32 func_L39_00552070(u8 *);
extern void func_003C2880(u8 *);
extern void func_L01_00404A10(void *, u8 *);

void func_L39_005515E8(u8 *a0) {
    s32 a = func_L39_00551918(a0);
    s32 b = func_L39_00552070(a0);
    if (a == 0 && b == 0) {
        if (a0[32] == 2) {
            func_003C2880(a0);
        }
    } else {
        func_L01_00404A10(func_L39_00551660, a0);
    }
}
/* localdecomp:end func_L39_005515E8 */

/* localdecomp:start func_L39_00551660 */
void func_L39_00551A38(void);
void func_L39_005521F8(void *);

void func_L39_00551660(void *arg0) {
    if (arg0 != 0) {
        u8 t = *(u8 *)((char *)arg0 + 0x20);
        if (t != 0xFE) {
            if (t == 0xFD) {
                return;
            }
            func_L39_00551A38();
            func_L39_005521F8(arg0);
        }
    }
}
/* localdecomp:end func_L39_00551660 */

/* localdecomp:start func_L39_005516B0 */
typedef int u128_005516B0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    u128_005516B0 pos;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
} R_005516B0;

extern u8 D_L39_003C13E0[];
extern void func_L39_005517C8(u8 *rec, s32 index);
extern f32 func_L01_0044AE78(f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);

void func_L39_005516B0(u8 *a0, u128_005516B0 *a1) {
    u8 *st = *(u8 **)(a0 + 0x68);
    s32 i = *(s16 *)(st + 0x30);
    s32 b = st[0x3A];
    s32 off;
    R_005516B0 *r;
    f32 v;

    off = b * 0x12C0 + i * 0x30;
    *(u128_005516B0 *)(D_L39_003C13E0 + off + 0x10) = *a1;
    v = func_L01_0044AE78((f32)i * 0.69813168f);
    off = b * 0x12C0;
    r = (R_005516B0 *)(D_L39_003C13E0 + (i * 0x30 + off));
    r->f20 = v;
    r->f28 = func_L39_005B4410(3.0f, 3.0f) * 0.017453292f;
    r->f24 = 0.25f;
    r->f2C = func_L39_005B4468(0.01f, 0.2f) * 0.020000001f;
    func_L39_005517C8(D_L39_003C13E0 + off, i);
    *(s16 *)(st + 0x30) += 1;
}
/* localdecomp:end func_L39_005516B0 */
