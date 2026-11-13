#include "common.h"

/* localdecomp:start func_L39_005A8ED8 */
typedef struct { s32 (*fn)(void); s32 arg; } E_005A8ED8;
typedef struct {
    char pad0[0x24DA0];
    void (*fnA)(void);
    char pad1[0x14];
    s32 (*fnB)(void);
    char pad2[4];
    E_005A8ED8 tblA[4];
    E_005A8ED8 tblB[3];
} S_005A8ED8;
extern s32 D_L39_0024BD18;
extern S_005A8ED8 *D_L39_00242A50;
extern void func_L39_005A8DC8(void);

void func_L39_005A8ED8(void) {
    s32 i;
    s32 r;

    if (D_L39_0024BD18 == 0 && D_L39_00242A50 != 0) {
        if (D_L39_00242A50->fnB != 0) {
            if (D_L39_00242A50->fnB() != 0) return;
        }
        r = 0;
        for (i = 0; i < 4; i++) {
            S_005A8ED8 *p = D_L39_00242A50;
            if (p->tblA[i].fn != 0) {
                r |= (&p->tblA[i])->fn();
            }
        }
        if (r != 0) return;
        for (i = 0; i < 3; i++) {
            S_005A8ED8 *p = D_L39_00242A50;
            if (p->tblB[i].fn != 0) {
                r |= (&p->tblB[i])->fn();
            }
        }
        if (r != 0) return;
        if (D_L39_00242A50 != 0) {
            D_L39_00242A50->fnA();
            func_L39_005A8DC8();
        }
    }
}
/* localdecomp:end func_L39_005A8ED8 */
