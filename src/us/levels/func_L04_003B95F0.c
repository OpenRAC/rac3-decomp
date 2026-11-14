#include "common.h"

/* NTSC-U counterpart of func_L04_003BB378 (src/levels/shared/L04_003BB208.c): 8 -> 10 */
typedef int u128_t __attribute__((mode(TI)));
typedef int q128 __attribute__((mode(TI)));
typedef struct Moby {
    char pad0[0x10];
    q128 pos;
    unsigned char state;
    char pad21[0x30 - 0x21];
    unsigned char b48;
    unsigned char b49;
    unsigned short h50;
    char pad34[0x38 - 0x34];
    unsigned long d56;
    char pad40[0xB8 - 0x40];
    struct Moby *parent;
} Moby;
extern void func_00388550(void *, void *, s32);

/* localdecomp:start func_L04_003B95F0 */
extern void func_00388550(void *, void *, s32);
extern void func_003BE4F0(Moby *, int, int, int);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern u8 D_L04_001E28C0[];

void func_L04_003B95F0(u8 *a0) {
    u8 *p;
    if ((*(u16 *)(a0 + 0x34) & 0x80) == 0) {
        p = *(u8 **)(a0 + 0xB8);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x10);
        *(u128_t *)(a0 + 0xF0) = *(u128_t *)(p + 0xF0);
        func_00388550(a0 + 0xC0, p + 0xC0, 0x30);
        if (*(s32 *)(*(u8 **)(*(u8 **)(a0 + 0xB8) + 0x68) + 0x18) != 0) {
            if (a0[0x43] != 1) {
                func_003BE4F0((Moby *)a0, 1, 0, 10);
            }
        } else {
            if (a0[0x43] != 0) {
                func_003BE4F0((Moby *)a0, 0, 0, 10);
            }
        }
        if (a0[0x31] != 0) {
            if (func_L01_0040C018(D_L04_001E28C0, a0 + 0x10) < 576.0f) {
                func_L01_00444188(a0);
                a0[0x6F] = 0x16;
            }
        }
    }
}
/* localdecomp:end func_L04_003B95F0 */
