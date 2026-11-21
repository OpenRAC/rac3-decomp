/* functional: high. Retail is a tail call (j) of the CRYPTO_add-style call; only the 2 trailing words of the 36-byte span (dead nop and sp adjust) differ in the check, behaviour identical. */
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern char D_L39_00477278[];

void func_L39_004E1110(s32 *a) {
    func_L39_004BECF0(a + 2, 1, 10, D_L39_00477278, 0xAE);
}
