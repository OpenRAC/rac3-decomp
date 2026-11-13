#include "common.h"

/* localdecomp:start func_L31_003AA030 */
typedef struct {
    f32 f00;
    s32 f04;
    s32 f08;
    f32 f0C;
    s32 f10;
    s32 f14;
} State_3AA030;

typedef struct {
    u8 pad_0[0xD0];
    u8 flag;
    u8 pad_D1[0xB];
    u8 *owner;
} Slot_3AA030;

extern u8 D_001A30B0[];

extern f32 func_00389380(f32, f32);
extern f32 func_00389410(f32);
extern s32 func_00388398(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_L03_0034A588(s32, s32, f32);
extern f32 func_L05_0043DD10(f32, f32, f32);

void func_L31_003AA030(u8 *obj) {
    State_3AA030 *s = *(State_3AA030 **)(obj + 0x68);
    s32 h;
    s32 h2;
    s32 h4;
    Slot_3AA030 *e;

    switch (obj[0x20]) {
    case 0:
        s->f00 = s->f00 * 3.1415927f / 180.0f;
        s->f0C = *(f32 *)(obj + 0xF4);
        s->f00 = func_00389380(s->f00, s->f0C);
        s->f10 = -1;
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if (func_L01_00452EC8(obj) != 0) {
            h = s->f10;
            if (h != -1 && (e = (Slot_3AA030 *)(D_001A30B0 + (h << 7)))->owner == obj && e->flag != 0) {
                func_0039FB08(h);
            }
            s->f10 = -1;
            *(f32 *)(obj + 0xF4) = s->f0C;
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
        }
        if (func_L01_00452F60(obj) != 0) {
            func_L01_00441FB8(obj, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(obj) != 0) {
            s->f08 = s->f04;
            if (s->f14 == 0) {
                *(s32 *)(obj + 0x98) = 0;
            }
        }
        h2 = s->f10;
        if (h2 == -1 || (e = (Slot_3AA030 *)(D_001A30B0 + (h2 << 7)))->owner != obj || e->flag == 0) {
            s->f10 = func_0039FE80(0, 4, obj);
        }
        *(f32 *)(obj + 0xF4) = func_L05_0043DD10(s->f0C, s->f00, func_L03_0034A588(s->f08, s->f04, 0.0f));
        if (func_00388398(&s->f08) != 0) {
            func_L01_00441FB8(obj, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(obj) != 0) {
            h = s->f10;
            if (h != -1 && (e = (Slot_3AA030 *)(D_001A30B0 + (h << 7)))->owner == obj && e->flag != 0) {
                func_0039FB08(h);
            }
            s->f10 = -1;
            *(f32 *)(obj + 0xF4) = s->f00;
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
        }
        if (func_L01_00452F60(obj) == 0) {
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(obj) != 0) {
            s->f08 = s->f04;
            if (s->f14 == 0) {
                *(s32 *)(obj + 0x98) = 0;
            }
        }
        h4 = s->f10;
        if (h4 == -1 || (e = (Slot_3AA030 *)(D_001A30B0 + (h4 << 7)))->owner != obj || e->flag == 0) {
            s->f10 = func_0039FE80(0, 4, obj);
        }
        *(f32 *)(obj + 0xF4) = func_00389410(s->f00 * (1.0f - func_L03_0034A588(s->f08, s->f04, 0.0f)));
        if (func_00388398(&s->f08) != 0) {
            func_L01_00441FB8(obj, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L31_003AA030 */
