#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003CF7B0 */
extern u8 D_00142CBE[];
extern s32 D_001D6694;
extern s32 D_001A71A4[];
extern u8 D_001A4C60[];
extern void func_003C2880(void *);
extern void func_L03_003CFB90(u8 *);
extern void func_L03_003CFAE8(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L03_004497E8(void *, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L02_003E71A8(f32, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L03_004495A8(void *, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045BD10(void *, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_0045A9F0(void *);
void func_L03_003CF7B0(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    s32 st;
    f32 d[4];
    s32 t;
    if (D_00142CBE[0] == 0) {
        func_003C2880(a0);
        return;
    }
    if (D_001D6694 == 2 || D_001A71A4[0] == 0x65) {
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) |= 1;
    } else {
        a0[0x31] = 1;
        *(u16 *)(a0 + 0x34) &= ~1;
    }
    st = a0[0x20];
    switch (st) {
    case 0:
        func_L03_003CFB90(a0);
        func_L01_004450F0(a0, 1, -1);
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 10);
        }
        break;
    case 1:
        if (func_L01_004561B8(a0) != 0) {
            func_L03_004497E8(a0, *(s32 *)(q + 0x2A0), 1, -1);
        }
        if (func_0038CAD0(q + 0x2C8) != 0) {
            if (func_L02_003E71A8(5.0f, a0 + 0x10, D_001A4C60) != 0) {
                vec_sub_ba(d, D_001A4C60, a0 + 0x10);
                if (func_0038CE68(d, q + 0xD0) > 0.0f) {
                    t = -*(s32 *)(q + 0x2CC);
                    *(s32 *)(q + 0x2CC) = t;
                    func_L03_004497E8(a0, *(s32 *)(q + 0x2A0), (t == 1) ? 1 : -1, -1);
                }
                *(s32 *)(q + 0x2C8) = 0x53;
            }
        }
        if (*(s32 *)(q + 0x2C8) != 0) {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 10);
            }
        } else {
            if (a0[0x43] != 2) {
                func_003C3A10(a0, 2, 0, 10);
            }
        }
        func_L03_004495A8(a0, *(s32 *)(q + 0x2A0));
        func_L01_0045BD10(a0, func_0038D160(*(f32 *)(q + 0xD0), *(f32 *)(q + 0xD4)));
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            a0[0xBC] = 0;
            *(s32 *)(q + 0x2D0) = (*(s32 *)(q + 0x2D4) != 0) ? 0xFA : 0x7D;
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 10);
            }
            *(s32 *)(q + 0x2D8) = *(s32 *)(q + 0x2D8) + 1;
            if (*(s32 *)(q + 0x2D8) < 6) {
                func_L01_00451E78(a0, 1, 0.0f);
            }
            if (*(s32 *)(q + 0x2D4) != 0) {
                func_L01_00459C50(5);
            }
            q[0x297] = 0xFF;
            func_003C4A40(a0, q + 0x290);
        }
        if (a0[0x60] & 2) {
            if (a0[0xBC] == 0 && *(s32 *)(q + 0x2D4) != 0) {
                a0[0xBC] = 1;
                if (a0[0x43] != 1) {
                    func_003C3A10(a0, 1, 0, 10);
                }
            } else {
                func_L01_004450F0(a0, 1, -1);
            }
        }
        func_L01_0045A9F0(a0);
        break;
    }
    func_L03_003CFAE8(a0);
}
/* localdecomp:end func_L03_003CF7B0 */

/* localdecomp:start func_L03_003CFAE8 */
extern s32 func_0038CAD0(void *);
extern void *func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern s32 D_001A71A4[];

void func_L03_003CFAE8(u8 *a0) {
    u8 *obj = *(u8 **)(a0 + 0x68);
    void *r;

    if (func_0038CAD0(obj + 0x2D0) != 0) {
        s32 flag;
        r = func_L01_00447490(a0, 0x10000, 0);
        flag = 0;
        if (r != 0) {
            void *q = *(void **)((u8 *)r + 0x20);
            if (q != 0 && *(s16 *)((u8 *)q + 0xAA) == 0x47) {
                flag = D_001A71A4[0] != 0x15;
            }
        }
        *(s32 *)(obj + 0x2D4) = flag;
        if (r != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
    func_L01_0044ABD0(a0, obj + 0x290);
}
/* localdecomp:end func_L03_003CFAE8 */

/* localdecomp:start func_L03_003CFB90 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_00477ED0(void *);

void func_L03_003CFB90(u8 *a0) {
    u8 *obj = *(u8 **)(a0 + 0x68);
    void **p;
    s32 i;

    *(s32 *)(obj + 0x68) |= 0x90;
    *(f32 *)(obj + 0x30) = 0.3f;
    *(f32 *)(obj + 0x38) = 0.8f;
    *(f32 *)(obj + 0x34) = 0.3f;
    *(f32 *)(obj + 0x64) = 0.2f;
    *(f32 *)(obj + 0x3C) = 0.8f;
    *(f32 *)(obj + 0x40) = 1.4835298f;
    *(f32 *)(obj + 0x60) = 0.08726646f;
    *(f32 *)(obj + 0x5C) = 0.00392f;
    func_L01_0045BD78(a0, 0.051200002f, 0.16000001f, 0.015079645f, 0.33510324f);
    *(s32 *)(obj + 0x2CC) = 1;
    p = (void **)(obj + 0x2A0);
    i = 1;
    do {
        i--;
        func_L01_00477ED0(*p);
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L03_003CFB90 */
