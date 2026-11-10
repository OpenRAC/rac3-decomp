/* Near miss, ported from rac4-decomp's func_L00_00536038 (cross-game near pair). NEAR: SQ_RA 0x20 frame (ra at 0x10) plus state in $v1/beql shape; C gives 0x10 frame */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    long f18;
} S_4FA228;

extern s32 func_L39_0050A5A0(S_4FA228 *, long);

s32 func_L39_004FA228(S_4FA228 *o) {
    s32 state;
    if (o->fC == 0x21 && o->f4 == 0 && func_L39_0050A5A0(o, o->f18) == 0) {
        state = 9;
    } else {
        if (o->f18 == 0) {
            return 1;
        }
        if ((o->fC & 1) && o->f18 >= 0) {
            return 1;
        }
        state = 8;
    }
    o->f8 = state;
    return 0;
}
