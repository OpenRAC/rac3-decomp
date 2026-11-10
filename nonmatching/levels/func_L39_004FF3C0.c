/* func_L39_004FF3C0: body matches; only the frame differs (retail 16-byte sd slots, frame 0x40, restore order ra,s2,s1,s0)
   Size 128, 1 place (L39), src/levels/39_multiplayer_menu/L39_004FB668.c, 9 diff rows all prologue/epilogue
   twin func_002B7C80 (rac2-less port); sibling-call free */
extern void *func_L39_004BEED8(s32);
extern void func_11D534(void *, s32, s32);
extern void func_L39_004FCF88(void *);
s32 func_L39_004FF3C0(void *a0, void **a1) {
    u8 *p = func_L39_004BEED8(0x78);
    if (p != 0) {
        func_11D534(p, 0, 0x20);
        *(void **)p = a0;
        *(void **)(p + 0x10) = p + 0x20;
        func_L39_004FCF88(p + 0x20);
        *(s32 *)(p + 0x14) = 0;
        *(s32 *)(p + 0x18) = 0;
        *a1 = p;
        return 0;
    }
    return 1;
}
