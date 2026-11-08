#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003AF398);

/* localdecomp:start func_L07_003AF600 */
void func_0038CB78(s32, s32, s32);
void func_L01_0043A430(void *, s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_L01_004AA760(s32, void *);

void func_L07_003AF600(void *arg0) {
    s32 temp_s0;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        temp_s0 = (*(s32 *)((u8 *)arg0 + 0x68)) + 0x90;
        func_0038CB78(temp_s0, 0, 0x40);
        func_L01_0043A430(arg0, 0, temp_s0);
        func_L01_004AA760(1, arg0);
        func_L01_004450F0(arg0, 1, -1);
    }
}
/* localdecomp:end func_L07_003AF600 */

INCLUDE_ASM("asm/levels", func_L07_003AF678);

INCLUDE_ASM("asm/levels", func_L07_003AF758);

INCLUDE_ASM("asm/levels", func_L07_003AF7B8);

INCLUDE_ASM("asm/levels", func_L07_003AF7F8);

INCLUDE_ASM("asm/levels", func_L07_003AF920);

INCLUDE_ASM("asm/levels", func_L07_003AFC10);

INCLUDE_ASM("asm/levels", func_L07_003AFD10);

/* localdecomp:start func_L07_003B0458 */
void func_L07_003B0530(void *);

void func_L07_003B0458(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        u8 *s;
        u8 *p;
        s32 i;

        f32 f;
        u8 one;

        s = (u8 *)(*(s32 *)((u8 *)arg0 + 0x68));
        f = *(f32 *)((u8 *)arg0 + 0xF8);
        one = 1;
        s[0x3E] = 3;
        *(f32 *)(s + 0x90) = f;
        p = s + 0x44;
        s[0x3F] = 0;
        s[0x64] = 0;
        *(s32 *)(s + 0x94) = 0;
        i = 0;
        do {
            *p = one;
            p--;
            i--;
        } while (i >= 0);
        func_L07_003B0530(arg0);
    }
}
/* localdecomp:end func_L07_003B0458 */

INCLUDE_ASM("asm/levels", func_L07_003B04C8);

/* localdecomp:start func_L07_003B0530 */
void func_L01_004AA7E8(void *, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003B0530(void *a0) {
    u8 *arg0 = (u8 *)a0;
    u8 *v1;

    *(s32 *)(arg0 + 0x98) = 0;
    v1 = *(u8 **)(arg0 + 0x68);
    *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x43) & 0xEFFF;
    *(u8 *)(arg0 + 0xA8) = 0xFF;
    func_L01_004AA7E8(arg0, 1);
    *(f32 *)(arg0 + 0xF8) = *(f32 *)(v1 + 0x90);
    *(s32 *)(v1 + 0x94) = 0;
    func_L01_004450F0(arg0, 8, -1);
}
/* localdecomp:end func_L07_003B0530 */

/* localdecomp:start func_L07_003B05A0 */
s32 func_L07_003B05A0(void *arg0) {
    return (u32) ((*(u8 *)((u8 *)arg0 + 0x20)) - 7) < 2U;
}
/* localdecomp:end func_L07_003B05A0 */

/* localdecomp:start func_L07_003B05B0 */
s32 func_L01_00447490(void *, s32, s32);
void func_L01_00456BD0(void *, s32);
void func_L07_003B0458(void *);

s32 func_L07_003B05B0(void *arg0) {
    s32 kind = *(u8 *)((u8 *)arg0 + 0x20);

    if (kind == 0) {
        func_L07_003B0458(arg0);
        return 0;
    }
    kind -= 4;
    if ((u8)kind >= 2) {
        *(u8 *)((u8 *)arg0 + 0xA8) = 0xFF;
        *(u16 *)((u8 *)arg0 + 0x34) &= 0xEFFF;
        return 0;
    }
    {
        s32 r;

        *(u16 *)((u8 *)arg0 + 0x34) |= 0x1000;
        r = func_L01_00447490(arg0, 0x30000, 0);
        if (r != 0) {
            *(u8 *)((u8 *)arg0 + 0xA8) = 0xFF;
            func_L01_004450F0(arg0, 6, -1);
        }
        func_L01_00456BD0(arg0, 3);
        return 0;
    }
}
/* localdecomp:end func_L07_003B05B0 */

INCLUDE_ASM("asm/levels", func_L07_003B0660);

INCLUDE_ASM("asm/levels", func_L07_003B0738);

INCLUDE_ASM("asm/levels", func_L07_003B0970);

INCLUDE_ASM("asm/levels", func_L07_003B0B08);

INCLUDE_ASM("asm/levels", func_L07_003B0CF8);

INCLUDE_ASM("asm/levels", func_L07_003B0E08);

INCLUDE_ASM("asm/levels", func_L07_003B0F20);

/* localdecomp:start func_L07_003B0F78 */
void func_003C7C38(void *);
void func_L07_003B0E08(void *, s32);

void func_L07_003B0F78(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    *(s32 *)((u8 *)temp_v0 + 0x48) = 0;
    *(s32 *)((u8 *)((*(void **)((u8 *)temp_v0 + 0x44))) + 0xF0) = 0;
    func_003C7C38((*(void **)((u8 *)temp_v0 + 0x44)));
    func_L07_003B0E08(arg0, 1);
}
/* localdecomp:end func_L07_003B0F78 */

/* localdecomp:start func_L07_003B0FC0 */
/* from rac4-decomp's func_01EEBC54 */
void func_L07_003B0FC0(void *arg0) {
    func_L07_003B0E08(arg0, 3);
}
/* localdecomp:end func_L07_003B0FC0 */

INCLUDE_ASM("asm/levels", func_L07_003B0FE0);

INCLUDE_ASM("asm/levels", func_L07_003B12D8);

INCLUDE_ASM("asm/levels", func_L07_003B13E8);

/* localdecomp:start func_L07_003B1578 */
typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    u8 f20;
};

/* from rac4-decomp's func_L05_004E00A8, renamed, constants adapted */
s32 func_L07_003B1578(Type1 *arg0) {
    s32 var_a0;
    u8 temp_v1;
    temp_v1 = arg0->f20;
    var_a0 = 0;
    if ((temp_v1 == 4) || (temp_v1 == 2) || (temp_v1 == 5)) {
        var_a0 = 1;
    }
    return var_a0;
}
/* localdecomp:end func_L07_003B1578 */

INCLUDE_ASM("asm/levels", func_L07_003B15A8);

INCLUDE_ASM("asm/levels", func_L07_003B1958);

INCLUDE_ASM("asm/levels", func_L07_003B1A30);

INCLUDE_ASM("asm/levels", func_L07_003B1C08);

INCLUDE_ASM("asm/levels", func_L07_003B24C8);

INCLUDE_ASM("asm/levels", func_L07_003B2738);

INCLUDE_ASM("asm/levels", func_L07_003B2870);

/* localdecomp:start func_L07_003B28B8 */
typedef struct {
    char _p0[0x20];
    u8 state;
} S_3B28B8;

/* from rac4-decomp's func_L01_0045B5D8 */
s32 func_L07_003B28B8(S_3B28B8 *arg0) {
    return arg0->state < 2;
}
/* localdecomp:end func_L07_003B28B8 */

INCLUDE_ASM("asm/levels", func_L07_003B28C8);

INCLUDE_ASM("asm/levels", func_L07_003B3028);

INCLUDE_ASM("asm/levels", func_L07_003B3160);

INCLUDE_ASM("asm/levels", func_L07_003B34A0);

INCLUDE_ASM("asm/levels", func_L07_003B3570);

INCLUDE_ASM("asm/levels", func_L07_003B3798);

INCLUDE_ASM("asm/levels", func_L07_003B37D0);

INCLUDE_ASM("asm/levels", func_L07_003B3A88);

INCLUDE_ASM("asm/levels", func_L07_003B3C78);

INCLUDE_ASM("asm/levels", func_L07_003B3DB0);

INCLUDE_ASM("asm/levels", func_L07_003B4250);

INCLUDE_ASM("asm/levels", func_L07_003B4308);

INCLUDE_ASM("asm/levels", func_L07_003B4370);

INCLUDE_ASM("asm/levels", func_L07_003B4470);

/* localdecomp:start func_L07_003B4688 */
extern void func_003C2F58(void *, s32, void *);

void func_L07_003B4688(void *arg0) {
    s32 i;
    u8 *p;

    i = 0;
    p = (u8 *)(*(s32 *)((u8 *)arg0 + 0x68)) + 0x330;
    do {
        func_003C2F58(arg0, i, p);
        i++;
        p += 0x10;
    } while (i < 6);
}
/* localdecomp:end func_L07_003B4688 */

INCLUDE_ASM("asm/levels", func_L07_003B46E8);

INCLUDE_ASM("asm/levels", func_L07_003B48E8);

INCLUDE_ASM("asm/levels", func_L07_003B4978);

/* localdecomp:start func_L07_003B4B68 */
void func_L07_003B4C30(void *, u8, f32, u8);

void func_L07_003B4B68(void *arg0, s16 arg1, f32 arg2) {
    s32 i;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (arg1 != -1 && arg1 < 0x15) {
        return;
    }
    for (i = 0; i < 2; i++) {
        if ((arg1 & 3) == 0 && arg1 != -1) {
            func_L07_003B4C30(arg0, i, arg2, p[0x44]);
        } else {
            func_L07_003B4C30(arg0, i, arg2, 0);
        }
    }
}
/* localdecomp:end func_L07_003B4B68 */

INCLUDE_ASM("asm/levels", func_L07_003B4C30);

INCLUDE_ASM("asm/levels", func_L07_003B4DF8);

INCLUDE_ASM("asm/levels", func_L07_003B4FD0);

INCLUDE_ASM("asm/levels", func_L07_003B5CC8);

INCLUDE_ASM("asm/levels", func_L07_003B5E08);

INCLUDE_ASM("asm/levels", func_L07_003B62C8);

INCLUDE_ASM("asm/levels", func_L07_003B6320);

INCLUDE_ASM("asm/levels", func_L07_003B64D0);

INCLUDE_ASM("asm/levels", func_L07_003B6800);

INCLUDE_ASM("asm/levels", func_L07_003B6870);

/* localdecomp:start func_L07_003B68F0 */
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(char *a0, char *a1, int a2, float f12, float f13,
                              float f14, float f15);

void func_L07_003B68F0(u8 *arg0) {
    u8 *s;
    u8 *p;
    u8 *q;
    u8 flag;
    f32 r;

    s = *(u8 **)(arg0 + 0x68);
    flag = s[0x323];
    if (0.0f < *(f32 *)(s + 0x148)) {
        if (flag & 1) {
            p = *(u8 **)(s + 0x190) + 0x10;
        } else {
            p = s + 0x80;
        }
    } else {
        if (flag & 2) {
            p = *(u8 **)(s + 0x190) + 0x10;
        } else {
            p = s + 0x80;
        }
    }
    q = arg0 + 0xF8;
    r = func_0038D160(*(f32 *)p - *(f32 *)(arg0 + 0x10),
                      *(f32 *)(p + 4) - *(f32 *)(arg0 + 0x14));
    func_L01_00448890((char *)q, (char *)s + 0x154, 0, r,
                      *(f32 *)(s + 0xB4), *(f32 *)(s + 0xB8), *(f32 *)(s + 0xBC));
}
/* localdecomp:end func_L07_003B68F0 */

INCLUDE_ASM("asm/levels", func_L07_003B6998);

INCLUDE_ASM("asm/levels", func_L07_003B6AE8);

INCLUDE_ASM("asm/levels", func_L07_003B6B38);

INCLUDE_ASM("asm/levels", func_L07_003B6BD8);

INCLUDE_ASM("asm/levels", func_L07_003B6CD8);

INCLUDE_ASM("asm/levels", func_L07_003B6DC8);

INCLUDE_ASM("asm/levels", func_L07_003B6E98);

INCLUDE_ASM("asm/levels", func_L07_003B70F0);

INCLUDE_ASM("asm/levels", func_L07_003B7230);

INCLUDE_ASM("asm/levels", func_L07_003B7378);
