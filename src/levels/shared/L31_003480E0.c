#include "common.h"

INCLUDE_ASM("asm/levels", func_L31_003480E0);

INCLUDE_ASM("asm/levels", func_L31_00348BD8);

INCLUDE_ASM("asm/levels", func_L31_00348EE8);

INCLUDE_ASM("asm/levels", func_L31_00348FE8);

INCLUDE_ASM("asm/levels", func_L31_00349270);

/* localdecomp:start func_L31_00349350 */
extern f32 D_L31_001DD018;

s32 func_L31_00349350(void *arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 1;
    if (!((*(f32 *)((u8 *)arg1 + 8)) < ((*(f32 *)((u8 *)arg0 + 0x18)) + D_L31_001DD018))) {
        var_v0 = 0;
    }
    return var_v0;
}
/* localdecomp:end func_L31_00349350 */

INCLUDE_ASM("asm/levels", func_L31_00349380);

INCLUDE_ASM("asm/levels", func_L31_003494B0);

INCLUDE_ASM("asm/levels", func_L31_00349560);

INCLUDE_ASM("asm/levels", func_L31_003496E8);

/* localdecomp:start func_L31_00349830 */
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);
void func_L31_00349830(s32 a0) {
    func_L30_0034CB68(a0, D_L31_001D66B0, 1, -1, 0, 0, D_L31_001DD09C, D_L31_001DD0A0);
}
/* localdecomp:end func_L31_00349830 */

INCLUDE_ASM("asm/levels", func_L31_00349868);

INCLUDE_ASM("asm/levels", func_L31_003498F8);

INCLUDE_ASM("asm/levels", func_L31_00349A18);

INCLUDE_ASM("asm/levels", func_L31_00349D18);

/* localdecomp:start func_L31_00349DD0 */
typedef struct {
    u8 pad[0x4C];
    f32 hist[16];
} Hist_003491F0;

typedef struct {
    u8 pad[0x68];
    Hist_003491F0 *w68;
} Moby_003491F0;

extern s32 D_L31_001DD0B0;

void func_L31_00349DD0(Moby_003491F0 *m, f32 value) {
    Hist_003491F0 *h;
    s32 i;
    h = m->w68;
    for (i = D_L31_001DD0B0 - 1; i >= 0; i--) {
        h->hist[i + 1] = h->hist[i];
    }
    h->hist[1] = value;
}
/* localdecomp:end func_L31_00349DD0 */

INCLUDE_ASM("asm/levels", func_L31_00349E10);

INCLUDE_ASM("asm/levels", func_L31_0034A0F8);

INCLUDE_ASM("asm/levels", func_L31_0034A638);

INCLUDE_ASM("asm/levels", func_L31_0034A740);

/* localdecomp:start func_L31_0034A968 */
typedef struct {
    f32 unk0;
    s16 unk4;
    char pad6[0x10 - 0x6];
    f32 unk10;
    char pad14[0x50 - 0x14];
    char unk50[0x70 - 0x50];
    s32 unk70;
    char pad74[0x80 - 0x74];
    s32 unk80;
    char pad84[0x90 - 0x84];
    f32 unk90;
    f32 unk94;
    f32 unk98;
} Vars;

typedef struct {
    char pad0[0x24];
    f32 unk24;
} Class;

typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x2C - 0x28];
    f32 scale;
    char pad30[0x68 - 0x30];
    Vars *vars;
} Moby;

extern f32 D_L31_001DD170;
extern f32 D_L31_001DD190;
extern f32 D_L31_001DD194;
extern void func_L31_00346998(Moby *, void *);

void func_L31_0034A968(Moby *m) {
    Vars *v = m->vars;

    if (v->unk10 <= 0.0f) {
        v->unk10 = D_L31_001DD170 * m->scale / m->cls->unk24;
    }
    v->unk0 = v->unk4;
    func_L31_00346998(m, v->unk50);
    v->unk70 = 1;
    if (v->unk90 <= 0.0f) {
        v->unk90 = D_L31_001DD190;
    }
    if (v->unk94 <= 0.0f) {
        v->unk94 = D_L31_001DD194;
    }
    v->unk98 = 0.0f;
    v->unk80 = 0;
}
/* localdecomp:end func_L31_0034A968 */

INCLUDE_ASM("asm/levels", func_L31_0034AA20);

INCLUDE_ASM("asm/levels", func_L31_0034ABB8);

INCLUDE_ASM("asm/levels", func_L31_0034ACA8);

INCLUDE_ASM("asm/levels", func_L31_0034ADF0);

INCLUDE_ASM("asm/levels", func_L31_0034AFD8);

INCLUDE_ASM("asm/levels", func_L31_0034B580);

INCLUDE_ASM("asm/levels", func_L31_0034B688);

INCLUDE_ASM("asm/levels", func_L31_0034B700);

INCLUDE_ASM("asm/levels", func_L31_0034B850);

INCLUDE_ASM("asm/levels", func_L31_0034BA10);

INCLUDE_ASM("asm/levels", func_L31_0034BB58);

INCLUDE_ASM("asm/levels", func_L31_0034BCA8);

INCLUDE_ASM("asm/levels", func_L31_0034BF90);

INCLUDE_ASM("asm/levels", func_L31_0034C5A0);

INCLUDE_ASM("asm/levels", func_L31_0034CA18);

INCLUDE_ASM("asm/levels", func_L31_0034CB80);

INCLUDE_ASM("asm/levels", func_L31_0034CC30);

INCLUDE_ASM("asm/levels", func_L31_0034CD18);
