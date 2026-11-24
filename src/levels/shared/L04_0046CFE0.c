#include "common.h"

/* localdecomp:start func_L04_0046CFE0 */
extern u8 *func_L01_0045B958(void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern s32 func_L01_0045D218(void *, void *);
extern f32 func_0038CF38(void *, void *);

s32 func_L04_0046CFE0(u8 *self, u8 *path) {
    u8 *p;
    f32 d;
    f32 thr;
    f32 d2;
    s32 cur;
    s32 tgt;
    if (*(s16 *)(self + 0xAA) == 0x1BDC) {
        p = func_L01_0045B958(self);
        if (p == 0) {
            return 0;
        }
        if (path != *(u8 **)(p + 0xC4)) {
            func_L01_0045C150(self, path, -1, 0);
        }
        func_L01_0045D218(self, path + (*(s16 *)(p + 0xC8) * 16 + 0x10));
        if (*(s32 *)(p + 0x38) & 0x400) {
            d = func_0038CF38(self + 0x10, path + (*(s16 *)(p + 0xC8) * 16 + 0x10));
        } else {
            d = func_0038CF38(self + 0x10, path + (*(s16 *)(p + 0xC8) * 16 + 0x10));
        }
        thr = (*(s32 *)(p + 0x38) & 0x400) ? 0.5f : 0.85f;
        if (d <= thr) {
            tgt = *(s16 *)(p + 0xCA);
            cur = *(s16 *)(p + 0xC8);
            if (tgt == cur) {
                return 1;
            }
            if (tgt < cur) {
                *(u16 *)(p + 0xC8) = *(u16 *)(p + 0xC8) - 1;
            } else {
                *(u16 *)(p + 0xC8) = *(u16 *)(p + 0xC8) + 1;
            }
        }
        return 0;
    } else {
        p = func_L01_0045B958(self);
        if (p == 0) {
            return 0;
        }
        if (path != *(u8 **)(p + 0xC4)) {
            func_L01_0045C150(self, path, -1, 0);
        }
        func_L01_0045D218(self, path + (*(s16 *)(p + 0xCA) * 16 + 0x10));
        if (*(s32 *)(p + 0x38) & 0x400) {
            d2 = func_0038CF38(self + 0x10, path + (*(s16 *)(p + 0xCA) * 16 + 0x10));
        } else {
            d2 = func_0038CF38(self + 0x10, path + (*(s16 *)(p + 0xCA) * 16 + 0x10));
        }
        if (d2 <= 0.5f) {
            tgt = *(s16 *)(p + 0xCA);
            cur = *(s16 *)(p + 0xC8);
            if (tgt == cur) {
                return 1;
            }
            if (tgt < cur) {
                *(u16 *)(p + 0xC8) = *(u16 *)(p + 0xC8) - 1;
            } else {
                *(u16 *)(p + 0xC8) = *(u16 *)(p + 0xC8) + 1;
            }
        }
        return 0;
    }
}
/* localdecomp:end func_L04_0046CFE0 */
