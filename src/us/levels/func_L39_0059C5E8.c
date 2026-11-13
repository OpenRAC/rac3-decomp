#include "common.h"

/* NTSC-U counterpart of func_L39_0059D978 (src/levels/39_multiplayer_menu/L39_0059D8F0.c) */
/* localdecomp:start func_L39_0059C5E8 */
s32 func_L39_0059C5B0(void);
extern void func_L39_00589460(s32);
extern void func_00194760(void);
extern void func_00193680(void);
extern void func_L39_005F1248(void);
extern void func_L39_005C0918(void);
extern void func_L39_005BFDC8(void);
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
extern void func_00195428(void);
extern void func_00138748(s32);
extern u8 D_L39_00242D08[];
extern void func_00192660(void);
extern void func_00128FE0(void);
extern void func_0012D318(void *, s32, void *);

void func_L39_0059C5E8(void *a0, s32 a1, void *a2)
{
    s32 i;

    func_L39_00589460(5);
    func_00194760();
    func_00193680();
    func_L39_005F1248();
    func_L39_005C0918();
    func_L39_005BFDC8();
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
    func_00195428();
    func_00138748(5);
    ((s32 (*)(void *))func_L39_0059C5B0)(D_L39_00242D08);
    func_00192660();
    func_00128FE0();
    func_0012D318(a0, a1, a2);
}
/* localdecomp:end func_L39_0059C5E8 */
