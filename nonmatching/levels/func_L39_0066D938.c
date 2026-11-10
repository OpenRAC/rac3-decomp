/* Near miss, ported from rac4-decomp's func_00540700 (cross-game near pair). NEAR: global base reg: ours $a2 lui after sb + beql, retail $v0 lui in beqz delay slot; 6 variants (struct/array/local/hint/early return) same */
typedef struct {
    s32 pad0;
    s32 f4;
    u8 pad8[0x2C];
    s32 f34;
    u8 pad38[0x18];
    u8 f50;
} S_66D938;
typedef struct {
    s32 pad[2];
    s32 f8;
} G_66D938;
extern s32 func_L39_0066D888(S_66D938 *, s32, s32);
extern void func_L39_0061E1B8(S_66D938 *, s32);
extern G_66D938 D_001A5CD0;

void func_L39_0066D938(S_66D938 *arg0, u8 arg1, u8 arg2) {
    if (func_L39_0066D888(arg0, arg1, arg2) != 0) {
        G_66D938 *g = &D_001A5CD0;

        arg0->f50 = arg1;
        if (arg0->f34 != g->f8) {
            arg0->f34 = g->f8;
            arg0->f4 = g->f8;
            func_L39_0061E1B8(arg0, 0);
        }
    }
}
