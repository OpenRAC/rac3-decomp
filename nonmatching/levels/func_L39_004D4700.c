/* Near miss, ported from rac4-decomp's func_L00_00510500 (cross-game near pair). NEAR: SIBCALL (retail ld ra; j func_L39_004D1DC8) */
extern s32 func_L00_0050DBC8(s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_L39_004D4700(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    return func_L00_0050DBC8(arg1, arg2, arg2 + 8, arg2 + 16, arg0, arg2 + 24, 1, arg7);
}
