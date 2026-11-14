#include "common.h"

/* localdecomp:start func_L10_00404678 */
typedef struct { u8 pad[0x34]; s32 frame; } S_Game;
extern S_Game D_L10_001E5F80;
typedef struct { u8 pad[0xB0]; } S_Rec;
extern S_Rec D_L10_001EE490[];
extern u8 D_L10_004043A0[];
extern void *func_L10_00403490(s32);
extern void func_L10_00404310(void *);
extern void func_L10_00404488(void *);
extern void func_L10_004043F8(void *, void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_00402498(void *, void *);

void func_L10_00404678(s32 *c) {
    void *obj;
    s32 i;

    obj = func_L10_00403490(c[0]);
    if (obj == 0) {
        return;
    }
    if (D_L10_001E5F80.frame == c[1]) {
        func_L10_00404310(obj);
    }
    if (D_L10_001E5F80.frame >= c[5] && D_L10_001E5F80.frame <= c[1]) {
        func_L10_00404488(obj);
    } else if (D_L10_001E5F80.frame >= c[3] && D_L10_001E5F80.frame <= c[6]) {
        if (func_0037E1D8(c[7]) == 0) {
            func_L10_00404488(obj);
        }
    } else if (D_L10_001E5F80.frame >= c[1] && D_L10_001E5F80.frame <= c[4]) {
        if (func_0037E1D8(c[8]) == 0) {
            func_L10_00404488(obj);
            for (i = 0; i < 3; i++) {
                func_L10_004043F8(obj, &D_L10_001EE490[i]);
                func_L01_00402498(D_L10_004043A0, 0);
            }
        }
    }
    if ((D_L10_001E5F80.frame >= c[1] && D_L10_001E5F80.frame <= c[2]) || (D_L10_001E5F80.frame >= c[3] && D_L10_001E5F80.frame <= c[4])) {
        if (func_0037E1D8(c[9]) == 0) {
            for (i = 0; i < 3; i++) {
                func_L10_004043F8(obj, &D_L10_001EE490[i]);
                func_L01_00402498(D_L10_004043A0, 0);
            }
        }
    }
}
/* localdecomp:end func_L10_00404678 */
