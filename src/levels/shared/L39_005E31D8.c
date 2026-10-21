#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005E31D8);

INCLUDE_ASM("asm/levels", func_L39_005E3618);

INCLUDE_ASM("asm/levels", func_L39_005E3A10);

/* localdecomp:start func_L39_005E3A40 */
extern u8 D_L39_002B5E70[];
void *func_L39_005E3A40(s32 i) {
    return D_L39_002B5E70 + (i << 9);
}
/* localdecomp:end func_L39_005E3A40 */

/* localdecomp:start func_L39_005E3A58 */
extern s32 func_L01_00517688(void);
extern void func_L39_005D6A78(s32, s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_005D6468(s32, s32);
extern s32 func_L01_004910C0(s32);
extern void func_L01_00353C80(s32);
void func_L39_005E3A58(void) {
    s32 p = func_L01_00517688();
    func_L39_005D6A78(p, 10);
    func_L39_0061C0E0(p, 0);
    func_L39_005D6468(p, 0);
    func_L01_00353C80(func_L01_004910C0(p));
}
/* localdecomp:end func_L39_005E3A58 */

/* localdecomp:start func_L39_005E3AB8 */
extern s32 func_L01_00517688(void);
extern s32 func_L01_0049F168(s32 a0);
extern void func_L01_00517748(s32 a0);
extern s32 func_L01_004910C0(s32 a0);
extern void func_L01_00353C80(s32 a0);
void func_L39_005E3AB8(void) {
    func_L01_00517748(func_L01_0049F168(func_L01_00517688()));
    func_L01_00353C80(func_L01_004910C0(func_L01_00517688()));
}
/* localdecomp:end func_L39_005E3AB8 */

INCLUDE_ASM("asm/levels", func_L39_005E3B00);

INCLUDE_ASM("asm/levels", func_L39_005E3C18);

INCLUDE_ASM("asm/levels", func_L39_005E3F08);

/* localdecomp:start func_L39_005E4000 */
typedef struct {
    s32 id;
    u8 pad[12];
} E_005E1A90;
extern u8 D_L39_001D8328[8];
extern E_005E1A90 D_L39_0049A0F8[];
extern s32 func_L01_00517688(void);
extern void func_L01_00516AA0(s32, s32, s32);
void func_L39_005E4000(void) {
    s32 i;
    D_L39_001D8328[func_L01_00517688()] = 1;
    for (i = 0; i < 6; i++) {
        if ((u32)(D_L39_0049A0F8[i].id - 0xD0013) < 3) {
            func_L01_00516AA0(D_L39_0049A0F8[i].id, 1, 1);
        } else {
            func_L01_00516AA0(D_L39_0049A0F8[i].id, 1, 0);
        }
    }
    func_L01_00516AA0(0xD0028, 1, 0);
}
/* localdecomp:end func_L39_005E4000 */

/* localdecomp:start func_L39_005E40A8 */
extern E_005E1A90 D_L39_0049A0F8[];
extern s32 func_L01_00517688(void);
extern void func_L01_00516AA0(s32, s32, s32);
extern u8 D_L39_001D8328[8];

typedef struct {
    s32 id;
    s32 pad[3];
} Ent5E1B38;


void func_L39_005E40A8(void) {
    s32 i;

    D_L39_001D8328[func_L01_00517688()] = 0;
    for (i = 0; i < 6; i++) {
        if ((u32)(((Ent5E1B38 *)&D_L39_0049A0F8)[i].id - 0xD0013) < 3) {
            func_L01_00516AA0(((Ent5E1B38 *)&D_L39_0049A0F8)[i].id, 1, 0);
        } else {
            func_L01_00516AA0(((Ent5E1B38 *)&D_L39_0049A0F8)[i].id, 1, 1);
        }
    }
    func_L01_00516AA0(0xD0028, 1, 1);
}
/* localdecomp:end func_L39_005E40A8 */

INCLUDE_ASM("asm/levels", func_L39_005E4150);
