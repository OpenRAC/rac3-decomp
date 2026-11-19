#include "common.h"

/* declared by functions of L39_0066C808.c, which this file was cut from */
typedef struct {
    u8 pad0[52];
    u16 unk34;
} Src669F78;
typedef struct {
    u8 pad0[24];
    Src669F78 *unk18;
    u16 unk1C;
    u8 pad1E[2];
    s32 unk20;
    u8 pad24[8];
    u8 unk2C;
} Obj669F78;
extern Obj669F78 *func_L39_0061D2D8(s32, s32, s32);
extern u8 *D_L39_00246330;

/* localdecomp:start func_L39_0066CDA0 */
extern Obj669F78 *func_L39_0061D2D8(s32, s32, s32);
extern s32 D_L39_0024D75C[];
extern u8 *D_L39_00246330;
void func_L39_0066CDA0(void) {
    u8 *v = ((u8 * (*)(s32, s32, s32))func_L39_0061D2D8)(7, D_L39_0024D75C[0], -2);
    D_L39_00246330 = v;
    v[44] = 0;
}
/* localdecomp:end func_L39_0066CDA0 */
