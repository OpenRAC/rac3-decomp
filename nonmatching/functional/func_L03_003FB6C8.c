/* functional: high. Hand-written asm in retail (raw bgtz word to stop ee-as padding the short loop); written as a do-while over 64-bit words: always compares at least one doubleword, n counts bytes and drops by 8 per word. Returns 1 if all compared words are equal, else 0. Not byte-matched. */
s32 func_L03_003FB6C8(long *a, long *b, s32 n) {
    do {
        if (*a != *b) {
            return 0;
        }
        a++;
        b++;
        n -= 8;
    } while (n > 0);
    return 1;
}
