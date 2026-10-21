#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006774F0);

INCLUDE_ASM("asm/levels", func_L39_006775B8);

INCLUDE_ASM("asm/levels", func_L39_006775E8);

/* localdecomp:start func_L39_006776D8 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
    s32 w16;
    s32 w20;
    s32 w24;
    u8 b28;
    u8 pad[3];
} S_00674CF0;
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_0053BED0(void *);
extern void func_L39_0066E100(s32, s32, s32, s32, s32, s32, s32, void *);
s32 func_L39_006776D8(s32 a0, s32 a1, s32 a2, void *a3) {
    S_00674CF0 buf;
    func_0038CC88(&buf, a3, 32);
    if (buf.b28 == 13) {
        func_L39_0053BED0(&buf);
    } else {
        func_L39_0066E100(buf.w16, buf.w20, buf.b28, 0, buf.w24, buf.w12, 0, &buf);
    }
    return 32;
}
/* localdecomp:end func_L39_006776D8 */

INCLUDE_ASM("asm/levels", func_L39_00677740);

INCLUDE_ASM("asm/levels", func_L39_006778A0);

/* localdecomp:start func_L39_006779A8 */
extern u8 *D_L39_001E084C;
extern void func_0038CC88(void *dst, void *src, s32 n);
s32 func_L39_006779A8(s32 a0, s32 a1, s32 a2, void *a3) {
    s32 buf[2];
    u8 *m;
    s32 *q;
    func_0038CC88(buf, a3, 8);
    if (buf[0] >= 0) {
        m = D_L39_001E084C + (buf[0] << 8);
        if (m != 0 && m[32] != 254 && m[32] != 253) {
            q = *(s32 **)(m + 104);
            if (q != 0 && *q == -1) {
                *q = buf[1];
            }
        }
    }
    return 8;
}
/* localdecomp:end func_L39_006779A8 */

INCLUDE_ASM("asm/levels", func_L39_00677A20);

/* localdecomp:start func_L39_00677B40 */
extern void func_0038CC88(void *dst, void *src, s32 n);
extern void func_L39_006684A0(void *a0);
s32 func_L39_00677B40(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 buf[36];
    ((void (*)(void *a0, s32 a1, s32 a2))func_0038CC88)(buf, a3, 36);
    if ((buf[31] & 0xF) == 3) {
        func_L39_006684A0(buf);
    }
    return 36;
}
/* localdecomp:end func_L39_00677B40 */

/* localdecomp:start func_L39_00677B88 */
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_00670AE0(void *);
s32 func_L39_00677B88(s32 a0, s32 a1, s32 a2, void *a3) {
    u8 buf[12];
    func_0038CC88(buf, a3, 12);
    func_L39_00670AE0(buf);
    return 12;
}
/* localdecomp:end func_L39_00677B88 */

INCLUDE_ASM("asm/levels", func_L39_00677BB8);

/* localdecomp:start func_L39_00677CB8 */
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_0066FA90(void *);
s32 func_L39_00677CB8(s32 a0, s32 a1, s32 a2, void *a3) {
    u8 buf[104];
    func_0038CC88(buf, a3, 104);
    func_L39_0066FA90(buf);
    return 104;
}
/* localdecomp:end func_L39_00677CB8 */
