/* Near miss, ported from rac2-decomp's func_003169D0 (cross-game near pair). FLAGS: needs @ps2as for inline lui/ori/mtc1 float constants (default as puts them in .lit4 via $gp); struct array Ent[3] stride 0xA0, key at 0x8C, flag at 0x94, obj at 0x30. Same shape as other @ps2as files in text_parts */
typedef struct {
    u8 pad0[0x30];
    u8 obj[0x5C];
    s32 key;
    u8 pad8[4];
    s32 flag;
    u8 pad9[8];
} Ent_0033DED0;

extern Ent_0033DED0 D_L01_00278BC0[];
extern void func_L01_0033E0C8(s32 a, Ent_0033DED0 *b);
extern void func_003D9508(void *o, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14);
extern f32 func_003824E0(f32 a, f32 b);

void func_L01_0033DED0(s32 arg0) {
    s32 i;
    for (i = 0; i < 3; i++) {
        Ent_0033DED0 *e = &D_L01_00278BC0[i];
        if (e->key == arg0) {
            func_L01_0033E0C8(arg0, e);
            if (e->flag == 0) {
                func_003D9508(e->obj, 0x31, 0x3F007F00, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, 0.0f);
                func_003D9508(e->obj, 0x31, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, 0.0f);
                func_003D9508(e->obj, 0xB, 0x10003F00, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
            }
        }
    }
}
