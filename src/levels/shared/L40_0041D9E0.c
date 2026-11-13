#include "common.h"

/* localdecomp:start func_L40_0041D9E0 */
s32 func_L40_0041D9E0(u8 *a0, u8 **a1, s32 *a2) {
    u8 *p = *(u8 **)(a0 + 104);
    *a2 = 8;
    *a1 = p + 32;
    return 0;
}
/* localdecomp:end func_L40_0041D9E0 */

/* localdecomp:start func_L40_0041DA00 */
extern s32 D_L40_00249840;
__asm__(".extern D_L40_00249840, 16");
extern s32 D_L40_00249844;
__asm__(".extern D_L40_00249844, 16");
extern u8 *D_L40_00241640;
__asm__(".extern D_L40_00241640, 16");
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 16");
extern u16 *D_L40_0028EA20[];
typedef struct { u8 pad[0x60]; s32 a60[8]; } T_0041DA00;
typedef struct { u8 pad[0x20C]; T_0041DA00 *p20C; } S_0041DA00;
extern S_0041DA00 D_L40_00357260;
extern u8 *D_L40_0024845C_0041DA00;
extern s32 D_L40_00248498;
typedef struct { u8 pad0[0x20]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; u8 f40[1]; } V_0041DA00;
extern void func_L40_004897A8(void *, s32);
extern void func_003C2880(void *);
extern void func_L40_0041D4B8(void *, s32, s32);
extern s32 func_L39_0066C828(void *, s32, s32);
extern void func_L40_0041DC00(void *, s32);
extern void func_L40_00489BC0(void *, void *, s32);

void func_L40_0041DA00(u8 *moby) {
    V_0041DA00 *v;
    u16 *p;
    u8 *q;
    s32 i;

    v = *(V_0041DA00 **)(moby + 0x68);
    if (moby[0x20] == 0) {
        D_L40_00249840 = 0;
        D_L40_00249844 = 0;
        if (((s8 *)D_L40_00241640)[0x18F] == 0) {
            func_L40_004897A8(moby, -1);
            if (v->f3C >= 0) {
                func_003C2880(D_L40_0024845C_0041DA00 + (v->f3C << 8));
            }
            p = D_L40_0028EA20[v->f34];
            while ((v->f34 & 0xFF) != 0xFF && v->f34 <= D_L40_00248498 && p != 0
                   && ((s16)p[-1] >= 0 || p == D_L40_0028EA20[v->f34])) {
                q = D_L40_0024845C + ((*p & 0x7FFF) << 8);
                if (q == 0) {
                    break;
                }
                func_003C2880(q);
                p++;
            }
            func_L40_0041D4B8(moby, -1, 1);
            func_003C2880(moby);
            return;
        }
        func_L39_0066C828(moby, -1, 1);
        v->f2C = -1;
        v->f20 = 0;
        v->f24 = 0;
        for (i = 0; i < 8; i++) {
            if (D_L40_0024845C + (D_L40_00357260.p20C->a60[i] << 8) == moby) {
                v->f2C = i;
                break;
            }
        }
        moby[0x20] = 1;
        v->f30 = 0x80FFFFFF;
    }
    func_L40_0041DC00(moby, 0);
    func_L40_00489BC0(moby, v->f40, -1);
}
/* localdecomp:end func_L40_0041DA00 */
