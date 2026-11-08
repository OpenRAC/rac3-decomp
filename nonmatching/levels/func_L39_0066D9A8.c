/* Near miss, ported from rac4-decomp's func_00540770 (cross-game near pair). NEAR: global is a scalar s32 (not array) w/ size hint 16 gives lui/lw; remaining: retail fills beqz delay slot with hoisted lui and shares epilogue, ours uses beql+duplicated ld; early-return and nested forms both tried */
__asm__(".extern D_001A5CD8, 16");
extern s32 D_001A5CD8;
extern s32 func_L39_0066D888(void *, s32, s32);
extern void func_L39_0061E278(void *);

void func_L39_0066D9A8(u8 *object, s32 value_in, s32 param) {
    s32 value = value_in & 0xFF;
    if (func_L39_0066D888(object, value, param & 0xFF) == 0) {
        return;
    }
    object[0x50] = value;
    if (*(s32 *)(object + 0x34) == D_001A5CD8) {
        func_L39_0061E278(object);
    }
    *(s32 *)(object + 0x34) = -1;
    *(s32 *)(object + 4) = -1;
}
