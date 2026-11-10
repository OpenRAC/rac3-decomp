#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

INCLUDE_ASM("asm/levels", func_L39_005013E0);

/* localdecomp:start func_L39_00501658 */
typedef struct S_00501658 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_00501658;

extern S_00501658 *func_L39_004E10B0(void);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004E1160(s32);
extern s32 func_L39_00505AE8(s32, s32, s32);
extern s32 func_L39_005017A0(s32, s32, s32);
extern void func_L39_004E1200(S_00501658 *);

S_00501658 *func_L39_00501658(s32 arg0, S_00501658 **arg1, s32 arg2, s32 arg3) {
    S_00501658 *p;
    s32 r;

    if (arg1 != 0 && *arg1 != 0) {
        p = *arg1;
    } else {
        p = func_L39_004E10B0();
        if (p == 0) {
            func_L39_004BC6C8(0xD, 0x9C, 0x806, 0, 0);
            return 0;
        }
    }
    p->f4 = arg0;
    p->f0 = func_L39_004E1160(arg0);
    switch (p->f0) {
    case 6:
        r = func_L39_00505AE8(0, arg2, arg3);
        p->fC = r;
        break;
    case 0x74:
        r = func_L39_005017A0(0, arg2, arg3);
        p->fC = r;
        break;
    default:
        func_L39_004BC6C8(0xD, 0x9C, 0x8F, 0, 0);
        goto fail;
    }
    if (r == 0) {
        func_L39_004BC6C8(0xD, 0x9C, 0x80D, 0, 0);
        goto fail;
    }
    if (arg1 != 0) {
        *arg1 = p;
    }
    return p;
fail:
    if (arg1 == 0 || *arg1 != p) {
        func_L39_004E1200(p);
    }
    return 0;
}
/* localdecomp:end func_L39_00501658 */

INCLUDE_ASM("asm/levels", func_L39_005017A0);

INCLUDE_ASM("asm/levels", func_L39_00501B08);

INCLUDE_ASM("asm/levels", func_L39_00502618);

/* localdecomp:start func_L39_00502FF8 */
extern void func_L39_00502618(u64 *, void *, s32);

/* OpenSSL's DES_encrypt3 (DES_LONG is 64-bit here) */
void func_L39_00502FF8(u64 *data, void *ks1, void *ks2, void *ks3) {
    u64 l, r, tt;

    l = data[0];
    r = data[1];
    tt = ((r >> 4) ^ l) & 0x0F0F0F0F; l ^= tt; r ^= tt << 4;
    tt = ((l >> 16) ^ r) & 0x0000FFFF; r ^= tt; l ^= tt << 16;
    tt = ((r >> 2) ^ l) & 0x33333333; l ^= tt; r ^= tt << 2;
    tt = ((l >> 8) ^ r) & 0x00FF00FF; r ^= tt; l ^= tt << 8;
    tt = ((r >> 1) ^ l) & 0x55555555; l ^= tt; r ^= tt << 1;
    data[0] = l;
    data[1] = r;
    func_L39_00502618(data, ks1, 1);
    func_L39_00502618(data, ks2, 0);
    func_L39_00502618(data, ks3, 1);
    l = data[0];
    r = data[1];
    tt = ((r >> 1) ^ l) & 0x55555555; l ^= tt; r ^= tt << 1;
    tt = ((l >> 8) ^ r) & 0x00FF00FF; r ^= tt; l ^= tt << 8;
    tt = ((r >> 2) ^ l) & 0x33333333; l ^= tt; r ^= tt << 2;
    tt = ((l >> 16) ^ r) & 0x0000FFFF; r ^= tt; l ^= tt << 16;
    tt = ((r >> 4) ^ l) & 0x0F0F0F0F; l ^= tt; r ^= tt << 4;
    data[0] = l;
    data[1] = r;
}
/* localdecomp:end func_L39_00502FF8 */

INCLUDE_ASM("asm/levels", func_L39_005031A8);

INCLUDE_ASM("asm/levels", func_L39_00503360);

INCLUDE_ASM("asm/levels", func_L39_00503B20);

/* localdecomp:start func_L39_005042F8 */
typedef struct S_005042F8 {
    s32 f0;
    s32 f4;
    s32 f8;
    void *fC;
    s32 f10;
    s32 f14;
} S_005042F8;

extern void *func_L39_004BEED8(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void *func_L39_004E2D20(void);
extern s32 func_L39_004E47A8(void);
extern s32 func_L39_004E5090(void);
extern s32 func_L39_004E48A8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L39_004E2D68(void *);
extern void func_L39_004E47F8(s32);
extern void func_L39_004BEF28(void *);

S_005042F8 *func_L39_005042F8(s32 arg0) {
    S_005042F8 *ret = 0;
    S_005042F8 *p;

    if (arg0 == 0) {
        func_L39_004BC6C8(5, 0x69, 0xE, 0, 0);
        return 0;
    }
    p = func_L39_004BEED8(0x18);
    if (p == 0) {
        func_L39_004BC6C8(5, 0x69, 0x21, 0, 0);
        return 0;
    }
    func_0011D534(p, 0, 0x18);
    p->f8 = arg0;
    if ((p->fC = func_L39_004E2D20()) != 0) {
        if ((p->f4 = func_L39_004E47A8()) != 0) {
            p->f10 = 1;
            func_L39_004E48A8(p->f4, 1, 2, 0, func_L39_004E5090(), 0, 0);
            ret = p;
            p = 0;
        }
    }
    if (p != 0) {
        if (p->fC != 0) {
            func_L39_004E2D68(p->fC);
        }
        if (p->f4 != 0) {
            func_L39_004E47F8(p->f4);
        }
        func_L39_004BEF28(p);
    }
    return ret;
}
/* localdecomp:end func_L39_005042F8 */
