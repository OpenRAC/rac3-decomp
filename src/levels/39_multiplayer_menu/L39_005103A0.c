#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005103A0);

INCLUDE_ASM("asm/levels", func_L39_005108A0);

INCLUDE_ASM("asm/levels", func_L39_00510A78);

/* localdecomp:start func_L39_00510B58 */
extern u8 D_L39_0046F450[];

typedef struct S_00510B58_Obj S_00510B58_Obj;
typedef struct {
    s32 (*fn0)(S_00510B58_Obj *, u8 *, s32);
} S_00510B58_Vt;
struct S_00510B58_Obj {
    S_00510B58_Vt *vt;
    s32 unk4;
    s32 pad[5];
    S_00510B58_Obj *unk1C;
};

s32 func_L39_00510B58(S_00510B58_Obj *arg0) {
    if (arg0->unk4 != 1) {
        return 0;
    }
    arg0->unk4 = 0;
    arg0 = arg0->unk1C;
    return arg0->vt->fn0(arg0, D_L39_0046F450, 2);
}
/* localdecomp:end func_L39_00510B58 */

INCLUDE_ASM("asm/levels", func_L39_00510BA8);

INCLUDE_ASM("asm/levels", func_L39_00510C84);

INCLUDE_ASM("asm/levels", func_L39_00510CA0);

INCLUDE_ASM("asm/levels", func_L39_00510DB8);

INCLUDE_ASM("asm/levels", func_L39_00510EB0);

INCLUDE_ASM("asm/levels", func_L39_00510EF0);

INCLUDE_ASM("asm/levels", func_L39_00510F60);

INCLUDE_ASM("asm/levels", func_L39_00510FF0);

INCLUDE_ASM("asm/levels", func_L39_00511188);

INCLUDE_ASM("asm/levels", func_L39_00511268);

INCLUDE_ASM("asm/levels", func_L39_00511480);

INCLUDE_ASM("asm/levels", func_L39_00511540);

LINKER_REMNANT("asm/levels", func_L39_005115A0);

INCLUDE_ASM("asm/levels", func_L39_005115B8);

INCLUDE_ASM("asm/levels", func_L39_00511750);

INCLUDE_ASM("asm/levels", func_L39_00511848);

INCLUDE_ASM("asm/levels", func_L39_005119F0);

INCLUDE_ASM("asm/levels", func_L39_00511A50);

INCLUDE_ASM("asm/levels", func_L39_00511BA8);

INCLUDE_ASM("asm/levels", func_L39_00511DB0);

INCLUDE_ASM("asm/levels", func_L39_00512018);

INCLUDE_ASM("asm/levels", func_L39_005120B0);

INCLUDE_ASM("asm/levels", func_L39_00512488);

INCLUDE_ASM("asm/levels", func_L39_00512510);

INCLUDE_ASM("asm/levels", func_L39_00512620);

INCLUDE_ASM("asm/levels", func_L39_00512778);

INCLUDE_ASM("asm/levels", func_L39_005127B8);

/* localdecomp:start func_L39_005128E8 */
/* from rac4-decomp's func_00410468, renamed */
void func_L39_005128E8(s32 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
}
/* localdecomp:end func_L39_005128E8 */

INCLUDE_ASM("asm/levels", func_L39_005128F8);

INCLUDE_ASM("asm/levels", func_L39_00512948);

INCLUDE_ASM("asm/levels", func_L39_00512A40);

INCLUDE_ASM("asm/levels", func_L39_00512B20);

INCLUDE_ASM("asm/levels", func_L39_00512BA8);

INCLUDE_ASM("asm/levels", func_L39_00512CB0);

INCLUDE_ASM("asm/levels", func_L39_00512E18);

INCLUDE_ASM("asm/levels", func_L39_00512EC0);

INCLUDE_ASM("asm/levels", func_L39_00512F78);

INCLUDE_ASM("asm/levels", func_L39_00513178);

INCLUDE_ASM("asm/levels", func_L39_00513350);

INCLUDE_ASM("asm/levels", func_L39_00513470);

INCLUDE_ASM("asm/levels", func_L39_00513808);

INCLUDE_ASM("asm/levels", func_L39_00513AD8);

INCLUDE_ASM("asm/levels", func_L39_00513B90);

INCLUDE_ASM("asm/levels", func_L39_00513D50);

INCLUDE_ASM("asm/levels", func_L39_00513DF0);

INCLUDE_ASM("asm/levels", func_L39_00513FA0);

INCLUDE_ASM("asm/levels", func_L39_005141B0);

INCLUDE_ASM("asm/levels", func_L39_00514750);

INCLUDE_ASM("asm/levels", func_L39_00514868);

INCLUDE_ASM("asm/levels", func_L39_005148F8);

INCLUDE_ASM("asm/levels", func_L39_00514AA0);

INCLUDE_ASM("asm/levels", func_L39_00514BE0);

INCLUDE_ASM("asm/levels", func_L39_00514CF8);

INCLUDE_ASM("asm/levels", func_L39_00514EB8);

/* localdecomp:start func_L39_00515030 */
extern s32 func_L39_004F7538(void *, void *, s32);
typedef struct { s32 cap; s32 n; long *d; } S_00515030;

s32 func_L39_00515030(s32 arg0, S_00515030 *s) {
    long *d;
    s32 i = arg0 * 8;
    s32 n = s->n - arg0;
    s32 bytes = n * 8;

    s->n = n;
    if (n <= 0) {
        d = s->d;
        do {
            i = 1;
            s->n = i;
            *d = 0;
        } while (0);
        return 0;
    }
    d = s->d;
    func_L39_004F7538(d, (u8 *) d + i, bytes);
    return 0;
}
/* localdecomp:end func_L39_00515030 */

INCLUDE_ASM("asm/levels", func_L39_00515088);

INCLUDE_ASM("asm/levels", func_L39_00515180);

INCLUDE_ASM("asm/levels", func_L39_005151E8);

LINKER_REMNANT("asm/levels", func_L39_00515250);

INCLUDE_ASM("asm/levels", func_L39_00515258);

INCLUDE_ASM("asm/levels", func_L39_00515438);

INCLUDE_ASM("asm/levels", func_L39_005155E8);

INCLUDE_ASM("asm/levels", func_L39_005156F4);

INCLUDE_ASM("asm/levels", func_L39_00515708);

INCLUDE_ASM("asm/levels", func_L39_00515778);

INCLUDE_ASM("asm/levels", func_L39_00515A70);

/* localdecomp:start func_L39_00515BD0 */
s32 func_L39_00515BD0(void) {
    return 0x20F;
}
/* localdecomp:end func_L39_00515BD0 */

INCLUDE_ASM("asm/levels", func_L39_00515BD8);

INCLUDE_ASM("asm/levels", func_L39_00515C28);

INCLUDE_ASM("asm/levels", func_L39_00515C70);

INCLUDE_ASM("asm/levels", func_L39_00515D28);

INCLUDE_ASM("asm/levels", func_L39_00515DA8);

INCLUDE_ASM("asm/levels", func_L39_00515E00);

INCLUDE_ASM("asm/levels", func_L39_00515E18);

LINKER_REMNANT("asm/levels", func_L39_00515F30);

INCLUDE_ASM("asm/levels", func_L39_00515F38);
