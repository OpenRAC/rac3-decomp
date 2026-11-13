#include "common.h"

/* localdecomp:start func_L07_003BCDD0 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);

void func_L07_003BCDD0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 t;
    f32 v;

    *(f32 *)(a0 + 0x18) -= *(f32 *)(s + 0x2AC);
    t = func_0038DAB8(*(f32 *)(s + 0x2A8), 0.12566371f);
    *(f32 *)(s + 0x2A8) = t;
    v = func_0038D0B0(t) * 0.2f;
    *(f32 *)(s + 0x2AC) = v;
    *(f32 *)(a0 + 0x18) += v;
}
/* localdecomp:end func_L07_003BCDD0 */

/* localdecomp:start func_L07_003BCE50 */
void func_L07_003BCE50(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x18) = (f32) ((*(f32 *)((u8 *)arg0 + 0x18)) - (*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2AC)));
}
/* localdecomp:end func_L07_003BCE50 */

/* localdecomp:start func_L07_003BCE68 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L07_003BCEE8(void *, void *, f32);
void func_L07_003BCE68(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 t = func_0038DAB8(*(f32 *)(s + 0x2A8), 0.12566371f);
    f32 v;
    *(f32 *)(s + 0x2A8) = t;
    v = func_0038D0B0(t) * 0.2f;
    *(f32 *)(s + 0x2AC) = v;
    *(f32 *)(a0 + 0x18) += v;
    func_L07_003BCEE8(a0, s + 0xD0, *(f32 *)(s + 0xE4));
}
/* localdecomp:end func_L07_003BCE68 */

INCLUDE_ASM("asm/levels", func_L07_003BCEE8);

/* localdecomp:start func_L07_003BD078 */
extern s32 D_001DF41C;
s32 func_L07_003BAC58(s32);
s32 func_L07_003BADA8(s32);
s32 func_L07_003BAF28(void *);

s32 func_L07_003BD078(void *arg0) {
    u8 *p;
    s32 t;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(s16 *)(p + 0x234) == 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x278) != -1) {
        if (func_L07_003BAC58(D_001DF41C + (*(s32 *)(p + 0x278) << 8)) == 0) {
            return 0;
        }
    }
    if (*(s32 *)(p + 0x27C) != -1) {
        if (func_L07_003BADA8(*(s32 *)(p + 0x27C)) == 0) {
            return 0;
        }
    }
    t = func_L07_003BAF28(arg0);
    *(s16 *)(p + 0x260) = t;
    return (s16)t < *(s16 *)(p + 0x262);
}
/* localdecomp:end func_L07_003BD078 */

INCLUDE_ASM("asm/levels", func_L07_003BD118);

INCLUDE_ASM("asm/levels", func_L07_003BD1E8);

INCLUDE_ASM("asm/levels", func_L07_003BD9D0);

INCLUDE_ASM("asm/levels", func_L07_003BDC08);

INCLUDE_ASM("asm/levels", func_L07_003BDFB8);

INCLUDE_ASM("asm/levels", func_L07_003BE2A0);

/* localdecomp:start func_L07_003BE368 */
extern void func_003C2C98(void *, void *);
extern void func_L07_003BB1F0(void *);
extern void func_L07_003BE3A8(void *, int);

void func_L07_003BE368(char *obj) {
    func_003C2C98(obj, *(char **)(obj + 0x68) + 0x2C0);
    func_L07_003BB1F0(obj);
    func_L07_003BE3A8(obj, 1);
}
/* localdecomp:end func_L07_003BE368 */

INCLUDE_ASM("asm/levels", func_L07_003BE3A8);

INCLUDE_ASM("asm/levels", func_L07_003BE570);

/* localdecomp:start func_L07_003BE5F8 */
void func_L07_003BE988(void *);
s32 func_L07_003BE570(void *);
void func_L07_003BE678(void *);
void func_L07_003BE708(void *);
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE5F8(void *arg0) {
    u8 *temp;

    temp = *(u8 **)((u8 *)arg0 + 0x68);
    func_L07_003BE988(arg0);
    *(s16 *)(temp + 0x4F6) = 0;
    if (*(long *)(temp + 0x3A0) == -1) {
        if (func_L07_003BE570(arg0) != 0) {
            func_L07_003BE708(arg0);
        } else {
            func_L07_003BE678(arg0);
        }
    } else {
        func_L07_003BE3A8(arg0, 7);
    }
}
/* localdecomp:end func_L07_003BE5F8 */

/* localdecomp:start func_L07_003BE678 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE678(void *arg0) {
    if (*(s32 *)(*(s32 *)((char *)arg0 + 0x68) + 0x398) != -1) {
        func_L07_003BE3A8(arg0, 4);
    } else {
        func_L07_003BE3A8(arg0, 5);
    }
}
/* localdecomp:end func_L07_003BE678 */

/* localdecomp:start func_L07_003BE6C0 */
extern void func_L07_003BE3A8(void *, int);
extern void func_L07_003BE678(void *);
void func_L07_003BE6C0(char *arg0) {
    if (*(int *)(*(char **)(arg0 + 0x68) + 0x39C) != -1) {
        func_L07_003BE3A8(arg0, 6);
    } else {
        func_L07_003BE678(arg0);
    }
}
/* localdecomp:end func_L07_003BE6C0 */

/* localdecomp:start func_L07_003BE708 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE708(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x39C)) != -1) {
        func_L07_003BE3A8(arg0, 0xB);
        return;
    }
    func_L07_003BE3A8(arg0, 0xC);
}
/* localdecomp:end func_L07_003BE708 */

/* localdecomp:start func_L07_003BE750 */
void func_L07_003BE988(void *);
s32 func_00382468(s32);

void func_L07_003BE750(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L07_003BE988(arg0);
    *(s16 *)(p + 0x4F6) = 0;
    *(u8 *)(p + 0x4FA) = 0;
    if (func_00382468(2) != 0) {
        *(u8 *)(p + 0x4FB) = 1;
        func_L07_003BE3A8(arg0, 0xD);
    } else {
        *(u8 *)(p + 0x4FB) = 2;
        func_L07_003BE3A8(arg0, 0xE);
    }
}
/* localdecomp:end func_L07_003BE750 */

/* localdecomp:start func_L07_003BE7C8 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE7C8(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    *(s16 *)((u8 *)temp_v1 + 0x4F8) = 0x32;
    if ((*(u8 *)((u8 *)temp_v1 + 0x4FA)) != 0) {
        func_L07_003BE3A8(arg0, 0xF);
        return;
    }
    func_L07_003BE3A8(arg0, 0xC);
}
/* localdecomp:end func_L07_003BE7C8 */

/* localdecomp:start func_L07_003BE818 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE818(void *arg0) {
    u8 *temp_v1;
    s32 v;

    temp_v1 = *(u8 **)((u8 *)arg0 + 0x68);
    v = *(s32 *)(temp_v1 + 0x3A0);
    if (v != -1) {
        temp_v1[0x4FB] = 3;
        func_L07_003BE3A8(arg0, 0x10);
        return;
    }
    if (*(s32 *)(temp_v1 + 0x3A4) != v) {
        temp_v1[0x4FB] = 3;
        func_L07_003BE3A8(arg0, 0x11);
    }
}
/* localdecomp:end func_L07_003BE818 */

INCLUDE_ASM("asm/levels", func_L07_003BE870);

/* localdecomp:start func_L07_003BE988 */
void func_L07_003BE988(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68) + 0x4F0;
    s32 i;
    for (i = 1; i >= 0; i--) {
        p[2] = 0;
        p[0] = 0;
        p++;
    }
}
/* localdecomp:end func_L07_003BE988 */

INCLUDE_ASM("asm/levels", func_L07_003BE9B8);
