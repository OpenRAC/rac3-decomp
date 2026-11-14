/* Level 7 near miss: 31 differences with the owning file's plain flags, all
   from the inline float constants (retail builds them with lui/ori/mtc1, ee-as
   loads them from .lit4 through $gp). The C matches under Ps2EeAs (@ps2as), but
   L07_003C0710.c also holds func_L07_003C1DC8 as INCLUDE_ASM and that function's
   bytes change when the file is switched to Ps2EeAs, so the flag cannot be added
   without breaking the level build. Not linked; the owning file's flags are
   unchanged. No VU0 or volatile. */
typedef struct {
    u8 pad0[8];
    s32 i8;
    u8 padC[0x18];
} E_003C1360;

extern u8 D_001426E0[];
extern s32 func_L01_0041A4F0(void);

s32 func_L07_003C1360(s32 arg0) {
    f32 f;
    s32 v;

    f = (f32)((E_003C1360 *)D_L07_002BC920)[arg0].i8;
    v = D_001426E0[arg0 + 0x8E];
    if (v >= 2) {
        f *= 0.1f;
    } else if (v == 1) {
        f *= 0.33f;
    }
    if (func_L01_0041A4F0()) {
        f *= 10.0f;
    }
    return (s32)(f * 0.02f + 0.5f) * 50;
}
