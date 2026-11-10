#include "common.h"

/* localdecomp:start func_L39_0059D8F0 */
extern s32 func_12BF88(s32, s32, s32, void *);
extern s32 func_12C190(s32);

s32 func_L39_0059D8F0(s32 a0) {
    s32 buf[2];
    s32 r = -1;

    if (a0 >= 0) {
        r = func_12BF88(a0, 0, 0, buf);
        if (r >= 0) {
            r = func_12C190(a0);
            if (r >= 0) {
                r = 0;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_0059D8F0 */

/* localdecomp:start func_L39_0059D940 */
s32 func_0012C220();
s32 func_L39_0059D8F0(s32);

/* from rac4-decomp's func_0045F460 */
s32 func_L39_0059D940(void) {
    s32 temp_v0;
    temp_v0 = func_0012C220();
    if (temp_v0 >= 0) {
        return func_L39_0059D8F0(temp_v0);
    }
    return 0;
}
/* localdecomp:end func_L39_0059D940 */

/* localdecomp:start func_L39_0059D978 */
s32 func_L39_0059D940(void);
extern void func_L39_0058A5D0(s32);
extern void func_00194670(void);
extern void func_00193590(void);
extern void func_L39_005F3948(void);
extern void func_L39_005C2960(void);
extern void func_L39_005C1E10(void);
extern void func_001372E8(s32);
extern void func_00136E48(void);
extern void func_001331A0(s32, s32);
extern void func_0013A9D8(s32);
extern void func_00126D00(s32);
extern void func_0013C878(s32, s32);
extern void func_0013C120(s32);
extern void func_0013C4E8(void);
extern void func_0013C090(void);
extern void func_0013B838(s32, s32, s32);
extern void func_0013B188(void);
extern void func_00195338(void);
extern void func_00138748(s32);
extern u8 D_L39_00242B88[];
extern void func_00192570(void);
extern void func_00128FE0(void);
extern void func_0012D318(void *, s32, void *);

void func_L39_0059D978(void *a0, s32 a1, void *a2)
{
    s32 i;

    func_L39_0058A5D0(5);
    func_00194670();
    func_00193590();
    func_L39_005F3948();
    func_L39_005C2960();
    func_L39_005C1E10();
    func_001372E8(0);
    func_00136E48();
    func_001331A0(0, 0);
    func_0013A9D8(0);
    func_00126D00(2);
    for (i = 0; i < 8; i++) {
        func_0013C878(i >= 4, i % 4);
    }
    func_0013C120(0);
    func_0013C120(1);
    func_0013C4E8();
    func_0013C090();
    func_0013B838(0, 0, 0);
    func_0013B188();
    func_00195338();
    func_00138748(5);
    ((s32 (*)(void *))func_L39_0059D940)(D_L39_00242B88);
    func_00192570();
    func_00128FE0();
    func_0012D318(a0, a1, a2);
}
/* localdecomp:end func_L39_0059D978 */
