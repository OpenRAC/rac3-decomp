#include "common.h"

/* declared by functions of L39_0066C808.c, which this file was cut from */
typedef struct {
    u8 pad0[52];
    u16 unk34;
} Src669F78;
typedef struct {
    u8 pad0[8];
    s32 unk8;
} Info669F78;
extern Info669F78 *func_L39_005C1018(Src669F78 *);
extern u8 *D_L39_00246330;

/* localdecomp:start func_L39_0066D348 */
extern Info669F78 *func_L39_005C1018(Src669F78 *);
extern u8 *D_L39_00246330;
typedef struct { u8 pad[0x1C]; void (*fn)(s32, s32); } V_66AA40;
typedef struct { u8 pad[0x18]; s32 x18; } A_66AA40;
extern void func_L39_0066D580(void);
void func_L39_0066D348(A_66AA40 *a, s32 b) {
    if (a == (*(A_66AA40 * *)&D_L39_00246330)) {
        func_L39_0066D580();
    } else {
        ((V_66AA40 * (*)(s32))func_L39_005C1018)(a->x18)->fn(a->x18, b);
    }
}
/* localdecomp:end func_L39_0066D348 */
