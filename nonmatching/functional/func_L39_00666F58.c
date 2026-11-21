/* functional: medium. Retail stores whatever $3 held on entry into a0->0x14 (an uninitialised leftover register, the stub's value is unspecified) then returns 0; C stores an uninitialised local the same way, the value is never defined by retail either. */
s32 func_L39_00666F58(u8 *a0) {
    s32 unused;
    *(s32 *)(a0 + 0x14) = unused;
    return 0;
}
