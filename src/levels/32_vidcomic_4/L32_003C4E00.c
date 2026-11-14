#include "common.h"

/* localdecomp:start func_L32_003C4E00 */
void func_L01_00404A10(void *, void *);
void func_L01_004450F0(void *, s32, s32);
void func_L32_003C4F08(void *);
void func_L32_003C4FC0(void *);
void func_L32_003C50B0(void *);
void func_L32_003C5280(void *);
extern u8 D_L32_003C4EC8[];

void func_L32_003C4E00(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 1:
        func_L32_003C4FC0(arg0);
        return;
    case 2:
        func_L32_003C50B0(arg0);
        func_L01_00404A10(D_L32_003C4EC8, arg0);
        return;
    case 0:
        func_L32_003C4F08(arg0);
        func_L01_004450F0(arg0, 3, -1);
        return;
    case 3:
        func_L32_003C5280(arg0);
        func_L01_00404A10(D_L32_003C4EC8, arg0);
        return;
    }
}
/* localdecomp:end func_L32_003C4E00 */

/* localdecomp:start func_L32_003C4EC8 */
void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern s32 D_L32_001DF424;
extern s32 D_L32_001DF42C;
extern f32 D_L32_001DF430;
extern f32 D_L32_001DF434;

void func_L32_003C4EC8(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    func_003D9508(arg0 + 0x10, D_L32_001DF42C, D_L32_001DF424, 0, D_L32_001DF430 * (*(f32 *)((u8 *)temp_v0 + 0x10)), D_L32_001DF434, (*(f32 *)((u8 *)temp_v0 + 0x1C)));
}
/* localdecomp:end func_L32_003C4EC8 */

/* localdecomp:start func_L32_003C4F08 */
#include "vu0.h"

typedef struct S_003C4F08 {
    u8 pad0[0x10];
    f32 f10;
    s32 f14;
    u8 pad18[8];
    s32 f20;
} S_003C4F08;

extern s32 D_L32_001E25F8;
__asm__(".extern D_L32_001E25F8, 16");
extern f32 D_L32_001DF3A4;
extern s32 D_L32_001DF394;
extern f32 D_L32_001DF39C;
extern s32 D_L32_001DF3EC;
extern s32 D_L32_001DF3F0;
extern s32 D_L32_001DF408;
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L32_003C53A0(void *);

void func_L32_003C4F08(void *arg0) {
    S_003C4F08 *pv = *(S_003C4F08 **)((u8 *)arg0 + 0x68);

    qzero(pv);
    pv->f14 = -1;
    pv->f10 = D_L32_001DF3A4;
    pv->f20 = -1;
    if (D_L32_001DF394 == 0) {
        D_L32_001DF394 = 1;
        func_L03_0034B218((u8 *)&D_L32_001E25F8, D_L32_001DF3EC, D_L32_001DF3F0, D_L32_001DF39C,
                          D_L32_001DF408, (void *)func_L32_003C53A0);
    }
}
/* localdecomp:end func_L32_003C4F08 */

/* localdecomp:start func_L32_003C4F70 */
typedef int u128_t __attribute__((mode(TI)));

u8 *func_003C24B0(s32, s32);

u8 *func_L32_003C4F70(u128_t *arg0) {
    u8 buf[16] __attribute__((aligned(16)));
    u8 *temp_v0;

    *(u128_t *)buf = *arg0;
    temp_v0 = func_003C24B0(0x1E9B, 0x30);
    if (temp_v0 == 0) {
        return 0;
    }
    temp_v0[0x20] = 0;
    temp_v0[0x30] = 0xFF;
    *(u128_t *)(temp_v0 + 0x10) = *(u128_t *)buf;
    return temp_v0;
}
/* localdecomp:end func_L32_003C4F70 */

/* localdecomp:start func_L32_003C4FC0 */
extern s32 func_L01_004561B8(u8 *);
extern void func_L30_0034CC28(void *, void *, void *, s32, s32, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_003A4F28(s32);
extern void func_L30_0034DAC0(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern s32 D_L32_001DF3B4;
extern f32 D_L32_001DF3A0;
extern u8 D_L32_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_001A30B0[];

void func_L32_003C4FC0(void *arg0) {
    u8 *a0 = arg0;
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 buf[0x30];
    s32 idx;
    u8 *q;

    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(p + 0x18) = D_L32_001DF3B4;
        func_L30_0034CC28(buf, a0, D_L32_001D66B0, 1, 0, 20.0f);
        *(s32 *)(buf + 0x14) |= 0x30001;
        func_003D4D00(a0 + 0x10, 1, a0, buf, D_L32_001DF3A0);
        idx = *(s32 *)(p + 0x20);
        if (idx != -1) {
            q = D_001A30B0 + (idx << 7);
            if (*(s32 *)(q + 0xDC) == (s32)a0 && *(u8 *)(q + 0xD0) != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(p + 0x20) = -1;
        func_L30_0034DAC0(p + 0x14);
    }
    if (func_0038CAD0(p + 0x18) != 0) {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L32_003C4FC0 */

INCLUDE_ASM("asm/levels", func_L32_003C50B0);

/* localdecomp:start func_L32_003C5280 */
extern s32 func_L01_004561B8(u8 *);
extern void func_L30_0034C8A8(void *, void *);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 D_001A30B0[];
extern s32 D_L32_001E25F8;
__asm__(".extern D_L32_001E25F8, 16");
extern s32 D_L32_001DF9C0;
__asm__(".extern D_L32_001DF9C0, 16");
extern s32 D_L32_001DF3B8;
__asm__(".extern D_L32_001DF3B8, 4");
extern s32 D_L32_001DF3AC;
__asm__(".extern D_L32_001DF3AC, 4");
extern f32 D_L32_001DF3A8;
__asm__(".extern D_L32_001DF3A8, 4");
extern f32 D_L32_001DF3A4;
__asm__(".extern D_L32_001DF3A4, 4");
extern f32 D_L32_001DF398;
__asm__(".extern D_L32_001DF398, 4");
extern s32 D_L32_001DF3E8;
__asm__(".extern D_L32_001DF3E8, 4");
extern f32 D_L32_001DF428;
__asm__(".extern D_L32_001DF428, 4");

void func_L32_003C5280(void *arg0) {
    u8 *a0 = arg0;
    u8 *p;
    u8 *q;
    s32 idx;

    p = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(p + 0x18) = D_L32_001DF3B8;
        func_L30_0034C8A8(&D_L32_001E25F8, a0);
    }
    *(f32 *)(p + 0x10) = func_003C4088(D_L32_001DF3A8, D_L32_001DF3A4,
        func_L03_0034B440(1, 0, 5, (f32)D_L32_001DF9C0, (f32)D_L32_001DF3AC, 1.0f));

    idx = *(s32 *)(p + 0x20);
    if (idx == -1) {
        *(s32 *)(p + 0x20) = func_L01_004AAC98(10, 4, (s32)a0, 0x19D1);
    } else {
        q = D_001A30B0 + (idx << 7);
        if (*(s32 *)(q + 0xDC) != (s32)a0 || *(u8 *)(q + 0xD0) == 0) {
            *(s32 *)(p + 0x20) = func_L01_004AAC98(10, 4, (s32)a0, 0x19D1);
        }
    }
    func_L30_0034CF28(a0 + 0x10, p + 0x14, D_L32_001DF3E8, D_L32_001DF398, D_L32_001DF398);
    *(f32 *)(p + 0x1C) = func_0038DAB8(*(f32 *)(p + 0x1C), D_L32_001DF428);
    if (func_0038CAD0(p + 0x18) != 0) {
        func_L01_004450F0(a0, 2, -1);
    }
}
/* localdecomp:end func_L32_003C5280 */

INCLUDE_ASM("asm/levels", func_L32_003C53A0);
