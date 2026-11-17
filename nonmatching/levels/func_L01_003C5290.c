/* PAL near miss (Codex wave 8): near miss: 4 words differ with the file's flags.
 * Worker's note: 4 diff / 149 words, 10.log (6 -> 4). Loop bodies and first preheader exact; second preheader tag/size address and counter/duplicated-position initialization exchanged. Ten plain-C compiles; contract.log compiles cleanly; fixed flags, no metadata.
 */
#include "common.h"
/* localdecomp:start func_L01_003C5290 */
extern vu0_v4 D_L01_002BB2E0[];
extern s32 D_L01_001DECFC;
extern f32 D_L01_001DED00, D_L01_001DED04;
extern s32 D_L01_001DED10, D_L01_001DED14;
extern f32 D_L01_001DED18, D_L01_001DED1C;
extern f32 D_L01_001DED20;
__asm__(".extern D_L01_001DED20, 4");
extern f32 D_L01_001DEDB8;
__asm__(".extern D_L01_001DEDB8, 4");
__asm__(".extern D_L01_001DECFC, 4");
__asm__(".extern D_L01_001DED00, 4");
__asm__(".extern D_L01_001DED04, 4");
__asm__(".extern D_L01_001DED10, 4");
__asm__(".extern D_L01_001DED14, 4");
__asm__(".extern D_L01_001DED18, 4");
__asm__(".extern D_L01_001DED1C, 4");
void func_L01_003C5290(u8 *moby, u8 *vars)
{
    extern void func_L01_0044F9F8(void *, s32, s32);
    extern void func_L01_003C5CA8(void *, u8 *);
    extern void func_L01_003C5220(u8 *, u8 *);
    extern u8 *func_L01_00470150(void *, u8 *, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
    s32 i;
    vu0_v4 *at;
    f32 *size;
    u8 **a, **b, **c;
    u8 *p;
    s32 tag, tag2;
    func_L01_0044F9F8(vars + 0x170, 128, 1);
    *(u16 *)(*(u8 **)(vars + 0x40) + 0x34) |= 0x41;
    *(u16 *)(*(u8 **)(vars + 0x44) + 0x34) |= 0x41;
    *(u16 *)(*(u8 **)(vars + 0x48) + 0x34) |= 0x41;
    if (*(u8 **)(vars + 0x54)) {
        *(u16 *)(*(u8 **)(vars + 0x54) + 0x34) |= 0x41;
        func_L01_003C5CA8(moby, vars);
    }
    func_L01_003C5220(moby, vars);
    a = (u8 **)(vars + 0x58);
    b = (u8 **)(vars + 0x70);
    c = (u8 **)(vars + 0x80);
    tag = 68;
    i = 5;
    at = D_L01_002BB2E0;
    for (; i >= 0; at++, i--) {
        if (a[5-i] == 0) {
            p = func_L01_00470150(at, moby, D_L01_001DECFC, -1, 1, -1, 0, -1,
                                  D_L01_001DED00 * 210000.0f, D_L01_001DED04, 1.0f, 0, 0);
            a[5-i] = p;
            if (p) p[3] = tag;
        }
    }
    tag2 = 68;
    size = &D_L01_001DEDB8;
    i = 3;
    for (; i >= 0; size++, i--) {
        if (b[3-i] == 0) {
            p = func_L01_00470150(&((vu0_v4 *)&D_L01_001DED20)[3-i], moby, D_L01_001DED10, -1, 1, -1, 3, -1,
                                  *size * 210000.0f, D_L01_001DED18, 1.0f, 0, 0);
            b[3-i] = p;
            if (p) p[3] = tag2;
        }
        if (c[3-i] == 0) {
            p = func_L01_00470150(&((vu0_v4 *)&D_L01_001DED20)[3-i], moby, D_L01_001DED14, -1, 1, -1, 0, -1,
                                  *size * 210000.0f, D_L01_001DED1C, 1.0f, 0, 0);
            c[3-i] = p;
            if (p) p[3] = tag2;
        }
    }
}
/* localdecomp:end func_L01_003C5290 */
