/* Near miss, ported from rac4-decomp's func_L00_0051AF58 (cross-game near pair). NEAR: 16-byte save-slot frame (0x30 frame, s0/s1/ra at 0/0x10/0x20) vs ours 0x20: known unreachable blocker; also third-call branch shape (bnel) differs */
typedef struct { u8 b[64]; } Blob64;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    Blob64 f18;
} Rec;
s32 func_L39_00505120(s32, s32);

s32 func_L39_004DF158(Rec *arg0, Rec *arg1) {
    arg0->f0 = arg1->f0;
    if (func_L39_00505120(arg0->f4, arg1->f4) == 0) {
        return 0;
    }
    if (func_L39_00505120(arg0->f8, arg1->f8) == 0) {
        return 0;
    }
    if (func_L39_00505120(arg0->fC, arg1->fC) == 0) {
        return 0;
    }
    arg0->f10 = arg1->f10;
    arg0->f14 = arg1->f14;
    arg0->f18 = arg1->f18;
    return 1;
}