/* US draft of func_003E47F8 (rac3-uya-decomp func_003E46B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003E47F8 */
typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern S_003DEEF0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_00381C40();
extern s32 func_003E85A8(s32, f32, f32);
s32 func_003E47F8(void) {
    s32 l[3];
    s32 pos;
    f32 den;
    f32 num;
    f32 t;
    pos = D_00142694[0] >> 5;
    l[0] = D_001A4BE0.b;
    l[1] = D_001A4BE0.a;
    if (l[0] == 0) {
        l[2] = 0;
        func_00381C40(l, l + 1, l + 2);
    }
    num = (f32)(pos - l[0]);
    den = (f32)(l[1] - l[0]);
    t = (den <= 0.0f) ? 0.0f : num / den;
    return func_003E85A8(0x90007, t * 0.1285f, 0.008f);
}
/* localdecomp:end func_003E47F8 */
