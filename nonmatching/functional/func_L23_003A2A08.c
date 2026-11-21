/* functional: medium. Same calls and stores; the clear-loop control flow was restructured and the place step is a static helper. */
#include "vu0.h"
#include "structs/hero.h"
typedef struct {
    u8 pad0[0x10]; s32 i10; u8 pad14[8]; s32 i1C; f32 f20; f32 f24; s32 i28; s32 i2C;
    s32 i30; s32 i34; s32 i38; s32 i3C; u8 pad40[8]; s32 i48; s32 i4C; u8 pad50[0x14];
    s32 i64; s32 i68; u8 pad6C[4]; V4 v70; u8 pad80[0xA0 - 0x80];
    s32 iA0; s32 iA4; s32 iA8; s32 iAC; s32 iB0; u8 padB4[0x160 - 0xB4];
    s32 i160; s32 i164; s32 i168; s32 i16C; s32 i170; f32 f174;
} Vars_3A2A08;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20_pad[0x21 - 0x20]; u8 b21; u8 pad22[0x68 - 0x22]; s32 *vars;
} Mob_3A2A08;
extern u16 *D_L23_0021C0E0[];
extern s32 D_L23_001DF198;
extern s32 D_L23_001D6768;
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 4");
extern u8 *D_L23_001E001C;
extern s32 func_L23_003A9C40(s32);
extern s32 func_L23_003B1230(s32);
extern void func_L23_003B12C8(s32);
extern s32 func_L23_003BB510(s32);
extern void func_L23_003BB5A8(s32);
extern s32 func_L23_003B54A0(s32);
extern s32 func_L23_003BA5D8(s32);
extern s32 func_L23_003BB0B8(s32);
extern s32 func_L23_003B98A8(s32);
extern void func_L23_003B9940(s32);
extern void func_L23_003A38C8(u8 *);

static u16 *place_3A2A08(u16 *p, s32 i)
{
    u16 *q = D_L23_001D6764[i];
    Mob_3A2A08 *mob = (Mob_3A2A08 *)(D_L23_001DF15C + ((*p & 0x7FFF) << 8));
    u8 *src = D_L23_001E001C + ((*q & 0x7FFF) << 6);
    s16 val;

    mob->pos = *(V4 *)(src + 0x30);
    mob->vars[0] = i;
    val = *p;
    p++;
    if (val < 0) {
        p = 0;
    }
    return p;
}

void func_L23_003A2A08(u8 *self)
{
    Vars_3A2A08 *v = *(Vars_3A2A08 **)(self + 0x68);
    u16 *p21;
    u16 *p20;
    u16 *p19;
    u16 *p18;
    u16 *p;
    u8 *mob;
    s32 idx;
    s32 i;
    u16 val;

    idx = v->i48;
    if (idx >= 0 && idx <= D_L23_001DF198) {
        p21 = D_L23_0021C0E0[v->i48];
        p20 = D_L23_0021C0E0[v->i4C];
        p19 = D_L23_0021C0E0[v->i28];
        p18 = D_L23_0021C0E0[v->i2C];
        for (i = 0; i < D_L23_001D6768; i++) {
            if (func_L23_003A9C40(i)) {
                if (p21 == 0) {
                    continue;
                }
                p21 = place_3A2A08(p21, i);
            }
            if (func_L23_003B1230(i)) {
                func_L23_003B12C8(i);
            }
            if (func_L23_003BB510(i)) {
                func_L23_003BB5A8(i);
            }
            if (func_L23_003B54A0(i)) {
                if (p20 == 0) {
                    continue;
                }
                p20 = place_3A2A08(p20, i);
            } else if (func_L23_003BA5D8(i)) {
                if (p19 == 0) {
                    continue;
                }
                p19 = place_3A2A08(p19, i);
            } else if (func_L23_003BB0B8(i)) {
                if (p18 == 0) {
                    continue;
                }
                p18 = place_3A2A08(p18, i);
            }
            if (func_L23_003B98A8(i)) {
                func_L23_003B9940(i);
            }
        }
        idx = v->i48;
        p = D_L23_0021C0E0[idx];
        for (;;) {
            if ((idx & 0xFF) == 0xFF || D_L23_001DF198 < idx || p == 0) {
                break;
            }
            val = *p;
            mob = D_L23_001DF15C + ((val & 0x7FFF) << 8);
            if (mob == 0) {
                break;
            }
            mob[0x21] = 0xFF;
            idx = v->i48;
            p++;
            if ((idx & 0xFF) == 0xFF || D_L23_001DF198 < idx || p == 0) {
                break;
            }
            if ((s16)p[-1] < 0 && p != D_L23_0021C0E0[idx]) {
                break;
            }
        }
        D_L23_0021C0E0[idx] = 0;
    }
    v->i10 = 0;
    v->i30 = 0 < D_L23_001DDF9C;
    v->iA4 = -1;
    v->iA8 = -1;
    v->i160 = -1;
    v->i164 = -1;
    v->i168 = -1;
    v->i38 = 0 < D_L23_001DDFA0;
    v->i34 = 0;
    v->i3C = 0;
    v->iA0 = 0;
    v->iAC = 0;
    v->i68 = 0;
    v->i64 = 0;
    v->i1C = 0;
    qzero(&v->v70);
    v->iB0 = 0;
    v->i170 = 0;
    v->i10 = (s32)D_001A4BE0.hero_moby;
    v->i16C = -1;
    v->f174 = 1.0f;
    v->f24 = 1.0f;
    v->f20 = 1.0f;
    func_L23_003A38C8(self);
}
