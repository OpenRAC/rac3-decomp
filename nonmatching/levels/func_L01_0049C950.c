/* func_L01_0049C950: MATCH (0 diff) with -mno-split-addresses (check.py --mode N, also with @ps2as). The file
   L01_0049BE80.c is built in split-address mode, where this C is 3 diff (the singleton pointer is loaded after the
   `move $a0,$v0` and into $v0 instead of the macro's `lui $v1`/`lw $v1,lo($v1)` before it). The boundary between the
   S code (func_L01_0049C630 is S only) and this N code lies between 0x49C688 and 0x49C950; the blocks after it
   (0049C9A0, 0049C9E8, 0049CA08) match in both modes. Needs a file cut at 0x49C950 with its own `-mno-split-addresses` line.
   D_001D52FC_0049C950 is the unsized-array view of the singleton pointer (lui/lw), the `$gp` view is D_001D52FC. */
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } S_0049C950;
extern S_0049C950 *D_001D52FC_0049C950[];
extern s32 func_L01_00498610(s32);
extern void func_L01_004990A8(s32 a, s32 b);
extern void func_L01_0049D200(void);
extern void func_L01_0049D190(void *p);

void func_L01_0049C950(void *p) {
    func_L01_004990A8(func_L01_00498610(0), D_001D52FC_0049C950[0]->w1C4);
    func_L01_0049D200();
    func_L01_0049D190(p);
}
