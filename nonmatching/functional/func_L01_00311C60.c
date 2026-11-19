/* functional: high. Same GS register writes and rectangle call as retail; the 64-bit OR with 0x100000000 is in the first call only. */
typedef struct {
    u8 pad0[0x24];
    s32 w24;
} Vars_311C60;
typedef struct {
    u8 pad0[0x68];
    Vars_311C60 *vars;
} Obj_311C60;
typedef struct {
    u8 pad0[8];
    s32 w8;
} G_1ED0_311C60;
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} G_FEC0_311C60;
extern G_1ED0_311C60 D_001A1ED0;
extern G_FEC0_311C60 D_001CFEC0;
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);

void func_L01_00311C60(S_311A18 *o) {
    Vars_311C60 *vars = ((Obj_311C60 *)o)->vars;
    if (vars->w24 != 0) {
        func_003A9440(0x4E, (long)((D_001A1ED0.w8 >> 13) | 0x1000000) | 0x100000000L);
        func_0038AF30(0, D_001CFEC0.h152, 0, D_001CFEC0.h150, (vars->w24 << 24) | 0xFFFFFF);
        func_003A9440(0x4E, (D_001A1ED0.w8 >> 13) | 0x1000000);
    }
}
