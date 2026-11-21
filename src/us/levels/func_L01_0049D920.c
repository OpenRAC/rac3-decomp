#include "common.h"

/* NTSC-U counterpart of func_L01_004A1180 (src/levels/shared/L01_0049FBC8.c): 8 -> 10 */
extern s32 func_0037DF98(s32);
extern void *func_003AED40(s32);
extern s32 func_0037DF98(s32);
extern s32 func_00389D18(f32, s32, s32);
extern void func_L01_0049D920();

/* localdecomp:start func_L01_0049D920 */
typedef struct {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 enabled;
    u8 pad15[3];
} Entry_004A1180;

extern Entry_004A1180 D_L01_002ED8A0[];
extern f32 D_L01_001DC128;
extern u8 D_L01_002ED8E8[];
extern s32 D_L01_001D9690;
extern s32 D_L01_001D968C;
extern s32 D_L01_001D9688;
__asm__(".extern D_L01_001D9690, 4");
__asm__(".extern D_L01_001D968C, 4");
__asm__(".extern D_L01_001D9688, 4");

extern void func_L01_0049E448(void);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003B3DB8(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E29B8(s32, s32);
extern s32 func_003E34A0(s32, s32, s32);
extern s32 func_L01_00513548(s32, f32, f32);
extern void func_L01_0049DDD0(void *);
extern s32 func_L01_00514020(s32, s32);
extern s32 func_003E3330(s32, f32, f32);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_003E31A8(s32, s32);
extern void func_L01_0049E0B0(void);
extern void func_L01_0049E718(void);
extern s32 func_L01_00512D70(s32, s32);
extern s32 func_L01_005131A0(s32, s32);
extern s32 func_003E3250(s32, s32, s32);
extern void func_L01_0049E5B8(void);

void func_L01_0049D920(void) {
    s32 i = 0;
    s32 scaled = 0;
    s32 selected;
    f32 ratio;
    f32 scale;
    f32 resize = 0.0f;
    f32 min = 0.0f;
    f32 max = 0.49f;
    f32 low = 6.0f;
    f32 high = 11.0f;
    Entry_004A1180 *p;
    Entry_004A1180 *q;

    func_L01_0049E448();
    ratio = (f32)func_00389D18(1.2f, func_0037DF98(0x106), -1) / D_L01_001DC128;
    if (max < ratio) {
        resize = 0.588000059f / ratio;
        scaled = 1;
        ratio = max;
    }
    ratio = (ratio - min) / (max - min);
    scale = func_003BEB48(low, high, ratio);
    if (high < scale) {
        scale = high;
    } else if (scale < low) {
        scale = low;
    }
    func_003B3DB8(0x10, scale, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008,
                  func_0037DF98(0x106), 0xD0006, 0x124, 0xD0007, 0xCD5);
    func_003E3A80(0xD0009, func_0037DF98(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD0009, 1);
    func_003E3A80(0xD000A, func_0037DF98(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD000A, 1);
    func_003E34A0(0xD000B, 0xD0009, 0xD000A);
    if (scaled) {
        func_L01_00513548(0xD0005, resize, resize);
    }
    func_L01_0049DDD0(D_L01_002ED8E8);
    func_L01_00514020(0x570005, 1);
    func_003E3330(0x570005, 0.49f, 0.0f);
    func_003E2DE0(0x11, 0x570000);
    func_003E29B8(0x570006, 1);
    func_003E31A8(0x570009, (s32)func_003AED40(0));
    func_L01_0049E0B0();
    func_L01_0049E718();
    D_L01_001D9690 = -1;
    p = &D_L01_002ED8A0[i];
    if (p->id) {
        selected = -1;
        q = p;
        do {
            if (q->enabled) {
                selected = i;
            }
            q++;
            i++;
        } while (q->id && selected < 0);
        D_L01_001D9690 = selected;
    }
    if (D_L01_001D9690 < 0 && D_L01_001D968C) {
        D_L01_001D9690 = 0;
    }
    func_L01_00512D70(0x570009, 0);
    func_L01_005131A0(0x570009, 0);
    func_003E3250(0x570009, 1, 10);
    D_L01_001D9688 = -1;
    func_L01_0049E5B8();
}
/* localdecomp:end func_L01_0049D920 */
