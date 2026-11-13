#include "common.h"

/* localdecomp:start func_L39_0061D0B8 */
typedef struct {
    u8 pad0[0x24C9];
    u8 idx;
    u8 pad24CA[0x4E];
    u8 on;
} S_61A940;

extern s32 D_L39_00241118[];
extern u8 D_L39_00245E88[8];
extern S_61A940 *func_L39_0061BF38(s32);
extern void func_L39_0058B1B8(s32, s32, s32, s32);

void func_L39_0061D0B8(void) {
    S_61A940 *p = func_L39_0061BF38(D_L39_00241118[0]);
    if (p->on) {
        if (D_L39_00245E88[p->idx] < 96) {
            D_L39_00245E88[p->idx] += 2;
        }
    } else {
        if (D_L39_00245E88[p->idx] == 0) {
            return;
        }
        D_L39_00245E88[p->idx] -= 2;
    }
    if (D_L39_00245E88[p->idx]) {
        func_L39_0058B1B8(0, 0, 0, D_L39_00245E88[p->idx]);
    }
}
/* localdecomp:end func_L39_0061D0B8 */

/* localdecomp:start func_L39_0061D150 */
extern s32 D_L39_0024D758[];
extern s32 D_L39_0024D75C_b;
extern void func_L39_0061E0C0(void);
extern void func_L39_0061D8C0(s32 a0);
extern void func_L39_0061D9D8(s32 a0);
extern void func_L39_0061DAF0(s32 a0);
extern void func_L39_0061DC08(s32 a0);
extern void func_L39_0061DD20(s32 a0);
extern void func_L39_0061DE38(s32 a0);
extern void func_L39_0061DF50(s32 a0);

void func_L39_0061D150(void) {
    D_L39_0024D75C_b = -1;
    D_L39_0024D758[0] = -1;
    func_L39_0061E0C0();
    func_L39_0061D8C0(1);
    func_L39_0061D9D8(2);
    func_L39_0061DAF0(3);
    func_L39_0061DC08(4);
    func_L39_0061DD20(5);
    func_L39_0061DE38(6);
    func_L39_0061DF50(7);
}
/* localdecomp:end func_L39_0061D150 */

/* localdecomp:start func_L39_0061D1B0 */
extern s32 D_L39_0024D75C[];
extern s32 D_L39_0024D758_b;
extern void func_L39_0061D6A8(void);
void func_L39_0061D1B0(s32 a0, s32 a1) {
    D_L39_0024D75C[0] = a0;
    D_L39_0024D758_b = a1;
    func_L39_0061D6A8();
}
/* localdecomp:end func_L39_0061D1B0 */
