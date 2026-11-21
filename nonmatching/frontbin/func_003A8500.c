/* func_003A8500 (frontbin): new C from the assembly (FE-1, 2026-11-21). Near miss: 62 differences
   with its file's flags (src/frontbin/3A8308.c, @ps2as), 54 with -mno-split-addresses.

   It binds the SIF RPC client at D_001D4B08 to server 0x11 (func_00122630; a negative result hangs),
   polls func_00122A10 until it is free, retries after a 0xFFFF-count delay while the client's word
   at +0x24 is 0, then calls function 2 for three words and clears the 64 16-byte entries of
   D_0022DF20. Compiled code, not hand-written: SN's short-loop padding, ordinary calls, no VU0.
   Its jr delay slot (addiu $sp) is the 4-byte LINKER_REMNANT func_003A8628, which goes when this
   becomes C (config/inventory.tsv sizes the function 300 bytes with it). Its boot_elf twin
   func_003A8900 (src/boot_elf/text/3A8708.c) is a 300-byte LINKER_REMNANT, though it is the same code.

   What differs: retail stores D_001D4B00/04/30/34/38 through $at (the assembler's macro expansion), so the
   function was built -mno-split-addresses, which its file is not (a file of its own, cut at 0x003A8500 and
   0x003A8630, would be needed). Retail also rebuilds &D_001D4B08 (lui/addiu) at each of its four uses and
   saves only $ra in a 0x30 frame. gcc keeps it in $s0 in every form tried (for(;;)/break, goto retry,
   while(i--) and do/while(i-- != 0) delays, a u8[] or a struct with the +0x24 field, both address
   modes). Retail's delay loop compares the decremented counter with -1 (bne $a2, $v0=-1), where these
   forms test the old value (move $v0, $a1; bnez). */

typedef struct { s32 a; s32 b; u8 pad8[8]; } E_3A8500;
typedef struct { u8 pad0[0x24]; s32 serve; } Cd_3A8500;
extern Cd_3A8500 D_001D4B08;
extern s32 D_001D4B00;
extern s32 D_001D4B04;
extern s32 D_001D4B30;
extern s32 D_001D4B34;
extern s32 D_001D4B38;
extern E_3A8500 D_0022DF20[64];
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122A10(void *);
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
void func_003A8500(void) {
    s32 r[4];
    s32 i;
    E_3A8500 *e;
    func_00121FE8(0);
retry:
    if (func_00122630(&D_001D4B08, 0x11, 1) < 0) {
        while (1) {
        }
    }
    while (func_00122A10(&D_001D4B08) != 0) {
    }
    if (D_001D4B08.serve == 0) {
        i = 0xFFFF;
        do {
        } while (i-- != 0);
        goto retry;
    }
    func_00122810(&D_001D4B08, 2, 0, 0, 0, r, 0x10, 0, 0);
    D_001D4B04 = r[1];
    D_001D4B30 = r[0];
    D_001D4B38 = r[2];
    D_001D4B00 = r[0];
    D_001D4B34 = 0;
    e = D_0022DF20;
    for (i = 0x3F; i >= 0; i--) {
        e->a = 0;
        e->b = 0;
        e++;
    }
}
