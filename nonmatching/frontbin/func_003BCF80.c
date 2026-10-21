/* Near miss of func_003BCF80 with its file's own flags: tools/check.py reports 41 diff
   (the version it replaces: 43).
*/

/* Candidate for func_003BCF80 (PAL frontbin).
   Retail materialises every address in one register (lui $vX, %hi; lw $vX, %lo($vX)),
   which is the form gcc emits for a literal address, and keeps the high half of
   D_1CCFD0 in a 64-bit register (daddu $s0, $v0, $0), which is the form gcc
   emits for a 64-bit (unsigned long) address. */

extern u8 D_001D5571;
s32 func_003A7618_003BCF80(s32);                         /* extern */
extern s32 D_001D9D04;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B7AA0_003B7AA0;

void func_003BCF80(void) {
    if (*(s32 *)0x1D9D04 == 1) {
        if (*(u8 *)0x1D5571 == 0) {
            ((S_001CCFD0_003B7AA0_003B7AA0 *)(unsigned long)0x1CCFD0)->f7 = 0;
            if ((func_003A7618_003BCF80(1) == 0) && (func_003A7618_003BCF80(2) == 0) && (func_003A7618_003BCF80(3) == 0) && (func_003A7618_003BCF80(4) == 0) && (func_003A7618_003BCF80(5) == 0)) {
                func_003A7618_003BCF80(6);
            }
            ((S_001CCFD0_003B7AA0_003B7AA0 *)(unsigned long)0x1CCFD0)->f7 = 1;
        }
    }
}
