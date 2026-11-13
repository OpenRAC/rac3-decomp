#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003C7468);

INCLUDE_ASM("asm/levels", func_L07_003C7E70);

INCLUDE_ASM("asm/levels", func_L07_003C80C0);

INCLUDE_ASM("asm/levels", func_L07_003C84F8);

INCLUDE_ASM("asm/levels", func_L07_003C8608);

/* localdecomp:start func_L07_003C86D0 */
extern void func_003C2C98(void *, void *);
extern void func_L07_003BB038(void *);
extern void func_L07_003BB1F0(void *);
extern void func_L07_003C8718(void *, s32);

void func_L07_003C86D0(char *obj) {
    func_003C2C98(obj, *(char **)(obj + 0x68) + 0x3C0);
    func_L07_003BB038(obj);
    func_L07_003BB1F0(obj);
    func_L07_003C8718(obj, 1);
}
/* localdecomp:end func_L07_003C86D0 */

INCLUDE_ASM("asm/levels", func_L07_003C8718);

/* localdecomp:start func_L07_003C8960 */
extern s32 D_L07_001DF41C;
s32 func_L07_003BAC58();
s32 func_L07_003BADA8();

s32 func_L07_003C8960(void *arg0) {
    u8 *p;
    s32 a;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(s16 *)(p + 0x144) != 1) {
        return 0;
    }
    a = *(s32 *)(p + 0x4A0);
    if (a != -1) {
        if (func_L07_003BAC58(D_L07_001DF41C + (a << 8)) == 0) {
            return 0;
        }
    }
    a = *(s32 *)(p + 0x4A4);
    if (a != -1) {
        if (func_L07_003BADA8() == 0) {
            return 0;
        }
    }
    if (*(s32 *)(p + 0x4B8) != -1 && *(s32 *)(p + 0x4B0) != -1) {
        if (*((u8 *)arg0 + 0x31) == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003C8960 */

/* localdecomp:start func_L07_003C8A10 */
s32 func_L07_003C8960(void *);
void func_L07_003C8718(void *, s32);
void func_L07_003C8A88(void *);
void func_L07_003C8B18(void *);

void func_L07_003C8A10(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (*(s32 *)(p + 0x4B8) == -1 && *(s32 *)(p + 0x4B0) == -1) {
        if (func_L07_003C8960(arg0)) {
            func_L07_003C8B18(arg0);
        } else {
            func_L07_003C8A88(arg0);
        }
    } else {
        func_L07_003C8718(arg0, 7);
    }
}
/* localdecomp:end func_L07_003C8A10 */

/* localdecomp:start func_L07_003C8A88 */
void func_L07_003C8718(void *, s32);

void func_L07_003C8A88(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x4a8)) != -1) {
        func_L07_003C8718(arg0, 4);
        return;
    }
    func_L07_003C8718(arg0, 0x5);
}
/* localdecomp:end func_L07_003C8A88 */

/* localdecomp:start func_L07_003C8AD0 */
void func_L07_003C8718(void *, s32);
void func_L07_003C8A88_003C8AD0(void *, void *);

void func_L07_003C8AD0(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x4AC)) != -1) {
        func_L07_003C8718(arg0, 0x6);
        return;
    }
    func_L07_003C8A88_003C8AD0(arg0, arg0);
}
/* localdecomp:end func_L07_003C8AD0 */

/* localdecomp:start func_L07_003C8B18 */
void func_L07_003C8718(void *, s32);
void func_L07_003C8B60(void *, void *);

void func_L07_003C8B18(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x4AC)) != -1) {
        func_L07_003C8718(arg0, 0xA);
        return;
    }
    func_L07_003C8B60(arg0, arg0);
}
/* localdecomp:end func_L07_003C8B18 */

/* localdecomp:start func_L07_003C8B60 */
void func_L07_003C8B60(void *arg0, void *arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (p[0x4D6] != 0) {
        func_L07_003C8718(arg0, 0xC);
        return;
    }
    func_L07_003C8718(arg0, 0xB);
}
/* localdecomp:end func_L07_003C8B60 */

INCLUDE_ASM("asm/levels", func_L07_003C8BA0);

/* localdecomp:start func_L07_003C8C30 */
void func_L07_003BB038(void *);
void func_L07_003C8718(void *, s32);
void func_L07_003C8B60_003C8C30(void *) __asm__("func_L07_003C8B60");

void func_L07_003C8C30(void *arg0) {
    u8 *h = *(u8 **)((u8 *)arg0 + 0x68);

    func_L07_003BB038(arg0);
    *(s16 *)(h + 0x4D4) = 0x25;
    if (h[0x4D7] != 0) {
        func_L07_003C8718(arg0, 0x16);
    } else {
        func_L07_003C8B60_003C8C30(arg0);
    }
}
/* localdecomp:end func_L07_003C8C30 */

/* localdecomp:start func_L07_003C8C90 */
void func_L07_003C8718(void *, s32);

void func_L07_003C8C90(unsigned char *a0)
{
    unsigned char *s = *(unsigned char **)(a0 + 0x68);

    if (*(s32 *)(s + 0x4B8) != -1) {
        func_L07_003C8718(a0, 0x17);
        return;
    }
    if (*(s32 *)(s + 0x4B0) == *(s32 *)(s + 0x4B8)) {
        return;
    }
    if (*(s32 *)(s + 0x4B4) != *(s32 *)(s + 0x4B8)) {
        *(u8 *)(s + 0x4DC) = 1;
        func_L07_003C8718(a0, 0x1A);
    } else {
        func_L07_003C8718(a0, 0x19);
    }
}
/* localdecomp:end func_L07_003C8C90 */

INCLUDE_ASM("asm/levels", func_L07_003C8CF8);

INCLUDE_ASM("asm/levels", func_L07_003C8D60);

INCLUDE_ASM("asm/levels", func_L07_003C8FF8);

/* localdecomp:start func_L07_003C90F8 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L07_003C90F8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 t = func_0038DAB8(*(f32 *)(p + 0x4C8), 0.06283186f);

    *(f32 *)(p + 0x4C8) = t;
    t = func_0038DB00(t, *(f32 *)(a0 + 0xF8));
    *(f32 *)(p + 0x288) = t;
    *(f32 *)(p + 0x2A8) = t;
}
/* localdecomp:end func_L07_003C90F8 */

/* localdecomp:start func_L07_003C9150 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L07_003C9150(u8 *a0, u8 *a1) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v = func_0038D160(*(f32 *)(a1 + 0) - *(f32 *)(a0 + 0x10),
                          *(f32 *)(a1 + 4) - *(f32 *)(a0 + 0x14));
    *(f32 *)(q + 0x2A8) = func_0038DB00(v, *(f32 *)(a0 + 0xF8));
}
/* localdecomp:end func_L07_003C9150 */

INCLUDE_ASM("asm/levels", func_L07_003C91A8);

INCLUDE_ASM("asm/levels", func_L07_003C9280);

INCLUDE_ASM("asm/levels", func_L07_003C9488);

INCLUDE_ASM("asm/levels", func_L07_003C9528);

INCLUDE_ASM("asm/levels", func_L07_003C96C0);

/* localdecomp:start func_L07_003C9780 */
void func_L07_003C9780(float *a, float *b, float da, float db) {
    *a += da;
    if (*a > 1.0f) {
        *a = 1.0f;
    }
    *b += db;
    if (*b > 1.0f) {
        *b -= 1.0f;
    }
}
/* localdecomp:end func_L07_003C9780 */

/* localdecomp:start func_L07_003C97D0 */
/* from rac2-decomp's func_00312E10, renamed */
int func_L07_003C97D0(unsigned char *p) { return p[0x20] == 1; }
/* localdecomp:end func_L07_003C97D0 */

INCLUDE_ASM("asm/levels", func_L07_003C97E0);

INCLUDE_ASM("asm/levels", func_L07_003C99A0);

INCLUDE_ASM("asm/levels", func_L07_003C9C40);

/* localdecomp:start func_L07_003C9D50 */
extern void func_L07_003C9D88(u8 *o, s32 a);

void func_L07_003C9D50(u8 *a) {
    func_L07_003C9D88(a, 0);
    func_L07_003C9D88(a, 1);
}
/* localdecomp:end func_L07_003C9D50 */

INCLUDE_ASM("asm/levels", func_L07_003C9D88);

INCLUDE_ASM("asm/levels", func_L07_003C9E88);
