/* Ported from rac4-decomp's func_L00_0071B9B0 (a twin of this function's code), names renamed from retail's
   relocations; 2 instruction(s) still differ under this file's flags. */
typedef struct {
    s32 pad0;
    s32 unk4;
} Type1;
typedef struct {
    u8 pad0[0xB0];
    Type1 *unkB0[(0x230 - 0xB0) / 4];
    s32 unk230;
} Type0;
s32 func_L39_0068B178(Type0 *);
s32 func_L39_0068B1E0(Type0 *, s32);
s32 func_L39_0068B2F8(Type0 *, s32, s32);

s32 func_L39_0068B3C0(Type0 *arg0) {
    s32 temp_s1;
    s32 temp_v1;
    s32 var_v0;
    temp_s1 = arg0->unk230;
    if (temp_s1 == -1) {
        var_v0 = func_L39_0068B178(arg0);
        goto block_4;
    }
    temp_v1 = arg0->unkB0[temp_s1]->unk4;
    if (temp_v1 < 3) {
        var_v0 = func_L39_0068B1E0(arg0, -1);
block_4:
        func_L39_0068B2F8(arg0, var_v0, 0);
        return temp_s1;
    }
    if (temp_v1 < 4) func_L39_0068B2F8(arg0, temp_s1, 0);
    return temp_s1;
}