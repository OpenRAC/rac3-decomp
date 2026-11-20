#include "common.h"

/* NTSC-U version of func_003BEF00 (frontbin): 12 -> 15; 12 -> 15 */
#include "common.h"





extern u8 D_U_001DA354_003BEF00;
extern s32 D_U_001DA350;
extern s32 D_U_001D8D58;
extern s32 D_U_001D8D70;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_U_00225780_003BEF00;
extern void func_U_003B7288();
extern s32 func_U_003B8A18();
extern s32 func_U_003B8A20();
extern void func_U_003B8C70();
extern void func_U_003B6488();
extern s32 func_U_003B8840();
extern void func_U_003B8968();
extern void func_U_003B8E10();
extern void func_U_003B8A48();
extern void func_U_00383848();
extern void func_U_003B8A68();
/* localdecomp:start func_U_003B9A08 */
__asm__(".extern D_U_001D8D70, 4");
extern void func_U_003B9030();
void func_U_003B9A08(s32 a0) {
    s32 v;
    if (D_U_001DA354_003BEF00 != 0) {
        func_U_003B7288();
        if (func_U_003B8A18() == 1) {
            func_U_003B8C70();
        }
        if (func_U_003B8A18() > 0 && func_U_003B8A20() != 0) {
            func_U_003B6488();
        }
        if ((&D_U_001DA354_003BEF00)[0x2C] == 0) {
            v = 0;
            if (func_U_003B8A18() > 0 && a0 != 0) {
                switch (D_U_001DA350) {
                case 0:
                    v = D_U_001D8D58;
                    break;
                case 1:
                    v = D_U_001D8D70;
                    break;
                }
                (&D_U_001DA354_003BEF00)[0x2C] = 1;
            } else {
                v = func_U_003B8840();
            }
            func_U_003B8968(v);
            func_U_003B8E10(func_U_003B9030);
            func_U_003B8A48();
            func_U_00383848();
        }
    }
    func_U_003B8A68(D_U_00225780_003BEF00.f34, D_U_00225780_003BEF00.h40, 0xF, 0xF);
}
/* localdecomp:end func_U_003B9A08 */
