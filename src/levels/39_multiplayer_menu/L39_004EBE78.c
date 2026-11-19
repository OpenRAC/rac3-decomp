#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EBE78 */
extern s32 func_L39_004CA3D0(void *, void **, void **);
extern s32 func_L39_004DE8F8(void *);
extern s32 func_L01_00494120(void *);
extern s32 func_L01_004CC758(void *);
extern void func_L39_004EBF88(void *);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004EB8B0(void *, void *, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004EBE78(u8 *a0) {
    void *out[2];
    s32 n;
    void *p;

    if (*(s32 *)(*(u8 **)(a0 + 0x54) + 0x184) != 0) {
        return 1;
    }
    if (func_L39_004CA3D0(*(void **)(*(u8 **)(a0 + 0xB0) + 0xAC), &out[0], &out[1]) == 0) {
        func_L39_004BC6C8(0x14, 0x9E, 0x8A, 0, 0);
        return 0;
    }
    *(void **)(*(u8 **)(a0 + 0x54) + 0x18C) = out[0];
    *(void **)(*(u8 **)(a0 + 0x54) + 0x190) = out[1];
    n = func_L39_004DE8F8(out[0]) + func_L01_00494120(out[1]) + func_L01_004CC758(out[0]);
    n = n * 2 + 1;
    func_L39_004EBF88(a0);
    p = func_L39_004BEED8(n);
    if (p != 0) {
        *(s32 *)(*(u8 **)(a0 + 0x54) + 0x184) = n;
        *(void **)(*(u8 **)(a0 + 0x54) + 0x188) = p;
        func_L39_004EB8B0(a0, p, n);
        return 1;
    }
    func_L39_004BC6C8(0x14, 0x9E, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004EBE78 */

/* localdecomp:start func_L39_004EBF88 */
extern void *func_11D534(void *, s32, u32);
extern void func_L39_004BEF28(void *);

void func_L39_004EBF88(void *arg0) {
    u8 *a0 = arg0;

    if (*(void **)(*(u8 **)(a0 + 0x54) + 0x188) != 0) {
        func_11D534(*(void **)(*(u8 **)(a0 + 0x54) + 0x188), 0, *(u32 *)(*(u8 **)(a0 + 0x54) + 0x184));
        func_L39_004BEF28(*(void **)(*(u8 **)(a0 + 0x54) + 0x188));
        *(void **)(*(u8 **)(a0 + 0x54) + 0x188) = 0;
    }
    *(u32 *)(*(u8 **)(a0 + 0x54) + 0x184) = 0;
}
/* localdecomp:end func_L39_004EBF88 */

/* localdecomp:start func_L39_004EBFE0 */
extern void *func_L39_00505060(void *);
extern u32 func_L39_004DE908(void *);
extern void *func_11D380(void *, const void *, u32);
extern void func_L39_00504A30(void *, u8 *, u8 *, u32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004C9F50(void *, s32, s32);

typedef struct Rec_004EBFE0 {
    s32 type;
    u32 length;
    s32 off;
    u8 *data;
    u8 *input;
} Rec_004EBFE0;

/* OpenSSL's ssl3_enc */
s32 func_L39_004EBFE0(u8 *s, s32 send) {
    Rec_004EBFE0 *rec;
    void *ds;
    u64 l;
    s32 bs, i;
    void *enc;

    if (send) {
        ds = *(void **)(s + 0x7C);
        rec = (Rec_004EBFE0 *)(*(u8 **)(s + 0x54) + 0xCC);
    } else {
        ds = *(void **)(s + 0x70);
        rec = (Rec_004EBFE0 *)(*(u8 **)(s + 0x54) + 0xB4);
    }
    if (ds == 0) {
        enc = 0;
    } else {
        enc = func_L39_00505060(ds);
    }

    if (*(void **)(s + 0xB0) == 0 || ds == 0 || enc == 0) {
        func_11D380(rec->data, rec->input, rec->length);
        rec->input = rec->data;
    } else {
        l = rec->length;
        bs = func_L39_004DE908(ds);
        if (bs != 1 && send) {
            i = bs - ((s32)l % bs);
            l += i;
            rec->length += i;
            rec->input[l - 1] = i - 1;
        }
        func_L39_00504A30(ds, rec->data, rec->input, l);
        if (bs != 1 && !send) {
            i = rec->data[l - 1] + 1;
            if (i > bs) {
                func_L39_004BC6C8(0x14, 0x86, 0x81, 0, 0);
                func_L39_004C9F50(s, 2, 0x33);
                return 0;
            }
            rec->length -= i;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_004EBFE0 */
