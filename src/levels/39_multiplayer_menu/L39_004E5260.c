#include "common.h"

/* localdecomp:start func_L39_004E5260 */
extern s32 D_L39_0046D354[];

s32 func_L39_004E5260(s32 arg0, s32 arg1, u8 *arg2, s32 arg3) {
    if (D_L39_0046D354[0] != 0) {
        return ((s32 (*)(s32, s32, u8 *, s32))D_L39_0046D354[0])(arg0, arg1, arg2, arg3);
    }
    return 0;
}
/* localdecomp:end func_L39_004E5260 */

LINKER_REMNANT("asm/levels", func_L39_004E5298);

INCLUDE_ASM("asm/levels", func_L39_004E52A0);

INCLUDE_ASM("asm/levels", func_L39_004E52B0);

INCLUDE_ASM("asm/levels", func_L39_004E6030);

INCLUDE_ASM("asm/levels", func_L39_004E7E58);

/* localdecomp:start func_L39_004E9A68 */
extern u8 D_L39_00453B40[];
extern u8 D_L39_00477400[];
extern void *func_0011D380(void *, const void *, unsigned int);

typedef struct { u16 data[64]; } RC2_KEY_004E9A68;

/* RC2 key schedule (RFC 2268). Matches with Sony's ee-gcc 2.9-ee-991111 (ee29check.sh), not 2.96:
 * 16-byte save slots with $ra highest. */
void func_L39_004E9A68(RC2_KEY_004E9A68 *key, s32 len, u8 *data, s32 bits) {
    u8 L[128];
    s32 i;
    s32 T8;
    u32 TM;

    if (len < 0) {
        data = D_L39_00453B40;
        len = 1;
    } else if (len > 128) {
        len = 128;
    }
    if (bits == 0) {
        bits = 1024;
    }
    T8 = (bits + 7) / 8;
    TM = ~(0xff << (8 + bits - 8 * T8));
    func_0011D380(L, data, len);
    for (i = len; i < 128; i++) {
        L[i] = D_L39_00477400[(L[i - 1] + L[i - len]) & 0xff];
    }
    L[128 - T8] = D_L39_00477400[L[128 - T8] & TM];
    for (i = 127 - T8; i >= 0; i--) {
        L[i] = D_L39_00477400[L[i + 1] ^ L[i + T8]];
    }
    for (i = 0; i < 128; i += 2) {
        key->data[i / 2] = L[i] | (L[i + 1] << 8);
    }
}
/* localdecomp:end func_L39_004E9A68 */

INCLUDE_ASM("asm/levels", func_L39_004E9C10);

/* localdecomp:start func_L39_004E9CD0 */
typedef struct {
    u32 x;
    u32 y;
    u32 data[256];
} RC4_KEY_004E9CD0;

void func_L39_004E9CD0(RC4_KEY_004E9CD0 *key, s32 len, u8 *data) {
    u32 tmp;
    s32 id1, id2;
    u32 *d;
    s32 i;

    d = key->data;
    key->x = 0;
    key->y = 0;
    for (i = 0; i < 256; i++) {
        d[i] = i;
    }
    id1 = id2 = 0;
    for (i = 0; i < 256; i++) {
        tmp = d[i];
        id2 = (data[id1] + tmp + id2) & 0xff;
        if (++id1 == len) id1 = 0;
        d[i] = d[id2];
        d[id2] = tmp;
    }
}
/* localdecomp:end func_L39_004E9CD0 */

LINKER_REMNANT("asm/levels", func_L39_004E9D68);

/* localdecomp:start func_L39_004E9D70 */
typedef struct S_004E9D70 {
    u8 pad0[0x18];
    struct S_004E9D70 *self;
    u8 pad1C[4];
    void *f20;
    s32 f24;
    u8 pad28[8];
    u32 flags;
    u8 pad34[4];
} S_004E9D70;

extern S_004E9D70 D_L39_0046D360;
extern u8 D_L39_0046D398[];
extern void *func_L39_004DF6A8(void);
extern void func_L39_004EA230(void *, s32, void *);

void *func_L39_004E9D70(s32 arg0) {
    s32 arg;

    if (!(D_L39_0046D360.flags & 2)) {
        arg = 2;
        D_L39_0046D360.flags |= 2;
        D_L39_0046D360.self = &D_L39_0046D360;
        D_L39_0046D360.f20 = func_L39_004DF6A8();
        D_L39_0046D360.f24 = 0;
        func_L39_004EA230(D_L39_0046D398, 16, &arg);
    }
    return D_L39_0046D398;
}
/* localdecomp:end func_L39_004E9D70 */

/* localdecomp:start func_L39_004E9DE8 */
typedef struct {
    u8 state[24];
    u8 *state2;
    u32 count;
    void *md;
    void *ctx;
} S_004E9DE8_st;

typedef struct {
    u8 pad[0xC];
    S_004E9DE8_st *st;
} S_004E9DE8;

extern void *func_L39_004DE940(void);
extern void func_L39_004EA080(S_004E9DE8 *, u8 *, s32);
extern s32 func_L01_00494120(void *);
extern s32 func_L39_004DD690(void *, void *);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, void *, s32 *);
extern void func_L39_004DE9B8(void *);

s32 func_L39_004E9DE8(S_004E9DE8 *obj, u8 *buf, s32 num) {
    S_004E9DE8_st *st;
    void *ctx;
    s32 i, j, k1, k2, mdlen;
    s32 outlen;
    u8 local_md[32];

    st = obj->st;
    ctx = st->ctx;
    if (ctx == 0) {
        ctx = func_L39_004DE940();
        if (ctx == 0) {
            return 0;
        }
    }
    func_L39_004EA080(obj, buf, num);
    i = 0;
    mdlen = func_L01_00494120(st->md);
    while (i < num) {
        func_L39_004DD690(ctx, st->md);
        func_L39_004DD778(ctx, st->state, 24);
        func_L39_004DD778(ctx, st->state2, 24);
        func_L39_004DD778(ctx, &st->count, 4);
        st->count++;
        func_L39_004DD7A8(ctx, local_md, &outlen);
        j = mdlen;
        while (i < num && j != 0) {
            buf[i++] = local_md[--j];
        }
        func_L39_004DD690(ctx, st->md);
        func_L39_004DD778(ctx, st->state, 24);
        func_L39_004DD778(ctx, st->state2, 24);
        func_L39_004DD778(ctx, &st->count, 4);
        func_L39_004DD778(ctx, local_md, mdlen);
        func_L39_004DD7A8(ctx, local_md, &outlen);
        k1 = (st->count * (mdlen / 2)) % 24;
        k2 = (k1 + mdlen / 2) % 24;
        for (j = 0; j < mdlen / 2; j++) {
            st->state[(k1 + j) % 24] ^= local_md[j];
            st->state2[(k2 + j) % 24] ^= local_md[j + mdlen / 2];
        }
    }
    if (st->ctx == 0) {
        func_L39_004DE9B8(ctx);
    }
    return num;
}
/* localdecomp:end func_L39_004E9DE8 */
