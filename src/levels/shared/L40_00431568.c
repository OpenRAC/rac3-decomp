#include "common.h"

/* declared by functions of L40_00430928.c, which this file was cut from */
extern void func_L39_00662B18(u8 *, void *, s32);

/* localdecomp:start func_L40_00431568 */
extern void func_L39_00662B18(u8 *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 *func_L39_0061BF38(s32);
extern void func_L01_00451F60(s32, s32, s32);
typedef struct { u8 pad[0x58]; f32 totals[8]; } T_00431568;
extern T_00431568 D_L40_00357260;
typedef struct { u8 pad[0x128]; s32 time; u8 pad2[0x500]; } G_00431568;
extern G_00431568 D_001A5CD0;
extern s32 *D_001D5A10_sda;

void func_L40_00431568(u8 *a0, u8 *msg) {
    u8 *data = *(u8 **)(a0 + 0x68);
    u8 counts[8];
    f32 damage;
    s32 i;

    switch (*(s32 *)msg & 0xF) {
    case 0:
        func_L39_00662B18(msg, counts, 8);
        {
            s32 k;
            for (k = 0; k < 8; k++) {
                D_L40_00357260.totals[k] += counts[k];
            }
        }
        if (a0[0x20] != 2) {
            func_L01_004450F0(a0, 2, -1);
        }
        *(f32 *)(data + 0x30) = 0.0f;
        *(s32 *)(data + 0x80) = 1;
        break;
    case 1:
        func_L39_00662B18(msg, &damage, 4);
        func_L39_00662B18(msg, counts, 8);
        {
            s32 k;
            for (k = 0; k < 8; k++) {
                D_L40_00357260.totals[k] += counts[k];
            }
        }
        if (*(s32 *)(data + 0x80) == 0 && *(s32 *)(data + 0x84) < *(s32 *)(msg + 4)) {
            f32 left = *(f32 *)(data + 0x30) - damage;
            f32 clamped = left > 0.0f ? left : 0.0f;
            *(f32 *)(data + 0x30) = clamped;
        }
        {
            s32 now = D_001A5CD0.time;
            if (now - *(s32 *)(data + 0x90) > 10000) {
                *(s32 *)(data + 0x90) = now;
                for (i = 0; i < *D_001D5A10_sda; i++) {
                    u8 *p = func_L39_0061BF38(i);
                    if (p != 0 && *(s32 *)(p + 0x2548) == *(s32 *)(data + 0x88)) {
                        func_L01_00451F60(0x1739, -1, p[0x24C9]);
                    }
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L40_00431568 */

/* localdecomp:start func_L40_00431768 */
extern void *func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern u8 *func_L39_0061CEA0(void *);
extern void func_L39_005F33E0(s32, s32, void *);
extern void func_0038CB78(void *, int, int);
extern void func_003C4A40(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L40_004313A0(void *, f32, void *);
extern f32 func_L40_00431338(s32 a0, void *a1);
extern void func_L40_004314C0(s32 id, s32 value);
extern s32 func_L40_00431540(s32 a0);

typedef u8 (*VFn_00431768)(void *, s32);

s32 func_L40_00431768(u8 *a0, s32 a1) {
    u8 *data = *(u8 **)(a0 + 0x68);
    u8 *res;
    u8 *obj;
    u8 *owner;
    f32 amount;
    f32 extra;
    s32 ok;
    u8 buf[8];

    if (a1 != 0) {
        return 0;
    }
    if (*(s32 *)(data + 0x80) == 0) {
    res = func_L01_00447490(a0, 0x10000, 0);
    amount = func_L01_004474E8(a0, res);
    if (res != 0 && *(void **)(res + 0x20) != 0) {
        owner = 0;
        obj = func_L39_0061CEA0(*(void **)(res + 0x20));
        ok = 1;
        if (obj != 0) {
            ok = (u8)(((VFn_00431768 *)*(u8 **)(obj + 0x14))[7](obj, *(s32 *)(data + 0x88)) ^ 1);
        }
        if (ok) {
            func_L39_005F33E0(2, 0, a0);
            if (obj != 0 && !(obj[3] & 0xF)) {
                owner = obj;
            }
            func_0038CB78(buf, 0, 8);
            extra = func_L40_00431338((s32)a0, buf);
            func_003C4A40(a0, data + 0x70);
            if (owner != 0) {
                buf[*(s32 *)(owner + 0x2544)] += (s32)amount;
            }
            amount += extra;
            if (*(void **)(res + 0x20) != 0) {
                f32 left = *(f32 *)(data + 0x30) - amount;
                f32 clamped = left > 0.0f ? left : 0.0f;
                if (clamped == 0.0f) {
                    func_L01_004450F0(a0, 2, -1);
                    if (!func_L40_00431540((s32)a0)) {
                        func_L40_004314C0((s32)a0, (s32)buf);
                    }
                } else {
                    func_L40_004313A0(a0, amount, buf);
                }
            }
        }
    }
    a0[0xA8] = 0xFF;
    }
    return 0;
}
/* localdecomp:end func_L40_00431768 */
