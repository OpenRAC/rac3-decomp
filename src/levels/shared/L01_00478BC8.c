#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00478BC8);

/* localdecomp:start func_L01_00478BD0 */
typedef struct { u8 pad0[8]; void **f8; u8 padC[0x14]; f32 f20; f32 f24; } O_478BD0;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_478BD0;
__asm__(".extern D_L01_001D8058_00478BD0, 1");
__asm__(".extern D_L01_001D8060, 4");
__asm__(".extern D_L01_001DC1E0_00478BD0, 4");
__asm__(".extern D_L01_001DC1B0_00478BD0, 4");
extern u8 D_L01_001D8058_00478BD0;
extern f32 D_L01_001D8060;
extern s32 D_L01_001DC1E0_00478BD0;
extern s32 D_L01_001DC1B0_00478BD0;
extern u8 D_L01_001E0370_00478BD0[1];
extern u8 D_L01_001E0388_00478BD0[1];
extern u8 D_L01_001E03A0[1];
extern u8 D_L01_001E03B8_00478BD0[1];
extern S_478BD0 D_L01_001E15E0_00478BD0;
extern void func_L01_00516468_00478BD0(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003B5060(s32);
extern void func_003E5090(s32);
extern void func_003E5360(s32);
extern void func_003E51F8(s32);
extern void func_003E8898(s32, f32, f32);
extern void func_L01_00518010(s32, s32);
extern s32 func_00392A18(void);
extern void func_L01_00517448(s32, s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00516FD8(s32, void *);
extern void func_L01_00516B90(s32, s32, s32);
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void func_003EDAD0(void *, s32, s32);
extern void func_L01_00517190(s32, s32);
extern s32 func_003E8630(s32, s32);
extern void func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8348(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_003E6FF0(s32, s32);
extern void func_L01_004796B8(void);

void func_L01_00478BD0(s32 arg0) {
    O_478BD0 *p;
    O_478BD0 *r;
    void *q;

    D_L01_001D8058_00478BD0 = 1;
    func_L01_00516468_00478BD0(1);
    func_0038CB78(D_L01_001E0370_00478BD0, 0, 0x18);
    func_0038CB78(D_L01_001E0370_00478BD0, 0, 0x30);
    func_0038CB78(D_L01_001E0370_00478BD0, 0, 8);
    func_003B5060(0x10000);
    func_003E5090(0x10001);
    func_003E5090(0x10002);
    func_003E5360(0x10003);
    func_003E8898(0x10003, 0.209999993f, 0.899999976f);
    func_L01_00518010(0x10003, 1);
    func_003E5360(0x10005);
    func_003E5360(0x10006);
    func_003E51F8(0x10004);
    func_L01_00517448(0x10002, func_00392A18(), 0x23);
    func_L01_00517448(0x10001, func_00392A18(), 0x24);
    func_L01_005170B8(0x10002, 0x332299DE);
    func_L01_005170B8(0x10001, 0x331465B7);
    func_L01_00516470(0x10003, 0.884998024f, 0.0599999987f);
    func_L01_00516470(0x10004, 0.927497029f, 0.0866660029f);
    func_L01_00516470(0x10005, 0.868999004f, 0.118500002f);
    func_L01_00516470(0x10006, 0.868999004f, 0.148499995f);
    func_L01_00517538(0x10003, 0.949999988f, 0.949999988f);
    func_L01_00517538(0x10005, 0.8f, 1.0f);
    func_L01_00517538(0x10006, 0.8f, 1.0f);
    func_L01_00517538(0x10004, 0.0577499978f, 0.0710769221f);
    func_L01_005170B8(0x10003, 0x7075D5FF);
    func_L01_005170B8(0x10005, 0x7075D5FF);
    func_L01_005170B8(0x10006, 0x7075D5FF);
    func_L01_005170B8(0x10004, 0x706EC8FF);
    func_L01_00516FD8(0x10003, D_L01_001E0370_00478BD0);
    func_L01_00516B90(0x10003, 2, 1);
    func_L01_00516FD8(0x10005, D_L01_001E0388_00478BD0);
    func_L01_00516B90(0x10005, 2, 1);
    func_L01_00516FD8(0x10006, D_L01_001E03A0);
    func_L01_00516B90(0x10006, 2, 1);
    if (D_L01_001E15E0_00478BD0.f4 != 0) { q = &D_L01_001E15E0_00478BD0; } else { q = func_003E6C08(); }
    p = (O_478BD0 *)func_003E6378(func_003E6DE8(q), 0x10003);
    if ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_L01_001DC1E0_00478BD0) == 0)) { p = 0; }
    func_003EDAD0(p, 0x40, 1);
    p->f20 = 0.00499999989f;
    p->f24 = 0.00499999989f;
    if (D_L01_001E15E0_00478BD0.f4 != 0) { q = &D_L01_001E15E0_00478BD0; } else { q = func_003E6C08(); }
    p = (O_478BD0 *)func_003E6378(func_003E6DE8(q), 0x10005);
    if ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_L01_001DC1E0_00478BD0) == 0)) { p = 0; }
    func_003EDAD0(p, 0x40, 1);
    p->f20 = 0.00499999989f;
    p->f24 = 0.00499999989f;
    if (D_L01_001E15E0_00478BD0.f4 != 0) { q = &D_L01_001E15E0_00478BD0; } else { q = func_003E6C08(); }
    p = (O_478BD0 *)func_003E6378(func_003E6DE8(q), 0x10006);
    if ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_L01_001DC1E0_00478BD0) == 0)) { p = 0; }
    func_003EDAD0(p, 0x40, 1);
    p->f20 = 0.00499999989f;
    p->f24 = 0.00499999989f;
    func_L01_00517190(0x10004, 0xED26);
    if (D_L01_001E15E0_00478BD0.f4 != 0) { q = &D_L01_001E15E0_00478BD0; } else { q = func_003E6C08(); }
    p = (O_478BD0 *)func_003E6378(func_003E6DE8(q), 0x10004);
    r = ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_L01_001DC1B0_00478BD0) == 0)) ? 0 : p;
    *(u16 *)((u8 *)r + 0x4A) = 0;
    func_003E8630(0x10000, 0x10001);
    func_003E8630(0x10000, 0x10002);
    func_003E8630(0x10000, 0x10003);
    func_003E8630(0x10000, 0x10005);
    func_003E8630(0x10000, 0x10006);
    func_003E8630(0x10000, 0x10004);
    func_003E90B8(0x10007, (s32)D_L01_001E03B8_00478BD0, 0x7075D5FF, 0.925000012f, 0.150000006f, D_L01_001D8060, D_L01_001D8060, 0.00499999989f, 0.00499999989f);
    func_003E8630(0x10000, 0x10007);
    func_003E8348(5, 0x10000);
    func_L01_00516AA0(0x10000, 1, 0);
    func_003E6FF0(arg0, 1);
    func_L01_004796B8();
    func_L01_00516468_00478BD0(0);
}
/* localdecomp:end func_L01_00478BD0 */

/* localdecomp:start func_L01_00479200 */
__asm__(".extern D_L01_001D8058, 1");
extern u8 D_L01_001D8058;
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00479578(s32);
extern s32 func_L01_00516010(s32);
s32 func_L01_00479200(void) {
    if (D_L01_001D8058 != 0) {
        func_L01_00516AA0(0x10000, 1, 0);
        return func_L01_00516010(func_L01_00479578(0));
    }
    return 0;
}
/* localdecomp:end func_L01_00479200 */

/* localdecomp:start func_L01_00479248 */
__asm__(".extern D_L01_001D8058, 1");
extern u8 D_L01_001D8058;
extern void func_L01_00516AA0(s32, s32, s32);
s32 func_L01_00479248(void) {
    if (D_L01_001D8058 != 0) {
        func_L01_00516AA0(0x10000, 1, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00479248 */

/* localdecomp:start func_L01_00479280 */
extern s32 func_L01_00479578_00479280(s32);
extern void func_L01_00516050(s32);
void func_L01_00479280(void) {
    func_L01_00516050(func_L01_00479578_00479280(0));
}
/* localdecomp:end func_L01_00479280 */
