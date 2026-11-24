#include "common.h"

typedef struct Obj_4917A0 Obj_4917A0;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_4917A0 *);
} Vt_4917A0;
struct Obj_4917A0 {
    s32 pad;
    Vt_4917A0 *vt;
};

/* localdecomp:start func_L01_00494F98 */
extern s32 D_L01_001D8F90;
extern void func_L01_00517918(s32);
extern Obj_4917A0 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);
void func_L01_00494F98(void) {
    Obj_4917A0 *o;
    func_L01_00517918(13);
    func_L01_00517918(14);
    func_L01_00517918(20);
    o = func_003B42F8(0);
    o->vt->fn(o);
    func_003A2750(1);
    func_003BB468(D_L01_001D8F90);
}
/* localdecomp:end func_L01_00494F98 */

/* localdecomp:start func_L01_00494FF0 */
extern void func_L01_0047E4B8_00494FF0();

void func_L01_00494FF0(void) {
    func_L01_0047E4B8_00494FF0();
}
/* localdecomp:end func_L01_00494FF0 */

/* localdecomp:start func_L01_00495010 */
extern void func_L01_0047E520_00495010();

void func_L01_00495010(void) {
    func_L01_0047E520_00495010();
}
/* localdecomp:end func_L01_00495010 */

/* localdecomp:start func_L01_00495030 */
extern s32 func_L01_00495030(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0B28;
extern s32 D_L01_001E0B10[2];
extern void func_L01_004948E8();
extern void func_L01_00494F98();
extern void func_L01_00494DC8();
extern void func_L01_00494FF0_00495030(void);
extern void func_L01_00495010_00495030();
s32 func_L01_00495030(void) {
    if (D_L01_001E0B28 == 0) {
        func_003E6FA0(D_L01_001E0B10, (s32)func_L01_004948E8, (s32)func_L01_00494F98, (s32)func_L01_00494DC8, (s32)func_L01_00494FF0_00495030, (s32)func_L01_00495010_00495030);
        D_L01_001E0B28 = 1;
    }
    return (s32)D_L01_001E0B10;
}
/* localdecomp:end func_L01_00495030 */

INCLUDE_ASM("asm/levels", func_L01_00495088);
