#include "common.h"

/* localdecomp:start func_L39_00518C30 */
extern u32 func_L39_00518A78(const char *nptr, char **endptr, s32 base, s32 *err);
extern u32 func_L39_00518A38(u32 x);

s32 func_L39_00518C30(const char *cp, u32 *addr) {
    u32 val;
    u32 parts[4];
    u32 *pp = parts;
    char *endp;
    s32 err;
    s32 n = 0;
    s32 done = 0;
    char c;
    u8 uc;

    do {
        err = 0;
        val = func_L39_00518A78(cp, &endp, 0, &err);
        if (err == 34 || endp == cp) {
            return 0;
        }
        cp = endp;
        *pp = val;
        c = uc = *cp;
        if (c == 0) {
            done = 1;
        } else if (c == '.') {
            if (n == 3) {
                return 0;
            }
            cp++;
            pp++;
            n++;
        } else {
            if ((u32)(uc - 9) >= 5 && uc != ' ') {
                return 0;
            }
            done = 1;
        }
    } while (!done);

    switch (n) {
    case 0:
        break;
    case 1:
        if (val > 0xFFFFFF || parts[0] > 0xFF) {
            return 0;
        }
        val |= parts[0] << 24;
        break;
    case 2:
        if (val > 0xFFFF || parts[0] > 0xFF || parts[1] > 0xFF) {
            return 0;
        }
        val |= (parts[0] << 24) | (parts[1] << 16);
        break;
    case 3:
        if (val > 0xFF || parts[0] > 0xFF || parts[1] > 0xFF || parts[2] > 0xFF) {
            return 0;
        }
        val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
        break;
    }
    if (addr) {
        *addr = func_L39_00518A38(val);
    }
    return 1;
}
/* localdecomp:end func_L39_00518C30 */

INCLUDE_ASM("asm/levels", func_L39_00518E34);

/* localdecomp:start func_L39_00518E48 */
typedef struct S_00518E48 {
    long f0;
    long f8;
    u16 f10;
} S_00518E48;

extern S_00518E48 D_L39_00479AA0;
extern S_00518E48 D_L39_00453DB8;
extern void *func_L39_00518EA8(s32, s32 *, S_00518E48 *, s32);

S_00518E48 *func_L39_00518E48(s32 arg0) {
    s32 local = arg0;
    D_L39_00453DB8.f0 = D_L39_00479AA0.f0;
    D_L39_00453DB8.f8 = D_L39_00479AA0.f8;
    D_L39_00453DB8.f10 = D_L39_00479AA0.f10;
    func_L39_00518EA8(2, &local, &D_L39_00453DB8, 0x12);
    return &D_L39_00453DB8;
}
/* localdecomp:end func_L39_00518E48 */

/* localdecomp:start func_L39_00518EA8 */
struct S_00518E48;
extern void *func_L39_00518F20(u8 *, void *, u32);
extern s32 *func_L39_005192F8(void);
extern s32 func_L39_00518FD0(void);
extern s32 *func_0011A6E0(void);
void *func_L39_00518EA8(s32 a0, s32 *a1, struct S_00518E48 *a2, s32 a3) {
    s32 *p;
    if (a0 == 2) {
        return func_L39_00518F20((u8 *)a1, a2, a3);
    }
    *func_L39_005192F8() = 0x6A;
    if (func_L39_00518FD0() != 0) {
        p = func_0011A6E0();
        *p = *func_L39_005192F8();
    }
    return 0;
}
/* localdecomp:end func_L39_00518EA8 */

/* localdecomp:start func_L39_00518F20 */
extern s32 D_00479AB8[];
s32 func_00128BA8(void *, s32, void *, s32, s32, s32, s32);
s32 *func_L39_005192F8(void);
s32 func_L39_00518FD0(void);
s32 *func_0011A6E0(void);
s32 func_001206F4(void *, void *);

void *func_L39_00518F20(u8 *a0, void *a1, u32 a2) {
    u8 buf[16];
    s32 *p;
    if (a2 < func_00128BA8(buf, 16, D_00479AB8, a0[0], a0[1], a0[2], a0[3])) {
        *func_L39_005192F8() = 0x1C;
        if (func_L39_00518FD0() != 0) {
            p = func_0011A6E0();
            *p = *func_L39_005192F8();
        }
        return 0;
    }
    func_001206F4(a1, buf);
    return a1;
}
/* localdecomp:end func_L39_00518F20 */

INCLUDE_ASM("asm/levels", func_L39_00518FC4);
