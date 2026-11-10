/* Near miss, ported from rac2-decomp's func_L03_00419C00 (cross-game near pair). FLAGS: retail builds 0.1f inline (lui/ori/mtc1) = needs @ps2as for src/levels/shared/L19_003553A0.c (its flags have none); also file context line 111 declares extern void func_L19_00356030(s32) which must become the 3-arg s32 prototype */
typedef struct {
    u8 pad0[0x80];
    u8 nodes[0x400];
    s32 count;
} S_356030;

extern s32 func_L19_0044A568(u8 *, u8 *, void *, u8 *, s32, s32 *, s32 *, f32, f32);

s32 func_L19_00356030(u8 *object, u8 *first, u8 *second) {
    f32 angle;
    s32 firstIndex;
    s32 secondIndex;
    S_356030 *record = *(S_356030 **)(object + 0x68);
    firstIndex = -1;
    secondIndex = -1;
    return func_L19_0044A568(first, second, &angle, record->nodes, record->count, &firstIndex, &secondIndex, 0.0f, 0.1f);
}
