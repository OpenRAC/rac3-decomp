#include "common.h"

typedef struct { u8 pad0[0xF4]; u8 *p; } O_A;

INCLUDE_ASM("asm/levels", func_L39_006873F0);

INCLUDE_ASM("asm/levels", func_L39_00687450);

INCLUDE_ASM("asm/levels", func_L39_00687508);

INCLUDE_ASM("asm/levels", func_L39_00687640);

/* localdecomp:start func_L39_006876A0 */
extern void func_L39_006B6A80(void *, s32);
extern void func_L39_006B6AA8(void *, s32);
extern void func_L39_006B6AD8(void *, s32);
extern void func_L39_00687268(void *, s32);
extern s32 func_L39_006B6AD0(s32);
extern s32 func_L39_006B6BC0(void *);
extern void func_1206F4(void *, s32);

s32 func_L39_006876A0(void *a0, s32 a1, void *a2, void *a3, void *a4) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)a0 + 0xD4);
    if (temp_s0 != 0) {
        func_L39_006B6A80(temp_s0, a1);
        func_L39_006B6AA8(temp_s0, (s32)a2);
        func_L39_006B6AD8(temp_s0, (s32)a3);
        func_L39_00687268(a0, 0x1C);
        if (a4 != 0) {
            func_1206F4(a4, func_L39_006B6AD0((s32)temp_s0));
        }
        return func_L39_006B6BC0(temp_s0);
    }
    return 0;
}
/* localdecomp:end func_L39_006876A0 */

/* localdecomp:start func_L39_00687750 */
void func_L39_00687268(void *, s32);
void func_L39_0069F5E8(s32);
void func_L39_0069F618(s32, s32);

void func_L39_00687750(void *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x104);
    if (temp_s0 != 0) {
        func_L39_0069F5E8(temp_s0);
        func_L39_00687268(arg0, 0x28);
        func_L39_0069F618(temp_s0, arg1);
    }
}
/* localdecomp:end func_L39_00687750 */

/* localdecomp:start func_L39_006877B0 */
extern void func_L39_006C87E0(void *a);
extern void func_L39_00687268(void *a, s32 b);
s32 func_L39_006877B0(O_A *a0) {
    u8 *s = a0->p;
    s32 r = 0;
    if (s != 0) {
        func_L39_006C87E0(s);
        func_L39_00687268(a0, 0x24);
        r = *(s32 *)(s + 0x2A8);
    }
    return r;
}
/* localdecomp:end func_L39_006877B0 */

/* localdecomp:start func_L39_00687800 */
void func_L39_00687268(void *, s32);
void func_L39_006CAA70(void *);
void func_L39_006CAA98(void *, s32, s32);

s32 func_L39_00687800(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_s0 = *(void **)((u8 *)arg0 + 0xF8);
    if (arg3 > 0) {
        if (temp_s0 != 0) {
            do {
                func_L39_006CAA70(temp_s0);
                func_L39_006CAA98(temp_s0, arg2, arg3);
            } while (0);
            do {
                *(s32 *)((u8 *)temp_s0 + 0x6B0) = arg4;
            } while (0);
            func_L39_00687268(arg0, 0x25);
            if (*(u8 *)((u8 *)temp_s0 + 0x6B4) == 0) {
                return *(s32 *)((u8 *)temp_s0 + 0x6B0);
            }
        }
    }
    return -1;
}
/* localdecomp:end func_L39_00687800 */

/* localdecomp:start func_L39_006878A0 */
void func_L39_00687268(void *, s32);
void func_L39_0069EAA8(void *);

s32 func_L39_006878A0(void *arg0) {
    s32 var_v0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x108);
    var_v0 = -1;
    if (temp_s0 != 0) {
        func_L39_0069EAA8(temp_s0);
        func_L39_00687268(arg0, 0x29);
        var_v0 = *(s32 *)((u8 *)temp_s0 + 0x2A8);
    }
    return var_v0;
}
/* localdecomp:end func_L39_006878A0 */

/* localdecomp:start func_L39_006878F0 */
extern void func_L39_006CC0E8(void *);
extern void func_L39_006CC108(void *, f32, f32);
extern void func_L39_00687268(void *, s32);

s32 func_L39_006878F0(void *a0, f32 a1, f32 a2) {
    void *p = *(void **)((u8 *)a0 + 0xEC);
    if (p != 0) {
        func_L39_006CC0E8(p);
        func_L39_006CC108(p, a1, a2);
        func_L39_00687268(a0, 0x22);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_006878F0 */

/* localdecomp:start func_L39_00687968 */
extern u8 D_L39_0047C208[];
void func_L39_0067EE00(void *);

void *func_L39_00687968(void *arg0) {
    u8 *obj;
    u8 *p;
    s32 i;
    s32 n1;
    s32 n2;

    obj = arg0;
    func_L39_0067EE00(arg0);
    *(u8 **)(obj + 0x60) = D_L39_0047C208;
    n1 = -1;
    n2 = 0x2D;
    *(s32 *)(obj + 0x270) = n1;
    *(s32 *)(obj + 0x284) = n2;
    *(s32 *)(obj + 0x288) = n2;
    *(s32 *)(obj + 0x274) = n1;
    *(s32 *)(obj + 0x28C) = n2;
    p = obj + 0x1C0;
    i = 0x2A;
    do {
        *(s32 *)(p - 0x15C) = 0;
        i--;
        *(s32 *)(p - 0xB0) = 0;
        *(s32 *)p = 0x2D;
        p += 4;
    } while (i >= 0);
    return obj;
}
/* localdecomp:end func_L39_00687968 */

INCLUDE_ASM("asm/levels", func_L39_006879E0);

INCLUDE_ASM("asm/levels", func_L39_00688108);

/* localdecomp:start func_L39_00688340 */
void func_L39_005F1718();
s32 func_L39_005F3548();

s32 func_L39_00688340(void) {
    s32 temp_s0;

    temp_s0 = func_L39_005F3548();
    func_L39_005F1718();
    func_L39_005F1718();
    return temp_s0;
}
/* localdecomp:end func_L39_00688340 */

LINKER_REMNANT("asm/levels", func_L39_00688378);

/* localdecomp:start func_L39_00688388 */
extern u8 D_L39_0047C2F8[];
void func_L39_0067EE00(void *);

void *func_L39_00688388(void *arg0) {
    u8 *obj;
    s32 i;

    obj = arg0;
    ((void *(*)(void *))func_L39_0067EE00)(arg0);
    *(s32 *)(obj + 0x10C) = 0;
    *(u8 **)(obj + 0x60) = D_L39_0047C2F8;
    for (i = 0x5F; i >= 0; i--) {
        ((s32 *)(obj + 0x110))[i] = 0;
    }
    *(s32 *)(obj + 0x290) = -1;
    *(u8 **)(obj + 0x2A4) = obj + 0x2A8;
    return obj;
}
/* localdecomp:end func_L39_00688388 */
