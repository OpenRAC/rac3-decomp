#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

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
