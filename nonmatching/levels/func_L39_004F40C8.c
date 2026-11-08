/* Near miss, ported from rac4-decomp's func_L00_0052FEC8 (cross-game near pair). NEAR: SIBCALL: retail ends with ld ra; ld s0; j func_004BEF28 (0x20 frame) */
extern void func_L39_00506630(s32);
extern void func_L39_004FA4E8(s32);
extern void func_L39_004BEF28(void *);

void func_L39_004F40C8(void *arg0) {
    if (arg0 != 0) {
        func_L39_00506630(*(s32 *)((u8 *)arg0 + 0));
        func_L39_004FA4E8(*(s32 *)((u8 *)arg0 + 4));
        func_L39_004BEF28(arg0);
    }
}
