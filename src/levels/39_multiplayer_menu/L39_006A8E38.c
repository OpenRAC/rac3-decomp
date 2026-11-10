#include "common.h"

/* localdecomp:start func_L39_006A8E38 */
__asm__(".extern D_L39_00241640, 16");
__asm__(".extern D_L39_0024D760, 16");

typedef struct {
    char pad[0x48];
    void *f48;
} S_006A8E38;

extern u8 *D_L39_00241640;
extern S_006A8E38 *D_L39_0024D760;
extern s32 func_L39_006D9328(void *, void *);

s32 func_L39_006A8E38(s32 a0, s32 index)
{
    void *element;
    s32 result;

    element = *(void **)((u8 *)D_L39_00241640 + (index << 2) + 0x150);
    result = func_L39_006D9328(D_L39_0024D760->f48, element);
    if (result) {
        return result + 0x48;
    }
    return 0;
}
/* localdecomp:end func_L39_006A8E38 */

LINKER_REMNANT("asm/levels", func_L39_006A8E80);

/* localdecomp:start func_L39_006A8E90 */
extern u8 D_L39_004AD9C0[];
extern u8 D_001DD250_sda;
extern u8 D_001DD251_sda;
extern u16 *D_001DD254_sda;

extern s32 D_001DD24C_sda;
extern s32 func_0038E1C8();

void func_L39_006A8E90(void)
{
    if (D_L39_004AD9C0[0] == 0xFF) {
        D_L39_004AD9C0[1] = 0xFE;
        D_001DD250_sda = 1;
        D_001DD251_sda = 0;
    } else if (D_L39_004AD9C0[1] == 0xFF) {
        D_L39_004AD9C0[0] = 0xFE;
        D_001DD250_sda = 1;
        D_001DD251_sda = 1;
    }
    D_001DD254_sda = (u16 *)&D_L39_004AD9C0[2];
    D_001DD24C_sda = func_0038E1C8();
}
/* localdecomp:end func_L39_006A8E90 */

/* localdecomp:start func_L39_006A8F08 */
extern u16 D_L39_004B0688[][5];

void func_L39_006A8F08(u16 (*src)[5], s32 n)
{
    s32 i, j;
    for (i = 0; i < 52; i++) {
        for (j = 0; j < n; j++) {
            D_L39_004B0688[i][j] = src[i][j];
        }
    }
}
/* localdecomp:end func_L39_006A8F08 */

/* localdecomp:start func_L39_006A8F60 */
extern u8 D_001DD250_sda;
extern u8 D_001DD251_sda;
extern u16 *D_001DD254_sda;

s16 func_L39_006A8F60(s32 a0)
{
    s32 r = 0;
    s16 v;

    if (D_001DD250_sda != 0) {
        v = D_001DD254_sda[a0];
        r = v;
        if (D_001DD251_sda != 0) {
            r = ((v & 0xFF) << 8) | ((v >> 8) & 0xFF);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006A8F60 */

/* localdecomp:start func_L39_006A8FB0 */
extern s32 D_001DD24C_sda;
extern u8 D_001DD250_sda;
extern s32 D_001DD258_sda;
extern s32 D_001DD25C_sda;
extern s32 D_001DD260_sda;
extern s16 func_L39_006A8F60(s32 a0);

s32 func_L39_006A8FB0(s16 c)
{
    s32 r;
    s32 i;
    s32 k;
    s32 n;
    s32 j;
    s32 v;

    if (D_001DD250_sda == 0) {
        return (u8)c;
    }
    r = -1;
    n = D_001DD24C_sda < D_001DD260_sda ? D_001DD24C_sda : D_001DD260_sda;
    j = D_001DD258_sda;
    for (k = 0; r < 0 && k < n; k++) {
        if (k == c - 0x20) {
            r = c;
        }
    }
    for (i = n; r < 0 && i < D_001DD24C_sda; i++) {
        v = func_L39_006A8F60(i);
        if (v >= 0x80) {
            switch ((u8)j) {
            case 0:
            case 0x25:
            case 0x5C:
                j++;
            }
            if (v == c) {
                r = j + D_001DD25C_sda;
            }
            j++;
        }
    }
    return r >= 0 ? r : 0x20;
}
/* localdecomp:end func_L39_006A8FB0 */

/* localdecomp:start func_L39_006A90F0 */
extern u16 D_L39_004B0688[][5];

u8 func_L39_006A90F0(s32 a0)
{
    s32 i;
    s32 j;
    s32 notfound = 1;

    for (i = 0; notfound && i < 5; i++) {
        for (j = 0; notfound && j < 52; j++) {
            if (a0 == (s16)D_L39_004B0688[j][i]) {
                notfound = 0;
            }
        }
    }
    return notfound ^ 1;
}
/* localdecomp:end func_L39_006A90F0 */

INCLUDE_ASM("asm/levels", func_L39_006A9160);

/* localdecomp:start func_L39_006A9E68 */
extern u8 D_L39_0047DB98[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006A9E68(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047DB98;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006A9E68 */
